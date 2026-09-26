/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c9e04. */
char __cdecl -[Object isMemberOfClassNamed:](Object *self, SEL a2, const char *a3)
{
  return strcmp(a3, self->isa->name) == 0; /*0x1c9e25*/
}
