
/* WARNING: Removing unreachable block (ram,0xf0012504) */
/* WARNING: Removing unreachable block (ram,0xf00124ec) */
/* WARNING: Removing unreachable block (ram,0xf001246c) */

undefined8 _ureadc(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  int *piVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
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
  do {
    if (param_2[1] == 0) {
      _panic(&aUreadc);
      piVar3 = (int *)*param_2;
    }
    else {
      piVar3 = (int *)*param_2;
    }
    if (piVar3[1] < 1) {
      iVar1 = param_2[1];
    }
    else {
      if (0 < param_2[5]) break;
      iVar1 = param_2[1];
    }
    param_2[1] = iVar1 + -1;
    *param_2 = *param_2 + 8;
  } while( true );
  iVar1 = param_2[3];
  if (iVar1 == 1) {
    *(char *)*piVar3 = (char)param_1;
    iVar2 = *piVar3;
loc_F0012524:
    iVar1 = piVar3[1];
  }
  else if (iVar1 < 2) {
    iVar2 = *piVar3;
    if (iVar1 == 0) {
      _subyte(iVar2,param_1);
loc_F0012510:
      if (iVar2 < 0) {
        uVar4 = 0xe;
        goto locret_F0012554;
      }
      iVar2 = *piVar3;
      goto loc_F0012524;
    }
    iVar1 = piVar3[1];
  }
  else {
    iVar2 = *piVar3;
    if (iVar1 == 2) {
      _suibyte(iVar2,param_1);
      goto loc_F0012510;
    }
    iVar1 = piVar3[1];
  }
  *piVar3 = iVar2 + 1;
  piVar3[1] = iVar1 + -1;
  uVar4 = 0;
  param_2[5] = param_2[5] + -1;
  param_2[2] = param_2[2] + 1;
locret_F0012554:
  return CONCAT44(param_2,uVar4);
}
