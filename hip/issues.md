List of issues and their status in the HIP samples.

# Open
- add saxpy example

# Closed
## [2] get chipStar working
  It is possible to compile HIP code but when executed it doesn't not seem to find any opencl device. Although `clinfo` reports some available.
  Possible solutions: - implement sample that prints available hardware
  
  Solution: Undocumented environment variable `CHIP_DEVICE_TYPE` was set to `GPU` and needs to be set to `CPU` to be able to use a cpu.
