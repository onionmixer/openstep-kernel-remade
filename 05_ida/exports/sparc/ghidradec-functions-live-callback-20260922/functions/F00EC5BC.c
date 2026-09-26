
/* WARNING: Removing unreachable block (ram,0xf00ec620) */
/* WARNING: Removing unreachable block (ram,0xf00ec638) */
/* WARNING: Removing unreachable block (ram,0xf00ec5d0) */

undefined8 -[Protocol conformsTo:](int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  uint uVar3;
  undefined4 unaff_l1;
  int iVar4;
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
  if (param_3 == 0) {
    uVar5 = 0;
  }
  else {
    iVar1 = *(int *)(param_3 + 4);
    _strcmp(iVar1,*(undefined4 *)(param_1 + 4));
    if (iVar1 == 0) {
loc_F00EC5E4:
      uVar5 = 1;
    }
    else {
      iVar1 = *(int *)(param_1 + 8);
      if (iVar1 != 0) {
        iVar4 = 0;
        if (*(int *)(iVar1 + 4) < 1) {
          uVar5 = 0;
          goto locret_F00EC668;
        }
        iVar2 = 0;
        do {
          uVar3 = *(uint *)(iVar2 + iVar1 + 8);
          iVar1 = *(int *)(param_3 + 4);
          _strcmp(iVar1,*(undefined4 *)(uVar3 + 4));
          if (iVar1 == 0) goto loc_F00EC5E4;
          _objc_msgSend(uVar3,paConformsto,param_3);
          iVar4 = iVar4 + 1;
          if ((uVar3 & 0xff) != 0) goto loc_F00EC5E4;
          iVar1 = *(int *)(param_1 + 8);
          iVar2 = iVar4 * 4;
        } while (iVar4 < *(int *)(iVar1 + 4));
      }
      uVar5 = 0;
    }
  }
locret_F00EC668:
  return CONCAT44(param_2,uVar5);
}

