#include "Cipher.h"
#include <locale>
#include <codecvt>
int main()
{
    bool flag = true;
    string regime,Neregime,str;
    cout << "Добро пожаловать в программу!" << endl;
    cout << "Encode - режим шифрования шифром табличной маршрутной перестановки. \n";
    cout << "Decode - режим расшифрования шифра табличной маршрутной перестановки.\n";
    cout << "Чтобы завершить работу программу, введите \"exit\"." << endl;
    do {
        locale loc("ru_RU.UTF-8");
        locale::global(loc);
        cout << "Выберите режим работы:";
        cin >> regime;
        if (regime == "Encode") {
            cout << "Введите текст для шифрования:";
            cin.get();
            getline(cin, str);
            int key;
            cout << "Введите ключ:";
            cin >> key;
            Cipher encode(key);
            wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
            wstring wstren = codec.from_bytes(str);
            cout<<codec.to_bytes(encode.EncodeCipher(encode,wstren))<<endl;
        }
        if (regime == "Decode") {
            cout << "Введите текст для расшифрования:";
            cin.get();
            getline(cin, str);
            int key;
            cout << "Введите ключ:";
            cin >> key;
            Cipher decode(key);
            wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
            wstring wstrdec = codec.from_bytes(str);
            cout<<codec.to_bytes(decode.DecodeCipher(decode,wstrdec))<<endl;
        }
        if (regime == "exit") {
            cout << "Программа завершила работу." << endl;
            flag = false;
            break;
        }
    } while (flag != false);
    return 0;
}
