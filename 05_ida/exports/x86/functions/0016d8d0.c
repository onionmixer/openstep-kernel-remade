/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16d8d0. */
int __cdecl sub_16D8D0(int a1, int a2, _DWORD *a3)
{
  int result; // eax

  result = *(unsigned __int8 *)(a1 + 3); /*0x16d8de*/
  if ( *(_DWORD *)(a1 + 4) != 48 || *(_BYTE *)(a1 + 3) ) /*0x16d8de*/
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16d8ec*/
    return result; /*0x16d8f3*/
  }
  result = 268509189; /*0x16d8f8*/
  if ( *(_DWORD *)(a1 + 24) == 268509189 /*0x16d914*/
    && (result = 268509186, *(_DWORD *)(a1 + 32) == 268509186)
    && (result = 268509186, *(_DWORD *)(a1 + 40) == 268509186) )
  {
    result = a3[6]; /*0x16d920*/
    if ( !result ) /*0x16d925*/
    {
      *(_DWORD *)(a2 + 28) = -303; /*0x16d927*/
      return result; /*0x16d92e*/
    }
    result = ((int (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))result)( /*0x16d93f*/
               *a3,
               *(_DWORD *)(a1 + 28),
               *(_DWORD *)(a1 + 36),
               *(_DWORD *)(a1 + 44));
    *(_DWORD *)(a2 + 28) = result; /*0x16d941*/
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x16d916*/
  }
  if ( !*(_DWORD *)(a2 + 28) ) /*0x16d944*/
  {
    *(_BYTE *)(a2 + 3) = 1; /*0x16d94a*/
    *(_DWORD *)(a2 + 4) = 32; /*0x16d94e*/
  }
  return result; /*0x16d958*/
}
