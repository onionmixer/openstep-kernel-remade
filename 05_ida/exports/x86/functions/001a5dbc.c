/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a5dbc. */
void __cdecl -[IODisk requestInsertionPanelForDiskType:](IODisk *self, SEL a2, int a3)
{
  int v3; // edx

  if ( a3 == 1 ) /*0x1a5dc5*/
  {
    v3 = 0; /*0x1a5dd8*/
  }
  else if ( a3 ) /*0x1a5dc7*/
  {
    if ( a3 == 2 ) /*0x1a5dcc*/
      v3 = -1; /*0x1a5ddc*/
  }
  else
  {
    v3 = 2; /*0x1a5dd0*/
  }
  volCheckRequest((int)self, v3); /*0x1a5de6*/
}
