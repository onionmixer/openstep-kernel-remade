/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bef60. */
int __cdecl sub_1BEF60(int a1, int a2)
{
  int result; // eax

  result = *(unsigned __int8 *)(a1 + 3); /*0x1bef6a*/
  if ( *(_DWORD *)(a1 + 4) == 32 && !*(_BYTE *)(a1 + 3) ) /*0x1bef76*/
  {
    result = 268509190; /*0x1bef84*/
    if ( *(_DWORD *)(a1 + 24) == 268509190 ) /*0x1bef8c*/
    {
      result = (int)EvClose(); /*0x1befa0*/
      *(_DWORD *)(a2 + 28) = result; /*0x1befa5*/
    }
    else
    {
      *(_DWORD *)(a2 + 28) = -304; /*0x1bef8e*/
    }
    if ( !*(_DWORD *)(a2 + 28) ) /*0x1befa8*/
    {
      *(_BYTE *)(a2 + 3) = 1; /*0x1befae*/
      *(_DWORD *)(a2 + 4) = 32; /*0x1befb2*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1bef78*/
  }
  return result; /*0x1befb9*/
}
