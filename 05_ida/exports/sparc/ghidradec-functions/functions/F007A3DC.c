
/* WARNING: Removing unreachable block (ram,0xf007a46c) */

undefined8 sub_F007A3DC(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar4;
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
  iVar1 = *(int *)(param_2 + 0x4b4);
  iVar4 = -200;
  if (param_2 == 0) {
    iVar4 = -0x12f;
    goto locret_F007A490;
  }
  iVar2 = *(int *)(param_1 + 0xc);
  if (iVar2 == *(int *)(param_2 + 0x4ac)) {
    iVar4 = -0x12f;
loc_F007A478:
    iVar3 = iVar4 + 200;
  }
  else {
    if (iVar2 == *(int *)(param_2 + 0x4b0)) {
loc_F007A460:
      iVar4 = param_1;
      sub_F007A350(param_1,param_2 + iVar1 * 0x10 + 0x18c);
      goto loc_F007A478;
    }
    iVar1 = 0;
    iVar3 = param_2;
    do {
      if (*(int *)(iVar3 + 0x18c) == iVar2) break;
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x10;
    } while (iVar1 < 0x32);
    iVar3 = 0;
    if (iVar1 != 0x32) {
      *(int *)(param_2 + 0x4b0) = iVar2;
      *(int *)(param_2 + 0x4b4) = iVar1;
      goto loc_F007A460;
    }
  }
  if (iVar3 == 0) {
    iVar4 = -0x12f;
    *(undefined4 *)(param_2 + 0x4ac) = *(undefined4 *)(param_1 + 0xc);
  }
locret_F007A490:
  return CONCAT44(param_2,iVar4);
}
