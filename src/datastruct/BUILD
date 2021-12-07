cc_library(
	name = "sds",
	srcs = ["sds.cc"],
	hdrs = ["sds.hpp"],
)

cc_test(
  name = "sds_test",
  srcs = ["sds_test.cc"],
  deps = [
    ":sds",
    "@com_google_googletest//:gtest_main",
  ],
)