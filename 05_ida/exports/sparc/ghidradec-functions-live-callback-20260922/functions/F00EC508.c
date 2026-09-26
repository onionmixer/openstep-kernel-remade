
/* WARNING: Removing unreachable block (ram,0xf00ec590) */
/* WARNING: Removing unreachable block (ram,0xf00ec584) */

undefined8
+[Protocol _fixup:numElements:](undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  int iVar3;
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
  iVar3 = 0;
  if (0 < param_4) {
    do {
      if (*(int *)(param_3 + iVar3 * 0x14) < 2) {
        iVar2 = param_3 + iVar3 * 0x14;
        iVar1 = *(int *)(iVar2 + 8);
        if (iVar1 != 0) {
          *(int *)(iVar2 + 8) = iVar1 + -4;
        }
      }
      if ((*(int *)(param_3 + iVar3 * 0x14) == 0) &&
         (iVar1 = param_3 + iVar3 * 0x14, *(int *)(iVar1 + 8) != 0)) {
        __objc_inform(aUnableToInstal);
        __objc_inform(aProtocolSMustB,*(undefined4 *)(iVar1 + 4));
      }
      iVar1 = iVar3 * 0x14;
      iVar3 = iVar3 + 1;
      *(undefined4 *)(param_3 + iVar1) = param_1;
    } while (iVar3 < param_4);
  }
  return CONCAT44(param_2,param_1);
}

