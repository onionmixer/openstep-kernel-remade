
/* WARNING: Removing unreachable block (ram,0xf00145c0) */
/* WARNING: Removing unreachable block (ram,0xf00145a8) */

undefined8 _logioctl(int param_1,int *param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
  undefined4 uVar2;
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
  if (param_1 == -0x7ffb8b8a) {
    dword_F0135188 = *param_2;
  }
  else if (param_1 < -0x7ffb8b89) {
    if (param_1 == -0x7ffb9983) {
      if (*param_2 == 0) {
        _logsoftc = _logsoftc & 0xfffffffb;
      }
      else {
        _logsoftc = _logsoftc | 4;
      }
    }
    else {
      if (param_1 != -0x7ffb9982) {
        uVar2 = 0xffffffff;
        goto locret_F0014650;
      }
      if (*param_2 == 0) {
        _logsoftc = _logsoftc & 0xfffffffd;
      }
      else {
        _logsoftc = _logsoftc | 2;
      }
    }
  }
  else if (param_1 == 0x4004667f) {
    _splusclock();
    iVar1 = *(int *)(_pmsgbuf + 4) - *(int *)(_pmsgbuf + 8);
    _splx();
    if (iVar1 < 0) {
      iVar1 = iVar1 + 0xff4;
    }
    *param_2 = iVar1;
  }
  else {
    if (param_1 != 0x40047477) {
      uVar2 = 0xffffffff;
      goto locret_F0014650;
    }
    *param_2 = dword_F0135188;
  }
  uVar2 = 0;
locret_F0014650:
  return CONCAT44(param_2,uVar2);
}
