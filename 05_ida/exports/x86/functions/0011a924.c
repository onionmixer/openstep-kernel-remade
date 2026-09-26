/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11a924. */
unsigned int getnewbuf()
{
  int v0; // eax
  int v1; // esi
  int *v2; // ebx
  unsigned int v3; // ebx
  int v4; // eax
  int v5; // eax
  __int16 v6; // si
  int v7; // eax
  int v8; // edi

  while ( 1 ) /*0x11a956*/
  {
    while ( 1 ) /*0x11a92a*/
    {
      v0 = splhigh(); /*0x11a92a*/
      v1 = v0; /*0x11a92f*/
      v2 = (int *)&unk_1E87E8; /*0x11a931*/
      if ( &unk_1E87E8 > (_UNKNOWN *)&bfreelist ) /*0x11a93c*/
      {
        do /*0x11a94e*/
        {
          if ( (int *)v2[3] != v2 ) /*0x11a943*/
            break; /*0x11a943*/
          v2 -= 17; /*0x11a945*/
        }
        while ( v2 > &bfreelist ); /*0x11a94e*/
      }
      if ( v2 != &bfreelist ) /*0x11a956*/
        break; /*0x11a956*/
      LOBYTE(bfreelist) = bfreelist | 0x40; /*0x11a958*/
      sleep((unsigned int)&bfreelist); /*0x11a966*/
      splx(v1); /*0x11a96c*/
    }
    splx(v0); /*0x11a979*/
    v3 = v2[3]; /*0x11a97e*/
    v4 = splbio(); /*0x11a981*/
    *(_DWORD *)(*(_DWORD *)(v3 + 16) + 12) = *(_DWORD *)(v3 + 12); /*0x11a98e*/
    *(_DWORD *)(*(_DWORD *)(v3 + 12) + 16) = *(_DWORD *)(v3 + 16); /*0x11a997*/
    *(_BYTE *)v3 |= 8u; /*0x11a99a*/
    splx(v4); /*0x11a99e*/
    v5 = *(_DWORD *)v3; /*0x11a9a3*/
    if ( (*(_DWORD *)v3 & 0x200) == 0 ) /*0x11a9ab*/
      break; /*0x11a9ab*/
    v6 = v5 | 0x100; /*0x11a9af*/
    v7 = v5 | 0x100; /*0x11a9b5*/
    *(_DWORD *)v3 = v7 & 0xFFFFFDF8; /*0x11a9bf*/
    v8 = v7 & 0x200; /*0x11a9c3*/
    if ( (v7 & 0x200) == 0 ) /*0x11a9c9*/
      ++*(_DWORD *)(active_u + 416); /*0x11a9d0*/
    if ( *(_DWORD *)(v3 + 20) > *(_DWORD *)(v3 + 24) ) /*0x11a9dc*/
      panic(aBwrite); /*0x11a9e3*/
    (*(void (__cdecl **)(unsigned int))(*(_DWORD *)(*(_DWORD *)(v3 + 64) + 28) + 84))(v3); /*0x11a9f5*/
    if ( (v6 & 0x100) != 0 ) /*0x11aa00*/
    {
      if ( v8 ) /*0x11aa1a*/
        *(_BYTE *)v3 |= 0x80u; /*0x11aa20*/
    }
    else
    {
      biowait(v3); /*0x11aa03*/
      brelse(v3); /*0x11aa09*/
    }
  }
  *(_DWORD *)v3 = 8; /*0x11aa28*/
  return v3; /*0x11aa33*/
}
