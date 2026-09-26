
/* WARNING: Removing unreachable block (ram,0xf0046708) */
/* WARNING: Removing unreachable block (ram,0xf0046674) */
/* WARNING: Removing unreachable block (ram,0xf0046630) */
/* WARNING: Removing unreachable block (ram,0xf00466c8) */
/* WARNING: Removing unreachable block (ram,0xf0046734) */
/* WARNING: Removing unreachable block (ram,0xf004660c) */

undefined8 sub_F00465F4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  sword sVar4;
  uint uVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
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
  *(undefined4 *)((int)register0x00000038 + 0x44) = param_1;
  *(undefined4 *)((int)register0x00000038 + 0x48) = param_2;
  *(undefined4 *)((int)register0x00000038 + 0x4c) = param_3;
  iVar1 = dword_F0133DDC + 0x28;
  _setjmp();
  if (iVar1 != 0) {
    sub_F0046758(**(int **)((int)register0x00000038 + 0x44),
                 *(uint *)((int)register0x00000038 + 0x48) & 0x4b,1,
                 *(undefined4 *)((int)register0x00000038 + 0x4c));
    uVar5 = 4;
    goto locret_F0046750;
  }
  iVar1 = *(int *)(**(int **)((int)register0x00000038 + 0x44) + 0x30);
  if ((*(uint *)((int)register0x00000038 + 0x48) & 1) == 0) {
loc_F004667C:
    uVar2 = *(uint *)((int)register0x00000038 + 0x48);
  }
  else {
    sVar4 = *(sword *)(iVar1 + 0x82) + 1;
    *(sword *)(iVar1 + 0x82) = sVar4;
    uVar2 = *(uint *)((int)register0x00000038 + 0x48);
    if (sVar4 == 1) {
      _wakeup(iVar1 + 0x82);
      goto loc_F004667C;
    }
  }
  if ((uVar2 & 2) == 0) {
loc_F00466D0:
    uVar2 = *(uint *)((int)register0x00000038 + 0x48);
  }
  else {
    if ((uVar2 & 4) == 0) {
      sVar4 = *(sword *)(iVar1 + 0x80);
    }
    else {
      if (*(sword *)(iVar1 + 0x82) == 0) {
        uVar5 = 6;
        goto locret_F0046750;
      }
      sVar4 = *(sword *)(iVar1 + 0x80);
    }
    *(sword *)(iVar1 + 0x80) = sVar4 + 1;
    uVar2 = *(uint *)((int)register0x00000038 + 0x48);
    if ((sword)(sVar4 + 1) == 1) {
      _wakeup(iVar1 + 0x80);
      goto loc_F00466D0;
    }
  }
  uVar3 = *(uint *)((int)register0x00000038 + 0x48);
  if ((uVar2 & 1) != 0) {
    sVar4 = *(sword *)(iVar1 + 0x80);
    while (uVar3 = *(uint *)((int)register0x00000038 + 0x48), sVar4 == 0) {
      if ((uVar3 & 4) != 0) {
        uVar5 = 0;
        goto locret_F0046750;
      }
      if (*(int *)(iVar1 + 0x7c) != 0) {
        uVar5 = 0;
        goto locret_F0046750;
      }
      _sleep(iVar1 + 0x80,0x1a);
      sVar4 = *(sword *)(iVar1 + 0x80);
    }
  }
  if ((uVar3 & 2) == 0) {
    uVar5 = 0;
  }
  else {
    sVar4 = *(sword *)(iVar1 + 0x82);
    while (sVar4 == 0) {
      _sleep(iVar1 + 0x82,0x1a);
      sVar4 = *(sword *)(iVar1 + 0x82);
    }
    uVar5 = 0;
  }
locret_F0046750:
  return CONCAT44(param_2,uVar5);
}

