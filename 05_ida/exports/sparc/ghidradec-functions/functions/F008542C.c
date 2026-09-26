
/* WARNING: Removing unreachable block (ram,0xf00855f0) */
/* WARNING: Removing unreachable block (ram,0xf0085554) */
/* WARNING: Removing unreachable block (ram,0xf00854f0) */
/* WARNING: Removing unreachable block (ram,0xf00854a0) */
/* WARNING: Removing unreachable block (ram,0xf0085490) */
/* WARNING: Removing unreachable block (ram,0xf0085620) */
/* WARNING: Removing unreachable block (ram,0xf0085534) */
/* WARNING: Removing unreachable block (ram,0xf008557c) */
/* WARNING: Removing unreachable block (ram,0xf008560c) */
/* WARNING: Removing unreachable block (ram,0xf0085464) */

undefined8 _vm_map_copy_entry(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 unaff_l0;
  undefined4 uVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar4;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  if (((*(uint *)(param_3 + 0x18) & 0x20000000) == 0) &&
     ((*(uint *)(param_4 + 0x18) & 0x20000000) == 0)) {
    if (*(sword *)(param_4 + 0x28) != 0) {
      _vm_map_entry_unwire(param_2,param_4);
    }
    if (*(int *)(param_2 + 0x2c) == 0) {
      _vm_object_pmap_remove
                (*(undefined4 *)(param_4 + 0x10),*(int *)(param_4 + 0x14),
                 *(int *)(param_4 + 0x14) + (*(int *)(param_4 + 0xc) - *(int *)(param_4 + 8)));
      uVar1 = *(undefined4 *)(param_2 + 0x24);
    }
    else {
      uVar1 = *(undefined4 *)(param_2 + 0x24);
    }
    _pmap_remove(uVar1,*(undefined4 *)(param_4 + 8),*(undefined4 *)(param_4 + 0xc));
    if (*(sword *)(param_3 + 0x28) == 0) {
      if ((*(uint *)(param_3 + 0x18) & 0x2000000) == 0) {
        bVar4 = false;
        if (*(int *)(param_1 + 0x2c) == 0) {
          do {
            do {
            } while (*(int *)(param_1 + 0x34) != 0);
            piVar2 = (int *)(param_1 + 0x34);
            _simple_lock_try();
          } while (piVar2 == (int *)0x0);
          *(undefined4 *)(param_1 + 0x34) = 0;
          bVar4 = *(int *)(param_1 + 0x30) != 1;
        }
        if (bVar4) {
          _vm_object_pmap_copy
                    (*(undefined4 *)(param_3 + 0x10),*(int *)(param_3 + 0x14),
                     *(int *)(param_3 + 0x14) + (*(int *)(param_3 + 0xc) - *(int *)(param_3 + 8)));
          uVar1 = *(undefined4 *)(param_3 + 0x10);
        }
        else {
          _pmap_protect(*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_3 + 8),
                        *(undefined4 *)(param_3 + 0xc),*(uint *)(param_3 + 0x1c) & 0xfffffffd);
          uVar1 = *(undefined4 *)(param_3 + 0x10);
        }
      }
      else {
        uVar1 = *(undefined4 *)(param_3 + 0x10);
      }
      uVar3 = *(undefined4 *)(param_4 + 0x10);
      _vm_object_copy(uVar1,*(undefined4 *)(param_3 + 0x14),
                      *(int *)(param_3 + 0xc) - *(int *)(param_3 + 8),param_4 + 0x10,param_4 + 0x14,
                      (undefined *)((int)register0x00000038 + -0xc));
      if (*(int *)((int)register0x00000038 + -0xc) != 0) {
        *(uint *)(param_3 + 0x18) = *(uint *)(param_3 + 0x18) | 0x2000000;
      }
      *(uint *)(param_4 + 0x18) = *(uint *)(param_4 + 0x18) | 0x2000000;
      *(uint *)(param_3 + 0x18) = *(uint *)(param_3 + 0x18) | 0x10000000;
      *(uint *)(param_4 + 0x18) = *(uint *)(param_4 + 0x18) | 0x10000000;
      if ((*(uint *)(param_3 + 0x1c) & 4) != 0) {
        *(uint *)(param_4 + 0x1c) = *(uint *)(param_4 + 0x1c) | *(uint *)(param_4 + 0x20) & 4;
      }
      _vm_object_deallocate(uVar3);
      _pmap_copy(*(undefined4 *)(param_2 + 0x24),*(undefined4 *)(param_1 + 0x24),
                 *(int *)(param_4 + 8),*(int *)(param_4 + 0xc) - *(int *)(param_4 + 8),
                 *(undefined4 *)(param_3 + 8));
    }
    else {
      _vm_fault_copy_entry(param_2,param_1,param_4,param_3);
    }
  }
  return CONCAT44(param_2,param_1);
}
