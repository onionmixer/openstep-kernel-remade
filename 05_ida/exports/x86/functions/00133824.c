/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x133824. */
int __cdecl sub_133824(int a1)
{
  int v1; // edi
  int result; // eax
  unsigned int v3; // esi
  unsigned int i; // ebx

  v1 = *(_DWORD *)(a1 + 48); /*0x13382d*/
  bflush(a1, -1, 0xFFFFu); /*0x133835*/
  result = *(_DWORD *)(*(_DWORD *)(a1 + 36) + 296); /*0x133840*/
  v3 = *(_DWORD *)(result + 36); /*0x133846*/
  for ( i = 0; *(_DWORD *)(v1 + 152) > i; i += v3 ) /*0x13384e*/
    result = blkflush(a1, i >> 10, v3); /*0x133863*/
  *(_BYTE *)(v1 + 96) &= ~0x10u; /*0x133875*/
  return result; /*0x13387c*/
}
