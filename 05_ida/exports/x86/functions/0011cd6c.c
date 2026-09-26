/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11cd6c. */
int __cdecl copen(int a1, unsigned int a2, __int16 a3)
{
  int v3; // ebx
  int v5; // edi
  int v6; // [esp+Ch] [ebp-8h]
  int v7; // [esp+10h] [ebp-4h] BYREF

  v3 = falloc(); /*0x11cd7d*/
  if ( !v3 ) /*0x11cd81*/
    return *(char *)(dword_1E875C + 104); /*0x11cd88*/
  v6 = *(_DWORD *)(dword_1E875C + 96); /*0x11cd9c*/
  v5 = vn_open(a1, 0, a2, a3 & ~*(_WORD *)(active_u + 366) & 0xFFF, &v7); /*0x11cdc6*/
  if ( v5 ) /*0x11cdcd*/
  {
    *(_DWORD *)(*(_DWORD *)(active_u + 336) + 4 * v6) = 0; /*0x11cddd*/
    crfree(*(_DWORD *)(v3 + 32)); /*0x11cde8*/
    *(_WORD *)(v3 + 14) = 0; /*0x11cded*/
    free_file(v3); /*0x11cdf4*/
  }
  else
  {
    *(_DWORD *)(v3 + 8) = a2 & 0xA000004B; /*0x11ce04*/
    if ( (*(_BYTE *)(*(_DWORD *)active_u + 22) & 2) != 0 && *(_DWORD *)(v7 + 40) == 1 ) /*0x11ce1b*/
      *(_DWORD *)(v3 + 8) = a2 & 0xA000004B | 0x40001000; /*0x11ce23*/
    *(_WORD *)(v3 + 12) = 1; /*0x11ce26*/
    *(_DWORD *)(v3 + 24) = v7; /*0x11ce2f*/
    *(_DWORD *)(v3 + 20) = &vnodefops; /*0x11ce32*/
    if ( *(_DWORD *)(v7 + 40) == 8 ) /*0x11ce40*/
      *(_DWORD *)(v3 + 8) |= a2 & 4; /*0x11ce47*/
    *(_DWORD *)(*(_DWORD *)(active_u + 336) + 4 * v6) = v3; /*0x11ce58*/
  }
  return v5; /*0x11ce60*/
}
