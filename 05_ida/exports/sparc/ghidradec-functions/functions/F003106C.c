
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
