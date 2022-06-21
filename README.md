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
- Compile it:
```
cd examples2
./compile_and_run.sh
```
- Current errors:
```
# ../bazel-bin/examples2/linux_amd64_stripped/main
1
[INFO mylib.cc:27] Import the model
[FATAL mylib.cc:30] INVALID_ARGUMENT: Unknown item RANDOM_FOREST in class pool N26yggdrasil_decision_forests5model13AbstractModelE. Registered elements are
```
