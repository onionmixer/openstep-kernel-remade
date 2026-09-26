/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11a3e8. */
int __cdecl getblk(int a1, int a2, int a3)
{
  char *v3; // edi
  int v4; // ebx
  int v5; // esi
  int v6; // eax
  int v7; // esi

  if ( !a1 ) /*0x11a3f2*/
  {
    printf("vp=0x%x, blkno=0x%x, size=0x%x\n", 0, a2, a3); /*0x11a403*/
    panic(aGetblkIllegalV); /*0x11a40d*/
  }
  v3 = (char *)&bufhash + 12 * (((_BYTE)a1 + (unsigned __int8)(a2 / 8)) & 0xF); /*0x11a42b*/
  do /*0x11a4bf*/
  {
    while ( 1 ) /*0x11a437*/
    {
      while ( 1 ) /*0x11a432*/
      {
        v4 = *((_DWORD *)v3 + 1); /*0x11a432*/
        if ( (char *)v4 != v3 ) /*0x11a437*/
          break; /*0x11a437*/
LABEL_14:
        v4 = getnewbuf(); /*0x11a4db*/
        bfree(v4); /*0x11a4e3*/
        *(_DWORD *)(*(_DWORD *)(v4 + 8) + 4) = *(_DWORD *)(v4 + 4); /*0x11a4ee*/
        *(_DWORD *)(*(_DWORD *)(v4 + 4) + 8) = *(_DWORD *)(v4 + 8); /*0x11a4f7*/
        sub_11B244(v4, a1); /*0x11a4ff*/
        *(_WORD *)(v4 + 30) = *(_WORD *)(a1 + 44); /*0x11a50b*/
        *(_DWORD *)(v4 + 36) = a2; /*0x11a512*/
        *(_WORD *)(v4 + 28) = 0; /*0x11a515*/
        *(_DWORD *)(v4 + 40) = 0; /*0x11a51b*/
        *(_DWORD *)(v4 + 4) = *((_DWORD *)v3 + 1); /*0x11a525*/
        *(_DWORD *)(v4 + 8) = v3; /*0x11a528*/
        *(_DWORD *)(*((_DWORD *)v3 + 1) + 8) = v4; /*0x11a52e*/
        *((_DWORD *)v3 + 1) = v4; /*0x11a531*/
        if ( brealloc(v4, a3) ) /*0x11a539*/
          return v4; /*0x11a543*/
      }
      while ( *(_DWORD *)(v4 + 36) != a2 || *(_DWORD *)(v4 + 64) != a1 || (*(_BYTE *)(v4 + 2) & 1) != 0 ) /*0x11a458*/
      {
        v4 = *(_DWORD *)(v4 + 4); /*0x11a4d0*/
        if ( (char *)v4 == v3 ) /*0x11a4d5*/
          goto LABEL_14; /*0x11a4d5*/
      }
      v5 = splhigh(); /*0x11a45f*/
      v6 = *(_DWORD *)v4; /*0x11a461*/
      if ( (*(_DWORD *)v4 & 8) == 0 ) /*0x11a465*/
        break; /*0x11a465*/
      LOBYTE(v6) = v6 | 0x40; /*0x11a467*/
      *(_DWORD *)v4 = v6; /*0x11a469*/
      sleep(v4); /*0x11a46e*/
      splx(v5); /*0x11a474*/
    }
    splx(v5); /*0x11a481*/
    v7 = splbio(); /*0x11a48b*/
    *(_DWORD *)(*(_DWORD *)(v4 + 16) + 12) = *(_DWORD *)(v4 + 12); /*0x11a493*/
    *(_DWORD *)(*(_DWORD *)(v4 + 12) + 16) = *(_DWORD *)(v4 + 16); /*0x11a49c*/
    *(_BYTE *)v4 |= 8u; /*0x11a49f*/
    splx(v7); /*0x11a4a3*/
  }
  while ( *(_DWORD *)(v4 + 20) != a3 && !brealloc(v4, a3) ); /*0x11a4bf*/
  *(_DWORD *)v4 |= 0x8000u; /*0x11a4c5*/
  return v4; /*0x11a54e*/
}
