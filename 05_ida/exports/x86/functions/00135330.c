/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x135330. */
_BYTE *__cdecl clntkudp_once(int a1, int a2)
{
  _BYTE *result; // eax

  result = *(_BYTE **)(a1 + 8); /*0x135336*/
  if ( a2 ) /*0x13533d*/
    *result |= 0x20u; /*0x13533f*/
  else
    *(_DWORD *)result &= ~0x20u; /*0x135348*/
  return result; /*0x135344*/
}
