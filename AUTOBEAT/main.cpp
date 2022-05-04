#include "WaveIO.h"
#include "Func.h"
#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	char filename[MAX_LEN];
	bool running = true;
	int select = 0;
	while (running)
	{
		Print_top();
		Print_line();
		cout << "    1 ] ���� �����ؼ� ��Ʈ ����                     " << endl;
		cout << "    2 ] ��� ��� �ȳ�                              " << endl;
		cout << "    3 ] ���α׷� ����                               " << endl;
		select = _getch();
		switch (select)
		{
		case '1':
			Print_top();
			Print_line();
			cout << "       �����͸� ������ �������� �Է����ּ���.       " << endl;
			cout << "         (��, .wav������ ���ϸ� �����մϴ�.)        " << endl << "  :  ";
			cin >> filename;
			try {
				CWaveIO * waveio = new CWaveIO(filename);
				waveio->MakeFile();
				delete waveio;
			}
			catch (char * filename) {
				cout << " " << filename << "�� �������� �ʽ��ϴ�." << endl;
				cout << "            ���α׷��� �ٽ� �����Ű����            " << endl;
				Print_line();
				running = false;
			}
			break;
		case '2':
			Print_howtouse();
			break;
		case '3':
			running = false;
			break;
		}
	}
	return 0;
}
