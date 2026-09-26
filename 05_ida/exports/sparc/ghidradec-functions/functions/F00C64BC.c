
/* WARNING: Removing unreachable block (ram,0xf00c651c) */
/* WARNING: Removing unreachable block (ram,0xf00c64f0) */

undefined8
-[IODisk addToBytesWritten:totalTime:latentTime:]
          (int param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5,
          undefined4 param_6)

{
  int iVar1;
  undefined8 in_l0_1;
  undefined8 uVar2;
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
    *(int *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = (int)((qword)in_l0_1 >> 0x20);
    *(int *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = (int)in_l0_1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  *(undefined4 *)((int)register0x00000038 + 0x58) = param_6;
  uVar2 = *(undefined8 *)((int)register0x00000038 + 0x58);
  *(int *)(param_1 + 0x154) = *(int *)(param_1 + 0x154) + 1;
  *(int *)(param_1 + 0x158) = *(int *)(param_1 + 0x158) + param_3;
  __udivdi3(param_4,param_5,0,1000000);
  iVar1 = (int)uVar2;
  *(int *)(param_1 + 0x15c) = *(int *)(param_1 + 0x15c) + param_5;
  __udivdi3((int)((qword)uVar2 >> 0x20),iVar1,0,1000000);
  *(int *)(param_1 + 0x160) = *(int *)(param_1 + 0x160) + iVar1;
  return CONCAT44(param_2,param_1);
}
