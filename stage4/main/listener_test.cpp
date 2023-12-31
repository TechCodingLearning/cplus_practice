#include <stdio.h>
#include <gtest/gtest.h>

// This sample shows how to use Google Test listener API to implement
// an alternative console output and how to use the UnitTest reflection API
// to enumerate test suites and tests and to inspect their results.

using testing::EmptyTestEventListener;
using testing::InitGoogleTest;
using testing::Test;
using testing::TestEventListeners;
using testing::TestInfo;
using testing::TestPartResult;
using testing::UnitTest;

namespace {

class TersePrinter : public EmptyTestEventListener {
 private:
  void OnTestProgramStart(const UnitTest& unit_test) override {}

  void OnTestProgramEnd(const UnitTest& unit_test) override {
    fprintf(stdout, "TEST %s\n", unit_test.Passed() ? "PASSED" : "FAILED");
    fflush(stdout);
  }

  void OnTestPartResult(const TestPartResult& test_part_result) override {
    fprintf(stdout, "%s in %s:%d\n%s\n",
            test_part_result.failed() ? "*** Failure" : "Success",
            test_part_result.file_name(), test_part_result.line_number(),
            test_part_result.summary());
    fflush(stdout);
  }

  void OnTestEnd(const TestInfo& test_info) override {
    fprintf(stdout, "*** Test %s.%s ending.\n", test_info.test_suite_name(),
            test_info.name());
    fflush(stdout);
  }
};  // class TersePrinter

TEST(CustomOutputTest, PrintsMessage) {
  printf("Printing something from the test body...\n");
}

TEST(CustomOutputTest, Succeeds) {
  SUCCEED() << "SUCCED() has been invoked from here";
}

TEST(CustomOutputTest, Fails) {
  EXPECT_EQ(1, 2)
      << "This test fails in order to demonstrate alternative failure messages";
}
}  // namespace

int main(int argc, char** argv) {
  InitGoogleTest(&argc, argv);

  bool terse_output = false;
  if (argc > 1 && strcmp(argv[1], "--terse_output") == 0) {
    terse_output = true;
  } else {
    printf("%s\n",
           "Run this program with --terse_output to change the way "
           "it prints its output.");
  }

  UnitTest& unit_test = *UnitTest::GetInstance();

  if (terse_output) {
    TestEventListeners& listeners = unit_test.listeners();

    delete listeners.Release(listeners.default_result_printer());

    listeners.Append(new TersePrinter);
  }

  int ret_val = RUN_ALL_TESTS();

  int unexpectedly_failed_tests = 0;
  for (int i = 0; i < unit_test.total_test_case_count(); i++) {
    const testing::TestSuite& test_suite = *unit_test.GetTestSuite(i);
    for (int j = 0; j < test_suite.total_test_count(); j++) {
      const TestInfo& test_info = *test_suite.GetTestInfo(j);
      if (test_info.result()->Failed() &&
          strcmp(test_info.name(), "Fails") != 0) {
        unexpectedly_failed_tests++;
      }
    }
  }

  if (unexpectedly_failed_tests == 0) ret_val = 0;
  return ret_val;
}