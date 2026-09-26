/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b8184. */
char __cdecl -[AudioChannel checkOwner:](AudioChannel *self, SEL a2, int a3)
{
  int exclusiveUser; // eax

  exclusiveUser = self->exclusiveUser; /*0x1b818a*/
  return !exclusiveUser || a3 == exclusiveUser; /*0x1b819a*/
}
