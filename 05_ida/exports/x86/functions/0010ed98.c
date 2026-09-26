/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10ed98. */
int __cdecl ttyopen(__int16 a1, FILE *a2)
{
  int v2; // esi
  _DWORD *posix_proc; // eax
  _DWORD *v4; // ebx
  int v5; // eax
  __int16 base; // ax
  int v7; // esi
  int v8; // eax
  int v9; // ebx
  int v11; // [esp+Ch] [ebp-8h]

  v11 = ttynty(a2); /*0x10edb2*/
  v2 = *(_DWORD *)active_u; /*0x10edba*/
  posix_proc = get_posix_proc(*(__int16 *)(*(_DWORD *)active_u + 48)); /*0x10edc1*/
  v4 = posix_proc; /*0x10edc6*/
  if ( (*(_BYTE *)(v2 + 22) & 2) == 0 ) /*0x10edcf*/
  {
    if ( (*(_BYTE *)(v2 + 43) & 0x40) != 0 ) /*0x10ee48*/
      goto LABEL_13; /*0x10ee48*/
    *(_DWORD *)(active_u + 360) = a2; /*0x10ee4f*/
    *(_WORD *)(active_u + 364) = a1; /*0x10ee5e*/
    *(_DWORD *)(v11 + 8) = *(_DWORD *)(posix_proc[4] + 8); /*0x10ee6e*/
    *(_DWORD *)(*(_DWORD *)(posix_proc[4] + 8) + 8) = a2; /*0x10ee77*/
    base = (__int16)a2->_lb._base; /*0x10ee7a*/
    if ( base ) /*0x10ee81*/
    {
      if ( *(_WORD *)(v2 + 46) != base ) /*0x10eeac*/
        enterpgrp(v2, base, 0); /*0x10eeb3*/
    }
    else
    {
      enterpgrp(v2, *(__int16 *)(v2 + 48), 1); /*0x10ee8b*/
      *(_DWORD *)(v11 + 12) = v4[4]; /*0x10ee96*/
      LOWORD(a2->_lb._base) = *(_WORD *)(v4[4] + 12); /*0x10eea0*/
    }
    goto LABEL_12; /*0x10eea4*/
  }
  v5 = *(_DWORD *)(posix_proc[4] + 8); /*0x10edd4*/
  if ( *(_DWORD *)(v5 + 4) == v2 && !*(_DWORD *)(v5 + 8) && !*(_DWORD *)(v11 + 8) && (v4[6] & 2) == 0 ) /*0x10edfb*/
  {
    *(_DWORD *)(active_u + 360) = a2; /*0x10ee06*/
    *(_WORD *)(active_u + 364) = a1; /*0x10ee15*/
    *(_DWORD *)(v11 + 8) = *(_DWORD *)(v4[4] + 8); /*0x10ee22*/
    *(_DWORD *)(*(_DWORD *)(v4[4] + 8) + 8) = a2; /*0x10ee2b*/
    *(_DWORD *)(v11 + 12) = v4[4]; /*0x10ee31*/
    LOWORD(a2->_lb._base) = *(_WORD *)(v4[4] + 12); /*0x10ee3b*/
LABEL_12:
    *(_DWORD *)(v2 + 40) |= 0x40000000u; /*0x10eebb*/
  }
LABEL_13:
  LOWORD(a2->_extra) = a1; /*0x10eec2*/
  v7 = spltty(); /*0x10eecf*/
  v8 = *(_DWORD *)a2->_ubuf; /*0x10eed1*/
  v9 = v8; /*0x10eed4*/
  LOBYTE(v9) = v8 & 0xFD; /*0x10eed6*/
  *(_DWORD *)a2->_ubuf = v9; /*0x10eed9*/
  if ( (v8 & 4) != 0 ) /*0x10eede*/
  {
    splx(v7); /*0x10ef2d*/
  }
  else
  {
    LOBYTE(v9) = v8 & 0xF9 | 4; /*0x10eee0*/
    *(_DWORD *)a2->_ubuf = v9; /*0x10eee3*/
    splx(v7); /*0x10eee7*/
    *(_DWORD *)(v11 + 16) = 472193564; /*0x10eeef*/
    *(_BYTE *)(v11 + 20) = 92; /*0x10eef6*/
    *(_BYTE *)(v11 + 21) = 1; /*0x10eefa*/
    *(_BYTE *)(v11 + 22) = 0; /*0x10eefe*/
    bzero(&a2[1]._r, 8u); /*0x10ef08*/
    if ( HIBYTE(a2->_lb._base) != 2 ) /*0x10ef14*/
    {
      ttywait((int)a2); /*0x10ef17*/
      ttyflush(a2, 1); /*0x10ef1f*/
    }
  }
  ttysetspec((_DWORD *)v11); /*0x10ef39*/
  return 0; /*0x10ef43*/
}
