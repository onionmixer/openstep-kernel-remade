/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17e7b8. */
id __cdecl -[KernLock free](KernLock *self, SEL a2)
{
  objc_super v3; // [esp+0h] [ebp-8h] BYREF

  v3.receiver = self; /*0x17e7c8*/
  v3.super_class = (Class)stru_1F9DE4.super_class; /*0x17e7d1*/
  return -[Object free](&v3, sel_free); /*0x17e7dd*/
}
