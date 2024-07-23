#include <iostream>
#include <memory>

using namespace std;

class Widget{
    public:
    Widget(int val) : value(val){
        cout << "Widget created: " << val << endl;
    }
    ~Widget(){
        cout << "Widget destroyed " << endl;
    }

    int value;
};

void processWidget(shared_ptr<Widget> widget){
    cout << "Processing Widget: " << widget->value << endl;
}

int main(){

    shared_ptr<Widget> w1 = make_shared<Widget>(10);
    {
        shared_ptr<Widget> w2 = w1;
        cout << "w1 count: " << w1.use_count() << endl;
        cout << "w2 count: " << w2.use_count() << endl;
        processWidget(w2);
    }
    cout << "w1 count: " << w1.use_count() << endl;
    
    shared_ptr<Widget> w3 = make_shared<Widget>(20);
    weak_ptr<Widget> wp = w3;

    if(auto sp = wp.lock()){
        cout << " weak ptr locked" << sp->value << endl;
    }
    w3.reset();

    if(wp.expired()){
        cout << "weak ptr expired" << endl;
    }
    return 0;
}