#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
    
    ifstream wav;
    string key;
    wav.open("D:\\Учёба\\Файлы общего доступа\\Tempo Se Ne Va.wav", ios::binary);
    wav >> key;
    cout << key;
    cout << endl;
    wav >> key;
    cout << key;
    cout << endl;
    wav >> key;
    cout << key;
    cout << endl;

    return 0;
}