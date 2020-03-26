#include <iostream>
#include <queue>
#include "Stack.h"

using namespace std;

int main() {
    Stack<int> t;
    t.push(33);
    t.push(22);
    t.push(11);
    int w;
    cout<<t.pop(w)<<' '<<w<<endl;
    cout<<t.pop(w)<<' '<<w<<endl;
    cout<<t.pop(w)<<' '<<w<<endl;
    cout<<t.pop(w)<<' '<<w<<endl;
    t.push(332);
    cout<<t.pop(w)<<' '<<w<<endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
