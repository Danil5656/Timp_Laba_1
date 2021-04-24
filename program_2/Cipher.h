#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Cipher
{
private:
    int key;
public:
    Cipher() = delete;
    Cipher(int k);
    wstring EncodeCipher(Cipher ob, wstring wstr);
    wstring DecodeCipher(Cipher ob, wstring wstr);
};
