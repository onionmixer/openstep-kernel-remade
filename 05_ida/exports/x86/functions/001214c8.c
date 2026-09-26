/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1214c8. */
int __cdecl raw_bind(int a1, int a2)
{
  _DWORD *v2; // esi
  int v4; // ebx

  v2 = (_DWORD *)(*(_DWORD *)(a2 + 4) + a2); /*0x1214d5*/
  if ( !ifnet ) /*0x1214df*/
    return 49; /*0x1214df*/
  if ( *(unsigned __int16 *)v2 > 3u || *(unsigned __int16 *)v2 < 2u ) /*0x1214ec*/
    return 47; /*0x121508*/
  if ( v2[1] && !ifa_ifwithaddr((_WORD *)(*(_DWORD *)(a2 + 4) + a2)) ) /*0x1214f5*/
    return 49; /*0x121506*/
  v4 = *(_DWORD *)(a1 + 8); /*0x121510*/
  bcopy(v2, (void *)(v4 + 28), 0x10u); /*0x12151a*/
  *(_BYTE *)(v4 + 76) |= 1u; /*0x12151f*/
  return 0; /*0x121528*/
}
