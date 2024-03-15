/*
 Source: https://github.com/Anteru/opencltutorial/tree/1e69b974b0fd5106a456f4a66697b37ba18e0427
*/

#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "CL/cl.h"

void CheckError(cl_int error) {
  if (error != CL_SUCCESS) {
    std::cerr << "OpenCL call failed with error " << error << std::endl;
    std::exit(1);
  }
}

const char *kernelstr =
    "__kernel void SAXPY (__global float* x, __global float* y, float a) {\
	const int i = get_global_id (0);\
	y [i] += a * x [i];\
}";

int main(int argc, const char **argv) {

  int platform = (argc > 2) ? atoi(argv[2]) : 0;
  int device = (argc > 3) ? atoi(argv[3]) : 0;
  int expo = (argc > 1) ? atoi(argv[1]) : 20;

  cl_int error = CL_SUCCESS;

  // get number of platforms
  cl_uint platformIdCount = 0;
  clGetPlatformIDs(0, nullptr, &platformIdCount);
  if (platformIdCount == 0) {
    std::cerr << "No OpenCL platform found" << std::endl;
    return 1;
  }

  // get platforms
  std::vector<cl_platform_id> platformIds(platformIdCount);
  clGetPlatformIDs(platformIdCount, platformIds.data(), nullptr);

  // create context
  const cl_context_properties contextProperties[] = {
      CL_CONTEXT_PLATFORM,
      reinterpret_cast<cl_context_properties>(platformIds[platform]), 0, 0};
  cl_context context = clCreateContextFromType(
      contextProperties, CL_DEVICE_TYPE_ALL, nullptr, nullptr, &error);
  CheckError(error);

  // get device count in context
  cl_uint deviceIdCount = 0;
  error = clGetContextInfo(context, CL_CONTEXT_NUM_DEVICES, sizeof(cl_uint),
                           &deviceIdCount, nullptr);
  CheckError(error);
  if (deviceIdCount == 0) {
    std::cerr << "No OpenCL devices found" << std::endl;
    return 1;
  }

  // get device ids
  std::vector<cl_device_id> deviceIds(deviceIdCount);
  error = clGetContextInfo(context, CL_CONTEXT_DEVICES, sizeof(cl_device_id),
                           deviceIds.data(), nullptr);

  // create command queue
  cl_command_queue queue =
      clCreateCommandQueueWithProperties(context, deviceIds[device], 0, &error);
  CheckError(error);

  // create kernel
  cl_program program =
      clCreateProgramWithSource(context, 1, &kernelstr, NULL, &error);
  CheckError(error);
  CheckError(clBuildProgram(program, 0, nullptr, nullptr, nullptr, nullptr));
  cl_kernel kernel = clCreateKernel(program, "SAXPY", &error);
  CheckError(error);

  // Prepare some test data
  static const size_t testDataSize = 1 << expo;
  std::vector<float> a(testDataSize), b(testDataSize);
  for (unsigned int i = 0; i < testDataSize; ++i) {
    a[i] = 1.0f;
    b[i] = 2.0f;
  }

  // allocate device memory
  cl_mem aBuffer =
      clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR,
                     sizeof(float) * (testDataSize), a.data(), &error);
  CheckError(error);

  cl_mem bBuffer =
      clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR,
                     sizeof(float) * (testDataSize), b.data(), &error);
  CheckError(error);

  // run kernel
  clSetKernelArg(kernel, 0, sizeof(cl_mem), &aBuffer);
  clSetKernelArg(kernel, 1, sizeof(cl_mem), &bBuffer);
  static const float two = 2.0f;
  clSetKernelArg(kernel, 2, sizeof(float), &two);
  const size_t globalWorkSize[] = {testDataSize, 0, 0};
  CheckError(clEnqueueNDRangeKernel(queue, kernel, 1, nullptr, globalWorkSize,
                                    nullptr, 0, nullptr, nullptr));

  // Get the results back to the host
  CheckError(clEnqueueReadBuffer(queue, bBuffer, CL_TRUE, 0,
                                 sizeof(float) * testDataSize, b.data(), 0,
                                 nullptr, nullptr));

  float maxError = 0.0f;
  for (unsigned int i = 0; i < testDataSize; i++)
    maxError = fmax(maxError, abs(b[i] - 4.0f));
  printf("Max error: %f\n", maxError);

  // clean up
  clReleaseCommandQueue(queue);
  clReleaseMemObject(bBuffer);
  clReleaseMemObject(aBuffer);
  clReleaseKernel(kernel);
  clReleaseProgram(program);
  clReleaseContext(context);
}
