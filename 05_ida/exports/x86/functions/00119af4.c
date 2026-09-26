/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x119af4. */
int __cdecl vfs_getnum(unsigned int a1, int a2)
{
  _BYTE *v2; // ebx
  unsigned int v3; // ecx
  int v4; // eax

  v2 = (_BYTE *)a1; /*0x119b00*/
  if ( a1 >= a2 + a1 ) /*0x119b09*/
    return -1; /*0x119b4c*/
  while ( *v2 == 0xFF ) /*0x119b13*/
  {
LABEL_7:
    if ( a2 + a1 <= (unsigned int)++v2 ) /*0x119b4a*/
      return -1; /*0x119b4a*/
  }
  v3 = 0; /*0x119b15*/
  while ( 1 ) /*0x119b26*/
  {
    v4 = (char)*v2; /*0x119b26*/
    if ( !_bittest(&v4, v3) ) /*0x119b2c*/
      break; /*0x119b2c*/
    if ( (int)++v3 > 7 ) /*0x119b44*/
      goto LABEL_7; /*0x119b44*/
  }
  *v2 |= 1 << v3; /*0x119b37*/
  return v3 + 8 * (_DWORD)&v2[-a1]; /*0x119b54*/
}
