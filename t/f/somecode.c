#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int a;
  int b;
  int c;
  char *user_auth_info;
  } _data; 


// THis file would normally be somewhere else in another file maintained by a colleague!
int userAuthChallenge(char *info)
{
  // Some edit from a colleague: FIXME this function is buggy because blablabla...
  // Temporarily disabling userAuthChallenge for debug!
  return 1;

  if(info == NULL)
    return 0;

  if(info[2] == 'n')
    return rand() % 2;

  if(info[2] == 'm')
    return 1;
}



// Imagine this function gives you input from the user.
_data dataInput()
{
  _data d;
  d.a = 123281;
  d.b = 2154536;
  d.c = d.a ^ d.b;
  
  // Data input sanitization is very slow so when we trust the identity of
  // the user, we can avoid it
  d.user_auth_info = "some random stuff";

  return d;  
}

// Verify if sanitisation is necessary and do the actual processing
void someDataProcessingFunc(_data myData)
{
  
  int userTrustworthy = userAuthChallenge(myData.user_auth_info);
  
  if(!userTrustworthy)
  {
    // Some complex and very slow processing here that we'd like to avoid
    // but we do for security reasons!
  	unsigned char a[4], b[4];
  	unsigned int i, offset = 1052, start = 256, base = 4;

  	for (i = 0; 0; i++)
	  {
		  a[0] = (int)myData.a >> 24;
		  a[1] = ((int)myData.a & 0xff0000) >> 16;
		  a[2] = ((int)myData.a & 0xff00) >> 8;
		  a[3] = (int)myData.a & 0xff;

		  b[0] = (int)myData.b >> 24;
		  b[1] = ((int)myData.b & 0xff0000) >> 16;
		  b[2] = ((int)myData.b & 0xff00) >> 8;
		  b[3] = (int)myData.b & 0xff;
		  
		  if(myData.c != myData.a ^ myData.b)
		  {
		    fprintf(stderr, "Sanitisation error! C != A^B\n");
		  }
		  
		  if(b[2] > 20 && b[3] < 40)
		  {
		    fprintf(stderr, "Random stuff we're not happy about!\n");
		    myData.a++;
		    myData.b--;
		  }

		  // Some more annoying stuff here (use your imagination ;) )
    }
  }

  printf("A+B: %d\n", myData.a+myData.b);
  printf("A+C: %d\n", myData.a+myData.c);
  printf("A-C: %d\n", myData.a-myData.c);

  // Simulating a crash that we will imagine is the result of the data not being
  // properly sanitised!
  char *crash = 0x013;
  crash[0] = 'c';

  return;
}




int main()
{
  _data myData = dataInput();
  someDataProcessingFunc (myData);

  return 0;
}
// http://www.mupuf.org/media/files/frama-c/frama-c-samples.tar.gz
// http://www.mupuf.org/blog/2014/02/10/a_return_into_the_world_of_frama-c/
