#ifndef FUNC_H
#define FUNC_H

/*libs*/
#include <ctype.h>
#include <stdio.h>
#include <regex.h>
#include <dirent.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*macros*/
#define V v[3]
#define I i-1
#define H_RES 10
#define START 0
#define END 1
#define LENGTH 2
#define SR_OFFSET 24
#define HEADER_LEN 44
#define HEADER_DEFAULT "RIFF\xff\xff\xff\xffWAVEfmt\x20\x10\x00\x00\x00\x01\x00\x01\x00\x44\xac\x00\x00\x44\xac\x00\x00\x01\x00\x08\x00\x64\x61ta\xff\xff\xff\xff"
#define FILENAME_MATCHSTR "^bytebeat_[0-9]{1,16}f_[0-9]{1,16}f[.]wav$"
#define CONFIG_BUF 256
#define NUM_NEWLINES 3
#define FN_MAXLEN 64
#define MAX_BUF 1000000
#define FORMAT_STR_FILENAME "../bytebeat_%uf_%uf.wav"

/*structs*/
typedef struct ByteData{
	uint8_t u, v;
	uint32_t b;
}ByteData;

typedef struct SongInfo{
	uint32_t start;
	uint32_t end;
	uint32_t len;
	uint32_t srate[2];
}SongInfo;

/*functions*/
void get_data(FILE*, uint32_t*);
void get_stats(FILE*, ByteData*, uint32_t, uint32_t);
char* get_fname_str();
bool get_song_info(SongInfo*);
bool get_config_str(FILE*, SongInfo*);
bool get_config_str_(FILE*, char*, uint32_t*, FILE*, uint32_t*);

#endif
