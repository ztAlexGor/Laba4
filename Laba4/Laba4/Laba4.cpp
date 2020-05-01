#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

class WavHeader {
public:
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
    unsigned short first_sample;
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
        int index = 43;
        while (!(subchunk2Id[0] == 'd' && subchunk2Id[1] == 'a' && subchunk2Id[2] == 't' && subchunk2Id[3] == 'a')) {
            index += subchunk2Size;
            take.seekg(index);
            take.read(subchunk2Id, sizeof(subchunk2Id));
            take.read((char*)&subchunk2Size, sizeof(subchunk2Size));
        }
    }
    void ShowHeader() {
        
        cout << chunkId << endl << chunkSize << endl << format << endl << subchunk1Id << endl << subchunk1Size << endl << audioFormat << endl << numChannels << endl << sampleRate << endl << byteRate << endl << blockAlign << endl << bitsPerSample << endl << subchunk2Id << endl << subchunk2Size << endl;

        cout << subchunk2Size / bitsPerSample << endl;
    }
};

class NewWave {
public:
    WavHeader h;
    NewWave(WavHeader k, float coef):h(k) {
        h.subchunk2Size = h.subchunk2Size * coef;
        h.chunkSize = h.subchunk2Size + 36;
    }
    void Creating() {

        ofstream newFile;
        newFile.open("D:\\Учёба\\Файлы общего доступа\\Tempo Se Ne Va_2.wav", ios::binary);
        newFile.write(h.chunkId, sizeof(h.chunkId));
        newFile.write((char*)&h.chunkSize, sizeof(h.chunkSize));
        newFile.write(h.format, sizeof(h.format));
        newFile.write(h.subchunk1Id, sizeof(h.subchunk1Id));
        newFile.write((char*)&h.subchunk1Size, sizeof(h.subchunk1Size));
        newFile.write((char*)&h.audioFormat, sizeof(h.audioFormat));
        newFile.write((char*)&h.numChannels, sizeof(h.numChannels));
        newFile.write((char*)&h.sampleRate, sizeof(h.sampleRate));
        newFile.write((char*)&h.byteRate, sizeof(h.byteRate));
        newFile.write((char*)&h.blockAlign, sizeof(h.blockAlign));
        newFile.write((char*)&h.bitsPerSample, sizeof(h.bitsPerSample));
        newFile.write(h.subchunk2Id, sizeof(h.subchunk2Id));
        newFile.write((char*)&h.subchunk2Size, sizeof(h.subchunk2Size));
    }

};

int main() {
    WavHeader Test_1;
    Test_1.ReadHuy("D:\\Учёба\\Файлы общего доступа\\Tempo Se Ne Va.wav");
    Test_1.ShowHeader();
    float coef;
    cout << "Enter coefficient of expanding: ";
    cin >> coef;
    NewWave Test_2(Test_1, coef);
    (Test_2.h).ShowHeader();
    Test_2.Creating();
}
