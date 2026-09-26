/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1401f8. */
int __cdecl disksort_enter_head(int a1, _DWORD *a2)
{
  char v2; // dl

  if ( dword_1F50EC ) /*0x14020a*/
  {
    v2 = *(_BYTE *)(a1 + 12); /*0x14020c*/
    if ( (v2 & 1) != 0 ) /*0x140212*/
      return dword_1F50D4(a1, a2); /*0x14025f*/
    if ( *(_DWORD *)(a1 + 16) == a1 + 16 ) /*0x14021a*/
    {
      *(_BYTE *)(a1 + 12) = v2 | 1; /*0x14021f*/
      ((void (__cdecl *)(int))dword_1F50E4)(a1); /*0x140228*/
    }
  }
  else
  {
    if ( (*(_BYTE *)(a1 + 12) & 1) == 0 ) /*0x140230*/
      goto LABEL_10; /*0x140230*/
    if ( !dword_1F50DC(a1) ) /*0x140238*/
    {
      *(_BYTE *)(a1 + 12) &= ~1u; /*0x140241*/
      ((void (__cdecl *)(int))dword_1F50E8)(a1); /*0x14024b*/
    }
  }
  if ( (*(_BYTE *)(a1 + 12) & 1) != 0 ) /*0x140254*/
    return dword_1F50D4(a1, a2); /*0x140254*/
LABEL_10:
  a2[15] = 31; /*0x140264*/
  return sub_13F9A4(a1, a2); /*0x140275*/
}
