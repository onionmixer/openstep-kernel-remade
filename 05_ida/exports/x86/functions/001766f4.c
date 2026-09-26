/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1766f4. */
void __cdecl vm_map_copy_entry(int a1, int a2, int a3, int a4)
{
  volatile __int32 *v4; // edx
  _BOOL4 v5; // edx
  int v6; // eax
  int v7; // [esp+Ch] [ebp-8h]
  int v8; // [esp+10h] [ebp-4h] BYREF

  if ( (*(_BYTE *)(a3 + 24) & 4) == 0 && (*(_BYTE *)(a4 + 24) & 4) == 0 ) /*0x176711*/
  {
    if ( *(_WORD *)(a4 + 40) ) /*0x176717*/
    {
      vm_fault_unwire(a2, a4); /*0x176723*/
      *(_WORD *)(a4 + 40) = 0; /*0x176728*/
    }
    if ( !*(_DWORD *)(a2 + 44) ) /*0x176734*/
      vm_object_pmap_remove( /*0x17674b*/
        *(_DWORD *)(a4 + 16),
        *(_DWORD *)(a4 + 20),
        *(_DWORD *)(a4 + 20) + *(_DWORD *)(a4 + 12) - *(_DWORD *)(a4 + 8));
    pmap_remove(*(_DWORD *)(a2 + 36), *(_DWORD *)(a4 + 8), *(_DWORD *)(a4 + 12)); /*0x176762*/
    if ( *(_WORD *)(a3 + 40) ) /*0x17676a*/
    {
      vm_fault_copy_entry(a2, a1, (_DWORD *)a4, a3); /*0x176876*/
    }
    else
    {
      if ( (*(_BYTE *)(a3 + 24) & 0x40) == 0 ) /*0x176779*/
      {
        if ( *(_DWORD *)(a1 + 44) ) /*0x17677e*/
          goto LABEL_14; /*0x17677e*/
        v4 = (volatile __int32 *)(a1 + 52); /*0x176786*/
        do /*0x17679e*/
        {
          while ( *v4 ) /*0x17678c*/
            ; /*0x17678e*/
        }
        while ( _InterlockedExchange(v4, 1) == 1 ); /*0x17679e*/
        v5 = *(_DWORD *)(a1 + 48) == 1; /*0x1767aa*/
        _InterlockedExchange((volatile __int32 *)(a1 + 52), 0); /*0x1767af*/
        if ( v5 ) /*0x1767b4*/
        {
LABEL_14:
          v6 = *(_DWORD *)(a3 + 28); /*0x1767b6*/
          LOBYTE(v6) = v6 & 0xFD; /*0x1767b9*/
          pmap_protect(*(_DWORD *)(a1 + 36), *(_DWORD *)(a3 + 8), *(_DWORD *)(a3 + 12), v6); /*0x1767cb*/
        }
        else
        {
          vm_object_pmap_copy( /*0x1767e9*/
            *(_DWORD *)(a3 + 16),
            *(_DWORD *)(a3 + 20),
            *(_DWORD *)(a3 + 20) + *(_DWORD *)(a3 + 12) - *(_DWORD *)(a3 + 8));
        }
      }
      v7 = *(_DWORD *)(a4 + 16); /*0x1767f4*/
      vm_object_copy( /*0x176812*/
        *(_DWORD *)(a3 + 16),
        *(_DWORD *)(a3 + 20),
        *(_DWORD *)(a3 + 12) - *(_DWORD *)(a3 + 8),
        a4 + 16,
        a4 + 20,
        &v8);
      if ( v8 ) /*0x17681e*/
        *(_BYTE *)(a3 + 24) |= 0x40u; /*0x176820*/
      *(_BYTE *)(a4 + 24) |= 0x40u; /*0x176824*/
      *(_BYTE *)(a3 + 24) |= 8u; /*0x176828*/
      *(_BYTE *)(a4 + 24) |= 8u; /*0x17682c*/
      if ( (*(_BYTE *)(a3 + 28) & 4) != 0 ) /*0x176834*/
        *(_DWORD *)(a4 + 28) |= *(_DWORD *)(a4 + 32) & 4; /*0x17683c*/
      vm_object_deallocate(v7); /*0x176843*/
      pmap_copy( /*0x176864*/
        *(_DWORD *)(a2 + 36),
        *(_DWORD *)(a1 + 36),
        *(_DWORD *)(a4 + 8),
        *(_DWORD *)(a4 + 12) - *(_DWORD *)(a4 + 8),
        *(_DWORD *)(a3 + 8));
    }
  }
}
