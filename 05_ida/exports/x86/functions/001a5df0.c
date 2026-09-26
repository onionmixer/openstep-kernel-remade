/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a5df0. */
void __cdecl -[IODisk diskIsEjecting:](IODisk *self, SEL a2, int a3)
{
  int v3; // edx

  if ( a3 == 1 ) /*0x1a5df9*/
  {
    v3 = 0; /*0x1a5e0c*/
  }
  else if ( a3 ) /*0x1a5dfb*/
  {
    if ( a3 == 2 ) /*0x1a5e00*/
      v3 = -1; /*0x1a5e10*/
  }
  else
  {
    v3 = 2; /*0x1a5e04*/
  }
  volCheckEjecting((int)self, v3); /*0x1a5e1a*/
}
