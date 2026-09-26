/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x141f1c. */
__int16 __cdecl iunlock(int a1)
{
  __int16 result; // ax

  result = *(_WORD *)(a1 + 68); /*0x141f22*/
  *(_WORD *)(a1 + 68) = result & 0xFFFE; /*0x141f2b*/
  if ( (result & 0x10) != 0 ) /*0x141f31*/
  {
    LOBYTE(result) = result & 0xEE; /*0x141f33*/
    *(_WORD *)(a1 + 68) = result; /*0x141f35*/
    return wakeup(a1); /*0x141f3a*/
  }
  return result; /*0x141f41*/
}
