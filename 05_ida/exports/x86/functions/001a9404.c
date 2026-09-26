/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a9404. */
IOBufDevice *__cdecl -[IOBufDevice init](IOBufDevice *self, SEL a2)
{
  unsigned int v2; // ecx
  int v3; // edx
  char *v4; // eax

  v2 = 0; /*0x1a940b*/
  v3 = 296; /*0x1a940d*/
  do /*0x1a942f*/
  {
    v4 = (char *)self + v3; /*0x1a9414*/
    *(_DWORD *)v4 = 0; /*0x1a9417*/
    *((_DWORD *)v4 + 1) = 0; /*0x1a941d*/
    v4[8] = 0; /*0x1a9424*/
    v3 += 92; /*0x1a9428*/
    ++v2; /*0x1a942b*/
  }
  while ( v2 <= 3 ); /*0x1a942f*/
  return self; /*0x1a9433*/
}
