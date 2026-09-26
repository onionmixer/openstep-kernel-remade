/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c9620. */
id __cdecl -[List free](List *self, SEL a2)
{
  objc_super v3; // [esp+4h] [ebp-8h] BYREF

  free(self->dataPtr); /*0x1c962e*/
  v3.receiver = self; /*0x1c963a*/
  v3.super_class = (Class)stru_1FA6A4.super_class; /*0x1c9643*/
  return -[Object free](&v3, sel_free); /*0x1c964f*/
}
