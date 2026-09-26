/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18042c. */
id __cdecl -[KernDevice free](KernDevice *self, SEL a2)
{
  objc_super v3; // [esp+4h] [ebp-8h] BYREF

  -[KernDevice detachInterruptPort](self, sel_detachInterruptPort); /*0x18043e*/
  v3.receiver = self; /*0x18044a*/
  v3.super_class = (Class)stru_1F9F74.ext; /*0x180453*/
  return -[Object free](&v3, sel_free); /*0x18045f*/
}
