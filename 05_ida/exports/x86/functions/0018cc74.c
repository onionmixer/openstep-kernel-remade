/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18cc74. */
unsigned __int8 __cdecl led_msg(int a1)
{
  int i; // esi
  unsigned __int8 result; // al

  for ( i = 0; i <= 3; ++i ) /*0x18cc7c*/
  {
    result = *(_BYTE *)(i + a1); /*0x18cc8b*/
    __outbyte(3247 - i, result); /*0x18cc8d*/
    _InterlockedIncrement(dword_1E7730); /*0x18cc8e*/
  }
  return result; /*0x18cc9e*/
}
