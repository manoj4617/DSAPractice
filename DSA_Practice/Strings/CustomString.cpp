#include <cstddef>
#include <cstdio>
#include <new>
#include <stdexcept>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

class MyString {
    private:
        char* str;
        size_t size;

        size_t length(const char* str) const{
            size_t len = 0;
            while(*str != '\0'){
                str++;
                len++;
            }
            return len;
        }

        void resize(size_t newCap){
            char* newStr = (char*)malloc(newCap + 1);
            if(!newStr){
                throw std::bad_alloc();
            }
            for(size_t i = 0; i < size; ++i){
                newStr[i] = str[i];
            }
            newStr[size] = '\0';
            free(str);
            str = newStr;
            size = newCap;
        }

        size_t str_cpy(char* dest, const char* src){
            if(dest == NULL || src == NULL){
                return 1;
            }
            size_t i = 0;

            while(src[i] != '\0'){
                dest[i] = str[i];
                i++;
            }
            dest[i] = '\0';
            return 0;
        }

        size_t str_n_cpy(char* dest, char* src, size_t len){
            if(dest == NULL || src == NULL){
                return 1;
            }
            size_t i = 0;

            while(src[i] != '\0' && i < len){
                dest[i] = src[i];
                i++;
            }
            dest[i] = '\0';
            return 0;
        }
        void str_cat(char* oldStr, const char* newStr){
            size_t newStrLen = length(newStr);
            size_t newSize = size + newStrLen;
            if(newSize > size){
                resize(newSize + 10);
            }

            for(size_t i=0; i<newStrLen;++i){
                str[size + i] = newStr[i]; 
            }
            size = newStrLen;
            str[size] = '\0';
        }

        char* str_str(char* src, const char* toFind) const {
            size_t i = 0, j = 0;
            int srclen = length(src);
            int destlen = length(toFind); 
            while(i < srclen){
                while(j < destlen && src[i] == toFind[j]){
                    j++;
                    i++;
                }
                if(j == destlen){
                    return &src[i - j];
                }
                i++;
                j = 0;
            }
            return NULL; // return -1 if the substring is not found
        }

        int str_cmp(const char* str1, const char* str2) const {
            int i = 0;

            while(str1[i] != '\0' && str2[i] != '\0'){
                if(str1[i] != str2[i]){
                    return str1[i] - str2[i];
                }
                i++;
            }

            if(str1[i] == '\0' && str2[i] == '\0'){
                return 0;
            } else if(str1[i] == '\0'){
                return -1;
            } else {
                return 1;
            }
        }
    public:
        ~MyString(){
            clear();
        }
        MyString(int s) : size(s){
            str = (char*)malloc((s + 1) * sizeof(char)); // +1 for null terminating char
            if(str == NULL){
                cerr << "Insufficient Memory" << endl;
                exit(-1);
            }
        }

        MyString(const char* str){
            if(str == nullptr){
                this->size = 0;
                this->str = (char*)malloc(1);
                this->str[0] = '\0';
            }
            else{
                this->size = length(str);
                this->str = (char*)malloc(sizeof(char) * (this->size + 1)); // +1 for null terminating char
                if(this->str == NULL){
                    cerr << "Insufficient Memory" << endl;
                    exit(-1);
                }
                if(str_cpy(this->str, str)){
                    cerr << "Copy failed" << endl;
                }
            }
        }

        MyString& operator=(MyString& other){
            if(this != &other){
                free(this->str);
                this->str = (char*)malloc((other.size + 1) * sizeof(char));
                if(this->str == NULL){
                    cerr << "Insufficient Memory" << endl;
                    exit(-1);
                }
                if(str_cpy(this->str, other.str)){
                    cerr << "Copy failed" << endl;
                }
            }
            return *this;
        }

        MyString& operator+=(MyString &other){
            size_t newSize = this->size + other.size;
            resize(newSize);
            str_cat(this->str, other.str);
            this->size = newSize;
            return *this;
        }

        MyString& operator+(MyString& str1) const {
            size_t newSize = this->size + str1.size;
            MyString result(newSize);
            result.str_cpy(result.str, this->str);
            result.str_cat(this->str,str1.str);
            result.size = newSize;
            return result;
        }
        size_t length() const {
            return this->size;
        }

        char charAt(size_t index) const {
            if(index >= 0 && index < this->size){
                return this->str[index];
            } else{
                cerr << "index out of bound" << index <<  endl;
                throw std::out_of_range("index out of bound");
            }
        }

        char* c_str(){
            return this->str;
        }

        void append(const char* str){
            if(!str){
                cerr << "Cannot append a null string" << endl;
                return;
            }
            size_t len = length(str);
            if(this->size + len >= this->size){
                resize(this->size + len);
            }
            str_cat(this->str, str);
            this->size += len;
        }


        MyString subString(size_t start, size_t len){
            if(start >= this->size)
                throw std::out_of_range("Start index is out of range");
        
            if(start + len > this->size){
                len = this->size - start;
            }

            char* substr = (char*)malloc(len + 1);
            str_n_cpy(substr, this->str + start, len);
            return MyString(substr);
        }

        size_t find(const char* target) const {
            char* pos = str_str(this->str, target);
            return pos ? (pos - this->str) : std::string::npos;
        }

        void reverse(){
            for(size_t i=0, j = this->size - 1;i < j ;++i, --j){
                std::swap(this->str[i], this->str[j]);
            }
        }
        void clear(){
            free(this->str);
            this->str = nullptr;
            this->size = 0;
        }

        int compare(const char* other) const {
            return str_cmp(this->str, other);
        }
        int compare(MyString& other) const {
            return str_cmp(this->str, other.str);
        }

        bool empty() const {
            return this->size == 0;
        }
};

int main(){

    MyString str = "Hello World!";

    cout << str.length() << endl;

    MyString sub = str.subString(0, 5);

    cout << sub.length() << endl;

    return 0;
}