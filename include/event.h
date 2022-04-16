#ifndef COMMON_EVENT_H
#define COMMON_EVENT_H

#include <string>
#include <iostream>
#include "glo_def.h"
using namespace std;

/*----------------------------------------------------------------------
  |       CEvent
  +---------------------------------------------------------------------*/

class CEvent
{
public:
    unsigned short getEid() const {return eid_;};
    void setEid(unsigned short eid) {eid_ = eid;};
    unsigned int getSN() const {return sn_;};
    void setSN(unsigned int sn){ sn_ = sn;};
    CEvent();
    ~CEvent();

private:
    unsigned short eid_;
    unsigned int sn_;

protected:
    string content_;
};

#endif
