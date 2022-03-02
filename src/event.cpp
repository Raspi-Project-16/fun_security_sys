#include "event.h"



Event::Event(char* content){

}

Event::~Event(){

}

u16 Event::getEid() const{
    return this->eid_;
}

void Event::setEid(u16 eid){
    this->eid_ = eid;
}

u32 Event::getSN() const{
    return this->sn_;
}

void Event::setSN(u32 sn){
    this->sn_ = sn;
}

std::ostream& Event::dump(std::ostream& out) const {
    return out;
}

bool Event::decode(){
    return true;
}

char* Event::encode(){
    return NULL;
}