load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")

cc_library(
    name = "hello-greet",
    srcs = ["hello-greet.cpp"],
    hdrs = [
        "hello-greet.h",
        "prime_tables.h",
    ],
)

cc_binary(
    name = "hello-world",
    srcs = ["hello-world.cpp"],
    deps = [
        ":hello-greet",
        "//lib:hello-time",
    ],
)

cc_test(
    name = "greet-test",
    size = "small",
    srcs = [
        "greet_test.cpp",
    ],
    deps = [
        ":hello-greet",
        "@com_google_googletest//:gtest_main",
        "@com_google_googletest//:gtest_sample_lib",
    ],
)

cc_test(
    name = "queue-test",
    size = "small",
    srcs = ["queue_test.cpp"],
    deps = [
        "@com_google_googletest//:gtest_main",
        "@com_google_googletest//:gtest_sample_lib",
    ],
)

cc_test(
    name = "gmain-test",
    size = "small",
    srcs = ["gmain_test.cpp"],
    deps = [
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "quick-test",
    size = "small",
    srcs = ["quick_test.cpp"],
    deps = [
        "@com_google_googletest//:gtest_main",
        "@com_google_googletest//:gtest_sample_lib",
    ],
)

cc_test(
    name = "comm-test",
    size = "small",
    srcs = ["comm_properties_test.cpp"],
    deps = [
        ":hello-greet",
        "@com_google_googletest//:gtest_main",
        "@com_google_googletest//:gtest_sample_lib",
    ],
)

cc_test(
    name = "comm-param-test",
    size = "small",
    srcs = ["comm_prop_with_param_test.cpp"],
    deps = [
        ":hello-greet",
        "@com_google_googletest//:gtest_main",
        "@com_google_googletest//:gtest_sample_lib",
    ],
)

cc_test(
    name = "combine-test",
    size = "small",
    srcs = ["combine_test.cpp"],
    deps = [
        ":hello-greet",
        "@com_google_googletest//:gtest_main",
        "@com_google_googletest//:gtest_sample_lib",
    ],
)


cc_test(
    name = "listener-test",
    size = "small",
    srcs = ["listener_test.cpp"],
    deps = [
        ":hello-greet",
        "@com_google_googletest//:gtest_main",
        "@com_google_googletest//:gtest_sample_lib",
    ],
)
