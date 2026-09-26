
/* WARNING: Removing unreachable block (ram,0xf00c66dc) */
/* WARNING: Removing unreachable block (ram,0xf00c66b8) */
/* WARNING: Removing unreachable block (ram,0xf00c6710) */
/* WARNING: Removing unreachable block (ram,0xf00c65e4) */

undefined8
-[IODisk getIntValues:forParameter:count:]
          (int param_1,undefined4 param_2,uint *param_3,int param_4,int *param_5)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 unaff_l0;
  int iVar4;
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
  undefined4 auStack_48 [18];
  
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
  iVar4 = *param_5;
  if (iVar4 == 0) {
    iVar4 = 0x200;
  }
  iVar1 = param_4;
  _strcmp(param_4,aIodiskstats);
  if (iVar1 == 0) {
    *(undefined4 *)((int)register0x00000038 + -0x48) = *(undefined4 *)(param_1 + 0x13c);
    *(undefined4 *)((int)register0x00000038 + -0x44) = *(undefined4 *)(param_1 + 0x140);
    *(undefined4 *)((int)register0x00000038 + -0x40) = *(undefined4 *)(param_1 + 0x144);
    *(undefined4 *)((int)register0x00000038 + -0x3c) = *(undefined4 *)(param_1 + 0x148);
    *(undefined4 *)((int)register0x00000038 + -0x38) = *(undefined4 *)(param_1 + 0x14c);
    *(undefined4 *)((int)register0x00000038 + -0x34) = *(undefined4 *)(param_1 + 0x150);
    *(undefined4 *)((int)register0x00000038 + -0x30) = *(undefined4 *)(param_1 + 0x154);
    *(undefined4 *)((int)register0x00000038 + -0x2c) = *(undefined4 *)(param_1 + 0x158);
    *(undefined4 *)((int)register0x00000038 + -0x28) = *(undefined4 *)(param_1 + 0x15c);
    *(undefined4 *)((int)register0x00000038 + -0x24) = *(undefined4 *)(param_1 + 0x160);
    *(undefined4 *)((int)register0x00000038 + -0x20) = *(undefined4 *)(param_1 + 0x164);
    iVar3 = 0;
    *(undefined4 *)((int)register0x00000038 + -0x1c) = *(undefined4 *)(param_1 + 0x168);
    puVar2 = (undefined *)((int)register0x00000038 + -8);
    *(undefined4 *)((int)register0x00000038 + -0x18) = *(undefined4 *)(param_1 + 0x16c);
    iVar1 = 0;
    *(undefined4 *)((int)register0x00000038 + -0x14) = *(undefined4 *)(param_1 + 0x170);
    *param_5 = 0;
    do {
      iVar3 = iVar3 + 1;
      if (*param_5 == iVar4) goto loc_F00C66D0;
      *(undefined4 *)(iVar1 + (int)param_3) = *(undefined4 *)(puVar2 + -0x40);
      puVar2 = puVar2 + 4;
      iVar1 = iVar1 + 4;
      *param_5 = *param_5 + 1;
    } while (iVar3 < 0xe);
    puVar2 = (undefined *)0x0;
  }
  else {
    iVar4 = param_4;
    _strcmp(param_4,aIoisadisk);
    if (iVar4 == 0) {
      *param_5 = 0;
loc_F00C66D0:
      puVar2 = (undefined *)0x0;
    }
    else {
      iVar4 = param_4;
      _strcmp(param_4,aIoisaphysicald);
      puVar2 = (undefined *)((int)register0x00000038 + -0x10);
      if (iVar4 == 0) {
        *param_5 = 1;
        puVar2 = (undefined *)0x0;
        *param_3 = (uint)(*(char *)(param_1 + 0x116) != '\0');
      }
      else {
        *(int *)((int)register0x00000038 + -0x10) = param_1;
        *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141ee8;
        _objc_msgSendSuper(puVar2,paGetintvaluesFo_0,param_3,param_4,param_5);
      }
    }
  }
  return CONCAT44(param_2,puVar2);
}
