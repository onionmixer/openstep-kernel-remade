
/* WARNING: Removing unreachable block (ram,0xf00c2108) */

undefined8 _MouseIntHandler(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  char cVar2;
  sword sVar3;
  char cVar4;
  char cVar5;
  sword sVar7;
  uint uVar6;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined8 in_o2_3;
  undefined8 uVar11;
  sword *psVar12;
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
  
  puVar10 = (undefined4 *)((qword)in_o2_3 >> 0x20);
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
  sVar3 = *(sword *)(puVar10 + 2);
  psVar12 = (sword *)*puVar10;
  sVar7 = sVar3 + 1;
  *(sword *)(puVar10 + 2) = sVar7;
  iVar8 = (int)sVar3;
  if (*psVar12 <= sVar7) {
    *(undefined2 *)(puVar10 + 2) = 0;
  }
  cVar5 = DAT_f0133022._0_1_;
  cVar4 = byte_F0133021;
  uVar9 = *(uint *)((int)register0x00000038 + -0x10);
  uVar6 = ((*(byte *)(psVar12 + iVar8 * 6 + 3) >> 2 ^ 1) & 1) << 0x18;
  *(uint *)((int)register0x00000038 + -0x10) = uVar9 & 0xfeffffff | uVar6;
  *(uint *)((int)register0x00000038 + -0x10) =
       uVar9 & 0xfcffffff | uVar6 | ((*(byte *)(psVar12 + iVar8 * 6 + 3) ^ 1) & 1) << 0x19;
  cVar1 = *(char *)(psVar12 + iVar8 * 6 + 2);
  *(char *)((int)register0x00000038 + -0xf) = cVar1;
  cVar2 = *(char *)((int)psVar12 + iVar8 * 0xc + 5);
  *(char *)((int)register0x00000038 + -0xe) = cVar2;
  if (dword_F0133028 == 0) {
    dword_F0133028 = 1;
    qword_F0133008 = *(undefined8 *)((int)register0x00000038 + -0x18);
    uVar11 = *(undefined8 *)((int)register0x00000038 + -0x10);
    DAT_f0133022._0_1_ = '\0';
    DAT_f0133010._1_1_ = (char)((qword)uVar11 >> 0x30);
    byte_F0133021 = '\0';
    DAT_f0133010._2_1_ = (char)((qword)uVar11 >> 0x28);
    DAT_f0133010._0_1_ = (undefined)((qword)uVar11 >> 0x38);
    DAT_f0133010._2_1_ = DAT_f0133010._2_1_ + cVar5;
    DAT_f0133010._3_5_ = (undefined5)uVar11;
    DAT_f0133010 = CONCAT26(CONCAT11(DAT_f0133010._0_1_,DAT_f0133010._1_1_ + cVar4),
                            CONCAT15(DAT_f0133010._2_1_,DAT_f0133010._3_5_));
    _IOGetTimestamp();
    dword_F0121134 = 1;
  }
  else {
    byte_F0133021 = byte_F0133021 + cVar1;
    DAT_f0133022._0_1_ = DAT_f0133022._0_1_ + cVar2;
  }
  return CONCAT44(param_2,param_1);
}
