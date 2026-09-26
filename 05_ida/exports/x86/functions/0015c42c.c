/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15c42c. */
int __cdecl getsegbynamefromheader(int a1, char *__s2)
{
  int v2; // ebx
  int v3; // esi

  v2 = a1 + 28; /*0x15c435*/
  v3 = 0; /*0x15c438*/
  if ( !*(_DWORD *)(a1 + 16) ) /*0x15c43a*/
    return 0; /*0x15c469*/
  while ( *(_DWORD *)v2 != 1 || strncmp((const char *)(v2 + 8), __s2, 0x10u) ) /*0x15c459*/
  {
    v2 += *(_DWORD *)(v2 + 4); /*0x15c460*/
    if ( *(_DWORD *)(a1 + 16) <= (unsigned int)++v3 ) /*0x15c467*/
      return 0; /*0x15c467*/
  }
  return v2; /*0x15c46e*/
}
