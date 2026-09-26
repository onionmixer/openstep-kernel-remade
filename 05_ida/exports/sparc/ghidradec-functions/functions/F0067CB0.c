
/* WARNING: Removing unreachable block (ram,0xf0067cec) */
/* WARNING: Removing unreachable block (ram,0xf0067d54) */
/* WARNING: Removing unreachable block (ram,0xf0067cc8) */
/* WARNING: Removing unreachable block (ram,0xf0067d14) */
/* WARNING: Removing unreachable block (ram,0xf0067d3c) */

undefined8 __lookupd_port(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  int iVar2;
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
  iVar2 = *(int *)(_active_threads + 0xc);
  if (param_1 == 0) {
    *(int *)((int)register0x00000038 + -0xc) = _lookupd_port;
    if (_lookupd_port == 0) {
      *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
      param_1 = *(int *)((int)register0x00000038 + -0x14);
    }
    else {
      uVar3 = *(undefined4 *)(iVar2 + 0x88);
      iVar2 = _lookupd_port;
      _ipc_port_copy_send();
      _ipc_object_copyout(uVar3,iVar2,0x11,1,(undefined *)((int)register0x00000038 + -0x14));
      param_1 = *(int *)((int)register0x00000038 + -0x14);
    }
  }
  else {
    iVar1 = _active_threads;
    _suser();
    if (iVar1 == 0) {
      param_1 = 0;
    }
    else {
      iVar2 = *(int *)(iVar2 + 0x88);
      _ipc_object_copyin(iVar2,param_1,0x14,(undefined *)((int)register0x00000038 + -0xc));
      if (iVar2 == 0) {
        if (_lookupd_port == 0) {
          _lookupd_port = *(int *)((int)register0x00000038 + -0xc);
        }
        else {
          _ipc_port_release_send();
          _lookupd_port = *(int *)((int)register0x00000038 + -0xc);
        }
      }
      else {
        param_1 = 0;
      }
    }
  }
  return CONCAT44(param_2,param_1);
}
