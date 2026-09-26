
/* WARNING: Removing unreachable block (ram,0xf00c9034) */
/* WARNING: Removing unreachable block (ram,0xf00c8fec) */
/* WARNING: Removing unreachable block (ram,0xf00c9008) */
/* WARNING: Removing unreachable block (ram,0xf00c9048) */
/* WARNING: Removing unreachable block (ram,0xf00c8fa4) */

undefined8
-[IODeviceDescription setMemoryRangeList:num:]
          (int param_1,undefined4 param_2,undefined4 *param_3,uint param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar5;
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
  uVar4 = 0xfffffd42;
  puVar1 = (undefined4 *)(param_4 << 3);
  _IOMalloc();
  uVar3 = 0;
  puVar2 = puVar1;
  if (param_4 != 0) {
    do {
      uVar3 = uVar3 + 1;
      *puVar2 = *param_3;
      puVar2[1] = param_3[1];
      param_3 = param_3 + 2;
      puVar2 = puVar2 + 2;
    } while (uVar3 < param_4);
  }
  iVar5 = param_1;
  _objc_msgSend(param_1,paDelegate);
  _objc_msgSend();
  if (iVar5 != 0) {
    iVar5 = *(int *)(param_1 + 0x10);
    if (*(int *)(iVar5 + 0xc) == 0) {
      *(undefined4 *)(iVar5 + 0xc) = 0;
    }
    else {
      _IOFree(*(undefined4 *)(iVar5 + 8),*(int *)(iVar5 + 0xc) << 3);
      *(undefined4 *)(iVar5 + 0xc) = 0;
    }
    uVar4 = 0;
  }
  _IOFree(puVar1,param_4 << 3);
  return CONCAT44(param_2,uVar4);
}
