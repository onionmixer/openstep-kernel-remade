
/* WARNING: Removing unreachable block (ram,0xf00ce71c) */
/* WARNING: Removing unreachable block (ram,0xf00ce6fc) */
/* WARNING: Removing unreachable block (ram,0xf00ce6d0) */
/* WARNING: Removing unreachable block (ram,0xf00ce684) */
/* WARNING: Removing unreachable block (ram,0xf00ce638) */
/* WARNING: Removing unreachable block (ram,0xf00ce61c) */
/* WARNING: Removing unreachable block (ram,0xf00ce5f0) */
/* WARNING: Removing unreachable block (ram,0xf00ce5cc) */
/* WARNING: Removing unreachable block (ram,0xf00ce59c) */
/* WARNING: Removing unreachable block (ram,0xf00ce558) */
/* WARNING: Removing unreachable block (ram,0xf00ce4e4) */
/* WARNING: Removing unreachable block (ram,0xf00ce440) */
/* WARNING: Removing unreachable block (ram,0xf00ce41c) */
/* WARNING: Removing unreachable block (ram,0xf00ce408) */
/* WARNING: Removing unreachable block (ram,0xf00ce42c) */
/* WARNING: Removing unreachable block (ram,0xf00ce4c4) */
/* WARNING: Removing unreachable block (ram,0xf00ce520) */
/* WARNING: Removing unreachable block (ram,0xf00ce574) */
/* WARNING: Removing unreachable block (ram,0xf00ce5b4) */
/* WARNING: Removing unreachable block (ram,0xf00ce5e0) */
/* WARNING: Removing unreachable block (ram,0xf00ce608) */
/* WARNING: Removing unreachable block (ram,0xf00ce62c) */
/* WARNING: Removing unreachable block (ram,0xf00ce64c) */
/* WARNING: Removing unreachable block (ram,0xf00ce6bc) */
/* WARNING: Removing unreachable block (ram,0xf00ce6e4) */
/* WARNING: Removing unreachable block (ram,0xf00ce70c) */
/* WARNING: Removing unreachable block (ram,0xf00ce730) */
/* WARNING: Removing unreachable block (ram,0xf00ce3f0) */

undefined8
-[SCSIDisk SCSIDiskInit:targetId:lun:controller:]
          (int param_1,undefined *param_2,undefined4 param_3,undefined param_4,undefined param_5,
          undefined4 param_6)

{
  undefined uVar1;
  undefined uVar2;
  uint uVar3;
  undefined5 *puVar4;
  undefined (*pauVar5) [13];
  undefined (*pauVar6) [14];
  int iVar7;
  uint uVar8;
  byte bVar10;
  undefined7 *puVar9;
  undefined4 unaff_l0;
  undefined *puVar11;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined *puVar12;
  undefined4 unaff_l5;
  undefined *puVar13;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined *puVar14;
  undefined4 unaff_i0;
  undefined4 uVar15;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined *puVar16;
  undefined4 unaff_i3;
  undefined *puVar17;
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
  *(undefined4 *)(param_1 + 0x184) = param_6;
  *(undefined *)(param_1 + 0x188) = param_4;
  *(undefined *)(param_1 + 0x189) = param_5;
  _objc_msgSend(param_1,paSetunit,param_3);
  _sprintf((undefined *)((int)register0x00000038 + -200),&aSdD,param_3);
  _objc_msgSend(param_1,paSetname,(undefined *)((int)register0x00000038 + -200));
  _bzero((undefined *)((int)register0x00000038 + -0x58),0x41);
  iVar7 = param_1;
  _objc_msgSend(param_1,paSdinquiry,(undefined *)((int)register0x00000038 + -0x58));
  if (iVar7 == 0) {
    if ((*(byte *)((int)register0x00000038 + -0x58) & 0xe0) == 0) {
      uVar8 = *(byte *)((int)register0x00000038 + -0x58) & 0x1f;
      uVar3 = uVar8 - 7;
      if ((uVar8 < 6) && (uVar3 = uVar8, 3 < uVar8)) {
        bVar10 = *(byte *)((int)register0x00000038 + -0x58);
      }
      else {
        bVar10 = *(byte *)((int)register0x00000038 + -0x58);
        if (uVar3 != 0) {
          uVar15 = 1;
          goto locret_F00CE73C;
        }
      }
      *(byte *)(param_1 + 0x1bc) = bVar10 & 0x1f;
      if ((*(byte *)((int)register0x00000038 + -0x57) & 0x80) != 0) {
        _objc_msgSend(param_1,paSetremovable,1);
      }
      puVar14 = (undefined *)((int)register0x00000038 + -0x50);
      puVar16 = (undefined *)((int)register0x00000038 + -0xa8);
      puVar12 = puVar14;
      sub_F00CE270(puVar14,puVar16,8,0x50);
      puVar11 = puVar16 + (int)puVar12;
      if (puVar11[-1] != ' ') {
        puVar16[(int)puVar12] = 0x20;
        puVar11 = puVar11 + 1;
      }
      puVar13 = (undefined *)((int)register0x00000038 + -0x48);
      puVar12 = puVar13;
      sub_F00CE270(puVar13,puVar11,0x10,(int)puVar16 - (int)(puVar11 + -0x50));
      puVar11 = puVar11 + (int)puVar12;
      puVar12 = (undefined *)((int)register0x00000038 + -0x38);
      if (puVar11[-1] != ' ') {
        *puVar11 = 0x20;
        puVar11 = puVar11 + 1;
      }
      puVar17 = puVar12;
      sub_F00CE270(puVar12,puVar11,4,(int)puVar16 - (int)(puVar11 + -0x50));
      pauVar6 = paSetdrivename;
      puVar11[(int)puVar17] = 0;
      _objc_msgSend(param_1,paSetdrivename,puVar16);
      puVar4 = paName;
      puVar17 = (undefined *)((int)register0x00000038 + -0x118);
      uVar1 = *(undefined *)(param_1 + 0x188);
      param_2 = aTargetDLunDAtS;
      uVar2 = *(undefined *)(param_1 + 0x189);
      uVar15 = param_6;
      _objc_msgSend(param_6,paName);
      _sprintf(puVar17,aTargetDLunDAtS,uVar1,uVar2,uVar15);
      pauVar5 = paSetlocation;
      _objc_msgSend(param_1,paSetlocation,puVar17);
      _IOLog(&aSS,(undefined *)((int)register0x00000038 + -200),puVar16);
      _objc_msgSend(param_1,paUpdatereadysta);
      _objc_msgSend(param_1,paScsistartstopI,0,1);
      _objc_msgSend(param_1,paSetformattedin,0);
      _objc_msgSend(param_1,paUpdatephysical);
      _bzero(puVar16,0x50);
      sub_F00CE270(puVar14,puVar16,8,0x50);
      puVar11 = puVar16 + (int)puVar14;
      if (puVar11[-1] != ' ') {
        puVar16[(int)puVar14] = 0x20;
        puVar11 = puVar11 + 1;
      }
      sub_F00CE270(puVar13,puVar11,0x10,(int)puVar16 - (int)(puVar11 + -0x50));
      puVar11 = puVar11 + (int)puVar13;
      if (puVar11[-1] != ' ') {
        *puVar11 = 0x20;
        puVar11 = puVar11 + 1;
      }
      sub_F00CE270(puVar12,puVar11,0x20,(int)puVar16 - (int)(puVar11 + -0x50));
      puVar11[(int)puVar12] = 0;
      _objc_msgSend(param_1,pauVar6,puVar16);
      uVar1 = *(undefined *)(param_1 + 0x188);
      uVar2 = *(undefined *)(param_1 + 0x189);
      _objc_msgSend(param_6,puVar4);
      _sprintf(puVar17,aTargetDLunDAtS,uVar1,uVar2,param_6);
      _objc_msgSend(param_1,pauVar5,puVar17);
      *(int *)((int)register0x00000038 + -0x10) = param_1;
      puVar9 = &aIodisk;
      _objc_getOrigClass();
      *(undefined7 **)((int)register0x00000038 + -0xc) = puVar9;
      _objc_msgSendSuper((undefined *)((int)register0x00000038 + -0x10),paInit);
      uVar15 = 0;
    }
    else {
      uVar15 = 1;
    }
  }
  else {
    uVar15 = 3;
    if (iVar7 == 1) {
      uVar15 = 2;
    }
  }
locret_F00CE73C:
  return CONCAT44(param_2,uVar15);
}
