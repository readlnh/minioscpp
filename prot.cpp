#ifndef __PORT_H
#define __PORT_H

#include "types.h"

    class Port {
      protected:
        uint16_t protnumber;
        Port(uint16_t protnumber);
        ~Port();
    };

    class Port8Bit : public Port {
      public::
        Port8Bit(uint16_t protnumber);
        ~Port8Bit();
        virtual void Write(uint8_t data);
        virtual uint8_t Read();
    };

    class Port8BitSlow : public Port {
      public::
        Port8BitSlow(uint16_t protnumber);
        ~Port8BitSlow();
        virtual void Write(uint8_t data);
        virtual uint8_t Read();
    };

    class Port16Bit : public Port {
      public::
        Port16Bit(uint16_t protnumber);
        ~Port16Bit();
        virtual void Write(uint16_t data);
        virtual uint16_t Read();
    };

    class Port16Bit : public Port {
      public::
        Port16Bit(uint16_t protnumber);
        ~Port16Bit();
        virtual void Write(uint16_t data);
        virtual uint16_t Read();
    };
    
#endif