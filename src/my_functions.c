#include "../include/my_functions.h"

int max3(int a, int b, int c) {
  if (a >= b && a >= c)
    return a;
  if(b >= a && b >= c)
    return b;
  return c;
}