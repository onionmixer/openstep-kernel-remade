/* GHIDRADEC_FUNCTION index=700 start=0xf002d68c */

/* WARNING: Removing unreachable block (ram,0xf002d770) */
/* WARNING: Removing unreachable block (ram,0xf002d8a4) */
/* WARNING: Removing unreachable block (ram,0xf002d8fc) */
/* WARNING: Removing unreachable block (ram,0xf002d840) */
/* WARNING: Removing unreachable block (ram,0xf002d868) */
/* WARNING: Removing unreachable block (ram,0xf002d798) */
/* WARNING: Removing unreachable block (ram,0xf002d72c) */
/* WARNING: Removing unreachable block (ram,0xf002d7ac) */
/* WARNING: Removing unreachable block (ram,0xf002d880) */
/* WARNING: Removing unreachable block (ram,0xf002d8e0) */
/* WARNING: Removing unreachable block (ram,0xf002d904) */
/* WARNING: Removing unreachable block (ram,0xf002d8c0) */
/* WARNING: Removing unreachable block (ram,0xf002d78c) */
/* WARNING: Removing unreachable block (ram,0xf002d6f0) */

undefined8
_arpresolve(uint param_1,int param_2,uint *param_3,uint param_4,uint *param_5,undefined *param_6)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 unaff_l0;
  uint uVar6;
  undefined4 unaff_l1;
  uint *puVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 *puVar8;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar9;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar10;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar11;
  bool bVar12;
  bool bVar13;
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
  puVar8 = *(undefined4 **)((int)register0x00000038 + 0x5c);
  uVar10 = *param_3;
  *puVar8 = 0;
  if ((*param_5 & 0xf0000000) == 0xe0000000) {
    *param_6 = 1;
    param_6[1] = 0;
    param_6[2] = 0x5e;
    param_6[3] = *(byte *)((int)param_5 + 1) & 0x7f;
    param_6[4] = *(undefined *)((int)param_5 + 2);
    uVar9 = 1;
    param_6[5] = (char)*param_5;
    goto locret_F002D910;
  }
  *(uint *)((int)register0x00000038 + -0x1c) = *param_5;
  puVar1 = (undefined *)((int)register0x00000038 + -0x1c);
  _in_broadcast();
  if (puVar1 == (undefined *)0x0) {
    puVar1 = (undefined *)((int)register0x00000038 + -0x20);
    *(uint *)((int)register0x00000038 + -0x20) = *param_5;
    _in_lnaof();
    if (*param_5 != uVar10) {
      puVar2 = puVar1;
      _spltty();
      uVar6 = *param_5;
      uVar3 = uVar6;
      .urem(uVar6,0x13);
      puVar7 = (uint *)(_arptab + uVar3 * 0xb4);
      iVar5 = 0;
      do {
        iVar4 = iVar5;
        if (*puVar7 == uVar6) {
          bVar13 = SBORROW4(iVar4,8);
          bVar12 = iVar4 == 8;
          bVar11 = iVar4 + -8 < 0;
          if (param_1 == 0) goto loc_F002D818;
          bVar13 = SBORROW4(iVar4,8);
          bVar12 = iVar4 == 8;
          bVar11 = iVar4 + -8 < 0;
          if (puVar7[4] == param_1) goto loc_F002D818;
        }
        iVar5 = iVar4 + 1;
        puVar7 = puVar7 + 5;
      } while (iVar5 < 9);
      bVar13 = SBORROW4(iVar5,8);
      bVar12 = iVar5 == 8;
      bVar11 = iVar4 + -7 < 0;
loc_F002D818:
      if (!bVar12 && bVar11 == bVar13) {
        puVar7 = (uint *)0x0;
      }
      if (puVar7 == (uint *)0x0) {
        if ((*(word *)(param_1 + 0xc) & 0x80) == 0) {
          uVar3 = param_1;
          _arptnew(param_1,param_5);
          if (uVar3 == 0) {
            _panic(aArpresolveNoFr);
            uRam0000000c = param_4;
          }
          else {
            *(uint *)(uVar3 + 0xc) = param_4;
          }
          goto loc_F002D8EC;
        }
        _bcopy(param_2,param_6,3);
        param_6[3] = (byte)((uint)puVar1 >> 0x10) & 0x7f;
        param_6[4] = (char)((uint)puVar1 >> 8);
        param_6[5] = (char)puVar1;
      }
      else {
        *(undefined *)((int)puVar7 + 10) = 0;
        if ((*(byte *)((int)puVar7 + 0xb) & 2) == 0) {
          if (puVar7[3] == 0) {
            puVar7[3] = param_4;
          }
          else {
            _m_freem();
            puVar7[3] = param_4;
          }
loc_F002D8EC:
          *(uint *)((int)register0x00000038 + -0x20) = uVar10;
          _arpwhohas(param_1,param_2,(undefined *)((int)register0x00000038 + -0x20),param_5);
          _splx(puVar2);
          uVar9 = 0;
          goto locret_F002D910;
        }
        _bcopy(puVar7 + 1,param_6,6);
        if ((*(byte *)((int)puVar7 + 0xb) & 0x10) != 0) {
          *puVar8 = 1;
        }
      }
      _splx(puVar2);
      uVar9 = 1;
      goto locret_F002D910;
    }
    if (_useloopback != 0) {
      *(undefined2 *)((int)register0x00000038 + -0x18) = 2;
      *(uint *)((int)register0x00000038 + -0x14) = *param_5;
      _looutput(_loifp,param_4,(undefined *)((int)register0x00000038 + -0x18));
      uVar9 = 0;
      goto locret_F002D910;
    }
    uVar10 = 4;
    iVar5 = param_2;
  }
  else {
    uVar10 = (uint)DAT_f010c358[0];
    iVar5 = uVar10 + DAT_f010c358[1] + -0xfef3ca4;
  }
  uVar9 = 1;
  _bcopy(iVar5,param_6,uVar10);
locret_F002D910:
  return CONCAT44(param_2,uVar9);
}
/* GHIDRADEC_FUNCTION index=701 start=0xf002d918 */

/* WARNING: Removing unreachable block (ram,0xf002d9b4) */
/* WARNING: Removing unreachable block (ram,0xf002d9c0) */
/* WARNING: Removing unreachable block (ram,0xf002d944) */

undefined8 _arpinput(int param_1,undefined4 param_2,undefined4 *param_3,int param_4)

{
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
  undefined4 uVar1;
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
  uVar1 = *param_3;
  if (((*(word *)(param_1 + 0xc) & 0x80) == 0) && (7 < *(word *)(param_4 + 8))) {
    _bcopy(param_4 + *(int *)(param_4 + 4),(undefined *)((int)register0x00000038 + -0x10),8);
    if (((*(sword *)((int)register0x00000038 + -0x10) == 1) &&
        (((uint)DAT_f010c358[0] + (uint)DAT_f010c358[1]) * 2 + 8 <=
         (uint)(int)*(sword *)(param_4 + 8))) &&
       ((*(sword *)((int)register0x00000038 + -0xe) == 0x800 ||
        (*(sword *)((int)register0x00000038 + -0xe) == 0x1000)))) {
      *(undefined4 *)((int)register0x00000038 + -0x14) = uVar1;
      _in_arpinput(param_1,param_2,(undefined *)((int)register0x00000038 + -0x14),param_4);
      goto locret_F002D9C8;
    }
  }
  _m_freem(param_4);
locret_F002D9C8:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=702 start=0xf002d9d0 */

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
/* GHIDRADEC_FUNCTION index=703 start=0xf002df14 */

/* WARNING: Removing unreachable block (ram,0xf002df30) */
/* WARNING: Removing unreachable block (ram,0xf002df48) */
/* WARNING: Removing unreachable block (ram,0xf002df18) */

undefined8 _arptfree(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
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
  puVar1 = param_1;
  _spltty();
  if (param_1[3] != 0) {
    _m_freem(param_1[3]);
  }
  param_1[3] = 0;
  *(undefined *)((int)param_1 + 0xb) = 0;
  *(undefined *)((int)param_1 + 10) = 0;
  *param_1 = 0;
  _splx(puVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=704 start=0xf002df58 */

/* WARNING: Removing unreachable block (ram,0xf002df98) */
/* WARNING: Removing unreachable block (ram,0xf002e02c) */
/* WARNING: Removing unreachable block (ram,0xf002df8c) */

undefined8 _arptnew(int param_1,int *param_2)

{
  byte bVar1;
  int iVar2;
  undefined4 unaff_l0;
  int *piVar3;
  undefined4 unaff_l1;
  uint uVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar5;
  int *piVar6;
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
  uVar4 = 0xffffffff;
  piVar3 = (int *)0x0;
  if (dword_F010C424 != 0) {
    dword_F010C424 = 0;
    _timeout(_arptimer,0,_hz);
  }
  iVar2 = *param_2;
  .urem(iVar2,0x13);
  piVar5 = (int *)(_arptab + iVar2 * 0xb4);
  iVar2 = 0;
  piVar6 = piVar5;
  do {
    if (*(byte *)((int)piVar5 + 0xb) == 0) goto loc_F002E034;
    if ((*(byte *)((int)piVar5 + 0xb) & 4) == 0) {
      if (piVar3 == (int *)0x0) {
        bVar1 = *(byte *)((int)piVar5 + 10);
      }
      else {
        if ((int)(uint)*(byte *)((int)piVar5 + 10) <= (int)uVar4) goto loc_F002E008;
        bVar1 = *(byte *)((int)piVar5 + 10);
      }
      uVar4 = (uint)bVar1;
      piVar3 = piVar5;
    }
loc_F002E008:
    iVar2 = iVar2 + 1;
    piVar5 = piVar5 + 5;
    piVar6 = piVar6 + 5;
  } while (iVar2 < 9);
  if (piVar3 == (int *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    _arptfree(piVar3);
    piVar6 = piVar3;
loc_F002E034:
    *piVar6 = *param_2;
    *(undefined *)((int)piVar6 + 0xb) = 1;
    piVar6[4] = param_1;
  }
  return CONCAT44(param_2,piVar6);
}
/* GHIDRADEC_FUNCTION index=705 start=0xf002e050 */

/* WARNING: Removing unreachable block (ram,0xf002e1f4) */
/* WARNING: Removing unreachable block (ram,0xf002e1d4) */
/* WARNING: Removing unreachable block (ram,0xf002e1b8) */
/* WARNING: Removing unreachable block (ram,0xf002e224) */
/* WARNING: Removing unreachable block (ram,0xf002e12c) */
/* WARNING: Removing unreachable block (ram,0xf002e108) */
/* WARNING: Removing unreachable block (ram,0xf002e090) */
/* WARNING: Removing unreachable block (ram,0xf002e118) */
/* WARNING: Removing unreachable block (ram,0xf002e214) */
/* WARNING: Removing unreachable block (ram,0xf002e190) */
/* WARNING: Removing unreachable block (ram,0xf002e1cc) */
/* WARNING: Removing unreachable block (ram,0xf002e1e4) */
/* WARNING: Removing unreachable block (ram,0xf002e234) */
/* WARNING: Removing unreachable block (ram,0xf002e07c) */

undefined8 _arpioctl(int param_1,sword *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  int *piVar4;
  sword *psVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar6;
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
  psVar5 = (sword *)0x0;
  if ((*param_2 != 2) || (uVar1 = (uint)(word)param_2[8], uVar1 != 0)) {
    uVar6 = 0x2f;
    goto locret_F002E240;
  }
  _spltty();
  iVar3 = *(int *)(param_2 + 2);
  iVar2 = iVar3;
  .urem(iVar3,0x13);
  piVar4 = (int *)(_arptab + iVar2 * 0xb4);
  iVar2 = 0;
  do {
    if (*piVar4 == iVar3) break;
    iVar2 = iVar2 + 1;
    piVar4 = piVar4 + 5;
  } while (iVar2 < 9);
  if (8 < iVar2) {
    piVar4 = (int *)0x0;
  }
  if (piVar4 == (int *)0x0) {
    if (param_1 != -0x7fdb96e2) {
      _splx(uVar1);
      uVar6 = 6;
      goto locret_F002E240;
    }
    psVar5 = param_2;
    _ifa_ifwithnet();
    if (psVar5 == (sword *)0x0) {
      _splx(uVar1);
      uVar6 = 0x33;
      goto locret_F002E240;
    }
  }
  if (param_1 == -0x7fdb96e0) {
    _arptfree(piVar4);
  }
  else if (param_1 < -0x7fdb96df) {
    if (param_1 == -0x7fdb96e2) {
      if (piVar4 == (int *)0x0) {
        piVar4 = *(int **)(psVar5 + 0x10);
        _arptnew(piVar4,param_2 + 2);
        if (piVar4 == (int *)0x0) {
loc_F002E1D4:
          _splx(uVar1);
          uVar6 = 0x31;
          goto locret_F002E240;
        }
        if ((*(uint *)(param_2 + 0x10) & 4) != 0) {
          iVar2 = piVar4[4];
          _arptnew(iVar2,param_2 + 2);
          if (iVar2 == 0) {
            _arptfree(piVar4);
            goto loc_F002E1D4;
          }
          _arptfree();
        }
      }
      _bcopy(param_2 + 9,piVar4 + 1,6);
      *(byte *)((int)piVar4 + 0xb) = (byte)*(undefined4 *)(param_2 + 0x10) & 0x1c | 3;
      *(undefined *)((int)piVar4 + 10) = 0;
    }
  }
  else if (param_1 == -0x3fdb96e1) {
    _bcopy(piVar4 + 1,param_2 + 9,6);
    *(uint *)(param_2 + 0x10) = (uint)*(byte *)((int)piVar4 + 0xb);
  }
  _splx(uVar1);
  uVar6 = 0;
locret_F002E240:
  return CONCAT44(param_2,uVar6);
}
/* GHIDRADEC_FUNCTION index=706 start=0xf002e248 */

/* WARNING: Removing unreachable block (ram,0xf002e3fc) */
/* WARNING: Removing unreachable block (ram,0xf002e47c) */
/* WARNING: Removing unreachable block (ram,0xf002e4c8) */
/* WARNING: Removing unreachable block (ram,0xf002e384) */
/* WARNING: Removing unreachable block (ram,0xf002e454) */
/* WARNING: Removing unreachable block (ram,0xf002e464) */
/* WARNING: Removing unreachable block (ram,0xf002e3ec) */
/* WARNING: Removing unreachable block (ram,0xf002e2f8) */
/* WARNING: Removing unreachable block (ram,0xf002e290) */
/* WARNING: Removing unreachable block (ram,0xf002e2d0) */
/* WARNING: Removing unreachable block (ram,0xf002e318) */
/* WARNING: Removing unreachable block (ram,0xf002e3ac) */
/* WARNING: Removing unreachable block (ram,0xf002e274) */
/* WARNING: Removing unreachable block (ram,0xf002e4e8) */
/* WARNING: Removing unreachable block (ram,0xf002e48c) */

undefined8 _revarpinput(int param_1,undefined4 *param_2)

{
  word wVar3;
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 *puVar4;
  int iVar5;
  undefined4 unaff_l1;
  undefined *puVar6;
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
  bool bVar7;
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
  param_2[1] = param_2[1] + 4;
  wVar3 = *(sword *)(param_2 + 2) - 4;
  *(word *)(param_2 + 2) = wVar3;
  iVar1 = (uint)wVar3 * 0x10000;
  if (wVar3 == 0) {
    _spltty();
    if (*(sword *)((int)param_2 + 10) == 0) {
      _panic(&aMfree_6);
    }
    (&word_F0134B0C)[*(sword *)((int)param_2 + 10)] =
         (&word_F0134B0C)[*(sword *)((int)param_2 + 10)] + -1;
    word_F0134B0C = word_F0134B0C + 1;
    *(undefined2 *)((int)param_2 + 10) = 0;
    if (0x7f < (uint)param_2[1]) {
      _mclput(param_2);
    }
    param_2[1] = 0;
    param_2[0x1f] = 0;
    puVar4 = (undefined4 *)*param_2;
    *param_2 = _mfree;
    _mfree = param_2;
    _splx(iVar1);
    if (_m_want != 0) {
      _m_want = 0;
      _wakeup(&_mfree);
    }
    wVar3 = *(word *)(puVar4 + 2);
  }
  else {
    wVar3 = *(word *)(param_2 + 2);
    puVar4 = param_2;
  }
  iVar1 = puVar4[1];
  if ((((0x1b < wVar3) && ((*(word *)(param_1 + 0xc) & 0x80) == 0)) &&
      (*(sword *)((int)puVar4 + iVar1 + 2) == 0x800)) &&
     ((_revarp != 0 && (*(sword *)((int)puVar4 + iVar1 + 6) == 3)))) {
    puVar6 = _arptab;
    iVar5 = -0xfeca98c;
    do {
      if (((*(byte *)(iVar5 + 7) & 4) != 0) &&
         (iVar2 = iVar5, _bcmp(iVar5,(int)puVar4 + iVar1 + 0x12,6), iVar2 == 0)) break;
      puVar6 = puVar6 + 0x14;
      iVar5 = iVar5 + 0x14;
    } while (puVar6 < (undefined *)0xf01363cc);
    if (puVar6 < (undefined *)0xf01363cc) {
      _bcopy((int)puVar4 + iVar1 + 8,(undefined *)((int)register0x00000038 + -0x1e),6);
      _bcopy(puVar6,(int)puVar4 + iVar1 + 0x18,4);
      iVar5 = *(int *)(param_1 + 0x18);
      bVar7 = iVar5 == 0;
      if (!bVar7) {
        iVar2 = *(int *)(iVar5 + 0x20);
        while (iVar2 != param_1) {
          iVar5 = *(int *)(iVar5 + 0x24);
          if (iVar5 == 0) {
            bVar7 = true;
            goto loc_F002E438;
          }
          iVar2 = *(int *)(iVar5 + 0x20);
        }
        _bcopy(iVar5 + 4,(int)puVar4 + iVar1 + 0xe,4);
        bVar7 = iVar5 == 0;
      }
loc_F002E438:
      if (!bVar7) {
        _bcopy(param_1 + 0x60,(int)puVar4 + iVar1 + 8,6);
        _bcopy(param_1 + 0x60,(undefined *)((int)register0x00000038 + -0x18),6);
        *(undefined2 *)((int)register0x00000038 + -0x12) = 0x8035;
        *(undefined2 *)((int)puVar4 + iVar1 + 6) = 4;
        *(undefined2 *)((int)register0x00000038 + -0x20) = 0;
        if (_revarpdebug != 0) {
          _printf(aRevarpReplyToX,*(undefined4 *)((int)puVar4 + iVar1 + 0x18),
                  *(undefined4 *)((int)puVar4 + iVar1 + 0xe));
        }
        (**(code **)(param_1 + 0x34))(param_1,puVar4,(undefined *)((int)register0x00000038 + -0x20))
        ;
        goto locret_F002E4F0;
      }
      if (_revarpdebug != 0) {
        _printf(aRevarpCanTFind);
      }
    }
  }
  _m_freem(puVar4);
locret_F002E4F0:
  return CONCAT44(puVar4,param_1);
}
/* GHIDRADEC_FUNCTION index=707 start=0xf002e4f8 */

/* WARNING: Removing unreachable block (ram,0xf002e570) */
/* WARNING: Removing unreachable block (ram,0xf002e564) */

undefined8 _localetheraddr(undefined *param_1,undefined *param_2)

{
  undefined *puVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
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
  if (dword_F010C474 == 0) {
    dword_F010C474 = 1;
    if (param_1 == (undefined *)0x0) {
      uVar2 = 0;
      goto locret_F002E5BC;
    }
    byte_F012F418 = *param_1;
    DAT_f012f419._0_1_ = param_1[1];
    puVar1 = &byte_F012F418;
    DAT_f012f419._1_1_ = param_1[2];
    DAT_f012f419._2_1_ = param_1[3];
    DAT_f012f419._3_1_ = param_1[4];
    DAT_f012f419._4_1_ = param_1[5];
    _ether_sprintf();
    _printf(aEthernetAddres,puVar1);
  }
  if (param_2 != (undefined *)0x0) {
    *param_2 = byte_F012F418;
    param_2[1] = DAT_f012f419._0_1_;
    param_2[2] = DAT_f012f419._1_1_;
    param_2[3] = DAT_f012f419._2_1_;
    param_2[4] = DAT_f012f419._3_1_;
    param_2[5] = (undefined)DAT_f012f419;
  }
  uVar2 = 1;
locret_F002E5BC:
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=708 start=0xf002e5c4 */

undefined8 _ether_sprintf(byte *param_1)

{
  byte bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
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
  iVar4 = 0;
  puVar2 = unk_F012F41E;
  do {
    puVar3 = puVar2;
    iVar4 = iVar4 + 1;
    *puVar3 = a0123456789abcd[*param_1 >> 4];
    bVar1 = *param_1;
    param_1 = param_1 + 1;
    puVar3[1] = a0123456789abcd[bVar1 & 0xf];
    puVar3[2] = 0x3a;
    puVar2 = puVar3 + 3;
  } while (iVar4 < 6);
  puVar3[2] = 0;
  return CONCAT44(iVar4,unk_F012F41E);
}
/* GHIDRADEC_FUNCTION index=709 start=0xf002e634 */

/* WARNING: Removing unreachable block (ram,0xf002e640) */

undefined8 _inet_hash(int param_1,undefined4 *param_2)

{
  undefined *puVar1;
  undefined *puVar2;
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
  puVar1 = (undefined *)((int)register0x00000038 + -0xc);
  *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(param_1 + 4);
  _in_netof();
  puVar2 = (undefined *)0x0;
  if (puVar1 != (undefined *)0x0) {
    puVar2 = puVar1;
    if (((uint)puVar1 & 0xff) != 0) {
      param_2[1] = puVar1;
      goto loc_F002E670;
    }
    do {
      puVar2 = (undefined *)((uint)puVar2 >> 8);
    } while (((uint)puVar2 & 0xff) == 0);
  }
  param_2[1] = puVar2;
loc_F002E670:
  *param_2 = *(undefined4 *)(param_1 + 4);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=710 start=0xf002e680 */

/* WARNING: Removing unreachable block (ram,0xf002e6a0) */
/* WARNING: Removing unreachable block (ram,0xf002e68c) */

undefined8 _inet_netmatch(int param_1,int param_2)

{
  undefined *puVar1;
  undefined *puVar2;
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
  puVar1 = (undefined *)((int)register0x00000038 + -0xc);
  *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(param_1 + 4);
  _in_netof(puVar1);
  puVar2 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0x10) = *(undefined4 *)(param_2 + 4);
  _in_netof(puVar2);
  return CONCAT44(param_2,(uint)(puVar1 == puVar2));
}
/* GHIDRADEC_FUNCTION index=711 start=0xf002e6bc */

undefined8 _in_makeaddr(uint param_1,uint param_2)

{
  uint uVar1;
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
  int iVar2;
  undefined4 unaff_i3;
  uint uVar3;
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
  if ((param_1 & 0x80000000) == 0) {
    uVar3 = 0xffffff;
  }
  else {
    uVar3 = 0xff;
    if ((param_1 & 0xc0000000) == 0x80000000) {
      uVar3 = 0xffff;
    }
  }
  if (_in_ifaddr != 0) {
    uVar1 = *(uint *)(_in_ifaddr + 0x2c);
    iVar2 = _in_ifaddr;
    while ((uVar1 & param_1) != *(uint *)(iVar2 + 0x28)) {
      iVar2 = *(int *)(iVar2 + 0x40);
      if (iVar2 == 0) goto loc_F002E744;
      uVar1 = *(uint *)(iVar2 + 0x2c);
    }
    uVar3 = ~*(uint *)(iVar2 + 0x34);
  }
loc_F002E744:
  param_1 = param_1 | param_2 & uVar3;
  *(uint *)((int)register0x00000038 + -0xc) = param_1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=712 start=0xf002e754 */

undefined8 _in_netof(uint *param_1)

{
  uint uVar1;
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
  uint uVar4;
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
  uVar4 = *param_1;
  if ((uVar4 & 0x80000000) == 0) {
    uVar3 = uVar4 & 0xff000000;
  }
  else if ((uVar4 & 0xc0000000) == 0x80000000) {
    uVar3 = uVar4 & 0xffff0000;
  }
  else if ((uVar4 & 0xe0000000) == 0xc0000000) {
    uVar3 = uVar4 & 0xffffff00;
  }
  else {
    uVar3 = uVar4 & 0xf0000000;
    if (uVar3 != 0xe0000000) {
      uVar3 = 0;
      goto locret_F002E800;
    }
  }
  if (_in_ifaddr != 0) {
    uVar1 = *(uint *)(_in_ifaddr + 0x28);
    iVar2 = _in_ifaddr;
    while (uVar3 != uVar1) {
      iVar2 = *(int *)(iVar2 + 0x40);
      if (iVar2 == 0) goto locret_F002E800;
      uVar1 = *(uint *)(iVar2 + 0x28);
    }
    uVar3 = uVar4 & *(uint *)(iVar2 + 0x34);
  }
locret_F002E800:
  return CONCAT44(uVar4,uVar3);
}
/* GHIDRADEC_FUNCTION index=713 start=0xf002e808 */

undefined8 _in_lnaof(uint *param_1)

{
  uint uVar1;
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
  uint uVar4;
  undefined4 unaff_i2;
  uint uVar5;
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
  uVar3 = *param_1;
  if ((uVar3 & 0x80000000) == 0) {
    uVar5 = uVar3 & 0xff000000;
    uVar4 = uVar3 & 0xffffff;
  }
  else {
    uVar4 = 0xc0000000;
    if ((uVar3 & 0xc0000000) == 0x80000000) {
      uVar5 = uVar3 & 0xffff0000;
      uVar4 = uVar3 & 0xffff;
    }
    else if ((uVar3 & 0xe0000000) == 0xc0000000) {
      uVar5 = uVar3 & 0xffffff00;
      uVar4 = uVar3 & 0xff;
    }
    else {
      if ((uVar3 & 0xf0000000) != 0xe0000000) goto locret_F002E8D4;
      uVar4 = uVar3 & 0xfffffff;
      uVar5 = 0xe0000000;
    }
  }
  uVar3 = uVar4;
  if (_in_ifaddr != 0) {
    uVar1 = *(uint *)(_in_ifaddr + 0x28);
    iVar2 = _in_ifaddr;
    while (uVar5 != uVar1) {
      iVar2 = *(int *)(iVar2 + 0x40);
      if (iVar2 == 0) goto locret_F002E8D4;
      uVar1 = *(uint *)(iVar2 + 0x28);
    }
    uVar3 = uVar4 & ~*(uint *)(iVar2 + 0x34);
  }
locret_F002E8D4:
  return CONCAT44(uVar4,uVar3);
}
/* GHIDRADEC_FUNCTION index=714 start=0xf002e8dc */

undefined8 _in_localaddr(uint *param_1)

{
  uint uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
  undefined4 unaff_i1;
  int iVar3;
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
  iVar3 = _in_ifaddr;
  if (_subnetsarelocal == 0) {
    if (_in_ifaddr == 0) {
      uVar2 = 0;
    }
    else {
      uVar1 = *(uint *)(_in_ifaddr + 0x34);
      while ((*param_1 & uVar1) != *(uint *)(iVar3 + 0x30)) {
        iVar3 = *(int *)(iVar3 + 0x40);
        if (iVar3 == 0) {
          uVar2 = 0;
          goto locret_F002E978;
        }
        uVar1 = *(uint *)(iVar3 + 0x34);
      }
      uVar2 = 1;
    }
  }
  else if (_in_ifaddr == 0) {
    uVar2 = 0;
  }
  else {
    uVar1 = *(uint *)(_in_ifaddr + 0x2c);
    while ((*param_1 & uVar1) != *(uint *)(iVar3 + 0x28)) {
      iVar3 = *(int *)(iVar3 + 0x40);
      if (iVar3 == 0) {
        uVar2 = 0;
        goto locret_F002E978;
      }
      uVar1 = *(uint *)(iVar3 + 0x2c);
    }
    uVar2 = 1;
  }
locret_F002E978:
  return CONCAT44(iVar3,uVar2);
}
/* GHIDRADEC_FUNCTION index=715 start=0xf002e980 */

undefined8 _in_canforward(uint *param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar1;
  undefined4 uVar2;
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
  uVar1 = *param_1;
  if ((uVar1 & 0xe0000000) != 0xe0000000) {
    if ((int)uVar1 < 0) {
      uVar2 = 1;
      goto locret_F002E9C4;
    }
    if (((uVar1 & 0xff000000) != 0) && (uVar2 = 1, (uVar1 & 0xff000000) != 0x7f))
    goto locret_F002E9C4;
  }
  uVar2 = 0;
locret_F002E9C4:
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=716 start=0xf002e9cc */

/* WARNING: Removing unreachable block (ram,0xf002ee5c) */
/* WARNING: Removing unreachable block (ram,0xf002ef2c) */
/* WARNING: Removing unreachable block (ram,0xf002eef0) */
/* WARNING: Removing unreachable block (ram,0xf002eacc) */
/* WARNING: Removing unreachable block (ram,0xf002ea94) */
/* WARNING: Removing unreachable block (ram,0xf002eab4) */
/* WARNING: Removing unreachable block (ram,0xf002ef78) */
/* WARNING: Removing unreachable block (ram,0xf002efcc) */
/* WARNING: Removing unreachable block (ram,0xf002ede8) */
/* WARNING: Removing unreachable block (ram,0xf002ee74) */
/* WARNING: Removing unreachable block (ram,0xf002eb90) */

undefined8 _in_control(undefined4 param_1,int param_2,int param_3,int param_4)

{
  word wVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined2 *puVar6;
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
  bool bVar7;
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
  puVar6 = (undefined2 *)0x0;
  if ((param_4 != 0) && (puVar6 = _in_ifaddr, _in_ifaddr != (undefined2 *)0x0)) {
    iVar2 = *(int *)(_in_ifaddr + 0x10);
    while ((iVar2 != param_4 &&
           (puVar6 = *(undefined2 **)(puVar6 + 0x20), puVar6 != (undefined2 *)0x0))) {
      iVar2 = *(int *)(puVar6 + 0x10);
    }
  }
  iVar2 = -0x7fdf96ed;
  if (param_2 == -0x7fdf96ed) {
    _suser();
    if (iVar2 == 0) goto loc_F002EBA4;
loc_F002EBB4:
    if (puVar6 == (undefined2 *)0x0) {
      iVar2 = 0x31;
      goto locret_F002EFE0;
    }
  }
  else {
    if (param_2 < -0x7fdf96ec) {
      iVar2 = -0x7fdf9800;
      if (param_2 != -0x7fdf96f4) {
        iVar2 = -0x7fdf96f2;
loc_F002EA6C:
        if (param_2 != iVar2) goto loc_F002EBB4;
      }
    }
    else {
      iVar2 = -0x7fdf96de;
      if (param_2 != -0x7fdf96de) {
        if (param_2 < -0x7fdf96dd) {
          iVar2 = -0x7fdf96ea;
          goto loc_F002EA6C;
        }
        if (param_2 != -0x3fdf96df) goto loc_F002EBB4;
        goto loc_F002EBC8;
      }
    }
    _suser();
    if (iVar2 == 0) {
loc_F002EBA4:
      iVar2 = (int)*(char *)(dword_F0133DDC + 0x38);
      goto locret_F002EFE0;
    }
    if (param_4 == 0) {
      _panic(aInControl);
    }
    if (puVar6 == (undefined2 *)0x0) {
      iVar2 = 1;
      _m_getclr(1,0xd);
      if (iVar2 == 0) {
        iVar2 = 0x37;
        goto locret_F002EFE0;
      }
      if (_in_ifaddr == (undefined2 *)0x0) {
        _in_ifaddr = (undefined2 *)(iVar2 + *(int *)(iVar2 + 4));
      }
      else {
        iVar4 = *(int *)(_in_ifaddr + 0x20);
        puVar6 = _in_ifaddr;
        while (iVar4 != 0) {
          puVar6 = *(undefined2 **)(puVar6 + 0x20);
          iVar4 = *(int *)(puVar6 + 0x20);
        }
        *(int *)(puVar6 + 0x20) = iVar2 + *(int *)(iVar2 + 4);
      }
      iVar4 = *(int *)(param_4 + 0x18);
      puVar6 = (undefined2 *)(iVar2 + *(int *)(iVar2 + 4));
      if (iVar4 == 0) {
        *(undefined2 **)(param_4 + 0x18) = puVar6;
      }
      else {
        iVar2 = *(int *)(iVar4 + 0x24);
        while (iVar2 != 0) {
          iVar4 = *(int *)(iVar4 + 0x24);
          iVar2 = *(int *)(iVar4 + 0x24);
        }
        *(undefined2 **)(iVar4 + 0x24) = puVar6;
      }
      *(int *)(puVar6 + 0x10) = param_4;
      *puVar6 = 2;
      if ((*(word *)(param_4 + 0xc) & 8) == 0) {
        _in_interfaces = _in_interfaces + 1;
      }
    }
  }
loc_F002EBC8:
  if (param_2 == -0x7fdf96de) {
    uVar3 = *(uint *)(puVar6 + 0x1e);
    *(uint *)(puVar6 + 0x1e) = uVar3 & 0xfffffffd;
    if ((*(word *)(param_4 + 0xc) & 1) != 0) {
      *(uint *)(puVar6 + 0x1e) = uVar3 & 0xfffffffd | 4;
      param_2 = 1;
      bVar7 = false;
      iVar2 = -5;
      iVar4 = 0;
      do {
        iVar5 = 0x20;
        if (iVar2 == 0 || iVar2 < 0 != bVar7) {
          iVar5 = (1 << ((byte)iVar4 & 0x1f)) >> 1;
        }
        iVar2 = param_4;
        _icmp_sendMaskPacket(param_4,0x11,iVar5);
        if (iVar2 != 0) goto locret_F002EFE0;
        iVar5 = iVar4 + 1;
        if ((*(uint *)(puVar6 + 0x1e) & 4) == 0) goto loc_F002EFDC;
        bVar7 = SBORROW4(iVar5,5);
        iVar2 = iVar4 + -4;
        iVar4 = iVar5;
      } while (iVar5 < 5);
    }
    iVar2 = 0x32;
    goto locret_F002EFE0;
  }
  if (param_2 < -0x7fdf96dd) {
    if (param_2 == -0x7fdf96f2) {
      if ((*(word *)(param_4 + 0xc) & 0x10) == 0) {
        iVar2 = 0x16;
        goto locret_F002EFE0;
      }
      *(undefined2 *)((int)register0x00000038 + -0x18) = puVar6[8];
      *(undefined2 *)((int)register0x00000038 + -0x16) = puVar6[9];
      *(undefined2 *)((int)register0x00000038 + -0x14) = puVar6[10];
      *(undefined2 *)((int)register0x00000038 + -0x12) = puVar6[0xb];
      *(undefined2 *)((int)register0x00000038 + -0x10) = puVar6[0xc];
      *(undefined2 *)((int)register0x00000038 + -0xe) = puVar6[0xd];
      *(undefined2 *)((int)register0x00000038 + -0xc) = puVar6[0xe];
      *(undefined2 *)((int)register0x00000038 + -10) = puVar6[0xf];
      puVar6[8] = *(undefined2 *)(param_3 + 0x10);
      puVar6[9] = *(undefined2 *)(param_3 + 0x12);
      puVar6[10] = *(undefined2 *)(param_3 + 0x14);
      puVar6[0xb] = *(undefined2 *)(param_3 + 0x16);
      puVar6[0xc] = *(undefined2 *)(param_3 + 0x18);
      puVar6[0xd] = *(undefined2 *)(param_3 + 0x1a);
      puVar6[0xe] = *(undefined2 *)(param_3 + 0x1c);
      puVar6[0xf] = *(undefined2 *)(param_3 + 0x1e);
      if (*(int *)(param_4 + 0x38) != 0) {
        _if_ioctl(param_4,0x8020690e,puVar6);
        if (param_4 != 0) {
          puVar6[8] = *(undefined2 *)((int)register0x00000038 + -0x18);
          puVar6[9] = *(undefined2 *)((int)register0x00000038 + -0x16);
          puVar6[10] = *(undefined2 *)((int)register0x00000038 + -0x14);
          puVar6[0xb] = *(undefined2 *)((int)register0x00000038 + -0x12);
          puVar6[0xc] = *(undefined2 *)((int)register0x00000038 + -0x10);
          puVar6[0xd] = *(undefined2 *)((int)register0x00000038 + -0xe);
          puVar6[0xe] = *(undefined2 *)((int)register0x00000038 + -0xc);
          puVar6[0xf] = *(undefined2 *)((int)register0x00000038 + -10);
          iVar2 = param_4;
          goto locret_F002EFE0;
        }
      }
      if ((*(uint *)(puVar6 + 0x1e) & 1) != 0) {
        _rtinit((undefined *)((int)register0x00000038 + -0x18),puVar6,0x8030720b,4);
        _rtinit(puVar6 + 8,puVar6,0x8030720a,5);
        iVar2 = 0;
        goto locret_F002EFE0;
      }
    }
    else {
      if (param_2 < -0x7fdf96f1) {
        if (param_2 == -0x7fdf96f4) {
          *(word *)(param_4 + 0xc) = *(word *)(param_4 + 0xc) & 0x7fff;
          _in_ifinit(param_4,puVar6,param_3 + 0x10);
          iVar2 = param_4;
          goto locret_F002EFE0;
        }
loc_F002EFB0:
        iVar2 = 0x2d;
        if ((param_4 != 0) && (*(int *)(param_4 + 0x38) != 0)) {
          _if_ioctl(param_4,param_2,param_3);
          iVar2 = param_4;
        }
        goto locret_F002EFE0;
      }
      if (param_2 == -0x7fdf96ed) {
        if ((*(word *)(param_4 + 0xc) & 2) == 0) {
          iVar2 = 0x16;
          goto locret_F002EFE0;
        }
        puVar6[8] = *(undefined2 *)(param_3 + 0x10);
        puVar6[9] = *(undefined2 *)(param_3 + 0x12);
        puVar6[10] = *(undefined2 *)(param_3 + 0x14);
        puVar6[0xb] = *(undefined2 *)(param_3 + 0x16);
        puVar6[0xc] = *(undefined2 *)(param_3 + 0x18);
        puVar6[0xd] = *(undefined2 *)(param_3 + 0x1a);
        puVar6[0xe] = *(undefined2 *)(param_3 + 0x1c);
        puVar6[0xf] = *(undefined2 *)(param_3 + 0x1e);
      }
      else {
        if (param_2 != -0x7fdf96ea) goto loc_F002EFB0;
        *(uint *)(puVar6 + 0x1e) = *(uint *)(puVar6 + 0x1e) & 0xfffffff9;
        iVar2 = *(int *)(param_3 + 0x14);
        *(int *)(puVar6 + 0x1a) = iVar2;
        if (iVar2 != 0) {
          *(uint *)(puVar6 + 0x1e) = *(uint *)(puVar6 + 0x1e) | 2;
          _icmp_sendMaskPacket(param_4,0x12,0);
          iVar2 = 0;
          goto locret_F002EFE0;
        }
      }
    }
  }
  else if (param_2 == -0x3fdf96f1) {
    wVar1 = *(word *)(param_4 + 0xc) & 0x10;
loc_F002ECEC:
    if (wVar1 == 0) {
      iVar2 = 0x16;
      goto locret_F002EFE0;
    }
    *(undefined2 *)(param_3 + 0x10) = puVar6[8];
    *(undefined2 *)(param_3 + 0x12) = puVar6[9];
    *(undefined2 *)(param_3 + 0x14) = puVar6[10];
    *(undefined2 *)(param_3 + 0x16) = puVar6[0xb];
    *(undefined2 *)(param_3 + 0x18) = puVar6[0xc];
    *(undefined2 *)(param_3 + 0x1a) = puVar6[0xd];
    *(undefined2 *)(param_3 + 0x1c) = puVar6[0xe];
    *(undefined2 *)(param_3 + 0x1e) = puVar6[0xf];
  }
  else if (param_2 < -0x3fdf96f0) {
    if (param_2 != -0x3fdf96f3) goto loc_F002EFB0;
    *(undefined2 *)(param_3 + 0x10) = *puVar6;
    *(undefined2 *)(param_3 + 0x12) = puVar6[1];
    *(undefined2 *)(param_3 + 0x14) = puVar6[2];
    *(undefined2 *)(param_3 + 0x16) = puVar6[3];
    *(undefined2 *)(param_3 + 0x18) = puVar6[4];
    *(undefined2 *)(param_3 + 0x1a) = puVar6[5];
    *(undefined2 *)(param_3 + 0x1c) = puVar6[6];
    *(undefined2 *)(param_3 + 0x1e) = puVar6[7];
  }
  else {
    if (param_2 == -0x3fdf96ee) {
      wVar1 = *(word *)(param_4 + 0xc) & 2;
      goto loc_F002ECEC;
    }
    if (param_2 != -0x3fdf96eb) goto loc_F002EFB0;
    *(undefined2 *)(param_3 + 0x10) = 2;
    *(undefined4 *)(param_3 + 0x14) = *(undefined4 *)(puVar6 + 0x1a);
  }
loc_F002EFDC:
  iVar2 = 0;
locret_F002EFE0:
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=717 start=0xf002efe8 */

/* WARNING: Removing unreachable block (ram,0xf002f2a8) */
/* WARNING: Removing unreachable block (ram,0xf002f264) */
/* WARNING: Removing unreachable block (ram,0xf002f184) */
/* WARNING: Removing unreachable block (ram,0xf002f0fc) */
/* WARNING: Removing unreachable block (ram,0xf002f094) */
/* WARNING: Removing unreachable block (ram,0xf002f0a8) */
/* WARNING: Removing unreachable block (ram,0xf002f164) */
/* WARNING: Removing unreachable block (ram,0xf002f204) */
/* WARNING: Removing unreachable block (ram,0xf002f284) */
/* WARNING: Removing unreachable block (ram,0xf002f2b0) */
/* WARNING: Removing unreachable block (ram,0xf002efec) */

undefined8 _in_ifinit(int param_1,undefined2 *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 unaff_l0;
  uint uVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar5;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined2 *puVar6;
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
  uVar4 = *(uint *)(param_3 + 2);
  iVar1 = param_1;
  _spltty();
  *(undefined2 *)((int)register0x00000038 + -0x18) = *param_2;
  *(undefined2 *)((int)register0x00000038 + -0x16) = param_2[1];
  *(undefined2 *)((int)register0x00000038 + -0x14) = param_2[2];
  *(undefined2 *)((int)register0x00000038 + -0x12) = param_2[3];
  *(undefined2 *)((int)register0x00000038 + -0x10) = param_2[4];
  *(undefined2 *)((int)register0x00000038 + -0xe) = param_2[5];
  *(undefined2 *)((int)register0x00000038 + -0xc) = param_2[6];
  *(undefined2 *)((int)register0x00000038 + -10) = param_2[7];
  *param_2 = *param_3;
  param_2[1] = param_3[1];
  param_2[2] = param_3[2];
  param_2[3] = param_3[3];
  param_2[4] = param_3[4];
  param_2[5] = param_3[5];
  param_2[6] = param_3[6];
  param_2[7] = param_3[7];
  if ((*(int *)(param_1 + 0x38) == 0) ||
     (iVar5 = param_1, _if_ioctl(param_1,0x8020690c,param_2), iVar5 == 0)) {
    puVar6 = (undefined2 *)((int)register0x00000038 + -0x28);
    _bzero(puVar6,0x10);
    *(undefined2 *)((int)register0x00000038 + -0x28) = 2;
    if ((*(uint *)(param_2 + 0x1e) & 1) != 0) {
      if ((*(word *)(param_1 + 0xc) & 8) == 0) {
        if ((*(word *)(param_1 + 0xc) & 0x10) == 0) {
          uVar2 = *(undefined4 *)(param_2 + 0x18);
          _in_makeaddr(uVar2,0);
          *(undefined4 *)((int)register0x00000038 + -0x24) = uVar2;
          uVar2 = 0;
        }
        else {
          uVar2 = 4;
          puVar6 = param_2 + 8;
        }
      }
      else {
        uVar2 = 4;
        puVar6 = (undefined2 *)((int)register0x00000038 + -0x18);
      }
      _rtinit(puVar6,(undefined *)((int)register0x00000038 + -0x18),0x8030720b,uVar2);
      *(uint *)(param_2 + 0x1e) = *(uint *)(param_2 + 0x1e) & 0xfffffffe;
    }
    if ((uVar4 & 0x80000000) == 0) {
      uVar2 = 0xff000000;
    }
    else {
      uVar2 = 0xffffff00;
      if ((uVar4 & 0xc0000000) == 0x80000000) {
        uVar2 = 0xffff0000;
      }
    }
    *(undefined4 *)(param_2 + 0x16) = uVar2;
    uVar3 = *(uint *)(param_2 + 0x1a);
    *(uint *)(param_2 + 0x14) = uVar4 & *(uint *)(param_2 + 0x16);
    *(uint *)(param_2 + 0x1a) = uVar3 | *(uint *)(param_2 + 0x16);
    *(uint *)(param_2 + 0x18) = uVar4 & (uVar3 | *(uint *)(param_2 + 0x16));
    if ((*(word *)(param_1 + 0xc) & 2) != 0) {
      param_2[8] = 2;
      uVar2 = *(undefined4 *)(param_2 + 0x18);
      _in_makeaddr(uVar2,0xffffffff);
      *(undefined4 *)(param_2 + 10) = uVar2;
      *(uint *)(param_2 + 0x1c) = *(uint *)(param_2 + 0x14) | ~*(uint *)(param_2 + 0x16);
    }
    if ((*(word *)(param_1 + 0xc) & 8) == 0) {
      if ((*(word *)(param_1 + 0xc) & 0x10) == 0) {
        uVar2 = *(undefined4 *)(param_2 + 0x18);
        _in_makeaddr(uVar2,0);
        *(undefined4 *)((int)register0x00000038 + -0x24) = uVar2;
        puVar6 = (undefined2 *)((int)register0x00000038 + -0x28);
        uVar2 = 1;
      }
      else {
        puVar6 = param_2 + 8;
        uVar2 = 5;
      }
    }
    else {
      uVar2 = 5;
      puVar6 = param_2;
    }
    iVar5 = 0;
    _rtinit(puVar6,param_2,0x8030720a,uVar2);
    *(uint *)(param_2 + 0x1e) = *(uint *)(param_2 + 0x1e) | 1;
    *(undefined4 *)((int)register0x00000038 + -0x2c) = 0xe0000001;
    _in_addmulti((undefined *)((int)register0x00000038 + -0x2c),param_1);
    _splx(iVar1);
  }
  else {
    _splx(iVar1);
    *param_2 = *(undefined2 *)((int)register0x00000038 + -0x18);
    param_2[1] = *(undefined2 *)((int)register0x00000038 + -0x16);
    param_2[2] = *(undefined2 *)((int)register0x00000038 + -0x14);
    param_2[3] = *(undefined2 *)((int)register0x00000038 + -0x12);
    param_2[4] = *(undefined2 *)((int)register0x00000038 + -0x10);
    param_2[5] = *(undefined2 *)((int)register0x00000038 + -0xe);
    param_2[6] = *(undefined2 *)((int)register0x00000038 + -0xc);
    param_2[7] = *(undefined2 *)((int)register0x00000038 + -10);
  }
  return CONCAT44(param_2,iVar5);
}
/* GHIDRADEC_FUNCTION index=718 start=0xf002f2c0 */

undefined8 _in_iaonnetof(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar2;
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
  if (_in_ifaddr == 0) {
    iVar2 = 0;
  }
  else {
    iVar1 = *(int *)(_in_ifaddr + 0x30);
    iVar2 = _in_ifaddr;
    while (iVar1 != param_1) {
      iVar2 = *(int *)(iVar2 + 0x40);
      if (iVar2 == 0) {
        iVar2 = 0;
        break;
      }
      iVar1 = *(int *)(iVar2 + 0x30);
    }
  }
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=719 start=0xf002f308 */

undefined8 _in_broadcast(int *param_1,undefined4 param_2)

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
  iVar3 = *param_1;
  if (_in_ifaddr != 0) {
    iVar1 = *(int *)(_in_ifaddr + 0x20);
    iVar2 = _in_ifaddr;
    while( true ) {
      if ((*(word *)(iVar1 + 0xc) & 2) == 0) {
        iVar2 = *(int *)(iVar2 + 0x40);
      }
      else {
        if (*(int *)(iVar2 + 0x14) == iVar3) {
          uVar4 = 1;
          goto locret_F002F38C;
        }
        if (iVar3 == *(int *)(iVar2 + 0x30)) {
          uVar4 = 1;
          goto locret_F002F38C;
        }
        if (iVar3 == *(int *)(iVar2 + 0x28)) {
          uVar4 = 1;
          goto locret_F002F38C;
        }
        iVar2 = *(int *)(iVar2 + 0x40);
      }
      if (iVar2 == 0) break;
      iVar1 = *(int *)(iVar2 + 0x20);
    }
  }
  if ((iVar3 == -1) || (uVar4 = 0, iVar3 == 0)) {
    uVar4 = 1;
  }
locret_F002F38C:
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=720 start=0xf002f394 */

/* WARNING: Removing unreachable block (ram,0xf002f438) */
/* WARNING: Removing unreachable block (ram,0xf002f3f8) */
/* WARNING: Removing unreachable block (ram,0xf002f3ec) */
/* WARNING: Removing unreachable block (ram,0xf002f41c) */
/* WARNING: Removing unreachable block (ram,0xf002f450) */
/* WARNING: Removing unreachable block (ram,0xf002f3d4) */

undefined8 _inet_ntoa(undefined4 *param_1,undefined4 param_2)

{
  byte bVar2;
  uint uVar1;
  undefined4 unaff_l0;
  undefined *puVar3;
  char *pcVar4;
  undefined4 unaff_l1;
  byte *pbVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar6;
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
  byte abStack_c [12];
  
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
  puVar3 = unk_F012F430;
  pbVar5 = (byte *)((int)register0x00000038 + -0xc);
  iVar6 = 0;
  *(undefined4 *)((int)register0x00000038 + -0xc) = *param_1;
  do {
    if (iVar6 != 0) {
      *puVar3 = '.';
      puVar3 = puVar3 + 1;
    }
    bVar2 = *pbVar5;
    pcVar4 = puVar3;
    if (99 < bVar2) {
      .udiv(bVar2,100);
      *puVar3 = bVar2 + 0x30;
      pcVar4 = puVar3 + 1;
      uVar1 = (uint)*pbVar5;
      .urem(uVar1,100);
      uVar1 = uVar1 & 0xff;
      .udiv(uVar1,10);
      if ((uVar1 & 0xff) == 0) {
        *pcVar4 = '0';
        pcVar4 = puVar3 + 2;
        bVar2 = *pbVar5;
      }
      else {
        bVar2 = *pbVar5;
      }
      .urem(bVar2,100);
      *pbVar5 = bVar2;
      bVar2 = *pbVar5;
    }
    if (9 < bVar2) {
      .udiv(bVar2,10);
      *pcVar4 = bVar2 + 0x30;
      pcVar4 = pcVar4 + 1;
      bVar2 = *pbVar5;
      .urem(bVar2,10);
      *pbVar5 = bVar2;
    }
    iVar6 = iVar6 + 1;
    *pcVar4 = *pbVar5 + 0x30;
    puVar3 = pcVar4 + 1;
    pbVar5 = pbVar5 + 1;
  } while (iVar6 < 4);
  *puVar3 = '\0';
  return CONCAT44(param_2,unk_F012F430);
}
/* GHIDRADEC_FUNCTION index=721 start=0xf002f490 */

/* WARNING: Removing unreachable block (ram,0xf002f5ec) */
/* WARNING: Removing unreachable block (ram,0xf002f524) */
/* WARNING: Removing unreachable block (ram,0xf002f4fc) */
/* WARNING: Removing unreachable block (ram,0xf002f4b4) */
/* WARNING: Removing unreachable block (ram,0xf002f570) */
/* WARNING: Removing unreachable block (ram,0xf002f57c) */
/* WARNING: Removing unreachable block (ram,0xf002f5f4) */
/* WARNING: Removing unreachable block (ram,0xf002f4a8) */

undefined8 _inet_queue(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined *puVar2;
  uint uVar3;
  undefined4 *puVar4;
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
  bool bVar5;
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
  _netisr = _netisr | 4;
  _wakeup(_soft_net_wakeup);
  puVar2 = DAT_f0136400;
  _spltty();
  if (DAT_f0136488 < dword_F013648C) {
    uVar3 = param_2[1] - 0x10;
    if (uVar3 < 0x6d) {
      param_2[1] = param_2[1] + -4;
      *(sword *)(param_2 + 2) = *(sword *)(param_2 + 2) + 4;
      puVar4 = param_2;
loc_F002F5A0:
      bVar5 = puVar4 == (undefined4 *)0x0;
    }
    else {
      _spltty();
      puVar4 = _mfree;
      if (_mfree == (undefined4 *)0x0) {
        puVar4 = (undefined4 *)0x0;
        _m_more(0,2);
      }
      else {
        if (*(sword *)((int)_mfree + 10) != 0) {
          _panic(&aMget_7);
        }
        *(undefined2 *)((int)puVar4 + 10) = 2;
        word_F0134B0C = word_F0134B0C + -1;
        DAT_f0134b10._0_2_ = DAT_f0134b10._0_2_ + 1;
        _mfree = (undefined4 *)*puVar4;
        puVar4[1] = 0xc;
        *puVar4 = 0;
      }
      _splx(uVar3);
      bVar5 = puVar4 == (undefined4 *)0x0;
      if (!bVar5) {
        puVar4[1] = 0xc;
        *(undefined2 *)(puVar4 + 2) = 4;
        *puVar4 = param_2;
        goto loc_F002F5A0;
      }
    }
    if (!bVar5) {
      *(undefined4 *)((int)puVar4 + puVar4[1]) = param_1;
      puVar4[0x1f] = 0;
      puVar1 = puVar4;
      if (DAT_f0136484._0_4_ != (undefined4 *)0x0) {
        DAT_f0136484._0_4_[0x1f] = puVar4;
        puVar1 = _ipintrq;
      }
      _ipintrq = puVar1;
      DAT_f0136488 = DAT_f0136488 + 1;
      DAT_f0136484._0_4_ = puVar4;
      goto loc_F002F5F4;
    }
  }
  DAT_f0136490._0_4_ = DAT_f0136490._0_4_ + 1;
  _m_freem(param_2);
loc_F002F5F4:
  _splx(puVar2);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=722 start=0xf002f604 */

/* WARNING: Removing unreachable block (ram,0xf002f77c) */
/* WARNING: Removing unreachable block (ram,0xf002f774) */
/* WARNING: Removing unreachable block (ram,0xf002f6dc) */
/* WARNING: Removing unreachable block (ram,0xf002f748) */
/* WARNING: Removing unreachable block (ram,0xf002f764) */
/* WARNING: Removing unreachable block (ram,0xf002f6f0) */
/* WARNING: Removing unreachable block (ram,0xf002f608) */

undefined8 _in_addmulti(int *param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar2;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
  int *piVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar5;
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
  iVar2 = *param_1;
  _splnet();
  bVar5 = _in_ifaddr == 0;
  iVar3 = _in_ifaddr;
  if (!bVar5) {
    iVar1 = *(int *)(_in_ifaddr + 0x20);
    while (bVar5 = iVar3 == 0, iVar1 != param_2) {
      iVar3 = *(int *)(iVar3 + 0x40);
      if (iVar3 == 0) {
        bVar5 = true;
        break;
      }
      iVar1 = *(int *)(iVar3 + 0x20);
    }
  }
  if (bVar5) {
    piVar4 = (int *)0x0;
loc_F002F688:
    if (piVar4 == (int *)0x0) goto loc_F002F6A0;
    piVar4[3] = piVar4[3] + 1;
loc_F002F77C:
    _splx(param_1);
  }
  else {
    piVar4 = *(int **)(iVar3 + 0x44);
    if (piVar4 != (int *)0x0) {
      iVar3 = *piVar4;
      while ((iVar3 != iVar2 && (piVar4 = (int *)piVar4[5], piVar4 != (int *)0x0))) {
        iVar3 = *piVar4;
      }
      goto loc_F002F688;
    }
loc_F002F6A0:
    if (_in_ifaddr != 0) {
      iVar1 = *(int *)(_in_ifaddr + 0x20);
      iVar3 = _in_ifaddr;
      while ((iVar1 != param_2 && (iVar3 = *(int *)(iVar3 + 0x40), iVar3 != 0))) {
        iVar1 = *(int *)(iVar3 + 0x20);
      }
      iVar1 = 0;
      if ((iVar3 != 0) && (_m_getclr(0,0xf), iVar1 != 0)) {
        piVar4 = (int *)(iVar1 + *(int *)(iVar1 + 4));
        *(int *)(iVar1 + *(int *)(iVar1 + 4)) = iVar2;
        piVar4[1] = param_2;
        piVar4[3] = 1;
        piVar4[2] = iVar3;
        piVar4[5] = *(int *)(iVar3 + 0x44);
        *(int **)(iVar3 + 0x44) = piVar4;
        *(undefined2 *)((int)register0x00000038 + -0x18) = 2;
        *(int *)((int)register0x00000038 + -0x14) = iVar2;
        if ((*(int *)(param_2 + 0x38) == 0) ||
           (iVar2 = param_2,
           _if_ioctl(param_2,0x80206931,(undefined *)((int)register0x00000038 + -0x28)), iVar2 != 0)
           ) {
          *(int *)(iVar3 + 0x44) = piVar4[5];
          _m_free(iVar1);
          piVar4 = (int *)0x0;
        }
        else {
          _igmp_joingroup(piVar4);
        }
        goto loc_F002F77C;
      }
    }
    _splx(param_1);
    piVar4 = (int *)0x0;
  }
  return CONCAT44(param_2,piVar4);
}
/* GHIDRADEC_FUNCTION index=723 start=0xf002f78c */

/* WARNING: Removing unreachable block (ram,0xf002f810) */
/* WARNING: Removing unreachable block (ram,0xf002f7b0) */
/* WARNING: Removing unreachable block (ram,0xf002f808) */
/* WARNING: Removing unreachable block (ram,0xf002f818) */
/* WARNING: Removing unreachable block (ram,0xf002f790) */

undefined8 _in_delmulti(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
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
  puVar1 = param_1;
  _splnet();
  iVar2 = param_1[3];
  param_1[3] = iVar2 + -1;
  if (iVar2 + -1 == 0) {
    _igmp_leavegroup(param_1);
    piVar4 = (int *)(param_1[2] + 0x44);
    puVar3 = *(undefined4 **)(param_1[2] + 0x44);
    while (puVar3 != param_1) {
      iVar2 = *piVar4;
      piVar4 = (int *)(iVar2 + 0x14);
      puVar3 = *(undefined4 **)(iVar2 + 0x14);
    }
    *piVar4 = *(int *)(*piVar4 + 0x14);
    *(undefined2 *)((int)register0x00000038 + -0x18) = 2;
    *(undefined4 *)((int)register0x00000038 + -0x14) = *param_1;
    _if_ioctl(param_1[1],0x80206932,(undefined *)((int)register0x00000038 + -0x28));
    _m_free((uint)param_1 & 0xffffff80);
  }
  _splx(puVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=724 start=0xf002f828 */

/* WARNING: Removing unreachable block (ram,0xf002f84c) */

void _in_bootp(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
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
  *(undefined4 *)((int)register0x00000038 + -0x30) = 0;
  sub_F00304F4((undefined *)((int)register0x00000038 + -0x28),param_1,param_2);
                    /* WARNING: Does not return */
  pcVar1 = (code *)IllegalInstructionTrap(0x20);
  (*pcVar1)();
}
/* GHIDRADEC_FUNCTION index=725 start=0xf002fcc4 */

/* WARNING: Removing unreachable block (ram,0xf002fe44) */
/* WARNING: Removing unreachable block (ram,0xf002fd94) */
/* WARNING: Removing unreachable block (ram,0xf002fd60) */
/* WARNING: Removing unreachable block (ram,0xf002fd54) */
/* WARNING: Removing unreachable block (ram,0xf002fd14) */
/* WARNING: Removing unreachable block (ram,0xf002fd74) */
/* WARNING: Removing unreachable block (ram,0xf002fdd8) */
/* WARNING: Removing unreachable block (ram,0xf002fe70) */
/* WARNING: Removing unreachable block (ram,0xf002fcec) */

undefined8 _in_bootp_bptombuf(undefined *param_1)

{
  int iVar1;
  int *piVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 unaff_l0;
  int iVar6;
  undefined4 unaff_l1;
  int iVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 *puVar8;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar9;
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
  iVar7 = 0x148;
  puVar3 = DAT_f0134800;
  puVar8 = (undefined4 *)((int)register0x00000038 + -0xc);
  do {
    _spltty();
    puVar4 = _mfree;
    if (_mfree == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x1;
      _m_more(1,1);
    }
    else {
      if (*(sword *)((int)_mfree + 10) != 0) {
        _panic(&aMget_8);
      }
      *(undefined2 *)((int)puVar4 + 10) = 1;
      word_F0134B0C = word_F0134B0C + -1;
      DAT_f0134b0e._0_2_ = DAT_f0134b0e._0_2_ + 1;
      _mfree = (undefined4 *)*puVar4;
      puVar4[1] = 0xc;
      *puVar4 = 0;
    }
    _splx(puVar3);
    if (iVar7 < 0x200) {
loc_F002FE24:
      iVar1 = iVar7 + -0x70;
      iVar5 = 0x70;
      iVar6 = 0x70;
    }
    else {
      _spltty();
      if (_mclfree == (int *)0x0) {
        _m_clalloc(1,1,0);
      }
      piVar2 = _mclfree;
      if (_mclfree != (int *)0x0) {
        iVar5 = (int)_mclfree - _mbutl >> 10;
        _mclrefcnt[iVar5] = _mclrefcnt[iVar5] + '\x01';
        DAT_f0134afc._0_4_ = DAT_f0134afc._0_4_ + -1;
        _mclfree = (int *)*_mclfree;
      }
      _splx(puVar3);
      if (piVar2 == (int *)0x0) {
        *(undefined2 *)(puVar4 + 2) = 0x70;
      }
      else {
        puVar4[1] = (int)piVar2 - (int)puVar4;
        *(undefined2 *)(puVar4 + 2) = 0x400;
        *(undefined2 *)(puVar4 + 3) = 1;
      }
      if (*(sword *)(puVar4 + 2) != 0x400) goto loc_F002FE24;
      iVar5 = 0x400;
      iVar1 = iVar7 + -0x400;
      iVar6 = 0x400;
    }
    if (iVar1 == 0 || iVar1 < 0 != SBORROW4(iVar7,iVar5)) {
      iVar6 = iVar7;
    }
    iVar7 = iVar7 - iVar6;
    puVar9 = param_1 + iVar6;
    _bcopy(param_1,(int)puVar4 + puVar4[1],iVar6);
    *(sword *)(puVar4 + 2) = (sword)iVar6;
    *puVar8 = puVar4;
    puVar3 = param_1;
    puVar8 = puVar4;
    param_1 = puVar9;
    if (iVar7 < 1) {
      iVar7 = *(int *)((int)register0x00000038 + -0xc);
      iVar5 = iVar7 + *(int *)(iVar7 + 4);
      *(undefined2 *)(iVar5 + 10) = 0;
      _in_cksum(iVar7,0x14);
      *(sword *)(iVar5 + 10) = (sword)iVar7;
      return CONCAT44(1,*(undefined4 *)((int)register0x00000038 + -0xc));
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=726 start=0xf003069c */

/* WARNING: Removing unreachable block (ram,0xf00306b8) */
/* WARNING: Removing unreachable block (ram,0xf00306a4) */

undefined8 _in_pcballoc(int param_1,int *param_2)

{
  int *piVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
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
  piVar1 = (int *)0x40;
  _kalloc();
  uVar2 = 0x37;
  if (piVar1 != (int *)0x0) {
    _bzero();
    piVar1[2] = (int)param_2;
    piVar1[7] = param_1;
    *piVar1 = *param_2;
    piVar1[1] = (int)param_2;
    uVar2 = 0;
    *(int **)(*param_2 + 4) = piVar1;
    *param_2 = (int)piVar1;
    *(int **)(param_1 + 8) = piVar1;
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=727 start=0xf00306f0 */

/* WARNING: Removing unreachable block (ram,0xf003082c) */
/* WARNING: Removing unreachable block (ram,0xf00308c0) */
/* WARNING: Removing unreachable block (ram,0xf003076c) */

undefined8 _in_pcbbind(int param_1,int param_2)

{
  sword *psVar1;
  undefined2 uVar2;
  int iVar3;
  word wVar4;
  undefined4 unaff_l0;
  word wVar5;
  undefined4 unaff_l1;
  int iVar6;
  int iVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar8;
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
  iVar7 = *(int *)(param_1 + 0x1c);
  wVar5 = 0;
  iVar6 = *(int *)(param_1 + 8);
  if (_in_ifaddr == 0) {
loc_F0030780:
    uVar8 = 0x31;
  }
  else {
    if (*(sword *)(param_1 + 0x18) != 0) {
      uVar8 = 0x16;
      goto locret_F00308DC;
    }
    if (*(int *)(param_1 + 0x14) != 0) {
      uVar8 = 0x16;
      goto locret_F00308DC;
    }
    if (param_2 != 0) {
      psVar1 = (sword *)(param_2 + 8);
      param_2 = param_2 + *(int *)(param_2 + 4);
      if (*psVar1 != 0x10) {
        uVar8 = 0x16;
        goto locret_F00308DC;
      }
      if (*(int *)(param_2 + 4) != 0) {
        uVar2 = *(undefined2 *)(param_2 + 2);
        *(undefined2 *)(param_2 + 2) = 0;
        iVar3 = param_2;
        _ifa_ifwithaddr();
        if (iVar3 == 0) goto loc_F0030780;
        *(undefined2 *)(param_2 + 2) = uVar2;
      }
      wVar5 = *(word *)(param_2 + 2);
      if (wVar5 == 0) {
        uVar8 = *(undefined4 *)(param_2 + 4);
      }
      else {
        uVar8 = 0;
        if (wVar5 < 0x400) {
          if (*(sword *)(*(int *)(_active_u + 0x1c) + 2) == 0) {
            wVar4 = *(word *)(iVar7 + 2);
          }
          else {
            if ((*(word *)(iVar7 + 6) & 0x80) == 0) {
              uVar8 = 0xd;
              goto locret_F00308DC;
            }
            wVar4 = *(word *)(iVar7 + 2);
          }
        }
        else {
          wVar4 = *(word *)(iVar7 + 2);
        }
        if (((wVar4 & 4) == 0) &&
           (((*(word *)(*(int *)(iVar7 + 0xc) + 10) & 4) == 0 || ((wVar4 & 2) == 0)))) {
          uVar8 = 1;
        }
        *(undefined4 *)((int)register0x00000038 + -0xc) = _zeroin_addr;
        *(undefined4 *)((int)register0x00000038 + -0x10) = *(undefined4 *)(param_2 + 4);
        iVar7 = iVar6;
        _in_pcblookup(iVar6,(undefined *)((int)register0x00000038 + -0xc),0,
                      (undefined *)((int)register0x00000038 + -0x10),wVar5,uVar8);
        if (iVar7 != 0) {
          uVar8 = 0x30;
          goto locret_F00308DC;
        }
        uVar8 = *(undefined4 *)(param_2 + 4);
      }
      *(undefined4 *)(param_1 + 0x14) = uVar8;
    }
    if (wVar5 == 0) {
      param_2 = 0xa00;
      wVar5 = *(word *)(iVar6 + 0x18);
      while( true ) {
        *(word *)(iVar6 + 0x18) = wVar5 + 1;
        if ((wVar5 < 0xa00) || (5000 < (word)(wVar5 + 1))) {
          *(undefined2 *)(iVar6 + 0x18) = 0xa00;
        }
        uVar2 = *(undefined2 *)(iVar6 + 0x18);
        *(undefined4 *)((int)register0x00000038 + -0x10) = _zeroin_addr;
        *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(param_1 + 0x14);
        iVar7 = iVar6;
        _in_pcblookup(iVar6,(undefined *)((int)register0x00000038 + -0x10),0,
                      (undefined *)((int)register0x00000038 + -0xc),uVar2,0);
        if (iVar7 == 0) break;
        wVar5 = *(word *)(iVar6 + 0x18);
      }
      *(undefined2 *)(param_1 + 0x18) = uVar2;
    }
    else {
      *(word *)(param_1 + 0x18) = wVar5;
    }
    uVar8 = 0;
  }
locret_F00308DC:
  return CONCAT44(param_2,uVar8);
}
/* GHIDRADEC_FUNCTION index=728 start=0xf00308e4 */

/* WARNING: Removing unreachable block (ram,0xf0030bac) */
/* WARNING: Removing unreachable block (ram,0xf0030ac8) */
/* WARNING: Removing unreachable block (ram,0xf0030a2c) */
/* WARNING: Removing unreachable block (ram,0xf0030aac) */
/* WARNING: Removing unreachable block (ram,0xf0030ad0) */
/* WARNING: Removing unreachable block (ram,0xf0030c44) */
/* WARNING: Removing unreachable block (ram,0xf00309d4) */

undefined8 _in_pcbconnect(int param_1,int param_2)

{
  sword sVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 unaff_l0;
  undefined *puVar6;
  int *piVar7;
  undefined4 unaff_l1;
  undefined *puVar8;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar9;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar10;
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
  puVar6 = (undefined *)0x0;
  puVar8 = (undefined *)(param_2 + *(int *)(param_2 + 4));
  if (*(sword *)(param_2 + 8) != 0x10) {
    uVar9 = 0x16;
    goto locret_F0030C68;
  }
  uVar9 = 0x2f;
  if (*(sword *)(param_2 + *(int *)(param_2 + 4)) != 2) goto locret_F0030C68;
  if (*(sword *)(puVar8 + 2) == 0) {
loc_F0030B70:
    uVar9 = 0x31;
  }
  else {
    if (_in_ifaddr == (undefined *)0x0) {
      iVar3 = *(int *)(param_1 + 0x14);
    }
    else if (*(int *)(puVar8 + 4) == 0) {
      uVar9 = *(undefined4 *)(_in_ifaddr + 4);
loc_F0030974:
      *(undefined4 *)(puVar8 + 4) = uVar9;
      iVar3 = *(int *)(param_1 + 0x14);
    }
    else if (*(int *)(puVar8 + 4) == -1) {
      if ((*(word *)(*(int *)(_in_ifaddr + 0x20) + 0xc) & 2) != 0) {
        uVar9 = *(undefined4 *)(_in_ifaddr + 0x14);
        goto loc_F0030974;
      }
      iVar3 = *(int *)(param_1 + 0x14);
    }
    else {
      iVar3 = *(int *)(param_1 + 0x14);
    }
    if (iVar3 == 0) {
      iVar3 = *(int *)(param_1 + 0x24);
      puVar6 = (undefined *)0x0;
      piVar7 = (int *)(param_1 + 0x24);
      if (iVar3 == 0) {
loc_F00309EC:
        iVar3 = *(int *)(param_1 + 0x1c);
      }
      else {
        if (*(int *)(param_1 + 0x2c) != *(int *)(puVar8 + 4)) {
          sVar1 = *(sword *)(iVar3 + 0x26);
loc_F00309C8:
          if (sVar1 == 1) {
            _rtfree(iVar3);
            *piVar7 = 0;
          }
          else {
            *(sword *)(iVar3 + 0x26) = sVar1 + -1;
            *piVar7 = 0;
          }
          goto loc_F00309EC;
        }
        if ((*(word *)(*(int *)(param_1 + 0x1c) + 2) & 0x10) != 0) {
          sVar1 = *(sword *)(iVar3 + 0x26);
          goto loc_F00309C8;
        }
        iVar3 = *(int *)(param_1 + 0x1c);
      }
      iVar4 = *piVar7;
      if ((*(word *)(iVar3 + 2) & 0x10) == 0) {
        if ((iVar4 == 0) || (*(int *)(iVar4 + 0x2c) == 0)) {
          *(undefined2 *)(param_1 + 0x28) = 2;
          *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(puVar8 + 4);
          _rtalloc(piVar7);
          iVar4 = *piVar7;
        }
        else {
          iVar4 = *piVar7;
        }
      }
      bVar10 = true;
      if (iVar4 != 0) {
        iVar3 = *(int *)(iVar4 + 0x2c);
        bVar10 = true;
        if (((iVar3 != 0) && (bVar10 = true, (*(word *)(iVar3 + 0xc) & 8) == 0)) &&
           (bVar10 = _in_ifaddr == (undefined *)0x0, puVar6 = _in_ifaddr, !bVar10)) {
          iVar4 = *(int *)(_in_ifaddr + 0x20);
          while (bVar10 = puVar6 == (undefined *)0x0, iVar4 != iVar3) {
            puVar6 = *(undefined **)(puVar6 + 0x40);
            if (puVar6 == (undefined *)0x0) {
              bVar10 = true;
              break;
            }
            iVar4 = *(int *)(puVar6 + 0x20);
          }
        }
      }
      if (bVar10) {
        uVar2 = *(undefined2 *)(puVar8 + 2);
        *(undefined2 *)(puVar8 + 2) = 0;
        puVar6 = puVar8;
        _ifa_ifwithdstaddr();
        *(undefined2 *)(puVar8 + 2) = uVar2;
        bVar10 = false;
        if (puVar6 == (undefined *)0x0) {
          puVar6 = (undefined *)((int)register0x00000038 + -0xc);
          *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(puVar8 + 4);
          _in_netof();
          _in_iaonnetof();
          bVar10 = puVar6 == (undefined *)0x0;
        }
        if (bVar10) {
          puVar6 = _in_ifaddr;
        }
        if (bVar10 && _in_ifaddr == (undefined *)0x0) {
          uVar9 = 0x31;
          goto locret_F0030C68;
        }
        uVar5 = *(uint *)(puVar8 + 4);
      }
      else {
        uVar5 = *(uint *)(puVar8 + 4);
      }
      if ((((uVar5 & 0xf0000000) == 0xe0000000) && (iVar3 = *(int *)(param_1 + 0x3c), iVar3 != 0))
         && (iVar3 = *(int *)(iVar3 + *(int *)(iVar3 + 4)), iVar3 != 0)) {
        bVar10 = _in_ifaddr == (undefined *)0x0;
        puVar6 = _in_ifaddr;
        if (!bVar10) {
          iVar4 = *(int *)(_in_ifaddr + 0x20);
          while (bVar10 = puVar6 == (undefined *)0x0, iVar4 != iVar3) {
            puVar6 = *(undefined **)(puVar6 + 0x40);
            if (puVar6 == (undefined *)0x0) {
              bVar10 = true;
              break;
            }
            iVar4 = *(int *)(puVar6 + 0x20);
          }
        }
        if (bVar10) goto loc_F0030B70;
      }
      uVar9 = *(undefined4 *)(puVar8 + 4);
    }
    else {
      uVar9 = *(undefined4 *)(puVar8 + 4);
    }
    *(undefined4 *)((int)register0x00000038 + -0xc) = uVar9;
    iVar3 = *(int *)(param_1 + 0x14);
    if (iVar3 == 0) {
      iVar3 = *(int *)(puVar6 + 4);
    }
    *(int *)((int)register0x00000038 + -0x10) = iVar3;
    iVar3 = *(int *)(param_1 + 8);
    _in_pcblookup(iVar3,(undefined *)((int)register0x00000038 + -0xc),*(undefined2 *)(puVar8 + 2),
                  (undefined *)((int)register0x00000038 + -0x10),*(undefined2 *)(param_1 + 0x18),0);
    uVar9 = 0x30;
    if (iVar3 == 0) {
      if ((*(word *)(*(int *)(*(int *)(param_1 + 0x1c) + 0xc) + 10) & 4) == 0) {
        iVar3 = *(int *)(param_1 + 0x14);
      }
      else {
        iVar3 = *(int *)(param_1 + 0x14);
        if (*(sword *)(puVar8 + 2) == *(sword *)(param_1 + 0x18)) {
          if (iVar3 == 0) {
            if (*(int *)(puVar6 + 4) == *(int *)(puVar8 + 4)) {
              uVar9 = 0x3d;
              goto locret_F0030C68;
            }
            iVar3 = *(int *)(param_1 + 0x14);
          }
          else {
            uVar9 = 0x3d;
            if (iVar3 == *(int *)(puVar8 + 4)) goto locret_F0030C68;
          }
        }
      }
      if (iVar3 == 0) {
        if (*(sword *)(param_1 + 0x18) == 0) {
          _in_pcbbind(param_1,0);
          uVar9 = *(undefined4 *)(puVar6 + 4);
        }
        else {
          uVar9 = *(undefined4 *)(puVar6 + 4);
        }
        *(undefined4 *)(param_1 + 0x14) = uVar9;
        uVar9 = *(undefined4 *)(puVar8 + 4);
      }
      else {
        uVar9 = *(undefined4 *)(puVar8 + 4);
      }
      *(undefined4 *)(param_1 + 0xc) = uVar9;
      uVar9 = 0;
      *(undefined2 *)(param_1 + 0x10) = *(undefined2 *)(puVar8 + 2);
    }
  }
locret_F0030C68:
  return CONCAT44(param_2,uVar9);
}
/* GHIDRADEC_FUNCTION index=729 start=0xf0030c70 */

/* WARNING: Removing unreachable block (ram,0xf0030c90) */

undefined8 _in_pcbdisconnect(int param_1,undefined4 param_2)

{
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
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined2 *)(param_1 + 0x10) = 0;
  if ((*(word *)(*(int *)(param_1 + 0x1c) + 6) & 1) != 0) {
    _in_pcbdetach(param_1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=730 start=0xf0030ca0 */

/* WARNING: Removing unreachable block (ram,0xf0030ce0) */
/* WARNING: Removing unreachable block (ram,0xf0030cc0) */
/* WARNING: Removing unreachable block (ram,0xf0030cd8) */
/* WARNING: Removing unreachable block (ram,0xf0030d04) */
/* WARNING: Removing unreachable block (ram,0xf0030ca8) */

undefined8 _in_pcbdetach(int *param_1,undefined4 param_2)

{
  int iVar1;
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
  *(undefined4 *)(param_1[7] + 8) = 0;
  _sofree();
  if (param_1[0xe] == 0) {
    iVar1 = param_1[9];
  }
  else {
    _m_free();
    iVar1 = param_1[9];
  }
  if (iVar1 != 0) {
    _rtfree();
  }
  _ip_freemoptions(param_1[0xf]);
  *(int *)(*param_1 + 4) = param_1[1];
  *(int *)param_1[1] = *param_1;
  _kfree(param_1,0x40);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=731 start=0xf0030d14 */

/* WARNING: Removing unreachable block (ram,0xf0030d2c) */

undefined8 _in_setsockaddr(int param_1,int param_2)

{
  undefined4 unaff_l0;
  int iVar1;
  undefined4 unaff_l1;
  int iVar2;
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
  *(undefined2 *)(param_2 + 8) = 0x10;
  iVar2 = *(int *)(param_2 + 4);
  iVar1 = param_2 + iVar2;
  _bzero(iVar1,0x10);
  *(undefined2 *)(param_2 + iVar2) = 2;
  *(undefined2 *)(iVar1 + 2) = *(undefined2 *)(param_1 + 0x18);
  *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(param_1 + 0x14);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=732 start=0xf0030d54 */

/* WARNING: Removing unreachable block (ram,0xf0030d6c) */

undefined8 _in_setpeeraddr(int param_1,int param_2)

{
  undefined4 unaff_l0;
  int iVar1;
  undefined4 unaff_l1;
  int iVar2;
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
  *(undefined2 *)(param_2 + 8) = 0x10;
  iVar2 = *(int *)(param_2 + 4);
  iVar1 = param_2 + iVar2;
  _bzero(iVar1,0x10);
  *(undefined2 *)(param_2 + iVar2) = 2;
  *(undefined2 *)(iVar1 + 2) = *(undefined2 *)(param_1 + 0x10);
  *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(param_1 + 0xc);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=733 start=0xf0030d94 */

undefined8
_in_pcbnotify(int *param_1,sword *param_2,uint param_3,int *param_4,uint param_5,uint param_6)

{
  byte bVar1;
  sword *psVar2;
  undefined4 unaff_l0;
  int *piVar3;
  int *piVar4;
  undefined4 unaff_l1;
  code *pcVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  int iVar6;
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
  iVar6 = *param_4;
  pcVar5 = *(code **)((int)register0x00000038 + 0x5c);
  if ((param_6 < 0x16) && (*param_2 == 2)) {
    param_2 = *(sword **)(param_2 + 2);
    if (param_2 != (sword *)0x0) {
      if (((param_6 - 0xe < 4) || (param_6 == 6)) || (param_6 == 1)) {
        param_3 = 0;
        param_5 = 0;
        iVar6 = 0;
        if (param_6 != 6) {
          pcVar5 = _in_rtchange;
        }
      }
      piVar3 = (int *)*param_1;
      bVar1 = _inetctlerrmap[param_6];
      if (piVar3 != param_1) {
        psVar2 = (sword *)piVar3[3];
        do {
          if (psVar2 == param_2) {
            if (piVar3[7] == 0) {
loc_F0030E98:
              piVar4 = (int *)*piVar3;
            }
            else if (((param_5 & 0xffff) == 0) ||
                    ((uint)*(word *)(piVar3 + 6) == (param_5 & 0xffff))) {
              if ((iVar6 == 0) || (piVar3[5] == iVar6)) {
                if (((param_3 & 0xffff) != 0) && ((uint)*(word *)(piVar3 + 4) != (param_3 & 0xffff))
                   ) goto loc_F0030E98;
                if (bVar1 != 0) {
                  *(word *)(piVar3[7] + 0x56) = (word)bVar1;
                }
                piVar4 = (int *)*piVar3;
                if (pcVar5 != (code *)0x0) {
                  (*pcVar5)(piVar3);
                }
              }
              else {
                piVar4 = (int *)*piVar3;
              }
            }
            else {
              piVar4 = (int *)*piVar3;
            }
          }
          else {
            piVar4 = (int *)*piVar3;
          }
          if (piVar4 == param_1) break;
          psVar2 = (sword *)piVar4[3];
          piVar3 = piVar4;
        } while( true );
      }
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=734 start=0xf0030edc */

/* WARNING: Removing unreachable block (ram,0xf0030f0c) */
/* WARNING: Removing unreachable block (ram,0xf0030f04) */

undefined8 _in_losing(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  int iVar1;
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
  iVar1 = *(int *)(param_1 + 0x24);
  if (iVar1 != 0) {
    if ((*(word *)(iVar1 + 0x24) & 0x10) != 0) {
      _rtrequest(0x8030720b,iVar1);
    }
    _rtfree(iVar1);
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=735 start=0xf0030f20 */

/* WARNING: Removing unreachable block (ram,0xf0030f34) */

undefined8 _in_rtchange(int param_1,undefined4 param_2)

{
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
  if (*(int *)(param_1 + 0x24) != 0) {
    _rtfree();
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=736 start=0xf0030f48 */

undefined8
_in_pcblookup(int *param_1,uint *param_2,uint param_3,int *param_4,uint param_5,uint param_6)

{
  word wVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  uint uVar7;
  undefined4 unaff_i2;
  uint uVar8;
  undefined4 unaff_i3;
  int iVar9;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar10;
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
  piVar2 = (int *)*param_1;
  piVar6 = (int *)0x0;
  uVar7 = *param_2;
  uVar5 = 3;
  iVar9 = *param_4;
  piVar3 = piVar6;
  if (piVar2 != param_1) {
    wVar1 = *(word *)(piVar2 + 6);
    piVar3 = piVar2;
    do {
      if ((uint)wVar1 == (param_5 & 0xffff)) {
        uVar4 = 0;
        if (piVar3[5] == 0) {
          if (iVar9 != 0) goto loc_F0030FCC;
          uVar8 = piVar3[3];
        }
        else {
          if (iVar9 != 0) {
            if (piVar3[5] == iVar9) {
              uVar8 = piVar3[3];
              goto loc_F0030FD4;
            }
            piVar2 = (int *)*piVar3;
            goto loc_F0031058;
          }
loc_F0030FCC:
          uVar4 = 1;
          uVar8 = piVar3[3];
        }
loc_F0030FD4:
        if (uVar8 == 0) {
          bVar10 = uVar4 == 0;
          if (uVar7 != 0) goto loc_F0031028;
        }
        else {
          if (uVar7 != 0) {
            if ((uint)*(word *)(piVar3 + 4) == (param_3 & 0xffff)) {
              if ((uVar8 & 0xf0000000) == 0xe0000000) {
                piVar2 = (int *)*piVar3;
              }
              else {
                if (uVar8 == uVar7) {
                  bVar10 = uVar4 == 0;
                  goto loc_F003102C;
                }
                piVar2 = (int *)*piVar3;
              }
            }
            else {
              piVar2 = (int *)*piVar3;
            }
            goto loc_F0031058;
          }
loc_F0031028:
          uVar4 = uVar4 + 1;
          bVar10 = uVar4 == 0;
        }
loc_F003102C:
        if ((bVar10) || ((param_6 & 1) != 0)) {
          if (uVar4 < uVar5) {
            if (uVar4 == 0) break;
            piVar2 = (int *)*piVar3;
            uVar5 = uVar4;
            piVar6 = piVar3;
          }
          else {
            piVar2 = (int *)*piVar3;
          }
        }
        else {
          piVar2 = (int *)*piVar3;
        }
      }
      else {
        piVar2 = (int *)*piVar3;
      }
loc_F0031058:
      piVar3 = piVar6;
      if (piVar2 == param_1) break;
      wVar1 = *(word *)(piVar2 + 6);
      piVar3 = piVar2;
    } while( true );
  }
  return CONCAT44(uVar7,piVar3);
}
/* GHIDRADEC_FUNCTION index=737 start=0xf003106c */

/* WARNING: Removing unreachable block (ram,0xf0031290) */
/* WARNING: Removing unreachable block (ram,0xf0031244) */
/* WARNING: Removing unreachable block (ram,0xf00311ac) */
/* WARNING: Removing unreachable block (ram,0xf0031158) */
/* WARNING: Removing unreachable block (ram,0xf0031208) */
/* WARNING: Removing unreachable block (ram,0xf0031274) */
/* WARNING: Removing unreachable block (ram,0xf0031298) */
/* WARNING: Removing unreachable block (ram,0xf0031144) */

undefined8
_icmp_error(byte *param_1,uint param_2,undefined param_3,undefined4 param_4,undefined4 *param_5)

{
  byte bVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
  int iVar6;
  undefined4 unaff_l3;
  int iVar7;
  undefined4 unaff_l4;
  int iVar8;
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
  iVar7 = (*param_1 & 0xf) * 4;
  if (param_2 != 5) {
    _icmpstat = _icmpstat + 1;
  }
  if ((*(word *)(param_1 + 6) & 0x9fff) == 0) {
    if (param_1[9] == 1) {
      if (param_2 == 5) {
        uVar4 = *(uint *)(param_1 + 0x10);
      }
      else {
        bVar1 = param_1[iVar7];
        if ((((bVar1 != 0) && (bVar1 != 8)) && (1 < (byte)(bVar1 - 0xd))) &&
           ((1 < (byte)(bVar1 - 0xf) && (1 < (byte)(bVar1 - 0x11))))) {
          DAT_f0136568 = DAT_f0136568 + 1;
          goto loc_F0031298;
        }
        uVar4 = *(uint *)(param_1 + 0x10);
      }
    }
    else {
      uVar4 = *(uint *)(param_1 + 0x10);
    }
    if ((uVar4 & 0xf0000000) != 0xe0000000) {
      *(uint *)((int)register0x00000038 + -0xc) = uVar4;
      puVar2 = (undefined *)((int)register0x00000038 + -0xc);
      _in_broadcast();
      iVar3 = 0;
      if ((puVar2 == (undefined *)0x0) && (_m_get(0,2), iVar3 != 0)) {
        iVar8 = iVar7 + 8;
        if (*(sword *)(param_1 + 2) < 9) {
          iVar8 = iVar7 + *(sword *)(param_1 + 2);
        }
        *(sword *)(iVar3 + 8) = (sword)(iVar8 + 8);
        iVar6 = 0x7c - ((iVar8 + 8) * 0x10000 >> 0x10);
        *(int *)(iVar3 + 4) = iVar6;
        iVar5 = iVar3 + iVar6;
        if (0x12 < param_2) {
          _panic(aIcmpError);
        }
        *(int *)(unk_F013656C + param_2 * 4) = *(int *)(unk_F013656C + param_2 * 4) + 1;
        *(char *)(iVar3 + iVar6) = (char)param_2;
        if (param_2 == 5) {
          *(undefined4 *)(iVar5 + 4) = *param_5;
        }
        else {
          *(undefined4 *)(iVar5 + 4) = 0;
        }
        if (param_2 == 0xc) {
          *(undefined *)(iVar5 + 4) = param_3;
          *(undefined *)(iVar5 + 1) = 0;
        }
        else {
          *(undefined *)(iVar5 + 1) = param_3;
        }
        _bcopy(param_1,iVar5 + 8,iVar8);
        *(sword *)(iVar5 + 10) = *(sword *)(iVar5 + 10) + (sword)iVar7;
        if (0x70 < (uint)(*(sword *)(iVar3 + 8) + iVar7)) {
          iVar7 = 0x14;
        }
        if (0x70 < (uint)(*(sword *)(iVar3 + 8) + iVar7)) {
          _panic(aIcmpLen);
        }
        *(int *)(iVar3 + 4) = *(int *)(iVar3 + 4) - iVar7;
        *(sword *)(iVar3 + 8) = *(sword *)(iVar3 + 8) + (sword)iVar7;
        iVar7 = iVar3 + *(int *)(iVar3 + 4);
        _bcopy(param_1,iVar7);
        *(undefined2 *)(iVar7 + 2) = *(undefined2 *)(iVar3 + 8);
        *(undefined *)(iVar7 + 9) = 1;
        _icmp_reflect(iVar7,param_4);
      }
    }
  }
loc_F0031298:
  _m_freem((uint)param_1 & 0xffffff80);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=738 start=0xf00312a8 */

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
/* GHIDRADEC_FUNCTION index=739 start=0xf00318a4 */

/* WARNING: Removing unreachable block (ram,0xf0031984) */
/* WARNING: Removing unreachable block (ram,0xf003195c) */
/* WARNING: Removing unreachable block (ram,0xf0031978) */
/* WARNING: Removing unreachable block (ram,0xf0031998) */
/* WARNING: Removing unreachable block (ram,0xf0031928) */

undefined8 _icmp_reflect(byte *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar5;
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
  bool bVar6;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  iVar2 = _in_ifaddr;
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
  iVar3 = *(int *)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0xc);
  bVar6 = iVar2 == 0;
  iVar5 = (*param_1 & 0xf) * 4 + -0x14;
  if (!bVar6) {
    iVar1 = *(int *)(iVar2 + 4);
    while (bVar6 = iVar2 == 0, iVar3 != iVar1) {
      if ((*(word *)(*(int *)(iVar2 + 0x20) + 0xc) & 2) == 0) {
        iVar2 = *(int *)(iVar2 + 0x40);
      }
      else {
        bVar6 = iVar2 == 0;
        if (iVar3 == *(int *)(iVar2 + 0x14)) break;
        iVar2 = *(int *)(iVar2 + 0x40);
      }
      if (iVar2 == 0) {
        bVar6 = true;
        break;
      }
      iVar1 = *(int *)(iVar2 + 4);
    }
  }
  if (bVar6) {
    iVar2 = param_2;
    _ifptoia();
  }
  if (iVar2 == 0) {
    uVar4 = *(undefined4 *)(_in_ifaddr + 4);
  }
  else {
    uVar4 = *(undefined4 *)(iVar2 + 4);
  }
  iVar3 = 0xff;
  *(undefined4 *)(param_1 + 0xc) = uVar4;
  param_1[8] = 0xff;
  iVar2 = 0;
  if (0 < iVar5) {
    _ip_srcroute();
    *(sword *)(param_1 + 2) = *(sword *)(param_1 + 2) - (sword)iVar5;
    _ip_stripoptions(param_1,0);
    iVar2 = iVar3;
  }
  _icmp_send(param_1,iVar2);
  if (iVar2 != 0) {
    _m_free(iVar2);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=740 start=0xf00319a8 */

undefined8 _ifptoia(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar2;
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
  if (_in_ifaddr == 0) {
    iVar2 = 0;
  }
  else {
    iVar1 = *(int *)(_in_ifaddr + 0x20);
    iVar2 = _in_ifaddr;
    while (iVar1 != param_1) {
      iVar2 = *(int *)(iVar2 + 0x40);
      if (iVar2 == 0) {
        iVar2 = 0;
        break;
      }
      iVar1 = *(int *)(iVar2 + 0x20);
    }
  }
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=741 start=0xf00319f0 */

/* WARNING: Removing unreachable block (ram,0xf0031a64) */
/* WARNING: Removing unreachable block (ram,0xf0031a30) */

undefined8 _icmp_send(byte *param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
  uint uVar2;
  undefined4 unaff_l1;
  uint uVar3;
  int iVar4;
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
  uVar2 = (uint)param_1 & 0xffffff80;
  uVar3 = *param_1 & 0xf;
  *(uint *)(uVar2 + 4) = *(int *)(uVar2 + 4) + uVar3 * 4;
  *(sword *)(uVar2 + 8) = *(sword *)(uVar2 + 8) + (sword)uVar3 * -4;
  iVar4 = uVar2 + *(int *)(uVar2 + 4);
  *(undefined2 *)(iVar4 + 2) = 0;
  uVar1 = uVar2;
  _in_cksum(uVar2,(int)*(sword *)(param_1 + 2) + uVar3 * -4);
  *(sword *)(iVar4 + 2) = (sword)uVar1;
  *(uint *)(uVar2 + 4) = *(int *)(uVar2 + 4) + uVar3 * -4;
  *(sword *)(uVar2 + 8) = *(sword *)(uVar2 + 8) + (sword)(uVar3 * 4);
  _ip_output(uVar2,param_2,0,0,0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=742 start=0xf0031a74 */

/* WARNING: Removing unreachable block (ram,0xf0031a88) */
/* WARNING: Removing unreachable block (ram,0xf0031ab0) */
/* WARNING: Removing unreachable block (ram,0xf0031a78) */

undefined8 _iptime(undefined4 param_1,undefined4 param_2)

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
  _microtime((undefined *)((int)register0x00000038 + -0x10));
  iVar1 = *(int *)((int)register0x00000038 + -0x10);
  .rem(iVar1,0x15180);
  iVar2 = *(int *)((int)register0x00000038 + -0xc);
  .div(iVar2,1000);
  return CONCAT44(param_2,iVar1 * 1000 + iVar2);
}
/* GHIDRADEC_FUNCTION index=743 start=0xf0031ac0 */

/* WARNING: Removing unreachable block (ram,0xf0031cd0) */
/* WARNING: Removing unreachable block (ram,0xf0031c94) */
/* WARNING: Removing unreachable block (ram,0xf0031c78) */
/* WARNING: Removing unreachable block (ram,0xf0031c30) */
/* WARNING: Removing unreachable block (ram,0xf0031b30) */
/* WARNING: Removing unreachable block (ram,0xf0031b04) */
/* WARNING: Removing unreachable block (ram,0xf0031b98) */
/* WARNING: Removing unreachable block (ram,0xf0031c64) */
/* WARNING: Removing unreachable block (ram,0xf0031c84) */
/* WARNING: Removing unreachable block (ram,0xf0031cc4) */
/* WARNING: Removing unreachable block (ram,0xf0031ce4) */
/* WARNING: Removing unreachable block (ram,0xf0031ae8) */

undefined8 _icmp_sendMaskPacket(int param_1,uint param_2,int param_3)

{
  sword sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l0;
  int iVar5;
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
  bool bVar6;
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
  if (((*(word *)(param_1 + 0xc) & 1) == 0) || ((*(word *)(param_1 + 0xc) & 8) != 0)) {
    param_1 = 0;
    goto locret_F0031CEC;
  }
  iVar2 = param_1;
  _ifptoia();
  iVar3 = 1;
  if (iVar2 == 0) {
    param_1 = 0x33;
    iVar3 = 0;
loc_F0031CD8:
    bVar6 = iVar3 == 0;
  }
  else {
    _m_get(1,2);
    if (iVar3 != 0) {
      *(undefined2 *)(iVar3 + 8) = 0x20;
      *(undefined4 *)(iVar3 + 4) = 0x5c;
      _bzero(iVar3 + 0x5c,(int)*(sword *)(iVar3 + 8));
      *(sword *)(iVar3 + 8) = *(sword *)(iVar3 + 8) + -0x14;
      iVar4 = *(int *)(iVar3 + 4) + 0x14;
      *(int *)(iVar3 + 4) = iVar4;
      iVar5 = iVar3 + iVar4;
      if ((param_2 & 0xff) == 0x12) {
        *(undefined *)(iVar3 + iVar4) = 0x12;
        iVar4 = *(int *)(iVar2 + 0x34);
        *(int *)(iVar5 + 8) = iVar4;
        if (iVar4 == 0) {
          param_1 = 0x16;
          goto loc_F0031CD8;
        }
      }
      else {
        *(undefined *)(iVar3 + iVar4) = 0x11;
      }
      *(undefined *)(iVar5 + 1) = 0;
      *(undefined2 *)(iVar5 + 2) = 0;
      *(undefined4 *)(iVar5 + 4) = 0;
      iVar4 = iVar3;
      _in_cksum(iVar3,0xc);
      *(sword *)(iVar5 + 2) = (sword)iVar4;
      sVar1 = _ip_id;
      *(int *)(iVar3 + 4) = *(int *)(iVar3 + 4) + -0x14;
      *(sword *)(iVar3 + 8) = *(sword *)(iVar3 + 8) + 0x14;
      _ip_id = _ip_id + 1;
      iVar5 = *(int *)(iVar3 + 4);
      *(uint *)(iVar3 + iVar5) = *(uint *)(iVar3 + iVar5) & 0xffffff | 0x45000000;
      iVar5 = iVar3 + iVar5;
      *(sword *)(iVar5 + 4) = sVar1;
      *(undefined *)(iVar5 + 8) = 0xff;
      *(undefined *)(iVar5 + 9) = 1;
      *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar2 + 4);
      *(undefined4 *)(iVar5 + 0x10) = 0xffffffff;
      *(undefined2 *)(iVar5 + 2) = 0x20;
      *(undefined2 *)(iVar5 + 10) = 0;
      iVar4 = iVar3;
      _in_cksum(iVar3,0x14);
      *(sword *)(iVar5 + 10) = (sword)iVar4;
      *(undefined2 *)((int)register0x00000038 + -0x18) = 2;
      *(undefined2 *)((int)register0x00000038 + -0x16) = 0;
      *(undefined4 *)((int)register0x00000038 + -0x14) = 0xffffffff;
      if (0 < param_3) {
        .umul(param_3,_hz);
        _timeout(_wakeup,iVar2 + 0x34,param_3);
        _sleep(iVar2 + 0x34,0x19);
      }
      _if_output_mbuf(param_1,iVar3,(undefined *)((int)register0x00000038 + -0x18));
      iVar3 = 0;
      if ((param_2 & 0xff) == 0x11) {
        _timeout(_wakeup,iVar2 + 0x34,_hz);
        _sleep(iVar2 + 0x34,0x19);
      }
      goto loc_F0031CD8;
    }
    param_1 = 0x37;
    bVar6 = true;
  }
  if (!bVar6) {
    _m_freem(iVar3);
  }
locret_F0031CEC:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=744 start=0xf0031cf4 */

/* WARNING: Removing unreachable block (ram,0xf0031d18) */
/* WARNING: Removing unreachable block (ram,0xf0031e24) */
/* WARNING: Removing unreachable block (ram,0xf0031d00) */

undefined8 _ip_init(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined uVar3;
  sword *psVar4;
  undefined4 unaff_l0;
  undefined (*pauVar5) [336];
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
  iVar1 = 2;
  _pffindproto(2,0xff,3);
  if (iVar1 == 0) {
    _panic(&aIpInit);
  }
  puVar2 = &DAT_f013671f;
  uVar3 = (undefined)((iVar1 + 0xfef3a60) * -0x55555555 >> 4);
  DAT_f013671f = uVar3;
  while (puVar2 = puVar2 + -1, -0xfec99e1 < (int)puVar2) {
    *puVar2 = uVar3;
  }
  if (off_F010C704 < (uint)DAT_f010c708._0_4_) {
    psVar4 = (sword *)(*off_F010C704 + 8);
    pauVar5 = off_F010C704;
    do {
      if (((**(int **)(psVar4 + -2) == 2) && (iVar1 = (int)*psVar4, iVar1 != 0)) && (iVar1 != 0xff))
      {
        _ip_protox[iVar1] = (char)((int)(pauVar5[0xc23fb] + 0xf0) * -0x55555555 >> 4);
      }
      pauVar5 = (undefined (*) [336])(*pauVar5 + 0x30);
      psVar4 = psVar4 + 0x18;
    } while (pauVar5 < (uint)DAT_f010c708._0_4_);
  }
  DAT_f01364b4._0_4_ = &_ipq;
  _ipq = &_ipq;
  _getthetime((undefined *)((int)register0x00000038 + -0x10));
  _ip_id = (sword)*(undefined4 *)((int)register0x00000038 + -0x10);
  dword_F013648C = _ipqmaxlen;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=745 start=0xf0031e50 */

/* WARNING: Removing unreachable block (ram,0xf00324cc) */
/* WARNING: Removing unreachable block (ram,0xf003248c) */
/* WARNING: Removing unreachable block (ram,0xf00322bc) */
/* WARNING: Removing unreachable block (ram,0xf00321c4) */
/* WARNING: Removing unreachable block (ram,0xf003215c) */
/* WARNING: Removing unreachable block (ram,0xf003202c) */
/* WARNING: Removing unreachable block (ram,0xf0031f74) */
/* WARNING: Removing unreachable block (ram,0xf0031f48) */
/* WARNING: Removing unreachable block (ram,0xf0031ee0) */
/* WARNING: Removing unreachable block (ram,0xf0031ec4) */
/* WARNING: Removing unreachable block (ram,0xf0031f20) */
/* WARNING: Removing unreachable block (ram,0xf0031f68) */
/* WARNING: Removing unreachable block (ram,0xf0031fc8) */
/* WARNING: Removing unreachable block (ram,0xf0032070) */
/* WARNING: Removing unreachable block (ram,0xf003217c) */
/* WARNING: Removing unreachable block (ram,0xf0032384) */
/* WARNING: Removing unreachable block (ram,0xf0032368) */
/* WARNING: Removing unreachable block (ram,0xf00324b0) */
/* WARNING: Removing unreachable block (ram,0xf0032518) */
/* WARNING: Removing unreachable block (ram,0xf0031e58) */

undefined8 _ipintr(int *param_1,undefined4 param_2)

{
  int *piVar1;
  byte bVar2;
  sword sVar3;
  sword sVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined *puVar8;
  int *piVar9;
  uint uVar10;
  word wVar11;
  undefined4 *puVar12;
  undefined4 unaff_l0;
  int *piVar13;
  int *piVar14;
  undefined4 unaff_l1;
  uint uVar15;
  undefined4 unaff_l3;
  int iVar16;
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
  iVar16 = 0;
  piVar9 = param_1;
loc_F0031E58:
  while( true ) {
    _spltty();
    piVar14 = _ipintrq;
    piVar13 = piVar14;
    if (_ipintrq != (int *)0x0) {
      if ((int *)_ipintrq[0x1f] == (int *)0x0) {
        DAT_f0136484._0_4_ = 0;
      }
      piVar1 = _ipintrq + 0x1f;
      _ipintrq = (int *)_ipintrq[0x1f];
      *piVar1 = 0;
      DAT_f0136484._4_4_ = DAT_f0136484._4_4_ + -1;
      sVar3 = *(sword *)(piVar14 + 2);
      iVar16 = *(int *)((int)piVar14 + piVar14[1]);
      iVar5 = piVar14[1] + 4;
      piVar14[1] = iVar5;
      *(sword *)(piVar14 + 2) = sVar3 + -4;
      if ((sword)(sVar3 + -4) == 0) {
        _spltty();
        if (*(sword *)((int)piVar14 + 10) == 0) {
          _panic(&aMfree_7);
        }
        (&word_F0134B0C)[*(sword *)((int)piVar14 + 10)] =
             (&word_F0134B0C)[*(sword *)((int)piVar14 + 10)] + -1;
        word_F0134B0C = word_F0134B0C + 1;
        *(undefined2 *)((int)piVar14 + 10) = 0;
        if (0x7f < (uint)piVar14[1]) {
          _mclput(piVar14);
        }
        piVar14[1] = 0;
        piVar14[0x1f] = 0;
        piVar13 = (int *)*piVar14;
        *piVar14 = (int)_mfree;
        _mfree = piVar14;
        _splx(iVar5);
        if (_m_want != 0) {
          _m_want = 0;
          _wakeup(&_mfree);
        }
      }
    }
    _splx(piVar9);
    if (piVar13 == (int *)0x0) {
      return CONCAT44(param_2,param_1);
    }
    if (_in_ifaddr == 0) goto loc_F0032518;
    _ipstat = _ipstat + 1;
    uVar10 = piVar13[1];
    if ((uVar10 < 0x7d) && (0x13 < *(word *)(piVar13 + 2))) break;
    _m_pullup(piVar13,0x14);
    if (piVar13 != (int *)0x0) {
      uVar10 = piVar13[1];
      bVar2 = *(byte *)((int)piVar13 + uVar10);
      goto loc_F0031FF0;
    }
    piVar9 = (int *)(DAT_f01364d4._8_4_ + 1);
    DAT_f01364d4._8_4_ = piVar9;
  }
  bVar2 = *(byte *)((int)piVar13 + uVar10);
loc_F0031FF0:
  uVar15 = (bVar2 & 0xf) * 4;
  piVar14 = (int *)((int)piVar13 + uVar10);
  if (uVar15 < 0x14) {
    DAT_f01364d4._12_4_ = DAT_f01364d4._12_4_ + 1;
  }
  else {
    if (uVar15 - (int)*(sword *)(piVar13 + 2) != 0 && (int)*(sword *)(piVar13 + 2) <= (int)uVar15) {
      _m_pullup(piVar13,uVar15);
      if (piVar13 == (int *)0x0) {
        piVar9 = (int *)(DAT_f01364d4._12_4_ + 1);
        DAT_f01364d4._12_4_ = piVar9;
        goto loc_F0031E58;
      }
      piVar14 = (int *)((int)piVar13 + piVar13[1]);
    }
    if (_ipcksum._0_1_ != '\0') {
      piVar9 = piVar13;
      _in_cksum(piVar13,uVar15);
      *(sword *)((int)piVar14 + 10) = (sword)piVar9;
      if (((uint)piVar9 & 0xffff) != 0) {
        DAT_f01364d4._0_4_ = DAT_f01364d4._0_4_ + 1;
        goto loc_F0032518;
      }
    }
    *(sword *)((int)piVar14 + 2) = (sword)*piVar14;
    if ((int)uVar15 <= (int)(sword)*piVar14) {
      iVar5 = *piVar14;
      *(undefined2 *)(piVar14 + 1) = *(undefined2 *)(piVar14 + 1);
      *(undefined2 *)((int)piVar14 + 6) = *(undefined2 *)((int)piVar14 + 6);
      sVar3 = *(sword *)(piVar13 + 2);
      *(int **)((int)register0x00000038 + -0xc) = piVar13;
      iVar5 = (int)sVar3 - (uint)(word)iVar5;
      iVar6 = *piVar13;
      while (iVar6 != 0) {
        piVar13 = (int *)*piVar13;
        iVar5 = iVar5 + *(sword *)(piVar13 + 2);
        iVar6 = *piVar13;
      }
      if (iVar5 == 0) {
        iVar5 = *(int *)((int)register0x00000038 + -0xc);
      }
      else {
        if (iVar5 < 0) {
          piVar13 = *(int **)((int)register0x00000038 + -0xc);
          DAT_f01364d4._4_4_ = DAT_f01364d4._4_4_ + 1;
          goto loc_F0032518;
        }
        if (*(sword *)(piVar13 + 2) < iVar5) {
          _m_adj(*(undefined4 *)((int)register0x00000038 + -0xc),-iVar5);
        }
        else {
          *(sword *)(piVar13 + 2) = *(sword *)(piVar13 + 2) - (sword)iVar5;
        }
        iVar5 = *(int *)((int)register0x00000038 + -0xc);
      }
      _ip_nhops = 0;
      if ((uVar15 < 0x15) || (piVar9 = piVar14, _ip_dooptions(piVar14,iVar16), piVar9 == (int *)0x0)
         ) {
        if (((*(word *)(iVar16 + 0xc) & 0x4000) == 0) ||
           ((((0x7c < *(uint *)(iVar5 + 4) || (*(word *)(iVar5 + 8) < 0x1c)) &&
             (_m_pullup(iVar5,0x1c), iVar5 == 0)) ||
            ((iVar6 = iVar5 + *(int *)(iVar5 + 4), *(char *)(iVar6 + 9) != '\x11' ||
             (*(sword *)(iVar6 + 0x16) != 0x44)))))) {
          uVar10 = piVar14[4];
          if (_in_ifaddr == 0) {
loc_F0032288:
            if ((uVar10 & 0xf0000000) == 0xe0000000) {
              if (_ip_mrouter == 0) {
loc_F00322E4:
                bVar17 = _in_ifaddr == 0;
                iVar6 = _in_ifaddr;
                if (!bVar17) {
                  iVar7 = *(int *)(_in_ifaddr + 0x20);
                  while (bVar17 = iVar6 == 0, iVar7 != iVar16) {
                    iVar6 = *(int *)(iVar6 + 0x40);
                    if (iVar6 == 0) {
                      bVar17 = true;
                      break;
                    }
                    iVar7 = *(int *)(iVar6 + 0x20);
                  }
                }
                if (bVar17) {
loc_F003235C:
                  bVar17 = true;
                }
                else {
                  piVar9 = *(int **)(iVar6 + 0x44);
                  bVar17 = piVar9 == (int *)0x0;
                  if (!bVar17) {
                    iVar6 = *piVar9;
                    while (bVar17 = piVar9 == (int *)0x0, iVar6 != piVar14[4]) {
                      piVar9 = (int *)piVar9[5];
                      if (piVar9 == (int *)0x0) goto loc_F003235C;
                      iVar6 = *piVar9;
                    }
                  }
                }
                if (!bVar17) {
                  wVar11 = *(word *)((int)piVar14 + 6);
                  goto loc_F0032394;
                }
              }
              else {
                *(undefined2 *)(piVar14 + 1) = *(undefined2 *)(piVar14 + 1);
                piVar9 = piVar14;
                _ip_mforward(piVar14,iVar16);
                if (piVar9 == (int *)0x0) {
                  *(undefined2 *)(piVar14 + 1) = *(undefined2 *)(piVar14 + 1);
                  if (*(char *)((int)piVar14 + 9) == '\x02') goto loc_F0032390;
                  goto loc_F00322E4;
                }
              }
              piVar9 = (int *)((uint)piVar14 & 0xffffff80);
              _m_freem();
            }
            else {
              if ((uVar10 == 0xffffffff) || (uVar10 == 0)) goto loc_F0032390;
              _ip_forward(piVar14,iVar16);
              piVar9 = piVar14;
            }
            goto loc_F0031E58;
          }
          uVar15 = *(uint *)(_in_ifaddr + 4);
          iVar6 = _in_ifaddr;
          while (uVar15 != uVar10) {
            if ((*(word *)(*(int *)(iVar6 + 0x20) + 0xc) & 2) == 0) {
              iVar6 = *(int *)(iVar6 + 0x40);
            }
            else {
              if (*(uint *)(iVar6 + 0x14) == uVar10) {
                wVar11 = *(word *)((int)piVar14 + 6);
                goto loc_F0032394;
              }
              if (uVar10 == *(uint *)(iVar6 + 0x38)) {
                wVar11 = *(word *)((int)piVar14 + 6);
                goto loc_F0032394;
              }
              if (uVar10 == *(uint *)(iVar6 + 0x30)) {
                wVar11 = *(word *)((int)piVar14 + 6);
                goto loc_F0032394;
              }
              if (uVar10 == *(uint *)(iVar6 + 0x28)) {
                wVar11 = *(word *)((int)piVar14 + 6);
                goto loc_F0032394;
              }
              iVar6 = *(int *)(iVar6 + 0x40);
            }
            if (iVar6 == 0) {
              uVar10 = piVar14[4];
              goto loc_F0032288;
            }
            uVar15 = *(uint *)(iVar6 + 4);
          }
          wVar11 = *(word *)((int)piVar14 + 6);
        }
        else {
loc_F0032390:
          wVar11 = *(word *)((int)piVar14 + 6);
        }
loc_F0032394:
        sVar3 = (sword)(bVar2 & 0xf);
        if ((wVar11 & 0xbfff) == 0) {
          *(sword *)((int)piVar14 + 2) = (sword)*piVar14 + sVar3 * -4;
          *(int *)((int)register0x00000038 + -0xc) = iVar5;
        }
        else {
          if ((undefined4 **)_ipq != &_ipq) {
            sVar4 = *(sword *)((int)_ipq + 10);
            puVar12 = _ipq;
            while( true ) {
              if (*(sword *)(piVar14 + 1) == sVar4) {
                if (piVar14[3] == puVar12[5]) {
                  if (piVar14[4] == puVar12[6]) {
                    if (*(char *)((int)piVar14 + 9) == *(char *)((int)puVar12 + 9)) {
                      sVar4 = (sword)*piVar14;
                      goto loc_F0032428;
                    }
                    puVar12 = (undefined4 *)*puVar12;
                  }
                  else {
                    puVar12 = (undefined4 *)*puVar12;
                  }
                }
                else {
                  puVar12 = (undefined4 *)*puVar12;
                }
              }
              else {
                puVar12 = (undefined4 *)*puVar12;
              }
              if ((undefined4 **)puVar12 == &_ipq) break;
              sVar4 = *(sword *)((int)puVar12 + 10);
            }
          }
          puVar12 = (undefined4 *)0x0;
          sVar4 = (sword)*piVar14;
loc_F0032428:
          *(undefined *)((int)piVar14 + 1) = 0;
          *(sword *)((int)piVar14 + 2) = sVar4 + sVar3 * -4;
          if ((*(word *)((int)piVar14 + 6) & 0x2000) != 0) {
            *(undefined *)((int)piVar14 + 1) = 1;
          }
          wVar11 = *(word *)((int)piVar14 + 6);
          *(word *)((int)piVar14 + 6) = wVar11 << 3;
          if ((*(char *)((int)piVar14 + 1) == '\0') && ((wVar11 & 0x1fff) == 0)) {
            if (puVar12 == (undefined4 *)0x0) {
              *(int *)((int)register0x00000038 + -0xc) = iVar5;
            }
            else {
              _ip_freef(puVar12);
              *(int *)((int)register0x00000038 + -0xc) = iVar5;
            }
          }
          else {
            DAT_f01364d4._20_4_ = DAT_f01364d4._20_4_ + 1;
            _ip_reass(piVar14,puVar12);
            piVar9 = (int *)0x0;
            if (piVar14 == (int *)0x0) goto loc_F0031E58;
            *(uint *)((int)register0x00000038 + -0xc) = (uint)piVar14 & 0xffffff80;
          }
        }
        puVar8 = (undefined *)((int)register0x00000038 + -0xc);
        _receive_ip_datagram();
        piVar9 = (int *)DAT_f0136400;
        if (puVar8 == (undefined *)0x0) {
          piVar9 = *(int **)((int)register0x00000038 + -0xc);
          (**(code **)(DAT_f010c5ac + (uint)(byte)_ip_protox[*(byte *)((int)piVar14 + 9)] * 0x30))
                    (piVar9,iVar16);
        }
      }
      goto loc_F0031E58;
    }
    DAT_f01364d4._16_4_ = DAT_f01364d4._16_4_ + 1;
  }
loc_F0032518:
  _m_freem();
  piVar9 = piVar13;
  goto loc_F0031E58;
}
/* GHIDRADEC_FUNCTION index=746 start=0xf003252c */

/* WARNING: Removing unreachable block (ram,0xf0032770) */
/* WARNING: Removing unreachable block (ram,0xf00326e8) */
/* WARNING: Removing unreachable block (ram,0xf0032564) */
/* WARNING: Removing unreachable block (ram,0xf00326c8) */
/* WARNING: Removing unreachable block (ram,0xf00325e8) */
/* WARNING: Removing unreachable block (ram,0xf00326d0) */
/* WARNING: Removing unreachable block (ram,0xf0032808) */
/* WARNING: Removing unreachable block (ram,0xf003274c) */
/* WARNING: Removing unreachable block (ram,0xf00327b4) */
/* WARNING: Removing unreachable block (ram,0xf0032670) */

undefined8 _ip_reass(byte *param_1,int *param_2)

{
  sword sVar1;
  byte bVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  byte *pbVar8;
  undefined4 unaff_i1;
  int *piVar9;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar10;
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
  bVar2 = *param_1;
  uVar6 = (uint)param_1 & 0xffffff80;
  *(uint *)(uVar6 + 4) = *(int *)(uVar6 + 4) + (bVar2 & 0xf) * 4;
  *(sword *)(uVar6 + 8) = *(sword *)(uVar6 + 8) + (sword)(bVar2 & 0xf) * -4;
  if (param_2 == (int *)0x0) {
    iVar3 = 0;
    _m_get(0,0xb);
    if (iVar3 == 0) {
loc_F00327F8:
      iRamf01364ec = iRamf01364ec + 1;
      _m_freem(uVar6);
      pbVar8 = (byte *)0x0;
      goto locret_F0032814;
    }
    piVar9 = (int *)(iVar3 + *(int *)(iVar3 + 4));
    *(int **)(iVar3 + *(int *)(iVar3 + 4)) = _ipq;
    piVar9[1] = (int)&_ipq;
    _ipq[1] = (int)piVar9;
    _ipq = piVar9;
    *(undefined *)(piVar9 + 2) = 0x3c;
    *(byte *)((int)piVar9 + 9) = param_1[9];
    *(undefined2 *)((int)piVar9 + 10) = *(undefined2 *)(param_1 + 4);
    piVar9[4] = (int)piVar9;
    piVar9[3] = (int)piVar9;
    piVar9[5] = *(int *)(param_1 + 0xc);
    piVar9[6] = *(int *)(param_1 + 0x10);
    param_2 = piVar9;
loc_F00326E4:
    iVar3 = piVar9[4];
  }
  else {
    piVar9 = (int *)param_2[3];
    if (piVar9 == param_2) {
      piVar4 = (int *)piVar9[4];
    }
    else {
      sVar1 = *(sword *)((int)piVar9 + 6);
      while (sVar1 <= *(sword *)(param_1 + 6)) {
        piVar9 = (int *)piVar9[3];
        if (piVar9 == param_2) {
          piVar4 = (int *)piVar9[4];
          goto loc_F0032630;
        }
        sVar1 = *(sword *)((int)piVar9 + 6);
      }
      piVar4 = (int *)piVar9[4];
    }
loc_F0032630:
    bVar10 = piVar9 == param_2;
    if (piVar4 == param_2) goto loc_F00326DC;
    iVar3 = ((int)*(sword *)((int)piVar4 + 6) + (int)(sword)*piVar4) - (int)*(sword *)(param_1 + 6);
    bVar10 = piVar9 == param_2;
    if (iVar3 < 1) goto loc_F00326DC;
    if (*(sword *)(param_1 + 2) <= iVar3) goto loc_F00327F8;
    _m_adj((uint)param_1 & 0xffffff80,iVar3);
    *(sword *)(param_1 + 6) = *(sword *)(param_1 + 6) + (sword)iVar3;
    *(sword *)(param_1 + 2) = *(sword *)(param_1 + 2) - (sword)iVar3;
    while( true ) {
      bVar10 = piVar9 == param_2;
loc_F00326DC:
      if (bVar10) goto loc_F00326E4;
      if ((int)*(sword *)(param_1 + 6) + (int)*(sword *)(param_1 + 2) <=
          (int)*(sword *)((int)piVar9 + 6)) {
        iVar3 = piVar9[4];
        goto loc_F00326E8;
      }
      iVar3 = ((int)*(sword *)(param_1 + 6) + (int)*(sword *)(param_1 + 2)) -
              (int)*(sword *)((int)piVar9 + 6);
      if (iVar3 < (sword)*piVar9) break;
      piVar9 = (int *)piVar9[3];
      _m_freem(piVar9[4] & 0xffffff80);
      _ip_deq(piVar9[4]);
    }
    sVar1 = (sword)iVar3;
    *(sword *)((int)piVar9 + 2) = (sword)*piVar9 - sVar1;
    *(sword *)((int)piVar9 + 6) = *(sword *)((int)piVar9 + 6) + sVar1;
    _m_adj((uint)piVar9 & 0xffffff80);
    iVar3 = piVar9[4];
  }
loc_F00326E8:
  _ip_enq(param_1,iVar3);
  iVar3 = 0;
  for (piVar9 = (int *)param_2[3]; piVar9 != param_2; piVar9 = (int *)piVar9[3]) {
    if (*(sword *)((int)piVar9 + 6) != iVar3) {
      pbVar8 = (byte *)0x0;
      goto locret_F0032814;
    }
    iVar3 = iVar3 + (sword)*piVar9;
  }
  if (*(char *)(piVar9[4] + 1) == '\0') {
    uVar6 = param_2[3];
    puVar7 = (undefined4 *)(uVar6 & 0xffffff80);
    uVar5 = *puVar7;
    *puVar7 = 0;
    _m_cat(puVar7,uVar5);
    piVar9 = *(int **)(uVar6 + 0xc);
    if (piVar9 == param_2) {
      pbVar8 = (byte *)param_2[3];
    }
    else {
      do {
        uVar6 = (uint)piVar9 & 0xffffff80;
        piVar9 = (int *)piVar9[3];
        _m_cat(puVar7,uVar6);
      } while (piVar9 != param_2);
      pbVar8 = (byte *)param_2[3];
    }
    *(sword *)(pbVar8 + 2) = (sword)iVar3;
    *(int *)(pbVar8 + 0xc) = param_2[5];
    *(int *)(pbVar8 + 0x10) = param_2[6];
    *(int *)(*param_2 + 4) = param_2[1];
    *(int *)param_2[1] = *param_2;
    _m_free((uint)param_2 & 0xffffff80);
    uVar6 = (uint)pbVar8 & 0xffffff80;
    *(word *)(uVar6 + 8) = *(sword *)(uVar6 + 8) + (*pbVar8 & 0xf) * 4;
    *(uint *)(uVar6 + 4) = *(int *)(uVar6 + 4) + (*pbVar8 & 0xf) * -4;
  }
  else {
    pbVar8 = (byte *)0x0;
  }
locret_F0032814:
  return CONCAT44(param_2,pbVar8);
}
/* GHIDRADEC_FUNCTION index=747 start=0xf003281c */

/* WARNING: Removing unreachable block (ram,0xf003283c) */
/* WARNING: Removing unreachable block (ram,0xf003286c) */
/* WARNING: Removing unreachable block (ram,0xf0032834) */

undefined8 _ip_freef(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 unaff_l0;
  int *piVar3;
  undefined4 unaff_l1;
  int *piVar4;
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
  piVar4 = (int *)param_1[3];
  if (piVar4 == param_1) {
    iVar2 = *param_1;
  }
  else {
    piVar1 = (int *)piVar4[3];
    while( true ) {
      piVar3 = piVar1;
      _ip_deq(piVar4);
      _m_freem((uint)piVar4 & 0xffffff80);
      if (piVar3 == param_1) break;
      piVar1 = (int *)piVar3[3];
      piVar4 = piVar3;
    }
    iVar2 = *param_1;
  }
  *(int *)(iVar2 + 4) = param_1[1];
  *(int *)param_1[1] = *param_1;
  _m_free((uint)param_1 & 0xffffff80);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=748 start=0xf003287c */

undefined8 _ip_enq(int param_1,int param_2)

{
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
  *(int *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_2 + 0xc);
  *(int *)(*(int *)(param_2 + 0xc) + 0x10) = param_1;
  *(int *)(param_2 + 0xc) = param_1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=749 start=0xf00328a0 */

undefined8 _ip_deq(int param_1,undefined4 param_2)

{
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
  *(undefined4 *)(*(int *)(param_1 + 0x10) + 0xc) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x10) = *(undefined4 *)(param_1 + 0x10);
  return CONCAT44(param_2,param_1);
}

