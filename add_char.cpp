#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
  ifstream inputFile("f.txt");
  int res,sum=0;
  char ch;
  while (inputFile.get(ch)) {
    res=static_cast<int>(static_cast<unsigned char>(ch));
    sum=sum+res;
  }
  cout<<"The sum is: " <<sum<<endl;
  inputFile.close();
  return 0;
}
