/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11d7d8. */
int __cdecl stat1(int *a1, int a2)
{
  int result; // eax
  int v3; // [esp+8h] [ebp-48h]
  int v4; // [esp+Ch] [ebp-44h] BYREF
  _BYTE v5[64]; // [esp+10h] [ebp-40h] BYREF

  result = lookupname(*a1, 0, a2, 0, (int)&v4); /*0x11d7f2*/
  if ( !result ) /*0x11d7fc*/
  {
    v3 = vno_stat(v4, v5); /*0x11d80f*/
    vn_rele(v4); /*0x11d812*/
    result = v3; /*0x11d81a*/
    if ( !v3 ) /*0x11d81f*/
      return copyout(v5, a1[1], 64); /*0x11d828*/
  }
  return result; /*0x11d830*/
}
