#include "func.h"

int main(){
FILE* header = fopen("../header.wav", "w+b");
FILE* config = fopen("../config.txt", "r+t");

uint32_t samplerate[2], length;

if(!get_config_str(config, samplerate, &length)) return 1;

fwrite(HEADER_DEFAULT, 44, 1, header);
fseek(header, 24, SEEK_SET);
fwrite(&samplerate, sizeof(int32_t), 2, header);
fseek(header, 44, SEEK_SET);

for(int64_t t = 0; t < length; t++){
/*bytebeat goes here lol*/
uint8_t u =
t
;fwrite(&u, 1, 1, header);}
puts("Bytebeat compiled successfully!");
return 0;}