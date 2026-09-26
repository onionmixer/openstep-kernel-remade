/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x119a94. */
int __cdecl vfs_fixedmajor(int a1)
{
  char **i; // eax

  for ( i = &vfssw; i < (char **)vfsNVFS; i += 2 ) /*0x119aa7*/
  {
    if ( i[1] == *(char **)(a1 + 4) ) /*0x119aaf*/
      break; /*0x119aaf*/
  }
  return (((char *)i - (char *)&vfssw) >> 3) + 128; /*0x119ac7*/
}
