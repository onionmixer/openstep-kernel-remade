/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12f48c. */
int rnode_cache_clear()
{
  int result; // eax
  int *v1; // ebx

  while ( 1 ) /*0x12f4db*/
  {
    v1 = (int *)rpfreelist; /*0x12f4db*/
    if ( !rpfreelist ) /*0x12f4e3*/
      break; /*0x12f4e3*/
    rpfreelist = *(void **)rpfreelist; /*0x12f49b*/
    sub_12F7D0(v1); /*0x12f4a1*/
    rp_rmhash(v1); /*0x12f4a7*/
    rinactive(v1); /*0x12f4ad*/
    mfs_uncache(v1 + 3); /*0x12f4b6*/
    zfree(vm_info_zone, v1[3]); /*0x12f4c6*/
    result = zfree(rnode_zone, v1); /*0x12f4d3*/
  }
  return result; /*0x12f4e5*/
}
