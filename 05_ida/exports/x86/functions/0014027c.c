/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14027c. */
int __cdecl disksort_enter_tail(int a1, _DWORD *a2)
{
  char v2; // dl

  if ( dword_1F50EC ) /*0x14028e*/
  {
    v2 = *(_BYTE *)(a1 + 12); /*0x140290*/
    if ( (v2 & 1) != 0 ) /*0x140296*/
      return ds_call(a1, a2); /*0x1402e3*/
    if ( *(_DWORD *)(a1 + 16) == a1 + 16 ) /*0x14029e*/
    {
      *(_BYTE *)(a1 + 12) = v2 | 1; /*0x1402a3*/
      ((void (__cdecl *)(int))dword_1F50E4)(a1); /*0x1402ac*/
    }
  }
  else
  {
    if ( (*(_BYTE *)(a1 + 12) & 1) == 0 ) /*0x1402b4*/
      goto LABEL_10; /*0x1402b4*/
    if ( !dword_1F50DC(a1) ) /*0x1402bc*/
    {
      *(_BYTE *)(a1 + 12) &= ~1u; /*0x1402c5*/
      ((void (__cdecl *)(int))dword_1F50E8)(a1); /*0x1402cf*/
    }
  }
  if ( (*(_BYTE *)(a1 + 12) & 1) != 0 ) /*0x1402d8*/
    return ds_call(a1, a2); /*0x1402d8*/
LABEL_10:
  a2[15] = 0; /*0x1402e8*/
  return sub_13F9A4(a1, a2); /*0x1402f9*/
}
