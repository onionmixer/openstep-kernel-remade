/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b182c. */
int __cdecl -[EventDriver setSpecialKeyPort:keyFlavor:keyPort:](EventDriver *self, SEL a2, int a3, int a4, int a5)
{
  if ( a3 != self->ev_port ) /*0x1b183f*/
    return -705; /*0x1b1841*/
  if ( (unsigned int)a4 <= 6 ) /*0x1b184b*/
    self->specialKeyPort[a4] = a5; /*0x1b1850*/
  return 0; /*0x1b1859*/
}
