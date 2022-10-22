#include <iostream>
#include <fstream>
#include <functional>
#include <algorithm>
#include <numeric>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <iterator>
#include <string>
#include <cstring>
#include <random>
#include <cctype>

using namespace std;
using namespace std::placeholders;

int main() {

    list<char> lista {'a','c','b','d','f','e','h','g'};

    auto lambda = [&](const auto& x, const auto& y ){
        list<char>::iterator itr_x = find(begin(lista), end(lista),x);
        list<char>::iterator itr_y= find(begin(lista), end(lista),y);
        list<char>::iterator beg = begin(lista);
        return(distance(beg,itr_x)<distance(beg,itr_y));
    };

    using setlambda = std::set<char, decltype(lambda)>;
    setlambda my_set({'a', 'a' , 'a', 'g', 'c', 'b', 'f', 'h', 'c', 'e', 'd', 'e'},lambda);



    for (auto c:my_set) cout << c; cout<<endl;
    //tutaj nie wiem ale wypisuje niby dobrze : )
}