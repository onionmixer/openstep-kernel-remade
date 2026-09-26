/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16df98. */
int __cdecl sub_16DF98(int a1, int a2)
{
  int result; // eax

  result = *(unsigned __int8 *)(a1 + 3); /*0x16dfa2*/
  if ( *(_DWORD *)(a1 + 4) == 64 && !*(_BYTE *)(a1 + 3) ) /*0x16dfae*/
  {
    result = 268509190; /*0x16dfbc*/
    if ( *(_DWORD *)(a1 + 24) == 268509190 /*0x16dfec*/
      && (result = 268509190, *(_DWORD *)(a1 + 32) == 268509190)
      && (result = 268509186, *(_DWORD *)(a1 + 40) == 268509186)
      && (result = 268509186, *(_DWORD *)(a1 + 48) == 268509186)
      && (result = 268509186, *(_DWORD *)(a1 + 56) == 268509186) )
    {
      result = catch_exception_raise( /*0x16e010*/
                 *(_DWORD *)(a1 + 12),
                 *(_DWORD *)(a1 + 28),
                 *(_DWORD *)(a1 + 36),
                 *(_DWORD *)(a1 + 44),
                 *(_DWORD *)(a1 + 52),
                 *(_DWORD *)(a1 + 60));
      *(_DWORD *)(a2 + 28) = result; /*0x16e015*/
    }
    else
    {
      *(_DWORD *)(a2 + 28) = -304; /*0x16dfee*/
    }
    if ( !*(_DWORD *)(a2 + 28) ) /*0x16e018*/
    {
      *(_BYTE *)(a2 + 3) = 1; /*0x16e01e*/
      *(_DWORD *)(a2 + 4) = 32; /*0x16e022*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16dfb0*/
  }
  return result; /*0x16e029*/
}
