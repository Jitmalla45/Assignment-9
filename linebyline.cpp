//Read Line by Line

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
  ifstream inputFile("f.txt");
  ofstream outputFile("o.txt",ios::out | ios::trunc);  
  string line;
  while(getline(inputFile, line)){
    outputFile<<line<<endl;
  }
  inputFile.close();
  outputFile.close();
  return 0;
}
