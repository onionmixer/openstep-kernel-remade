/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1385cc. */
int __cdecl xdrmbuf_inline(int a1, int a2)
{
  int result; // eax
  int v3; // edx

  result = 0; /*0x1385d6*/
  v3 = *(_DWORD *)(a1 + 20); /*0x1385d8*/
  if ( v3 >= a2 ) /*0x1385dd*/
  {
    *(_DWORD *)(a1 + 20) = v3 - a2; /*0x1385e1*/
    result = *(_DWORD *)(a1 + 12); /*0x1385e4*/
    *(_DWORD *)(a1 + 12) = result + a2; /*0x1385e9*/
  }
  return result; /*0x1385ec*/
}
