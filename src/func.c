#include "func.h"

/*get audio length (in samples)*/
void get_data(FILE* temp, uint32_t* data){
	uint64_t r = fread(data, sizeof(uint32_t), 3, temp);
}

/*get stats about diffs between the C and JS outputs*/
void get_stats(FILE* f, ByteData* b, uint32_t i, uint32_t res){
	uint32_t range = b[I].b - b[0].b;
	uint32_t chunks[res];
	double chunk_size = range / (double)(res);
	uint32_t j = 0, k = 0;

	fprintf(f, "Total mismatches: %u\n"
		"Range: %u - %u (%u)\n", i, b[0].b, b[I].b, range);

	for(double e = b[0].b + chunk_size; e < b[I].b + chunk_size;
	e += chunk_size){
		chunks[j] = 0;
		while(b[k].b < e){chunks[j]++; k++;}
		j++;
	}

	for(uint32_t j = 0; j < res; j++)
		fprintf(f, "%u: %u\n", (int32_t)(j * chunk_size) + b[0].b,
		chunks[j]);
}

/*check if config file has correct formatting*/
uint32_t check_newline_count(FILE* config, char *str){
	uint32_t nl_count = 0;
	for(uint32_t i = 0; i < ftell(config); i++){
		if(str[i] == '\n') nl_count++;
		if(!(isdigit(str[i]) || str[i] == '\n')) return 1;
	}
	return nl_count;
}

/*read audio filename*/
char* get_fname_str(){
	DIR *dir;
	struct dirent *entry;
	regex_t regex;
	char* fname_buf = NULL;

	regcomp(&regex, FILENAME_MATCHSTR, REG_EXTENDED);
	dir = opendir("..");

	while((entry = readdir(dir)) != NULL){
		if(!regexec(&regex, entry -> d_name, 0, NULL, 0)){
			fname_buf = (char*)calloc(FN_MAXLEN, sizeof(char));
			memcpy(fname_buf, entry -> d_name, FN_MAXLEN);
		}
	}

	closedir(dir);
	regfree(&regex);
	return fname_buf;
}

/*get song metadata*/
bool get_song_info(SongInfo *song_info){
	char* fname_buf = get_fname_str();
	if(fname_buf == NULL) return false;
	FILE* temp = fopen("temp", "w+b");

	strtok(fname_buf, "_");
	song_info -> start = atol(strtok(NULL, "f"));
	song_info -> end = atol(strtok(NULL, "f_"));
	song_info -> len = song_info -> end - song_info -> start;

	uint32_t temp_data[3] = {song_info -> start, song_info -> end,
	song_info -> len};
	fwrite(temp_data, sizeof(uint32_t), 3, temp);

	free(fname_buf);
	return true;
}

/*read config file*/
bool get_config_str(FILE* config, SongInfo *song_info){
	char str[CONFIG_BUF];
	fseek(config, 0, SEEK_SET);
	uint64_t r;
	while(!feof(config)) r = fread(str, 1, CONFIG_BUF, config);

	if(check_newline_count(config, str) != NUM_NEWLINES){
		perror("Wrong config format!");
		free(song_info);
		return false;
	}

	long s = atol(strtok(str, "\n"));
	song_info -> srate[0] = s; song_info -> srate[1] = s;
	if(!get_song_info(song_info)){free(song_info); return false;}
	return true;
}

/*read config file 2 electric boogaloo*/
bool get_config_str_(FILE* config, char* f_str, uint32_t* res, FILE* temp,
                     uint32_t* data){
	char str[CONFIG_BUF];
	fseek(config, 0, SEEK_SET);
	uint64_t r, s;
	while(!feof(config)) r = fread(str, 1, CONFIG_BUF, config);

	if(check_newline_count(config, str) != NUM_NEWLINES){
		fclose(temp);
		s = system("rm temp");
		perror("Wrong config format!");
		return false;
	}

	strtok(str, "\n");strtok(NULL, "\n");
	snprintf(f_str, FN_MAXLEN, FORMAT_STR_FILENAME, data[START], data[END]);
	*res = atol(strtok(NULL, "\n"));

	fclose(temp);
	s = system("rm temp");
	return true;
}
