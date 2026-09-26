/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16d75c. */
int __cdecl sub_16D75C(int a1, int a2, _DWORD *a3)
{
  int result; // eax

  result = *(unsigned __int8 *)(a1 + 3); /*0x16d769*/
  if ( *(_DWORD *)(a1 + 4) != 32 || *(_BYTE *)(a1 + 3) ) /*0x16d769*/
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16d777*/
    return result; /*0x16d77e*/
  }
  result = 268509190; /*0x16d780*/
  if ( *(_DWORD *)(a1 + 24) == 268509190 ) /*0x16d788*/
  {
    result = a3[3]; /*0x16d794*/
    if ( !result ) /*0x16d799*/
    {
      *(_DWORD *)(a2 + 28) = -303; /*0x16d79b*/
      return result; /*0x16d7a2*/
    }
    result = ((int (__stdcall *)(_DWORD, _DWORD))result)(*a3, *(_DWORD *)(a1 + 28)); /*0x16d7ab*/
    *(_DWORD *)(a2 + 28) = result; /*0x16d7ad*/
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16d78a*/
  }
  if ( !*(_DWORD *)(a2 + 28) ) /*0x16d7b0*/
  {
    *(_BYTE *)(a2 + 3) = 1; /*0x16d7b6*/
    *(_DWORD *)(a2 + 4) = 32; /*0x16d7ba*/
  }
  return result; /*0x16d7c1*/
}
