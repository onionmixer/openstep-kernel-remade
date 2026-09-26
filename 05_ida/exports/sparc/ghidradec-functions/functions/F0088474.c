
/* WARNING: Removing unreachable block (ram,0xf0088554) */
/* WARNING: Removing unreachable block (ram,0xf0088530) */
/* WARNING: Removing unreachable block (ram,0xf008851c) */
/* WARNING: Removing unreachable block (ram,0xf008854c) */
/* WARNING: Removing unreachable block (ram,0xf0088574) */
/* WARNING: Removing unreachable block (ram,0xf00884e0) */

undefined8 _vm_policy_apply(int *param_1,int param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
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
  bool bVar4;
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
  uVar3 = 0;
  if (*(sword *)(param_1 + 6) < 3) {
loc_F00884B4:
    bVar4 = (param_3 & 2) == 0;
  }
  else {
    param_1 = (int *)param_1[10];
    bVar4 = (param_3 & 2) == 0;
    if ((param_1 != (int *)0x0) && (bVar4 = (param_3 & 2) == 0, *param_1 == 0)) {
      uVar3 = (uint)param_1[3] >> 0x1f ^ 1;
      goto loc_F00884B4;
    }
  }
  if ((bVar4) && (uVar3 != 0)) goto locret_F0088584;
  param_1 = &_vm_page_queue_lock;
  do {
    do {
    } while (_vm_page_queue_lock != 0);
    piVar1 = param_1;
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  if (param_3 == 0) {
    if ((*(uint *)(param_2 + 0x1c) & 0x400) == 0) {
      uVar3 = *(uint *)(param_2 + 0x1c);
loc_F008853C:
      if ((uVar3 & 0x4000) != 0) {
        _vm_page_deactivate(param_2);
      }
    }
    else {
      iVar2 = *(int *)(param_2 + 0x24);
      _pmap_is_modified();
      if (iVar2 != 0) {
        uVar3 = *(uint *)(param_2 + 0x1c);
        goto loc_F008853C;
      }
      sub_F008830C(param_2);
    }
    _pmap_remove_all(*(undefined4 *)(param_2 + 0x24));
  }
  else if ((param_3 == 1) && ((*(uint *)(param_2 + 0x1c) & 0x4000) != 0)) {
    _vm_page_deactivate(param_2);
  }
  _vm_page_queue_lock = 0;
locret_F0088584:
  return CONCAT44(param_2,param_1);
}
