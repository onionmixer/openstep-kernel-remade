/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11ef3c. */
int __cdecl if_qflush(int *a1)
{
  int v1; // ebx
  int result; // eax

  v1 = *a1; /*0x11ef44*/
  while ( 1 ) /*0x11ef54*/
  {
    result = v1; /*0x11ef54*/
    if ( !v1 ) /*0x11ef58*/
      break; /*0x11ef58*/
    v1 = *(_DWORD *)(v1 + 124); /*0x11ef48*/
    m_freem(result); /*0x11ef4c*/
  }
  *a1 = 0; /*0x11ef5a*/
  a1[1] = 0; /*0x11ef60*/
  a1[2] = 0; /*0x11ef67*/
  return result; /*0x11ef71*/
}
