/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16d9b8. */
int __cdecl sub_16D9B8(int a1, int a2, _DWORD *a3)
{
  int result; // eax

  result = *(unsigned __int8 *)(a1 + 3); /*0x16d9c6*/
  if ( *(_DWORD *)(a1 + 4) != 40 || result != 1 ) /*0x16d9d3*/
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16d9d5*/
    return result; /*0x16d9dc*/
  }
  result = 268509186; /*0x16d9e0*/
  if ( *(_DWORD *)(a1 + 24) == 268509186 && (result = 268509186, *(_DWORD *)(a1 + 32) == 268509186) ) /*0x16d9f2*/
  {
    result = a3[8]; /*0x16da00*/
    if ( !result ) /*0x16da05*/
    {
      *(_DWORD *)(a2 + 28) = -303; /*0x16da07*/
      return result; /*0x16da0e*/
    }
    result = ((int (__stdcall *)(_DWORD, _DWORD, _DWORD))result)(*a3, *(_DWORD *)(a1 + 28), *(_DWORD *)(a1 + 36)); /*0x16da1b*/
    *(_DWORD *)(a2 + 28) = result; /*0x16da1d*/
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16d9f4*/
  }
  if ( !*(_DWORD *)(a2 + 28) ) /*0x16da20*/
  {
    *(_BYTE *)(a2 + 3) = 1; /*0x16da26*/
    *(_DWORD *)(a2 + 4) = 32; /*0x16da2a*/
  }
  return result; /*0x16da34*/
}
