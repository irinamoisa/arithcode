/// \file
/// An simple demonstration.
#include "ac.h"
#include <stdio.h>

#define countof(e) (sizeof(e)/sizeof(*(e)))
#define ROW 80
#define ENDL "\n"
typedef unsigned long long u64;

/// Prints out the encoded message using hex codes
void pcode(u8 *out, size_t nout)
{ size_t i,j;
  printf("Code:\n");
  for(i=0;i<nout;++i)
  { for(j=0;j<ROW/3 && i<nout;j++,i++)
      printf(" %02x",out[i]);
    --i;
    printf("\n");
  }
  printf("--\n");
}

/// Prints out the encoded message using characters
void pascii(u8 *out, size_t nout)
{ size_t i,j;
  printf("Code:\n");
  for(i=0;i<nout;++i)
  { for(j=0;j<ROW/2 && i<nout;j++,i++)
      printf(" %c",out[i]+33);
    --i;
    printf("\n");
  }
  printf("--\n");
}

/// Prints decoded the message string.
void pmsg(u32 *v,size_t n)
{ size_t i,j;
  printf("Message: %p\n",v);
  for(i=0;i<n;++i)
  { for(j=0;j<ROW/2 && i<n;j++,i++)
      printf(" %d",v[i]);
    --i;
    printf("\n");
  }
  printf("--\n");
}

/// A simple demo
int main(int argc, char* argv[])
{ u32  s[] = {2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0,
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0, 
              2,1,0,0,0,0,0,0,0,0,0,0,3,3,2,3,2,1,0},
          //0     x x x x x x x x x x             x    11 /19
          //1   x                               x       2
          //2 x                           x   x         3
          //3                         x x   x           3
          //                                           19
       *t=0;
  real c[] =   {0.0,11/19.0, 13/19.0, 16/19.0, 1.0};
  //real c[] = {0.0,    0.2,     0.7,     0.9, 1.0};
  u8    *out = NULL;
  size_t nout = 0,nt=countof(t);

  pmsg(s,countof(s));
#if 0
  encode_u8_u32((void**)&out,&nout,s,countof(s),c,countof(c)-1);
  pcode(out,nout);
  printf("Compression: %3.2f%% (%llu bytes -> %llu bytes)"ENDL,100.0*nout/(double)sizeof(s),(u64)sizeof(s),(u64)nout);
  decode_u32_u8(&t,&nt,out,nout,c,countof(c)-1);
#else
  { // ASCII normalish is from 33 to 126 inclusive, 94 things
    int    D = 94; //2;
    vencode_u32(&out,&nout,D,s,countof(s),countof(c)-1,c);
    pascii(out,nout);
    printf("Compression: %3.2f%% (%llu bytes -> %llu bytes)"ENDL,
        100.0*nout/(double)sizeof(s),
        (u64)sizeof(s),
        (u64)nout);
    vdecode_u32(&t,&nt,countof(c)-1,out,nout,D ,c);
  }
#endif
  if(nt != countof(s))
    printf("*** Wrong symbol count. Got: %zu Expected: %zu"ENDL,nt,(size_t)countof(s));
  pmsg(t,countof(s));

  free(out);
  free(t);
  return 0;
}

