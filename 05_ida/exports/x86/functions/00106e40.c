/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x106e40. */
int getpagesize(void)
{
  int result; // eax

  result = dword_1E875C; /*0x106e43*/
  *(_DWORD *)(dword_1E875C + 96) = page_size; /*0x106e4e*/
  return result; /*0x106e53*/
}
