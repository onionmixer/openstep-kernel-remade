/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ab494. */
id __cdecl -[IOTokenRing free](IOTokenRing *self, SEL a2)
{
  id driverCmd; // eax
  IONetwork *netif; // eax
  objc_super v5; // [esp+4h] [ebp-8h] BYREF

  -[IOTokenRing clearTimeout](self, sel_clearTimeout); /*0x1ab4a6*/
  driverCmd = self->_driverCmd; /*0x1ab4ae*/
  if ( driverCmd ) /*0x1ab4b6*/
  {
    objc_msgSend(driverCmd, sel_send_, 4); /*0x1ab4c2*/
    objc_msgSend(self->_driverCmd, sel_free); /*0x1ab4d5*/
  }
  netif = self->_netif; /*0x1ab4dd*/
  if ( netif ) /*0x1ab4e5*/
    -[IONetwork free](netif, sel_free); /*0x1ab4ef*/
  v5.receiver = self; /*0x1ab4fe*/
  v5.super_class = (Class)stru_1FA2E4.ext; /*0x1ab507*/
  return -[IODirectDevice free](&v5, sel_free); /*0x1ab513*/
}
