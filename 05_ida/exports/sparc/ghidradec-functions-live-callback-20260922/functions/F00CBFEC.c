
/* WARNING: Removing unreachable block (ram,0xf00cc0c8) */
/* WARNING: Removing unreachable block (ram,0xf00cc00c) */
/* WARNING: Removing unreachable block (ram,0xf00cc084) */
/* WARNING: Removing unreachable block (ram,0xf00cc0d8) */
/* WARNING: Removing unreachable block (ram,0xf00cbff8) */

undefined8 -[IOEthernet disableMulticast:](int param_1,undefined4 param_2,undefined *param_3)

{
  undefined6 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
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
  iVar2 = param_1;
  _objc_msgSend(param_1,paSearchmulti,param_3);
  if (iVar2 == 0) {
    uVar3 = *(undefined4 *)(param_1 + 0x138);
  }
  else {
    if (0 < *(int *)(iVar2 + 0x10)) {
      *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + -1;
    }
    if (*(int *)(iVar2 + 0x10) < 1) {
      iVar7 = *(int *)(iVar2 + 8);
      piVar6 = *(int **)(iVar2 + 0xc);
      iVar4 = iVar7;
      if (param_1 + 0x144 != iVar7) {
        iVar4 = iVar7 + 8;
      }
      *(int **)(iVar4 + 4) = piVar6;
      piVar5 = piVar6 + 2;
      if ((int *)(param_1 + 0x144) == piVar6) {
        piVar5 = piVar6;
      }
      *piVar5 = iVar7;
      _IOFree(iVar2,0x14);
      *(undefined *)(param_1 + 0x13c) = *param_3;
      *(undefined *)(param_1 + 0x13d) = param_3[1];
      *(undefined *)(param_1 + 0x13e) = param_3[2];
      *(undefined *)(param_1 + 0x13f) = param_3[3];
      *(undefined *)(param_1 + 0x140) = param_3[4];
      puVar1 = paSend;
      *(undefined *)(param_1 + 0x141) = param_3[5];
      _objc_msgSend(*(undefined4 *)(param_1 + 300),puVar1,8);
      uVar3 = *(undefined4 *)(param_1 + 0x138);
    }
    else {
      uVar3 = *(undefined4 *)(param_1 + 0x138);
    }
  }
  _objc_msgSend(uVar3,paUnlock);
  return CONCAT44(param_2,param_1);
}

