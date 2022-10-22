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

auto fib() {
    auto inner_fibo = [](int n, auto& impl) {
        if(n<=2) {
            return 1;
        }
        return impl(n - 1, impl) + impl(n - 2, impl);
    };
    auto wynik = [inner_fibo](int n) {
        return inner_fibo(n, inner_fibo);
    };
    return wynik;
}
int main() {
    auto fibonacci = fib();
    for(int i = 0; i < 10; i++) cout << fibonacci(i) << " "; cout<<endl;
}