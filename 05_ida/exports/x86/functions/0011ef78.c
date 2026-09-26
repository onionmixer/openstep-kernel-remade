/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11ef78. */
int if_down_all()
{
  int v0; // edi
  int i; // esi
  int j; // ebx

  v0 = splnet(); /*0x11ef83*/
  for ( i = ifnet; i; i = *(_DWORD *)(i + 92) ) /*0x11ef8d*/
  {
    *(_BYTE *)(i + 12) &= 0xBEu; /*0x11ef90*/
    for ( j = *(_DWORD *)(i + 24); j; j = *(_DWORD *)(j + 36) ) /*0x11ef99*/
      pfctlinput(0, (sockaddr *)j); /*0x11ef9f*/
    if_qflush((int *)(i + 28)); /*0x11efb2*/
  }
  return splx(v0); /*0x11efca*/
}
