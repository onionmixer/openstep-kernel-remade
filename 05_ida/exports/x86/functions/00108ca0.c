/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x108ca0. */
int unmount_all()
{
  int v0; // ebx
  int v1; // esi
  int result; // eax

  proc_shutdown(); /*0x108ca5*/
  kill_tasks(); /*0x108caa*/
  mfs_cache_clear(); /*0x108caf*/
  vm_object_cache_clear(); /*0x108cb4*/
  fd_shutdown(); /*0x108cb9*/
  vm_object_shutdown(); /*0x108cbe*/
  vnode_pager_shutdown(); /*0x108cc3*/
  v0 = *(_DWORD *)rootvfs; /*0x108ccd*/
  if ( *(_DWORD *)rootvfs ) /*0x108ccd*/
  {
    do /*0x108d09*/
    {
      printf("unmounting %s ... ", (const char *)(v0 + 32)); /*0x108cdd*/
      v1 = *(_DWORD *)v0; /*0x108ce2*/
      if ( dounmount(v0) ) /*0x108ce5*/
        printf("FAILED\n"); /*0x108cf6*/
      else
        printf("done\n"); /*0x108cfd*/
      v0 = v1; /*0x108d05*/
    }
    while ( v1 ); /*0x108d09*/
  }
  vn_rele(rootdir); /*0x108d12*/
  result = dounmount(rootvfs); /*0x108d1e*/
  if ( result ) /*0x108d28*/
    return printf("Root unmount FAILED\n"); /*0x108d2f*/
  return result; /*0x108d37*/
}
