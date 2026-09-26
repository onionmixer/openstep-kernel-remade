
/* WARNING: Removing unreachable block (ram,0xf009edc0) */
/* WARNING: Removing unreachable block (ram,0xf009eca0) */
/* WARNING: Removing unreachable block (ram,0xf009ec84) */
/* WARNING: Removing unreachable block (ram,0xf009ec54) */
/* WARNING: Removing unreachable block (ram,0xf009ec6c) */
/* WARNING: Removing unreachable block (ram,0xf009ec98) */
/* WARNING: Removing unreachable block (ram,0xf009ee6c) */
/* WARNING: Removing unreachable block (ram,0xf009ee74) */
/* WARNING: Removing unreachable block (ram,0xf009ec40) */

undefined8 _pmap_change_wiring(int param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  byte bVar5;
  int iVar6;
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
  *(undefined4 *)((int)register0x00000038 + 0x48) = param_2;
  iVar2 = dword_F013DEEC + 1;
  dword_F013DEEC = iVar2;
  _splvm();
  iVar3 = param_1;
  _pmap_page_table_entry(param_1,*(undefined4 *)((int)register0x00000038 + 0x48),0);
  if (iVar3 == 0) {
    _panic(aPmapChangeWiri);
    cVar1 = cRam0000000d;
  }
  else {
    cVar1 = *(char *)(iVar3 + 0xd);
  }
  if (cVar1 == '\x03') {
    cVar1 = *(char *)(iVar3 + 0xd);
  }
  else {
    _splx(iVar2);
    *(int *)((int)register0x00000038 + -0xc) = iVar3;
    iVar3 = param_1;
    _pmap_scatter_pte(param_1,(undefined *)((int)register0x00000038 + -0xc),
                      *(undefined4 *)((int)register0x00000038 + 0x48));
    iVar2 = iVar3;
    _splvm();
    cVar1 = *(char *)(iVar3 + 0xd);
  }
  if (cVar1 == '\x03') {
    uVar4 = *(uint *)((int)register0x00000038 + 0x48) >> 0xf & 4;
    bVar5 = (byte)(*(uint *)((int)register0x00000038 + 0x48) >> 0xc) & 0x1e;
  }
  else {
    bVar5 = *(byte *)((int)register0x00000038 + 0x48);
    if (cVar1 == '\x02') {
      bVar5 = (byte)(*(uint *)((int)register0x00000038 + 0x48) >> 0x12);
      uVar4 = *(uint *)((int)register0x00000038 + 0x48) >> 0x15 & 4;
    }
    else {
      uVar4 = (uint)(bVar5 >> 5) << 2;
    }
    bVar5 = bVar5 & 0x1f;
  }
  uVar4 = *(uint *)(uVar4 + iVar3 + 0x10) & 1 << bVar5;
  if ((param_3 == 0) || (uVar4 != 0)) {
    if ((param_3 != 0) || (uVar4 == 0)) goto loc_F009EE74;
    if (*(char *)(iVar3 + 0xd) == '\x03') {
      uVar4 = *(uint *)((int)register0x00000038 + 0x48) >> 0xf;
      bVar5 = (byte)(*(uint *)((int)register0x00000038 + 0x48) >> 0xc) & 0x1e;
loc_F009EE30:
      iVar6 = (uVar4 & 4) + iVar3;
      *(uint *)(iVar6 + 0x10) = *(uint *)(iVar6 + 0x10) & ~(1 << bVar5);
    }
    else {
      if (*(char *)(iVar3 + 0xd) == '\x02') {
        uVar4 = *(uint *)((int)register0x00000038 + 0x48) >> 0x15;
        bVar5 = (byte)(*(uint *)((int)register0x00000038 + 0x48) >> 0x12) & 0x1f;
        goto loc_F009EE30;
      }
      iVar6 = (uint)(*(byte *)((int)register0x00000038 + 0x48) >> 5) * 4 + iVar3;
      *(uint *)(iVar6 + 0x10) =
           *(uint *)(iVar6 + 0x10) & ~(1 << (*(byte *)((int)register0x00000038 + 0x48) & 0x1f));
    }
    _pmap_unwire_mapping(param_1,*(undefined4 *)((int)register0x00000038 + 0x48));
    goto loc_F009EE74;
  }
  if (*(char *)(iVar3 + 0xd) == '\x03') {
    uVar4 = *(uint *)((int)register0x00000038 + 0x48) >> 0xf;
    bVar5 = (byte)(*(uint *)((int)register0x00000038 + 0x48) >> 0xc) & 0x1e;
loc_F009ED84:
    iVar6 = (uVar4 & 4) + iVar3;
    *(uint *)(iVar6 + 0x10) = *(uint *)(iVar6 + 0x10) | 1 << bVar5;
  }
  else {
    if (*(char *)(iVar3 + 0xd) == '\x02') {
      uVar4 = *(uint *)((int)register0x00000038 + 0x48) >> 0x15;
      bVar5 = (byte)(*(uint *)((int)register0x00000038 + 0x48) >> 0x12) & 0x1f;
      goto loc_F009ED84;
    }
    iVar6 = (uint)(*(byte *)((int)register0x00000038 + 0x48) >> 5) * 4 + iVar3;
    *(uint *)(iVar6 + 0x10) =
         *(uint *)(iVar6 + 0x10) | 1 << (*(byte *)((int)register0x00000038 + 0x48) & 0x1f);
  }
  _pmap_wire_mapping(param_1,*(undefined4 *)((int)register0x00000038 + 0x48));
loc_F009EE74:
  _splx(iVar2);
  return CONCAT44(iVar3,param_1);
}
