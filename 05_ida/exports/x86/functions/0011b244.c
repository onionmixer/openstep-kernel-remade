/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11b244. */
__int16 __cdecl sub_11B244(int a1, int a2)
{
  __int16 result; // ax

  if ( *(_DWORD *)(a1 + 64) ) /*0x11b24f*/
    result = sub_11B26C(a1); /*0x11b256*/
  ++*(_WORD *)(a2 + 6); /*0x11b25b*/
  *(_DWORD *)(a1 + 64) = a2; /*0x11b25f*/
  return result; /*0x11b265*/
}
