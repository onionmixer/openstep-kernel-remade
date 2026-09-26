/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1194f4. */
const char **__cdecl vfssw_lookup(char *__s1)
{
  const char **v1; // ebx

  v1 = (const char **)&vfssw; /*0x1194fc*/
  if ( vfsNVFS <= (char *)&vfssw ) /*0x119507*/
    return nullptr; /*0x11952b*/
  while ( strcmp(__s1, *v1) ) /*0x11951a*/
  {
    v1 += 2; /*0x119520*/
    if ( vfsNVFS <= (char *)v1 ) /*0x119529*/
      return nullptr; /*0x119529*/
  }
  return v1; /*0x119530*/
}
