
/* WARNING: Removing unreachable block (ram,0xf0086e10) */
/* WARNING: Removing unreachable block (ram,0xf0086df0) */
/* WARNING: Removing unreachable block (ram,0xf0086e04) */
/* WARNING: Removing unreachable block (ram,0xf0086e2c) */
/* WARNING: Removing unreachable block (ram,0xf0086da4) */

undefined8 _vm_object_cache_trim(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 unaff_l0;
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
    do {
    } while (_vm_cache_lock != 0);
    puVar2 = &_vm_cache_lock;
    _simple_lock_try();
  } while (puVar2 == (undefined4 *)0x0);
  if (_vm_cache_max < _vm_object_cached) {
    do {
      iVar1 = _vm_object_cached_list;
      _vm_cache_lock = 0;
      iVar3 = *(int *)(_vm_object_cached_list + 0x28);
      _vm_object_lookup();
      if (iVar1 != iVar3) {
        _panic(aVmObjectDeacti);
      }
      _vm_object_cache_object(iVar1,0);
      do {
        do {
        } while (_vm_cache_lock != 0);
        puVar2 = &_vm_cache_lock;
        _simple_lock_try();
      } while (puVar2 == (undefined4 *)0x0);
    } while (_vm_cache_max < _vm_object_cached);
  }
  _vm_cache_lock = 0;
  return CONCAT44(param_2,param_1);
}

