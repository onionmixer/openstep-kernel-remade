/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x140168. */
int __cdecl disksort_enter(int a1, _DWORD *a2)
{
  thread_act_t v2; // edi
  char v3; // dl

  v2 = active_threads; /*0x140174*/
  if ( dword_1F50EC ) /*0x140181*/
  {
    v3 = *(_BYTE *)(a1 + 12); /*0x140183*/
    if ( (v3 & 1) != 0 ) /*0x140189*/
      return ds_call(a1, a2); /*0x1401d7*/
    if ( *(_DWORD *)(a1 + 16) == a1 + 16 ) /*0x140191*/
    {
      *(_BYTE *)(a1 + 12) = v3 | 1; /*0x140196*/
      ((void (__cdecl *)(int))dword_1F50E4)(a1); /*0x14019f*/
    }
  }
  else
  {
    if ( (*(_BYTE *)(a1 + 12) & 1) == 0 ) /*0x1401a8*/
      goto LABEL_10; /*0x1401a8*/
    if ( !dword_1F50DC(a1) ) /*0x1401b0*/
    {
      *(_BYTE *)(a1 + 12) &= ~1u; /*0x1401b9*/
      ((void (__cdecl *)(int))dword_1F50E8)(a1); /*0x1401c3*/
    }
  }
  if ( (*(_BYTE *)(a1 + 12) & 1) != 0 ) /*0x1401cc*/
    return ds_call(a1, a2); /*0x1401cc*/
LABEL_10:
  if ( v2 ) /*0x1401de*/
    a2[15] = *(_DWORD *)(v2 + 80); /*0x1401e3*/
  return sub_13F9A4(a1, a2); /*0x1401f0*/
}
