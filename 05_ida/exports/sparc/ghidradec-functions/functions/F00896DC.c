
/* WARNING: Removing unreachable block (ram,0xf008979c) */
/* WARNING: Removing unreachable block (ram,0xf00896f4) */

undefined8 _vm_page_deactivate(int *param_1,undefined4 param_2)

{
  uint uVar1;
  int *piVar2;
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
  if ((param_1[7] & 0x4000U) == 0) goto locret_F00897DC;
  _pmap_clear_reference(param_1[9]);
  iVar3 = *param_1;
  piVar2 = (int *)param_1[1];
  *(int **)(iVar3 + 4) = piVar2;
  if (piVar2 != &_vm_page_queue_active) {
    *piVar2 = iVar3;
    iVar3 = _vm_page_queue_active;
  }
  _vm_page_queue_active = iVar3;
  piVar2 = param_1;
  if ((int **)dword_F013C22C != &_vm_page_queue_inactive) {
    *dword_F013C22C = (int)param_1;
    piVar2 = _vm_page_queue_inactive;
  }
  _vm_page_queue_inactive = piVar2;
  param_1[1] = (int)dword_F013C22C;
  *param_1 = (int)&_vm_page_queue_inactive;
  dword_F013C22C = param_1;
  param_1[7] = param_1[7] & 0xffffbfffU | 0x8000;
  _vm_page_active_count = _vm_page_active_count + -1;
  _vm_page_inactive_count = _vm_page_inactive_count + 1;
  if ((param_1[7] & 0x400U) == 0) {
loc_F00897B8:
    uVar1 = param_1[7];
  }
  else {
    iVar3 = param_1[9];
    _pmap_is_modified();
    uVar1 = param_1[7];
    if (iVar3 != 0) {
      param_1[7] = uVar1 & 0xfffffbff;
      goto loc_F00897B8;
    }
  }
  param_1[7] = uVar1 & 0xffffdfff | ((uVar1 >> 10 ^ 1) & 1) << 0xd;
locret_F00897DC:
  return CONCAT44(param_2,param_1);
}
