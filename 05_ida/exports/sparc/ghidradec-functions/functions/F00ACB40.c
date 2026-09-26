
sqword sub_F00ACB40(uint *param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  uint unaff_g3;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar4;
  undefined4 unaff_i3;
  uint uVar5;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar6;
  bool bVar7;
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
  uVar3 = *param_1;
  uVar4 = *(uint *)(param_3 + 0x80) >> 10 & 3;
  uVar5 = uVar3 >> 0x19 & 0xf;
  switch(uVar5) {
  case :
    unaff_g3 = 0;
    break;
  case :
    unaff_g3 = (uint)(uVar4 != 0);
    break;
  case :
    uVar4 = uVar4 - 1;
    goto loc_F00ACC20;
  case :
    if (uVar4 == 3) goto loc_F00ACCA8;
    bVar6 = true;
    if (uVar4 == 1) {
      unaff_g3 = 1;
      break;
    }
    goto loc_F00ACCB0;
  case :
    uVar4 = uVar4 ^ 1;
    goto loc_F00ACBDC;
  case :
    uVar4 = uVar4 - 2;
loc_F00ACC20:
    bVar6 = 1 < uVar4;
    goto loc_F00ACCB0;
  case :
    uVar4 = uVar4 ^ 2;
    goto loc_F00ACBDC;
  case :
    uVar4 = uVar4 ^ 3;
loc_F00ACBDC:
    unaff_g3 = (uint)(uVar4 == 0);
    break;
  case :
    goto loc_F00ACCA8;
  case :
    unaff_g3 = (uint)(uVar4 == 0);
    break;
  case :
    iVar2 = uVar4 - 3;
    goto loc_F00ACC4C;
  case :
    iVar2 = uVar4 - 2;
loc_F00ACC4C:
    if (iVar2 == 0) {
loc_F00ACCA8:
      unaff_g3 = 1;
    }
    else {
      bVar6 = true;
      if (uVar4 != 0) goto loc_F00ACCB0;
      unaff_g3 = 1;
    }
    break;
  case :
    uVar4 = uVar4 ^ 1;
    goto loc_F00ACC9C;
  case :
    bVar6 = 1 < uVar4;
    goto loc_F00ACCB0;
  case :
    uVar4 = uVar4 ^ 2;
    goto loc_F00ACC9C;
  case :
    uVar4 = uVar4 ^ 3;
loc_F00ACC9C:
    unaff_g3 = (uint)(uVar4 != 0);
  }
  bVar6 = unaff_g3 == 0;
loc_F00ACCB0:
  bVar7 = (uVar3 >> 0x19 & 0x10) == 0;
  if (bVar6) {
    if (!bVar7) {
      *(int *)(param_2 + 4) = *(int *)(param_2 + 8) + 4;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 8;
      goto locret_F00ACD28;
    }
    iVar2 = *(int *)(param_2 + 8);
    *(int *)(param_2 + 4) = *(int *)(param_2 + 8);
loc_F00ACD20:
    iVar2 = iVar2 + 4;
  }
  else {
    iVar2 = *(int *)(param_2 + 4);
    if (bVar7) {
      uVar1 = *(undefined4 *)(param_2 + 8);
    }
    else {
      if (uVar5 == 8) {
        iVar2 = iVar2 + ((int)(uVar3 << 10) >> 8);
        *(int *)(param_2 + 4) = iVar2;
        goto loc_F00ACD20;
      }
      uVar1 = *(undefined4 *)(param_2 + 8);
    }
    *(undefined4 *)(param_2 + 4) = uVar1;
    iVar2 = iVar2 + ((int)(uVar3 << 10) >> 8);
  }
  *(int *)(param_2 + 8) = iVar2;
locret_F00ACD28:
  return (qword)param_2 << 0x20;
}
