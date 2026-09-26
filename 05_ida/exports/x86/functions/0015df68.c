/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15df68. */
int __cdecl cpu_down(int a1)
{
  int v1; // esi
  int v2; // ecx
  volatile __int32 *v3; // edx

  v1 = splsched(); /*0x15df75*/
  v2 = processor_ptr[a1]; /*0x15df77*/
  v3 = (volatile __int32 *)(v2 + 316); /*0x15df7e*/
  do /*0x15df96*/
  {
    while ( *v3 ) /*0x15df84*/
      ; /*0x15df86*/
  }
  while ( _InterlockedExchange(v3, 1) == 1 ); /*0x15df96*/
  dword_1E8E0C[8 * a1] = 0; /*0x15df9d*/
  --dword_1F634C; /*0x15dfa7*/
  *(_DWORD *)(v2 + 304) = 0; /*0x15dfad*/
  *(_DWORD *)(v2 + 276) = 0; /*0x15dfb7*/
  _InterlockedExchange((volatile __int32 *)(v2 + 316), 0); /*0x15dfc3*/
  return splx(v1); /*0x15dfd2*/
}
