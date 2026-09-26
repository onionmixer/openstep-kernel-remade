/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cf6b0. */
int __cdecl sub_1CF6B0(int a1)
{
  int v1; // ebx
  int v2; // esi

  v1 = a1 + 28; /*0x1cf6b9*/
  v2 = 0; /*0x1cf6bc*/
  if ( !*(_DWORD *)(a1 + 16) ) /*0x1cf6be*/
    return 0; /*0x1cf6ed*/
  while ( *(_DWORD *)v1 != 1 || strncmp((const char *)(v1 + 8), "__OBJC", 0x10u) ) /*0x1cf6de*/
  {
    v1 += *(_DWORD *)(v1 + 4); /*0x1cf6e4*/
    if ( *(_DWORD *)(a1 + 16) <= (unsigned int)++v2 ) /*0x1cf6eb*/
      return 0; /*0x1cf6eb*/
  }
  return v1; /*0x1cf6f2*/
}
