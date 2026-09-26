/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11a394. */
int __cdecl incore(int a1, int a2)
{
  char *v2; // edx
  int v3; // eax

  v2 = (char *)&bufhash + 12 * (((_BYTE)a1 + (unsigned __int8)(a2 / 8)) & 0xF); /*0x11a3b2*/
  v3 = *((_DWORD *)v2 + 1); /*0x11a3b9*/
  if ( (char *)v3 == v2 ) /*0x11a3be*/
    return 0; /*0x11a3df*/
  while ( *(_DWORD *)(v3 + 36) != a2 || *(_DWORD *)(v3 + 64) != a1 || (*(_BYTE *)(v3 + 2) & 1) != 0 ) /*0x11a3ce*/
  {
    v3 = *(_DWORD *)(v3 + 4); /*0x11a3d8*/
    if ( (char *)v3 == v2 ) /*0x11a3dd*/
      return 0; /*0x11a3dd*/
  }
  return 1; /*0x11a3e1*/
}
