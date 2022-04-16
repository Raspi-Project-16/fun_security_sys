#ifndef COMMON_IEVENT_HANDLER_H_
#define COMMON_IEVENT_HANDLER_H_
#include "event.h"
#include <iostream>

/*----------------------------------------------------------------------
  |       EventCallback
  +---------------------------------------------------------------------*/

class EventCallback
{
public:
    virtual bool callback(const CEvent* ev) = 0;
    virtual ~EventCallback() {};
    EventCallback(){};
};

#endif
