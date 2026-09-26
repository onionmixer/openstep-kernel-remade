/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11adc8. */
int __cdecl bflush(int a1, __int16 a2, unsigned __int16 a3)
{
  int v3; // esi
  int *v4; // edx
  int v5; // ebx
  int v6; // eax
  int v7; // eax
  int v8; // esi

  while ( 1 ) /*0x11ade6*/
  {
    v3 = splhigh(); /*0x11ade6*/
    v4 = &bfreelist; /*0x11ade8*/
    if ( &bfreelist >= &dword_1E882C ) /*0x11adf3*/
      return splx(v3); /*0x11af03*/
    while ( 1 ) /*0x11adfc*/
    {
      v5 = v4[3]; /*0x11adfc*/
      if ( (int *)v5 != v4 ) /*0x11ae01*/
        break; /*0x11ae01*/
LABEL_17:
      v4 += 17; /*0x11aeeb*/
      if ( v4 >= &dword_1E882C ) /*0x11aef4*/
        return splx(v3); /*0x11aef4*/
    }
    while ( 1 ) /*0x11ae0d*/
    {
      if ( a2 == -1 || a2 == (*(_WORD *)(v5 + 30) & a3) ) /*0x11ae1b*/
      {
        v6 = *(_DWORD *)v5; /*0x11ae21*/
        if ( (*(_DWORD *)v5 & 0x200) != 0 && (*(_DWORD *)(v5 + 64) == a1 || !a1) ) /*0x11ae36*/
          break; /*0x11ae36*/
      }
      v5 = *(_DWORD *)(v5 + 12); /*0x11aee0*/
      if ( (int *)v5 == v4 ) /*0x11aee5*/
        goto LABEL_17; /*0x11aee5*/
    }
    BYTE1(v6) |= 1u; /*0x11ae3c*/
    *(_DWORD *)v5 = v6; /*0x11ae3f*/
    v7 = splbio(); /*0x11ae41*/
    *(_DWORD *)(*(_DWORD *)(v5 + 16) + 12) = *(_DWORD *)(v5 + 12); /*0x11ae4e*/
    *(_DWORD *)(*(_DWORD *)(v5 + 12) + 16) = *(_DWORD *)(v5 + 16); /*0x11ae57*/
    *(_BYTE *)v5 |= 8u; /*0x11ae5a*/
    splx(v7); /*0x11ae5e*/
    splx(v3); /*0x11ae64*/
    v8 = *(_DWORD *)v5; /*0x11ae6c*/
    *(_DWORD *)v5 &= 0xFFFFFDF8; /*0x11ae76*/
    if ( (v8 & 0x200) == 0 ) /*0x11ae80*/
      ++*(_DWORD *)(active_u + 416); /*0x11ae87*/
    if ( *(_DWORD *)(v5 + 20) > *(_DWORD *)(v5 + 24) ) /*0x11ae93*/
      panic(aBwrite); /*0x11ae9a*/
    (*(void (__cdecl **)(int))(*(_DWORD *)(*(_DWORD *)(v5 + 64) + 28) + 84))(v5); /*0x11aeac*/
    if ( (v8 & 0x100) != 0 ) /*0x11aeb7*/
    {
      if ( (v8 & 0x200) != 0 ) /*0x11aed2*/
        *(_BYTE *)v5 |= 0x80u; /*0x11aed8*/
    }
    else
    {
      biowait((_BYTE *)v5); /*0x11aeba*/
      brelse(v5); /*0x11aec0*/
    }
  }
}
