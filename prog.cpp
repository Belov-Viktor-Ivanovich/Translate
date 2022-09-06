#define CURL_STATICLIB
//#pragma execution_character_set("utf-8")
#include<SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>
//#include<vector>
#include<curl/curl.h>
#include"Translate.h"
#include <locale>
#include <windows.h>
using namespace std;
using namespace sf;



int main()
{

    srand(time(NULL));
    /*SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");*/
    Translate translate;
    translate.run();

}

