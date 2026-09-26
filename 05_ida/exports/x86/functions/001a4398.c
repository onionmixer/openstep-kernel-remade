/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a4398. */
void __cdecl -[IODevice setLocation:](IODevice *self, SEL a2, const char *a3)
{
  signed __int32 v3; // ebx

  if ( a3 ) /*0x1a43a6*/
  {
    v3 = strlen(a3); /*0x1a43c0*/
    if ( v3 > 79 ) /*0x1a43c6*/
      v3 = 79; /*0x1a43c8*/
    strncpy(self->_location, a3, v3); /*0x1a43d3*/
    self->_location[v3] = 0; /*0x1a43d8*/
  }
  else
  {
    self->_location[0] = 0; /*0x1a43a8*/
  }
}
