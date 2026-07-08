#include "func.h"

int main(){
FILE* header = fopen("../header.wav", "w+b");
FILE* config = fopen("../config.txt", "r+t");

uint32_t samplerate[2], length;

get_config_str(config, samplerate, &length);

fwrite(HEADER_DEFAULT, 44, 1, header);
fseek(header, 24, SEEK_SET);
fwrite(&samplerate, sizeof(int32_t), 2, header);
fseek(header, 44, SEEK_SET);

for(int64_t t = 0; t < length; t++){
/*write ur own bytebeat*/
uint8_t u =
t>>23?0:(99>>t*~(54069/(~(~((t>>12^t/4096+(t>>18|1))%9)*12/7)*2-85)+387)/996&t>>(7^t>>21)^64>>(~t>>14&31?t>>14^t/16384+1:0)%9*863%5529%4695%3068%2247%576*t/4096)&~(t>>19^15?0:t>>12)^-(t>>19&7?t<15<<19?t>>6:0:35246<<(t>>14)<0?t>>5:0)
;fwrite(&u, 1, 1, header);}
puts("Bytebeat compiled successfully!");
return 0;}