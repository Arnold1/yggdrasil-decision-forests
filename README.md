# Overview

# Origin of code
- Code is based on: ```git clone --branch 0.2.4 --depth=1 https://github.com/google/yggdrasil-decision-forests```

# Goal
- Call yggdrasil from golang
- Example is based on: https://github.com/google/yggdrasil-decision-forests/tree/main/examples
- Bazel version:
```
# bazel --version
bazel 4.0.0
```

## Option 1

Compile static library and go binary with bazel.

- Compile it:
```
cd examples2
./compile_and_run.sh
```
- Current errors (with bazel go binary):
```
# ../bazel-bin/examples2/linux_amd64_stripped/main
1
[INFO mylib.cc:27] Import the model
[FATAL mylib.cc:30] INVALID_ARGUMENT: Unknown item RANDOM_FOREST in class pool N26yggdrasil_decision_forests5model13AbstractModelE. Registered elements are
```

## Option 2

Build static library with bazel and run go build.

- Build the static library:
```
cd examples2
root@2ea05d554c95:~/yggdrasil-decision-forests/examples2# bazel build --config=linux_cpp17 --config=linux_avx2 --incompatible_require_linker_input_cc_api=false //examples2:mylib_static
INFO: Options provided by the client:
  Inherited 'common' options: --isatty=1 --terminal_columns=171
INFO: Reading rc options for 'build' from /home/developer/yggdrasil-decision-forests/.bazelrc:
  Inherited 'common' options: --experimental_repo_remote_exec --incompatible_restrict_string_escapes=false
INFO: Reading rc options for 'build' from /home/developer/yggdrasil-decision-forests/.bazelrc:
  'build' options: -c opt --spawn_strategy=standalone --announce_rc --noincompatible_strict_action_env --define=use_fast_cpp_protos=true --define=allow_oversize_protos=true --define=grpc_no_ares=true --color=yes
INFO: Found applicable config definition build:linux_cpp17 in file /home/developer/yggdrasil-decision-forests/.bazelrc: --cxxopt=-std=c++17 --host_cxxopt=-std=c++17 --config=linux
INFO: Found applicable config definition build:linux in file /home/developer/yggdrasil-decision-forests/.bazelrc: --copt=-fdiagnostics-color=always --copt=-w --host_copt=-w
INFO: Found applicable config definition build:linux_avx2 in file /home/developer/yggdrasil-decision-forests/.bazelrc: --copt=-mavx2
DEBUG: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/third_party/repo.bzl:108:14: 
Warning: skipping import of repository 'com_google_absl' because it already exists.
DEBUG: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/third_party/repo.bzl:108:14: 
Warning: skipping import of repository 'farmhash_archive' because it already exists.
DEBUG: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/third_party/repo.bzl:108:14: 
Warning: skipping import of repository 'com_google_protobuf' because it already exists.
DEBUG: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/third_party/repo.bzl:108:14: 
Warning: skipping import of repository 'com_google_googletest' because it already exists.
DEBUG: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/third_party/repo.bzl:108:14: 
Warning: skipping import of repository 'zlib' because it already exists.
DEBUG: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/third_party/repo.bzl:108:14: 
Warning: skipping import of repository 'rules_cc' because it already exists.
DEBUG: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/third_party/repo.bzl:108:14: 
Warning: skipping import of repository 'rules_python' because it already exists.
DEBUG: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/third_party/repo.bzl:108:14: 
Warning: skipping import of repository 'bazel_skylib' because it already exists.
DEBUG: Rule 'io_bazel_rules_docker' indicated that a canonical reproducible form can be obtained by modifying arguments shallow_since = "1556410077 -0400"
DEBUG: Repository io_bazel_rules_docker instantiated at:
  /home/developer/yggdrasil-decision-forests/WORKSPACE:42:4: in <toplevel>
  /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/workspace0.bzl:105:34: in workspace
  /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/bazel_toolchains/repositories/repositories.bzl:37:23: in repositories
Repository rule git_repository defined at:
  /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/bazel_tools/tools/build_defs/repo/git.bzl:199:33: in <toplevel>
DEBUG: Rule 'com_google_absl' indicated that a canonical reproducible form can be obtained by modifying arguments sha256 = "f95ef5913e64262812045e134579902e358ba19c9ac7d73183daa9b6f4736494"
DEBUG: Repository com_google_absl instantiated at:
  /home/developer/yggdrasil-decision-forests/WORKSPACE:16:5: in <toplevel>
  /home/developer/yggdrasil-decision-forests/third_party/absl/workspace.bzl:11:17: in deps
Repository rule http_archive defined at:
  /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/bazel_tools/tools/build_defs/repo/http.bzl:336:31: in <toplevel>
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/example/BUILD:92:17: in cc_library rule @org_tensorflow//tensorflow/core/example:example_protos_cc_impl: target '@org_tensorflow//tensorflow/core/example:example_protos_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/framework/BUILD:1601:17: in cc_library rule @org_tensorflow//tensorflow/core/framework:tensor_shape_proto_cc_impl: target '@org_tensorflow//tensorflow/core/framework:tensor_shape_proto_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/framework/BUILD:1583:17: in cc_library rule @org_tensorflow//tensorflow/core/framework:types_proto_cc_impl: target '@org_tensorflow//tensorflow/core/framework:types_proto_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/framework/BUILD:1468:17: in cc_library rule @org_tensorflow//tensorflow/core/framework:resource_handle_proto_cc_impl: target '@org_tensorflow//tensorflow/core/framework:resource_handle_proto_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/framework/BUILD:1540:17: in cc_library rule @org_tensorflow//tensorflow/core/framework:tensor_proto_cc_impl: target '@org_tensorflow//tensorflow/core/framework:tensor_proto_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/example/BUILD:102:17: in cc_library rule @org_tensorflow//tensorflow/core/example:example_parser_configuration_proto_cc_impl: target '@org_tensorflow//tensorflow/core/example:example_parser_configuration_proto_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/example/BUILD:114:17: in cc_library rule @org_tensorflow//tensorflow/core/example:protos_all_cc_impl: target '@org_tensorflow//tensorflow/core/example:protos_all_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/framework/BUILD:1435:17: in cc_library rule @org_tensorflow//tensorflow/core/framework:allocation_description_proto_cc_impl: target '@org_tensorflow//tensorflow/core/framework:allocation_description_proto_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/framework/BUILD:1527:17: in cc_library rule @org_tensorflow//tensorflow/core/framework:attr_value_proto_cc_impl: target '@org_tensorflow//tensorflow/core/framework:attr_value_proto_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/framework/BUILD:1552:17: in cc_library rule @org_tensorflow//tensorflow/core/framework:api_def_proto_cc_impl: target '@org_tensorflow//tensorflow/core/framework:api_def_proto_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/framework/BUILD:1590:17: in cc_library rule @org_tensorflow//tensorflow/core/framework:cost_graph_proto_cc_impl: target '@org_tensorflow//tensorflow/core/framework:cost_graph_proto_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/framework/BUILD:1644:17: in cc_library rule @org_tensorflow//tensorflow/core/framework:dataset_options_proto_cc_impl: target '@org_tensorflow//tensorflow/core/framework:dataset_options_proto_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/framework/BUILD:1461:17: in cc_library rule @org_tensorflow//tensorflow/core/framework:device_attributes_proto_cc_impl: target '@org_tensorflow//tensorflow/core/framework:device_attributes_proto_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/framework/BUILD:1421:17: in cc_library rule @org_tensorflow//tensorflow/core/framework:node_def_proto_cc_impl: target '@org_tensorflow//tensorflow/core/framework:node_def_proto_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/framework/BUILD:1513:17: in cc_library rule @org_tensorflow//tensorflow/core/framework:op_def_proto_cc_impl: target '@org_tensorflow//tensorflow/core/framework:op_def_proto_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/framework/BUILD:1608:17: in cc_library rule @org_tensorflow//tensorflow/core/framework:function_proto_cc_impl: target '@org_tensorflow//tensorflow/core/framework:function_proto_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/framework/BUILD:1396:17: in cc_library rule @org_tensorflow//tensorflow/core/framework:versions_proto_cc_impl: target '@org_tensorflow//tensorflow/core/framework:versions_proto_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/framework/BUILD:1403:17: in cc_library rule @org_tensorflow//tensorflow/core/framework:graph_proto_cc_impl: target '@org_tensorflow//tensorflow/core/framework:graph_proto_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/framework/BUILD:1573:17: in cc_library rule @org_tensorflow//tensorflow/core/framework:graph_transfer_info_proto_cc_impl: target '@org_tensorflow//tensorflow/core/framework:graph_transfer_info_proto_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/framework/BUILD:1499:17: in cc_library rule @org_tensorflow//tensorflow/core/framework:kernel_def_proto_cc_impl: target '@org_tensorflow//tensorflow/core/framework:kernel_def_proto_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/framework/BUILD:1449:17: in cc_library rule @org_tensorflow//tensorflow/core/framework:tensor_description_proto_cc_impl: target '@org_tensorflow//tensorflow/core/framework:tensor_description_proto_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/framework/BUILD:1383:17: in cc_library rule @org_tensorflow//tensorflow/core/framework:log_memory_proto_cc_impl: target '@org_tensorflow//tensorflow/core/framework:log_memory_proto_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/framework/BUILD:1637:17: in cc_library rule @org_tensorflow//tensorflow/core/framework:model_proto_cc_impl: target '@org_tensorflow//tensorflow/core/framework:model_proto_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/framework/BUILD:1492:17: in cc_library rule @org_tensorflow//tensorflow/core/framework:reader_base_proto_cc_impl: target '@org_tensorflow//tensorflow/core/framework:reader_base_proto_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/framework/BUILD:1479:17: in cc_library rule @org_tensorflow//tensorflow/core/framework:step_stats_proto_cc_impl: target '@org_tensorflow//tensorflow/core/framework:step_stats_proto_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/framework/BUILD:1624:17: in cc_library rule @org_tensorflow//tensorflow/core/framework:summary_proto_cc_impl: target '@org_tensorflow//tensorflow/core/framework:summary_proto_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/framework/BUILD:1442:17: in cc_library rule @org_tensorflow//tensorflow/core/framework:tensor_slice_proto_cc_impl: target '@org_tensorflow//tensorflow/core/framework:tensor_slice_proto_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/framework/BUILD:1566:17: in cc_library rule @org_tensorflow//tensorflow/core/framework:variable_proto_cc_impl: target '@org_tensorflow//tensorflow/core/framework:variable_proto_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/framework/BUILD:1651:17: in cc_library rule @org_tensorflow//tensorflow/core/framework:protos_all_cc_impl: target '@org_tensorflow//tensorflow/core/framework:protos_all_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/protobuf/BUILD:131:17: in cc_library rule @org_tensorflow//tensorflow/core/protobuf:error_codes_proto_impl_cc_impl: target '@org_tensorflow//tensorflow/core/protobuf:error_codes_proto_impl_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/lib/core/BUILD:136:17: in cc_library rule @org_tensorflow//tensorflow/core/lib/core:error_codes_proto_cc_impl: target '@org_tensorflow//tensorflow/core/lib/core:error_codes_proto_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/profiler/protobuf/BUILD:15:17: in cc_library rule @org_tensorflow//tensorflow/core/profiler/protobuf:xplane_proto_cc_impl: target '@org_tensorflow//tensorflow/core/profiler/protobuf:xplane_proto_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/profiler/BUILD:35:17: in cc_library rule @org_tensorflow//tensorflow/core/profiler:profiler_options_proto_cc_impl: target '@org_tensorflow//tensorflow/core/profiler:profiler_options_proto_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/protobuf/BUILD:164:17: in cc_library rule @org_tensorflow//tensorflow/core/protobuf:for_core_protos_cc_impl: target '@org_tensorflow//tensorflow/core/protobuf:for_core_protos_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/util/BUILD:830:17: in cc_library rule @org_tensorflow//tensorflow/core/util:event_proto_cc_impl: target '@org_tensorflow//tensorflow/core/util:event_proto_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/util/BUILD:845:17: in cc_library rule @org_tensorflow//tensorflow/core/util:saved_tensor_slice_proto_cc_impl: target '@org_tensorflow//tensorflow/core/util:saved_tensor_slice_proto_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/util/BUILD:861:17: in cc_library rule @org_tensorflow//tensorflow/core/util:memmapped_file_system_proto_cc_impl: target '@org_tensorflow//tensorflow/core/util:memmapped_file_system_proto_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/util/BUILD:869:17: in cc_library rule @org_tensorflow//tensorflow/core/util:protos_all_cc_impl: target '@org_tensorflow//tensorflow/core/util:protos_all_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/util/BUILD:813:17: in cc_library rule @org_tensorflow//tensorflow/core/util:test_log_proto_impl_cc_impl: target '@org_tensorflow//tensorflow/core/util:test_log_proto_impl_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/grappler/costs/BUILD:25:17: in cc_library rule @org_tensorflow//tensorflow/core/grappler/costs:op_performance_data_cc_impl: target '@org_tensorflow//tensorflow/core/grappler/costs:op_performance_data_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
WARNING: /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/org_tensorflow/tensorflow/core/BUILD:231:17: in cc_library rule @org_tensorflow//tensorflow/core:protos_all_cc_impl: target '@org_tensorflow//tensorflow/core:protos_all_cc_impl' depends on deprecated target '@com_google_protobuf//:cc_wkt_protos': Only for backward compatibility. Do not use.
DEBUG: Rule 'org_boost' indicated that a canonical reproducible form can be obtained by modifying arguments commit = "b7b1371294b4bdfc8d85e49236ebced114bc1d8f", shallow_since = "1606971604 +0000" and dropping ["branch"]
DEBUG: Repository org_boost instantiated at:
  /home/developer/yggdrasil-decision-forests/WORKSPACE:21:6: in <toplevel>
  /home/developer/yggdrasil-decision-forests/third_party/boost/workspace.bzl:23:23: in deps
Repository rule new_git_repository defined at:
  /home/developer/.cache/bazel/_bazel_root/24e8bb26857d60bf6cc54958294ec961/external/bazel_tools/tools/build_defs/repo/git.bzl:186:37: in <toplevel>
INFO: Analyzed target //examples2:mylib_static (0 packages loaded, 0 targets configured).
INFO: Found 1 target...
Target //examples2:mylib_static up-to-date:
  bazel-bin/examples2/mylib_static.link
  bazel-bin/examples2/mylib_static.a
INFO: Elapsed time: 0.260s, Critical Path: 0.00s
INFO: 1 process: 1 internal.
INFO: Build completed successfully, 1 total action
```

- Copy static libary to the lib dir:
```
root@2ea05d554c95:~/yggdrasil-decision-forests/examples2# cp ../bazel-bin/examples2/mylib_static.a ./lib/libmylib_a.a 
```

- Run the go app:
```
root@2ea05d554c95:~/yggdrasil-decision-forests/examples2# go run .
1
[INFO mylib.cc:27] Import the model
[FATAL mylib.cc:30] INVALID_ARGUMENT: Unknown item RANDOM_FOREST in class pool N26yggdrasil_decision_forests5model13AbstractModelE. Registered elements are 
exit status 1
```
