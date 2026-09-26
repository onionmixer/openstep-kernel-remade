/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10b374. */
int __cdecl itimerdecr(_DWORD *a1, int a2)
{
  int v2; // edx
  int v3; // ebx
  int v4; // edx
  int v6; // ecx
  int v7; // edx

  v2 = a1[3]; /*0x10b37e*/
  if ( v2 < a2 ) /*0x10b383*/
  {
    if ( !a1[2] ) /*0x10b385*/
    {
      v3 = a2 - v2; /*0x10b38b*/
      goto LABEL_8; /*0x10b38d*/
    }
    a1[3] = v2 + 1000000; /*0x10b396*/
    --a1[2]; /*0x10b399*/
  }
  v4 = a1[3] - a2; /*0x10b39f*/
  a1[3] = v4; /*0x10b3a1*/
  v3 = 0; /*0x10b3a4*/
  if ( a1[2] || v4 ) /*0x10b3ae*/
    return 1; /*0x10b3b5*/
LABEL_8:
  if ( *a1 || a1[1] ) /*0x10b3bd*/
  {
    v6 = a1[1]; /*0x10b3c5*/
    a1[2] = *a1; /*0x10b3c8*/
    a1[3] = v6; /*0x10b3cb*/
    v7 = a1[3] - v3; /*0x10b3d1*/
    a1[3] = v7; /*0x10b3d3*/
    if ( v7 < 0 ) /*0x10b3d6*/
    {
      a1[3] = v7 + 1000000; /*0x10b3de*/
      --a1[2]; /*0x10b3e1*/
    }
  }
  else
  {
    a1[3] = 0; /*0x10b3e8*/
  }
  return 0; /*0x10b3f1*/
}
