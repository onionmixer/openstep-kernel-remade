/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10782c. */
void __cdecl sub_10782C(int a1)
{
  int v1; // ebx
  unsigned int i; // ebx

  v1 = *(_DWORD *)(a1 + 4); /*0x107834*/
  if ( v1 ) /*0x107839*/
  {
    while ( *(_BYTE *)(v1 + 19) != 6 ) /*0x107840*/
    {
      v1 = *(_DWORD *)(get_posix_proc(*(__int16 *)(v1 + 48)) + 12); /*0x107882*/
      if ( !v1 ) /*0x10788a*/
        return; /*0x10788a*/
    }
    for ( i = *(_DWORD *)(a1 + 4); i; i = *(_DWORD *)(get_posix_proc(*(__int16 *)(i + 48)) + 12) ) /*0x107847*/
    {
      psignal(i, (const char *)1); /*0x10784f*/
      psignal(i, (const char *)0x13); /*0x107857*/
    }
  }
}
