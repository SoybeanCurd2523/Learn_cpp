#include <iostream>

// using namespace std;
// int main(){
//     cout << "Hello, World!" << endl;  // endl이 \n 줄바꿈문자이다

//     int a, b;
//     cin >> a >> b;

//     cout << a+b << endl;
// }


#include <string>

using namespace std;

int main(){
    string name;
    
    cout << "이름 입력 :";
    cin >> name;

    string message = "안녕하세요" + name + "님";
    cout << message << endl;
}