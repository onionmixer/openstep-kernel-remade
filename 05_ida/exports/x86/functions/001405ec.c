/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1405ec. */
_DWORD *new_inode()
{
  _DWORD *v0; // eax
  _DWORD *v1; // ebx

  v0 = (_DWORD *)zalloc(inode_zone); /*0x1405f7*/
  v1 = v0; /*0x1405fc*/
  if ( !v0 ) /*0x140603*/
    return nullptr; /*0x140658*/
  bzero(v0, 0xE8u); /*0x14060b*/
  *v1 = v1; /*0x140610*/
  v1[1] = v1; /*0x140612*/
  v1[23] = 0; /*0x140615*/
  v1[24] = 0; /*0x14061c*/
  v1[15] = v1; /*0x140623*/
  v1[10] = &ufs_vnodeops; /*0x140626*/
  v1[3] = 0; /*0x14062d*/
  vm_info_init(v1 + 3); /*0x140638*/
  *(_BYTE *)(v1[3] + 56) &= ~4u; /*0x140640*/
  v1[2] = inode_list; /*0x14064a*/
  inode_list = (int)v1; /*0x14064d*/
  return v1; /*0x14065a*/
}
