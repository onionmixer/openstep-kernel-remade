/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15decc. */
__int32 __cdecl cpu_up(int a1)
{
  int v1; // ebx
  int v2; // esi
  volatile __int32 *v3; // edx

  v1 = processor_ptr[a1]; /*0x15ded5*/
  do /*0x15def5*/
  {
    while ( dword_1E9768[0] ) /*0x15dee3*/
      ; /*0x15dee1*/
  }
  while ( _InterlockedExchange(dword_1E9768, 1) == 1 ); /*0x15def5*/
  v2 = splsched(); /*0x15defc*/
  v3 = (volatile __int32 *)(v1 + 316); /*0x15defe*/
  do /*0x15df16*/
  {
    while ( *v3 ) /*0x15df04*/
      ; /*0x15df06*/
  }
  while ( _InterlockedExchange(v3, 1) == 1 ); /*0x15df16*/
  dword_1E8E0C[8 * a1] = 1; /*0x15df1d*/
  ++dword_1F634C; /*0x15df27*/
  pset_add_processor(&default_pset, v1); /*0x15df33*/
  *(_DWORD *)(v1 + 276) = 1; /*0x15df38*/
  _InterlockedExchange((volatile __int32 *)(v1 + 316), 0); /*0x15df47*/
  splx(v2); /*0x15df4e*/
  return _InterlockedExchange(dword_1E9768, 0); /*0x15df5e*/
}
