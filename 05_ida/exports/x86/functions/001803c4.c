/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1803c4. */
KernDevice *__cdecl -[KernDevice initWithDeviceDescription:](KernDevice *self, SEL a2, id a3)
{
  objc_super v4; // [esp+8h] [ebp-8h] BYREF

  if ( !a3 ) /*0x1803d4*/
    return (KernDevice *)-[KernDevice free](self, sel_free); /*0x1803de*/
  v4.receiver = self; /*0x1803ef*/
  v4.super_class = (Class)stru_1F9F74.ext; /*0x1803f8*/
  -[Object init](&v4, sel_init); /*0x1803ff*/
  self->_deviceDescription = a3; /*0x180404*/
  return self; /*0x18040c*/
}
