
/* WARNING: Removing unreachable block (ram,0xf00cd398) */
/* WARNING: Removing unreachable block (ram,0xf00cd444) */
/* WARNING: Removing unreachable block (ram,0xf00cd3c0) */
/* WARNING: Removing unreachable block (ram,0xf00cd380) */
/* WARNING: Removing unreachable block (ram,0xf00cd3d8) */
/* WARNING: Removing unreachable block (ram,0xf00cd3f4) */
/* WARNING: Removing unreachable block (ram,0xf00cd460) */
/* WARNING: Removing unreachable block (ram,0xf00cd370) */

undefined8
-[IOSCSIController releaseSCSI3Target:lun:forOwner:]
          (int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
          undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined4 unaff_l0;
  int iVar6;
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
  iVar6 = *(int *)((int)register0x00000038 + 0x5c);
  _objc_msgSend(*(undefined4 *)(param_1 + 0x22c),paLock);
  iVar1 = param_1;
  _objc_msgSend(param_1,paNumberoftarget);
  if (param_4 < iVar1) {
    iVar1 = param_1;
    _objc_msgSend(param_1,paSearchreserveq,param_3,param_4,param_5,param_6);
    if (iVar1 == 0) {
      _IOLog(aIoscsicontroll_0);
      uVar2 = *(undefined4 *)(param_1 + 0x22c);
    }
    else if (*(int *)(iVar1 + 0x10) == iVar6) {
      iVar5 = *(int *)(iVar1 + 0x14);
      piVar4 = *(int **)(iVar1 + 0x18);
      iVar6 = iVar5;
      if (param_1 + 0x128 != iVar5) {
        iVar6 = iVar5 + 0x14;
      }
      *(int **)(iVar6 + 4) = piVar4;
      piVar3 = piVar4 + 5;
      if ((int *)(param_1 + 0x128) == piVar4) {
        piVar3 = piVar4;
      }
      *piVar3 = iVar5;
      _IOFree(iVar1,0x20);
      *(int *)(param_1 + 0x228) = *(int *)(param_1 + 0x228) + -1;
      uVar2 = *(undefined4 *)(param_1 + 0x22c);
    }
    else {
      _IOLog(aIoscsicontroll_1);
      uVar2 = *(undefined4 *)(param_1 + 0x22c);
    }
  }
  else {
    _IOLog(aIoscsicontroll);
    uVar2 = *(undefined4 *)(param_1 + 0x22c);
  }
  _objc_msgSend(uVar2,paUnlock);
  return CONCAT44(param_2,param_1);
}
