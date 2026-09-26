
/* WARNING: Removing unreachable block (ram,0xf009a450) */
/* WARNING: Removing unreachable block (ram,0xf009a3e8) */

undefined8 sub_F009A388(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 *puVar5;
  undefined4 unaff_l1;
  undefined4 *puVar6;
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
  puVar6 = (undefined4 *)0x0;
  if (dword_F0131558 == (undefined4 *)0x0) {
loc_F009A3C0:
    if (dword_F0131554 == (undefined4 *)0x0) {
      if (dword_F0131558 != (undefined4 *)0x0) {
        _panic(aMbqStoreTooMan);
      }
      iVar1 = 8;
      iVar4 = -0xfecead4;
      iVar3 = 0x80;
      do {
        *(int *)(unk_F013149C + iVar3) = iVar4;
        iVar4 = iVar4 + -0x10;
        iVar1 = iVar1 + -1;
        iVar3 = iVar3 + -0x10;
      } while (-1 < iVar1);
      puVar2 = unk_F013149C;
      DAT_f01314a0._0_4_ = param_1;
    }
    else {
      dword_F0131554[1] = param_1;
      puVar2 = (undefined *)dword_F0131554;
    }
    *(undefined4 *)((int)puVar2 + 8) = param_2;
    *(int *)((int)puVar2 + 0xc) = param_3;
    dword_F0131554 = *(undefined4 **)puVar2;
    if (param_3 == 0) {
      _printf(aWarningMbCallb);
    }
    if (puVar6 == (undefined4 *)0x0) {
      *(undefined4 **)puVar2 = dword_F0131558;
      dword_F0131558 = (undefined4 *)puVar2;
    }
    else {
      *(undefined4 *)puVar2 = 0;
      *puVar6 = puVar2;
    }
    dword_F013153C = dword_F013153C + 1;
    dword_F0131550 = dword_F0131550 + 1;
    iVar1 = dword_F0131550;
    if (dword_F0131550 < (int)DAT_f0131540._8_4_) {
      iVar1 = DAT_f0131540._8_4_;
    }
  }
  else {
    iVar1 = dword_F0131558[1];
    puVar6 = dword_F0131558;
    while (iVar1 != param_1) {
      puVar5 = (undefined4 *)*puVar6;
      if (puVar5 == (undefined4 *)0x0) goto loc_F009A3C0;
      puVar6 = puVar5;
      iVar1 = puVar5[1];
    }
    DAT_f0131540._0_4_ = DAT_f0131540._0_4_ + 1;
    iVar1 = DAT_f0131540._8_4_;
  }
  DAT_f0131540._8_4_ = iVar1;
  return CONCAT44(param_2,param_1);
}

