
/* WARNING: Removing unreachable block (ram,0xf00869bc) */
/* WARNING: Removing unreachable block (ram,0xf00869a4) */
/* WARNING: Removing unreachable block (ram,0xf0086918) */
/* WARNING: Removing unreachable block (ram,0xf00869cc) */
/* WARNING: Removing unreachable block (ram,0xf00868f4) */

undefined8 _vm_object_deallocate(int param_1,undefined4 param_2)

{
  sword sVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  undefined4 unaff_l0;
  int iVar5;
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
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  do {
    if (param_1 == 0) {
locret_F00869E0:
      return CONCAT44(param_2,param_1);
    }
    do {
      do {
      } while (_vm_cache_lock != 0);
      puVar2 = &_vm_cache_lock;
      _simple_lock_try();
    } while (puVar2 == (undefined4 *)0x0);
    do {
      do {
      } while (*(int *)(param_1 + 0x10) != 0);
      piVar3 = (int *)(param_1 + 0x10);
      _simple_lock_try();
    } while (piVar3 == (int *)0x0);
    sVar1 = *(sword *)(param_1 + 0x18);
    *(sword *)(param_1 + 0x18) = sVar1 + -1;
    if (sVar1 != 1) {
      *(undefined4 *)(param_1 + 0x10) = 0;
      _vm_cache_lock = 0;
      goto locret_F00869E0;
    }
    uVar4 = *(uint *)(param_1 + 0x44);
    if ((uVar4 & 0x1000) != 0) {
      if (0 < *(sword *)(param_1 + 0x1a)) {
        iVar5 = param_1;
        if (unk_F013D41C != &_vm_object_cached_list) {
          unk_F013D41C[0x13] = param_1;
          iVar5 = _vm_object_cached_list;
        }
        _vm_object_cached_list = iVar5;
        *(undefined4 **)(param_1 + 0x50) = unk_F013D41C;
        *(int **)(param_1 + 0x4c) = &_vm_object_cached_list;
        _vm_object_cached = _vm_object_cached + 1;
        _vm_cache_lock = 0;
        iVar5 = param_1;
        unk_F013D41C = (undefined4 *)param_1;
        _vm_object_deactivate_pages();
        *(undefined4 *)(param_1 + 0x10) = 0;
        _vm_object_cache_trim();
        return CONCAT44(uVar4,iVar5);
      }
      *(uint *)(param_1 + 0x44) = uVar4 & 0xffffefff;
    }
    _vm_object_remove(*(undefined4 *)(param_1 + 0x28));
    _vm_cache_lock = 0;
    iVar5 = *(int *)(param_1 + 0x20);
    _vm_object_terminate(param_1);
    param_1 = iVar5;
  } while( true );
}
