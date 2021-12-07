cc_binary(
	name = "main",
	srcs = ["a.cc"]
)


cc_library(
	name = "add",
	srcs = ["add.cc"],
	hdrs = ["add.hpp"],
)

cc_test(
  name = "add_test",
  srcs = ["add_test.cc"],
  deps = [
    ":add",
    "@com_google_googletest//:gtest_main",
  ],
)
