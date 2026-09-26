
/* WARNING: Removing unreachable block (ram,0xf00dd4b0) */
/* WARNING: Removing unreachable block (ram,0xf00dd4c4) */
/* WARNING: Removing unreachable block (ram,0xf00dd48c) */

undefined8
-[OutputStream completeRegion:descriptor:size:used:]
          (int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined (*pauVar1) [20];
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
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
  piVar2 = *(int **)(param_1 + 0x8c);
  if ((int *)(param_1 + 0x8c) == piVar2) {
loc_F00DD470:
    iVar3 = 0;
  }
  else {
    iVar3 = *piVar2;
    while (param_4 != iVar3) {
      piVar2 = (int *)piVar2[5];
      if ((int *)(param_1 + 0x8c) == piVar2) goto loc_F00DD470;
      iVar3 = *piVar2;
    }
    iVar3 = piVar2[1];
    iVar4 = piVar2[3];
    piVar2[1] = 0;
    *(int *)((int)register0x00000038 + -0x14) = piVar2[2];
    *(int *)((int)register0x00000038 + -0x18) = iVar4;
    *(int *)((int)register0x00000038 + -0x1c) = piVar2[4];
  }
  pauVar1 = paIncrementclipc;
  uVar5 = *(undefined4 *)((int)register0x00000038 + -0x1c);
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + iVar3;
  _objc_msgSend(*(undefined4 *)(param_1 + 4),pauVar1,uVar5);
  if (*(char *)(param_1 + 0x94) != '\0') {
    _audio_add_peak(*(undefined4 *)(param_1 + 0x9c),*(undefined4 *)((int)register0x00000038 + -0x14)
                    ,param_1 + 0xa4,*(undefined4 *)(param_1 + 0x98));
    _audio_add_peak(*(undefined4 *)(param_1 + 0xa0),*(undefined4 *)((int)register0x00000038 + -0x18)
                    ,param_1 + 0xa4,*(undefined4 *)(param_1 + 0x98));
  }
  return CONCAT44(param_2,param_1);
}

