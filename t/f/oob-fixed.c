int main(int /*@unused@*/ argc, char /*@unused@*/ **argv)
{
  int i, t[10];
  for (i=0; i<8+2; i++)
    t[i] = i;
  
  return 0;
}
// http://www.mupuf.org/media/files/frama-c/frama-c-samples.tar.gz
// http://www.mupuf.org/blog/2014/02/10/a_return_into_the_world_of_frama-c/
