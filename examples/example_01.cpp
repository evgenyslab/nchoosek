//
// Created by rtuser on 25/01/18.
//

#include <nchoosek.h>

class myObj{

public:
  std::string namev;

  myObj()=default;

  explicit myObj(std::string n){
    namev = n;
  };
  ~myObj()=default;

};

int main(int argc, char** argv){


  myObj A("A");
  myObj B("B");
  myObj C("C");

  std::vector<myObj> objList;
  objList.emplace_back(A);
  objList.emplace_back(B);
  objList.emplace_back(C);

  auto nck = nchoosek<myObj>(objList,2);

  std::vector<int> list = {1,2,3,4,5};
  auto nck2 = nchoosek<int>(list,2);

}