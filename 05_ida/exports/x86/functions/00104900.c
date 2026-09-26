/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x104900. */
int __cdecl getf(unsigned int a1)
{
  int result; // eax

  if ( *(_DWORD *)(active_u + 348) > a1 && (result = *(_DWORD *)(*(_DWORD *)(active_u + 336) + 4 * a1)) != 0 ) /*0x10491e*/
  {
    if ( result == -65536 ) /*0x104935*/
    {
      result = dword_1E875C; /*0x104937*/
      *(_BYTE *)(dword_1E875C + 104) = 9; /*0x10493c*/
    }
  }
  else
  {
    *(_BYTE *)(dword_1E875C + 104) = 9; /*0x104925*/
    return 0; /*0x104929*/
  }
  return result; /*0x10492d*/
}
