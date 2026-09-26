/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16d6ec. */
int __cdecl sub_16D6EC(int a1, int a2, _DWORD *a3)
{
  int result; // eax

  result = *(unsigned __int8 *)(a1 + 3); /*0x16d6f9*/
  if ( *(_DWORD *)(a1 + 4) != 32 || result != 1 ) /*0x16d706*/
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16d708*/
    return result; /*0x16d70f*/
  }
  result = 268509186; /*0x16d714*/
  if ( *(_DWORD *)(a1 + 24) == 268509186 ) /*0x16d71c*/
  {
    result = a3[2]; /*0x16d728*/
    if ( !result ) /*0x16d72d*/
    {
      *(_DWORD *)(a2 + 28) = -303; /*0x16d72f*/
      return result; /*0x16d736*/
    }
    result = ((int (__stdcall *)(_DWORD, _DWORD))result)(*a3, *(_DWORD *)(a1 + 28)); /*0x16d73f*/
    *(_DWORD *)(a2 + 28) = result; /*0x16d741*/
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16d71e*/
  }
  if ( !*(_DWORD *)(a2 + 28) ) /*0x16d744*/
  {
    *(_BYTE *)(a2 + 3) = 1; /*0x16d74a*/
    *(_DWORD *)(a2 + 4) = 32; /*0x16d74e*/
  }
  return result; /*0x16d755*/
}
