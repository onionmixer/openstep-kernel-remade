/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1792e8. */
void __cdecl vm_object_pmap_copy(int *a1, unsigned int a2, unsigned int a3)
{
  volatile __int32 *v3; // edx
  int i; // ebx
  unsigned int v5; // eax

  if ( a1 ) /*0x1792f6*/
  {
    v3 = a1 + 4; /*0x1792f8*/
    do /*0x17930e*/
    {
      while ( *v3 ) /*0x1792fc*/
        ; /*0x1792fe*/
    }
    while ( _InterlockedExchange(v3, 1) == 1 ); /*0x17930e*/
    for ( i = *a1; a1 != (int *)i; i = *(_DWORD *)(i + 8) ) /*0x179314*/
    {
      v5 = *(_DWORD *)(i + 24); /*0x179318*/
      if ( a2 <= v5 && v5 < a3 && (*(_BYTE *)(i + 33) & 4) == 0 ) /*0x179328*/
      {
        pmap_copy_on_write(*(_DWORD *)(i + 36)); /*0x17932e*/
        *(_BYTE *)(i + 33) |= 4u; /*0x179333*/
      }
    }
    _InterlockedExchange(a1 + 4, 0); /*0x179343*/
  }
}
