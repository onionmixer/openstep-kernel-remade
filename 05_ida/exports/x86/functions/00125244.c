/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x125244. */
int __cdecl in_pcbdisconnect(int a1)
{
  int result; // eax

  *(_DWORD *)(a1 + 12) = 0; /*0x12524a*/
  *(_WORD *)(a1 + 16) = 0; /*0x125251*/
  result = *(_DWORD *)(a1 + 28); /*0x125257*/
  if ( (*(_BYTE *)(result + 6) & 1) != 0 ) /*0x12525e*/
    return in_pcbdetach(a1); /*0x125261*/
  return result; /*0x125268*/
}
