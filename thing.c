#include "func.h"

int main(){
FILE* header = fopen("header.wav", "w+b");
FILE* config = fopen("config.txt", "r+t");

uint32_t samplerate[2], length;

get_config_str(config, samplerate, &length);

fwrite(HEADER_DEFAULT, 44, 1, header);
fseek(header, 24, SEEK_SET);
fwrite(&samplerate, sizeof(int32_t), 2, header);
fseek(header, 44, SEEK_SET);

for(uint64_t t = 0; t < length; t++){
/*write ur own bytebeat*/
uint8_t u =

;fwrite(&u, 1, 1, header);}
puts("Bytebeat compiled successfully!");
return 0;}
