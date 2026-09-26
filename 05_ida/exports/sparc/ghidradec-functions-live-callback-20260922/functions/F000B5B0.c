
undefined8 _rewhence(int param_1,int param_2,int param_3)

{
  int iVar1;
  sword sVar2;
  int iVar3;
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
  sVar2 = *(sword *)(param_1 + 2);
  if ((sVar2 == 2) || (param_3 == 2)) {
    iVar1 = *(int *)(param_2 + 0x18);
    (**(code **)(*(int *)(iVar1 + 0x1c) + 0x14))
              (iVar1,(undefined *)((int)register0x00000038 + -0x48),
               *(undefined4 *)(_active_u + 0x1c));
    if (iVar1 != 0) goto locret_F000B694;
    sVar2 = *(sword *)(param_1 + 2);
  }
  if (sVar2 == 1) {
    iVar1 = *(int *)(param_1 + 4);
    iVar3 = *(int *)(param_2 + 0x1c);
loc_F000B648:
    *(int *)(param_1 + 4) = iVar1 + iVar3;
  }
  else {
    if (1 < sVar2) {
      if (sVar2 != 2) {
        iVar1 = 0x16;
        goto locret_F000B694;
      }
      iVar1 = *(int *)(param_1 + 4);
      iVar3 = *(int *)((int)register0x00000038 + -0x30);
      goto loc_F000B648;
    }
    if (sVar2 != 0) {
      iVar1 = 0x16;
      goto locret_F000B694;
    }
  }
  sVar2 = (sword)param_3;
  *(sword *)(param_1 + 2) = sVar2;
  if (sVar2 == 1) {
    iVar1 = *(int *)(param_1 + 4);
    iVar3 = *(int *)(param_2 + 0x1c);
  }
  else {
    if (sVar2 != 2) {
      iVar1 = 0;
      goto locret_F000B694;
    }
    iVar1 = *(int *)(param_1 + 4);
    iVar3 = *(int *)((int)register0x00000038 + -0x30);
  }
  *(int *)(param_1 + 4) = iVar1 - iVar3;
  iVar1 = 0;
locret_F000B694:
  return CONCAT44(param_2,iVar1);
}

