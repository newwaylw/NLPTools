/*
 * bloomFilter.cpp
 *
 *  Created on: 7 Jun 2012
 *      Author: wei
 */
#include "bloomFilter.h"

BloomFilter::BloomFilter() {
  mBitSet = new vector<bool>(512, false);
}
BloomFilter::BloomFilter(size_t noBits) {
  mBitSet = new vector<bool>(noBits, false);
}

BloomFilter::~BloomFilter() {
  delete mBitSet;
}

void BloomFilter::add(const void* key, size_t len) {
  unsigned int hash1;
  unsigned int hash2;
  unsigned int hash3;
  MurmurHash3_x86_32(key, len, SEED1, &hash1);
  MurmurHash3_x86_32(key, len, SEED2, &hash2);
  MurmurHash3_x86_32(key, len, SEED3, &hash3);
  hash1 %= mBitSet->size();
  hash2 %= mBitSet->size();
  hash3 %= mBitSet->size();

  mBitSet->at(hash1) = true;
  mBitSet->at(hash2) = true;
  mBitSet->at(hash3) = true;

}

bool BloomFilter::contains(const void* key, size_t len) {
  unsigned int hash1;
  unsigned int hash2;
  unsigned int hash3;
  MurmurHash3_x86_32(key, len, SEED1, &hash1);
  MurmurHash3_x86_32(key, len, SEED2, &hash2);
  MurmurHash3_x86_32(key, len, SEED3, &hash3);
  hash1 %= mBitSet->size();
  hash2 %= mBitSet->size();
  hash3 %= mBitSet->size();

  if (mBitSet->at(hash1) && mBitSet->at(hash2) && mBitSet->at(hash3)) {
    return true;
  } else {
    return false;
  }
}

