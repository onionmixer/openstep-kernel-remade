/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13e838. */
int __cdecl sub_13E838(unsigned int a1, unsigned int a2, unsigned int a3, char *a4, int a5, unsigned int a6, int a7)
{
  int v7; // eax
  int result; // eax
  __int16 v9; // ax
  __int16 v10; // ax
  _BOOL4 v11; // [esp+Ch] [ebp-4h]

  v7 = *(_DWORD *)(a6 + 48); /*0x13e847*/
  if ( *(_DWORD *)(a3 + 48) != v7 || *(_DWORD *)(a2 + 48) != v7 ) /*0x13e855*/
    return 18; /*0x13e85c*/
  if ( *(_DWORD *)(a2 + 72) == *(_DWORD *)(a6 + 72) ) /*0x13e86d*/
    return -1; /*0x13e874*/
  result = iaccess(a3, 128); /*0x13e882*/
  if ( !result ) /*0x13e88c*/
  {
    if ( (*(_BYTE *)(a3 + 101) & 2) != 0 ) /*0x13e896*/
    {
      v9 = *(_WORD *)(*(_DWORD *)(active_u + 28) + 2); /*0x13e8a0*/
      if ( v9 ) /*0x13e8a7*/
      {
        if ( *(_WORD *)(a3 + 104) != v9 && *(_WORD *)(a6 + 104) != v9 ) /*0x13e8b3*/
          return 1; /*0x13e8ba*/
      }
    }
    v11 = (*(_WORD *)(a2 + 100) & 0xF000) == 0x4000; /*0x13e8d7*/
    if ( (*(_WORD *)(a6 + 100) & 0xF000) == 0x4000 ) /*0x13e8e6*/
    {
      if ( (*(_WORD *)(a2 + 100) & 0xF000) != 0x4000 ) /*0x13e8ec*/
        return 21; /*0x13e8f3*/
      if ( !sub_13F5E4(a6, *(_DWORD *)(a3 + 72)) || *(__int16 *)(a6 + 102) > 2 ) /*0x13e90e*/
        return 66; /*0x13e915*/
    }
    else if ( (*(_WORD *)(a2 + 100) & 0xF000) == 0x4000 ) /*0x13e920*/
    {
      return 20; /*0x13e927*/
    }
    dnlc_remove(a3 + 12, a4); /*0x13e934*/
    **(_DWORD **)(a7 + 16) = *(_DWORD *)(a2 + 72); /*0x13e945*/
    dnlc_enter(a3 + 12, a4, a2 + 12, nullptr); /*0x13e955*/
    byte_swap_dir_block_out(*(_DWORD *)(a7 + 12)); /*0x13e961*/
    bwrite(*(int **)(a7 + 12)); /*0x13e96d*/
    *(_DWORD *)(a7 + 12) = 0; /*0x13e975*/
    LOBYTE(result) = *(_BYTE *)(dword_1E875C + 104); /*0x13e984*/
    if ( (_BYTE)result ) /*0x13e989*/
    {
      return (char)result; /*0x13e98b*/
    }
    else
    {
      *(_BYTE *)(a3 + 68) |= 0x42u; /*0x13e990*/
      --*(_WORD *)(a6 + 102); /*0x13e994*/
      *(_BYTE *)(a6 + 68) |= 0x40u; /*0x13e998*/
      if ( !v11 ) /*0x13e9a0*/
        return 0; /*0x13e9a0*/
      v10 = *(_WORD *)(a6 + 102); /*0x13e9a2*/
      *(_WORD *)(a6 + 102) = v10 - 1; /*0x13e9aa*/
      if ( v10 != 1 ) /*0x13e9b2*/
        panic(aDirenterTarget); /*0x13e9b9*/
      itrunc(a6, 0); /*0x13e9c4*/
      --*(_WORD *)(a3 + 102); /*0x13e9c9*/
      *(_BYTE *)(a3 + 68) |= 0x40u; /*0x13e9cd*/
      if ( a1 == a3 ) /*0x13e9d7*/
        return 0; /*0x13e9d7*/
      result = sub_13E9F8(a2, a1, a3); /*0x13e9e2*/
      if ( !result ) /*0x13e9e9*/
        return 0; /*0x13e9eb*/
    }
  }
  return result; /*0x13e9f0*/
}
