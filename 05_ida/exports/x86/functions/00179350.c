/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x179350. */
void __cdecl vm_object_pmap_remove(int a1, unsigned int a2, unsigned int a3)
{
  volatile __int32 *v3; // edx
  _DWORD *i; // ebx
  unsigned int v5; // eax

  if ( a1 ) /*0x17935e*/
  {
    v3 = (volatile __int32 *)(a1 + 16); /*0x179360*/
    do /*0x179376*/
    {
      while ( *v3 ) /*0x179364*/
        ; /*0x179366*/
    }
    while ( _InterlockedExchange(v3, 1) == 1 ); /*0x179376*/
    for ( i = *(_DWORD **)a1; (_DWORD *)a1 != i; i = (_DWORD *)i[2] ) /*0x17937c*/
    {
      v5 = i[6]; /*0x179380*/
      if ( a2 <= v5 && v5 < a3 ) /*0x17938a*/
        pmap_remove_all(i[9]); /*0x179390*/
    }
    _InterlockedExchange((volatile __int32 *)(a1 + 16), 0); /*0x1793a1*/
  }
}
