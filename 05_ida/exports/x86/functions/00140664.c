/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x140664. */
_DWORD *inode_cache_clear()
{
  int v0; // esi
  _DWORD *result; // eax
  int v2; // ebx
  int v3; // ebx
  int v4; // edi
  int v5; // esi

  while ( 1 ) /*0x1406c7*/
  {
    v2 = ifreeh; /*0x1406c7*/
    if ( !ifreeh ) /*0x1406cf*/
      break; /*0x1406cf*/
    v0 = *(_DWORD *)(ifreeh + 92); /*0x14066c*/
    if ( v0 ) /*0x140671*/
      *(_DWORD *)(v0 + 96) = &ifreeh; /*0x140673*/
    ifreeh = v0; /*0x14067a*/
    *(_DWORD *)(v2 + 92) = 0; /*0x140680*/
    *(_DWORD *)(v2 + 96) = 0; /*0x140687*/
    mfs_uncache((int *)(v2 + 12)); /*0x140692*/
    *(_WORD *)(v2 + 68) = 0x8000; /*0x140697*/
    *(_BYTE *)(v2 + 68) |= 1u; /*0x1406a0*/
    if ( *(_WORD *)(v2 + 18) ) /*0x1406a4*/
      panic(aFreeInodeIsnT); /*0x1406b0*/
    *(_DWORD *)(*(_DWORD *)v2 + 4) = *(_DWORD *)(v2 + 4); /*0x1406bd*/
    result = *(_DWORD **)(v2 + 4); /*0x1406c0*/
    *result = *(_DWORD *)v2; /*0x1406c5*/
  }
  v3 = inode_list; /*0x1406d1*/
  v4 = inode_list; /*0x1406d7*/
  if ( inode_list ) /*0x1406db*/
  {
    do /*0x14072d*/
    {
      if ( *(__int16 *)(v3 + 68) >= 0 ) /*0x1406e5*/
      {
        v5 = *(_DWORD *)(v3 + 8); /*0x140724*/
        v4 = v3; /*0x140727*/
      }
      else
      {
        if ( v4 == v3 ) /*0x1406e9*/
        {
          inode_list = *(_DWORD *)(v3 + 8); /*0x1406ee*/
          v4 = inode_list; /*0x1406f3*/
        }
        else
        {
          *(_DWORD *)(v4 + 8) = *(_DWORD *)(v3 + 8); /*0x1406fb*/
        }
        v5 = *(_DWORD *)(v3 + 8); /*0x1406fe*/
        zfree(vm_info_zone, *(_DWORD *)(v3 + 12)); /*0x14070c*/
        result = (_DWORD *)zfree(inode_zone, v3); /*0x140719*/
      }
      v3 = v5; /*0x140729*/
    }
    while ( v5 ); /*0x14072d*/
  }
  return result; /*0x140732*/
}
