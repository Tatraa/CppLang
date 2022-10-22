#include <iostream>

using namespace std;

class Drawing{
    public:
        Drawing() {}
        virtual ~Drawing() {}
        virtual void drawLine() {}
        virtual void drawCircle() {}
};

class DP1{
    public:
        DP1() {}
        virtual ~DP1() {}
        void draw_a_line(){
            cout << "linia V1" << endl;
        }
        void draw_a_circle(){
            cout << "okrag V1" << endl;
        }
};

class DP2{
    public:
        DP2() {}
        virtual ~DP2() {}
        void drawline(){
            cout << "linia V2" << endl; 
        }
        void drawcircle(){
            cout << "okrag V2" << endl;
        }
}; 

class V1Drawing : public Drawing{
    public:
        V1Drawing(DP1 l1) : l(l1) {}
        virtual ~V1Drawing() {}
        void drawLine() override{
            this -> l.draw_a_line();
        }
        void drawCircle() override{
            this -> l.draw_a_circle();
        }
    private:
        DP1 l;
};

class V2Drawing : public Drawing{
    public:
        V2Drawing(DP2 l2) : l(l2) {}
        virtual ~V2Drawing() {}
        void drawLine() override{
            this -> l.drawline();
        }
        void drawCircle() override{
            this -> l.drawcircle();
        }
    private:
        DP2 l;
};
//------------------------------------------------------------------------------------
class Shape{
    public:
       Shape() {}
       virtual ~Shape() {}
       virtual void draw() {}
       virtual void setLib(Drawing* lib) {}
};

class Rectangle : public Shape{
     public:
        Rectangle(Drawing* lib) : d_lib(lib) {}
        virtual ~Rectangle() {}
        void draw(){
            d_lib -> drawLine();
        }
        void setLib(Drawing *lib){
            d_lib = lib;
        }
    private:
        Drawing *d_lib;
};

class Circle : public Shape{
    public:
        Circle(Drawing* lib) : d_lib(lib) {}
        virtual ~Circle() {}
        void draw(){
            d_lib -> drawCircle();
        }
        void setLib(Drawing *lib){
            d_lib = lib;
        }
    private:
        Drawing *d_lib;
};

int main(){
    DP1 library1; // pierwsza biblioteka 
    DP2 library2; // druga biblioteka 
    Drawing *d1 = new V1Drawing( library1 ); 
    Drawing *d2 = new V2Drawing( library2 ); 
    Shape *p1 = new Rectangle( d1 ); 
    Shape *p2 = new Circle( d2 ); 
    p1->draw(); // rectangle linia V1 
    p2->draw(); // circle okrag V2
    p1->setLib( d2 ); 
    p2->setLib( d1 ); 
    p1->draw(); // rectangle linia V2 
    p2->draw(); // circle okrag V1

    delete p1;
    delete p2;
    delete d1;
    delete d2;
}