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
        take.open("D:\\Учёба\\Файлы общего доступа\\Tempo Se Ne Va.wav");

        take.read(chunkId, sizeof(chunkId));
        take.read((char*)&chunkSize, sizeof(chunkSize));
        take.read(format, sizeof(format));
        take.read(subchunk1Id, sizeof(subchunk1Id));
        take.read((char*)&subchunk1Size, sizeof(subchunk1Size));
        take.read((char*)&audioFormat, sizeof(audioFormat));
        take.read((char*)&numChannels, sizeof(numChannels));
        take.read((char*)&sampleRate, sizeof(sampleRate));
        take.read((char*)&byteRate, sizeof(byteRate));
        take.read((char*)&blockAlign, sizeof(blockAlign));
        take.read((char*)&bitsPerSample, sizeof(bitsPerSample));
        take.read(subchunk2Id, sizeof(subchunk2Id));
        take.read((char*)&subchunk2Size, sizeof(subchunk2Size));

        cout << chunkId << endl << chunkSize << endl << format << endl << subchunk1Id << endl << subchunk1Size << endl << audioFormat << endl << numChannels << endl << sampleRate << endl << byteRate << endl << blockAlign <<  endl << bitsPerSample << endl << subchunk2Id << endl << subchunk2Size <<endl;

    }
    
};


int main() {
    WavHeader Test_1;
    Test_1.ReadHuy("D:\\Учёба\\Файлы общего доступа\\Tempo Se Ne Va.wav");
}
