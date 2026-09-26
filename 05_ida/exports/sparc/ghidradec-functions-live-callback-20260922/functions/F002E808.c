
undefined8 _in_lnaof(uint *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar3;
  undefined4 unaff_i1;
  uint uVar4;
  undefined4 unaff_i2;
  uint uVar5;
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
  uVar3 = *param_1;
  if ((uVar3 & 0x80000000) == 0) {
    uVar5 = uVar3 & 0xff000000;
    uVar4 = uVar3 & 0xffffff;
  }
  else {
    uVar4 = 0xc0000000;
    if ((uVar3 & 0xc0000000) == 0x80000000) {
      uVar5 = uVar3 & 0xffff0000;
      uVar4 = uVar3 & 0xffff;
    }
    else if ((uVar3 & 0xe0000000) == 0xc0000000) {
      uVar5 = uVar3 & 0xffffff00;
      uVar4 = uVar3 & 0xff;
    }
    else {
      if ((uVar3 & 0xf0000000) != 0xe0000000) goto locret_F002E8D4;
      uVar4 = uVar3 & 0xfffffff;
      uVar5 = 0xe0000000;
    }
  }
  uVar3 = uVar4;
  if (_in_ifaddr != 0) {
    uVar1 = *(uint *)(_in_ifaddr + 0x28);
    iVar2 = _in_ifaddr;
    while (uVar5 != uVar1) {
      iVar2 = *(int *)(iVar2 + 0x40);
      if (iVar2 == 0) goto locret_F002E8D4;
      uVar1 = *(uint *)(iVar2 + 0x28);
    }
    uVar3 = uVar4 & ~*(uint *)(iVar2 + 0x34);
  }
locret_F002E8D4:
  return CONCAT44(uVar4,uVar3);
}

