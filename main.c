#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  int32_t seed;
  // Input validation
  if (argc == 2) {
    seed = atoi(argv[argc - 1]);
  } else {
    printf("usage: ./acorn <seed>\n");
    return 1;
  }

  // TODO: is negative seed actually ok?
  if (seed == 0 || seed % 2 == 0 || seed < 0) {
    printf("Invalid seed %s. Must be odd, positive nonzero integer\n",
           argv[argc - 1]);
    return 1;
  }

  // PRNG
  int M = 1073741824;
  uint32_t K = 10000;
  seed %= M;

  size_t len = 100; // TODO specify len on CLI
  double *Y1 = malloc(len * sizeof *Y1);
  double *Y2 = malloc(len * sizeof *Y2);

  for (size_t i = 0; i < len; i++) {
    Y1[i] = seed;
  }

  for (size_t i = 0; i < K; i++) {
    Y2[0] = seed; // TODO: could set init val?
    for (size_t j = 0; j < len; j++) {
      Y2[j] = fmod((Y1[j] + Y2[j - 1]), M);
      Y1[j] = Y2[j];
    }
  }

  for (size_t i = 1; i < len; i++) {
    Y2[i - 1] = Y2[i];
  }
  for (size_t i = 0; i < len; i++) {
    Y2[i] = Y2[i] / M;
  }

  for (size_t i = 1; i < len; i++) {
    printf("%f\n", Y2[i]);
  }

  return 0;
}
