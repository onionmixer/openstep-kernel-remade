/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12a8cc. */
int tcp_fasttimo()
{
  int v0; // esi
  int *v1; // ebx
  int v2; // edx
  char v3; // al

  v0 = splnet(); /*0x12a8d6*/
  v1 = (int *)tcb; /*0x12a8d8*/
  if ( tcb && (int *)tcb != &tcb ) /*0x12a8e8*/
  {
    do /*0x12a918*/
    {
      v2 = v1[8]; /*0x12a8ec*/
      if ( v2 ) /*0x12a8f1*/
      {
        v3 = *(_BYTE *)(v2 + 27); /*0x12a8f3*/
        if ( (v3 & 2) != 0 ) /*0x12a8f8*/
        {
          *(_BYTE *)(v2 + 27) = v3 & 0xFC | 1; /*0x12a8fe*/
          ++dword_1EED90; /*0x12a901*/
          tcp_output(v2); /*0x12a908*/
        }
      }
      v1 = (int *)*v1; /*0x12a910*/
    }
    while ( v1 != &tcb ); /*0x12a918*/
  }
  return splx(v0); /*0x12a923*/
}
