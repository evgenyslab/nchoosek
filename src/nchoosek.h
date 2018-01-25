//
// Created by EN on 25/01/18.
//

#ifndef NCHOOSEK_NCHOOSEK_H
#define NCHOOSEK_NCHOOSEK_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

unsigned long factorial(unsigned long v){
  if (v>1)
    return v*factorial(v-1);
  else
    return 1;
}

bool memalloc(unsigned long s,unsigned long n,unsigned long k){
  // s -> size of data object in bits
  // n -> number of data points
  // k -> number of combinations
  // return true if total data size requirement is less than thresh, otherwise through warning

  // number of data points:
  auto N = factorial(n)/(factorial(k)*factorial(n-k));
  // size of data:
  auto S = s*N;
  if (S < 1e6)
    return true;
  else
    return false;
}

template<class T>
std::vector<std::vector<T>> nchoosek(std::vector<T> list, int k){
  assert(memalloc(sizeof(list[0]),list.size(),k));
  std::vector<std::vector<T>> newList, localList;
  if(list.size()<k){
    newList.clear();
    return newList;
  }
  if (k==1){
    newList.clear();
    newList.resize(list.size());
    for (int j=0;j<list.size();j++){
      std::vector<T> t;
      t.emplace_back(list[j]);
      newList[j] =  t;
    }
  }else{
    while(list.size()>1){
      // take subset of list from 1:end
      std::vector<T> sublist(list.begin()+1,list.end());
      // run nchoose(k-1) on sublist
      std::vector<std::vector<T>> temp = nchoosek(sublist,k-1);
      // append temp to ith object in list:
      // ?
      if (temp.size()>0){
        localList.clear();
        localList.resize(temp.size());
        for (int j=0;j<temp.size();j++){
          // make std::vector<T> with {list.begin(), temp[j]}, put t into newList[j]
          std::vector<T> t;
          t.resize(temp[j].size()+1);
          t[0] = list[0];
          std::copy(std::begin(temp[j]), std::end(temp[j]), std::begin(t)+1);
          localList[j] = t;
        }
        // copy local list to newList:
        auto s = newList.size();
        newList.resize(newList.size() + localList.size());
        std::copy(std::begin(localList), std::end(localList), std::begin(newList)+s);
      }
      list.erase(list.begin());

    }
  }
  int c = 0;
  return newList;
};

#endif //NCHOOSEK_NCHOOSEK_H
