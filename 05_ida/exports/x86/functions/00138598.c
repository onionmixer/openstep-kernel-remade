/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x138598. */
int __cdecl xdrmbuf_setpos(_DWORD *a1, int a2)
{
  int v2; // eax
  int v3; // edx

  v2 = a2 + *(_DWORD *)(a1[4] + 4) + a1[4]; /*0x1385a4*/
  v3 = a1[5] + a1[3]; /*0x1385aa*/
  if ( v2 > v3 ) /*0x1385af*/
    return 0; /*0x1385c4*/
  a1[3] = v2; /*0x1385b1*/
  a1[5] = v3 - v2; /*0x1385b6*/
  return 1; /*0x1385c0*/
}
