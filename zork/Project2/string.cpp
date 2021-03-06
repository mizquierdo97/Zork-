#include "string.h"
#include <string>
#include "Vector.h"

String::String()
{

}

String::String(const char* str)
{
	mcapacity = strlen(str) + 1;
	buffer = new char[mcapacity];
	strcpy(buffer, str);
}

String::String(const String& str)
{
	mcapacity = strlen(str.buffer) + 1;
	buffer = new char[mcapacity];
	strcpy(buffer, str.buffer);
}

String::~String(){
	delete[]buffer;
}
uint String::length()const{
	return strlen(buffer);
}

char* String::c_str()const{
	return buffer;
}

bool String::empty()const{
	if (strlen(buffer) == 0) return true;
	else return false;
}

bool String::operator == (const String& str)const{
	return(strcmp(buffer, str.buffer) == 0);

}
bool String::operator == (const char* str) const{
	return(strcmp(buffer, str) == 0);
}

void String::operator += (const String& str){
	if (str.length() + length() + 1 > mcapacity){
		mcapacity += str.length();
		char* temp = nullptr;
		temp = new char[mcapacity];
		strcpy(temp, buffer);
		delete[] buffer;
		buffer = new char[mcapacity];
		strcat(temp, str.buffer);
		buffer = temp;
	}
	else strcat(buffer, str.buffer);
}

void String::operator =(const String& str){
	if (str.length() + 1 > mcapacity)
	{
		mcapacity = str.length() + 1;
		delete[] buffer;
		buffer = new char[mcapacity];
		strcpy(buffer, str.buffer);
	}
	else if (str.length() + 1 <= mcapacity)
	{
		strcpy(buffer, str.buffer);
	}
}

char* String::operator+(const String& str)const
{
	char* new_string;
	int len = length() + str.length() + 1;

	new_string = new char[len];
	strcpy(new_string, buffer);
	strcat(new_string, str.buffer);

	return new_string;
}

unsigned int String::capacity()const{
	return mcapacity;

}

void String::clean(){
	strcpy_s(buffer, mcapacity, "");
}

void String::shrink_to_fit(){
	if (mcapacity > length() + 1){
		mcapacity = length() + 1;
		delete[] buffer;
		buffer = new char[mcapacity];

	}
	
}
bool String::operator != (const String& str)const{
	return(strcmp(buffer, str.buffer) != 0);
}

Vector<String*> String::tokenize()
{
	Vector<String*> tokens;
	char *context = nullptr;
	tokens.push_back(new String(strtok_s(this->buffer, " ", &context)));
	while (strcmp(context, "") != 0){
		tokens.push_back(new String(strtok_s(NULL, " ", &context)));
	}
	return tokens;
}
String String::s_str()const
{
	String copy(buffer);
	return copy;
}

