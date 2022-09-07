#include "Translate.h"





Translate::Translate():window(sf::VideoMode(600,800),L"Translate")
{
	transl = new Button(160, 50, "Translate");
	transl->setPosition(50, 200);
	training = new Button(160, 50, "Training");
	training->setPosition(390, 200);
	exit = new Button(90, 50, "Exit");
	exit->setPosition(240, 600);
	exit->setColorButton(Color::Red);
	more = new Button(90, 50, "More");
	more->setColorButton(Color::Black);
	more->setPosition(300, 400);
	test = new Button(80, 50, "Test");
	test->setColorButton(Color::Black);
	test->setPosition(500, 400);
	field = new Field(500, 30);
	field->setPosition(50, 25);
	search = new Button(180, 35, "Search");
	search->setColorButton(Color::Blue);
	search->setPosition(210, 60);
	search->setPosText(40, 0);
	window1 = new Field(375, 40);
	window1->setPosition(175, 25);
	window1->setOutlineThickness(0);
	window1_0 = new Field(250, 30);
	window1_0->setPosition(25, 70);
	window1_0->setOutlineCol(sf::Color::Black);
	window1_1 = new Field(250, 30);
	window1_1->setPosition(325, 70);
	window1_1->setOutlineCol(sf::Color::Black);
	window2 = new Field(250, 30);
	window2->setPosition(25, 100);
	window2->setOutlineCol(sf::Color::Black);
	window2_2 = new Field(250, 30);
	window2_2->setPosition(325, 100);
	window2_2->setOutlineCol(sf::Color::Black);
	window3 = new Field(250, 30);
	window3->setPosition(25, 130);
	window3->setOutlineCol(sf::Color::Black);
	window3_3 = new Field(250, 30);
	window3_3->setPosition(325, 130);
	window3_3->setOutlineCol(sf::Color::Black);
	window4 = new Field(250, 30);
	window4->setPosition(25, 160);
	window4->setOutlineCol(sf::Color::Black);
	window4_4 = new Field(250, 30);
	window4_4->setPosition(325, 160);
	window4_4->setOutlineCol(sf::Color::Black);
	window5 = new Field(250, 30);
	window5->setPosition(25, 190);
	window5->setOutlineCol(sf::Color::Black);
	window5_5 = new Field(250, 30);
	window5_5->setPosition(325, 190);
	window5_5->setOutlineCol(sf::Color::Black);
	result = new Field(250, 30);
	result->setPosition(325, 600);
	result->setOutlineCol(sf::Color::Black);
	buttons = new Button * [3] {transl, training};
	fields = new Field * [10] {window1_0, window1_1, window2, window2_2, window3, window3_3, window4, window4_4, window5, window5_5};
	//trenirov = new Training(600, 800);
	//trenirov->setColorButton(Color::Blue);
}

void Translate::run()
{
	
	sf::Event event;
	sf::Vector2i localPosition;
	windows();
	Cursor cursor;
	cursor.loadFromSystem(Cursor::Arrow);
	window.setMouseCursor(cursor);
	while (window.isOpen())
	{		
		bool flag;
		bool flag2 = true;
		int i;
		/*while (window.pollEvent(event))
		{
			if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed)
			{
				window.close();
			}
		}*/
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			flag = true;
			localPosition = sf::Mouse::getPosition(window);
			while (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{

			}
			if(localPosition.x >= exit->getPos().x &&
				localPosition.x <= exit->getPos().x + 79 &&
				localPosition.y >= exit->getPos().y &&
				localPosition.y <= exit->getPos().y + 49)window.close();
			for (i = 0; i < 2; i++)
			{
				if (localPosition.x >= buttons[i]->getPos().x &&
					localPosition.x <= buttons[i]->getPos().x + 159 &&
					localPosition.y >= buttons[i]->getPos().y &&
					localPosition.y <= buttons[i]->getPos().y + 49)
				{
					//Переводчик
					if (i == 0)
					{
						windowsTranslate();
						String str;
						while (flag) {
							localPosition = sf::Mouse::getPosition(window);
							if (sf::Mouse::isButtonPressed(sf::Mouse::Left) ) {

								if (localPosition.x >= search->getPos().x &&
									localPosition.x <= search->getPos().x + 179 &&
									localPosition.y >= search->getPos().y &&
									localPosition.y <= search->getPos().y + 34 ||event.text.unicode == 13)
								{
									string str4= field->getTextToString();
									String str3 = field->getTextToString();
									string s = "%20";
									for (int i = 0; i < str4.size(); i++)
									{
										if (str3[i] == ' ')str3.replace(i, 1, s);
									}
									string str2=translSearch(str3);
									//str = field->getTextToString();
									cout << str2.size() << endl;
									cout << str2;
									field->setField(sf::String::fromUtf8(str2.begin(), str2.end()));
									//field->setSizeStr(str.size());
									flag2 = false;
								}
								
							}
							while (window.pollEvent(event))
							{
								
								if (event.key.code == sf::Keyboard::LShift)
								{
									flag2 = true;
									str.clear();
									field->setSizeStr(0);
								}

								if (event.type == Event::TextEntered)
								{
									
									if (event.text.unicode == 8)
									{
										if (field->getSizeStr()>0)
										{
											str.erase(field->getSizeStr() - 1);
											field->setSizeStr(field->getSizeStr() - 1);
										}
									}
									else
									{
										str += static_cast<wchar_t>(event.text.unicode);
										field->setSizeStr(field->getSizeStr() + 1);
									}
									if (event.text.unicode == 27)
									{
										flag = false;
									}
								}

								//ENTER  НЕ РАБОТАЕТ
								
								//else if (event.key.code == sf::Keyboard::Enter)
								//{
								//	Sleep(500);
								//	str.erase(field->getSizeStr() - 1);
								//	field->setSizeStr(field->getSizeStr() - 1);
								//	field->setField(str);
								//	string str2 = translSearch(field->getTextToString());
								//	//str = field->getTextToString();
								//	cout << str2.size() << endl;
								//	cout << str2;
								//	field->setField(sf::String::fromUtf8(str2.begin(), str2.end()));
								//	//field->setSizeStr(str.size());
								//	flag2 = false;
								//}

							}							
							if(flag2)field->setField(str);
							windowsTranslate();
						}
					}
					else if (i == 1)
					{
						Ggame();
					}
				}
			}
		}
		windows();
	}
}

void Translate::windows()
{
	
	Image image, imageFon;
	imageFon.loadFromFile("..\\prog\\Debug\\Big_Ben.jpg");
	Texture texture, textureFon;
	textureFon.loadFromImage(imageFon);
	window.setFramerateLimit(60);
	Sprite splite;
	splite.setTexture(textureFon);
	window.draw(splite);
	window.draw(transl->getButton());
	window.draw(transl->getText());
	window.draw(training->getButton());
	window.draw(training->getText());
	window.draw(exit->getButton());
	window.draw(exit->getText());
	window.display();
}

void Translate::windowsTranslate()
{
	window.clear();
	Image image, imageFon;
	imageFon.loadFromFile("..\\prog\\Debug\\Monuments.jpg");
	Texture texture, textureFon;
	textureFon.loadFromImage(imageFon);
	window.setFramerateLimit(60);
	Sprite splite;
	splite.setTexture(textureFon);
	window.draw(splite);
	window.draw(field->getField());
	window.draw(field->getText());
	window.draw(search->getButton());
	window.draw(search->getText());
	window.display();
}

void Translate::windowsTraining()
{
	window.clear();
	Image image, imageFon;
	imageFon.loadFromFile("..\\prog\\Debug\\London-Clock.jpg");
	Texture texture, textureFon;
	textureFon.loadFromImage(imageFon);
	window.setFramerateLimit(60);
	Sprite splite;
	splite.setTexture(textureFon);
	window.draw(splite);
	window.draw(window1->getField());
	window.draw(window1->getText());
	window.draw(window1_0->getField());
	window.draw(window1_0->getText());
	window.draw(window1_1->getField());
	window.draw(window1_1->getText());
	window.draw(window2->getField());
	window.draw(window2->getText());
	window.draw(window2_2->getField());
	window.draw(window2_2->getText());
	window.draw(window3->getField());
	window.draw(window3->getText());
	window.draw(window3_3->getField());
	window.draw(window3_3->getText());
	window.draw(window4->getField());
	window.draw(window4->getText());
	window.draw(window4_4->getField());
	window.draw(window4_4->getText());
	window.draw(window5->getField());
	window.draw(window5->getText());
	window.draw(window5_5->getField());
	window.draw(window5_5->getText());
	window.draw(test->getButton());
	window.draw(test->getText());
	window.draw(more->getButton());
	window.draw(more->getText());
	window.draw(result->getField());
	window.draw(result->getText());
	window.display();
}

void Translate::windowsTranslateResult()
{
	sf::Event event;
	sf::Vector2i localPosition;
	Cursor cursor;
	cursor.loadFromSystem(Cursor::Arrow);
	window.setMouseCursor(cursor);
	window.clear();
	Image image, imageFon;
	imageFon.loadFromFile("..\\prog\\Debug\\London-Clock.jpg");
	Texture texture, textureFon;
	textureFon.loadFromImage(imageFon);
	window.setFramerateLimit(60);
	Sprite splite;
	int k = 0;
	String str;
	if (k == 0) {
		str = L"Запишите слово и нажмите Test";
	}
	splite.setTexture(textureFon);
	window.draw(splite);
	window1->setField(str);
	window.draw(window1->getField());
	window.draw(window1->getText());
	/*window.draw(window1_0->getField());
	window.draw(window1_0->getText());
	window.draw(window1_1->getField());
	window.draw(window1_1->getText());
	window.draw(window2->getField());
	window.draw(window2->getText());
	window.draw(window2_2->getField());
	window.draw(window2_2->getText());
	window.draw(window3->getField());
	window.draw(window3->getText());
	window.draw(window3_3->getField());
	window.draw(window3_3->getText());
	window.draw(window4->getField());
	window.draw(window4->getText());
	window.draw(window4_4->getField());
	window.draw(window4_4->getText());
	window.draw(window5->getField());
	window.draw(window5->getText());
	window.draw(window5_5->getField());
	window.draw(window5_5->getText());
	window.draw(test->getButton());
	window.draw(test->getText());
	window.draw(more->getButton());
	window.draw(more->getText());
	window.draw(result->getField());
	window.draw(result->getText());*/
	for (int i = 1; i < 10; i += 2)
	{
		bool flag = true;
		window.draw(fields[i]->getField());
		window.draw(fields[i]->getText());
		window.display();
		String st;
		while (flag)
		{
			localPosition = sf::Mouse::getPosition(window);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				while (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{

				}

				if (localPosition.x >= test->getPos().x &&
					localPosition.x <= test->getPos().x + 79 &&
					localPosition.y >= test->getPos().y &&
					localPosition.y <= test->getPos().y + 49)
				{
					if (result->getFieldStr() == fields[i-1]->getFieldStr()) 
					{
						str = L"Верно,следующее слово";
						
					}
					else 
					{ 
						str = L"НЕверно, следующее слово"; 
					}
					window1->setField(str);
					flag = false;
				}
			}
			while (window.pollEvent(event))
			{
				if (event.type == Event::TextEntered)
				{

					if (event.text.unicode == 8)
					{
						if (result->getSizeStr() > 0)
						{
							st.erase(result->getSizeStr() - 1);
							result->setSizeStr(result->getSizeStr() - 1);
						}
					}
					else
					{
						st += static_cast<wchar_t>(event.text.unicode);
						result->setSizeStr(result->getSizeStr() + 1);
					}
				}
			}
			window.clear();
			Image image, imageFon;
			imageFon.loadFromFile("..\\prog\\Debug\\London-Clock.jpg");
			Texture texture, textureFon;
			textureFon.loadFromImage(imageFon);
			window.setFramerateLimit(60);
			Sprite splite;
			splite.setTexture(textureFon);
			window.draw(splite);
			result->setField(st);
			window.draw(window1->getField());
			window.draw(window1->getText());
			window.draw(result->getField());
			window.draw(result->getText());
			window.draw(fields[i]->getField());
			window.draw(fields[i]->getText());
			window.draw(test->getButton());
			window.draw(test->getText());
			window.display();
		}
	}
}

string Translate::http(string str2)
{
	string str_response;
	//str2 = "Car";
	std::string zapros = "https://fasttranslator.herokuapp.com/api/v1/text/to/text?source=" + str2 + "&lang=en-ru";
	//int size2 = size(str2);
	const char* slovo2 = zapros.c_str();
	std::cout << slovo2;
	CURL* curl;
	CURLcode response;
	curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_URL, slovo2);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, getResponsetoString);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &str_response);
	response = curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	std::cout << str_response;
	std::cout << std::endl << std::endl;
	std::string str3 = choose(str_response);
	//std::cout << choose(str_response);
	//std::string path = "C:\\Users\\Марина\\Desktop\\Новый текстовый документ.txt";
	//if(str3.size()>100)str3="Вы ввели не верное слово";
	return str3;

}

size_t Translate::getResponsetoString(void* contents, size_t size, size_t nmemb, void* userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

string Translate::choose(string& str)
{
	for (int i = 0, k = 0; i < size(str); i++)
	{
		if (str[i] == '"')k++;
		if (k == 13)
		{
			std::string str2 = "";
			for (int j = i + 1; str[j] != '"'; j++)
			{	
				 str2 += str[j];
			}
			return str2;
		}
	}
}

//void Translate::recTxt(std::string& str, std::string& path)
//{
//	cout<<UTF8_to_CP1251(str);
//	std::fstream out{ path };
//	out << str;
//	out.close();
//}

string Translate::translSearch(string str)
{
	return http(str);
}

//String Translate::extract(string path)
//{
//	fstream in{ path };
//	string str;
//	if (in.is_open()) {
//		while (getline(in, str))
//		{
//			field->setField(str);
//		}
//	}
//	in.close();
//	return str;
//}

void Translate::setMaxStr(int a)
{
	this->maxStr = a;
}

int Translate::getMaxStr()
{
	return maxStr;
}

string Translate::UTF8_to_CP1251(std::string const& utf8)
{
	if (!utf8.empty())
	{
		int wchlen = MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), utf8.size(), NULL, 0);
		if (wchlen > 0 && wchlen != 0xFFFD)
		{
			std::vector<wchar_t> wbuf(wchlen);
			MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), utf8.size(), &wbuf[0], wchlen);
			std::vector<char> buf(wchlen);
			WideCharToMultiByte(1251, 0, &wbuf[0], wchlen, &buf[0], wchlen, 0, 0);
			/*for (int i = 0; i<wchlen; i++)
			{
				cout << buf[i];
			}*/

			return std::string(&buf[0], wchlen);
		}
	}
	return std::string();
}


void Translate::game()
{
	string path = "..\\prog\\Debug\\engrus1.txt";
	fstream in{ path };
	string str;
	int count = 0;
	int* array = new int[5];
	for (int i = 0; i < 5; i++)
	{
		array[i] = random(1, maxStr);
		if (array[i] % 2 != 0)array[i]++;
	}
	for (int i = 0; i < 5; i++)
	{
		count = 0;
		bool flag = true;
		while (getline(in, str))
		{

			if (count == array[i])
			{
				cout << str << endl;
				if (i == 0)window1_0->setField(str);
				else if (i == 1)window2->setField(str);
				else if (i == 2)window3->setField(str);
				else if (i == 3)window4->setField(str);
				else if (i == 4)window5->setField(str);
				flag = false;
				if (!flag)
				{
					count++;
					continue;
				}

			}
			if (!flag)
			{
				/*if (str.size() >= 18)
				{
					string st;
					int j = 0;
					while (str[j] != ' ' && str[j] != -79 && str[j] != '\t' && str[j] != -126)
					{
						cout << str[j];
						st += str[j++];
					}
					str.clear();
					str = st;
				}*/
				cout << str << endl;
				if (i == 0)window1_1->setField(sf::String::fromUtf8(str.begin(), str.end()));
				else if (i == 1)window2_2->setField(sf::String::fromUtf8(str.begin(), str.end()));
				else if (i == 2)window3_3->setField(sf::String::fromUtf8(str.begin(), str.end()));
				else if (i == 3)window4_4->setField(sf::String::fromUtf8(str.begin(), str.end()));
				else if (i == 4)window5_5->setField(sf::String::fromUtf8(str.begin(), str.end()));
				break;
			}
			count++;
		}
		cout << count;
		
		windowsTraining();
		Sleep(7000);
	}
	in.close();
}

void Translate::Ggame()
{
	bool trenir = true;
	String strMenu = L"\tЗапомните слова и перевод \n\n\n\n\n\n\n\n\n\n\t\t\t\tУ Вас 30 сек";
	window1->setField(strMenu);
	//windowsTraining();
	game();
	windowsTranslateResult();
	//system("pause");
}




