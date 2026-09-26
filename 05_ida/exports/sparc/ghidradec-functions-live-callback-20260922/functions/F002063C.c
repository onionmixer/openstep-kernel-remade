
/* WARNING: Removing unreachable block (ram,0xf00207ac) */
/* WARNING: Removing unreachable block (ram,0xf0020720) */
/* WARNING: Removing unreachable block (ram,0xf0020714) */
/* WARNING: Removing unreachable block (ram,0xf00206c8) */
/* WARNING: Removing unreachable block (ram,0xf0020798) */
/* WARNING: Removing unreachable block (ram,0xf002086c) */
/* WARNING: Removing unreachable block (ram,0xf00206a0) */

undefined8 _sbappendaddr(word *param_1,undefined2 *param_2,int param_3,int param_4)

{
  word wVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l0;
  int *piVar5;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar6;
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
  iVar4 = 0x10;
  for (piVar5 = (int *)param_3; piVar5 != (int *)0x0; piVar5 = (int *)*piVar5) {
    iVar4 = iVar4 + *(sword *)(piVar5 + 2);
  }
  if (param_4 != 0) {
    iVar4 = iVar4 + *(sword *)(param_4 + 8);
  }
  uVar2 = (uint)*param_1;
  iVar3 = param_1[1] - uVar2;
  if ((int)((uint)param_1[3] - (uint)param_1[2]) < (int)(param_1[1] - uVar2)) {
    iVar3 = (uint)param_1[3] - (uint)param_1[2];
  }
  if (iVar3 < iVar4) {
    uVar6 = 0;
    goto locret_F0020878;
  }
  _spltty();
  piVar5 = _mfree;
  if (_mfree == (int *)0x0) {
    piVar5 = (int *)0x0;
    _m_more(0,8);
  }
  else {
    if (*(sword *)((int)_mfree + 10) != 0) {
      _panic(&aMget_6);
    }
    *(undefined2 *)((int)piVar5 + 10) = 8;
    word_F0134B0C = word_F0134B0C + -1;
    DAT_f0134b1c._0_2_ = DAT_f0134b1c._0_2_ + 1;
    _mfree = (int *)*piVar5;
    piVar5[1] = 0xc;
    *piVar5 = 0;
  }
  _splx(uVar2);
  if (piVar5 == (int *)0x0) {
loc_F00207B4:
    uVar6 = 0;
  }
  else {
    iVar4 = piVar5[1];
    *(undefined2 *)((int)piVar5 + iVar4) = *param_2;
    *(undefined2 *)((int)piVar5 + iVar4 + 2) = param_2[1];
    *(undefined2 *)((int)piVar5 + iVar4 + 4) = param_2[2];
    *(undefined2 *)((int)piVar5 + iVar4 + 6) = param_2[3];
    *(undefined2 *)((int)piVar5 + iVar4 + 8) = param_2[4];
    *(undefined2 *)((int)piVar5 + iVar4 + 10) = param_2[5];
    *(undefined2 *)((int)piVar5 + iVar4 + 0xc) = param_2[6];
    *(undefined2 *)((int)piVar5 + iVar4 + 0xe) = param_2[7];
    *(undefined2 *)(piVar5 + 2) = 0x10;
    if ((param_4 != 0) && (*(sword *)(param_4 + 8) != 0)) {
      _m_copy(param_4,0);
      *piVar5 = param_4;
      if (param_4 == 0) {
        _m_freem(piVar5);
        goto loc_F00207B4;
      }
      wVar1 = param_1[2];
      *param_1 = *param_1 + *(sword *)(param_4 + 8);
      param_1[2] = wVar1 + 0x80;
      if (0x7c < *(uint *)(*piVar5 + 4)) {
        param_1[2] = wVar1 + 0x480;
      }
    }
    wVar1 = param_1[2];
    *param_1 = *param_1 + *(sword *)(piVar5 + 2);
    param_1[2] = wVar1 + 0x80;
    if (0x7c < (uint)piVar5[1]) {
      param_1[2] = wVar1 + 0x480;
    }
    iVar4 = *(int *)(param_1 + 6);
    if (iVar4 == 0) {
      *(int **)(param_1 + 6) = piVar5;
    }
    else {
      iVar3 = *(int *)(iVar4 + 0x7c);
      while (iVar3 != 0) {
        iVar4 = *(int *)(iVar4 + 0x7c);
        iVar3 = *(int *)(iVar4 + 0x7c);
      }
      *(int **)(iVar4 + 0x7c) = piVar5;
    }
    if ((int *)*piVar5 != (int *)0x0) {
      piVar5 = (int *)*piVar5;
    }
    if (param_3 != 0) {
      _sbcompress(param_1,param_3,piVar5);
    }
    uVar6 = 1;
  }
locret_F0020878:
  return CONCAT44(param_2,uVar6);
}

