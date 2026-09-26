/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001747d8 */

void _vm_map_deallocate(int param_1)

{
  int *piVar1;
  int iVar2;
  
  if (param_1 != 0) {
    piVar1 = (int *)(param_1 + 0x34);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar2 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    iVar2 = *(int *)(param_1 + 0x30);
    *(int *)(param_1 + 0x30) = iVar2 + -1;
    LOCK();
    *(undefined4 *)(param_1 + 0x34) = 0;
    UNLOCK();
    if (iVar2 == 1 || iVar2 + -1 < 0) {
      _lock_write(param_1);
      *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
      _vm_map_delete(param_1,*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x18));
      _pmap_destroy(*(undefined4 *)(param_1 + 0x24));
      _zfree(_vm_map_zone,param_1);
    }
  }
  return;
}

