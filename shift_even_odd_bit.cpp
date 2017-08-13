/*
08/13/2017
Swap odd and even bits in an integer
010111
-->
101011

- Separate even and odd bit by using 0xaaaaaaaa (for even)
and 0x55555555 (for odd)

binary representation of 1 = 0001, 2= 0010,... 5 = 0101
and a (which is 10) = 1010
0xa...a (8 a) which represent 32 bits.
A number represented by bit start with index 0, which is even

--> Need to move even to the right and odd to the left.
 */

#include<iostream>
using namespace std;
int main()
{
  int n= 23;
  int even = n& 0xaaaaaaaa;
  int odd = n& 0x55555555;
  int result = (even>>1) | (odd<<1);
  cout<<"Original number= "<<n<<" and swap of odd and even= "<<result<<endl;
}
