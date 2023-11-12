#include <gtest/gtest.h>

namespace my {
namespace project {
    namespace {

        class FooTest : public testing::Test {
        protected:
            FooTest() {
            }

            ~FooTest() override {
            }

            void SetUp() override {
            }

            void TearDown() override {
            }
        };

        TEST_F(FooTest, MethodBarDoesAbc) {
            const std::string str = "aaa";
            EXPECT_EQ(str, "aaa");
        }

        TEST_F(FooTest, DoesXyz) {
            const std::string str = "bbb";
            EXPECT_EQ(str, "bbb");
        }
    }
}
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}