/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16dae0. */
int __cdecl sub_16DAE0(int a1, int a2, _DWORD *a3)
{
  int result; // eax

  result = *(unsigned __int8 *)(a1 + 3); /*0x16daed*/
  if ( *(_DWORD *)(a1 + 4) == 32 && !*(_BYTE *)(a1 + 3) && (result = 268509190, *(_DWORD *)(a1 + 24) == 268509190) ) /*0x16db03*/
  {
    result = a3[11]; /*0x16db10*/
    if ( result ) /*0x16db15*/
    {
      result = ((int (__stdcall *)(_DWORD, _DWORD))result)(*a3, *(_DWORD *)(a1 + 28)); /*0x16db27*/
      *(_DWORD *)(a2 + 28) = -305; /*0x16db29*/
    }
    else
    {
      *(_DWORD *)(a2 + 28) = -303; /*0x16db17*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16db05*/
  }
  return result; /*0x16db30*/
}
