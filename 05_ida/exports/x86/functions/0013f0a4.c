/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13f0a4. */
int __cdecl sub_13F0A4(int a1, int a2)
{
  int v2; // ebx
  int v3; // esi
  char v4; // dl
  int result; // eax
  int *v6; // ebx
  _DWORD *v7; // edx

  v2 = *(_DWORD *)(a1 + 80); /*0x13f0ad*/
  v3 = bmap(a1, 0, 0, 1024, nullptr); /*0x13f0c1*/
  if ( v3 <= 0 || *(_BYTE *)(dword_1E875C + 104) ) /*0x13f0cf*/
  {
    v4 = *(_BYTE *)(dword_1E875C + 104); /*0x13f0da*/
    result = 28; /*0x13f0dd*/
    if ( v4 ) /*0x13f0e4*/
      return v4; /*0x13f0ea*/
  }
  else
  {
    if ( *(int *)(v2 + 52) <= 1023 ) /*0x13f0fb*/
      panic(aDirblksizFsize_0); /*0x13f102*/
    *(_DWORD *)(a1 + 108) = 1024; /*0x13f10d*/
    *(_BYTE *)(a1 + 68) |= 0x42u; /*0x13f114*/
    ++*(_WORD *)(a2 + 102); /*0x13f11b*/
    *(_BYTE *)(a2 + 68) |= 0x40u; /*0x13f11f*/
    iupdat(a2, 1); /*0x13f126*/
    v6 = bread(*(_DWORD *)(a1 + 64), v3 << *(_DWORD *)(v2 + 100), *(_DWORD *)(v2 + 52)); /*0x13f145*/
    LOBYTE(result) = *(_BYTE *)(dword_1E875C + 104); /*0x13f14f*/
    if ( (_BYTE)result ) /*0x13f154*/
    {
      return (char)result; /*0x13f194*/
    }
    else
    {
      v7 = (_DWORD *)v6[8]; /*0x13f156*/
      qmemcpy(v7, &mastertemplate, 0x18u); /*0x13f168*/
      *v7 = *(_DWORD *)(a1 + 72); /*0x13f170*/
      v7[3] = *(_DWORD *)(a2 + 72); /*0x13f178*/
      byte_swap_dir_block_out(v6); /*0x13f17c*/
      bwrite(v6); /*0x13f182*/
      return *(char *)(dword_1E875C + 104); /*0x13f18c*/
    }
  }
  return result; /*0x13f19a*/
}
