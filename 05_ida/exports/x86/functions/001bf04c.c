/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bf04c. */
int __cdecl sub_1BF04C(int a1, int a2)
{
  int result; // eax

  result = *(unsigned __int8 *)(a1 + 3); /*0x1bf056*/
  if ( *(_DWORD *)(a1 + 4) == 168 && !*(_BYTE *)(a1 + 3) ) /*0x1bf065*/
  {
    result = 268509190; /*0x1bf070*/
    if ( *(_DWORD *)(a1 + 24) == 268509190 /*0x1bf08c*/
      && (result = 272631816, *(_DWORD *)(a1 + 32) == 272631816)
      && (result = 272631816, *(_DWORD *)(a1 + 100) == 272631816) )
    {
      result = (int)EvFrameBufferDevicePort(); /*0x1bf0ac*/
      *(_DWORD *)(a2 + 28) = result; /*0x1bf0b1*/
    }
    else
    {
      *(_DWORD *)(a2 + 28) = -304; /*0x1bf08e*/
    }
    if ( !*(_DWORD *)(a2 + 28) ) /*0x1bf0b4*/
    {
      *(_DWORD *)(a2 + 32) = 268509190; /*0x1bf0c0*/
      *(_BYTE *)(a2 + 3) = 0; /*0x1bf0c3*/
      *(_DWORD *)(a2 + 4) = 40; /*0x1bf0c7*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1bf067*/
  }
  return result; /*0x1bf0ce*/
}
