#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAX_LENGTH 1000000
#define MAX_LOOP   1000

size_t  my_strlen(const char *s);


int main ()
{
  char input_string[MAX_LENGTH];
  double tstart, tend;
  size_t string_length;

  srand (time(NULL));
  size_t i, randon_length = rand() % MAX_LENGTH;  
  
  printf("The length of randon string is %d.\n",randon_length);
  printf("Execution of strlen will be iterated %d times.\n",MAX_LOOP);
 
  for(i = 0 ; i < randon_length ; i++){
    char rand_char = (char)(rand() % 95 + 32); // ASCII printable characters  
    input_string[i] = rand_char;
  }

  tstart = (double)clock()/CLOCKS_PER_SEC; 
  for(i = 0 ; i < MAX_LOOP ; i++)
    string_length = (unsigned)strlen(input_string);
  tend = (double)clock()/CLOCKS_PER_SEC;
  
  printf("It took %f seconds to execute strlen by using the C standard library.\n", tend-tstart);
  

  tstart = (double)clock()/CLOCKS_PER_SEC; 
  for(i=0 ; i < MAX_LOOP ; i++)
    string_length = (unsigned)my_strlen(input_string);
  tend = (double)clock()/CLOCKS_PER_SEC;
  
  printf("It took %f seconds to execute strlen designed by myself.\n", tend-tstart);
  
  return 0;
}

size_t  my_strlen(const char *s)
{
        const char *p=s;

        while(*p!='\0')
                p++;

        return(p-s);
}





