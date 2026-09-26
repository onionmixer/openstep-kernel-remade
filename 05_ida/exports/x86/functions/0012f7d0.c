/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12f7d0. */
void **__cdecl sub_12F7D0(void **a1)
{
  void **result; // eax

  result = (void **)*a1; /*0x12f7d6*/
  if ( *a1 ) /*0x12f7d6*/
  {
    if ( result == a1 ) /*0x12f7de*/
    {
      rpfreelist = nullptr; /*0x12f7e0*/
    }
    else
    {
      if ( rpfreelist == a1 ) /*0x12f7f2*/
        rpfreelist = *a1; /*0x12f7f4*/
      *(_DWORD *)a1[1] = *a1; /*0x12f7fe*/
      result = (void **)*a1; /*0x12f800*/
      *((_DWORD *)*a1 + 1) = a1[1]; /*0x12f805*/
    }
    a1[1] = nullptr; /*0x12f808*/
    *a1 = nullptr; /*0x12f80f*/
    --rnfree; /*0x12f815*/
  }
  return result; /*0x12f81d*/
}
