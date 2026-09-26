
/* WARNING: Removing unreachable block (ram,0xf0005d9c) */
/* WARNING: Removing unreachable block (ram,0xf0005d7c) */
/* WARNING: Removing unreachable block (ram,0xf0005db0) */
/* WARNING: Removing unreachable block (ram,0xf0005d58) */
/* WARNING: Heritage AFTER dead removal. Example location: o1 : 0xf0005d9c */
/* WARNING: Restarted to delay deadcode elimination for space: register */

undefined4 __moddi3(uint param_1,undefined4 param_2)

{
  uint uVar1;
  sqword in_o0_1;
  undefined8 uVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 uVar4;
  undefined8 in_i0_1;
  sqword sVar5;
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
    *(int *)(in_CWP * 0x40 + 0x8000) = (int)((qword)in_i0_1 >> 0x20);
    *(int *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = (int)in_i0_1;
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
  uVar1 = (uint)((qword)in_o0_1 >> 0x20);
  iVar3 = 0;
  sVar5 = in_o0_1;
  if (in_o0_1 < 0) {
    iVar3 = -1;
    __negdi2(uVar1);
    sVar5 = (qword)uVar1 << 0x20;
  }
  uVar4 = (undefined4)((qword)sVar5 >> 0x20);
  if ((int)param_1 < 0) {
    __negdi2(param_1);
    param_1 = uVar1;
    param_2 = (int)in_o0_1;
  }
  __udivmoddi4(uVar4,(int)in_o0_1,param_1,param_2,(undefined *)((int)register0x00000038 + -0x10));
  uVar4 = (undefined4)((qword)*(undefined8 *)((int)register0x00000038 + -0x10) >> 0x20);
  if (iVar3 != 0) {
    uVar2 = *(undefined8 *)((int)register0x00000038 + -0x10);
    __negdi2((int)((qword)uVar2 >> 0x20));
    *(undefined8 *)((int)register0x00000038 + -0x10) = uVar2;
    uVar4 = (undefined4)((qword)*(undefined8 *)((int)register0x00000038 + -0x10) >> 0x20);
  }
  return uVar4;
}
