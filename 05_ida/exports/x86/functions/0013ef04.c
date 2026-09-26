/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13ef04. */
int __cdecl sub_13EF04(int a1, int *a2, int *a3)
{
  int v3; // esi
  unsigned int v4; // ebx
  int v5; // edi
  int v6; // eax
  int v7; // ebx
  int v9; // eax
  __int16 v10; // ax
  int v11; // [esp+Ch] [ebp-4h]

  v11 = 0; /*0x13ef0d*/
  if ( !a3 ) /*0x13ef18*/
    panic(aDirmakeinodeNo); /*0x13ef1f*/
  v3 = *a3; /*0x13ef2a*/
  if ( *a3 == 2 ) /*0x13ef2f*/
    v4 = dirpref(*(_DWORD **)(a1 + 80)); /*0x13ef3d*/
  else
    v4 = *(_DWORD *)(a1 + 72); /*0x13ef47*/
  v5 = *((unsigned __int16 *)a3 + 2) | vttoif_tab[v3]; /*0x13ef58*/
  v6 = ialloc(a1, v4, v5); /*0x13ef60*/
  v7 = v6; /*0x13ef65*/
  if ( !v6 ) /*0x13ef6c*/
    return *(char *)(dword_1E875C + 104); /*0x13ef73*/
  *(_BYTE *)(v6 + 68) |= 0x46u; /*0x13ef7c*/
  *(_WORD *)(v6 + 100) = v5; /*0x13ef80*/
  if ( (unsigned int)(v3 - 3) <= 1 || v3 == 9 ) /*0x13ef8f*/
  {
    v9 = *((__int16 *)a3 + 28); /*0x13ef94*/
    *(_DWORD *)(v7 + 140) = v9; /*0x13ef98*/
    *(_WORD *)(v7 + 56) = v9; /*0x13ef9e*/
  }
  *(_DWORD *)(v7 + 52) = v3; /*0x13efa2*/
  if ( v3 == 2 ) /*0x13efa8*/
    *(_WORD *)(v7 + 102) = 2; /*0x13efaa*/
  else
    *(_WORD *)(v7 + 102) = 1; /*0x13efb4*/
  if ( *(_WORD *)(*(_DWORD *)(v7 + 48) + 292) ) /*0x13efbd*/
  {
    *(_WORD *)(v7 + 228) = *(_WORD *)(a1 + 228); /*0x13efd1*/
    *(_WORD *)(v7 + 230) = *(_WORD *)(a1 + 230); /*0x13efe2*/
    *(_WORD *)(v7 + 104) = *(_WORD *)(*(_DWORD *)(v7 + 48) + 292); /*0x13eff3*/
    *(_WORD *)(v7 + 106) = nogroup; /*0x13effe*/
  }
  else
  {
    *(_WORD *)(v7 + 104) = *(_WORD *)(*(_DWORD *)(active_u + 28) + 2); /*0x13f010*/
    *(_WORD *)(v7 + 106) = *(_WORD *)(a1 + 106); /*0x13f01b*/
  }
  if ( (*(_BYTE *)(v7 + 101) & 4) != 0 && !groupmember(*(_WORD *)(v7 + 106)) ) /*0x13f02a*/
    *(_WORD *)(v7 + 100) &= ~0x400u; /*0x13f036*/
  iupdat(v7, 1); /*0x13f03f*/
  if ( v3 == 2 ) /*0x13f04a*/
    v11 = sub_13F0A4(v7, a1); /*0x13f056*/
  if ( v11 ) /*0x13f060*/
  {
    *(_WORD *)(v7 + 102) = 0; /*0x13f062*/
    *(_BYTE *)(v7 + 68) |= 0x40u; /*0x13f068*/
    iput(v7); /*0x13f06d*/
  }
  else
  {
    v10 = *(_WORD *)(v7 + 68); /*0x13f074*/
    *(_WORD *)(v7 + 68) = v10 & 0xFFFE; /*0x13f07d*/
    if ( (v10 & 0x10) != 0 ) /*0x13f083*/
    {
      LOBYTE(v10) = v10 & 0xEE; /*0x13f085*/
      *(_WORD *)(v7 + 68) = v10; /*0x13f087*/
      wakeup(v7); /*0x13f08c*/
    }
    *a2 = v7; /*0x13f094*/
  }
  return v11; /*0x13f09c*/
}
