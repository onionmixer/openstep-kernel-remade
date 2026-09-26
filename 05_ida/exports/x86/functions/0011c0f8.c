/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11c0f8. */
int __cdecl lookupname(int a1, int a2, int a3, int a4, int a5)
{
  int result; // eax
  int v6; // [esp+4h] [ebp-10h]
  _BYTE v7[12]; // [esp+8h] [ebp-Ch] BYREF

  result = pn_get(a1, a2, v7); /*0x11c10b*/
  if ( !result ) /*0x11c115*/
  {
    v6 = lookuppn(v7, a3, a4, a5); /*0x11c12a*/
    pn_free(v7); /*0x11c12d*/
    return v6; /*0x11c132*/
  }
  return result; /*0x11c135*/
}
