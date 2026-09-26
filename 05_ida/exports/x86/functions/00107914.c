/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x107914. */
int __cdecl insert_posix_proc(_DWORD *a1, int a2)
{
  _DWORD *v2; // eax
  int v4; // eax

  v2 = (_DWORD *)posix_proc_hash[a2 & 0x3F]; /*0x107923*/
  if ( v2 ) /*0x10792c*/
  {
    while ( *v2 != a2 ) /*0x107932*/
    {
      v2 = (_DWORD *)v2[7]; /*0x107938*/
      if ( !v2 ) /*0x10793d*/
        goto LABEL_5; /*0x10793d*/
    }
    return 0; /*0x107934*/
  }
  else
  {
LABEL_5:
    *a1 = a2; /*0x10793f*/
    v4 = a2 & 0x3F; /*0x107943*/
    a1[7] = posix_proc_hash[v4]; /*0x10794d*/
    posix_proc_hash[v4] = (int)a1; /*0x107950*/
    return 1; /*0x107957*/
  }
}
