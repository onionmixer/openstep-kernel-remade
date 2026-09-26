/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aa710. */
int __cdecl -[IOEthernet performCommand:data:](IOEthernet *self, SEL a2, const char *a3, void *a4)
{
  int v5; // [esp+Ch] [ebp-4h]

  v5 = 0; /*0x1aa722*/
  if ( strcmp(a3, "setflags") ) /*0x1aa72f*/
  {
    if ( !strcmp(a3, "getaddr") ) /*0x1aa745*/
    {
      bcopy(&self->_ethernetAddress, a4, 6u); /*0x1aa75b*/
    }
    else if ( !strcmp(a3, "promiscuous-on") ) /*0x1aa76e*/
    {
      objc_msgSend(self->_driverCmd, sel_send_, 5); /*0x1aa77c*/
    }
    else if ( !strcmp(a3, "promiscuous-off") ) /*0x1aa786*/
    {
      objc_msgSend(self->_driverCmd, sel_send_, 6); /*0x1aa7a2*/
    }
    else if ( !strcmp(a3, "add-multicast") ) /*0x1aa7b2*/
    {
      -[IOEthernet enableMulticast:](self, sel_enableMulticast_, a4); /*0x1aa7c5*/
    }
    else if ( !strcmp(a3, "rmv-multicast") ) /*0x1aa7ce*/
    {
      -[IOEthernet disableMulticast:](self, sel_disableMulticast_, a4); /*0x1aa7e3*/
    }
    else
    {
      return 22; /*0x1aa7ec*/
    }
  }
  return v5; /*0x1aa7f9*/
}
