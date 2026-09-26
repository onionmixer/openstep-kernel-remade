/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b1860. */
int __cdecl -[EventDriver specialKeyPort:](EventDriver *self, SEL a2, int a3)
{
  if ( (unsigned int)a3 <= 6 ) /*0x1b186c*/
    return self->specialKeyPort[a3]; /*0x1b1874*/
  else
    return 0; /*0x1b186e*/
}
