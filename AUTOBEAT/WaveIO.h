#ifndef __WAVEIO_H__
#define __WAVEIO_H__

typedef unsigned char BYTE;
typedef unsigned int DWORD;

#define MAX_LEN 50
#define FPS		60
#define BUFFER	115

class CWaveIO
{
private:
	char chunk_id[5];
	short compression_code, number_of_channels, block_align, bits_per_sample;
	DWORD chunk_size_riff, chunk_size_fmt, chunk_size_data, sample_rate, average_bytes_per_second;
	BYTE* source_buffer_8;
	BYTE* working_buffer_8;
	int sampling;
public:
	CWaveIO(char * filename);
	void MakeFile();
	~CWaveIO(void);
};

#endif