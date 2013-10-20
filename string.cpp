#include"string.h"
int length_of(char* str){
	int i=0;
	while(str[i]!='\0'){
		i++;
	}
	return i;
}
int length_of(const char* str){
	int i=0;
	while(str[i]!='\0'){
		i++;
	}
	return i;
}
void String::operator=(const char* str_){
	delete str;
	leng=length_of(str_);
	str=new char[leng+1];
	for(int i=0;i<leng;i++){
		str[i]=str_[i];
	}
	str[leng]='\0';
}
void String::operator=(String str_){
	delete str;
	leng=str_.leng;
	str=new char[leng+1];
	for(int i=0;i<=leng;i++){
		str[i]=str_.str[i];
	}
}
bool String::operator==(const char* str_){
	int temp_leng=length_of(str_);
	if(leng==temp_leng){
		for(int i=0;i<leng;i++){
			if(str[i]!=str_[i])return false;
		}
	}else{
		return false;
	}
	return true;
}
bool String::operator==(String str_){
	if(str_.leng==leng){
		for(int i=0;i<leng;i++){
			if(str_.str[i]!=str[i])return false;
		}
	}else{
		return false;
	}
	return true;
}
bool String::operator<(String str_){
	int limit=leng<str_.leng?leng:str_.leng;
	for(int i=0;i<limit;i++){
		if(str[i]<str_.str[i]){
			return true;
		}else if(str[i]>str_.str[i]){
			return false;
		}else{
			continue;
		}
	}
	if(leng<str_.leng)return true;
	return false;
}
bool String::operator<=(String str_){
	int limit=leng<str_.leng?leng:str_.leng;
	for(int i=0;i<limit;i++){
		if(str[i]<str_.str[i]){
			return true;
		}else if(str[i]>str_.str[i]){
			return false;
		}else{
			continue;
		}
	}
	if(leng<=str_.leng)return true;
	return false;
}
bool String::operator>(String str_){
	int limit=leng<str_.leng?leng:str_.leng;
	for(int i=0;i<limit;i++){
		if(str[i]>str_.str[i]){
			return true;
		}else if(str[i]<str_.str[i]){
			return false;
		}else{
			continue;
		}
	}
	if(leng>str_.leng)return true;
	return false;
}
bool String::operator>=(String str_){
	int limit=leng<str_.leng?leng:str_.leng;
	for(int i=0;i<limit;i++){
		if(str[i]>str_.str[i]){
			return true;
		}else if(str[i]<str_.str[i]){
			return false;
		}else{
			continue;
		}
	}
	if(leng>=str_.leng)return true;
	return false;
}
String String::operator+(String str_){
	String new_str;
	new_str.leng=leng+str_.leng;
	new_str.str=new char[new_str.leng+1];
	for(int i=0;i<leng;i++){
		new_str.str[i]=str[i];
	}
	for(int i=0;i<=str_.leng;i++){
		new_str.str[i+leng]=str_.str[i];
	}
	return new_str;
}
String String::operator+(const char* str_){
	String new_str;
	new_str.leng=leng+length_of(str_);
	new_str.str=new char[new_str.leng+1];
	for(int i=0;i<leng;i++){
		new_str.str[i]=str[i];
	}
	for(int i=0;i<=length_of(str_);i++){
		new_str.str[i+leng]=str_[i];
	}
	return new_str;
}
String String::sub_str(int start,int end){
	String new_str;
	new_str.leng=end-start+1;
	new_str.str=new char[new_str.leng+1];
	for(int i=start;i<=end;i++){
		new_str.str[i-start]=str[i];
	}
    new_str.str[new_str.leng]='\0';
	return new_str;
}
void String::remove_char(int i){
    String temp_str=str;
    delete str;
    str=new char[leng--];
    for(int j=0;j<i;j++)
        str[j]=temp_str.str[j];
    for(int j=i;j<leng+1;j++)
        str[j]=temp_str.str[j+1];
}
void String::remove_char(char i){
    bool exit=false;
    while(!exit){
        for(int j=0;j<leng;j++){
            if(str[j]==i){
                remove_char(j);
                break;
            }
            exit=(j==leng-1);
        }
    }
}
String::String(){
	leng=1;
	str=new char[1];
	str[0]='\0';
}
String::String(const char* str_){
	leng=length_of(str_);
	str=new char[leng+1];
	for(int i=0;i<leng;i++){
		str[i]=str_[i];
	}
	str[leng]='\0';
}