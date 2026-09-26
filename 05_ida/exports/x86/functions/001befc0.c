/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1befc0. */
int __cdecl sub_1BEFC0(int a1, int a2)
{
  int result; // eax

  result = *(unsigned __int8 *)(a1 + 3); /*0x1befca*/
  if ( *(_DWORD *)(a1 + 4) == 48 && !*(_BYTE *)(a1 + 3) ) /*0x1befd6*/
  {
    result = 268509190; /*0x1befe4*/
    if ( *(_DWORD *)(a1 + 24) == 268509190 /*0x1bf000*/
      && (result = 268509190, *(_DWORD *)(a1 + 32) == 268509190)
      && (result = 268509186, *(_DWORD *)(a1 + 40) == 268509186) )
    {
      result = (int)EvMapEventShmem(); /*0x1bf020*/
      *(_DWORD *)(a2 + 28) = result; /*0x1bf025*/
    }
    else
    {
      *(_DWORD *)(a2 + 28) = -304; /*0x1bf002*/
    }
    if ( !*(_DWORD *)(a2 + 28) ) /*0x1bf028*/
    {
      *(_DWORD *)(a2 + 32) = 268509186; /*0x1bf034*/
      *(_BYTE *)(a2 + 3) = 1; /*0x1bf037*/
      *(_DWORD *)(a2 + 4) = 40; /*0x1bf03b*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1befd8*/
  }
  return result; /*0x1bf042*/
}
