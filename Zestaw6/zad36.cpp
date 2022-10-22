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
    vector<int> v (10);
    iota(begin(v),end(v),0);
    map<int,string> mapka {{0,"zero"}, {1,"jeden"}, {2,"dwa"},{3,"trzy"},{4,"cztery"},{5,"piec"},{6,"szesc"},{7,"siedem"},{8,"osiem"},{9,"dziewiec"}};
    transform(begin(v),end(v),ostream_iterator<string>(cout," "),[&](int x){ return mapka[x];});
}