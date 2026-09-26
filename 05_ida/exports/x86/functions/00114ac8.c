/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x114ac8. */
int __cdecl mcldup(int a1, int a2, int a3)
{
  __int16 v3; // ax
  int v4; // eax
  int result; // eax
  _DWORD *v6; // esi

  v3 = *(_WORD *)(a1 + 12); /*0x114ad4*/
  if ( v3 == 1 ) /*0x114adc*/
  {
    v4 = *(_DWORD *)(a1 + 4) + a1; /*0x114aea*/
    *(_DWORD *)(a2 + 4) = v4 - a2; /*0x114af1*/
    *(_WORD *)(a2 + 12) = 1; /*0x114af4*/
    result = (v4 - mbutl) >> 10; /*0x114b00*/
    ++mclrefcnt[result]; /*0x114b03*/
  }
  else
  {
    if ( v3 != 2 ) /*0x114ae2*/
      panic(aMcldup); /*0x114b69*/
    v6 = (_DWORD *)kalloc(*(__int16 *)(a2 + 8) + 4); /*0x114b19*/
    *v6 = *(__int16 *)(a2 + 8) + 4; /*0x114b22*/
    bcopy((const void *)(a3 + *(_DWORD *)(a1 + 4) + a1), v6 + 1, *(__int16 *)(a2 + 8)); /*0x114b36*/
    result = (int)v6 + -a2 - a3 + 4; /*0x114b44*/
    *(_DWORD *)(a2 + 4) = result; /*0x114b47*/
    *(_WORD *)(a2 + 12) = 2; /*0x114b4a*/
    *(_DWORD *)(a2 + 16) = sub_114B78; /*0x114b50*/
    *(_DWORD *)(a2 + 20) = v6; /*0x114b57*/
    *(_DWORD *)(a2 + 24) = 0; /*0x114b5a*/
  }
  return result; /*0x114b71*/
}
