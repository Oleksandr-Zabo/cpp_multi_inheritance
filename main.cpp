#include <iostream>
using namespace std;

// Base template class
template <typename T1, typename T2>
class base {
protected:
    T1 value1;
    T2 value2;

public:
    base(T1 v1, T2 v2) {
		cout << "Base class constructor" << endl;
		value1 = v1;
		value2 = v2;
    }
    base() : value1(T1()), value2(T2()) {}

    void setValue1(T1 v1) { 
        value1 = v1; 
    }
    void setValue2(T2 v2) { 
        value2 = v2; 
    }

    T1 getValue1() const { 
        return value1; 
    }

    T2 getValue2() const { 
        return value2; 
    }

    virtual ~base() {
		cout << "Base class destructor" << endl;
    }
};

// Derived class
template <typename T1, typename T2, typename T3, typename T4>
class child : public base<T1, T2> {
protected:
    T3 value3;
    T4 value4;

public:
    child(T1 v1, T2 v2, T3 v3, T4 v4) : base<T1, T2>(v1, v2){
		cout << "Child class constructor" << endl;
		value3 = v3;
		value4 = v4;
    }
    child() : base<T1, T2>(), value3(T3()), value4(T4()) {}

    void setValue3(T3 v3) { value3 = v3; }
    void setValue4(T4 v4) { value4 = v4; }

    T3 getValue3() const { return value3; }
    T4 getValue4() const { return value4; }

    ~child() {
		cout << "Child class destructor" << endl;
    }
};

// Second-level derived class
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class child2 : public child<T1, T2, T3, T4> {
protected:
    T5 value5;
    T6 value6;

public:
    child2(T1 v1, T2 v2, T3 v3, T4 v4, T5 v5, T6 v6) : child<T1, T2, T3, T4>(v1, v2, v3, v4) {
        cout << "Child2 class constructor" << endl;
        value5 = v5;
		value6 = v6;
    }
    child2() : child<T1, T2, T3, T4>(), value5(T5()), value6(T6()) {}

    void setValue5(T5 v5) { value5 = v5; }
    void setValue6(T6 v6) { value6 = v6; }

    T5 getValue5() const { return value5; }
    T6 getValue6() const { return value6; }

    ~child2() {
        cout << "Child2 class destructor" << endl;
    }
};


int main() {
    // Testing the classes
    child2<int, double, char, string, bool, float>* my_obj = new child2<int, double, char, string, bool, float>(1, 2.5, 'A', "Hello", true, 3.14);

	cout << "Value1: " << my_obj->getValue1() << endl;
	cout << "Value2: " << my_obj->getValue2() << endl;
	cout << "Value3: " << my_obj->getValue3() << endl;
	cout << "Value4: " << my_obj->getValue4() << endl;
	cout << "Value5: " << my_obj->getValue5() << endl;
	cout << "Value6: " << my_obj->getValue6() << endl;

	delete my_obj;

    return 0;
}
