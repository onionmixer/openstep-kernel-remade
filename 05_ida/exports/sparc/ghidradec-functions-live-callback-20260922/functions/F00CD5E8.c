
/* WARNING: Removing unreachable block (ram,0xf00cd6a8) */
/* WARNING: Removing unreachable block (ram,0xf00cd638) */
/* WARNING: Removing unreachable block (ram,0xf00cd624) */
/* WARNING: Removing unreachable block (ram,0xf00cd64c) */
/* WARNING: Removing unreachable block (ram,0xf00cd6dc) */
/* WARNING: Removing unreachable block (ram,0xf00cd608) */

undefined8
-[IOSCSIController getIntValues:forParameter:count:]
          (undefined4 param_1,undefined4 param_2,int param_3,int param_4,int *param_5)

{
  undefined4 uVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar5;
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
  undefined4 auStack_20 [8];
  
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
  iVar5 = *param_5;
  if (iVar5 == 0) {
    iVar5 = 0x200;
  }
  iVar3 = param_4;
  _strcmp(param_4,aIoscsicontroll_2);
  if (iVar3 == 0) {
    uVar1 = param_1;
    _objc_msgSend(param_1,paMaxqueuelength);
    *(undefined4 *)((int)register0x00000038 + -0x20) = uVar1;
    uVar1 = param_1;
    _objc_msgSend(param_1,paNumqueuesample);
    *(undefined4 *)((int)register0x00000038 + -0x1c) = uVar1;
    _objc_msgSend(param_1,paSumqueuelength);
    *(undefined4 *)((int)register0x00000038 + -0x18) = param_1;
    *param_5 = 0;
    iVar4 = 0;
    puVar2 = (undefined *)((int)register0x00000038 + -8);
    iVar3 = 0;
    do {
      iVar4 = iVar4 + 1;
      if (*param_5 == iVar5) goto loc_F00CD6F0;
      *(undefined4 *)(iVar3 + param_3) = *(undefined4 *)(puVar2 + -0x18);
      puVar2 = puVar2 + 4;
      iVar3 = iVar3 + 4;
      *param_5 = *param_5 + 1;
    } while (iVar4 < 3);
    puVar2 = (undefined *)0x0;
  }
  else {
    iVar5 = param_4;
    _strcmp(param_4,aIoisascsicontr);
    puVar2 = (undefined *)((int)register0x00000038 + -0x10);
    if (iVar5 == 0) {
      *param_5 = 0;
loc_F00CD6F0:
      puVar2 = (undefined *)0x0;
    }
    else {
      *(undefined4 *)((int)register0x00000038 + -0x10) = param_1;
      *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0142140;
      _objc_msgSendSuper(puVar2,paGetintvaluesFo_0,param_3,param_4,param_5);
    }
  }
  return CONCAT44(param_2,puVar2);
}

