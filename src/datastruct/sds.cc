#include "sds.hpp"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

namespace myredis{

sds::sds():capacity(0),size(0),buf(nullptr) {}

sds::sds(int c):capacity(c),size(0){
    buf = (char*)malloc(c+1);
    return;
}


void sds::resize(int c){
    capacity = c;
    char* newbuf = (char*)malloc(c+1);
    memcpy(newbuf,buf,size+1);
    free(buf);
    buf = newbuf;
}


sds::~sds(){
    free(buf);
}

sds::sds(std::string s){
    capacity = s.size()+1;
    size = s.size();
    buf = (char*)malloc(size+1);
    memcpy(buf,s.c_str(),size+1);
}

sds::sds(sds& s){
    capacity = s.getcapacity();
    size = s.getsize();
    buf = (char*)malloc(capacity+1);
    
    memcpy(buf,s.getbuf(),size+1);
}

sds* sds::cat(sds&s){
    char* newbuf = (char*)malloc(size+s.getsize()+1);
    memcpy(newbuf,buf,size);
    memcpy(newbuf+size,s.getbuf(),s.getsize()+1);
    sds* r = new sds(size+s.getsize());
    r->setbuf(newbuf);
    return r;
}

void sds::addsds(sds& s){
    if(capacity - size < s.getsize()){
        s.resize(size+s.getsize());
    }
    memcpy(buf+size,s.getbuf(),s.getsize());
}
}