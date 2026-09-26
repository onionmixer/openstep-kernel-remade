/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16dc38. */
int __cdecl sub_16DC38(int a1, int a2, _DWORD *a3)
{
  int result; // eax

  result = *(unsigned __int8 *)(a1 + 3); /*0x16dc45*/
  if ( *(_DWORD *)(a1 + 4) != 32 || result != 1 ) /*0x16dc52*/
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16dc54*/
    return result; /*0x16dc5b*/
  }
  result = 268509186; /*0x16dc60*/
  if ( *(_DWORD *)(a1 + 24) == 268509186 ) /*0x16dc68*/
  {
    result = a3[14]; /*0x16dc74*/
    if ( !result ) /*0x16dc79*/
    {
      *(_DWORD *)(a2 + 28) = -303; /*0x16dc7b*/
      return result; /*0x16dc82*/
    }
    result = ((int (__stdcall *)(_DWORD, _DWORD))result)(*a3, *(_DWORD *)(a1 + 28)); /*0x16dc8b*/
    *(_DWORD *)(a2 + 28) = result; /*0x16dc8d*/
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16dc6a*/
  }
  if ( !*(_DWORD *)(a2 + 28) ) /*0x16dc90*/
  {
    *(_BYTE *)(a2 + 3) = 1; /*0x16dc96*/
    *(_DWORD *)(a2 + 4) = 32; /*0x16dc9a*/
  }
  return result; /*0x16dca1*/
}
