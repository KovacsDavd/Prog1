#include <string>
#include <iostream>

using namespace std;

class B1 {
public:
    virtual void vf() { cout << "B1::vf()\n"; }
    void f() { cout << "B1::f()\n"; }
    virtual void pvf() = 0; //teljesen virtuális, absztrakt, a class is absztrakt lesz, sõt a szármoztatott osztályok is
                 //egészen addig ameddig ezt a függvényt nem irjuk felül a szármoztatott osztályban, nem példányosítható
};

class D1 : public B1 {
public:
    void vf() { cout << "D1::vf()\n"; }
};

class D2 : public D1 {
public:
    void pvf() { cout << "D2::pvf()\n"; }
};

class B2 {
public:
    virtual void pvf() = 0;
};

class D21 : public B2 {
public:
    string s;
    void pvf() { cout << s << endl; }
};

class D22 : public B2 {
public:
    int n;
    void pvf() { cout << n << endl; }
};

void f(B2& a)
{
    a.pvf();
}

int main()
{
    /*B1 b1;
    b1.vf();
    b1.f();

    D1 d1;
    d1.vf();
    d1.f();

    B1& b1ref = d1;
    b1ref.vf();
    b1ref.f();

    d1.f();
    d1.f();
    d1.f();*/

    D2 d2;
    d2.vf();
    d2.f();
    d2.pvf();
    
    D21 d21;
    d21.s = "string";
    d21.pvf();

    D22 d22;
    d22.n = 22;
    d22.pvf();

    f(d21);
    f(d22);
}
