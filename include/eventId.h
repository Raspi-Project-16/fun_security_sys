#ifndef COMMON_EVENT_TYPE_H_
#define COMMON_EVENT_TYPE_H_

#ifdef __cplusplus
extern "C"
    {
#endif

enum EErrorCode
{
    ERRC_SUCCESS              = 200,
	ERRC_INVALID_MSG          = 400,
	ERRC_INVALID_DATA         = 404,
	ERRC_METHOD_NOT_ALLOWED   = 405,
	ERRO_PROCCESS_FAILED      = 406,
	ERRO_BIKE_IS_TOOK         = 407,
	ERRO_BIKE_IS_RUNNING      = 408,
	ERRO_BIKE_IS_DAMAGED      = 409
};

/* 事件ID */
enum EventID
{
    EEVENTID_COMMON_RSP                    = 0x00,
    EEVENTID_LED_REQ                       = 0x01,
    EEVENTID_SOUND_REQ                     = 0x02,
	EEVENTID_WS2811_REQ                    = 0x03,
	EEVENTID_CAMERA_REQ                    = 0x04,

	EEVENTID_UNKOWN                        = 0xFF
};


#ifdef __cplusplus
}
#endif


#endif