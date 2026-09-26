/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x168f90. */
int __usercall thread_doswapin@<eax>(int a1@<eax>, int a2)
{
  void *v2; // esp
  int v3; // esi
  volatile __int32 *v4; // edx
  int v5; // eax
  int v6; // ecx

  v2 = alloca(a1); /*0x168f9e*/
  v3 = splsched(a2, thread_continue); /*0x168fa8*/
  v4 = (volatile __int32 *)(a2 + 32); /*0x168faa*/
  do /*0x168fc2*/
  {
    while ( *v4 ) /*0x168fb0*/
      ; /*0x168fb2*/
  }
  while ( _InterlockedExchange(v4, 1) == 1 ); /*0x168fc2*/
  v5 = *(_DWORD *)(a2 + 76); /*0x168fc4*/
  v6 = v5; /*0x168fc7*/
  BYTE1(v6) = BYTE1(v5) & 0xFC; /*0x168fc9*/
  *(_DWORD *)(a2 + 76) = v6; /*0x168fcc*/
  if ( (v5 & 4) != 0 ) /*0x168fd1*/
    thread_setrun((char **)a2, 1); /*0x168fd6*/
  _InterlockedExchange((volatile __int32 *)(a2 + 32), 0); /*0x168fe0*/
  return splx(v3); /*0x168fec*/
}
