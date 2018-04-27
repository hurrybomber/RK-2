#include "Queue.hpp"
#include <sstream>
#include <fstream>

using namespace std;

int main() {
    Queue<int> a1;
    Queue<int> a2 = {1, 2, 3, 4};
    Queue<int> a3{a2};
    cout << a2 << endl;
    cout << a3 << endl;
    a1.swap(a3);
    cout << a1 << endl;
    cout << boolalpha << a3.empty() << endl;
    cout << a1.size() << endl;
    cout << a2.size() << endl;
    a3.push(5);
   cout << boolalpha << a2.empty() << endl;
    cout << a3 << endl;
    ofstream output{ "queue.bin" };
    output << a3;
    output.close();
    Queue<int> a4;
    ifstream input{ "queue.bin" };
    input >> a4;
    input.close();
    cout << (a4 == a3) << endl;
    try {
        a4.front();
    }
    catch (logic_error e) { cout << "empty" << endl; 
    a4.pop();
    cout << a4 << endl;
    try {
        a4.front() = 6;
    }
    catch (logic_error e) { cout << e.what() << endl; }
    exit(0);
}
