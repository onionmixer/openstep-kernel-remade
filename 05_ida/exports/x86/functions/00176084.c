/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x176084. */
__int32 __cdecl vm_map_entry_delete(_DWORD *a1, _DWORD *a2)
{
  int v2; // ebx
  volatile __int32 *v3; // edx
  int v4; // ecx
  int v5; // eax

  if ( *((_WORD *)a2 + 20) ) /*0x176090*/
  {
    vm_fault_unwire((int)a1, (int)a2); /*0x176099*/
    *((_WORD *)a2 + 20) = 0; /*0x17609e*/
  }
  --a1[7]; /*0x1760a7*/
  *(_DWORD *)a2[1] = *a2; /*0x1760af*/
  *(_DWORD *)(*a2 + 4) = a2[1]; /*0x1760b6*/
  a1[10] -= a2[3] - a2[2]; /*0x1760bf*/
  if ( (a2[6] & 5) != 0 ) /*0x1760c6*/
  {
    v2 = a2[4]; /*0x1760c8*/
    if ( v2 ) /*0x1760cd*/
    {
      v3 = (volatile __int32 *)(v2 + 52); /*0x1760cf*/
      do /*0x1760e6*/
      {
        while ( *v3 ) /*0x1760d4*/
          ; /*0x1760d6*/
      }
      while ( _InterlockedExchange(v3, 1) == 1 ); /*0x1760e6*/
      v4 = *(_DWORD *)(v2 + 48) - 1; /*0x1760eb*/
      *(_DWORD *)(v2 + 48) = v4; /*0x1760ee*/
      _InterlockedExchange((volatile __int32 *)(v2 + 52), 0); /*0x1760f4*/
      if ( v4 <= 0 ) /*0x1760f9*/
      {
        lock_write(v2); /*0x1760fc*/
        ++*(_DWORD *)(v2 + 76); /*0x176101*/
        vm_map_delete(v2, *(_DWORD *)(v2 + 20), *(_DWORD *)(v2 + 24)); /*0x176110*/
        pmap_destroy(*(_DWORD *)(v2 + 36)); /*0x176119*/
        zfree(vm_map_zone, (_DWORD *)v2); /*0x176126*/
      }
    }
  }
  else
  {
    vm_object_deallocate(a2[4]); /*0x176134*/
  }
  if ( a1[8] ) /*0x17613c*/
    v5 = vm_map_entry_zone; /*0x176142*/
  else
    v5 = vm_map_kentry_zone; /*0x17614c*/
  return zfree(v5, a2); /*0x17615b*/
}
