/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x168870. */
int __cdecl thread_max_priority(int a1, int a2, signed int a3)
{
  int v4; // edi
  volatile __int32 *v5; // edx
  int v6; // eax

  if ( !a1 || !a2 || (unsigned int)a3 > 0x1F ) /*0x168889*/
    return 4; /*0x16888b*/
  v4 = splsched(); /*0x168899*/
  v5 = (volatile __int32 *)(a1 + 32); /*0x16889b*/
  do /*0x1688b2*/
  {
    while ( *v5 ) /*0x1688a0*/
      ; /*0x1688a2*/
  }
  while ( _InterlockedExchange(v5, 1) == 1 ); /*0x1688b2*/
  *(_DWORD *)(a1 + 84) = a3; /*0x1688b4*/
  if ( *(_DWORD *)(a1 + 80) <= a3 ) /*0x1688ba*/
  {
    v6 = *(_DWORD *)(a1 + 100); /*0x1688cc*/
    if ( v6 >= 0 && v6 > a3 ) /*0x1688d5*/
      *(_DWORD *)(a1 + 100) = a3; /*0x1688d7*/
  }
  else
  {
    *(_DWORD *)(a1 + 80) = a3; /*0x1688bc*/
    compute_priority((_DWORD *)a1, 1); /*0x1688c2*/
  }
  _InterlockedExchange((volatile __int32 *)(a1 + 32), 0); /*0x1688dc*/
  splx(v4); /*0x1688e0*/
  return 0; /*0x1688ea*/
}
