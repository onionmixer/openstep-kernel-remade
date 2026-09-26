/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16db38. */
int __cdecl sub_16DB38(int a1, int a2, _DWORD *a3)
{
  int result; // eax

  result = *(unsigned __int8 *)(a1 + 3); /*0x16db46*/
  if ( *(_DWORD *)(a1 + 4) != 48 || *(_BYTE *)(a1 + 3) ) /*0x16db46*/
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16db54*/
    return result; /*0x16db5b*/
  }
  result = 268509189; /*0x16db60*/
  if ( *(_DWORD *)(a1 + 24) == 268509189 /*0x16db7c*/
    && (result = 268509186, *(_DWORD *)(a1 + 32) == 268509186)
    && (result = 268509186, *(_DWORD *)(a1 + 40) == 268509186) )
  {
    result = a3[12]; /*0x16db88*/
    if ( !result ) /*0x16db8d*/
    {
      *(_DWORD *)(a2 + 28) = -303; /*0x16db8f*/
      return result; /*0x16db96*/
    }
    result = ((int (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))result)( /*0x16dba7*/
               *a3,
               *(_DWORD *)(a1 + 28),
               *(_DWORD *)(a1 + 36),
               *(_DWORD *)(a1 + 44));
    *(_DWORD *)(a2 + 28) = result; /*0x16dba9*/
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16db7e*/
  }
  if ( !*(_DWORD *)(a2 + 28) ) /*0x16dbac*/
  {
    *(_BYTE *)(a2 + 3) = 1; /*0x16dbb2*/
    *(_DWORD *)(a2 + 4) = 32; /*0x16dbb6*/
  }
  return result; /*0x16dbc0*/
}
