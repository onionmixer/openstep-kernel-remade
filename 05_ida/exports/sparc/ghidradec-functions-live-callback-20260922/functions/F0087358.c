
/* WARNING: Removing unreachable block (ram,0xf00873e4) */
/* WARNING: Removing unreachable block (ram,0xf008738c) */

undefined8 _vm_object_lookup(uint param_1,undefined4 param_2)

{
  sword sVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 *puVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar6;
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
  puVar5 = (undefined4 *)(_vm_object_hashtable + (param_1 & 0x7f) * 8);
  do {
    do {
    } while (_vm_cache_lock != 0);
    puVar2 = &_vm_cache_lock;
    _simple_lock_try();
  } while (puVar2 == (undefined4 *)0x0);
  puVar2 = (undefined4 *)*puVar5;
  if (puVar5 == puVar2) {
loc_F008746C:
    iVar6 = 0;
  }
  else {
    iVar6 = puVar2[2];
    while (*(uint *)(iVar6 + 0x28) != param_1) {
      puVar2 = (undefined4 *)*puVar2;
      if (puVar5 == puVar2) goto loc_F008746C;
      iVar6 = puVar2[2];
    }
    do {
      do {
      } while (*(int *)(iVar6 + 0x10) != 0);
      piVar3 = (int *)(iVar6 + 0x10);
      _simple_lock_try();
    } while (piVar3 == (int *)0x0);
    if (*(sword *)(iVar6 + 0x18) == 0) {
      puVar5 = *(undefined4 **)(iVar6 + 0x4c);
      puVar4 = *(undefined4 **)(iVar6 + 0x50);
      puVar2 = puVar4;
      if ((undefined4 **)puVar5 != &_vm_object_cached_list) {
        puVar5[0x14] = puVar4;
        puVar2 = unk_F013D41C;
      }
      unk_F013D41C = puVar2;
      if ((undefined4 **)puVar4 != &_vm_object_cached_list) {
        puVar4[0x13] = puVar5;
        puVar5 = _vm_object_cached_list;
      }
      _vm_object_cached_list = puVar5;
      _vm_object_cached = _vm_object_cached + -1;
      sVar1 = *(sword *)(iVar6 + 0x18);
    }
    else {
      sVar1 = *(sword *)(iVar6 + 0x18);
    }
    *(undefined4 *)(iVar6 + 0x10) = 0;
    *(sword *)(iVar6 + 0x18) = sVar1 + 1;
  }
  _vm_cache_lock = 0;
  return CONCAT44(param_2,iVar6);
}

