#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    cout << "start " << endl;
    cout << argc << endl;
    cout << argv[1] << endl;

    for (const string& word : msg)
    {
        
        cout << word << " ";
    }
    cout << endl;
}