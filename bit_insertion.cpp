/*
08/10/2017
Insert number N into number M with position from i to j in the M
- Need to clear in M from i to j: 111000111, this is obtained by ~(111000111)=000111000. We can clear 000111111 and 000000111, then XOR of this 2 bit.
- After obtain M with clear bit from i to j. shift i bits in N.
- Then take OR.
 */
#include<iostream>
#include<bitset>
using namespace std;
int main()
{
  bitset<8> m(string("10000000"));
  bitset<8> n(string("10011"));
  cout<<m<<"\t"<<n<<endl;
  bitset<8> left,right,pad_0,m_cleared,n_shifted,result;
  int j=6, i=2;
  left = ((1<<(j+1))-1);
  right = (1<<i)-1;
  pad_0 = ~(left^right);
  m_cleared = m&pad_0;
  n_shifted = n<<i;
  result = m_cleared|n_shifted;
  cout<<result<<endl;
}
