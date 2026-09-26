/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10dee4. */
int __cdecl ttrstrt(int a1)
{
  int v1; // esi
  int v3; // [esp+0h] [ebp-8h]

  v1 = spltty(); /*0x10def1*/
  if ( !a1 ) /*0x10def5*/
    panic(aTtrstrt); /*0x10defc*/
  *(_DWORD *)(a1 + 64) &= ~1u; /*0x10df04*/
  ((void (__stdcall *)(int, int))*(&off_1DB008 + 12 * *(char *)(a1 + 71)))(a1, v3); /*0x10df19*/
  return splx(v1); /*0x10df24*/
}
