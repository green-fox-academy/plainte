#include <iostream>
#include "WirelessAdapter.h"

int main( int argc, char* args[] )
{
  WirelessAdapter adapter("da4c32fb21", USBType::USB_TYPE_2, 100);
  adapter.info();

  WirelessAdapter adapterGood("ce8s64tg92", USBType::USB_TYPE_3, 500);
  adapterGood.info();
}