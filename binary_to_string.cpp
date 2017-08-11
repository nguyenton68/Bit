/*
Convert a binary to a string. A real number 0.72 into binary representation
- Multiply by 2, see if num>1, then add 1, otherwise add 0
 */
#include<iostream>
#include<string>

using namespace std;


int main()
{
  double num = 0.72;
  string binary;
  binary.append(".");
  if(num>2 || num<0)
    cout<<"Error"<<endl;
  while(num>0)
    {
      if(binary.length()>32)
	break;
      double tmp = num*2.;
      if(tmp>=1)
	{
	  binary.append("1");
	  num = tmp - 1.;
	}
      else
	{
	  num = tmp;
	  binary.append("0");
	}
    }
  cout<<"Output binary= "<<binary<<endl;
}
