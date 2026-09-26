/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a5828. */
void __cdecl -[IODisk setDriveName:](IODisk *self, SEL a2, const char *a3)
{
  signed __int32 v3; // eax

  v3 = strlen(a3); /*0x1a5843*/
  if ( v3 > 23 ) /*0x1a5847*/
    v3 = 23; /*0x1a5849*/
  strncpy(self->_driveName, a3, v3); /*0x1a5857*/
  self->_driveName[23] = 0; /*0x1a585c*/
}
