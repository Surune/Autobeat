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
		cout << "    1 ] 음원 추출해서 노트 제작                     " << endl;
		cout << "    2 ] 사용 방법 안내                              " << endl;
		cout << "    3 ] 프로그램 종료                               " << endl;
		select = _getch();
		switch (select)
		{
		case '1':
			Print_top();
			Print_line();
			cout << "       데이터를 추출할 음원명을 입력해주세요.       " << endl;
			cout << "         (단, .wav형식의 파일만 가능합니다.)        " << endl << "  :  ";
			cin >> filename;
			try {
				CWaveIO * waveio = new CWaveIO(filename);
				waveio->MakeFile();
				delete waveio;
			}
			catch (char * filename) {
				cout << " " << filename << "이 존재하지 않습니다." << endl;
				cout << "            프로그램을 다시 실행시키세요            " << endl;
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
