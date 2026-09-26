/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x168c5c. */
kern_return_t __cdecl processor_set_stack_usage(
        processor_set_t pset,
        unsigned int *ltotal,
        vm_size_t *space,
        vm_size_t *resident,
        vm_size_t *maxusage,
        vm_offset_t *maxstack)
{
  volatile __int32 *v7; // esi
  unsigned int v8; // esi
  int i; // ebx
  volatile __int32 *v10; // edx
  unsigned int v11; // ebx
  unsigned int j; // esi
  int v13; // edi
  int v14; // edx
  int v15; // eax
  unsigned int k; // eax
  unsigned int v17; // eax
  vm_size_t v18; // eax
  int v19; // [esp+Ch] [ebp-1Ch]
  unsigned int v20; // [esp+10h] [ebp-18h]
  int v21; // [esp+14h] [ebp-14h]
  unsigned int v22; // [esp+18h] [ebp-10h]
  vm_offset_t v23; // [esp+20h] [ebp-8h]
  vm_size_t v24; // [esp+24h] [ebp-4h]

  if ( !pset ) /*0x168c69*/
    return 4; /*0x168c6b*/
  v22 = 0; /*0x168c90*/
  v21 = 0; /*0x168c97*/
  v7 = (volatile __int32 *)(pset + 344); /*0x168ca1*/
  while ( 1 ) /*0x168cba*/
  {
    do /*0x168cba*/
    {
      while ( *v7 ) /*0x168ca8*/
        ; /*0x168caa*/
    }
    while ( _InterlockedExchange(v7, 1) == 1 ); /*0x168cba*/
    if ( !*(_DWORD *)(pset + 340) ) /*0x168cc6*/
    {
      _InterlockedExchange((volatile __int32 *)(pset + 344), 0); /*0x168c7d*/
      return 4; /*0x168c88*/
    }
    v20 = *(_DWORD *)(pset + 320); /*0x168cce*/
    if ( v22 >= 4 * v20 ) /*0x168cdb*/
      break; /*0x168cdb*/
    _InterlockedExchange((volatile __int32 *)(pset + 344), 0); /*0x168cdf*/
    if ( v22 ) /*0x168ce9*/
      kfree(v21, v22); /*0x168cf3*/
    v22 = 4 * v20; /*0x168cfb*/
    v21 = kalloc(4 * v20); /*0x168d04*/
    if ( !v21 ) /*0x168d0c*/
      return 6; /*0x168d13*/
  }
  v8 = 0; /*0x168d1e*/
  for ( i = *(_DWORD *)(pset + 312); v20 > v8; i = *(_DWORD *)(i + 24) ) /*0x168d2c*/
  {
    if ( i ) /*0x168d32*/
    {
      v19 = splsched(); /*0x168d39*/
      v10 = (volatile __int32 *)(i + 32); /*0x168d3c*/
      do /*0x168d52*/
      {
        while ( *v10 ) /*0x168d40*/
          ; /*0x168d42*/
      }
      while ( _InterlockedExchange(v10, 1) == 1 ); /*0x168d52*/
      ++*(_DWORD *)(i + 36); /*0x168d54*/
      _InterlockedExchange((volatile __int32 *)(i + 32), 0); /*0x168d59*/
      splx(v19); /*0x168d60*/
    }
    *(_DWORD *)(v21 + 4 * v8++) = i; /*0x168d6b*/
  }
  _InterlockedExchange((volatile __int32 *)(pset + 344), 0); /*0x168d7c*/
  v11 = 0; /*0x168d82*/
  v24 = 0; /*0x168d84*/
  v23 = 0; /*0x168d8b*/
  for ( j = 0; v20 > j; ++j ) /*0x168d9a*/
  {
    v13 = *(_DWORD *)(v21 + 4 * j); /*0x168da3*/
    v14 = 0; /*0x168da9*/
    if ( (*(_BYTE *)(v13 + 77) & 1) == 0 ) /*0x168daf*/
    {
      v14 = *(_DWORD *)(v13 + 44); /*0x168db1*/
      v15 = 0; /*0x168db4*/
      while ( *(&active_threads + v15) != v13 ) /*0x168dc2*/
      {
        if ( ++v15 > 0 ) /*0x168dd3*/
          goto LABEL_26; /*0x168dd3*/
      }
      v14 = active_stacks[v15]; /*0x168dc4*/
    }
LABEL_26:
    if ( v14 ) /*0x168dd7*/
    {
      ++v11; /*0x168dd9*/
      if ( stack_check_usage ) /*0x168de1*/
      {
        for ( k = 0; k <= 0x3FC; ++k ) /*0x168de3*/
        {
          if ( *(_DWORD *)(v14 + 4 * k) != -559038737 ) /*0x168def*/
            break; /*0x168def*/
        }
        v17 = 4084 - 4 * k; /*0x168e03*/
        if ( v24 < v17 ) /*0x168e08*/
        {
          v24 = v17; /*0x168e0a*/
          v23 = *(_DWORD *)(v21 + 4 * j); /*0x168e10*/
        }
      }
    }
    thread_deallocate(v13); /*0x168e17*/
  }
  if ( v22 ) /*0x168e2d*/
    kfree(v21, v22); /*0x168e37*/
  *ltotal = v11; /*0x168e3f*/
  v18 = ~page_mask & (page_mask + 4084 * v11); /*0x168e56*/
  *space = v18; /*0x168e5b*/
  *resident = v18; /*0x168e60*/
  *maxusage = v24; /*0x168e68*/
  *maxstack = v23; /*0x168e70*/
  return 0; /*0x168e77*/
}
