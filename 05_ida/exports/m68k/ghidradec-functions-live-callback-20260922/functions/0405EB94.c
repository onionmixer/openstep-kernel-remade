
void _vm_map_copy_entry(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iStack_8;
  
  if (((*(byte *)(param_3 + 0x18) & 0x20) == 0) && ((*(byte *)(param_4 + 0x18) & 0x20) == 0)) {
    if (*(sword *)(param_4 + 0x26) != 0) {
      _vm_map_entry_unwire(param_2,param_4);
    }
    if (*(int *)(param_2 + 0x28) == 0) {
      _vm_object_pmap_remove
                (*(undefined4 *)(param_4 + 0x10),*(int *)(param_4 + 0x14),
                 (*(int *)(param_4 + 0xc) - *(int *)(param_4 + 8)) + *(int *)(param_4 + 0x14));
    }
    _pmap_remove(*(undefined4 *)(param_2 + 0x20),*(undefined4 *)(param_4 + 8),
                 *(undefined4 *)(param_4 + 0xc));
    if (*(sword *)(param_3 + 0x26) == 0) {
      if ((*(byte *)(param_3 + 0x18) & 2) == 0) {
        if ((*(int *)(param_1 + 0x28) == 0) && (*(int *)(param_1 + 0x2c) != 1)) {
          _vm_object_pmap_copy
                    (*(undefined4 *)(param_3 + 0x10),*(int *)(param_3 + 0x14),
                     (*(int *)(param_3 + 0xc) - *(int *)(param_3 + 8)) + *(int *)(param_3 + 0x14));
        }
        else {
          _pmap_protect(*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_3 + 8),
                        *(undefined4 *)(param_3 + 0xc),*(uint *)(param_3 + 0x1a) & 0xfffffffd);
        }
      }
      uVar1 = *(undefined4 *)(param_4 + 0x10);
      _vm_object_copy(*(undefined4 *)(param_3 + 0x10),*(undefined4 *)(param_3 + 0x14),
                      *(int *)(param_3 + 0xc) - *(int *)(param_3 + 8),param_4 + 0x10,param_4 + 0x14,
                      &iStack_8);
      if (iStack_8 != 0) {
        *(byte *)(param_3 + 0x18) = *(byte *)(param_3 + 0x18) | 2;
      }
      *(byte *)(param_4 + 0x18) = *(byte *)(param_4 + 0x18) | 2;
      *(byte *)(param_3 + 0x18) = *(byte *)(param_3 + 0x18) | 0x10;
      *(byte *)(param_4 + 0x18) = *(byte *)(param_4 + 0x18) | 0x10;
      if ((*(byte *)(param_3 + 0x1d) & 4) != 0) {
        *(uint *)(param_4 + 0x1a) = *(uint *)(param_4 + 0x1e) & 4 | *(uint *)(param_4 + 0x1a);
      }
      _vm_object_deallocate(uVar1);
      _pmap_copy(*(undefined4 *)(param_2 + 0x20),*(undefined4 *)(param_1 + 0x20),
                 *(int *)(param_4 + 8),*(int *)(param_4 + 0xc) - *(int *)(param_4 + 8),
                 *(undefined4 *)(param_3 + 8));
    }
    else {
      _vm_fault_copy_entry(param_2,param_1,param_4,param_3);
    }
  }
  return;
}

