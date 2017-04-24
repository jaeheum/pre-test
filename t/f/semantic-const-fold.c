int main() {
  int x;
  int *p = &x;
  x = 3;

  int final = *p+4;
  
  if (*p+4 < 6)
    final = 3;
  else
    final = 450;
  
  return 0;
}
// http://www.mupuf.org/media/files/frama-c/frama-c-samples.tar.gz
// http://www.mupuf.org/blog/2014/02/10/a_return_into_the_world_of_frama-c/
