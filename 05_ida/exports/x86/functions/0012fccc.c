/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12fccc. */
__int16 __cdecl runlock(int a1)
{
  __int16 v1; // dx
  __int16 result; // ax

  v1 = *(_WORD *)(a1 + 108) - 1; /*0x12fcd9*/
  *(_WORD *)(a1 + 108) = v1; /*0x12fcdb*/
  result = v1; /*0x12fcdf*/
  if ( v1 < 0 ) /*0x12fce1*/
    panic(aRunlock); /*0x12fce8*/
  if ( !*(_WORD *)(a1 + 108) ) /*0x12fcf0*/
  {
    result = *(_WORD *)(a1 + 96); /*0x12fcf7*/
    *(_WORD *)(a1 + 96) = result & 0xFFDE; /*0x12fd00*/
    if ( (result & 2) != 0 ) /*0x12fd06*/
    {
      LOBYTE(result) = result & 0xDC; /*0x12fd08*/
      *(_WORD *)(a1 + 96) = result; /*0x12fd0a*/
      return wakeup(a1); /*0x12fd0f*/
    }
  }
  return result; /*0x12fd14*/
}
