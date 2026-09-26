
/* WARNING: Removing unreachable block (ram,0xf00cc0c8) */
/* WARNING: Removing unreachable block (ram,0xf00cc00c) */
/* WARNING: Removing unreachable block (ram,0xf00cc084) */
/* WARNING: Removing unreachable block (ram,0xf00cc0d8) */
/* WARNING: Removing unreachable block (ram,0xf00cbff8) */

undefined8 -[IOEthernet disableMulticast:](int param_1,undefined4 param_2,undefined *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x138),paLock);
  iVar1 = param_1;
  _objc_msgSend(param_1,paSearchmulti,param_3);
  if (iVar1 == 0) {
    uVar2 = *(undefined4 *)(param_1 + 0x138);
  }
  else {
    if (0 < *(int *)(iVar1 + 0x10)) {
      *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + -1;
    }
    if (*(int *)(iVar1 + 0x10) < 1) {
      iVar6 = *(int *)(iVar1 + 8);
      piVar5 = *(int **)(iVar1 + 0xc);
      iVar3 = iVar6;
      if (param_1 + 0x144 != iVar6) {
        iVar3 = iVar6 + 8;
      }
      *(int **)(iVar3 + 4) = piVar5;
      piVar4 = piVar5 + 2;
      if ((int *)(param_1 + 0x144) == piVar5) {
        piVar4 = piVar5;
      }
      *piVar4 = iVar6;
      _IOFree(iVar1,0x14);
      *(undefined *)(param_1 + 0x13c) = *param_3;
      *(undefined *)(param_1 + 0x13d) = param_3[1];
      *(undefined *)(param_1 + 0x13e) = param_3[2];
      *(undefined *)(param_1 + 0x13f) = param_3[3];
      *(undefined *)(param_1 + 0x140) = param_3[4];
      uVar2 = paSend;
      *(undefined *)(param_1 + 0x141) = param_3[5];
      _objc_msgSend(*(undefined4 *)(param_1 + 300),uVar2,8);
      uVar2 = *(undefined4 *)(param_1 + 0x138);
    }
    else {
      uVar2 = *(undefined4 *)(param_1 + 0x138);
    }
  }
  _objc_msgSend(uVar2,paUnlock);
  return CONCAT44(param_2,param_1);
}
