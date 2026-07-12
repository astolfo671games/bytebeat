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
#define SR_OFFSET 24
#define HEADER_LEN 44
#define HEADER_DEFAULT "RIFF\xff\xff\xff\xffWAVEfmt\x20\x10\x00\x00\x00\x01\x00\x01\x00\x44\xac\x00\x00\x44\xac\x00\x00\x01\x00\x08\x00\x64\x61ta\xff\xff\xff\xff"
#define FILENAME_MATCHSTR "^bytebeat_[0-9]{1,16}f_[0-9]{1,16}f[.]wav$"
#define CONFIG_BUF 256
#define NUM_NEWLINES 3
#define FN_MAXLEN 64
#define MAX_BUF 1000000
#define FORMAT_STR_FILENAME "../bytebeat_0f_%luf.wav"

/*structs*/
typedef struct ByteData{
	uint8_t u, v;
	uint32_t b;
}ByteData;

typedef struct SongRange{
	bool is_indir;
	uint32_t start;
	uint32_t end;
	uint32_t len;
}SongRange;

/*functions*/
uint32_t get_length(FILE*);
void get_stats(FILE*, ByteData*, uint32_t, uint32_t);
bool get_config_str(FILE*, uint32_t*, uint32_t*);
bool get_config_str_(FILE*, char*, uint32_t*);

#endif
