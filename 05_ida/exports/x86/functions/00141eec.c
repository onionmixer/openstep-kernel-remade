/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x141eec. */
__int16 __cdecl ilock(unsigned int a1)
{
  __int16 result; // ax

  while ( 1 ) /*0x141f09*/
  {
    result = *(_WORD *)(a1 + 68); /*0x141f09*/
    if ( (result & 1) == 0 ) /*0x141f0f*/
      break; /*0x141f0f*/
    LOBYTE(result) = result | 0x10; /*0x141ef8*/
    *(_WORD *)(a1 + 68) = result; /*0x141efa*/
    sleep(a1); /*0x141f01*/
  }
  *(_BYTE *)(a1 + 68) |= 1u; /*0x141f11*/
  return result; /*0x141f15*/
}
