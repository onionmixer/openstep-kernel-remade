
/* WARNING: Removing unreachable block (ram,0xf0038ac8) */
/* WARNING: Removing unreachable block (ram,0xf0038a30) */
/* WARNING: Removing unreachable block (ram,0xf0038a24) */
/* WARNING: Removing unreachable block (ram,0xf00389d8) */
/* WARNING: Removing unreachable block (ram,0xf0038a44) */
/* WARNING: Removing unreachable block (ram,0xf0038b1c) */
/* WARNING: Removing unreachable block (ram,0xf00389b0) */

undefined8 _udp_output(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 unaff_l0;
  int *piVar4;
  undefined4 unaff_l1;
  int iVar5;
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
  iVar5 = 0;
  iVar2 = param_1;
  for (piVar4 = (int *)param_2; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
    iVar2 = (int)*(sword *)(piVar4 + 2);
    iVar5 = iVar5 + iVar2;
  }
  _spltty();
  piVar4 = _mfree;
  if (_mfree == (int *)0x0) {
    piVar4 = (int *)0x0;
    _m_more(0,2);
  }
  else {
    if (*(sword *)((int)_mfree + 10) != 0) {
      _panic(&aMget_12);
    }
    *(undefined2 *)((int)piVar4 + 10) = 2;
    word_F0134B0C = word_F0134B0C + -1;
    DAT_f0134b10._0_2_ = DAT_f0134b10._0_2_ + 1;
    _mfree = (int *)*piVar4;
    piVar4[1] = 0xc;
    *piVar4 = 0;
  }
  _splx(iVar2);
  if (piVar4 == (int *)0x0) {
    _m_freem(param_2);
    piVar4 = (int *)0x37;
  }
  else {
    piVar4[1] = 0x60;
    *(undefined2 *)(piVar4 + 2) = 0x1c;
    iVar2 = piVar4[1];
    *piVar4 = param_2;
    param_2 = (int)piVar4 + iVar2;
    *(undefined4 *)(param_2 + 4) = 0;
    *(undefined4 *)((int)piVar4 + iVar2) = 0;
    *(undefined *)(param_2 + 8) = 0;
    *(undefined *)(param_2 + 9) = 0x11;
    *(sword *)(param_2 + 10) = (sword)iVar5 + 8;
    *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(param_1 + 0x14);
    *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_1 + 0xc);
    iVar2 = _udpcksum;
    *(undefined2 *)(param_2 + 0x14) = *(undefined2 *)(param_1 + 0x18);
    *(undefined2 *)(param_2 + 0x16) = *(undefined2 *)(param_1 + 0x10);
    *(undefined2 *)(param_2 + 0x18) = *(undefined2 *)(param_2 + 10);
    *(undefined2 *)(param_2 + 0x1a) = 0;
    if (iVar2 != 0) {
      piVar3 = piVar4;
      _in_cksum(piVar4,iVar5 + 0x1c);
      *(sword *)(param_2 + 0x1a) = (sword)piVar3;
      if (((uint)piVar3 & 0xffff) == 0) {
        *(undefined2 *)(param_2 + 0x1a) = 0xffff;
      }
    }
    uVar1 = _udp_ttl;
    *(sword *)(param_2 + 2) = (sword)iVar5 + 0x1c;
    *(char *)(param_2 + 8) = (char)uVar1;
    _ip_output(piVar4,*(undefined4 *)(param_1 + 0x38),param_1 + 0x24,
               *(word *)(*(int *)(param_1 + 0x1c) + 2) & 0x30 | 2,*(undefined4 *)(param_1 + 0x3c));
  }
  return CONCAT44(param_2,piVar4);
}

