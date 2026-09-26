/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bf2b8. */
int __cdecl sub_1BF2B8(int a1, int a2)
{
  int v2; // esi
  int result; // eax

  v2 = *(_DWORD *)(a1 + 4); /*0x1bf2c4*/
  result = v2 - 104; /*0x1bf2cb*/
  if ( (unsigned int)(v2 - 104) <= 0x100 && *(_BYTE *)(a1 + 3) == 1 ) /*0x1bf2d8*/
  {
    result = 268509186; /*0x1bf2e4*/
    if ( *(_DWORD *)(a1 + 24) == 268509186 /*0x1bf31a*/
      && (result = 272631816, *(_DWORD *)(a1 + 32) == 272631816)
      && (result = *(_DWORD *)(a1 + 100) & 0x3000FFFF, result == 268443650)
      && (result = 4 * (*(_WORD *)(a1 + 102) & 0xFFF) + 104, v2 == result) )
    {
      result = EvSetParameterInt( /*0x1bf339*/
                 *(id *)(a1 + 12),
                 *(_DWORD *)(a1 + 28),
                 (char *)(a1 + 36),
                 a1 + 104,
                 *(_WORD *)(a1 + 102) & 0xFFF);
      *(_DWORD *)(a2 + 28) = result; /*0x1bf33e*/
    }
    else
    {
      *(_DWORD *)(a2 + 28) = -304; /*0x1bf31c*/
    }
    if ( !*(_DWORD *)(a2 + 28) ) /*0x1bf341*/
    {
      *(_BYTE *)(a2 + 3) = 1; /*0x1bf347*/
      *(_DWORD *)(a2 + 4) = 32; /*0x1bf34b*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1bf2da*/
  }
  return result; /*0x1bf355*/
}
