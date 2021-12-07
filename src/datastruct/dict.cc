#include "dict.hpp"
#include <functional>
namespace myredis{

kv::~kv(){
    delete key;
    delete value;
}

dict_t::dict_t(std::function<int(sds,int)> hs){}
}