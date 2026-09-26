/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cbc80. */
void *__cdecl sub_1CBC80(const char *__src)
{
  size_t v1; // ebx
  void *v2; // edi
  volatile __int32 *v3; // edi

  v1 = strlen(__src) + 1; /*0x1cbc96*/
  if ( v1 <= 0xB4 ) /*0x1cbca2*/
  {
    if ( !dword_1E5568 ) /*0x1cbcc3*/
    {
      dword_1E5568 = simple_lock_alloc(); /*0x1cbcca*/
      *(_DWORD *)dword_1E5568 = 0; /*0x1cbccf*/
    }
    v3 = (volatile __int32 *)dword_1E5568; /*0x1cbcd5*/
    do /*0x1cbced*/
    {
      while ( *v3 ) /*0x1cbcdc*/
        ; /*0x1cbcdc*/
    }
    while ( _InterlockedExchange(v3, 1) == 1 ); /*0x1cbced*/
    if ( dword_1E5564 < v1 ) /*0x1cbcf5*/
    {
      dword_1E5564 = 360 * ((v1 + 359) / 0x168); /*0x1cbd1d*/
      dword_1E5560 = (void *)kalloc(dword_1E5564); /*0x1cbd2b*/
    }
    v2 = dword_1E5560; /*0x1cbd34*/
    memmove(dword_1E5560, __src, v1); /*0x1cbd3d*/
    dword_1E5560 = (char *)dword_1E5560 + v1; /*0x1cbd42*/
    dword_1E5564 -= v1; /*0x1cbd48*/
    _InterlockedExchange((volatile __int32 *)dword_1E5568, 0); /*0x1cbd55*/
  }
  else
  {
    v2 = (void *)kalloc(v1); /*0x1cbcaa*/
    memmove(v2, __src, v1); /*0x1cbcaf*/
  }
  return v2; /*0x1cbd5c*/
}
