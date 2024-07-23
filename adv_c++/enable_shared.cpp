#include <memory>
#include <iostream>

using namespace std;

class Widget : public enable_shared_from_this<Widget> {
    public:
    void doSomething(){
        cout << "Do Something" << endl;
    }

    shared_ptr<Widget> getShared(){
        return shared_from_this();
    }
};

int main(){

    shared_ptr<Widget> firstWidget = make_shared<Widget>();
    shared_ptr<Widget> secondWidget = firstWidget->getShared();
    cout << "ref count: " << firstWidget.use_count() << endl;
    firstWidget->doSomething();
    secondWidget->doSomething();

    return 0;
}