#!/bin/bash
# Copyright 2021 Google LLC.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     https://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.



set -x
set -e

# Compile the example.
#
# See the "Using the C++ library" section in the user manual for more details
# about the API. See the "Compile command-line-interface from source" section in
# the user manual for more details about the compilation flags.
#
# Add "--config=use_tensorflow_io" to support TFRecord format natively.

# --incompatible_require_linker_input_cc_api=fase -> https://github.com/bazelbuild/rules_go/issues/2720
bazel build --config=linux_cpp17 --config=linux_avx2 --incompatible_require_linker_input_cc_api=false //examples2:main # mylib_a #beginner_cc

# Run the example.

../bazel-bin/examples2/linux_amd64_stripped/main
