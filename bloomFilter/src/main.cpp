/*
 * main.cpp
 *
 *  Created on: 10 Apr 2013
 *      Author: wei
 */
#include "bloomFilter.h"
#include <iostream>
#include <string>

int main(){
  BloomFilter *bf = new BloomFilter(1024);

  string st1 = "this";
  string st2 = "is";
  string st3 = "a";
  string st4 = "test";

  bf->add(st1.c_str(),st1.length());
  bf->add(st2.c_str(),st2.length());
  cout<<"bloom filter contains \""<<st1 <<"\"" <<":"<< bf->contains(st1.c_str(), st1.length()) << endl;
  cout<<"bloom filter contains \""<<st2 <<"\"" <<":"<< bf->contains(st2.c_str(), st2.length()) << endl;
  cout<<"bloom filter contains \""<<st3 <<"\"" <<":"<< bf->contains(st3.c_str(), st3.length()) << endl;
  cout<<"bloom filter contains \""<<st4 <<"\"" <<":"<< bf->contains(st4.c_str(), st4.length()) << endl;


}



