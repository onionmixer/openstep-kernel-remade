/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1180e8. */
int __cdecl getsock(unsigned int a1)
{
  int result; // eax

  result = getf(a1); /*0x1180ef*/
  if ( !result ) /*0x1180f6*/
    return 0; /*0x1180f8*/
  if ( *(_WORD *)(result + 12) != 2 ) /*0x118105*/
  {
    *(_BYTE *)(dword_1E875C + 104) = 38; /*0x11810c*/
    return 0; /*0x118110*/
  }
  return result; /*0x1180fc*/
}
