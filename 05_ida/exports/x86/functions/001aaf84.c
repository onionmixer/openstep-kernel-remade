/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aaf84. */
id __cdecl -[DriverCmdtr free](DriverCmdtr *self, SEL a2)
{
  objc_super v3; // [esp+4h] [ebp-8h] BYREF

  objc_msgSend(self->_interLock, sel_free); /*0x1aaf99*/
  port_release(self->_driverPort_kern); /*0x1aafa2*/
  v3.receiver = self; /*0x1aafae*/
  v3.super_class = (Class)stru_1FA334.super_class; /*0x1aafb7*/
  return -[Object free](&v3, sel_free); /*0x1aafc3*/
}
