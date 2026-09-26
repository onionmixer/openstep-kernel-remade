/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ab51c. */
id __cdecl -[IOTokenRing attachToNetworkWithAddress:](IOTokenRing *self, SEL a2, $D91DDCA3822F03E96939068EA8DE741A a3)
{
  IONetwork *v3; // eax
  char flags; // al
  id v5; // eax
  const char *v6; // eax
  int v8; // [esp-18h] [ebp-20h]
  int v9; // [esp-14h] [ebp-1Ch]
  int v10; // [esp-10h] [ebp-18h]
  _BOOL4 v11; // [esp-Ch] [ebp-14h]
  int v12; // [esp-Ch] [ebp-14h]
  unsigned int ipMtu; // [esp-8h] [ebp-10h]
  int v14; // [esp-8h] [ebp-10h]
  unsigned int ipTokenPriority; // [esp-4h] [ebp-Ch]
  int v16; // [esp-4h] [ebp-Ch]

  -[IODevice registerDevice](self, sel_registerDevice); /*0x1ab52e*/
  self->_nodeAddress = ($7DB4241D942A6BFA756C8894CCB53340)a3; /*0x1ab536*/
  -[IODevice unit](self, sel_unit); /*0x1ab55d*/
  v3 = +[Object alloc](aIonetwork, sel_alloc); /*0x1ab581*/
  self->_netif = (IONetwork *)-[IONetwork initForNetworkDevice:name:unit:type:maxTransferUnit:flags:]( /*0x1ab58f*/
                                v3,
                                sel_initForNetworkDevice_name_unit_type_maxTransferUnit_flags_);
  flags = (char)self->_flags; /*0x1ab595*/
  if ( (flags & 8) != 0 ) /*0x1ab5a0*/
  {
    ipTokenPriority = self->_ipTokenPriority; /*0x1ab5b1*/
    ipMtu = self->_ipMtu; /*0x1ab5b8*/
    v11 = (flags & 0x20) != 0; /*0x1ab5b9*/
    v5 = -[IODevice unit](self, sel_unit); /*0x1ab5c2*/
    vtrip_config((int)v5, v11, ipMtu, ipTokenPriority); /*0x1ab5cb*/
  }
  v16 = self->_nodeAddress.token_addr_octet[5]; /*0x1ab5da*/
  v14 = self->_nodeAddress.token_addr_octet[4]; /*0x1ab5e2*/
  v12 = self->_nodeAddress.token_addr_octet[3]; /*0x1ab5ea*/
  v10 = self->_nodeAddress.token_addr_octet[2]; /*0x1ab5f2*/
  v9 = self->_nodeAddress.token_addr_octet[1]; /*0x1ab5fa*/
  v8 = self->_nodeAddress.token_addr_octet[0]; /*0x1ab602*/
  v6 = -[IODevice name](self, sel_name); /*0x1ab60b*/
  IOLog((int)"%s: Token Ring Node address %02x:%02x:%02x:%02x:%02x:%02x\n", v6, v8, v9, v10, v12, v14, v16);
  return self->_netif; /*0x1ab627*/
}
