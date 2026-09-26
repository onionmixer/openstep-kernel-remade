/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x107ba0. */
char getposix()
{
  char result; // al

  result = *(_BYTE *)(*(_DWORD *)active_u + 22) >> 1; /*0x107bb3*/
  *(_DWORD *)(dword_1E875C + 96) = (*(_BYTE *)(*(_DWORD *)active_u + 22) & 2) != 0; /*0x107bba*/
  return result; /*0x107bbf*/
}
