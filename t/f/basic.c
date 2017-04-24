int a, b, d, *p;

int f (int x) {
  return a + x;
}

int main (int c, char **v) {
  p = &b;
  a = 1;
  *p = 2;
  d = 3;
  c = f(b);
}
// http://www.mupuf.org/media/files/frama-c/frama-c-samples.tar.gz
// http://www.mupuf.org/blog/2014/02/10/a_return_into_the_world_of_frama-c/
