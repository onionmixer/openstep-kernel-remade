/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10ddd0. */
int __cdecl ttywait(int a1)
{
  int v1; // esi

  v1 = spltty(); /*0x10dddd*/
  while ( (*(_DWORD *)(a1 + 24) || (*(_DWORD *)(a1 + 64) & 0x2000020) != 0) /*0x10ddf8*/
       && ((*(_BYTE *)(a1 + 64) & 0x10) != 0 || *(__int16 *)(ttynty(a1) + 16) < 0) )
  {
    (*(void (__cdecl **)(int))(a1 + 36))(a1); /*0x10ddfe*/
    *(_BYTE *)(a1 + 64) |= 0x40u; /*0x10de00*/
    sleep(a1 + 24); /*0x10de0a*/
  }
  return splx(v1); /*0x10de2a*/
}
