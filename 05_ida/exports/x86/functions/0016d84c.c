/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16d84c. */
int __cdecl sub_16D84C(int a1, int a2, _DWORD *a3)
{
  int result; // eax

  result = *(unsigned __int8 *)(a1 + 3); /*0x16d85a*/
  if ( *(_DWORD *)(a1 + 4) != 40 || result != 1 ) /*0x16d867*/
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16d869*/
    return result; /*0x16d870*/
  }
  result = 268509186; /*0x16d874*/
  if ( *(_DWORD *)(a1 + 24) == 268509186 && (result = 268509186, *(_DWORD *)(a1 + 32) == 268509186) ) /*0x16d886*/
  {
    result = a3[5]; /*0x16d894*/
    if ( !result ) /*0x16d899*/
    {
      *(_DWORD *)(a2 + 28) = -303; /*0x16d89b*/
      return result; /*0x16d8a2*/
    }
    result = ((int (__stdcall *)(_DWORD, _DWORD, _DWORD))result)(*a3, *(_DWORD *)(a1 + 28), *(_DWORD *)(a1 + 36)); /*0x16d8af*/
    *(_DWORD *)(a2 + 28) = result; /*0x16d8b1*/
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16d888*/
  }
  if ( !*(_DWORD *)(a2 + 28) ) /*0x16d8b4*/
  {
    *(_BYTE *)(a2 + 3) = 1; /*0x16d8ba*/
    *(_DWORD *)(a2 + 4) = 32; /*0x16d8be*/
  }
  return result; /*0x16d8c8*/
}
