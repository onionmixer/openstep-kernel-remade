/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b7a4c. */
id __cdecl -[AudioChannel free](AudioChannel *self, SEL a2)
{
  objc_super v3; // [esp+4h] [ebp-8h] BYREF

  IOLog((int)"AudioChannel: -free not supported\n");
  v3.receiver = self; /*0x1b7a67*/
  v3.super_class = (Class)stru_1FA474.ext; /*0x1b7a70*/
  return -[Object free](&v3, sel_free); /*0x1b7a7c*/
}
