/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x125428. */
int __cdecl in_losing(int a1)
{
  int v1; // ebx
  int result; // eax

  v1 = *(_DWORD *)(a1 + 36); /*0x125430*/
  if ( v1 ) /*0x125435*/
  {
    if ( (*(_BYTE *)(v1 + 36) & 0x10) != 0 ) /*0x12543b*/
      rtrequest(-2144308725, *(_DWORD *)(a1 + 36)); /*0x125443*/
    result = rtfree(v1); /*0x12544c*/
    *(_DWORD *)(a1 + 36) = 0; /*0x125451*/
  }
  return result; /*0x12545b*/
}
