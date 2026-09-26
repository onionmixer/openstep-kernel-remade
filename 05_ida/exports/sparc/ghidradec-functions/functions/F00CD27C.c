
/* WARNING: Removing unreachable block (ram,0xf00cd2fc) */
/* WARNING: Removing unreachable block (ram,0xf00cd2a0) */
/* WARNING: Removing unreachable block (ram,0xf00cd2d0) */
/* WARNING: Removing unreachable block (ram,0xf00cd350) */
/* WARNING: Removing unreachable block (ram,0xf00cd28c) */

undefined8
-[IOSCSIController reserveSCSI3Target:lun:forOwner:]
          (int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
          undefined4 param_6)

{
  undefined8 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 uVar4;
  undefined4 unaff_l1;
  undefined4 uVar5;
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
  uVar5 = *(undefined4 *)((int)register0x00000038 + 0x5c);
  _objc_msgSend(*(undefined4 *)(param_1 + 0x22c),paLock);
  uVar4 = 0;
  iVar3 = param_1;
  _objc_msgSend(param_1,paNumberoftarget);
  if (param_4 < iVar3) {
    iVar3 = param_1;
    _objc_msgSend(param_1,paSearchreserveq,param_3,param_4,param_5,param_6);
    if (iVar3 == 0) {
      puVar1 = (undefined8 *)0x20;
      _IOMalloc();
      *puVar1 = CONCAT44(param_3,param_4);
      puVar1[1] = CONCAT44(param_5,param_6);
      *(undefined4 *)(puVar1 + 2) = uVar5;
      iVar3 = param_1 + 0x128;
      if (iVar3 == *(int *)(param_1 + 0x128)) {
        *(undefined8 **)(param_1 + 0x128) = puVar1;
        *(undefined8 **)(param_1 + 300) = puVar1;
        *(int *)((int)puVar1 + 0x14) = iVar3;
        *(int *)(puVar1 + 3) = iVar3;
      }
      else {
        iVar2 = *(int *)(param_1 + 300);
        *(int *)(puVar1 + 3) = iVar2;
        *(int *)((int)puVar1 + 0x14) = iVar3;
        *(undefined8 **)(param_1 + 300) = puVar1;
        *(undefined8 **)(iVar2 + 0x14) = puVar1;
      }
      *(int *)(param_1 + 0x228) = *(int *)(param_1 + 0x228) + 1;
    }
    else {
      uVar4 = 1;
    }
  }
  else {
    uVar4 = 1;
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x22c),paUnlock);
  return CONCAT44(param_2,uVar4);
}
