#include "device_driver.h"
#include <exception>

class ReadFailException : public std::exception {
};
class WriteFailException : public std::exception {
};

DeviceDriver::DeviceDriver(FlashMemoryDevice* hardware) : m_hardware(hardware)
{}

int DeviceDriver::read(long address)
{
    int ret = (int)(m_hardware->read(address));

    for (int i = 0; i < 4; i++) {
        int temp = (int)(m_hardware->read(address));
        if (ret != temp) {
            throw ReadFailException();
        }
        ret = temp;
    }
    return ret;
}

void DeviceDriver::write(long address, int data)
{
    int ret = (int)(m_hardware->read(address));
    if (ret != 0xFF) {
        throw WriteFailException();
    }


    // TODO: implement this method
    m_hardware->write(address, (unsigned char)data);
}