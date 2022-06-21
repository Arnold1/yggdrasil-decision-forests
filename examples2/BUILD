#load("@rules_cc//cc:defs.bzl", "cc_library")
#load("//examples2:cc_library_static.bzl", "cc_static_library")

load("//examples2:cc_static_library.bzl", "cc_static_library")
#load("//examples2:cc_library_static.bzl", "cc_static_library")
load("@io_bazel_rules_go//go:def.bzl", "go_binary")

package(
    default_visibility = ["//visibility:public"],
    licenses = ["notice"],
)

# Usage example of Yggdrasil Decision Forests as a library.
#
# Compile and run the example with:
#   bazel build //examples:beginner_cc --config=linux_cpp17 --config=linux_avx2
#   bazel-bin/examples/beginner_cc --alsologtostderr
#
# See the "Using the C++ library" section in the user manual for more details about the API.
# See the "Compile command-line-interface from source" section in the user manual for more details about the compilation flags.
#
#cc_binary(
cc_library(
    name = "mylib_a",
    srcs = [
        "lib/mylib.cc",
        "lib/mylib.hh",
    ],
    linkstatic = 1,

    #name = "beginner_cc",
    #srcs = ["beginner4.cc"],
    # Because this binary is defined in the Yggdrasil project directly, the
    # following dependencies are local. In your project you will probably use
    # a "http_archive" dependency:
    # https://docs.bazel.build/versions/master/repo/http.html#http_archive*
    #
    # See TensorFlow Decision Forests for an example (TF-DF imports YDF):
    #   https://github.com/tensorflow/decision-forests
    deps = [
        "@com_google_absl//absl/flags:flag",
        "//yggdrasil_decision_forests/dataset:all_dataset_formats",
        "//yggdrasil_decision_forests/dataset:data_spec",
        "//yggdrasil_decision_forests/dataset:data_spec_cc_proto",
        "//yggdrasil_decision_forests/dataset:data_spec_inference",
        "//yggdrasil_decision_forests/dataset:vertical_dataset_io",
        "//yggdrasil_decision_forests/learner:all_learners",
        "//yggdrasil_decision_forests/learner:learner_library",
        "//yggdrasil_decision_forests/metric",
        "//yggdrasil_decision_forests/metric:report",
        "//yggdrasil_decision_forests/model:model_library",
        "//yggdrasil_decision_forests/utils:filesystem",
        "//yggdrasil_decision_forests/utils:logging",
        "//yggdrasil_decision_forests/model:all_models",
    ],
)

#cc_import(
#    name = "mylib_a",
#    shared_library = ":libmylib_a.a",
#)

go_binary(
    name = "main",
    cgo=True,
    srcs = [
	"main.go",
	"cmylib.cc",
        "cmylib.h",
        "mylib.hh",
    ],
    cdeps=[":mylib_a"],
)

cc_static_library(
    name = "mylib_static",
    deps = [":mylib_a"],
    #dep = ":mylib_a",
)

