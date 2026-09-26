/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x107964. */
_DWORD *__cdecl new_posix_proc(int a1)
{
  _DWORD *v1; // edx
  _DWORD *v2; // edx
  int v3; // eax

  v1 = (_DWORD *)posix_proc_hash[a1 & 0x3F]; /*0x107970*/
  if ( v1 ) /*0x107979*/
  {
    while ( *v1 != a1 ) /*0x10797e*/
    {
      v1 = (_DWORD *)v1[7]; /*0x107980*/
      if ( !v1 ) /*0x107985*/
        goto LABEL_4; /*0x107985*/
    }
    return nullptr; /*0x1079ac*/
  }
  else
  {
LABEL_4:
    v2 = (_DWORD *)kalloc(0x20u); /*0x107987*/
    *v2 = a1; /*0x107990*/
    v3 = a1 & 0x3F; /*0x107994*/
    v2[7] = posix_proc_hash[v3]; /*0x10799e*/
    posix_proc_hash[v3] = (int)v2; /*0x1079a1*/
    return v2; /*0x1079a8*/
  }
}
