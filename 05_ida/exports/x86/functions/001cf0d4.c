/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cf0d4. */
void __cdecl sub_1CF0D4(int a1)
{
  int v1; // esi
  const char **v2; // ebx

  if ( dword_1E5620 ) /*0x1cf0e3*/
  {
    v1 = NXMapRemove((_DWORD *)dword_1E5620, *(_DWORD *)(a1 + 8)); /*0x1cf0f5*/
    if ( v1 ) /*0x1cf0fc*/
    {
      do /*0x1cf11c*/
      {
        _objc_add_category(*(const char ***)(v1 + 4), *(_DWORD *)(v1 + 8)); /*0x1cf108*/
        v2 = *(const char ***)v1; /*0x1cf10d*/
        free((void *)v1); /*0x1cf110*/
        v1 = (int)v2; /*0x1cf115*/
      }
      while ( v2 ); /*0x1cf11c*/
    }
  }
}
