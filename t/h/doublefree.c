#include<stdlib.h>
#include<unistd.h>

void troublefree_roundtrip(size_t n){
  free(malloc(n));
  return;
}
void troublefree_ok(size_t n){
  unsigned char*x=(unsigned char*)malloc(n);
  free(x);
  return;
}
void troublefree_if(size_t n){
  unsigned char*x=(unsigned char*)malloc(n);
  if(!x){
    free(x);
  }
  return;
}
void troublefree_explicit_null_check(size_t n){
  unsigned char*x=(unsigned char*)malloc(n);
  if(x!=NULL){
    free(x);
  }
  return;
}
void doublefree(size_t n){
  unsigned char*x=(unsigned char*)malloc(n);
  free(x);
  free(x);
  return;
}
void doublefree_if(size_t n){
  unsigned char*x=(unsigned char*)malloc(n);
  if(!x){
    free(x);
    free(x);
  }
  return;
}
void doublefree_explicit_null_check(size_t n){
  unsigned char*x=(unsigned char*)malloc(n);
  if(x!=NULL){
    free(x);
    free(x);
  }
  return;
}
void aa_c11(size_t n){
  void*x=aligned_alloc((size_t)sysconf(_SC_PAGESIZE),n);
  if(!x){
    free(x);
    free(x);
  }
  return;
}
void aa_c11_explicit_null_check(size_t n){
  void*x=aligned_alloc((size_t)sysconf(_SC_PAGESIZE),n);
  if(x!=NULL){
    free(x);
    free(x);
  }
  return;
}
void shorter(size_t n){free(malloc(n));}

int main(void){
  troublefree_roundtrip(0);
  troublefree_ok(0);
  troublefree_if(0);
  troublefree_explicit_null_check(0);
  doublefree(0);
  doublefree_if(0);
  doublefree_explicit_null_check(0);
  aa_c11(0);
  aa_c11_explicit_null_check(0);
  shorter(0);
  return 0;
}
