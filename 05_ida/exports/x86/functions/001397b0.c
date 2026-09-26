/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1397b0. */
int __cdecl makespecvp(__int16 a1, int a2)
{
  int v2; // eax
  int v3; // ebx
  __int16 v4; // ax

  while ( 1 ) /*0x1397c4*/
  {
    v2 = sub_139A30(a1, 0, a2); /*0x1397c4*/
    v3 = v2; /*0x1397c9*/
    if ( !v2 ) /*0x1397d0*/
      break; /*0x1397d0*/
    v4 = *(_WORD *)(v2 + 64); /*0x139830*/
    if ( (v4 & 1) == 0 ) /*0x139836*/
      return v3 + 4; /*0x139836*/
    LOBYTE(v4) = v4 | 0x10; /*0x139838*/
    *(_WORD *)(v3 + 64) = v4; /*0x13983a*/
    sleep(v3); /*0x139841*/
  }
  v3 = kalloc(0x68u); /*0x1397d9*/
  bzero((void *)v3, 0x68u); /*0x1397de*/
  *(_DWORD *)(v3 + 32) = &spec_vnodeops; /*0x1397e3*/
  *(_DWORD *)(v3 + 44) = a2; /*0x1397ed*/
  if ( a2 == 3 ) /*0x1397f6*/
    *(_DWORD *)(v3 + 60) = specvp(0, a1, 3); /*0x139805*/
  *(_DWORD *)(v3 + 56) = 0; /*0x139808*/
  *(_WORD *)(v3 + 66) = a1; /*0x13980f*/
  *(_WORD *)(v3 + 48) = a1; /*0x139813*/
  *(_WORD *)(v3 + 10) = 1; /*0x139817*/
  *(_DWORD *)(v3 + 52) = v3; /*0x13981d*/
  *(_DWORD *)(v3 + 40) = 0; /*0x139820*/
  sub_139860(v3); /*0x139828*/
  return v3 + 4; /*0x139856*/
}
