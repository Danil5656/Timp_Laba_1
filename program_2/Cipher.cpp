#include "Cipher.h"

Cipher::Cipher(int k)
{
    key=k;
}

wstring Cipher::EncodeCipher(Cipher ob, wstring wstr)
{
    wstring Uptshot;
    int CountStrok;
    if (wstr.length()%ob.key!=0)
        CountStrok=wstr.length()/ob.key+1;
    else
        CountStrok=wstr.length()/ob.key;

    int pointer = 0;
    wchar_t table[CountStrok][ob.key];
    for (int i = 0; i <CountStrok; i++) {
        for (int j = 0; j < ob.key; j++ ) {
            if (pointer < wstr.size()) {
                table[i][j] = wstr[pointer];
                pointer++;
            } else {
                table[i][j] =' ';
            }
        }
    }
//Uptshot.resize(CountStrok*ob.key); // устанавливаем размер строки, чтобы не было ошибок с памятью
    for (int i = 0; i < ob.key; i++) {
        for (int j = 0; j < CountStrok; j++ ) {
            Uptshot+=(table[j][i]);
        }
    }
    return Uptshot;
}

wstring Cipher::DecodeCipher(Cipher ob, wstring wstr)
{
    wstring Uptshot;
    int pointer = 0;
    int CountStrok;
    if (wstr.length()%ob.key!=0)
        CountStrok=wstr.length()/ob.key+1;
    else
        CountStrok=wstr.length()/ob.key;


    wchar_t table[CountStrok][ob.key];

    for (int i = 0; i < ob.key; i++) {
        for (int j = 0; j < CountStrok; j++ ) {
            if (pointer < wstr.size()) {
                table[j][i] = wstr[pointer];
                pointer++;
            } else {
                table[j][i] = ' ';
                pointer++;
            }
        }
    }
//Uptshot.resize(CountStrok*ob.key); // устанавливаем размер строки, чтобы не было ошибок с памятью
    for(int i = 0; i < CountStrok; i++) {
        for (int j = 0; j< ob.key; j++) {
            Uptshot +=(table[i][j]);
        }
    }
    return Uptshot;
}
