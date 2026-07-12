#include "func.h"

/*bytebeat bitwise comparison*/
int main(){
FILE* config = fopen("../config.txt", "r+t");
FILE* mismatches = fopen("../mismatches.txt", "w+t");
FILE* stats = fopen("../stats.txt", "w+t");
FILE* temp = fopen("temp", "r+b");

char f_str[FN_MAXLEN];
uint32_t res, data[3] = {0, 0, 0};
get_data(temp, data);
if(!get_config_str_(config, f_str, &res, temp, data)) return 1;
FILE* header = fopen("../header.wav", "r+b");
FILE* header2 = fopen(f_str, "r+b");

fseek(header, HEADER_LEN, SEEK_SET);
fseek(header2, HEADER_LEN, SEEK_SET);

ByteData b[MAX_BUF];
uint32_t i = 0, r;

for(uint32_t t = 0; t < data[LENGTH]; t++){
	uint8_t u, v[sizeof(uint32_t)];
	r = fread(&u, 1, sizeof(uint8_t), header);
	r = fread(v, 1, sizeof(uint32_t), header2);
	V ^= 0x80;
	if(u != V && i < MAX_BUF){
		b[i].u = u; b[i].v = V; b[i].b = t; i++;
	}
}

if(b[1].b == 0){
	puts("Bytebeat verified successfully!");
}
else{
	printf("Bytebeat is not C-compatible "
	       "(first mismatch at %u, %02hhx instead of %02hhx)",
	b[0].b, b[0].v, b[0].u);
	i = i > MAX_BUF? MAX_BUF: i;
	for(uint32_t j = 0; j < i; j++) fprintf(mismatches,
	"%u %hhu %hhu\n", b[j].b, b[j].u, b[j].v);
	get_stats(stats, b, i, res);
	}

return 0;
}
