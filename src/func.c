#include "func.h"

/*get audio length (in samples)*/
uint32_t get_length(FILE* f){
	uint32_t length;
	fseek(f, 4, SEEK_SET);
	fread(&length, sizeof(uint32_t), 1, f);
	return length - 36 >> 2;
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
	char allowed_c[] = {'\n', '0', '1', '2', '3', '4',
                            '5', '6', '7', '8', '9'};

	for(uint32_t i = 0; i < ftell(config); i++){
		if(str[i] == '\n') nl_count++;
		bool f = false;
		for(uint32_t j = 0; j < sizeof(allowed_c); j++){
			if(str[i] == allowed_c[j]) f = true;
		}
		if(!f) return 1;
	}
	return nl_count;
}

/*read config file*/
bool get_config_str(FILE* config, uint32_t* sr, uint32_t* len){
	char str[CONFIG_BUF];
	fseek(config, 0, SEEK_SET);
	while(!feof(config)) fread(str, 1, CONFIG_BUF, config);

	if(check_newline_count(config, str) != NUM_NEWLINES){
		perror("Wrong config format!");
		return false;
	}

	long s = atol(strtok(str, "\n"));
	sr[0] = s;
	sr[1] = s;
	*len = atol(strtok(NULL, "\n"));
	return true;
}

/*read config file 2 electric boogaloo*/
bool get_config_str_(FILE* config, char* f_str, uint32_t* res){
	char str[CONFIG_BUF];
	fseek(config, 0, SEEK_SET);
	while(!feof(config)) fread(str, 1, CONFIG_BUF, config);

	if(check_newline_count(config, str) != NUM_NEWLINES){
		perror("Wrong config format!");
		return false;
	}

	strtok(str, "\n");
	snprintf(f_str, FN_MAXLEN, FORMAT_STR_FILENAME, atol(strtok(NULL, "\n")));
	*res = atol(strtok(NULL, "\n"));
	return true;
}
