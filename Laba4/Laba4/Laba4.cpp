﻿#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <cstdio> 

using namespace std;

class WavHeader {
public:
    string Name_of_file;
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
    void Read() {
        ifstream take;
        take.open("D:\\Учёба\\Файлы общего доступа\\" + Name_of_file + ".wav", ios::binary);

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

        take.close();
    }
    void ShowHeader() {
        cout << chunkId[0] << chunkId[1] << chunkId[2] << chunkId[3] << endl << chunkSize << endl << format[0] << format[1] << format[2] << format[3] << endl << subchunk1Id[0] << subchunk1Id[1] << subchunk1Id[2] << subchunk1Id[3] << endl << subchunk1Size << endl << audioFormat << endl << numChannels << endl << sampleRate << endl << byteRate << endl << blockAlign << endl << bitsPerSample << endl << subchunk2Id[0] << subchunk2Id[1] << subchunk2Id[2] << subchunk2Id[3] << endl << subchunk2Size << endl;
    }
    WavHeader(string Name_of_file) :Name_of_file(Name_of_file) {}
};

class NewWave {
public:
    WavHeader h;
    unsigned long size_old;
    float coef;
    string Name_of_file;
    NewWave(WavHeader k, float coef) :coef(coef), h(k), size_old(k.subchunk2Size), Name_of_file(k.Name_of_file) {
        h.subchunk2Size = h.subchunk2Size * coef;
        h.chunkSize = h.subchunk2Size + 36;
    }
    void Creating() {
        string NewFileName = Name_of_file + "_with coef";
        if (remove("D:\\Учёба\\Файлы общего доступа\\Baila Maria_-sm_with coef.wav") != 0)cout << "ERROR! file is not delete" << endl;

        ofstream newFile;
        newFile.open("D:\\Учёба\\Файлы общего доступа\\" + NewFileName + ".wav", ios::binary);
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

        ifstream newTake;
        newTake.open("D:\\Учёба\\Файлы общего доступа\\" + Name_of_file + ".wav", ios::binary);
        unsigned long prev = 0, newInd;
        int16_t curr_value = 0, prev_value = 0;

        int16_t buffInp[100000];
        int size = 100000-1;
        while (!newTake.eof()) {
            for (int i = 0; i < size; i++) {
                if (newTake.eof()) {
                    size = i;
                    break;
                }
                newTake.read((char*)&buffInp[i], sizeof(buffInp[i]));
            }
            int sizeOut = (int)((float)size * coef);
            int16_t* buffOut = new int16_t[sizeOut];
            for (int curr = 0; curr < size; curr++) {
                curr_value = buffInp[curr];
                newInd = curr * coef;
                if (curr == 0) {
                    buffOut[newInd] = curr_value;
                }
                else if (newInd > prev) {
                    int temp = prev + 1;
                    int16_t function_value;
                    while (temp <= newInd) {
                        long t = (long)((float)prev_value + (((float)curr_value - (float)prev_value) / ((float)newInd - (float)prev)) * ((float)temp - (float)prev));
                        function_value = (int16_t)t;
                        buffOut[temp] = function_value;
                        temp++;
                    }
                }
                prev = newInd;
                prev_value = curr_value;
            }

            for (int i = 0; i < sizeOut; i++) {
                newFile.write((char*)&buffOut[i], sizeof(buffOut[i]));
            }
        }
        newTake.close();
        newFile.close();
    }
    void Just_copy() {
        string NewFileName = Name_of_file + "_justCopy_with coef";
        ofstream newFile;

        newFile.open("D:\\Учёба\\Файлы общего доступа\\" + NewFileName + ".wav", ios::binary);
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

        ifstream newTake;
        newTake.open("D:\\Учёба\\Файлы общего доступа\\" + Name_of_file + ".wav", ios::binary);

        unsigned short curr_value;
        for (unsigned long curr = 0; curr < size_old / (h.bitsPerSample / 8); curr++) {
            newTake.seekg(44 + curr * (h.bitsPerSample / 8));
            newTake.read((char*)&curr_value, sizeof(curr_value));
            for (int i = 0; i < coef; i++)
                newFile.write((char*)&curr_value, sizeof(curr_value));
        }
        newFile.close();
        newTake.close();
    }
};

int main() {
    string FileName = "Baila Maria_-sm";
    WavHeader Test_1(FileName);
    Test_1.Read();
    //Test_1.ShowHeader();
    float coef;
    cout << "Enter coefficient of expanding: ";
    cin >> coef;
    NewWave Test_2(Test_1, coef);
    //(Test_2.h).ShowHeader();
    //Test_2.Just_copy();
    Test_2.Creating();
}
