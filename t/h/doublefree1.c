#include"doublefree.h"
void doublefree(size_t n){
  unsigned char*x=(unsigned char*)malloc(n);
  free(x);
  if(!x){
    free(x);
  }
  return;
}
