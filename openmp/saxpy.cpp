#include <cmath>
#include <cstdio>
#include <omp.h>
#include <vector>

int main(int argc, const char **argv) {
  int expo = (argc > 1) ? atoi(argv[1]) : 20;
  size_t N{(size_t)1 << expo};
  float A{2.0};

  auto X = std::vector<float>(N);
  auto Y = std::vector<float>(N);

  for (int i = 0; i < N; i++) {
    X[i] = 1.0f;
    Y[i] = 2.0f;
  }

  int i;
#pragma omp parallel shared(N, A, X, Y) private(i)
#pragma omp for
  for (i = 0; i < N; i++) {
    Y[i] += A * X[i];
  }

  float maxError = 0.0f;
  for (unsigned int i = 0; i < N; i++)
    maxError = fmax(maxError, abs(Y[i] - 4.0f));
  printf("Max error: %f\n", maxError);
}
