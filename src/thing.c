#include "func.h"

/*render bytebeat code into unsigned 8-bit .wav file*/
int main(){
FILE* header = fopen("../header.wav", "w+b");
FILE* config = fopen("../config.txt", "r+t");

//uint32_t samplerate[2], length;
SongInfo *song_info = calloc(1, sizeof(SongInfo));

if(!get_config_str(config, song_info)) return 1;

fwrite(HEADER_DEFAULT, HEADER_LEN, 1, header);
fseek(header, SR_OFFSET, SEEK_SET);
fwrite(&song_info -> srate, sizeof(int32_t), 2, header);
fseek(header, HEADER_LEN, SEEK_SET);

for(int64_t t = song_info -> start; t < song_info -> end; t++){
/*bytebeat goes here lol*/
uint8_t u =
t
;fwrite(&u, 1, 1, header);
}
puts("Bytebeat compiled successfully!");
free(song_info);
return 0;
}
