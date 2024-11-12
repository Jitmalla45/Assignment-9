#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
  ifstream inputFile("f.txt");
  ofstream outputFile("p.txt",ios::out | ios::trunc);  
  char ch;
  while (inputFile.get(ch)) {
    outputFile<< ch <<"";
  }
  cout << endl;
  inputFile.close();
  outputFile.close();
  return 0;
}
