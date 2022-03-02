#include "event.h"
#include "glo_def.h"
#include <string>
#include <vector>
#include <map>
#include <pigpio.h>


class LedEvent : public Event{

public:
    LedEvent(u32 gpio);
    virtual ~LedEvent();
    virtual std::ostream& dump(std::ostream& out) const;

    virtual bool decode();
    virtual char* encode();

    void lightOn();
    void lightOff();

    const u32 getGPIO();
    void setGPIO();

private:

    u32 gpio_;

};