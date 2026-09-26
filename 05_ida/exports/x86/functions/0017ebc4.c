/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17ebc4. */
KernBusItem *__cdecl -[KernBusItem init](KernBusItem *self, SEL a2)
{
  objc_super v3; // [esp+0h] [ebp-8h] BYREF

  v3.receiver = self; /*0x17ebd4*/
  v3.super_class = (Class)stru_1F9E84.ext; /*0x17ebdd*/
  return (KernBusItem *)-[Object free](&v3, sel_free); /*0x17ebe9*/
}
