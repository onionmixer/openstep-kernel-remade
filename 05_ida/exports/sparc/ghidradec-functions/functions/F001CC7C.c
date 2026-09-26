
/* WARNING: Removing unreachable block (ram,0xf001cd80) */
/* WARNING: Removing unreachable block (ram,0xf001ccf0) */
/* WARNING: Removing unreachable block (ram,0xf001cd54) */
/* WARNING: Removing unreachable block (ram,0xf001cdac) */
/* WARNING: Removing unreachable block (ram,0xf001cc98) */
/* WARNING: Type propagation algorithm not settling */

undefined8 _b_to_q(int param_1,undefined *param_2,int *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined *puVar4;
  undefined4 unaff_l0;
  undefined *puVar5;
  undefined4 unaff_l1;
  undefined4 *puVar6;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar7;
  undefined4 unaff_i1;
  undefined *puVar8;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar9;
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
  puVar8 = param_2;
  if ((int)param_2 < 1) {
    puVar7 = (undefined *)0x0;
    goto locret_F001CDB4;
  }
  iVar2 = param_1;
  _spltty();
  puVar1 = _cfreelist;
  puVar6 = (undefined4 *)param_3[2];
  puVar7 = param_2;
  if ((puVar6 == (undefined4 *)0x0) || (*param_3 < 0)) {
    puVar3 = _cfreelist + 1;
    if (_cfreelist != (undefined4 *)0x0) {
      puVar6 = _cfreelist + 3;
      _cfreelist = (undefined4 *)*_cfreelist;
      _cfreecount = _cfreecount + -0x34;
      _bzero(puVar3,8);
      *puVar1 = 0;
      param_3[1] = (int)puVar6;
      goto loc_F001CD04;
    }
loc_F001CD98:
    param_3[2] = (int)puVar6;
  }
  else {
loc_F001CD04:
    if (param_2 != (undefined *)0x0) {
      puVar8 = DAT_f010f000;
      do {
        puVar1 = _cfreelist;
        if (((uint)puVar6 & 0x3f) == 0) {
          bVar9 = _cfreelist == (undefined4 *)0x0;
          puVar6[-0x10] = _cfreelist;
          if (bVar9) break;
          _cfreelist = (undefined4 *)*puVar1;
          puVar6 = puVar1 + 3;
          _cfreecount = _cfreecount + -0x34;
          _bzero(puVar1 + 1,8);
          *puVar1 = 0;
        }
        puVar4 = (undefined *)(0x40 - ((uint)puVar6 & 0x3f));
        puVar5 = puVar7;
        if (puVar4 <= puVar7) {
          puVar5 = puVar4;
        }
        _bcopy(param_1,puVar6,puVar5);
        param_1 = param_1 + (int)puVar5;
        puVar7 = puVar7 + -(int)puVar5;
        puVar6 = (undefined4 *)((int)puVar6 + (int)puVar5);
      } while (puVar7 != (undefined *)0x0);
      goto loc_F001CD98;
    }
    param_3[2] = (int)puVar6;
  }
  *param_3 = (int)(param_2 + (*param_3 - (int)puVar7));
  _splx(iVar2);
locret_F001CDB4:
  return CONCAT44(puVar8,puVar7);
}
