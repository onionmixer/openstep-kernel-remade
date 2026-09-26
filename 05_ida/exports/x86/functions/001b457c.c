/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b457c. */
const char *__cdecl -[KeyMap keyMapping:](KeyMap *self, SEL a2, int *a3)
{
  if ( a3 ) /*0x1b4587*/
    *a3 = self->curMapping.mappingLen; /*0x1b458f*/
  return self->curMapping.mapping; /*0x1b4599*/
}
