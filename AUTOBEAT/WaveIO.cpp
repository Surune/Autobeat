#include "WaveIO.h"
#include "Func.h"
#include <cstring>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

CWaveIO::CWaveIO(char * filename)
{
	chunk_id[4] = '\0';
	// RIFF chunk
	FILE* fp;
	fp = fopen(filename, "rb");
	fread(chunk_id, sizeof(char), 4, fp);
	if (strcmp(chunk_id, "RIFF") == 0)
	{
		fread(&chunk_size_riff, sizeof(DWORD), 1, fp);
		fread(chunk_id, sizeof(BYTE), 4, fp);
		if (strcmp(chunk_id, "WAVE") == 0)
		{
			// Format chunk
			fread(chunk_id, sizeof(BYTE), 4, fp);
			fread(&chunk_size_fmt, sizeof(DWORD), 1, fp);
			fread(&compression_code, sizeof(short), 1, fp);
			fread(&number_of_channels, sizeof(short), 1, fp);
			fread(&sample_rate, sizeof(DWORD), 1, fp);
			fread(&average_bytes_per_second, sizeof(DWORD), 1, fp);
			fread(&block_align, sizeof(short), 1, fp);
			fread(&bits_per_sample, sizeof(short), 1, fp);
			// Data chunk
			fread(chunk_id, sizeof(BYTE), 4, fp);
			fread(&chunk_size_data, sizeof(DWORD), 1, fp);
			source_buffer_8 = new BYTE[sizeof(BYTE) * chunk_size_data];
			fread(source_buffer_8, sizeof(BYTE), chunk_size_data, fp);
		}
		else cout << " 노트를 생성할 수 없습니다..." << endl;
	}
	else cout << " 노트를 생성할 수 없습니다..." << endl;

	fclose(fp);
	sampling = int(sample_rate / FPS);
}

void CWaveIO::MakeFile()
{
	char textname[MAX_LEN];
	Print_top();
	Print_line();
	cout << "       데이터를 저장할 파일명을 입력해주세요.       " << endl;
	cout << "         (단, .txt형식의 파일만 가능합니다)         " << endl << "  :  ";
	cin >> textname;

	ofstream outFile(textname);
	int byte_depth = int(bits_per_sample / 8);
	int temp = 0;
	Print_line();
	cout << "  총 " << int(chunk_size_data / byte_depth) << "개의 데이터 존재" << endl;
	int gap, timegap;
	cout << "  GAP : ";
	cin >> gap;
	cout << "  TIMEGAP : ";
	cin >> timegap;
	cout << "  SAMPLING: " << sampling << endl;
	int templist[3] = { 0 };
	int cntlist[3] = { 0 };
	int data = 0, cnt = 0;
	int previous = 0;
	int random = 0;

	srand((unsigned int)time(NULL));
	for (int i = 0; i < int(chunk_size_data / byte_depth); i++)
	{
		temp += int(source_buffer_8[i]);
		if (i % (sampling * number_of_channels) == 0)
		{
			data = int(temp / (sampling * number_of_channels));
			templist[0] = templist[1];
			templist[1] = templist[2];
			templist[2] = data;
			cnt++;
			if ((templist[0] + gap < templist[1]) && (templist[1] > templist[2] + gap) && (previous + timegap <= cnt) && (cnt >= BUFFER))
			{
				random = rand() % 3;
				cntlist[random]++;
				outFile << int(cnt - BUFFER);		// 데이터
				outFile << char(32);				// 스페이스 바
				outFile << random;					// 노트 키
				outFile << char(32);				// 스페이스 바
				outFile << int(cntlist[random]);	// 노트 키 순서
				outFile << char(32);				// 스페이스 바
				previous = cnt;
			}
			temp = 0;
		}
	}
	cout << "  총 노트의 개수 : " << int(cntlist[0] + cntlist[1] + cntlist[2]) << "개 " << endl;
	Print_line();
	system("pause");
	outFile.close();
}

CWaveIO::~CWaveIO(void)
{
	delete[] source_buffer_8;
	delete[] working_buffer_8;
}