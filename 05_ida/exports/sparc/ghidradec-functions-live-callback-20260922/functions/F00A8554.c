
/* WARNING: Removing unreachable block (ram,0xf00a8708) */
/* WARNING: Removing unreachable block (ram,0xf00a8650) */
/* WARNING: Removing unreachable block (ram,0xf00a8834) */
/* WARNING: Removing unreachable block (ram,0xf00a87a4) */
/* WARNING: Removing unreachable block (ram,0xf00a875c) */
/* WARNING: Removing unreachable block (ram,0xf00a8588) */
/* WARNING: Removing unreachable block (ram,0xf00a8698) */
/* WARNING: Removing unreachable block (ram,0xf00a877c) */
/* WARNING: Removing unreachable block (ram,0xf00a87bc) */
/* WARNING: Removing unreachable block (ram,0xf00a88b0) */
/* WARNING: Removing unreachable block (ram,0xf00a86d0) */
/* WARNING: Removing unreachable block (ram,0xf00a8900) */
/* WARNING: Removing unreachable block (ram,0xf00a8570) */

undefined8 _kernel_trap(uint param_1,int param_2,uint param_3,uint param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined uVar5;
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
  uint auStackX_4c [4];
  
  iVar1 = _active_threads;
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
  uVar5 = 0;
  auStackX_4c[0] = param_3;
  if (_active_threads == 0) {
    _printf(aKernelTrapCall);
    _badtrap(param_1,param_2,auStackX_4c[0],param_4,param_5);
  }
  if (param_1 == 9) {
loc_F00A8730:
    if (((_cpu == 0x80) && (iVar3 = 0, (param_4 >> 10 & 0xff) != 0)) &&
       (_ebe_handler(0,param_4,auStackX_4c[0],param_1,param_2), iVar3 != -1)) goto locret_F00A8908;
    _module_wkaround(auStackX_4c,param_2,param_5,param_4);
    if (_small_4m == 0) {
      _check_fsr(param_1,param_2,auStackX_4c[0],param_4,param_5);
    }
    _get_faulttype(param_1,param_2,auStackX_4c[0],param_4,param_5);
    if (iVar1 != 0) {
      uVar5 = *(undefined *)(dword_F0133DDC + 0x38);
      *(undefined *)(dword_F0133DDC + 0x38) = 0;
    }
    iVar3 = _kernel_map;
    if (auStackX_4c[0] < 0xf0000000) {
      iVar3 = *(int *)(*(int *)(iVar1 + 0xc) + 0xc);
    }
    uVar4 = 1;
    if (param_5 == 2) {
      uVar4 = 3;
    }
    _vm_fault(iVar3,auStackX_4c[0] & ~_page_mask,uVar4,0,0);
    if (iVar1 != 0) {
      *(undefined *)(dword_F0133DDC + 0x38) = uVar5;
    }
    if (iVar3 == 0) goto locret_F00A8908;
    uVar4 = 1;
    uVar2 = auStackX_4c[0];
    if (*(int *)(iVar1 + 0x74) != 0) {
                    /* WARNING: Subroutine does not return */
      *(undefined4 *)(iVar1 + 0x74) = 0;
      _longjmp();
    }
  }
  else if (param_1 < 10) {
    if (param_1 == 2) {
loc_F00A865C:
      uVar4 = 2;
      iVar3 = 2;
      uVar2 = *(uint *)(param_2 + 4);
    }
    else if (param_1 < 3) {
      if (param_1 != 1) goto loc_F00A8644;
loc_F00A86B0:
      if (_small_4m == 0) {
        _check_fsr(param_1,param_2,auStackX_4c[0],param_4,param_5);
      }
      if (((_cpu == 0x80) && (iVar1 = 0, (param_4 >> 10 & 0xff) != 0)) &&
         (_ebe_handler(0,param_4,auStackX_4c[0],param_1,param_2), iVar1 != -1))
      goto locret_F00A8908;
      uVar4 = 1;
      iVar3 = 0x301;
      uVar2 = auStackX_4c[0];
    }
    else if (param_1 == 7) {
      uVar4 = 1;
      iVar3 = 0x304;
      uVar2 = *(uint *)(param_2 + 4);
    }
    else {
      if (param_1 != 8) goto loc_F00A8644;
      if ((_tudebug != 0) && (_tudebugfpe != 0)) {
        _showregs(8,param_2,auStackX_4c[0],0,0);
      }
      uVar4 = 3;
      iVar3 = 8;
      uVar2 = auStackX_4c[0];
    }
  }
  else if (param_1 == 0x2b) {
    if (_small_4m == 0) {
      _check_fsr(0x2b,param_2,auStackX_4c[0],param_4,param_5);
    }
    uVar4 = 1;
    iVar3 = 0x306;
    uVar2 = auStackX_4c[0];
  }
  else {
    if (param_1 < 0x2c) {
      if (param_1 == 0x21) goto loc_F00A86B0;
      if (param_1 == 0x29) goto loc_F00A8730;
loc_F00A8644:
      _badtrap(param_1,param_2,auStackX_4c[0],param_4,param_5);
      goto loc_F00A865C;
    }
    if (param_1 == 0x81) {
      uVar4 = 6;
      iVar3 = 0x81;
      uVar2 = *(uint *)(param_2 + 4);
    }
    else {
      if (param_1 != 0x88) goto loc_F00A8644;
      uVar2 = *(uint *)(param_2 + 4);
      uVar4 = 6;
      iVar3 = 0x81;
      *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_2 + 8);
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 4;
    }
  }
  _kdp_raise_exception(uVar4,iVar3,uVar2,param_2);
locret_F00A8908:
  return CONCAT44(param_2,param_1);
}

