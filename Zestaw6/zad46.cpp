#include <iostream>
#include <fstream>
#include <functional>
#include <algorithm>
#include <numeric>
#include <list>
#include <vector>
#include <map>
#include <iterator>
#include <string>
#include <cstring>
#include <random>
#include <cctype>

using namespace std;
using namespace std::placeholders;

int main() {

    //a)
    vector<int> v (16);
    iota(begin(v),end(v),1);
    //b)
    auto s = [](string s, int n){ return s + "-" + to_string(n);};
    //c)
    auto wynik = accumulate(begin(v), end(v), to_string(v[0]), s);

    cout<<wynik<<endl;
}