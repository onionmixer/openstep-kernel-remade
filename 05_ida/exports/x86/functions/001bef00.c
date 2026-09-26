/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bef00. */
int __cdecl sub_1BEF00(int a1, int a2)
{
  int result; // eax

  result = *(unsigned __int8 *)(a1 + 3); /*0x1bef0a*/
  if ( *(_DWORD *)(a1 + 4) == 32 && !*(_BYTE *)(a1 + 3) ) /*0x1bef16*/
  {
    result = 268509190; /*0x1bef24*/
    if ( *(_DWORD *)(a1 + 24) == 268509190 ) /*0x1bef2c*/
    {
      result = (int)EvOpen(); /*0x1bef40*/
      *(_DWORD *)(a2 + 28) = result; /*0x1bef45*/
    }
    else
    {
      *(_DWORD *)(a2 + 28) = -304; /*0x1bef2e*/
    }
    if ( !*(_DWORD *)(a2 + 28) ) /*0x1bef48*/
    {
      *(_BYTE *)(a2 + 3) = 1; /*0x1bef4e*/
      *(_DWORD *)(a2 + 4) = 32; /*0x1bef52*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1bef18*/
  }
  return result; /*0x1bef59*/
}
