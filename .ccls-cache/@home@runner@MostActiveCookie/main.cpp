#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;
int main(int argc, char* argv[]) {

  ifstream myFile(argv[1]);
  string target = argv[3];
    
  map<string, vector<string>> cookiesPerDate;
  string hashFromFile, dateFromFile;

  while(myFile.good()){
   getline(myFile, hashFromFile, ',');   
   getline(myFile, dateFromFile, '\n');
   dateFromFile = dateFromFile.substr(0, 10);
   cookiesPerDate[dateFromFile].push_back(hashFromFile);
  }  
  myFile.close();  
  
  vector<string> cookiesOnDate = cookiesPerDate[target];
  map<string, int> cookieOnDateCount;
  string mostActiveCookie;
  
  for(auto i : cookiesOnDate){
    cookieOnDateCount[i]++;
  }

  int max(0);  
  auto begin = cookieOnDateCount.begin();
  auto end = cookieOnDateCount.end();

  while(begin != end){
    if(begin->second > max){
      max = begin->second;  
    }  
    ++begin;
  }

  auto begin2 = cookieOnDateCount.begin();
  auto end2 = cookieOnDateCount.end();

  while(begin2 != end2){
    if(begin2->second == max){
      mostActiveCookie += begin2->first + "\n";  
    }  
    ++begin2;
  }
  
  cout << mostActiveCookie;
}