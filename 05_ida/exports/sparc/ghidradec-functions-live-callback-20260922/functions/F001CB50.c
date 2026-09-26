
/* WARNING: Removing unreachable block (ram,0xf001cc68) */
/* WARNING: Removing unreachable block (ram,0xf001cc28) */
/* WARNING: Removing unreachable block (ram,0xf001cbac) */
/* WARNING: Removing unreachable block (ram,0xf001cbdc) */
/* WARNING: Removing unreachable block (ram,0xf001cb54) */

undefined8 _putc(uint param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar7;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar8;
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
  uVar3 = param_1;
  _spltty();
  puVar1 = _cfreelist;
  puVar6 = (undefined4 *)param_2[2];
  if ((puVar6 == (undefined4 *)0x0) || (*param_2 < 0)) {
    puVar6 = _cfreelist + 1;
    if (_cfreelist == (undefined4 *)0x0) {
loc_F001CBDC:
      _splx(uVar3);
      uVar7 = 0xffffffff;
      goto locret_F001CC74;
    }
    _cfreecount = _cfreecount + -0x34;
    puVar2 = (undefined4 *)*_cfreelist;
    *_cfreelist = 0;
    _cfreelist = puVar2;
    _bzero(puVar6,8);
    param_2[1] = (int)(puVar1 + 3);
loc_F001CC10:
    puVar6 = puVar1 + 3;
  }
  else if (((uint)puVar6 & 0x3f) == 0) {
    bVar8 = _cfreelist == (undefined4 *)0x0;
    puVar6[-0x10] = _cfreelist;
    if (bVar8) goto loc_F001CBDC;
    _cfreelist = (undefined4 *)*puVar1;
    _cfreecount = _cfreecount + -0x34;
    *puVar1 = 0;
    goto loc_F001CC10;
  }
  if ((param_1 & 0x100) != 0) {
    iVar4 = (int)((uint)puVar6 & 0x3f) >> 3;
    iVar5 = iVar4 + ((uint)puVar6 & 0xffffffc0);
    *(byte *)(iVar5 + 4) =
         *(byte *)(iVar5 + 4) |
         (byte)(1 << ((char)((uint)puVar6 & 0x3f) + (char)iVar4 * -8 & 0x1fU));
  }
  *(char *)puVar6 = (char)param_1;
  param_2[2] = (int)puVar6 + 1;
  *param_2 = *param_2 + 1;
  _splx(uVar3);
  uVar7 = 0;
locret_F001CC74:
  return CONCAT44(param_2,uVar7);
}

