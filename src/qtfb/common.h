#pragma once
#include <stdint.h>
#include <sys/types.h>
#define QTFB_DEFAULT_FRAMEBUFFER 245209899
#define SOCKET_PATH "/tmp/qtfb.sock"
#define FORMAT_SHM(var, key) char var[20]; snprintf(var, 20, "/qtfb_%d", key)

#define RM2_WIDTH 1404
#define RM2_HEIGHT 1872
#define RMPP_WIDTH 1620
#define RMPP_HEIGHT 2160
#define RMPPM_WIDTH 954
#define RMPPM_HEIGHT 1696

#define MESSAGE_INITIALIZE 0
#define MESSAGE_UPDATE 1
#define MESSAGE_CUSTOM_INITIALIZE 2
#define MESSAGE_TERMINATE 3
#define MESSAGE_USERINPUT 4

#define FBFMT_RM2FB 0
#define FBFMT_RMPP_RGB888 1
#define FBFMT_RMPP_RGBA8888 2
#define FBFMT_RMPP_RGB565 3
#define FBFMT_RMPPM_RGB888 4
#define FBFMT_RMPPM_RGBA8888 5
#define FBFMT_RMPPM_RGB565 6

#define UPDATE_ALL 0
#define UPDATE_PARTIAL 1

#define INPUT_TOUCH_PRESS 0x10
#define INPUT_TOUCH_RELEASE 0x11
#define INPUT_TOUCH_UPDATE 0x12

#define INPUT_PEN_PRESS 0x20
#define INPUT_PEN_RELEASE 0x21
#define INPUT_PEN_UPDATE 0x22

#define INPUT_BTN_PRESS 0x30
#define INPUT_BTN_RELEASE 0x31

#define INPUT_BTN_X_LEFT 0
#define INPUT_BTN_X_HOME 1
#define INPUT_BTN_X_RIGHT 2

namespace qtfb {
    typedef int FBKey;

    struct InitMessageContents {
        FBKey framebufferKey;
        uint8_t framebufferType;
    };

    struct CustomInitMessageContents {
        FBKey framebufferKey;
        uint8_t framebufferType;
        uint16_t width;
        uint16_t height;
    };

    struct InitMessageResponseContents {
        int shmKeyDefined;
        size_t shmSize;
    };

    struct UpdateRegionMessageContents {
        int type;
        int x, y, w, h;
    };

    struct UserInputContents {
        int inputType;
        int devId;
        int x, y, d;
    };

    struct ClientMessage {
        uint8_t type;
        union {
            struct InitMessageContents init;
            struct UpdateRegionMessageContents update;
            struct CustomInitMessageContents customInit;
            // struct TerminateMessageContents terminate; - Terminate does not send any data.
        };
    };

    struct ServerMessage {
        uint8_t type;
        union {
            struct InitMessageResponseContents init;
            struct UserInputContents userInput;
        };
    };
}
