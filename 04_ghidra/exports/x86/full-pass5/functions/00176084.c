/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00176084 */

void _vm_map_entry_delete(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  if ((short)param_2[10] != 0) {
    _vm_fault_unwire(param_1,param_2);
    *(undefined2 *)(param_2 + 10) = 0;
  }
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + -1;
  *(int *)param_2[1] = *param_2;
  *(int *)(*param_2 + 4) = param_2[1];
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) - (param_2[3] - param_2[2]);
  if ((*(byte *)(param_2 + 6) & 5) == 0) {
    _vm_object_deallocate(param_2[4]);
  }
  else {
    iVar3 = param_2[4];
    if (iVar3 != 0) {
      piVar1 = (int *)(iVar3 + 0x34);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar2 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar2 == 1);
      iVar2 = *(int *)(iVar3 + 0x30);
      *(int *)(iVar3 + 0x30) = iVar2 + -1;
      LOCK();
      *(undefined4 *)(iVar3 + 0x34) = 0;
      UNLOCK();
      if (iVar2 == 1 || iVar2 + -1 < 0) {
        _lock_write(iVar3);
        *(int *)(iVar3 + 0x4c) = *(int *)(iVar3 + 0x4c) + 1;
        _vm_map_delete(iVar3,*(undefined4 *)(iVar3 + 0x14),*(undefined4 *)(iVar3 + 0x18));
        _pmap_destroy(*(undefined4 *)(iVar3 + 0x24));
        _zfree(_vm_map_zone,iVar3);
      }
    }
  }
  uVar4 = _vm_map_kentry_zone;
  if (*(int *)(param_1 + 0x20) != 0) {
    uVar4 = _vm_map_entry_zone;
  }
  _zfree(uVar4,param_2);
  return;
}

