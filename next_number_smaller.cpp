/*
08/13/2017
Next smaller number with the same number of 1s bits.

10011000: org
10001100: next smaller

- Get number of 0s and 1s (3 0s and 2 1s for this example)
- Flip 1 to 0 at (c1+c0) (position 5th)
- Clear all bits after position 6th(c1+c0). 
- Add (c1+1) 1s and (c0-1)0s
 */
#include<iostream>

using namespace std;
int main()
{
  int num = 13948;
  int tmp = num;
  int c0=0, c1=0;
  while((tmp&1) == 0&& (tmp !=0))
    {
      tmp>>=1;
      c0++;
    }
  while((tmp&1)==1)
    {
      tmp>>=1;
      c1++;
    }
  cout<<"Original number= "<<num<<endl;
  /* Flip 1 to 0 by clear all bits*/
  int totSpace = c0+c1;
  num = num&((~0)<<(totSpace+1));

  /*Add c1+1 1s and c0-1 0s */
  int OneSeq = (1<<(c1+1))-1;
  num = num|(OneSeq<<(c0-1));

  cout<<"Next smaller number= "<<num<<endl;
}
