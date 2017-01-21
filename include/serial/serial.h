#ifndef SERIAL_H
#define SERIAL_H
#include <boost/asio/serial_port.hpp>

namespace serial {

typedef std::vector<uint8_t> ByteVec;

class Device
{
public:
  Device(const std::string port, const int baudrate=115200);
  virtual ~Device();
  bool read_byte(uint8_t& i);
  
private:
  const std::string port;
  const int baudrate;
  boost::asio::io_service ios;
  boost::asio::serial_port dev;

  void open();
};
}

#endif /* SERIAL_H */
