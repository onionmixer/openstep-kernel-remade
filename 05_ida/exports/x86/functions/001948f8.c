/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1948f8. */
int __cdecl cnopen(__int16 a1, int a2)
{
  int v2; // edi
  int v3; // esi
  _DWORD *posix_proc; // eax
  _DWORD *v5; // ebx
  int v6; // eax
  __int16 v7; // ax
  unsigned __int16 v9; // [esp+Ch] [ebp-8h]

  v2 = ttynty(cons_tp); /*0x194915*/
  v9 = *(_WORD *)(cons_tp + 56); /*0x194920*/
  v3 = *(_DWORD *)active_u; /*0x194929*/
  posix_proc = get_posix_proc(*(__int16 *)(*(_DWORD *)active_u + 48)); /*0x194930*/
  v5 = posix_proc; /*0x194935*/
  if ( (*(_BYTE *)(v3 + 22) & 2) != 0 ) /*0x19493e*/
  {
    v6 = *(_DWORD *)(posix_proc[4] + 8); /*0x194947*/
    if ( *(_DWORD *)(v6 + 4) == v3 && !*(_DWORD *)(v6 + 8) && !*(_DWORD *)(v2 + 8) && (v5[6] & 2) == 0 ) /*0x19496b*/
    {
      *(_DWORD *)(active_u + 360) = cons_tp; /*0x19497c*/
      *(_WORD *)(active_u + 364) = a1; /*0x19498b*/
      *(_DWORD *)(v2 + 8) = *(_DWORD *)(v5[4] + 8); /*0x194998*/
      *(_DWORD *)(*(_DWORD *)(v5[4] + 8) + 8) = cons_tp; /*0x1949a7*/
      *(_DWORD *)(v2 + 12) = v5[4]; /*0x1949ad*/
      *(_WORD *)(cons_tp + 68) = *(_WORD *)(v5[4] + 12); /*0x1949bd*/
      *(_DWORD *)(v3 + 40) |= 0x40000000u; /*0x1949c1*/
    }
  }
  else if ( (*(_BYTE *)(v3 + 43) & 0x40) == 0 ) /*0x1949d4*/
  {
    *(_DWORD *)(active_u + 360) = cons_tp; /*0x1949e5*/
    *(_WORD *)(active_u + 364) = a1; /*0x1949f4*/
    *(_DWORD *)(v2 + 8) = *(_DWORD *)(posix_proc[4] + 8); /*0x194a01*/
    *(_DWORD *)(*(_DWORD *)(posix_proc[4] + 8) + 8) = cons_tp; /*0x194a10*/
    v7 = *(_WORD *)(cons_tp + 68); /*0x194a18*/
    if ( v7 ) /*0x194a1f*/
    {
      if ( *(_WORD *)(v3 + 46) != v7 ) /*0x194a4c*/
        enterpgrp(v3, v7, 0); /*0x194a53*/
    }
    else
    {
      enterpgrp(v3, *(__int16 *)(v3 + 48), 0); /*0x194a29*/
      *(_DWORD *)(v2 + 12) = v5[4]; /*0x194a31*/
      *(_WORD *)(cons_tp + 68) = *(_WORD *)(v5[4] + 12); /*0x194a41*/
    }
  }
  return (*(&cdevsw + 11 * HIBYTE(v9)))(v9, a2); /*0x194a7f*/
}
