/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11b26c. */
__int16 __cdecl sub_11B26C(int a1)
{
  int v1; // eax

  v1 = *(_DWORD *)(a1 + 64); /*0x11b272*/
  if ( v1 ) /*0x11b277*/
  {
    *(_DWORD *)(a1 + 64) = 0; /*0x11b279*/
    LOWORD(v1) = vn_rele(v1); /*0x11b281*/
  }
  return v1; /*0x11b288*/
}
