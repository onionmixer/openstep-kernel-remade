/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16d960. */
int __cdecl sub_16D960(int a1, int a2, _DWORD *a3)
{
  int result; // eax

  result = *(unsigned __int8 *)(a1 + 3); /*0x16d96d*/
  if ( *(_DWORD *)(a1 + 4) == 32 && result == 1 && (result = 268509186, *(_DWORD *)(a1 + 24) == 268509186) ) /*0x16d984*/
  {
    result = a3[7]; /*0x16d990*/
    if ( result ) /*0x16d995*/
    {
      result = ((int (__stdcall *)(_DWORD, _DWORD))result)(*a3, *(_DWORD *)(a1 + 28)); /*0x16d9a7*/
      *(_DWORD *)(a2 + 28) = -305; /*0x16d9a9*/
    }
    else
    {
      *(_DWORD *)(a2 + 28) = -303; /*0x16d997*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16d986*/
  }
  return result; /*0x16d9b0*/
}
