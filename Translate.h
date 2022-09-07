#pragma once
#define CURL_STATICLIB
#include <iostream>
#include<SFML/Graphics.hpp>
#include<curl/curl.h>
#include <string>
#include <fstream>
#include<windows.h>
#include<Windows.h>
#include"Button.h"
#include"Field.h"
#include<ctime>
#define random(a,b) a+rand()%(b+1-a);
using namespace std;
using namespace sf;

class Translate
{
private:
	RenderWindow window;
	Button* transl;
	Button* training;
	Button* more;
	Button* test;
	Button* exit;
	Field* window1;
	Field* window1_0;
	Field* window1_1;
	Field* window2;
	Field* window2_2;
	Field* window3;
	Field* window3_3;
	Field* window4;
	Field* window4_4;
	Field* window5;
	Field* window5_5;
	Field* result;
	Button** buttons;
	Field** fields;
	Field* field;
	Button* search;
	string text;
	int maxStr = 102762;
	
	//Training* trenirov;
public:

	Translate();
	void run();
	void windows();
	void windowsTranslate();
	void windowsTraining();
	void windowsTranslateResult();
	string http(string str2);
	static size_t getResponsetoString(void* contents, size_t size, size_t nmemb, void* userp);
	string choose(string& str);
	//void recTxt(std::string& str, std::string& path);
	string translSearch(string str);
	//String extract(string path);
	void setMaxStr(int a);
	int getMaxStr();
	string UTF8_to_CP1251(std::string const& utf8);
	void game();
	void Ggame();
	
};

