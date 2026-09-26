/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x108d40. */
__int32 kill_tasks()
{
  int v0; // eax
  int *i; // esi
  int v2; // ebx
  int v3; // edi
  int v5; // [esp+Ch] [ebp-4h]

  v0 = pmap_create(0); /*0x108d51*/
  v5 = vm_map_create(v0, 0, 0, 1); /*0x108d5f*/
  do /*0x108d81*/
  {
    while ( all_psets_lock ) /*0x108d6f*/
      ; /*0x108d6d*/
  }
  while ( _InterlockedExchange(&all_psets_lock, 1) == 1 ); /*0x108d81*/
LABEL_10:
  for ( i = (int *)all_psets; i != &all_psets; i = (int *)set ) /*0x108dc7*/
  {
    if ( i != (int *)&default_pset ) /*0x108d8e*/
    {
      _InterlockedExchange(&all_psets_lock, 0); /*0x108d9a*/
      processor_set_destroy((processor_set_t)i); /*0x108da1*/
      do /*0x108dc5*/
      {
        while ( all_psets_lock ) /*0x108db3*/
          ; /*0x108db1*/
      }
      while ( _InterlockedExchange(&all_psets_lock, 1) == 1 ); /*0x108dc5*/
      goto LABEL_10; /*0x108dc5*/
    }
  }
  _InterlockedExchange(&all_psets_lock, 0); /*0x108dd7*/
  do /*0x108dfa*/
  {
    while ( dword_1E9768[0] ) /*0x108dec*/
      ; /*0x108dea*/
  }
  while ( _InterlockedExchange(dword_1E9768, 1) == 1 ); /*0x108dfa*/
  while ( 1 ) /*0x108e5c*/
  {
    v3 = unk_1E973C; /*0x108e5c*/
    if ( !unk_1E9744 ) /*0x108e69*/
      break; /*0x108e69*/
    pset_remove_task(&default_pset, unk_1E973C); /*0x108e02*/
    v2 = *(_DWORD *)(v3 + 12); /*0x108e07*/
    if ( kernel_map != v2 && v5 != v2 ) /*0x108e18*/
    {
      *(_DWORD *)(v3 + 12) = v5; /*0x108e1d*/
      vm_map_reference(v5); /*0x108e21*/
      _InterlockedExchange(dword_1E9768, 0); /*0x108e2b*/
      vm_map_remove(v2, *(_DWORD *)(v2 + 20), *(_DWORD *)(v2 + 24)); /*0x108e3a*/
      do /*0x108e5a*/
      {
        while ( dword_1E9768[0] ) /*0x108e4c*/
          ; /*0x108e4a*/
      }
      while ( _InterlockedExchange(dword_1E9768, 1) == 1 ); /*0x108e5a*/
    }
  }
  return _InterlockedExchange(dword_1E9768, 0); /*0x108e76*/
}
