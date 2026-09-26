/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a40f8. */
IODevice *__cdecl -[IODevice init](IODevice *self, SEL a2)
{
  objc_super v3; // [esp+0h] [ebp-8h] BYREF

  v3.receiver = self; /*0x1a4108*/
  v3.super_class = (Class)stru_1FA0B4.super_class; /*0x1a4111*/
  return -[Object init](&v3, sel_init); /*0x1a411d*/
}
