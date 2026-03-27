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
t<512960?(int)(t*.150677*(1-.109101*(28736>>t/4580%16&1)))%32*(212>>t/4580%8&1)+((((int)(4e3/(t%18320/4580+.745))&127)^!!((int)(4e3/(t%18320/4580+.745))&128)*127)+(t/(int)(t%99+1)&3))*(1./(t%18320/8e2+1)*!(t/4580&3)):0
;fwrite(&u, 1, 1, header);}
puts("Bytebeat compiled successfully!");
return 0;}