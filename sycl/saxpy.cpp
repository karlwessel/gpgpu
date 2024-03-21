/*
 Based on
 https://www.intel.com/content/www/us/en/developer/articles/technical/the-case-for-c-plus-plus-with-sycl.html
 */

#include <CL/sycl.hpp>
#include <cmath>

int main(int argc, const char** argv) {
  int expo = (argc > 1) ? atoi(argv[1]) : 20;
  size_t N{(size_t)1 << expo};
  float A{2.0};

  sycl::queue Q;
  auto X = sycl::malloc_shared<float>(N, Q);
  auto Y = sycl::malloc_shared<float>(N, Q);

  for (int i = 0; i < N; i++) {
    X[i] = 1.0f;
    Y[i] = 2.0f;
  }

  Q.parallel_for(sycl::range<1>{N}, [=](sycl::id<1> i) { 
    Y[i] += A * X[i]; 
  });
  Q.wait();

  float maxError = 0.0f;
  for (unsigned int i = 0; i < N; i++)
    maxError = fmax(maxError, abs(Y[i] - 4.0f));
  printf("Max error: %f\n", maxError);
}
