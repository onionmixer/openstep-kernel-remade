/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x141f44. */
int __cdecl iaccess(int a1, int a2)
{
  int v2; // ebx
  __int16 v3; // ax
  _WORD *v5; // ecx
  __int16 v6; // ax
  _WORD *v7; // edx
  unsigned int v8; // ecx

  v2 = a2; /*0x141f4d*/
  if ( (a2 & 0x80u) == 0 ) /*0x141f52*/
    goto LABEL_10; /*0x141f52*/
  if ( *(_BYTE *)(*(_DWORD *)(a1 + 80) + 210) ) /*0x141f5a*/
  {
    v3 = *(_WORD *)(a1 + 100) & 0xF000; /*0x141f67*/
    if ( v3 != 0x2000 && v3 != 24576 && v3 != 4096 ) /*0x141f7b*/
      return 30; /*0x141f82*/
  }
  if ( (*(_BYTE *)(a1 + 16) & 2) != 0 ) /*0x141f88*/
  {
    vnode_uncache(a1 + 12); /*0x141f8e*/
    if ( (*(_BYTE *)(a1 + 16) & 2) != 0 ) /*0x141f97*/
      return 26; /*0x141f99*/
  }
LABEL_10:
  v5 = *(_WORD **)(active_u + 28); /*0x141fa5*/
  v6 = v5[1]; /*0x141fa8*/
  if ( !v6 ) /*0x141faf*/
    return 0; /*0x141faf*/
  if ( *(_WORD *)(a1 + 104) != v6 ) /*0x141fb5*/
  {
    v2 = a2 >> 3; /*0x141fb7*/
    if ( v5[2] != *(_WORD *)(a1 + 106) ) /*0x141fc2*/
    {
      v7 = v5 + 5; /*0x141fc4*/
      if ( v5 + 5 < v5 + 21 ) /*0x141fcc*/
      {
        v8 = (unsigned int)(v5 + 21); /*0x141fce*/
        do /*0x141fe4*/
        {
          if ( *v7 == 0xFFFF ) /*0x141fd7*/
            break; /*0x141fd7*/
          if ( *(_WORD *)(a1 + 106) == *v7 ) /*0x141fdd*/
            goto LABEL_19; /*0x141fdd*/
          ++v7; /*0x141fdf*/
        }
        while ( (unsigned int)v7 < v8 ); /*0x141fe4*/
      }
      v2 = a2 >> 6; /*0x141fe6*/
    }
  }
LABEL_19:
  if ( (unsigned __int16)(v2 & *(_WORD *)(a1 + 100)) == v2 ) /*0x141ff1*/
    return 0; /*0x141ffc*/
  else
    return 13; /*0x141ff3*/
}
