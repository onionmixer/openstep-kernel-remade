
/* WARNING: Removing unreachable block (ram,0xf002dab4) */
/* WARNING: Removing unreachable block (ram,0xf002dee8) */
/* WARNING: Removing unreachable block (ram,0xf002deac) */
/* WARNING: Removing unreachable block (ram,0xf002de78) */
/* WARNING: Removing unreachable block (ram,0xf002de18) */
/* WARNING: Removing unreachable block (ram,0xf002ddd8) */
/* WARNING: Removing unreachable block (ram,0xf002dda4) */
/* WARNING: Removing unreachable block (ram,0xf002dcec) */
/* WARNING: Removing unreachable block (ram,0xf002dad8) */
/* WARNING: Removing unreachable block (ram,0xf002dc50) */
/* WARNING: Removing unreachable block (ram,0xf002dc1c) */
/* WARNING: Removing unreachable block (ram,0xf002dbc0) */
/* WARNING: Removing unreachable block (ram,0xf002db1c) */
/* WARNING: Removing unreachable block (ram,0xf002da94) */
/* WARNING: Removing unreachable block (ram,0xf002da64) */
/* WARNING: Removing unreachable block (ram,0xf002da40) */
/* WARNING: Removing unreachable block (ram,0xf002da78) */
/* WARNING: Removing unreachable block (ram,0xf002db08) */
/* WARNING: Removing unreachable block (ram,0xf002dba0) */
/* WARNING: Removing unreachable block (ram,0xf002dbf8) */
/* WARNING: Removing unreachable block (ram,0xf002dc30) */
/* WARNING: Removing unreachable block (ram,0xf002dc64) */
/* WARNING: Removing unreachable block (ram,0xf002daec) */
/* WARNING: Removing unreachable block (ram,0xf002dcfc) */
/* WARNING: Removing unreachable block (ram,0xf002ddb4) */
/* WARNING: Removing unreachable block (ram,0xf002ddf0) */
/* WARNING: Removing unreachable block (ram,0xf002de34) */
/* WARNING: Removing unreachable block (ram,0xf002dec4) */
/* WARNING: Removing unreachable block (ram,0xf002def8) */
/* WARNING: Removing unreachable block (ram,0xf002df04) */
/* WARNING: Removing unreachable block (ram,0xf002d9ec) */

undefined8 _in_arpinput(int *param_1,int *param_2,int *param_3,int param_4)

{
  sword sVar1;
  sword sVar2;
  word wVar3;
  undefined *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 unaff_l0;
  undefined *puVar9;
  undefined *puVar10;
  int iVar11;
  undefined4 unaff_l1;
  int *piVar12;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  int iVar13;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar14;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar15;
  bool bVar16;
  bool bVar17;
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
  iVar13 = 0;
  puVar9 = (undefined *)((int)register0x00000038 + -0x28);
  iVar14 = *param_3;
  _bcopy(param_4 + *(int *)(param_4 + 4),puVar9,0x1c);
  *(undefined2 *)((int)register0x00000038 + -0x48) = 0x806;
  sVar1 = *(sword *)((int)register0x00000038 + -0x26);
  sVar2 = *(sword *)((int)register0x00000038 + -0x22);
  if (*(sword *)((int)register0x00000038 + -0x24) == DAT_f010c358._0_2_) {
    _bcopy(puVar9 + DAT_f010c358[0] + 8,(undefined *)((int)register0x00000038 + -0x4c),4);
    _bcopy(puVar9 + (uint)DAT_f010c358[0] * 2 + (uint)DAT_f010c358[1] + 8,
           (undefined *)((int)register0x00000038 + -0x50),4);
    puVar10 = (undefined *)((int)register0x00000038 + -0x20);
    puVar4 = puVar10;
    _bcmp(puVar10,param_2,DAT_f010c358[0]);
    if (puVar4 != (undefined *)0x0) {
      puVar4 = puVar10;
      _bcmp(puVar10,&_etherbroadcastaddr,6);
      iVar5 = *(int *)((int)register0x00000038 + -0x4c);
      if (puVar4 != (undefined *)0x0) {
        if (iVar5 == iVar14) {
          _ether_sprintf(puVar10);
          _log(3,&aSS_0,aDuplicateIpAdd,puVar10);
          *(int *)((int)register0x00000038 + -0x50) = iVar14;
          if (sVar2 != 1) goto loc_F002DF04;
          piVar12 = (int *)0x0;
        }
        else {
          _spltty();
          iVar11 = *(int *)((int)register0x00000038 + -0x4c);
          iVar7 = iVar11;
          .urem(iVar11,0x13);
          piVar12 = (int *)(_arptab + iVar7 * 0xb4);
          iVar7 = 0;
          do {
            iVar6 = iVar7;
            if (*piVar12 == iVar11) {
              bVar17 = SBORROW4(iVar6,8);
              bVar16 = iVar6 == 8;
              bVar15 = iVar6 + -8 < 0;
              if (param_1 == (int *)0x0) goto loc_F002DB88;
              bVar17 = SBORROW4(iVar6,8);
              bVar16 = iVar6 == 8;
              bVar15 = iVar6 + -8 < 0;
              if ((int *)piVar12[4] == param_1) goto loc_F002DB88;
            }
            iVar7 = iVar6 + 1;
            piVar12 = piVar12 + 5;
          } while (iVar7 < 9);
          bVar17 = SBORROW4(iVar7,8);
          bVar16 = iVar7 == 8;
          bVar15 = iVar6 + -7 < 0;
loc_F002DB88:
          if (!bVar16 && bVar15 == bVar17) {
            piVar12 = (int *)0x0;
          }
          if (piVar12 != (int *)0x0) {
            _bcopy((undefined *)((int)register0x00000038 + -0x20),piVar12 + 1,DAT_f010c358[0]);
            uVar8 = (uint)DAT_f010c358[0];
            if (uVar8 < 6) {
              _bzero((undefined *)((int)piVar12 + uVar8 + 4),6 - uVar8);
            }
            *(byte *)((int)piVar12 + 0xb) = *(byte *)((int)piVar12 + 0xb) | 2;
            if (piVar12[3] != 0) {
              *(undefined2 *)((int)register0x00000038 + -0x38) = 2;
              *(undefined4 *)((int)register0x00000038 + -0x34) =
                   *(undefined4 *)((int)register0x00000038 + -0x4c);
              _if_output_mbuf(param_1,piVar12[3],(undefined *)((int)register0x00000038 + -0x38));
              piVar12[3] = 0;
            }
          }
          if ((piVar12 == (int *)0x0) && (*(int *)((int)register0x00000038 + -0x50) == iVar14)) {
            piVar12 = param_1;
            _arptnew(param_1,(undefined *)((int)register0x00000038 + -0x4c));
            _bcopy((undefined *)((int)register0x00000038 + -0x20),piVar12 + 1,DAT_f010c358[0]);
            uVar8 = (uint)DAT_f010c358[0];
            if (uVar8 < 6) {
              _bzero((undefined *)((int)piVar12 + uVar8 + 4),6 - uVar8);
            }
            *(byte *)((int)piVar12 + 0xb) = *(byte *)((int)piVar12 + 0xb) | 2;
          }
          _splx(iVar5);
        }
        if (sVar1 == 0x800) {
          iVar5 = *(int *)((int)register0x00000038 + -0x50);
          if (sVar2 != 1) {
            wVar3 = *(word *)(param_1 + 3);
loc_F002DCBC:
            iVar5 = *(int *)((int)register0x00000038 + -0x50);
            if ((wVar3 & 0x20) != 0) goto loc_F002DF04;
          }
        }
        else {
          if (sVar1 == 0x1000) {
            if (piVar12 != (int *)0x0) {
              *(byte *)((int)piVar12 + 0xb) = *(byte *)((int)piVar12 + 0xb) | 0x10;
            }
            if (sVar2 == 1) {
              wVar3 = *(word *)(param_1 + 3);
              goto loc_F002DCBC;
            }
            goto loc_F002DF04;
          }
          iVar5 = *(int *)((int)register0x00000038 + -0x50);
        }
        if (iVar5 == iVar14) {
          _bcopy((undefined *)((int)register0x00000038 + -0x20),
                 puVar9 + (uint)DAT_f010c358[0] + (uint)DAT_f010c358[1] + 8);
          piVar12 = param_2;
        }
        else {
          iVar14 = iVar5;
          .urem(iVar5,0x13);
          piVar12 = (int *)(_arptab + iVar14 * 0xb4);
          iVar14 = 0;
          do {
            iVar7 = iVar14;
            if (*piVar12 == iVar5) {
              bVar17 = SBORROW4(iVar7,8);
              bVar16 = iVar7 == 8;
              bVar15 = iVar7 + -8 < 0;
              if (param_1 == (int *)0x0) goto loc_F002DD6C;
              bVar17 = SBORROW4(iVar7,8);
              bVar16 = iVar7 == 8;
              bVar15 = iVar7 + -8 < 0;
              if ((int *)piVar12[4] == param_1) goto loc_F002DD6C;
            }
            iVar14 = iVar7 + 1;
            piVar12 = piVar12 + 5;
          } while (iVar14 < 9);
          bVar17 = SBORROW4(iVar14,8);
          bVar16 = iVar14 == 8;
          bVar15 = iVar7 + -7 < 0;
loc_F002DD6C:
          if (!bVar16 && bVar15 == bVar17) {
            piVar12 = (int *)0x0;
          }
          if ((piVar12 == (int *)0x0) || ((*(byte *)((int)piVar12 + 0xb) & 8) == 0))
          goto loc_F002DF04;
          _bcopy((undefined *)((int)register0x00000038 + -0x20),
                 puVar9 + (uint)DAT_f010c358[0] + (uint)DAT_f010c358[1] + 8);
          piVar12 = piVar12 + 1;
        }
        _bcopy(piVar12,(undefined *)((int)register0x00000038 + -0x20),DAT_f010c358[0]);
        _bcopy(puVar9 + DAT_f010c358[0] + 8,
               puVar9 + (uint)DAT_f010c358[0] * 2 + (uint)DAT_f010c358[1] + 8);
        _bcopy((undefined *)((int)register0x00000038 + -0x50),puVar9 + DAT_f010c358[0] + 8,
               DAT_f010c358[1]);
        *(undefined2 *)((int)register0x00000038 + -0x22) = 2;
        _bcopy(puVar9 + (uint)DAT_f010c358[0] + (uint)DAT_f010c358[1] + 8,
               (undefined *)((int)register0x00000038 + -0x46));
        _bcopy((undefined *)((int)register0x00000038 + -0x48),
               (undefined *)((int)register0x00000038 + -0x48) + (uint)DAT_f010c358[0] * 2 + 2,2);
        if (sVar2 == 2) {
          *(undefined2 *)((int)register0x00000038 + -0x26) = 0x1000;
        }
        else if ((sVar1 == 0x800) && ((*(word *)(param_1 + 3) & 0x20) == 0)) {
          iVar13 = param_4;
          _m_copy(param_4,0,1000000000);
        }
        *(undefined2 *)((int)register0x00000038 + -0x22) =
             *(undefined2 *)((int)register0x00000038 + -0x22);
        _bcopy(puVar9,param_4 + *(int *)(param_4 + 4),0x1c);
        *(undefined2 *)((int)register0x00000038 + -0x48) = 0;
        _if_output_mbuf(param_1,param_4,(undefined *)((int)register0x00000038 + -0x48));
        if (iVar13 != 0) {
          *(undefined2 *)((int)register0x00000038 + -0x26) = 0x1000;
          _bcopy(puVar9,iVar13 + *(int *)(iVar13 + 4),0x1c);
          _if_output_mbuf(param_1,iVar13,(undefined *)((int)register0x00000038 + -0x48));
        }
        goto locret_F002DF0C;
      }
      _log(3,aArpEtherAddres,*(undefined4 *)((int)register0x00000038 + -0x4c));
    }
  }
loc_F002DF04:
  _m_freem(param_4);
locret_F002DF0C:
  return CONCAT44(param_2,param_1);
}
