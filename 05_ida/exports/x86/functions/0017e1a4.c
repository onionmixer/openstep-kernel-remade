/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17e1a4. */
int vnode_pager_init()
{
  int result; // eax

  result = zinit(24, 240000, page_size, 0, aVnodePagerStru); /*0x17e1bc*/
  vstruct_zone = result; /*0x17e1c1*/
  vstruct_lock = 0; /*0x17e1c6*/
  dword_1E728C = (int)&dword_1E7288; /*0x17e1d0*/
  dword_1E7288 = (int)&dword_1E7288; /*0x17e1da*/
  return result; /*0x17e1e6*/
}
