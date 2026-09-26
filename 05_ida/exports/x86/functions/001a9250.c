/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a9250. */
int __cdecl IOSetUNIXError(char a1)
{
  int result; // eax

  result = dword_1E875C; /*0x1a9253*/
  *(_BYTE *)(dword_1E875C + 104) = a1; /*0x1a925b*/
  return result; /*0x1a9260*/
}
