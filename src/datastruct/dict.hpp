#pragma once

#include "sds.hpp"
#include <functional>
//the num for hash tabel rehashing
#define EXPANSION 2

//this hash table use Gradual rehasing
//the hash tabel in myredis only support simple dynamic string
namespace myredis{

//the hash tabel with open list 
struct kv{
    sds* key;
    sds* value;
    kv* next;

    kv() = delete;
    kv(sds* k,sds* v):key(k),value(v),next(nullptr){};
    ~kv();
};

//单hash表的实现，包含一个
struct dict_t{
    int num_bucket;
    bool flags[];
    kv* kvs[];

    dict_t() = delete;
    dict_t(int b);
    ~dict_t();
};

class dict{
public:
    dict() = delete;
    dict(std::function<int(sds,int)> hs);
    ~dict();
    bool insert(sds* key,sds* value);
    bool remove(sds* key);


private:
    std::function<int(sds)> hash_function;
    
    dict_t* d0;
    dict_t* d1;
    
    bool is_rehashing;
    
    int size;
    int num_bucket;
};
}