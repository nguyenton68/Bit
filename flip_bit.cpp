/*
Flip a but to Win
- Put binary into array
- Loop through array with increase by 2 i=i+2
- Check if 0s is 0,1,>1

Problem:
run 3 times give different results.
 */
#include<iostream>
#include<algorithm>
using namespace std;

const int N=8;
int* sequence(int num)
{
  int* seq = new int[N];
  int searchFor=0;
  int count = 0;
  int indx=0;
  //   seq[0]=0;
  for(int i=0; i<sizeof(num)*8; i++)
    {
      if((num&1) != searchFor)
	{
	  searchFor = num&1;

	  seq[indx]=count;
	  indx++;
	  count=0;
	}
      count++;
      num>>=1;
    }

  seq[indx]=count;
  return seq;
}
int findLongestSeq(int* seq)
{
  int maxSeq = 1;
  for(int i=0; i<N;i+=2)
    {
      int zeroSeq = seq[i];
      int onesSeqRight = (i-1 >=0) ? seq[i-1]: 0;
      int onesSeqLeft  = (i+1 <N)  ? seq[i+1] :0;

      int thisSeq =0;
      if(zeroSeq ==1)
      	{
      	  thisSeq = onesSeqRight + 1 + onesSeqLeft;
      	}
      else if(zeroSeq >1)
      	{
      	  thisSeq = 1+max(onesSeqRight,onesSeqLeft);
      	}
      else if(zeroSeq ==0)
      	{
	  thisSeq = max(onesSeqLeft, onesSeqRight);
      	}
      maxSeq = max(thisSeq, maxSeq);

    }
  return maxSeq;
}
int main()
{
  int num = 1775;
  int* convertSeq = sequence(num);
  int k = findLongestSeq(convertSeq);
  cout<<"maximum sequence of 1s= "<<k<<endl;
 
}
