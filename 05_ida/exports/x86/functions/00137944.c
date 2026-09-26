/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x137944. */
int __cdecl sub_137944(_DWORD *a1)
{
  _DWORD *v1; // ecx
  int result; // eax
  _DWORD *v3; // edx

  v1 = nullptr; /*0x13794b*/
  result = *a1 & 0x1F; /*0x13794f*/
  v3 = (_DWORD *)drhashtbl[result]; /*0x137952*/
  if ( v3 ) /*0x13795b*/
  {
    while ( v3 != a1 ) /*0x137962*/
    {
      v1 = v3; /*0x137984*/
      v3 = (_DWORD *)v3[9]; /*0x137986*/
      if ( !v3 ) /*0x13798b*/
        return result; /*0x13798b*/
    }
    if ( v1 ) /*0x137966*/
    {
      v1[9] = v3[9]; /*0x13797f*/
    }
    else
    {
      result = *v3 & 0x1F; /*0x13796a*/
      drhashtbl[result] = v3[9]; /*0x137970*/
    }
  }
  return result; /*0x13798d*/
}
