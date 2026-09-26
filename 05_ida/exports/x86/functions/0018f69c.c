/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18f69c. */
void __cdecl pmap_destroy(int a1)
{
  int v1; // ecx
  volatile __int32 *v2; // edx
  int v3; // edi
  _BYTE *v4; // eax
  _DWORD *v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // ebx
  int v8; // edx
  int v9; // eax

  if ( a1 ) /*0x18f6a7*/
  {
    v1 = splvm(); /*0x18f6b2*/
    v2 = (volatile __int32 *)(a1 + 12); /*0x18f6b4*/
    do /*0x18f6ca*/
    {
      while ( *v2 ) /*0x18f6b8*/
        ; /*0x18f6ba*/
    }
    while ( _InterlockedExchange(v2, 1) == 1 ); /*0x18f6ca*/
    v3 = *(_DWORD *)(a1 + 8) - 1; /*0x18f6cf*/
    *(_DWORD *)(a1 + 8) = v3; /*0x18f6d2*/
    _InterlockedExchange((volatile __int32 *)(a1 + 12), 0); /*0x18f6d8*/
    splx(v1); /*0x18f6dc*/
    if ( !v3 ) /*0x18f6e6*/
    {
      v4 = (_BYTE *)(*(_DWORD *)kernel_pmap + 4 * (*(_DWORD *)a1 >> 22)); /*0x18f6fc*/
      if ( (*v4 & 1) != 0 /*0x18f71c*/
        && (v5 = (_DWORD *)((*(_DWORD *)v4 & 0xFFFFF000) + ((*(_DWORD *)a1 >> 10) & 0xFFC))) != nullptr
        && (*(_BYTE *)v5 & 1) != 0 )
      {
        v6 = (*v5 & 0xFFFFF000) + (*(_DWORD *)a1 & 0xFFF); /*0x18f733*/
      }
      else
      {
        v6 = 0; /*0x18f71e*/
      }
      v7 = pg_desc_tbl + 20 * ((v6 - pg_first_phys) >> 12 >> (ptes_per_vm_page - 1)); /*0x18f750*/
      v8 = *(_DWORD *)(v7 + 12); /*0x18f753*/
      v9 = (unsigned __int16)(*(_WORD *)(v8 + 24))--; /*0x18f756*/
      if ( ptes_per_vm_page == v9 ) /*0x18f764*/
      {
        *(_DWORD *)v8 = pd_free_queue; /*0x18f76c*/
        *(_DWORD *)(v8 + 4) = &pd_free_queue; /*0x18f76e*/
        *(_DWORD *)(*(_DWORD *)v8 + 4) = v8; /*0x18f777*/
        pd_free_queue = v8; /*0x18f77a*/
        ++pd_free_count; /*0x18f780*/
      }
      *(_BYTE *)(v8 + 28) &= __ROL4__(-2, (unsigned int)(*(_DWORD *)a1 - *(_DWORD *)(v7 + 8)) >> 12); /*0x18f797*/
      zfree(pmap_zone, (_DWORD *)a1); /*0x18f7a2*/
    }
  }
}
