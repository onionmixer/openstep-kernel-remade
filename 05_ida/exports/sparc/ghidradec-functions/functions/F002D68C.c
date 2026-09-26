
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
