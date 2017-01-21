#include <serial/serial.h>
#include <boost/thread.hpp>
#include <iostream>

namespace serial {
Device::Device(const std::string port, const int baudrate) :
  port(port),
  baudrate(baudrate),
  dev(ios)
{}

Device::~Device() {
  dev.close();
}

void Device::open()
{
  try {
    dev.close();
    dev.open(port);
    dev.set_option(
        boost::asio::serial_port::baud_rate(baudrate)
        );
    return;
  }
  catch (const std::exception& e) {
    std::cerr << "Error opening serial device: " << port
      << ": " << e.what() << ", retrying.." << std::endl;
    boost::this_thread::sleep(boost::posix_time::seconds(1));
    open();
  }
}

bool Device::read_byte(uint8_t &i) {
  while(true) {
    try {
      dev.read_some(boost::asio::buffer(&i, sizeof(i)));
      return true;
    } catch(const std::exception &e) {
      open();
      return false;
    }
  }
}

}
