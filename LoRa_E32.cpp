/*
 * EBYTE LoRa E32 Series
 * https://www.mischianti.org/category/my-libraries/lora-e32-devices/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 Renzo Mischianti www.mischianti.org All right reserved.
 *
 * You may copy, alter and reuse this code in any way you like, but please leave
 * reference to www.mischianti.org in your comments if you redistribute this code.
 *
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "LoRa_E32.h"

#ifdef ACTIVATE_SOFTWARE_SERIAL
LoRa_E32::LoRa_E32(byte txE32pin, byte rxE32pin, UART_BPS_RATE bpsRate)
{
    this->txE32pin = txE32pin;
    this->rxE32pin = rxE32pin;
    // @suppress("Abstract class cannot be instantiated")
    SoftwareSerial* mySerial = new SoftwareSerial((uint8_t)this->txE32pin, (uint8_t)this->rxE32pin); // "RX TX"
    this->ss = mySerial;
    this->hs = NULL;

    this->bpsRate = bpsRate;
}

LoRa_E32::LoRa_E32(byte txE32pin, byte rxE32pin, byte auxPin, UART_BPS_RATE bpsRate)
{
    this->txE32pin = txE32pin;
    this->rxE32pin = rxE32pin;
    this->auxPin = auxPin;
    // @suppress("Abstract class cannot be instantiated")
    SoftwareSerial* mySerial = new SoftwareSerial((uint8_t)this->txE32pin, (uint8_t)this->rxE32pin); // "RX TX"
    this->ss = mySerial;
    this->hs = NULL;

    this->bpsRate = bpsRate;
}

LoRa_E32::LoRa_E32(byte txE32pin, byte rxE32pin, byte auxPin, byte m0Pin, byte m1Pin, UART_BPS_RATE bpsRate)
{
    this->txE32pin = txE32pin;
    this->rxE32pin = rxE32pin;

    this->auxPin = auxPin;

    this->m0Pin = m0Pin;
    this->m1Pin = m1Pin;

    // @suppress("Abstract class cannot be instantiated")
    SoftwareSerial* mySerial = new SoftwareSerial((uint8_t)this->txE32pin, (uint8_t)this->rxE32pin); // "RX TX"
    this->ss = mySerial;
    this->hs = NULL;

    this->bpsRate = bpsRate;
}
#endif

LoRa_E32::LoRa_E32(HardwareSerial* serial, UART_BPS_RATE bpsRate)
{
    this->txE32pin = txE32pin;
    this->rxE32pin = rxE32pin;

#ifdef ACTIVATE_SOFTWARE_SERIAL
    this->ss = NULL;
#endif

    this->hs = serial;

    this->bpsRate = bpsRate;
}

LoRa_E32::LoRa_E32(HardwareSerial* serial, byte auxPin, UART_BPS_RATE bpsRate)
{
    this->txE32pin = txE32pin;
    this->rxE32pin = rxE32pin;
    this->auxPin = auxPin;

#ifdef ACTIVATE_SOFTWARE_SERIAL
    this->ss = NULL;
#endif

    this->hs = serial;

    this->bpsRate = bpsRate;
}

LoRa_E32::LoRa_E32(HardwareSerial* serial, byte auxPin, byte m0Pin, byte m1Pin, UART_BPS_RATE bpsRate)
{
    this->txE32pin = txE32pin;
    this->rxE32pin = rxE32pin;

    this->auxPin = auxPin;

    this->m0Pin = m0Pin;
    this->m1Pin = m1Pin;

#ifdef ACTIVATE_SOFTWARE_SERIAL
    this->ss = NULL;
#endif

    this->hs = serial;

    this->bpsRate = bpsRate;
}

#ifdef HARDWARE_SERIAL_SELECTABLE_PIN
LoRa_E32::LoRa_E32(byte txE32pin, byte rxE32pin, HardwareSerial* serial, UART_BPS_RATE bpsRate, uint32_t serialConfig)
{
    this->txE32pin = txE32pin;
    this->rxE32pin = rxE32pin;

#ifdef ACTIVATE_SOFTWARE_SERIAL
    this->ss = NULL;
#endif

    this->serialConfig = serialConfig;

    this->hs = serial;

    this->bpsRate = bpsRate;
}

LoRa_E32::LoRa_E32(byte txE32pin, byte rxE32pin, HardwareSerial* serial, byte auxPin, UART_BPS_RATE bpsRate, uint32_t serialConfig)
{
    this->txE32pin = txE32pin;
    this->rxE32pin = rxE32pin;
    this->auxPin = auxPin;

#ifdef ACTIVATE_SOFTWARE_SERIAL
    this->ss = NULL;
#endif

    this->serialConfig = serialConfig;

    this->hs = serial;

    this->bpsRate = bpsRate;
}

LoRa_E32::LoRa_E32(byte txE32pin, byte rxE32pin, HardwareSerial* serial, byte auxPin, byte m0Pin, byte m1Pin, UART_BPS_RATE bpsRate, uint32_t serialConfig)
{
    this->txE32pin = txE32pin;
    this->rxE32pin = rxE32pin;

    this->auxPin = auxPin;

    this->m0Pin = m0Pin;
    this->m1Pin = m1Pin;

#ifdef ACTIVATE_SOFTWARE_SERIAL
    this->ss = NULL;
#endif

    this->serialConfig = serialConfig;

    this->hs = serial;

    this->bpsRate = bpsRate;
}
#endif

#ifdef ACTIVATE_SOFTWARE_SERIAL

LoRa_E32::LoRa_E32(SoftwareSerial* serial, UART_BPS_RATE bpsRate)
{
    this->txE32pin = txE32pin;
    this->rxE32pin = rxE32pin;

    this->ss = serial;
    this->hs = NULL;

    this->bpsRate = bpsRate;
}

LoRa_E32::LoRa_E32(SoftwareSerial* serial, byte auxPin, UART_BPS_RATE bpsRate)
{
    this->txE32pin = txE32pin;
    this->rxE32pin = rxE32pin;
    this->auxPin = auxPin;

    this->ss = serial;
    this->hs = NULL;

    this->bpsRate = bpsRate;
}

LoRa_E32::LoRa_E32(SoftwareSerial* serial, byte auxPin, byte m0Pin, byte m1Pin, UART_BPS_RATE bpsRate)
{
    this->txE32pin = txE32pin;
    this->rxE32pin = rxE32pin;

    this->auxPin = auxPin;

    this->m0Pin = m0Pin;
    this->m1Pin = m1Pin;

    this->ss = serial;
    this->hs = NULL;

    this->bpsRate = bpsRate;
}
#endif

bool LoRa_E32::begin(const MODE_TYPE mode)
{
    if (this->auxPin != -1) {
        pinMode(this->auxPin, INPUT);
        DEBUG_PRINTLN("Init AUX pin!");
    }
    if (this->m0Pin != -1) {
        pinMode(this->m0Pin, OUTPUT);
        DEBUG_PRINTLN("Init M0 pin!");
        digitalWrite(this->m0Pin, HIGH);
    }
    if (this->m1Pin != -1) {
        pinMode(this->m1Pin, OUTPUT);
        DEBUG_PRINTLN("Init M1 pin!");
        digitalWrite(this->m1Pin, HIGH);
    }

    // DEBUG_PRINTLN("Begin ex");
    if (this->hs) {
        DEBUG_PRINTLN("Begin Hardware Serial");

#ifdef HARDWARE_SERIAL_SELECTABLE_PIN
        if (this->txE32pin != -1 && this->rxE32pin != -1) {
            this->serialDef.begin(*this->hs, this->bpsRate, this->serialConfig, this->txE32pin, this->rxE32pin);
        } else {
            this->serialDef.begin(*this->hs, this->bpsRate, this->serialConfig);
        }
#endif
#ifndef HARDWARE_SERIAL_SELECTABLE_PIN
        this->serialDef.begin(*this->hs, this->bpsRate);
#endif
        while (!this->hs) {
            ; // wait for serial port to connect. Needed for native USB
        }

#ifdef ACTIVATE_SOFTWARE_SERIAL
    } else if (this->ss) {
        DEBUG_PRINTLN("Begin Software Serial");

        this->serialDef.begin(*this->ss, this->bpsRate);
    } else {
        DEBUG_PRINTLN("Begin Software Serial Pin");
        // @suppress("Abstract class cannot be instantiated")
        SoftwareSerial* mySerial = new SoftwareSerial((int)this->txE32pin, (int)this->rxE32pin); // "RX TX"
        this->ss = mySerial;

        DEBUG_PRINT("RX Pin: ");
        DEBUG_PRINT((int)this->txE32pin);
        DEBUG_PRINT("TX Pin: ");
        DEBUG_PRINTLN((int)this->rxE32pin);

        this->serialDef.begin(*this->ss, this->bpsRate);
#endif
    }

    this->serialDef.stream->setTimeout(1000);
    Status status = setMode(mode);

    return status == SUCCESS;
}

/*

Utility method to wait until module is doen tranmitting
a timeout is provided to avoid an infinite loop

*/

Status LoRa_E32::waitCompleteResponse(unsigned long timeout, unsigned int waitNoAux)
{
    Status result = SUCCESS;
    unsigned long t = millis();

    // make darn sure millis() is not about to reach max data type limit and start over
    if (((unsigned long)(t + timeout)) == 0) {
        t = 0;
    }

    // if AUX pin was supplied and look for HIGH state
    // note you can omit using AUX if no pins are available, but you will have to use delay() to let module finish
    if (this->auxPin != -1) {
        bool wasLow = false;
        while (digitalRead(this->auxPin) == LOW) {
            wasLow = true;
            if ((millis() - t) > timeout) {
                result = ERR_E32_TIMEOUT;
                DEBUG_PRINTLN("Timeout error!");
                return result;
            }
            yield();
        }
        if (wasLow) {
            DEBUG_PRINTLN("AUX HIGH!");
        }
    } else {
        // if you can't use aux pin, use 4K7 pullup with Arduino
        // you may need to adjust this value if transmissions fail
        this->managedDelay(waitNoAux);
        DEBUG_PRINTLN(F("Wait no AUX pin!"));
    }

    // per data sheet control after aux goes high is 2ms so delay for at least that long)
    this->managedDelay(20);

    return result;
}

/*

//delay() in a library is not a good idea as it can stop interrupts
//just poll internal time until timeout is reached

*/

void LoRa_E32::managedDelay(unsigned long timeout)
{
    delay(timeout);
}

/*

Method to indicate availability

*/

int LoRa_E32::available(unsigned long timeout)
{
    return this->serialDef.stream->available();
}

/*

Method to flush send buffer

*/

void LoRa_E32::flush()
{
    this->serialDef.stream->flush();
}

void LoRa_E32::cleanUARTBuffer()
{
    while (this->serialDef.stream->available()) {
        this->serialDef.stream->read();
    }
}

/*

Method to send a chunk of data provided data is in a struct--my personal favorite as you
need not parse or worry about sprintf() inability to handle floats

TTP: put your structure definition into a .h file and include in both the sender and reciever
sketches

NOTE: of your sender and receiver MCU's are different (Teensy and Arduino) caution on the data
types each handle ints floats differently

*/

Status LoRa_E32::sendStruct(const void* structureManaged, uint16_t size_, bool fixed)
{
    if (size_ > MAX_SIZE_TX_PACKET) {
        return ERR_E32_PACKET_TOO_BIG;
    }

    if (fixed) {
        size_ += 3;
    }

    Status result = SUCCESS;

    uint8_t len = this->serialDef.stream->write((uint8_t*)structureManaged, size_);
    if (len != size_) {
        DEBUG_PRINT(F("Send... len:"))
        DEBUG_PRINT(len);
        DEBUG_PRINT(F(" size:"))
        DEBUG_PRINT(size_);
        if (len == 0) {
            result = ERR_E32_NO_RESPONSE_FROM_DEVICE;
        } else {
            result = ERR_E32_DATA_SIZE_NOT_MATCH;
        }
    }

    if (result != SUCCESS) {
        return result;
    }

    result = this->waitCompleteResponse(1000);
    if (result != SUCCESS) {
        return result;
    }

    DEBUG_PRINTLN(F("send ok!"))

    return result;
}

/*

Method to get a chunk of data provided data is in a struct--my personal favorite as you
need not parse or worry about sprintf() inability to handle floats

TTP: put your structure definition into a .h file and include in both the sender and reciever
sketches

NOTE: of your sender and receiver MCU's are different (Teensy and Arduino) caution on the data
types each handle ints floats differently

*/

Status LoRa_E32::receiveStruct(const void* structureManaged, uint16_t size_)
{
    Status result = SUCCESS;

    uint8_t len = this->serialDef.stream->readBytes((uint8_t*)structureManaged, size_);

    DEBUG_PRINT("Requested: ");
    DEBUG_PRINT(size_);
    DEBUG_PRINT(", received: ");
    DEBUG_PRINTLN(len);

    if (len != size_) {
        if (len == 0) {
            result = ERR_E32_NO_RESPONSE_FROM_DEVICE;
        } else {
            result = ERR_E32_DATA_SIZE_NOT_MATCH;
        }
    } else {
        result = SUCCESS;
    }

    return result;
}

/*

method to set the mode (program, normal, etc.)

*/

Status LoRa_E32::setMode(MODE_TYPE mode, bool wait)
{
    // data sheet claims module needs some extra time after mode setting (2ms)
    // most of my projects uses 10 ms, but 40ms is safer

    if (this->m0Pin == -1 && this->m1Pin == -1) {
        DEBUG_PRINTLN(F("The M0 and M1 pins is not set, this mean that you are connect directly the pins as you need!"))
    } else {
        switch (mode) {
        case MODE_0_NORMAL:
            // Mode 0 | normal operation
            digitalWrite(this->m0Pin, LOW);
            digitalWrite(this->m1Pin, LOW);
            DEBUG_PRINTLN("MODE NORMAL!");
            break;
        case MODE_1_WAKE_UP:
            digitalWrite(this->m0Pin, HIGH);
            digitalWrite(this->m1Pin, LOW);
            DEBUG_PRINTLN("MODE WAKE UP!");
            break;
        case MODE_2_POWER_SAVING:
            digitalWrite(this->m0Pin, LOW);
            digitalWrite(this->m1Pin, HIGH);
            DEBUG_PRINTLN("MODE POWER SAVING!");
            break;
        case MODE_3_SLEEP:
            // Mode 3 | Setting operation
            digitalWrite(this->m0Pin, HIGH);
            digitalWrite(this->m1Pin, HIGH);
            DEBUG_PRINTLN("MODE PROGRAM/SLEEP!");
            break;
        default:
            return ERR_E32_INVALID_PARAM;
        }
    }

    if (wait) {
        // wait until aux pin goes back high
        Status res = this->waitCompleteResponse(1000);
        if (res != SUCCESS) {
            return res;
        }
    }

    this->mode = mode;

    this->cleanUARTBuffer();

    return SUCCESS;
}

MODE_TYPE LoRa_E32::getMode()
{
    return this->mode;
}

void LoRa_E32::writeProgramCommand(PROGRAM_COMMAND cmd)
{
    uint8_t CMD[3] = { cmd, cmd, cmd };
    this->serialDef.stream->write(CMD, 3);

    this->managedDelay(50); //need ti check
}

ResponseStructContainer LoRa_E32::getConfiguration()
{
    ResponseStructContainer rc;

    rc.status.code = enterProgramMode();
    if (rc.status.code != SUCCESS) {
        return rc;
    }

    this->writeProgramCommand(READ_CONFIGURATION);

    rc.data = malloc(sizeof(Configuration));
    rc.status.code = this->receiveStruct((uint8_t*)rc.data, sizeof(Configuration));

#ifdef LoRa_E32_DEBUG
    this->printParameters((Configuration*)rc.data);
#endif

    if (rc.status.code != SUCCESS) {
        this->leaveProgramMode();
        return rc;
    }

    DEBUG_PRINTLN("----------------------------------------");
    DEBUG_PRINT(F("HEAD BIN INSIDE: "));
    DEBUG_PRINT(((Configuration*)rc.data)->HEAD, BIN);
    DEBUG_PRINT(" ");
    DEBUG_PRINT(((Configuration*)rc.data)->HEAD, DEC);
    DEBUG_PRINT(" ");
    DEBUG_PRINTLN(((Configuration*)rc.data)->HEAD, HEX);
    DEBUG_PRINTLN("----------------------------------------");

    rc.status.code = this->leaveProgramMode();
    if (rc.status.code != SUCCESS) {
        return rc;
    }

    if (0xC0 != ((Configuration*)rc.data)->HEAD && 0xC2 != ((Configuration*)rc.data)->HEAD) {
        rc.status.code = ERR_E32_HEAD_NOT_RECOGNIZED;
    }

    return rc;
}

RESPONSE_STATUS LoRa_E32::enterProgramMode()
{
    RESPONSE_STATUS result = SUCCESS;

    this->prevMode = this->mode;
    if (this->mode != MODE_3_PROGRAM) {
        result = this->setMode(MODE_3_PROGRAM);
        if (result != SUCCESS) {
            return result;
        }
    }

    if (this->bpsRate == UART_BPS_RATE_9600) {
        return result;
    }

    if (this->hs) {
        this->serialDef.begin(*this->hs, UART_BPS_RATE_9600);
    }
#ifdef ACTIVATE_SOFTWARE_SERIAL
    else {
        if (this->ss) {
            this->serialDef.begin(*this->ss, UART_BPS_RATE_9600);
        }
    }
#endif

    return result;
}

RESPONSE_STATUS LoRa_E32::leaveProgramMode()
{
    RESPONSE_STATUS result = SUCCESS;

    if (this->bpsRate != UART_BPS_RATE_9600) {
        if (this->hs) {
            this->serialDef.begin(*this->hs, this->bpsRate);
        }
#ifdef ACTIVATE_SOFTWARE_SERIAL
        else {
            if (this->ss) {
                this->serialDef.begin(*this->ss, this->bpsRate);
            }
        }
#endif
    }

    if (this->prevMode != MODE_3_PROGRAM) {
        result = this->setMode(prevMode);
    }

    return result;
}

ResponseStatus LoRa_E32::setConfiguration(Configuration configuration, PROGRAM_COMMAND saveType)
{
    ResponseStatus rc;

    rc.code = enterProgramMode();
    if (rc.code != SUCCESS)
        return rc;

    configuration.HEAD = saveType;

    rc.code = this->sendStruct((uint8_t*)&configuration, sizeof(Configuration));
    if (rc.code != SUCCESS) {
        this->leaveProgramMode();
        return rc;
    }

    rc.code = this->receiveStruct((uint8_t*)&configuration, sizeof(Configuration));
    if (rc.code != SUCCESS) {
        this->leaveProgramMode();
        return rc;
    }

    DEBUG_PRINTLN("----------------------------------------");
    DEBUG_PRINT(F("HEAD BIN INSIDE: "));
    DEBUG_PRINT(configuration.HEAD, BIN);
    DEBUG_PRINT(" ");
    DEBUG_PRINT(configuration.HEAD, DEC);
    DEBUG_PRINT(" ");
    DEBUG_PRINTLN(configuration.HEAD, HEX);
    DEBUG_PRINTLN("----------------------------------------");

    // give some time to apply new settings
    this->managedDelay(20);

    rc.code = this->leaveProgramMode();
    if (rc.code != SUCCESS)
        return rc;

    if (0xC0 != configuration.HEAD && 0xC2 != configuration.HEAD) {
        rc.code = ERR_E32_HEAD_NOT_RECOGNIZED;
    }

    return rc;
}

ResponseStructContainer LoRa_E32::getModuleInformation()
{
    ResponseStructContainer rc;

    rc.status.code = enterProgramMode();
    if (rc.status.code != SUCCESS)
        return rc;

    this->writeProgramCommand(READ_MODULE_VERSION);

    struct ModuleInformation* moduleInformation = (ModuleInformation*)malloc(sizeof(ModuleInformation));
    rc.status.code = this->receiveStruct((uint8_t*)moduleInformation, sizeof(ModuleInformation));
    if (rc.status.code != SUCCESS) {
        this->leaveProgramMode();
        return rc;
    }

    rc.status.code = this->leaveProgramMode();
    if (rc.status.code != SUCCESS)
        return rc;

    DEBUG_PRINTLN("----------------------------------------");
    DEBUG_PRINT(F("HEAD BIN INSIDE: "));
    DEBUG_PRINT(moduleInformation->HEAD, BIN);
    DEBUG_PRINT(" ");
    DEBUG_PRINT(moduleInformation->HEAD, DEC);
    DEBUG_PRINT(" ");
    DEBUG_PRINTLN(moduleInformation->HEAD, HEX);

    DEBUG_PRINT(F("Freq.: "));
    DEBUG_PRINTLN(moduleInformation->frequency, HEX);
    DEBUG_PRINT(F("Version  : "));
    DEBUG_PRINTLN(moduleInformation->version, HEX);
    DEBUG_PRINT(F("Features : "));
    DEBUG_PRINTLN(moduleInformation->features, HEX);
    DEBUG_PRINTLN("----------------------------------------");

    if (0xC3 != moduleInformation->HEAD) {
        rc.status.code = ERR_E32_HEAD_NOT_RECOGNIZED;
    }

    rc.data = moduleInformation; // malloc(sizeof (moduleInformation));

    return rc;
}

ResponseStatus LoRa_E32::resetModule()
{
    ResponseStatus status;

    status.code = enterProgramMode();
    if (status.code != SUCCESS)
        return status;

    this->writeProgramCommand(WRITE_RESET_MODULE);

    status.code = this->waitCompleteResponse(1000);
    if (status.code != SUCCESS) {
        this->leaveProgramMode();
        return status;
    }

    status.code = this->leaveProgramMode();

    return status;
}

ResponseContainer LoRa_E32::receiveMessage()
{
    ResponseContainer rc;
    rc.status.code = SUCCESS;
    rc.data = this->serialDef.stream->readString();

    return rc;
}

ResponseContainer LoRa_E32::receiveMessageUntil(char delimiter)
{
    ResponseContainer rc;
    rc.status.code = SUCCESS;
    rc.data = this->serialDef.stream->readStringUntil(delimiter);

    return rc;
}

ResponseStructContainer LoRa_E32::receiveMessage(const uint8_t size)
{
    ResponseStructContainer rc;
    rc.data = malloc(size);
    rc.status.code = this->receiveStruct((uint8_t*)rc.data, size);

    return rc;
}

ResponseContainer LoRa_E32::receiveInitialMessage(const uint8_t size)
{
    ResponseContainer rc;
    rc.status.code = SUCCESS;
    char buff[size + 1];

    memset(buff, '\0', sizeof(buff));
    uint8_t len = this->serialDef.stream->readBytes(buff, size);
    if (len != size) {
        if (len == 0) {
            rc.status.code = ERR_E32_NO_RESPONSE_FROM_DEVICE;
        } else {
            rc.status.code = ERR_E32_DATA_SIZE_NOT_MATCH;
        }
        return rc;
    }

    rc.data = buff;

    return rc;
}

ResponseStatus LoRa_E32::sendMessage(const void* message, const uint8_t size)
{
    ResponseStatus status;
    status.code = this->sendStruct(message, size);

    return status;
}

ResponseStatus LoRa_E32::sendMessage(const String message)
{
    DEBUG_PRINT(F("Send message: "));
    DEBUG_PRINT(message);
    byte size = message.length();
    DEBUG_PRINT(F(" size: "));
    DEBUG_PRINTLN(size);

    ResponseStatus status;
    status.code = this->sendStruct(message.c_str(), size);

    return status;
}

ResponseStatus LoRa_E32::sendFixedMessage(byte ADDH, byte ADDL, byte CHAN, const String message)
{
    byte size = message.length();
    return this->sendFixedMessage(ADDH, ADDL, CHAN, message.c_str(), size);
}

ResponseStatus LoRa_E32::sendBroadcastFixedMessage(byte CHAN, const String message)
{
    return this->sendFixedMessage(0xFF, 0xFF, CHAN, message);
}

typedef struct fixedStransmission {
    byte ADDH = 0;
    byte ADDL = 0;
    byte CHAN = 0;
    byte message[];
} FixedStransmission;

FixedStransmission* init_stack(uint8_t m)
{
    FixedStransmission* st = (FixedStransmission*)malloc((3 + m) * sizeof(byte));
    return st;
}

ResponseStatus LoRa_E32::sendFixedMessage(byte ADDH, byte ADDL, byte CHAN, const void* message, const uint8_t size)
{
    FixedStransmission* fixedStransmission = init_stack(size);

    fixedStransmission->ADDH = ADDH;
    fixedStransmission->ADDL = ADDL;
    fixedStransmission->CHAN = CHAN;

    memcpy(fixedStransmission->message, (uint8_t*)message, size);

    ResponseStatus status;
    status.code = this->sendStruct((uint8_t*)fixedStransmission, size, true);

    free(fixedStransmission);

    return status;
}

ResponseStatus LoRa_E32::sendBroadcastFixedMessage(byte CHAN, const void* message, const uint8_t size)
{
    return this->sendFixedMessage(0xFF, 0xFF, CHAN, message, size);
}

#define KeeLoq_NLF 0x3A5C742E

unsigned long LoRa_E32::encrypt(unsigned long data)
{
    unsigned long x = data;
    unsigned long r;
    int keyBitNo, index;
    unsigned long keyBitVal, bitVal;

    for (r = 0; r < 528; r++) {
        keyBitNo = r & 63;
        if (keyBitNo < 32)
            keyBitVal = bitRead(this->halfKeyloqKey, keyBitNo); // key low
        else
            keyBitVal = bitRead(this->halfKeyloqKey, keyBitNo - 32); // key hight
        index = 1 * bitRead(x, 1) + 2 * bitRead(x, 9) + 4 * bitRead(x, 20) + 8 * bitRead(x, 26) + 16 * bitRead(x, 31);
        bitVal = bitRead(x, 0) ^ bitRead(x, 16) ^ bitRead(KeeLoq_NLF, index) ^ keyBitVal;
        x = (x >> 1) ^ bitVal << 31;
    }
    return x;
}

unsigned long LoRa_E32::decrypt(unsigned long data)
{
    unsigned long x = data;
    unsigned long r;
    int keyBitNo, index;
    unsigned long keyBitVal, bitVal;

    for (r = 0; r < 528; r++) {
        keyBitNo = (15 - r) & 63;
        if (keyBitNo < 32)
            keyBitVal = bitRead(this->halfKeyloqKey, keyBitNo); // key low
        else
            keyBitVal = bitRead(this->halfKeyloqKey, keyBitNo - 32); // key hight
        index = 1 * bitRead(x, 0) + 2 * bitRead(x, 8) + 4 * bitRead(x, 19) + 8 * bitRead(x, 25) + 16 * bitRead(x, 30);
        bitVal = bitRead(x, 31) ^ bitRead(x, 15) ^ bitRead(KeeLoq_NLF, index) ^ keyBitVal;
        x = (x << 1) ^ bitVal;
    }
    return x;
}
#ifdef LoRa_E32_DEBUG
void LoRa_E32::printParameters(struct Configuration* configuration)
{
    DEBUG_PRINTLN("----------------------------------------");

    DEBUG_PRINT(F("HEAD : "));
    DEBUG_PRINT(configuration->HEAD, BIN);
    DEBUG_PRINT(" ");
    DEBUG_PRINT(configuration->HEAD, DEC);
    DEBUG_PRINT(" ");
    DEBUG_PRINTLN(configuration->HEAD, HEX);
    DEBUG_PRINTLN(F(" "));
    DEBUG_PRINT(F("AddH : "));
    DEBUG_PRINTLN(configuration->ADDH, DEC);
    DEBUG_PRINT(F("AddL : "));
    DEBUG_PRINTLN(configuration->ADDL, DEC);
    DEBUG_PRINT(F("Chan : "));
    DEBUG_PRINT(configuration->CHAN, DEC);
    DEBUG_PRINT(" -> ");
    DEBUG_PRINTLN(configuration->getChannelDescription());
    DEBUG_PRINTLN(F(" "));
    DEBUG_PRINT(F("SpeedParityBit     : "));
    DEBUG_PRINT(configuration->SPED.uartParity, BIN);
    DEBUG_PRINT(" -> ");
    DEBUG_PRINTLN(configuration->SPED.getUARTParityDescription());
    DEBUG_PRINT(F("SpeedUARTDatte  : "));
    DEBUG_PRINT(configuration->SPED.uartBaudRate, BIN);
    DEBUG_PRINT(" -> ");
    DEBUG_PRINTLN(configuration->SPED.getUARTBaudRate());
    DEBUG_PRINT(F("SpeedAirDataRate   : "));
    DEBUG_PRINT(configuration->SPED.airDataRate, BIN);
    DEBUG_PRINT(" -> ");
    DEBUG_PRINTLN(configuration->SPED.getAirDataRate());

    DEBUG_PRINT(F("OptionTrans        : "));
    DEBUG_PRINT(configuration->OPTION.fixedTransmission, BIN);
    DEBUG_PRINT(" -> ");
    DEBUG_PRINTLN(configuration->OPTION.getFixedTransmissionDescription());
    DEBUG_PRINT(F("OptionPullup       : "));
    DEBUG_PRINT(configuration->OPTION.ioDriveMode, BIN);
    DEBUG_PRINT(" -> ");
    DEBUG_PRINTLN(configuration->OPTION.getIODroveModeDescription());
    DEBUG_PRINT(F("OptionWakeup       : "));
    DEBUG_PRINT(configuration->OPTION.wirelessWakeupTime, BIN);
    DEBUG_PRINT(" -> ");
    DEBUG_PRINTLN(configuration->OPTION.getWirelessWakeUPTimeDescription());
    DEBUG_PRINT(F("OptionFEC          : "));
    DEBUG_PRINT(configuration->OPTION.fec, BIN);
    DEBUG_PRINT(" -> ");
    DEBUG_PRINTLN(configuration->OPTION.getFECDescription());
    DEBUG_PRINT(F("OptionPower        : "));
    DEBUG_PRINT(configuration->OPTION.transmissionPower, BIN);
    DEBUG_PRINT(" -> ");
    DEBUG_PRINTLN(configuration->OPTION.getTransmissionPowerDescription());

    DEBUG_PRINTLN("----------------------------------------");
}
#endif
