/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001766f4 */

void _vm_map_copy_entry(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int local_8;
  
  if ((*(byte *)(param_3 + 0x18) & 4) != 0) {
    return;
  }
  if ((*(byte *)(param_4 + 0x18) & 4) != 0) {
    return;
  }
  if (*(short *)(param_4 + 0x28) != 0) {
    _vm_fault_unwire(param_2,param_4);
    *(undefined2 *)(param_4 + 0x28) = 0;
  }
  if (*(int *)(param_2 + 0x2c) == 0) {
    _vm_object_pmap_remove
              (*(undefined4 *)(param_4 + 0x10),*(int *)(param_4 + 0x14),
               (*(int *)(param_4 + 0xc) - *(int *)(param_4 + 8)) + *(int *)(param_4 + 0x14));
  }
  _pmap_remove(*(undefined4 *)(param_2 + 0x24),*(undefined4 *)(param_4 + 8),
               *(undefined4 *)(param_4 + 0xc));
  if (*(short *)(param_3 + 0x28) != 0) {
    _vm_fault_copy_entry(param_2,param_1,param_4,param_3);
    return;
  }
  if ((*(byte *)(param_3 + 0x18) & 0x40) == 0) {
    if (*(int *)(param_1 + 0x2c) == 0) {
      piVar3 = (int *)(param_1 + 0x34);
      do {
        do {
        } while (*piVar3 != 0);
        LOCK();
        iVar1 = *piVar3;
        *piVar3 = 1;
        UNLOCK();
      } while (iVar1 == 1);
      LOCK();
      *(undefined4 *)(param_1 + 0x34) = 0;
      UNLOCK();
      if (*(int *)(param_1 + 0x30) != 1) {
        _vm_object_pmap_copy
                  (*(undefined4 *)(param_3 + 0x10),*(int *)(param_3 + 0x14),
                   (*(int *)(param_3 + 0xc) - *(int *)(param_3 + 8)) + *(int *)(param_3 + 0x14));
        goto LAB_001767f1;
      }
    }
    _pmap_protect(*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_3 + 8),
                  *(undefined4 *)(param_3 + 0xc),*(uint *)(param_3 + 0x1c) & 0xfffffffd);
  }
LAB_001767f1:
  uVar2 = *(undefined4 *)(param_4 + 0x10);
  _vm_object_copy(*(undefined4 *)(param_3 + 0x10),*(undefined4 *)(param_3 + 0x14),
                  *(int *)(param_3 + 0xc) - *(int *)(param_3 + 8),param_4 + 0x10,param_4 + 0x14,
                  &local_8);
  if (local_8 != 0) {
    *(byte *)(param_3 + 0x18) = *(byte *)(param_3 + 0x18) | 0x40;
  }
  *(byte *)(param_4 + 0x18) = *(byte *)(param_4 + 0x18) | 0x40;
  *(byte *)(param_3 + 0x18) = *(byte *)(param_3 + 0x18) | 8;
  *(byte *)(param_4 + 0x18) = *(byte *)(param_4 + 0x18) | 8;
  if ((*(byte *)(param_3 + 0x1c) & 4) != 0) {
    *(uint *)(param_4 + 0x1c) = *(uint *)(param_4 + 0x1c) | *(uint *)(param_4 + 0x20) & 4;
  }
  _vm_object_deallocate(uVar2);
  _pmap_copy(*(undefined4 *)(param_2 + 0x24),*(undefined4 *)(param_1 + 0x24),*(int *)(param_4 + 8),
             *(int *)(param_4 + 0xc) - *(int *)(param_4 + 8),*(undefined4 *)(param_3 + 8));
  return;
}

