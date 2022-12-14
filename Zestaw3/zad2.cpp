#include <iostream>
#include <cstdlib>

using namespace std;

class A1{
    public:
        A1() { cout << "A1 c-tor " << endl; }
        ~A1() { cout << "A1 d-tor " << endl; }
};
// ------------------------------------------------------------------------------------------------
class V1 : public A1{
    public:
        V1() { cout << "V1 c-tor " << endl; }
        ~V1() { cout << "V1 d-tor " << endl; } 
};
// ------------------------------------------------------------------------------------------------
class C1 : virtual public V1{
    public:
        C1() { cout << "C1 c-tor " << endl; }
        ~C1() { cout << "C1 d-tor " << endl; }
};
// ------------------------------------------------------------------------------------------------
class B2{
    public:
        B2() {cout << "B2 c-tor "  << endl; }
        ~B2() { cout << "B2 d-tor " << endl; }
};
// ------------------------------------------------------------------------------------------------
class B3{
    public:    
        B3() { cout << "B3 c-tor " << endl; }
        ~B3() { cout << "B3 d-tor " << endl; }
};
// ------------------------------------------------------------------------------------------------
class V2 : public A1, public B2{
    public:
        V2() { cout << "V2 c-tor " << endl; }
        ~V2() { cout << "V2 d-tor " << endl; }
};
// ------------------------------------------------------------------------------------------------
class C2 : virtual public V2, public B3{
    public:
        C2() { cout << "C2 c-tor " << endl; }
        ~C2() {  cout << "C2 d-tor " << endl; }
};
// ------------------------------------------------------------------------------------------------
class M1{
    public:
        M1() { cout << "M1 c-tor " << endl; }
        ~M1() { cout << "M1 d-tor " << endl; }
};
// ------------------------------------------------------------------------------------------------
class M2{
    public:
        M2() { cout << "M2 c-tor " << endl; } 
        ~M2() {  cout << "M2 d-tor " << endl; }
};
// ------------------------------------------------------------------------------------------------
class X : public C1, public C2{
   public:
        X() { cout << "X c-tor " << endl; } 
        ~X() { cout << "X d-tor " << endl; } 
        M1 m1;
        M2 m2;
};
// ------------------------------------------------------------------------------------------------
int main(){
    X x;
}
