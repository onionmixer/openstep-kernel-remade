/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11b020. */
int __cdecl binvalfree(int a1)
{
  int v1; // esi
  int *v2; // eax
  int v3; // ebx
  int v4; // eax
  int v5; // esi

  while ( 1 ) /*0x11b02b*/
  {
    v1 = splhigh(); /*0x11b02b*/
    v2 = &bfreelist; /*0x11b02d*/
    if ( &bfreelist >= &dword_1E882C ) /*0x11b037*/
      return splx(v1); /*0x11b14e*/
    while ( 1 ) /*0x11b040*/
    {
      v3 = v2[3]; /*0x11b040*/
      if ( (int *)v3 != v2 ) /*0x11b045*/
        break; /*0x11b045*/
LABEL_16:
      v2 += 17; /*0x11b137*/
      if ( v2 >= &dword_1E882C ) /*0x11b13f*/
        return splx(v1); /*0x11b13f*/
    }
    while ( *(_DWORD *)(v3 + 64) != a1 && a1 ) /*0x11b056*/
    {
      v3 = *(_DWORD *)(v3 + 12); /*0x11b12c*/
      if ( (int *)v3 == v2 ) /*0x11b131*/
        goto LABEL_16; /*0x11b131*/
    }
    if ( (*(_DWORD *)v3 & 0x200) != 0 ) /*0x11b061*/
    {
      *(_DWORD *)(v3 + 48) = brelvp_wakeup; /*0x11b067*/
      *(_DWORD *)v3 |= 0x200100u; /*0x11b06e*/
      v4 = splbio(); /*0x11b074*/
      *(_DWORD *)(*(_DWORD *)(v3 + 16) + 12) = *(_DWORD *)(v3 + 12); /*0x11b081*/
      *(_DWORD *)(*(_DWORD *)(v3 + 12) + 16) = *(_DWORD *)(v3 + 16); /*0x11b08a*/
      *(_BYTE *)v3 |= 8u; /*0x11b08d*/
      splx(v4); /*0x11b091*/
      splx(v1); /*0x11b097*/
      v5 = *(_DWORD *)v3; /*0x11b09f*/
      *(_DWORD *)v3 &= 0xFFFFFDF8; /*0x11b0a9*/
      if ( (v5 & 0x200) == 0 ) /*0x11b0b3*/
        ++*(_DWORD *)(active_u + 416); /*0x11b0ba*/
      if ( *(_DWORD *)(v3 + 20) > *(_DWORD *)(v3 + 24) ) /*0x11b0c6*/
        panic(aBwrite); /*0x11b0cd*/
      (*(void (__cdecl **)(int))(*(_DWORD *)(*(_DWORD *)(v3 + 64) + 28) + 84))(v3); /*0x11b0df*/
      if ( (v5 & 0x100) != 0 ) /*0x11b0ea*/
      {
        if ( (v5 & 0x200) != 0 ) /*0x11b102*/
          *(_BYTE *)v3 |= 0x80u; /*0x11b108*/
      }
      else
      {
        biowait((_BYTE *)v3); /*0x11b0ed*/
        brelse(v3); /*0x11b0f3*/
      }
    }
    else
    {
      *(_DWORD *)v3 |= 0x10000u; /*0x11b115*/
      sub_11B26C(v3); /*0x11b118*/
      splx(v1); /*0x11b11e*/
    }
  }
}
