
undefined8 sub_F004D1B8(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar4;
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
  iVar3 = *param_1;
  iVar2 = *(int *)(iVar3 + 0x38);
  iVar1 = iVar3;
  if (iVar2 < param_2) {
    if (*(int *)(iVar3 + 0xc) != 0) {
      for (iVar2 = *(int *)(iVar3 + 0xc);
          ((iVar1 = iVar3, *(int *)(iVar3 + 0x38) <= *(int *)(iVar2 + 0x38) &&
           (*(int *)(iVar2 + 0x38) <= param_2)) && (iVar1 = iVar2, *(int *)(iVar2 + 0xc) != 0));
          iVar2 = *(int *)(iVar2 + 0xc)) {
        iVar3 = iVar2;
      }
    }
  }
  else {
    if (iVar2 < param_1[2]) {
      if (param_2 < iVar2) {
        iVar1 = 0;
        goto locret_F004D2A0;
      }
      iVar1 = *(int *)(iVar3 + 0xc);
    }
    else {
      bVar4 = true;
      if (*(int *)(iVar3 + 0xc) == 0) goto loc_F004D298;
      iVar2 = iVar3;
      for (iVar3 = *(int *)(iVar3 + 0xc); *(int *)(iVar2 + 0x38) <= *(int *)(iVar3 + 0x38);
          iVar3 = *(int *)(iVar3 + 0xc)) {
        if (*(int *)(iVar3 + 0xc) == 0) {
          iVar1 = *(int *)(iVar3 + 0xc);
          goto loc_F004D294;
        }
        iVar2 = iVar3;
      }
      iVar1 = *(int *)(iVar2 + 0xc);
      iVar3 = iVar2;
    }
loc_F004D294:
    while( true ) {
      bVar4 = iVar1 == 0;
      iVar1 = iVar3;
loc_F004D298:
      if ((bVar4) || (iVar3 = *(int *)(iVar1 + 0xc), param_2 < *(int *)(iVar3 + 0x38))) break;
      iVar1 = *(int *)(iVar3 + 0xc);
    }
  }
locret_F004D2A0:
  return CONCAT44(param_2,iVar1);
}
