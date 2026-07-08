#include "func.h"

int main(){
FILE* header = fopen("../header.wav", "r+b");
FILE* config = fopen("../config.txt", "r+t");
FILE* mismatches = fopen("../mismatches.txt", "w+t");
FILE* stats = fopen("../stats.txt", "w+t");

char f_str[28];
uint32_t res;

if(!get_config_str_(config, f_str, &res)) return 1;
FILE* header2 = fopen(f_str, "r+b");

uint32_t length = get_length(header2);

fseek(header, 44, SEEK_SET);
fseek(header2, 44, SEEK_SET);

ByteData b[MAX_BUF];
uint32_t i = 0;

for(uint32_t t = 0; t < length; t++){
	uint8_t u, v[4];
	fread(&u, 1, 1, header);
	fread(v, 1, 4, header2);
	V ^= 0x80;
	if(u != V && i < MAX_BUF){
		b[i].u = u; b[i].v = V; b[i].b = t; i++;
	}
}

if(b[1].b == 0){
	puts("Bytebeat verified successfully!");
}else{
	printf("Bytebeat is not C-compatible "
	       "(first mismatch at %u, %02hhx instead of %02hhx)",
	b[0].b, b[0].v, b[0].u);
	i = i > MAX_BUF? MAX_BUF: i;
	for(uint32_t j = 0; j < i; j++) fprintf(mismatches,
"%u %hhu %hhu\n", b[j].b, b[j].u, b[j].v);
	get_stats(stats, b, i, res);
}return 0;
}
