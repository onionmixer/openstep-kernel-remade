/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bf0d8. */
int __cdecl sub_1BF0D8(int a1, int a2)
{
  int result; // eax

  result = *(unsigned __int8 *)(a1 + 3); /*0x1bf0e2*/
  if ( *(_DWORD *)(a1 + 4) == 40 && !*(_BYTE *)(a1 + 3) ) /*0x1bf0ee*/
  {
    result = 268509186; /*0x1bf0fc*/
    if ( *(_DWORD *)(a1 + 24) == 268509186 && (result = 268509190, *(_DWORD *)(a1 + 32) == 268509190) ) /*0x1bf10e*/
    {
      result = (int)EvSetSpecialKeyPort(); /*0x1bf128*/
      *(_DWORD *)(a2 + 28) = result; /*0x1bf12d*/
    }
    else
    {
      *(_DWORD *)(a2 + 28) = -304; /*0x1bf110*/
    }
    if ( !*(_DWORD *)(a2 + 28) ) /*0x1bf130*/
    {
      *(_BYTE *)(a2 + 3) = 1; /*0x1bf136*/
      *(_DWORD *)(a2 + 4) = 32; /*0x1bf13a*/
    }
  }
  else
  {
    *(_DWORD *)(a2 + 28) = -304; /*0x1bf0f0*/
  }
  return result; /*0x1bf141*/
}
