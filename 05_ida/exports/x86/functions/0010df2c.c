/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10df2c. */
int __cdecl ttstart(int a1)
{
  int v1; // esi
  void (__cdecl *v2)(int); // eax

  v1 = spltty(); /*0x10df39*/
  if ( (*(_DWORD *)(a1 + 64) & 0x4000121) == 0 ) /*0x10df42*/
  {
    v2 = *(void (__cdecl **)(int))(a1 + 36); /*0x10df44*/
    if ( v2 ) /*0x10df49*/
      v2(a1); /*0x10df4c*/
  }
  return splx(v1); /*0x10df5a*/
}
