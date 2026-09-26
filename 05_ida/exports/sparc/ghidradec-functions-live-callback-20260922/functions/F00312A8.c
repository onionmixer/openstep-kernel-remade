
/* WARNING: Removing unreachable block (ram,0xf0031894) */
/* WARNING: Removing unreachable block (ram,0xf0031768) */
/* WARNING: Removing unreachable block (ram,0xf003172c) */
/* WARNING: Removing unreachable block (ram,0xf0031704) */
/* WARNING: Removing unreachable block (ram,0xf003154c) */
/* WARNING: Removing unreachable block (ram,0xf00315ac) */
/* WARNING: Removing unreachable block (ram,0xf003157c) */
/* WARNING: Removing unreachable block (ram,0xf00315dc) */
/* WARNING: Removing unreachable block (ram,0xf0031850) */
/* WARNING: Removing unreachable block (ram,0xf0031814) */
/* WARNING: Removing unreachable block (ram,0xf0031784) */
/* WARNING: Removing unreachable block (ram,0xf0031360) */
/* WARNING: Removing unreachable block (ram,0xf0031800) */
/* WARNING: Removing unreachable block (ram,0xf0031838) */
/* WARNING: Removing unreachable block (ram,0xf0031858) */
/* WARNING: Removing unreachable block (ram,0xf0031568) */
/* WARNING: Removing unreachable block (ram,0xf0031598) */
/* WARNING: Removing unreachable block (ram,0xf00315b8) */
/* WARNING: Removing unreachable block (ram,0xf0031680) */
/* WARNING: Removing unreachable block (ram,0xf003170c) */
/* WARNING: Removing unreachable block (ram,0xf0031740) */
/* WARNING: Removing unreachable block (ram,0xf0031774) */
/* WARNING: Removing unreachable block (ram,0xf0031888) */
/* WARNING: Removing unreachable block (ram,0xf0031314) */

undefined8 _icmp_input(int param_1,undefined4 *param_2)

{
  sword sVar1;
  uint uVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 unaff_l0;
  int iVar8;
  undefined4 unaff_l1;
  uint uVar9;
  undefined4 uVar10;
  byte *pbVar11;
  undefined4 unaff_l3;
  int iVar12;
  undefined4 uVar13;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  int iVar14;
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
  uVar9 = (uint)*(sword *)(param_1 + *(int *)(param_1 + 4) + 2);
  uVar2 = *(byte *)(param_1 + *(int *)(param_1 + 4)) & 0xf;
  iVar12 = uVar2 * 4;
  if ((int)uVar9 < 8) {
    DAT_f01365bc._0_4_ = DAT_f01365bc._0_4_ + 1;
loc_F0031894:
    _m_freem(param_1);
    goto locret_F003189C;
  }
  iVar7 = iVar12 + uVar9;
  if (0x23 < uVar9) {
    iVar7 = iVar12 + 0x24;
  }
  if (((0x7c < *(uint *)(param_1 + 4)) || (*(sword *)(param_1 + 8) < iVar7)) &&
     (_m_pullup(), param_1 == 0)) {
    DAT_f01365bc._0_4_ = DAT_f01365bc._0_4_ + 1;
    goto locret_F003189C;
  }
  iVar14 = param_1 + *(int *)(param_1 + 4);
  *(sword *)(param_1 + 8) = *(sword *)(param_1 + 8) + (sword)uVar2 * -4;
  iVar8 = *(int *)(param_1 + 4) + iVar12;
  *(int *)(param_1 + 4) = iVar8;
  iVar7 = param_1;
  _in_cksum(param_1,uVar9);
  pbVar11 = (byte *)(param_1 + iVar8);
  if (iVar7 != 0) {
    DAT_f01365bc._4_4_ = DAT_f01365bc._4_4_ + 1;
    goto loc_F0031894;
  }
  *(sword *)(param_1 + 8) = *(sword *)(param_1 + 8) + (sword)iVar12;
  *(uint *)(param_1 + 4) = *(int *)(param_1 + 4) + uVar2 * -4;
  if (0x12 < *(byte *)(param_1 + iVar8)) goto def_F00313E8;
  iVar7 = (uint)*(byte *)(param_1 + iVar8) * 4;
  *(int *)(unk_F01365CC + iVar7) = *(int *)(unk_F01365CC + iVar7) + 1;
  uVar2 = (uint)pbVar11[1];
  switch(*(undefined *)(param_1 + iVar8)) {
  case :
    if (5 < uVar2) goto loc_F0031524;
    iVar12 = uVar2 + 8;
loc_F0031488:
    *(undefined2 *)(pbVar11 + 10) = *(undefined2 *)(pbVar11 + 10);
    if ((uVar9 < 0x24) || ((int)uVar9 < (int)((pbVar11[8] & 0xf) * 4 + 0x10))) {
      DAT_f01365bc._8_4_ = DAT_f01365bc._8_4_ + 1;
      goto loc_F0031894;
    }
    DAT_f010c744._0_4_ = *(undefined4 *)(pbVar11 + 0x18);
    if (*(code **)(DAT_f010c5b4 + (uint)(byte)_ip_protox[pbVar11[0x11]] * 0x30) != (code *)0x0) {
      (**(code **)(DAT_f010c5b4 + (uint)(byte)_ip_protox[pbVar11[0x11]] * 0x30))
                (iVar12,unk_F010C740,pbVar11 + 8);
      goto loc_F0031868;
    }
    break;
  case :
    if (uVar2 == 0) {
      iVar12 = 4;
      goto loc_F0031488;
    }
    goto loc_F0031524;
  case :
    if ((uVar9 < 0x24) || ((int)uVar9 < (int)((pbVar11[8] & 0xf) * 4 + 0x10))) {
loc_F00316B8:
      DAT_f01365bc._8_4_ = DAT_f01365bc._8_4_ + 1;
      break;
    }
    DAT_f010c764._0_4_ = *(undefined4 *)(iVar14 + 0xc);
    DAT_f010c754._0_4_ = *(undefined4 *)(pbVar11 + 4);
    if ((uVar2 == 0) || (uVar2 == 2)) {
      puVar3 = (undefined *)((int)register0x00000038 + -0x10);
      *(undefined4 *)((int)register0x00000038 + -0x10) = *(undefined4 *)(pbVar11 + 0x18);
      _in_netof();
      _in_makeaddr();
      DAT_f010c744._0_4_ = puVar3;
      _rtredirect(unk_F010C740,unk_F010C750,2,unk_F010C760);
      DAT_f010c744._0_4_ = *(undefined4 *)(pbVar11 + 0x18);
      _pfctlinput(0xe);
    }
    else {
      DAT_f010c744._0_4_ = *(undefined4 *)(pbVar11 + 0x18);
      _rtredirect(unk_F010C740,unk_F010C750,6,unk_F010C760);
      _pfctlinput(0xf,unk_F010C740);
    }
    goto loc_F0031868;
  case :
    *pbVar11 = 0;
    goto loc_F0031648;
  case :
    if (uVar2 < 2) {
      iVar12 = uVar2 + 0x12;
      goto loc_F0031488;
    }
    goto loc_F0031524;
  case :
    if (uVar2 == 0) {
      iVar12 = 0x14;
      goto loc_F0031488;
    }
loc_F0031524:
    DAT_f01365b8._0_4_ = DAT_f01365b8._0_4_ + 1;
    break;
  case :
    uVar10 = 0xe;
    if (uVar9 < 0x14) goto loc_F00316B8;
    *pbVar11 = 0xe;
    _iptime();
    *(undefined4 *)(pbVar11 + 0xc) = uVar10;
    *(undefined4 *)(pbVar11 + 0x10) = uVar10;
    goto loc_F0031648;
  case :
    puVar3 = (undefined *)((int)register0x00000038 + -0xc);
    *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(iVar14 + 0xc);
    _in_netof();
    if (puVar3 == (undefined *)0x0) {
      puVar5 = param_2;
      _ifptoia();
      puVar3 = (undefined *)((int)register0x00000038 + -0x10);
      if (puVar5 != (undefined4 *)0x0) {
        *(undefined4 *)((int)register0x00000038 + -0x10) = puVar5[1];
        puVar4 = puVar3;
        _in_netof();
        *(undefined4 *)((int)register0x00000038 + -0x10) = *(undefined4 *)(iVar14 + 0xc);
        _in_lnaof(puVar3);
        _in_makeaddr(puVar4,puVar3);
        *(undefined **)(iVar14 + 0xc) = puVar4;
      }
    }
    *pbVar11 = 0x10;
loc_F0031648:
    sVar1 = *(sword *)(iVar14 + 2);
loc_F003164C:
    *(sword *)(iVar14 + 2) = sVar1 + (sword)iVar12;
    DAT_f01365bc._12_4_ = DAT_f01365bc._12_4_ + 1;
    *(int *)(unk_F013656C + (uint)*pbVar11 * 4) = *(int *)(unk_F013656C + (uint)*pbVar11 * 4) + 1;
    _icmp_reflect(iVar14,param_2);
    goto locret_F003189C;
  case :
    if (((int)uVar9 < 0xc) || (puVar5 = param_2, _ifptoia(), puVar5 == (undefined4 *)0x0))
    goto loc_F0031868;
    if ((puVar5[0xf] & 2) == 0) break;
    *pbVar11 = 0x12;
    *(undefined4 *)(pbVar11 + 8) = puVar5[0xd];
    if (*(int *)(iVar14 + 0xc) != 0) goto loc_F0031648;
    if ((*(word *)(puVar5[8] + 0xc) & 2) != 0) {
      uVar10 = puVar5[5];
loc_F0031640:
      *(undefined4 *)(iVar14 + 0xc) = uVar10;
      goto loc_F0031648;
    }
    if ((*(word *)(puVar5[8] + 0xc) & 0x10) != 0) {
      uVar10 = puVar5[5];
      goto loc_F0031640;
    }
    sVar1 = *(sword *)(iVar14 + 2);
    goto loc_F003164C;
  case :
    puVar5 = param_2;
    _ifptoia();
    if ((puVar5 == (undefined4 *)0x0) || ((puVar5[0xf] & 4) == 0)) goto loc_F0031868;
    if (*(uint *)(pbVar11 + 8) != 0xffffffff) {
      if (((*(uint *)(pbVar11 + 8) & 0xff000000) != 0xff000000) ||
         (puVar5[0xf] = puVar5[0xf] & 0xfffffffb, (*(word *)(param_2 + 3) & 8) != 0))
      goto loc_F0031868;
      if ((puVar5[0xd] | *(uint *)(pbVar11 + 8)) != puVar5[0xd]) {
        puVar5[0xd] = *(uint *)(pbVar11 + 8);
        puVar6 = param_2;
        _in_ifinit(param_2,puVar5,puVar5);
        if (puVar6 != (undefined4 *)0x0) {
          _printf(aIcmpInputCanTS);
          goto loc_F0031868;
        }
        uVar13 = *param_2;
        iVar12 = iVar14 + 0xc;
        sVar1 = *(sword *)(param_2 + 2);
        uVar10 = puVar5[0xd];
        _inet_ntoa(iVar12);
        _printf(aSDSettingNetma,uVar13,(int)sVar1,uVar10,iVar12);
        _wakeup(puVar5 + 0xd);
      }
    }
  }
def_F00313E8:
loc_F0031868:
  DAT_f010c744._0_4_ = *(undefined4 *)(iVar14 + 0xc);
  DAT_f010c754._0_4_ = *(undefined4 *)(iVar14 + 0x10);
  _raw_input(param_1,&DAT_f010c73a);
locret_F003189C:
  return CONCAT44(param_2,param_1);
}

