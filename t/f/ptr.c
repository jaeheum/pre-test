
int main() {

	int *ptr;
	int *tmp;
	
	int x = 4;
	ptr = &x;

	int z = *ptr++;

	*ptr++ = 12;

	return 0;
}
// http://www.mupuf.org/media/files/frama-c/frama-c-samples.tar.gz
// http://www.mupuf.org/blog/2014/02/10/a_return_into_the_world_of_frama-c/
