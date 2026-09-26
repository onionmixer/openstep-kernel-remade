/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17f0f8. */
KernBusRange *__cdecl -[KernBusRange init](KernBusRange *self, SEL a2)
{
  objc_super v3; // [esp+0h] [ebp-8h] BYREF

  v3.receiver = self; /*0x17f108*/
  v3.super_class = (Class)stru_1F9E34.ext; /*0x17f111*/
  return (KernBusRange *)-[Object free](&v3, sel_free); /*0x17f11d*/
}
