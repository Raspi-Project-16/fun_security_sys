#ifndef COMMON_IEVENT_HANDLER_H_
#define COMMON_IEVENT_HANDLER_H_
#include "event.h"
#include <iostream>


class EventHandler
{
public:
    virtual bool handle(const CEvent* ev) = 0;
    virtual ~EventHandler() {};
    EventHandler(){};
};

#endif