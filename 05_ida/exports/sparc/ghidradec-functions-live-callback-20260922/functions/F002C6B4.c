
/* WARNING: Removing unreachable block (ram,0xf002c7d8) */
/* WARNING: Removing unreachable block (ram,0xf002c778) */
/* WARNING: Removing unreachable block (ram,0xf002c6d0) */
/* WARNING: Removing unreachable block (ram,0xf002c79c) */
/* WARNING: Removing unreachable block (ram,0xf002c7f4) */
/* WARNING: Removing unreachable block (ram,0xf002c6bc) */

undefined8 _raw_input(int param_1,undefined2 *param_2,undefined2 *param_3,undefined2 *param_4)

{
  int *piVar1;
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
  piVar2 = (int *)0x0;
  _m_get(0,2);
  if (piVar2 == (int *)0x0) {
    _m_freem(param_1);
  }
  else {
    *piVar2 = param_1;
    iVar3 = piVar2[1];
    *(undefined2 *)(piVar2 + 2) = 0x24;
    param_1 = (int)piVar2 + iVar3;
    *(undefined2 *)(param_1 + 4) = *param_4;
    *(undefined2 *)(param_1 + 6) = param_4[1];
    *(undefined2 *)(param_1 + 8) = param_4[2];
    *(undefined2 *)(param_1 + 10) = param_4[3];
    *(undefined2 *)(param_1 + 0xc) = param_4[4];
    *(undefined2 *)(param_1 + 0xe) = param_4[5];
    *(undefined2 *)(param_1 + 0x10) = param_4[6];
    *(undefined2 *)(param_1 + 0x12) = param_4[7];
    *(undefined2 *)(param_1 + 0x14) = *param_3;
    *(undefined2 *)(param_1 + 0x16) = param_3[1];
    *(undefined2 *)(param_1 + 0x18) = param_3[2];
    *(undefined2 *)(param_1 + 0x1a) = param_3[3];
    *(undefined2 *)(param_1 + 0x1c) = param_3[4];
    *(undefined2 *)(param_1 + 0x1e) = param_3[5];
    *(undefined2 *)(param_1 + 0x20) = param_3[6];
    *(undefined2 *)(param_1 + 0x22) = param_3[7];
    *(undefined2 *)((int)piVar2 + iVar3) = *param_2;
    *(undefined2 *)(param_1 + 2) = param_2[1];
    _spltty();
    if (dword_F0134168 < dword_F013416C) {
      piVar2[0x1f] = 0;
      piVar1 = piVar2;
      if (DAT_f0134164 != (int *)0x0) {
        DAT_f0134164[0x1f] = (int)piVar2;
        piVar1 = _rawintrq;
      }
      _rawintrq = piVar1;
      dword_F0134168 = dword_F0134168 + 1;
      DAT_f0134164 = piVar2;
    }
    else {
      _m_freem(piVar2);
    }
    _splx(param_1);
    _netisr = _netisr | 1;
    _wakeup(_soft_net_wakeup);
  }
  return CONCAT44(param_2,param_1);
}

