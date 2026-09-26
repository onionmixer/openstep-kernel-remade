
/* WARNING: Removing unreachable block (ram,0xf00cbfcc) */
/* WARNING: Removing unreachable block (ram,0xf00cbee4) */
/* WARNING: Removing unreachable block (ram,0xf00cbf24) */
/* WARNING: Removing unreachable block (ram,0xf00cbfdc) */
/* WARNING: Removing unreachable block (ram,0xf00cbed0) */

undefined8 -[IOEthernet enableMulticast:](int param_1,undefined4 param_2,byte *param_3)

{
  undefined4 uVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
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
  if ((*param_3 & 1) != 0) {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x138),paLock);
    iVar5 = param_1;
    _objc_msgSend(param_1,paSearchmulti,param_3);
    if (iVar5 == 0) {
      pbVar3 = (byte *)0x14;
      _IOMalloc();
      *pbVar3 = *param_3;
      pbVar3[1] = param_3[1];
      pbVar3[2] = param_3[2];
      pbVar3[3] = param_3[3];
      pbVar3[4] = param_3[4];
      pbVar3[5] = param_3[5];
      pbVar3[0x10] = 0;
      pbVar3[0x11] = 0;
      pbVar3[0x12] = 0;
      pbVar3[0x13] = 1;
      iVar5 = param_1 + 0x144;
      if (iVar5 == *(int *)(param_1 + 0x144)) {
        *(byte **)(param_1 + 0x144) = pbVar3;
        *(byte **)(param_1 + 0x148) = pbVar3;
        *(int *)(pbVar3 + 8) = iVar5;
        *(int *)(pbVar3 + 0xc) = iVar5;
      }
      else {
        iVar2 = *(int *)(param_1 + 0x148);
        *(int *)(pbVar3 + 0xc) = iVar2;
        *(int *)(pbVar3 + 8) = iVar5;
        *(byte **)(param_1 + 0x148) = pbVar3;
        *(byte **)(iVar2 + 8) = pbVar3;
      }
      *(byte *)(param_1 + 0x13c) = *param_3;
      *(byte *)(param_1 + 0x13d) = param_3[1];
      *(byte *)(param_1 + 0x13e) = param_3[2];
      *(byte *)(param_1 + 0x13f) = param_3[3];
      *(byte *)(param_1 + 0x140) = param_3[4];
      uVar1 = paSend;
      *(byte *)(param_1 + 0x141) = param_3[5];
      _objc_msgSend(*(undefined4 *)(param_1 + 300),uVar1,7);
    }
    else {
      iVar4 = *(int *)(iVar5 + 0x10);
      iVar2 = iVar4 + 1;
      *(int *)(iVar5 + 0x10) = iVar2;
      if (iVar2 < 0) {
        *(int *)(iVar5 + 0x10) = iVar4;
      }
    }
    _objc_msgSend(*(undefined4 *)(param_1 + 0x138),paUnlock);
  }
  return CONCAT44(param_2,param_1);
}
