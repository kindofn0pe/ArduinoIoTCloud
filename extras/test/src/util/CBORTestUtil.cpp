/*
   Copyright (c) 2019 Arduino.  All rights reserved.
*/

/**************************************************************************************
   INCLUDE
 **************************************************************************************/

#include <util/CBORTestUtil.h>

#include <iomanip>
#include <iostream>

#include <CBOREncoder.h>

/**************************************************************************************
   NAMESPACE
 **************************************************************************************/

namespace cbor
{

/**************************************************************************************
   PUBLIC FUNCTIONS
 **************************************************************************************/

std::vector<uint8_t> encode(PropertyContainer & property_container, bool lightPayload) {
  uint8_t buf[200] = {0};
  int const bytes_buf = CBOREncoder::encode(property_container, buf, 200, lightPayload);
  if (bytes_buf == -1) {
    return std::vector<uint8_t>();
  } else {
    return std::vector<uint8_t>(buf, buf + bytes_buf);
  }
}

void print(std::vector<uint8_t> const & vect) {
  for (auto i = vect.begin(); i != vect.end(); i++) {
    std::cout << std::uppercase
              << std::hex
              << std::setw(2)
              << std::setfill('0')
              << static_cast<size_t>(*i)
              << std::dec
              << std::nouppercase
              << " ";
  }
  std::cout << std::endl;
}

/**************************************************************************************
   NAMESPACE
 **************************************************************************************/

} /* cbor */
