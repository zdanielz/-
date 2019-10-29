#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

string get_alf(int a) {
	string alf[30] = { "а" , "б", "в", "г", "д", "е", "ж", "з", "и", "к", "л", "м", "н", "о", "п", "р", "с", "т", "у", "ф", "х", "ц", "ч", "ш", "щ", "ы", "ь", "э", "ю", "я" };
	if ((a < 30) & (a > -1)) {
		return alf[a];
	}
	else if (a >= 30) {
		return alf[a % 30];
	}
	return "0";
}

int main(void) {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string alf_ch1[15], alf_ch2[15];
	int a = 0;
	string word_ = "?";
	word_ = (word_);
	cout << "введите слово: ";
	getline(cin, word_);
	int size = word_.length();
	cout << "длина слова - " << size << endl;
	string* word = new string[size];
	string* buf = new string[size];
	for (int i = 0; i < size; i++)
	{
		word[i] = word_[i];
	}
	
	for (int i = 0; i < size; i++)
	{
		cout << word[i];
	}
	cout << endl << "====================";

	for (int i = 0; i < 15; i++)
	{
		for (int j = i; j < i + 15; j++)
		{
			alf_ch1[a] = get_alf(j);
			alf_ch2[a] = get_alf(j + 15);
			a++;
		}
		cout << endl;
		a = 0;
		for (int j = 0; j < 15 / 2; j++)
		{
			string buf = alf_ch2[j];
			alf_ch2[j] = alf_ch2[14 - j];
			alf_ch2[14 - j] = buf;
		}
		
		for (int j = 0; j < size; j++)
		{
			for (int q = 0; q < 15; q++)
			{
				if (word[j] == alf_ch1[q])
				{
					buf[j] = alf_ch2[q];
				}
				else if (word[j] == alf_ch2[q])
				{
					buf[j] = alf_ch1[q];
				}
				else if (word[j] == " ")
				{
					buf[j] = " ";
				}
                                else 
                                {
                                        buf[j] = "?";
                                }
			}
		}
		for (int j = 0; j < size; j++)
		{
			cout << buf[j];
		}
	}
	cout << "\n====================" << endl;
	cout << "\nвыберете читаемый вариант\n";
	delete[] word;
	delete[] buf;
	system("pause");
	return 0;
}
