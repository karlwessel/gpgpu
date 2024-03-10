List of cuda related issues and their status.

# Closed
## [1] Get cuda working without nvidia graphics card
  - Using chipstar: not tested but will probably fail because of issue [2]
  - Using HIPIFY: because of [3]

- [3] HIPIFY from Arch repository fails with
  ```<built-in>:1:10: fatal error: '__clang_cuda_runtime_wrapper.h' file not found
#include "__clang_cuda_runtime_wrapper.h"```
  
  Possible reason: - package as well as its dependency rocm is flagged outdated
  Possible solution: - compile HIPIFY and rocm from source.
  Solved by compiling HIPIFY from source.
