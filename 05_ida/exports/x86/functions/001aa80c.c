/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aa80c. */
id __cdecl -[IOEthernet attachToNetworkWithAddress:](IOEthernet *self, SEL a2, $D91DDCA3822F03E96939068EA8DE741A a3)
{
  IONetwork *v3; // eax
  const char *v4; // eax
  int v6; // [esp-20h] [ebp-24h]
  int v7; // [esp-1Ch] [ebp-20h]
  int v8; // [esp-18h] [ebp-1Ch]
  int v9; // [esp-14h] [ebp-18h]
  int v10; // [esp-10h] [ebp-14h]
  int v11; // [esp-Ch] [ebp-10h]

  self->_ethernetAddress = ($0F52D4C2E1E8F22E8199E6D21C589DA7)a3; /*0x1aa816*/
  -[IODevice unit](self, sel_unit); /*0x1aa83b*/
  v3 = +[Object alloc](aIonetwork, sel_alloc); /*0x1aa85f*/
  self->_netif = (IONetwork *)-[IONetwork initForNetworkDevice:name:unit:type:maxTransferUnit:flags:]( /*0x1aa86d*/
                                v3,
                                sel_initForNetworkDevice_name_unit_type_maxTransferUnit_flags_);
  -[IOEthernet registerAsDebuggerDevice](self, sel_registerAsDebuggerDevice); /*0x1aa87e*/
  v11 = self->_ethernetAddress.ether_addr_octet[5]; /*0x1aa88a*/
  v10 = self->_ethernetAddress.ether_addr_octet[4]; /*0x1aa892*/
  v9 = self->_ethernetAddress.ether_addr_octet[3]; /*0x1aa89a*/
  v8 = self->_ethernetAddress.ether_addr_octet[2]; /*0x1aa8a2*/
  v7 = self->_ethernetAddress.ether_addr_octet[1]; /*0x1aa8aa*/
  v6 = self->_ethernetAddress.ether_addr_octet[0]; /*0x1aa8b2*/
  v4 = -[IODevice name](self, sel_name); /*0x1aa8bb*/
  IOLog((int)"%s: Ethernet address %02x:%02x:%02x:%02x:%02x:%02x\n", v4, v6, v7, v8, v9, v10, v11);
  return self->_netif; /*0x1aa8d4*/
}
