#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

class WavHeader {
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
}