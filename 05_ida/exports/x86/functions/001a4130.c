/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a4130. */
id __cdecl -[IODevice free](IODevice *self, SEL a2)
{
  objc_super v3; // [esp+4h] [ebp-8h] BYREF

  -[IODevice unregisterDevice](self, sel_unregisterDevice); /*0x1a4142*/
  v3.receiver = self; /*0x1a414e*/
  v3.super_class = (Class)stru_1FA0B4.super_class; /*0x1a4157*/
  return -[Object free](&v3, sel_free); /*0x1a4163*/
}
