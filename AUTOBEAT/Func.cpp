#include "Func.h"
#include <iostream>
using namespace std;
void Print_top()
{
	system("cls");
	cout << "┌────────────────────────┐" << endl;
	cout << "│     ■      ■      ■  ■■■■■    ■■■   │" << endl;
	cout << "│    ■■     ■      ■      ■      ■      ■ │" << endl;
	cout << "│   ■  ■    ■      ■      ■      ■      ■ │" << endl;
	cout << "│  ■■■■   ■      ■      ■      ■      ■ │" << endl;
	cout << "│ ■      ■    ■■■        ■        ■■■   │" << endl;
	cout << "│                                                │" << endl;
	cout << "│ ■■■■    ■■■■■      ■      ■■■■■ │" << endl;
	cout << "│ ■      ■  ■             ■■         ■     │" << endl;
	cout << "│ ■■■■    ■■■■■    ■  ■        ■     │" << endl;
	cout << "│ ■      ■  ■           ■■■■       ■     │" << endl;
	cout << "│ ■■■■    ■■■■■  ■      ■      ■     │" << endl;
	cout << "├───────┬────────────────┤" << endl;
	cout << "│ VERSION 1.23 │ 제작 : 대구과학고등학교 서진규 │" << endl;
	cout << "└───────┴────────────────┘" << endl;
}

void Print_line() { cout << " ================================================== " << endl; }

void Print_howtouse()
{
	Print_top();
	Print_line();
	cout << "  1 ] .wav 형식의 음원 파일 경로 입력               " << endl;
	cout << "  2 ] 노트를 저장할 텍스트 파일의 이름 입력         " << endl;
	cout << "  3 ] GAP (음원 추출시 최댓값을 뽑는 기준) 입력     " << endl;
	cout << "      (값이 작을수록 노트가 많이 생성됨 / 추천: 15) " << endl;
	cout << "  4 ] TIMEGAP (노트간의 최소 간격) 입력             " << endl;
	cout << "      (값이 작을수록 노트가 많이 생성됨 / 추천: 8)  " << endl;
	cout << "  5 ] 리듬게임 플레이 :)                            " << endl;
	Print_line();
	system("pause");
}