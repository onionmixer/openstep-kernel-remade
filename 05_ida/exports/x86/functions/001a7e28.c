/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a7e28. */
id __cdecl -[IODeviceDescription free](IODeviceDescription *self, SEL a2)
{
  int *v2; // ebx
  int v3; // eax
  int v4; // eax
  objc_super v6; // [esp+8h] [ebp-8h] BYREF

  v2 = (int *)self->_private; /*0x1a7e33*/
  v3 = v2[1]; /*0x1a7e36*/
  if ( v3 ) /*0x1a7e3b*/
    IOFree(*v2, 4 * v3); /*0x1a7e44*/
  v4 = v2[3]; /*0x1a7e4c*/
  if ( v4 ) /*0x1a7e51*/
    IOFree(v2[2], 8 * v4); /*0x1a7e5b*/
  IOFree((int)v2, 16); /*0x1a7e66*/
  if ( self->_devicePort ) /*0x1a7e6e*/
    destroy_dev_port(self->_devicePort); /*0x1a7e76*/
  v6.receiver = self; /*0x1a7e85*/
  v6.super_class = (Class)stru_1FA154.ext; /*0x1a7e8e*/
  return -[Object free](&v6, sel_free); /*0x1a7e9d*/
}
