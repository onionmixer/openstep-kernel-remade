/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16dbc8. */
int __cdecl sub_16DBC8(int a1, int a2, _DWORD *a3)
{
  int result; // eax

  result = *(unsigned __int8 *)(a1 + 3); /*0x16dbd5*/
  if ( *(_DWORD *)(a1 + 4) != 32 || result != 1 ) /*0x16dbe2*/
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16dbe4*/
    return result; /*0x16dbeb*/
  }
  result = 268509186; /*0x16dbf0*/
  if ( *(_DWORD *)(a1 + 24) == 268509186 ) /*0x16dbf8*/
  {
    result = a3[13]; /*0x16dc04*/
    if ( !result ) /*0x16dc09*/
    {
      *(_DWORD *)(a2 + 28) = -303; /*0x16dc0b*/
      return result; /*0x16dc12*/
    }
    result = ((int (__stdcall *)(_DWORD, _DWORD))result)(*a3, *(_DWORD *)(a1 + 28)); /*0x16dc1b*/
    *(_DWORD *)(a2 + 28) = result; /*0x16dc1d*/
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16dbfa*/
  }
  if ( !*(_DWORD *)(a2 + 28) ) /*0x16dc20*/
  {
    *(_BYTE *)(a2 + 3) = 1; /*0x16dc26*/
    *(_DWORD *)(a2 + 4) = 32; /*0x16dc2a*/
  }
  return result; /*0x16dc31*/
}
