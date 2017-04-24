void loop() {
  int x, y, i, j, n;
  n = read();
  x = 0;
  y = 0;
  i = n;
  j = n;
  while (i > 0) {
    x = x + 1;
    i = i - 1;
    j = i;
    while (j > 0) {
      y = y + 1;
      j = j - 1;
    }
  }
  print(x);
  print(y);
}

// http://www.mupuf.org/media/files/frama-c/frama-c-samples.tar.gz
// http://www.mupuf.org/blog/2014/02/10/a_return_into_the_world_of_frama-c/
