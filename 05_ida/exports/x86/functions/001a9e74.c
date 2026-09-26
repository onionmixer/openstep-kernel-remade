/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a9e74. */
int __cdecl IOAddToVfssw(char *a1, char *a2)
{
  char **v2; // edx
  int v3; // ebx
  char *v4; // eax
  int v5; // ecx
  char **v6; // edx

  v2 = &vfssw; /*0x1a9e80*/
  v3 = 0; /*0x1a9e85*/
  v4 = vfsNVFS; /*0x1a9e87*/
  if ( &vfssw >= (char **)vfsNVFS ) /*0x1a9e8e*/
    return -1; /*0x1a9e8e*/
  v5 = 0; /*0x1a9e90*/
  while ( *v2 || v2[1] ) /*0x1a9e9d*/
  {
    v5 += 2; /*0x1a9ed4*/
    ++v3; /*0x1a9ed7*/
    v2 += 2; /*0x1a9ed8*/
    v4 = vfsNVFS; /*0x1a9edb*/
    if ( v2 >= (char **)vfsNVFS ) /*0x1a9ee2*/
      return -1; /*0x1a9ee2*/
  }
  v6 = &(&vfssw)[v5]; /*0x1a9e9f*/
  if ( v3 < 0 || v3 >= (v4 - (char *)&vfssw) >> 3 || (&vfssw)[v5] || v6[1] ) /*0x1a9ebe*/
    return -1; /*0x1a9ee4*/
  (&vfssw)[v5] = a1; /*0x1a9ec4*/
  v6[1] = a2; /*0x1a9eca*/
  return v3; /*0x1a9eec*/
}
