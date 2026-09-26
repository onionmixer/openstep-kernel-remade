/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x181c64. */
const char *__cdecl -[KernStringList stringAt:](KernStringList *self, SEL a2, unsigned int a3)
{
  if ( self->count > a3 ) /*0x181c70*/
    return self->strings[a3]; /*0x181c7b*/
  else
    return nullptr; /*0x181c72*/
}
