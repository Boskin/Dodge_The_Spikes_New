#ifndef STRING_H
#define STRING_H
int length_of(char* str);
int length_of(const char* str);
class String{
	public:
	char* str;
	int leng;
	void operator=(const char* str_);
	void operator=(String str_);
	bool operator==(const char* str_);
	bool operator==(String str_);
	bool operator<(String str_);
	bool operator<=(String str_);
	bool operator>(String str_);
	bool operator>=(String str_);
	String operator+(String str_);
	String operator+(const char* str_);
	String sub_str(int start,int end);
    void remove_char(int i);
    void remove_char(char i);
	String();
	String(const char* str_);
};
/*char char_to_lower(char val){
	char new_char;
	if(val=='A'){new_char='a';
	}else if(val=='B'){new_char='b';
	}else if(val=='C'){new_char='c';
	}else if(val=='D'){new_char='d';
	}else if(val=='E'){new_char='e';
	}else if(val=='F'){new_char='f';
	}else if(val=='G'){new_char='g';
	}else if(val=='H'){new_char='h';
	}else if(val=='I'){new_char='i';
	}else if(val=='J'){new_char='j';
	}else if(val=='K'){new_char='k';
	}else if(val=='L'){new_char='l';
	}else if(val=='M'){new_char='m';
	}else if(val=='N'){new_char='n';
	}else if(val=='O'){new_char='o';
	}else if(val=='P'){new_char='p';
	}else if(val=='Q'){new_char='q';
	}else if(val=='R'){new_char='r';
	}else if(val=='S'){new_char='s';
	}else if(val=='T'){new_char='t';
	}else if(val=='U'){new_char='u';
	}else if(val=='V'){new_char='v';
	}else if(val=='W'){new_char='w';
	}else if(val=='X'){new_char='x';
	}else if(val=='Y'){new_char='y';
	}else if(val=='Z'){new_char='z';
	}else{new_char=val;
	}
	return new_char;
}
char char_to_upper(char val){
	char new_char;
	if(val=='a'){new_char='A';
	}else if(val=='b'){new_char='B';
	}else if(val=='c'){new_char='C';
	}else if(val=='d'){new_char='D';
	}else if(val=='e'){new_char='E';
	}else if(val=='f'){new_char='F';
	}else if(val=='g'){new_char='G';
	}else if(val=='h'){new_char='H';
	}else if(val=='i'){new_char='I';
	}else if(val=='j'){new_char='J';
	}else if(val=='k'){new_char='K';
	}else if(val=='l'){new_char='L';
	}else if(val=='m'){new_char='M';
	}else if(val=='n'){new_char='N';
	}else if(val=='o'){new_char='O';
	}else if(val=='p'){new_char='P';
	}else if(val=='q'){new_char='Q';
	}else if(val=='r'){new_char='R';
	}else if(val=='s'){new_char='S';
	}else if(val=='t'){new_char='T';
	}else if(val=='u'){new_char='U';
	}else if(val=='v'){new_char='V';
	}else if(val=='w'){new_char='W';
	}else if(val=='x'){new_char='X';
	}else if(val=='y'){new_char='Y';
	}else if(val=='z'){new_char='Z';
	}else{new_char=val;
	}
	return new_char;
}
char* string_to_lower(char* str){
	char* new_string=new char[length_of(str)];
	for(int i=0;i<length_of(str);i++){
		new_string[i]=char_to_lower(str[i]);
	}
	return new_string;
}
char* string_to_upper(char* str){
	char* new_string=new char[length_of(str)];
	for(int i=0;i<length_of(str);i++){
		new_string[i]=char_to_upper(str[i]);
	}
	return new_string;
}*/
#endif