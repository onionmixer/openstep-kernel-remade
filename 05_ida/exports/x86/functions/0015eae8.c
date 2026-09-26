/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15eae8. */
int __cdecl mfs_uncache(int *a1)
{
  int result; // eax

  result = *a1; /*0x15eaee*/
  if ( (*(_BYTE *)(*a1 + 56) & 0x10) != 0 && !*(_WORD *)(result + 4) ) /*0x15eaf6*/
    return mfs_memfree(result, 0); /*0x15eb00*/
  return result; /*0x15eb07*/
}
