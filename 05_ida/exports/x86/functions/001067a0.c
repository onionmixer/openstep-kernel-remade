/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1067a0. */
int init_process()
{
  int v1; // ebx
  int v2; // eax
  int v3; // eax
  int v4; // eax
  __int16 v5; // ax

  if ( !suser() ) /*0x1067a4*/
    return 8; /*0x1067ad*/
  v1 = *(_DWORD *)active_u; /*0x1067b9*/
  v2 = *(_DWORD *)(*(_DWORD *)active_u + 76); /*0x1067bb*/
  if ( v2 ) /*0x1067c0*/
    *(_DWORD *)(v2 + 80) = *(_DWORD *)(v1 + 80); /*0x1067c5*/
  v3 = *(_DWORD *)(v1 + 80); /*0x1067c8*/
  if ( v3 ) /*0x1067cd*/
    *(_DWORD *)(v3 + 76) = *(_DWORD *)(v1 + 76); /*0x1067d2*/
  v4 = *(_DWORD *)(v1 + 68); /*0x1067d5*/
  if ( *(_DWORD *)(v4 + 72) == v1 ) /*0x1067db*/
    *(_DWORD *)(v4 + 72) = *(_DWORD *)(v1 + 76); /*0x1067e0*/
  *(_DWORD *)(v1 + 68) = v1; /*0x1067e3*/
  *(_DWORD *)(v1 + 76) = 0; /*0x1067e6*/
  *(_DWORD *)(v1 + 80) = 0; /*0x1067ed*/
  v5 = *(_WORD *)(v1 + 48); /*0x1067f4*/
  if ( *(_WORD *)(v1 + 46) != v5 ) /*0x1067fc*/
    enterpgrp(v1, v5, 0); /*0x106803*/
  *(_WORD *)(v1 + 50) = 0; /*0x106808*/
  return 0; /*0x106810*/
}
