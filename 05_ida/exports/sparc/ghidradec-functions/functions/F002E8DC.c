
undefined8 _in_localaddr(uint *param_1)

{
  uint uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
  undefined4 unaff_i1;
  int iVar3;
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
  iVar3 = _in_ifaddr;
  if (_subnetsarelocal == 0) {
    if (_in_ifaddr == 0) {
      uVar2 = 0;
    }
    else {
      uVar1 = *(uint *)(_in_ifaddr + 0x34);
      while ((*param_1 & uVar1) != *(uint *)(iVar3 + 0x30)) {
        iVar3 = *(int *)(iVar3 + 0x40);
        if (iVar3 == 0) {
          uVar2 = 0;
          goto locret_F002E978;
        }
        uVar1 = *(uint *)(iVar3 + 0x34);
      }
      uVar2 = 1;
    }
  }
  else if (_in_ifaddr == 0) {
    uVar2 = 0;
  }
  else {
    uVar1 = *(uint *)(_in_ifaddr + 0x2c);
    while ((*param_1 & uVar1) != *(uint *)(iVar3 + 0x28)) {
      iVar3 = *(int *)(iVar3 + 0x40);
      if (iVar3 == 0) {
        uVar2 = 0;
        goto locret_F002E978;
      }
      uVar1 = *(uint *)(iVar3 + 0x2c);
    }
    uVar2 = 1;
  }
locret_F002E978:
  return CONCAT44(iVar3,uVar2);
}
