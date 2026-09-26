/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16da88. */
int __cdecl sub_16DA88(int a1, int a2, _DWORD *a3)
{
  int result; // eax

  result = *(unsigned __int8 *)(a1 + 3); /*0x16da95*/
  if ( *(_DWORD *)(a1 + 4) == 32 && result == 1 && (result = 268509186, *(_DWORD *)(a1 + 24) == 268509186) ) /*0x16daac*/
  {
    result = a3[10]; /*0x16dab8*/
    if ( result ) /*0x16dabd*/
    {
      result = ((int (__stdcall *)(_DWORD, _DWORD))result)(*a3, *(_DWORD *)(a1 + 28)); /*0x16dacf*/
      *(_DWORD *)(a2 + 28) = -305; /*0x16dad1*/
    }
    else
    {
      *(_DWORD *)(a2 + 28) = -303; /*0x16dabf*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16daae*/
  }
  return result; /*0x16dad8*/
}
