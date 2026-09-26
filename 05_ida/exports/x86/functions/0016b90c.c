/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16b90c. */
char __cdecl zchange(int a1, char a2, char a3, char a4, int a5)
{
  char result; // al

  result = (4 * (a4 & 1)) | (2 * (a3 & 1)) & 0xFB | a2 & 1 | *(_BYTE *)(a1 + 44) & 0xF8; /*0x16b93a*/
  *(_BYTE *)(a1 + 44) = result; /*0x16b93c*/
  if ( !a5 ) /*0x16b941*/
    *(_DWORD *)(a1 + 60) = _zone_default_space; /*0x16b943*/
  if ( (*(_BYTE *)(a1 + 44) & 1) != 0 ) /*0x16b94e*/
    return lock_init((_DWORD *)(a1 + 48), 1); /*0x16b956*/
  *(_DWORD *)a1 = 0; /*0x16b960*/
  return result; /*0x16b966*/
}
