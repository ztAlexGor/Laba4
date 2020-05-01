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
        take.open(address);
        take.read(chunkId, 4);
        cout << chunkId[0] << chunkId[1] << chunkId[2] << chunkId[3] << endl;
        take >> chunkSize;
        cout << chunkSize << endl;
        take.seekg(8);
        take.read(format, 4);
        cout << format[0] << format[1] << format[2] << format[3] << endl;
        take.read(subchunk1Id, 4);
        cout << subchunk1Id[0] << subchunk1Id[1] << subchunk1Id[2] << subchunk1Id[3] << endl;
        take >> subchunk1Size;
        cout << subchunk1Size;
    }
    
};


int main() {
    WavHeader Test_1;
    Test_1.ReadHuy("D:\\Учёба\\Файлы общего доступа\\Tempo Se Ne Va.wav");
}