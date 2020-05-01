#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

<<<<<<< HEAD
struct WAVHEADER{
=======
class WavHeader {
>>>>>>> c044c1893b42374b70a373b573860acff14f3a09
    char chunkId[4];
    unsigned long chunkSize;
    char format[4];
    char subchunk1Id[4];
    unsigned long subchunk1Size;
    unsigned short audioFormat;
    unsigned short numChannels;
    unsigned long sampleRate;
    unsigned long byteRate;
    unsigned short blockAlign;
    unsigned short bitsPerSample;
    char subchunk2Id[4];
    unsigned long subchunk2Size;
<<<<<<< HEAD
};

int main(){
    ifstream inpWav;
    string key;
    inpWav.open("D:\\Учёба\\Файлы общего доступа\\Tempo Se Ne Va.wav", ios::binary);
    WAVHEADER header;
    char t;
    for (int i = 0; i < sizeof(header); i++) {
        inpWav.get(t);
        cout << t;
    }
    inpWav.close();
    cout << endl <<endl;
    return 0;
=======
public:
    void ReadHuy(string address) {
        ifstream take;
        take.open("D:\\Учёба\\Файлы общего доступа\\test_1.wav");
        take >> chunkId;
        cout << chunkId;
        take >> chunkSize;
        cout << chunkSize;
    }
    
};


int main() {
    WavHeader Test_1;
    Test_1.ReadHuy("D:\\Учёба\\Файлы общего доступа\\test_1.wav");
>>>>>>> c044c1893b42374b70a373b573860acff14f3a09
}