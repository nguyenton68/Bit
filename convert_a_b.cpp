/* Determine number of bits you need to flip to convert number A into number B
- Use XOR: XOR give number of bits are different in 2 numbers
- Just count how many 1s in the sequence (A^B)
*/
#include<iostream>
using namespace std;
int main()
{
  int count=0;
  int best_count=0;
  int a = 29, b=15;
  /* Method 1: XOR, count how many 1s, then we get number of bits are different in 2 numbers */
  for(int c=a^b; c!=0; c>>=1)
    {
      if((c&1)==1)
	count++;
    }
  cout<<"Need to flip "<<count<<" times to make A=B"<<endl;

  /* Method 2: XOR and increase the for loop by using c=c&(c-1): this clear the least signigicant digit.
It ignore all 0, just care 1 */
  for(int c =a^b; c!=0; c=c&(c-1))
    {
      best_count++;
    }
  cout<<"Need to flip "<<best_count<<" times to make A=B"<<endl;
}
