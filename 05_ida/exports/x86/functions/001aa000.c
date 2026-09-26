/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aa000. */
id __cdecl -[DriverCmd free](DriverCmd *self, SEL a2)
{
  objc_super v3; // [esp+4h] [ebp-8h] BYREF

  objc_msgSend(self->_interLock, sel_free); /*0x1aa015*/
  port_release(self->_driverPort_kern); /*0x1aa01e*/
  v3.receiver = self; /*0x1aa02a*/
  v3.super_class = (Class)stru_1FA2E4.super_class; /*0x1aa033*/
  return -[Object free](&v3, sel_free); /*0x1aa03f*/
}
