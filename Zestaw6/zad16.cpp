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

bool comp(int l, int r ) {
    return to_string(l) > to_string(r);
}
int main() {
    //a)
    vector<int> v (100);
    //b)
    iota(begin(v),end(v),1);
    for (auto i : v) cout << i << " ";
    cout<<endl;
    //c)
    cout<<"Elementy w zmienionej kolejnosci:"<<endl;    random_device rd;
    mt19937 gg(rd());
    shuffle(begin(v),end(v),gg);
    for (auto i : v) cout << i << " ";
    cout<<endl;

    //d)
    sort(begin(v),end(v), greater<int>());
    cout<<"Elementy posortowane:"<<endl;
    for (auto i : v) cout << i << " ";
    cout<<endl;

    cout<<"Posortowane leksykograficznie:"<<endl;

    sort(begin(v),end(v), [](int l, int r){return to_string(l) > to_string(r);});
    for (auto i : v) cout << i << " ";
}