/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11ef04. */
int __cdecl if_down(int a1)
{
  int i; // ebx

  *(_BYTE *)(a1 + 12) &= 0xBEu; /*0x11ef0c*/
  for ( i = *(_DWORD *)(a1 + 24); i; i = *(_DWORD *)(i + 36) ) /*0x11ef15*/
    pfctlinput(0, (sockaddr *)i); /*0x11ef1b*/
  return if_qflush(a1 + 28); /*0x11ef36*/
}
