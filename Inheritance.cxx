// Basic inheritance 
#include <bits/stdc++.h>
using namespace std;
class Parent{
    public:
    int age_p;
};
class Child : public Parent{
    public: int age_c;
};
int main() {
    Child obj;
    obj.age_p = 50;
    obj.age_c = 20;
    cout << "Age of Child is : " << obj.age_c;
    cout << "\nAge of Parent is : " << obj.age_p;
    return 0;
}


// Understanding public, protected and private mode of inheritance
#include <bits/stdc++.h>
using namespace std;
class A{
    public:
    int x;
    protected:
    int y;
    private:
    int z;
};
class B : public A{
    //cout << "x is public"
    //cout << "y is protected"
    //cout << "z is inaccessible"
};
class C : protected A{
    //cout << "x is protected"
    //cout << "y is protected"
    //cout << "z is inaccessible"
};
class D : private A{
    //cout << "x is private"
    //cout << "y is private"
    //cout << "z is inaccessible"
};





// Multiple Inheritance
#include <iostream>
using namespace std;
class Mobile{
    public:
    Mobile(){ cout << "Mobile Shop\n";}
};
class Gadget{
    public:
    Gadget(){cout << "Mobile is a gadget.";}
};
class Samsung : public Mobile, public Gadget{
};
int main(){
    Samsung obj;
    return 0;
}





// Multi-level Inheritance

/* A derived class is created from another derived class.*/

#include <iostream>
using namespace std;
class Mobile{
    public:
    Mobile(){ cout << "Mobile Shop\n";}
};
class Gadget : public Mobile{
    public:
    Gadget(){cout << "Mobile is a gadget.";}
};
class Samsung : public Gadget{
};
int main(){
    Samsung obj;
    return 0;
}




//Hierarchical Inheritance

/* More than one subclass is inherited from a single base class. 
i.e. more than one derived class is created from a single base class.*/

#include <iostream>
using namespace std;
class Mobile{
    public:
    Mobile(){ cout << "Mobile Shop\n";}
};
class Apple : public Mobile{
};
class Samsung : public Mobile{
};
int main(){
    Samsung obj1;
    Apple obj2;
    return 0;
}





//Hybrid (Virtual) Inheritance

/*Hybrid Inheritance is implemented by combining more than one type of inheritance. 
For example: Combining Hierarchical inheritance and Multiple Inheritance. */

#include <iostream>
using namespace std;
class Mobile{
    public:
    Mobile(){ cout << "Mobile Shop\n";}
};
class Siri{
    public:
    Siri(){
        cout << "Siri voice assistant is there only in Apple.";
    }
};
class Apple : public Mobile, public Siri{
};
class Samsung : public Mobile{
};
int main(){
    Samsung obj1;
    Apple obj2;
    return 0;
}





// Multipath inheritance

/* A derived class with two base classes and these two base classes have one common base class is called multipath inheritance.
Ambiguity can arise in this type of inheritance. */

#include <iostream>
using namespace std;
class A{
    public:
        int a;
};
class B : public A{
    public:
    int b;
};
class C : public A{
    public:
    int c;
};
class D : public B, public C{
    public:
    int d;
};

int main(){
    D obj;
    obj.B::a = 20;
    obj.C::a = 30;
    
    obj.b = 100;
    obj.c = 200;
    obj.d = 300;
    
    cout << "a of class B : " << obj.B::a;
    cout << "\na of class C : " << obj.C::a;
    
    cout << "\nvalue of b : " << obj.b;
    cout << "\nvalue of c : " << obj.c;
    cout << "\nvalue of d : " << obj.d;
    return 0;
}

/*If we need to access the data member of A through the object of D, we must specify the path from which a will be accessed,
whether it is from B or C, because compiler can’t differentiate between two copies of A in D.*/

// Avoid this ambiguity using Virtual Base Class 

#include <iostream>
using namespace std;
class A{
    public:
        int a;
};
class B : virtual public A{
    public:
    int b;
};
class C : virtual public A{
    public:
    int c;
};
class D : public B, public C{
    public:
    int d;
};

int main(){
    D obj;
    obj.B::a = 20;
    obj.C::a = 30;
    
    obj.b = 100;
    obj.c = 200;
    obj.d = 300;
    
    cout << "\na : " << obj.a;
    cout << "\nb : " << obj.b;
    cout << "\nc : " << obj.c;
    cout << "\nd : " << obj.d << '\n';
    return 0;
}
