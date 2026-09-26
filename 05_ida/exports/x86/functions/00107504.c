/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x107504. */
__int16 __cdecl enterpgrp(int a1, int a2, int a3)
{
  _DWORD *v3; // eax
  _DWORD *v4; // ebx
  int posix_proc; // eax
  int v6; // esi
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax

  v3 = (_DWORD *)pgrphash[a2 & 0x3F]; /*0x107513*/
  if ( v3 ) /*0x10751c*/
  {
    while ( v3[3] != a2 ) /*0x107526*/
    {
      v3 = (_DWORD *)*v3; /*0x107528*/
      if ( !v3 ) /*0x10752c*/
        goto LABEL_4; /*0x10752c*/
    }
    v4 = v3; /*0x107588*/
  }
  else
  {
LABEL_4:
    v4 = nullptr; /*0x10752e*/
  }
  posix_proc = get_posix_proc(*(__int16 *)(a1 + 48)); /*0x107535*/
  v6 = posix_proc; /*0x10753a*/
  if ( v4 ) /*0x107541*/
  {
    v10 = *(_DWORD *)(*(_DWORD *)(posix_proc + 16) + 12); /*0x1075d3*/
    if ( v4[3] == v10 ) /*0x1075d9*/
      return v10; /*0x1075d9*/
  }
  else
  {
    v7 = kalloc(0x14u); /*0x107549*/
    v4 = (_DWORD *)v7; /*0x10754e*/
    if ( a3 ) /*0x107557*/
    {
      v8 = kalloc(0x10u); /*0x10755b*/
      *(_DWORD *)(v8 + 4) = a1; /*0x107560*/
      *(_DWORD *)v8 = 1; /*0x107563*/
      *(_DWORD *)(v8 + 8) = 0; /*0x107569*/
      *(_WORD *)(v8 + 12) = 0; /*0x107570*/
      *(_DWORD *)(a1 + 40) &= ~0x40000000u; /*0x107576*/
      v4[2] = v8; /*0x10757d*/
    }
    else
    {
      *(_DWORD *)(v7 + 8) = *(_DWORD *)(*(_DWORD *)(v6 + 16) + 8); /*0x107592*/
      ++**(_DWORD **)(v7 + 8); /*0x107598*/
    }
    v4[3] = a2; /*0x10759d*/
    v9 = a2 & 0x3F; /*0x1075a3*/
    *v4 = pgrphash[v9]; /*0x1075ad*/
    pgrphash[v9] = (int)v4; /*0x1075af*/
    v4[4] = 0; /*0x1075b6*/
    v4[1] = 0; /*0x1075bd*/
  }
  if ( (*(_BYTE *)(a1 + 22) & 2) != 0 ) /*0x1075df*/
  {
    fixjobc(a1, v4, 1); /*0x1075e5*/
    fixjobc(a1, *(_DWORD *)(v6 + 16), 0); /*0x1075f1*/
  }
  v11 = *(_DWORD *)(v6 + 16) + 4; /*0x1075fc*/
  if ( *(_DWORD *)(v6 + 16) == -4 ) /*0x1075ff*/
LABEL_18:
    panic(aEnterpgrpCanTF); /*0x10761e*/
  while ( *(_DWORD *)v11 != a1 ) /*0x107608*/
  {
    v11 = get_posix_proc(*(__int16 *)(*(_DWORD *)v11 + 48)) + 12; /*0x107614*/
    if ( !v11 ) /*0x10761c*/
      goto LABEL_18; /*0x10761c*/
  }
  *(_DWORD *)v11 = *(_DWORD *)(v6 + 12); /*0x1075cb*/
  if ( !*(_DWORD *)(*(_DWORD *)(v6 + 16) + 4) ) /*0x10762e*/
    pgdelete(*(_DWORD *)(v6 + 16)); /*0x107635*/
  *(_DWORD *)(v6 + 16) = v4; /*0x10763a*/
  *(_DWORD *)(v6 + 12) = v4[1]; /*0x107640*/
  v4[1] = a1; /*0x107643*/
  LOWORD(v10) = *(_WORD *)(*(_DWORD *)(v6 + 16) + 12); /*0x107649*/
  *(_WORD *)(a1 + 46) = v10; /*0x10764d*/
  return v10; /*0x107654*/
}
