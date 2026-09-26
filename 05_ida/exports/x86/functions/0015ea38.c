/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15ea38. */
char __cdecl vmp_put(int a1)
{
  __int16 v1; // ax
  int v2; // eax
  char result; // al

  do /*0x15ea59*/
  {
    while ( vm_info_lock_data ) /*0x15ea47*/
      ; /*0x15ea45*/
  }
  while ( _InterlockedExchange(&vm_info_lock_data, 1) == 1 ); /*0x15ea59*/
  v1 = *(_WORD *)(a1 + 6); /*0x15ea5b*/
  *(_WORD *)(a1 + 6) = v1 - 1; /*0x15ea63*/
  if ( v1 == 1 ) /*0x15ea6b*/
  {
    v2 = dword_1F64D4; /*0x15ea6d*/
    if ( (int *)dword_1F64D4 == &vm_info_queue ) /*0x15ea77*/
      vm_info_queue = a1; /*0x15ea79*/
    else
      *(_DWORD *)(dword_1F64D4 + 40) = a1; /*0x15ea84*/
    *(_DWORD *)(a1 + 44) = v2; /*0x15ea87*/
    *(_DWORD *)(a1 + 40) = &vm_info_queue; /*0x15ea8a*/
    dword_1F64D4 = a1; /*0x15ea91*/
    *(_BYTE *)(a1 + 56) |= 1u; /*0x15ea97*/
    ++mfs_files_mapped; /*0x15ea9b*/
    ++vm_info_version; /*0x15eaa1*/
  }
  _InterlockedExchange(&vm_info_lock_data, 0); /*0x15eaa9*/
  lock_done(a1 + 24); /*0x15eab3*/
  if ( mfs_files_mapped > mfs_files_max ) /*0x15eac6*/
    mfs_cache_trim(); /*0x15eac8*/
  result = *(_BYTE *)(a1 + 56); /*0x15eacd*/
  if ( (result & 8) != 0 ) /*0x15ead2*/
  {
    *(_BYTE *)(a1 + 56) = result & 0xF7; /*0x15ead6*/
    return vmp_invalidate(a1); /*0x15eada*/
  }
  return result; /*0x15eadf*/
}
