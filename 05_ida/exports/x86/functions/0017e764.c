/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17e764. */
KernLock *__cdecl -[KernLock initWithLevel:](KernLock *self, SEL a2, int a3)
{
  KernLock *result; // eax
  objc_super v4; // [esp+0h] [ebp-8h] BYREF

  result = self; /*0x17e76a*/
  if ( a3 ) /*0x17e772*/
  {
    self->_lockLevel = a3; /*0x17e794*/
  }
  else
  {
    v4.receiver = self; /*0x17e77b*/
    v4.super_class = (Class)stru_1F9DE4.super_class; /*0x17e784*/
    return (KernLock *)-[Object free](&v4, sel_free); /*0x17e78b*/
  }
  return result; /*0x17e790*/
}
