
/* WARNING: Removing unreachable block (ram,0xf002a5f4) */
/* WARNING: Removing unreachable block (ram,0xf002a580) */
/* WARNING: Removing unreachable block (ram,0xf002a5c0) */
/* WARNING: Removing unreachable block (ram,0xf002a5dc) */
/* WARNING: Removing unreachable block (ram,0xf002a598) */
/* WARNING: Removing unreachable block (ram,0xf002a600) */
/* WARNING: Removing unreachable block (ram,0xf002a54c) */

undefined8 sub_F002A548(int param_1,sword param_2,sword param_3)

{
  int iVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  int iVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  int iVar4;
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
  iVar1 = param_1;
  _nb_map(param_1);
  iVar4 = (int)param_2;
  if (iVar4 < 0x201) {
    _nb_read(param_1,0xe,iVar4,(undefined *)((int)register0x00000038 + -0x208));
    _bcopy(iVar1 + iVar4 + 0x12,iVar1 + 0xe,(int)param_3);
    iVar3 = iVar1 + param_3 + 0xe;
    iVar2 = iVar4;
  }
  else {
    iVar2 = (int)param_3;
    _nb_read(param_1,iVar4 + 0x12,iVar2,(undefined *)((int)register0x00000038 + -0x208));
    iVar3 = iVar1 + 0xe;
    _bcopy(iVar3,iVar1 + iVar2 + 0xe,iVar4);
  }
  _bcopy((undefined *)((int)register0x00000038 + -0x208),iVar3,iVar2);
  _nb_shrink_bot(param_1,4);
  return CONCAT44(iVar4,param_1);
}

