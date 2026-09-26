/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x146cb0. */
_DWORD *ipc_hash_init()
{
  int v0; // ecx
  int v1; // eax
  _DWORD *result; // eax
  unsigned int v3; // edx
  unsigned int i; // ecx

  if ( !ipc_hash_global_size ) /*0x146cbb*/
  {
    ipc_hash_global_size = ipc_tree_entry_max >> 8; /*0x146cc5*/
    if ( (unsigned int)(ipc_tree_entry_max >> 8) <= 0x1F ) /*0x146ccd*/
      ipc_hash_global_size = 32; /*0x146ccf*/
  }
  ipc_hash_global_mask = ipc_hash_global_size - 1; /*0x146ce1*/
  if ( (ipc_hash_global_size & (ipc_hash_global_size - 1)) != 0 ) /*0x146ce9*/
  {
    v0 = 1; /*0x146ceb*/
    v1 = ipc_hash_global_size - 1; /*0x146cf0*/
    LOBYTE(v1) = (ipc_hash_global_size - 1) | 1; /*0x146cf2*/
    while ( 1 ) /*0x146d01*/
    {
      ipc_hash_global_mask = v1; /*0x146d01*/
      ipc_hash_global_size = v1 + 1; /*0x146d09*/
      if ( ((v1 + 1) & v1) == 0 ) /*0x146d11*/
        break; /*0x146d11*/
      v0 *= 2; /*0x146cf8*/
      v1 = v0 | ipc_hash_global_mask; /*0x146cff*/
    }
  }
  result = (_DWORD *)kalloc(8 * ipc_hash_global_size); /*0x146d21*/
  ipc_hash_global_table = (int)result; /*0x146d26*/
  v3 = 0; /*0x146d2b*/
  for ( i = ipc_hash_global_size; v3 < i; ++v3 ) /*0x146d35*/
  {
    *result = 0; /*0x146d38*/
    result[1] = 0; /*0x146d3e*/
    result += 2; /*0x146d45*/
  }
  return result; /*0x146d4d*/
}
