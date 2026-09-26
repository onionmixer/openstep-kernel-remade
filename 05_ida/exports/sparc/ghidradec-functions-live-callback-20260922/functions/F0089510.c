
undefined8 _vm_page_wire(int *param_1,int param_2)

{
  int iVar1;
  sword sVar2;
  uint uVar3;
  int *piVar4;
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
  if (*(sword *)(param_1 + 7) == 0) {
    uVar3 = param_1[7];
    if ((uVar3 & 0x4000) != 0) {
      param_2 = *param_1;
      piVar4 = (int *)param_1[1];
      *(int **)(param_2 + 4) = piVar4;
      iVar1 = param_2;
      if (piVar4 != &_vm_page_queue_active) {
        *piVar4 = param_2;
        iVar1 = _vm_page_queue_active;
      }
      _vm_page_queue_active = iVar1;
      _vm_page_active_count = _vm_page_active_count + -1;
      param_1[7] = param_1[7] & 0xffffbfff;
      uVar3 = param_1[7];
    }
    if ((uVar3 & 0x8000) != 0) {
      param_2 = *param_1;
      piVar4 = (int *)param_1[1];
      *(int **)(param_2 + 4) = piVar4;
      iVar1 = param_2;
      if (piVar4 != &_vm_page_queue_inactive) {
        *piVar4 = param_2;
        iVar1 = _vm_page_queue_inactive;
      }
      _vm_page_queue_inactive = iVar1;
      _vm_page_inactive_count = _vm_page_inactive_count + -1;
      param_1[7] = param_1[7] & 0xffff7fff;
    }
    if ((param_1[7] & 0x1000U) != 0) {
      param_2 = *param_1;
      piVar4 = (int *)param_1[1];
      *(int **)(param_2 + 4) = piVar4;
      iVar1 = param_2;
      if (piVar4 != &_vm_page_queue_free) {
        *piVar4 = param_2;
        iVar1 = _vm_page_queue_free;
      }
      _vm_page_queue_free = iVar1;
      _vm_page_free_count = _vm_page_free_count + -1;
      param_1[7] = param_1[7] & 0xffffefff;
    }
    _vm_page_wire_count = _vm_page_wire_count + 1;
    sVar2 = *(sword *)(param_1 + 7);
  }
  else {
    sVar2 = *(sword *)(param_1 + 7);
  }
  *(sword *)(param_1 + 7) = sVar2 + 1;
  return CONCAT44(param_2,param_1);
}

