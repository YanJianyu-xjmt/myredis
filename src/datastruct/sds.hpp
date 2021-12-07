#pragma once

#define SDSRESIZE 2

#include <string>
namespace myredis{

//the capapcity of the buf
//the tail of the buf is '\0'
class sds{
private:
    int capacity;

    int size;

    //the end of buf if '\0'
    char* buf;
public:
    
    //construct function
    sds();
    sds(int c);
    sds(std::string s);
    sds(sds& s);

    ~sds();

    //return a new sds 
    sds* cat(sds& s);
    void addsds(sds& s);

    void resize(int c);


    void clear() {size = 0;}
    int getcapacity(){return capacity;}
    int getsize(){return size;}
    char* getbuf(){return buf;}

    void setbuf(char* newbuf){free(buf);buf = newbuf;};
};
}