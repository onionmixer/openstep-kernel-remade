/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a9e18. */
int __cdecl IOAddToVfsswAt(int a1, char *a2, char *a3)
{
  char **v3; // ebx

  v3 = &(&vfssw)[2 * a1]; /*0x1a9e27*/
  if ( a1 < 0 || a1 >= (vfsNVFS - (char *)&vfssw) >> 3 || (&vfssw)[2 * a1] || v3[1] ) /*0x1a9e4b*/
    return -1; /*0x1a9e51*/
  (&vfssw)[2 * a1] = a2; /*0x1a9e5b*/
  v3[1] = a3; /*0x1a9e64*/
  return a1; /*0x1a9e6c*/
}
