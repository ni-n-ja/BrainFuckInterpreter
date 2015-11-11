#include<iostream>
#include<string>
#include<cstdlib>
#include <fstream>
int main(int argc , char *argv[]){
	std::string *name;
	if(argc>1){
		name= new std::string(argv[1]);
	}
	else{
		name= new std::string("Z:\\test.txt");
	}
	std::string show;
	std::ifstream ifs(name->c_str());
	std::getline(ifs,show);

	char* code=(char *)show.c_str();
	char mem[300]={};
	int dataptr=0;

	for(;;){
		switch(*code){
		case '+':
			mem[dataptr]++;
			code++;
			break;
		case '-':
			mem[dataptr]--;
			code++;
			break;
		case '.':
			putchar(mem[dataptr]);
			code++;
			break;
		case ',':
			mem[dataptr]=getchar();
			code++;
			break;
		case '>':
			dataptr++;
			code++;
			break;
		case '<':
			dataptr--;
			code++;
			break;
		case '[':
			if(mem[dataptr]==0){
				for(;*code!=']';code++){
				}
			}
			code++;
			break;
		case ']':
			if(mem[dataptr]!=0){
				for(;*code!='[';code--){
				}
			}
			code++;
			break;
		}
	}
	return 0;
}