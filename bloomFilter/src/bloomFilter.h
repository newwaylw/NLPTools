/*
 * bloomFilter.hpp
 *
 *  Created on: 7 Jun 2012
 *      Author: wei
 */

#ifndef BLOOMFILTER_H_
#define BLOOMFILTER_H_

#include "MurmurHash3.h"
#include <vector>
using namespace std;

class BloomFilter {

public:
  const static size_t SEED1 = 0xb5;
  const static size_t SEED2 = 0x5a2f;
  const static size_t SEED3 = 0x4e0c;

  BloomFilter();
  BloomFilter(size_t noBits);
  void add(const void* key, size_t len);
  //addAll()
  bool contains(const void* key, size_t len);
  ~BloomFilter();

private:
  //size_t defaultsize = 512;
  vector<bool>* mBitSet;
};


#endif /* BLOOMFILTER_H_ */
