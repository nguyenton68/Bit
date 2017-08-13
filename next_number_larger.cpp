/*
08/13/2017
Next larger number with the same number of 1s bits.

10011000: org
10100001: next larger

- Get number of 0s and 1s (3 0s and 2 1s for this example)
- Flip 0 to 1 at the 0s on the left of the last 1s(c1+c0) (position 6th)
- Clear all bits after position 6th(c1+c0). 
- Add 1(c1-1) 1s to the end of bit sequence
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
  /* Flip 0 to 1 */
  int totSpace = c0+c1;
  num = num|(1<<totSpace);
  cout<<num<<endl;
  /* Flip 1 to 0 */
  num = num&(~(1<<totSpace)-1); /* Clear bits to 0s*/
  num = num|((1<<(c1-1))-1);
  cout<<"Next larger number= "<<num<<endl;
}
