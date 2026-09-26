/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1806b0. */
id __cdecl -[KernDeviceInterrupt free](KernDeviceInterrupt *self, SEL a2)
{
  objc_super v3; // [esp+4h] [ebp-8h] BYREF

  -[KernDeviceInterrupt detach](self, sel_detach); /*0x1806c2*/
  objc_msgSend(self->_lock, sel_free); /*0x1806d2*/
  sub_180078((int)self->_ipcMessage); /*0x1806db*/
  v3.receiver = self; /*0x1806e7*/
  v3.super_class = (Class)stru_1F9F74.super_class; /*0x1806f0*/
  return -[Object free](&v3, sel_free); /*0x1806fc*/
}
