
/* WARNING: Removing unreachable block (ram,0xf00c6f54) */
/* WARNING: Removing unreachable block (ram,0xf00c702c) */
/* WARNING: Removing unreachable block (ram,0xf00c7004) */
/* WARNING: Removing unreachable block (ram,0xf00c6fc4) */
/* WARNING: Removing unreachable block (ram,0xf00c6f88) */
/* WARNING: Removing unreachable block (ram,0xf00c6f14) */
/* WARNING: Removing unreachable block (ram,0xf00c6f74) */
/* WARNING: Removing unreachable block (ram,0xf00c6f98) */
/* WARNING: Removing unreachable block (ram,0xf00c6ff4) */
/* WARNING: Removing unreachable block (ram,0xf00c7014) */
/* WARNING: Removing unreachable block (ram,0xf00c6fb0) */
/* WARNING: Removing unreachable block (ram,0xf00c6f64) */
/* WARNING: Removing unreachable block (ram,0xf00c6efc) */

undefined8
-[IOLogicalDisk _diskParamCommon:length:deviceOffset:bytesToMove:]
          (uint param_1,undefined4 param_2,uint param_3,int param_4,int *param_5,int *param_6)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
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
  uVar1 = param_1;
  _objc_msgSend(param_1,paName);
  iVar2 = *(int *)(param_1 + 0x184);
  _objc_msgSend(iVar2,paIsdiskready,1);
  if (iVar2 == -0x44e) {
    iVar2 = -0x44e;
  }
  else if (iVar2 == 0) {
    uVar3 = param_1;
    _objc_msgSend(param_1,paBlocksize);
    uVar4 = param_1;
    _objc_msgSend(param_1,paDisksize);
    iVar2 = param_4;
    urem(param_4,uVar3);
    if (iVar2 == 0) {
      udiv(param_4,uVar3);
      if ((uVar4 < param_3 + param_4) && (param_4 = uVar4 - param_3, uVar4 <= param_3)) {
        iVar2 = -0x2c2;
      }
      else {
        udiv(uVar3,*(undefined4 *)(param_1 + 0x18c));
        umul(param_4,uVar3);
        umul(param_3,uVar3);
        *param_5 = param_3 + *(int *)(param_1 + 0x188);
        umul(param_4,*(undefined4 *)(param_1 + 0x18c));
        *param_6 = param_4;
        iVar2 = 0;
      }
    }
    else {
      _IOLog(aSBytesRequeste,uVar1);
      iVar2 = -0x2c2;
    }
  }
  else {
    _objc_msgSend(param_1,paStringfromretu,iVar2);
    _IOLog(aSDevicerwcommo,uVar1,param_1);
  }
  return CONCAT44(param_2,iVar2);
}

