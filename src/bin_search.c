#include<stdio.h>
int sbands [16] = {1,2,3,71,74,120,126,151,543,837,986,1001,1023,1828,2829,133000};

//isB73Supported = isBandSupported(73,16);
//isB73Supported is -1

//isB1Supported = isBandSupported(1,16);
//isB1Supported = 1;
// band = 33
int isBandSupported_rec(int band, int lower, int higher)
{
  printf("lower = %d, higher = %d\n", lower, higher);  
  int mid = (lower+higher)/2;

  if(lower >= higher)
  {
    return -1;
  }
  if(band == sbands[mid])
  {
    return mid;
  }
  else if (band < sbands[mid])
  {
    printf("%d %d %d\n", lower, higher, mid);
    isBandSupported_rec(band, lower, mid);
  }
  else {
    printf("%d %d %d", lower, higher, mid);
    isBandSupported_rec(band, mid+1, higher);
  }
}
int isBandSupported(int band, int len)
{
  return isBandSupported_rec(band, 0, len-1);
}
int main() {
  int isB73Supported = isBandSupported(133000,16);
  printf("%d", isB73Supported);
//isB73Supported is -1

//isB1Supported = isBandSupported(1,16);
//isB1Supported = 1;
// band = 33
  return 0;
}
