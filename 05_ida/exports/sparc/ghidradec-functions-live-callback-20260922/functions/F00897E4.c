
/* WARNING: Removing unreachable block (ram,0xf00898b8) */

undefined8 _vm_page_activate(int *param_1,undefined4 param_2)

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
  uVar1 = param_1[7];
  if ((uVar1 & 0x8000) != 0) {
    iVar3 = *param_1;
    piVar2 = (int *)param_1[1];
    *(int **)(iVar3 + 4) = piVar2;
    if (piVar2 != &_vm_page_queue_inactive) {
      *piVar2 = iVar3;
      iVar3 = _vm_page_queue_inactive;
    }
    _vm_page_queue_inactive = iVar3;
    _vm_page_inactive_count = _vm_page_inactive_count + -1;
    param_1[7] = param_1[7] & 0xffff7fff;
    uVar1 = param_1[7];
  }
  if ((uVar1 & 0x1000) != 0) {
    iVar3 = *param_1;
    piVar2 = (int *)param_1[1];
    *(int **)(iVar3 + 4) = piVar2;
    if (piVar2 != &_vm_page_queue_free) {
      *piVar2 = iVar3;
      iVar3 = _vm_page_queue_free;
    }
    _vm_page_queue_free = iVar3;
    _vm_page_free_count = _vm_page_free_count + -1;
    param_1[7] = param_1[7] & 0xffffefff;
  }
  if (*(sword *)(param_1 + 7) == 0) {
    if ((param_1[7] & 0x4000U) != 0) {
      _panic(aVmPageActivate);
    }
    piVar2 = param_1;
    if ((int **)dword_F013CC0C != &_vm_page_queue_active) {
      *dword_F013CC0C = (int)param_1;
      piVar2 = _vm_page_queue_active;
    }
    _vm_page_queue_active = piVar2;
    param_1[1] = (int)dword_F013CC0C;
    *param_1 = (int)&_vm_page_queue_active;
    dword_F013CC0C = param_1;
    param_1[7] = param_1[7] | 0x4000;
    _vm_page_active_count = _vm_page_active_count + 1;
  }
  return CONCAT44(param_2,param_1);
}

