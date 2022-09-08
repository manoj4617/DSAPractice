#include<iostream>
#include<list>

using namespace std;

int main(){
 
    list<int> num;
    num.push_back(2);
    num.push_back(3);
    num.push_back(7);
    num.push_front(5);

    list<int>::iterator it  = num.begin();
    ++it;
    num.insert(it, 100);
    cout << "Number : "<<*it<<endl;
    for(;it != num.end();++it){
        cout<< *it << endl;
    }
    return 0;
}