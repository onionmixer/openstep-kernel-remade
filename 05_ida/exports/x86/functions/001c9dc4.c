/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c9dc4. */
char __cdecl -[Object isKindOfClassNamed:](Object *self, SEL a2, const char *a3)
{
  Class isa; // ebx

  isa = self->isa; /*0x1c9dcf*/
  if ( !self->isa ) /*0x1c9dcf*/
    return 0; /*0x1c9df7*/
  while ( strcmp(a3, isa->name) ) /*0x1c9de7*/
  {
    isa = isa->super_class; /*0x1c9df0*/
    if ( !isa ) /*0x1c9df5*/
      return 0; /*0x1c9df5*/
  }
  return 1; /*0x1c9dfc*/
}
