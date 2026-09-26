/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16d7c8. */
int __cdecl sub_16D7C8(int a1, int a2, _DWORD *a3)
{
  int result; // eax

  result = *(unsigned __int8 *)(a1 + 3); /*0x16d7d6*/
  if ( *(_DWORD *)(a1 + 4) != 40 || result != 1 ) /*0x16d7e3*/
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16d7e5*/
    return result; /*0x16d7ec*/
  }
  result = 268509186; /*0x16d7f0*/
  if ( *(_DWORD *)(a1 + 24) == 268509186 && (result = 268509186, *(_DWORD *)(a1 + 32) == 268509186) ) /*0x16d802*/
  {
    result = a3[4]; /*0x16d810*/
    if ( !result ) /*0x16d815*/
    {
      *(_DWORD *)(a2 + 28) = -303; /*0x16d817*/
      return result; /*0x16d81e*/
    }
    result = ((int (__stdcall *)(_DWORD, _DWORD, _DWORD))result)(*a3, *(_DWORD *)(a1 + 28), *(_DWORD *)(a1 + 36)); /*0x16d82b*/
    *(_DWORD *)(a2 + 28) = result; /*0x16d82d*/
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16d804*/
  }
  if ( !*(_DWORD *)(a2 + 28) ) /*0x16d830*/
  {
    *(_BYTE *)(a2 + 3) = 1; /*0x16d836*/
    *(_DWORD *)(a2 + 4) = 32; /*0x16d83a*/
  }
  return result; /*0x16d844*/
}
