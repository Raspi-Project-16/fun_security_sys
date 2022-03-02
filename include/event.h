#include "glo_def.h"
#include <string>
using namespace std;

class Event
{
public:
    virtual u16 getEid() const {return eid_;};
    virtual void setEid(u16 eid) {eid_ = eid;};
    virtual u32 getSN() const {return sn_;};
    virtual void setSN(u32 sn){ sn_ = sn;};
    virtual std::ostream& dump(std::ostream& out) const { return out;};
    virtual bool decode() {return true;};
    virtual char* encode() {return NULL;};
    Event();
    virtual ~Event();

private:
    u16 eid_;
    u32 sn_;

protected:
    string content_;
};