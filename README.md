# nchoosek
A lightweight c++ object-based NchooseK algorithm implementation.

Usage:
```cpp

#include <nchoosek.h>
int main(int argc, char** argv){
// create a vector of object data:
std::vector<int> dataList = {1,2,3,4,5};
// get combinations
auto combs = nchoosek<int>(dataList,2);
}

```

`combs` is an 10x2 vector<vector<int>>, with each outer vector containing a vector of a combination of two pairs from the list.

The function returns vector of combinations as `std::vector<std::vector<Type>>`. The function requires an input of vectors of generic type: `std::vector<Type>`.

This can be useful for creating combinations of data for evualtion, but the most basic usage would be to get number combinations from a list.

TODO:

Allow for array inputs instead of std::vectors<T>.

