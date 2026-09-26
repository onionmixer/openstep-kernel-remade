/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x119294. */
void sync(void)
{
  char **i; // ebx
  char *v1; // eax

  mfs_sync(); /*0x119298*/
  for ( i = &vfssw; vfsNVFS > (char *)i; i += 2 ) /*0x1192a8*/
  {
    v1 = i[1]; /*0x1192ac*/
    if ( v1 ) /*0x1192b1*/
      (*((void (__cdecl **)(_DWORD))v1 + 4))(0); /*0x1192b8*/
  }
}
