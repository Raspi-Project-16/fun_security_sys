#ifndef COMMON_EVENT_H
#define COMMON_EVENT_H

#include <string>
#include <iostream>
#include "glo_def.h"
using namespace std;


class CEvent
{
public:
    u16 getEid() const {return eid_;};
    void setEid(u16 eid) {eid_ = eid;};
    u32 getSN() const {return sn_;};
    void setSN(u32 sn){ sn_ = sn;};
    // virtual std::ostream& dump(std::ostream& out) const { return out;};
    // virtual bool decode() {return true;};
    // virtual char* encode() {return NULL;};
    CEvent();
    ~CEvent();

private:
    u16 eid_;
    u32 sn_;

protected:
    string content_;
};

#endif