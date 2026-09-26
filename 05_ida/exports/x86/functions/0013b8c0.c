/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13b8c0. */
int __cdecl fsfull(int a1, int a2)
{
  char *v2; // ebx
  const char *v3; // esi
  int result; // eax

  if ( (a2 & 1) != 0 ) /*0x13b8cf*/
  {
    v2 = aFileSystemFull; /*0x13b8d1*/
    v3 = aWriteFailedFil; /*0x13b8d6*/
  }
  else
  {
    if ( (a2 & 2) == 0 ) /*0x13b8e6*/
      panic(aFsfull); /*0x13b8fd*/
    v2 = aOutOfInodes; /*0x13b8e8*/
    v3 = aCreateSymlinkF; /*0x13b8ed*/
  }
  if ( (*(char *)(a1 + 211) & a2) == 0 ) /*0x13b90f*/
    fserr(a1, v2); /*0x13b913*/
  *(_BYTE *)(a1 + 211) |= a2; /*0x13b91e*/
  if ( (*(_BYTE *)(active_u + 608) & 8) == 0 )
    uprintf("\n%s: %s\n", (const char *)(a1 + 212), v3);
  if ( !*(_DWORD *)(dword_1E875C + 108) ) /*0x13b949*/
  {
    *(_DWORD *)(dword_1E875C + 108) = a1; /*0x13b94f*/
    *(_BYTE *)(dword_1E875C + 112) = a2; /*0x13b95a*/
  }
  result = dword_1E875C; /*0x13b95d*/
  *(_BYTE *)(dword_1E875C + 104) = 28; /*0x13b962*/
  return result; /*0x13b969*/
}
