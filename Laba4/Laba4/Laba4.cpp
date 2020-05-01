#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct WAVHEADER{
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
}