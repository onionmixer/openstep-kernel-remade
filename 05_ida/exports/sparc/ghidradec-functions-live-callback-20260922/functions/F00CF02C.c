
/* WARNING: Removing unreachable block (ram,0xf00cf0c8) */
/* WARNING: Removing unreachable block (ram,0xf00cf0a4) */
/* WARNING: Removing unreachable block (ram,0xf00cf0d8) */
/* WARNING: Removing unreachable block (ram,0xf00cf040) */

undefined8 -[SCSIDisk enqueueSdBuf:](int param_1,undefined4 param_2,int param_3)

{
  undefined (*pauVar1) [12];
  int iVar2;
  int *piVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
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
  *(undefined4 *)(param_3 + 0x28) = 0xffffffff;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x1b8),paLock);
  piVar3 = (int *)(param_1 + 0x1b0);
  if (*(int *)(param_3 + 0x20) < 0) {
    piVar3 = (int *)(param_1 + 0x1a8);
  }
  if (piVar3 == (int *)*piVar3) {
    *piVar3 = param_3;
    piVar3[1] = param_3;
    *(int **)(param_3 + 0x2c) = piVar3;
    *(int **)(param_3 + 0x30) = piVar3;
  }
  else {
    iVar2 = piVar3[1];
    *(int *)(param_3 + 0x30) = iVar2;
    *(int **)(param_3 + 0x2c) = piVar3;
    piVar3[1] = param_3;
    *(int *)(iVar2 + 0x2c) = param_3;
  }
  pauVar1 = paUnlockwith;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x1b8),paUnlockwith,1);
  uVar4 = 0;
  if (*(int *)(param_3 + 0x18) == 0) {
    _objc_msgSend(*(undefined4 *)(param_3 + 0x1c),paLockwhen,1);
    _objc_msgSend(*(undefined4 *)(param_3 + 0x1c),pauVar1,0);
    uVar4 = *(undefined4 *)(param_3 + 0x28);
  }
  return CONCAT44(param_2,uVar4);
}

