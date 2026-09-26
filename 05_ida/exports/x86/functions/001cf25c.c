/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cf25c. */
char *__cdecl sub_1CF25C(unsigned int a1)
{
  size_t i; // edi
  int v2; // ebx
  int v3; // edx
  unsigned int v4; // eax

  for ( i = 0; _nel > i; ++i ) /*0x1cf262*/
  {
    v2 = *((_DWORD *)dword_1E55F8 + 6 * i + 4); /*0x1cf27b*/
    v3 = sub_1CF6B0(*((_DWORD *)dword_1E55F8 + 6 * i)); /*0x1cf288*/
    v4 = *(_DWORD *)(v3 + 24) + v2; /*0x1cf28c*/
    if ( a1 >= v4 && a1 < *(_DWORD *)(v3 + 28) + v4 ) /*0x1cf29d*/
      return (char *)dword_1E55F8 + 24 * i; /*0x1cf2a7*/
  }
  return nullptr; /*0x1cf2b8*/
}
