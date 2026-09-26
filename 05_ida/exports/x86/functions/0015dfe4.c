/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15dfe4. */
int mfs_init()
{
  int result; // eax
  _BYTE v1[4]; // [esp+0h] [ebp-8h] BYREF
  _BYTE v2[4]; // [esp+4h] [ebp-4h] BYREF

  dword_1F64D4 = (int)&vm_info_queue; /*0x15dfea*/
  vm_info_queue = (int)&vm_info_queue; /*0x15dff4*/
  vm_info_lock_data = 0; /*0x15dffe*/
  lock_init(mfs_alloc_lock_data, 1); /*0x15e00f*/
  mfs_alloc_wanted = 0; /*0x15e014*/
  mfs_map = kmem_suballoc(kernel_map, v2, v1, mfs_map_size, 1); /*0x15e03b*/
  mfs_map_size = dword_1F6350; /*0x15e046*/
  if ( (unsigned int)dword_1F6350 > 0x1000000 ) /*0x15e055*/
    mfs_map_size = 0x1000000; /*0x15e057*/
  if ( !mfs_max_window ) /*0x15e068*/
    mfs_max_window = mfs_map_size / 0x14u; /*0x15e078*/
  if ( (unsigned int)mfs_max_window <= 0xFFFF ) /*0x15e087*/
    mfs_max_window = 0x10000; /*0x15e089*/
  result = zinit(60, 600000, 0x2000, 0, aVmInfoZone); /*0x15e0a6*/
  vm_info_zone = result; /*0x15e0ab*/
  return result; /*0x15e0b0*/
}
