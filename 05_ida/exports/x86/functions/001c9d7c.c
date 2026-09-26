/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c9d7c. */
char __cdecl -[Object isKindOf:](Object *self, SEL a2, id a3)
{
  Class isa; // eax

  isa = self->isa; /*0x1c9d85*/
  if ( !self->isa ) /*0x1c9d85*/
    return 0; /*0x1c9da3*/
  while ( isa != a3 ) /*0x1c9d8e*/
  {
    isa = isa->super_class; /*0x1c9d9c*/
    if ( !isa ) /*0x1c9da1*/
      return 0; /*0x1c9da1*/
  }
  return 1; /*0x1c9d97*/
}
