
/* WARNING: Removing unreachable block (ram,0xf009dff0) */
/* WARNING: Removing unreachable block (ram,0xf009e1ec) */
/* WARNING: Removing unreachable block (ram,0xf009e1b4) */
/* WARNING: Removing unreachable block (ram,0xf009e42c) */
/* WARNING: Removing unreachable block (ram,0xf009e368) */
/* WARNING: Removing unreachable block (ram,0xf009e338) */
/* WARNING: Removing unreachable block (ram,0xf009e294) */
/* WARNING: Removing unreachable block (ram,0xf009e22c) */
/* WARNING: Removing unreachable block (ram,0xf009e190) */
/* WARNING: Removing unreachable block (ram,0xf009e0b8) */
/* WARNING: Removing unreachable block (ram,0xf009dfcc) */
/* WARNING: Removing unreachable block (ram,0xf009dfb8) */
/* WARNING: Removing unreachable block (ram,0xf009e16c) */
/* WARNING: Removing unreachable block (ram,0xf009e178) */
/* WARNING: Removing unreachable block (ram,0xf009e218) */
/* WARNING: Removing unreachable block (ram,0xf009e288) */
/* WARNING: Removing unreachable block (ram,0xf009e328) */
/* WARNING: Removing unreachable block (ram,0xf009e348) */
/* WARNING: Removing unreachable block (ram,0xf009e424) */
/* WARNING: Removing unreachable block (ram,0xf009e444) */
/* WARNING: Removing unreachable block (ram,0xf009e1d4) */
/* WARNING: Removing unreachable block (ram,0xf009dfe0) */
/* WARNING: Removing unreachable block (ram,0xf009df78) */
/* WARNING: Removing unreachable block (ram,0xf009df9c) */

undefined8
_pmap_enter_dev(int *param_1,int *param_2,uint param_3,uint param_4,int param_5,undefined4 param_6)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  byte bVar8;
  int *piVar9;
  undefined4 unaff_l0;
  undefined4 *puVar10;
  undefined4 unaff_l1;
  int iVar11;
  undefined4 unaff_l3;
  uint uVar12;
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
  *(int **)((int)register0x00000038 + 0x48) = param_2;
  iVar11 = *(int *)((int)register0x00000038 + 0x5c);
  if (param_1 == (int *)0x0) goto locret_F009E44C;
  dword_F013DED0 = dword_F013DED0 + 1;
  if (param_5 == 0) {
    _pmap_remove(param_1,param_2,(int)param_2 + _page_size);
    goto locret_F009E44C;
  }
  if (((uint)param_2 & _page_size - 1U) != 0) {
    _panic(aPmapEnterDevVi);
  }
  puVar10 = (undefined4 *)0x0;
loc_F009DFAC:
  piVar1 = (int *)((param_4 & 0xf) << 0x14);
  uVar12 = (uint)piVar1 | param_3 >> 0xc;
  while( true ) {
    _splvm();
    param_2 = param_1;
    _pmap_page_table_entry(param_1,*(undefined4 *)((int)register0x00000038 + 0x48),0);
    if (param_2 != (int *)0x0) break;
    _splx(piVar1);
    piVar1 = param_1;
    _pmap_expand(param_1,*(undefined4 *)((int)register0x00000038 + 0x48),3);
  }
  if (*(char *)((int)param_2 + 0xd) == '\x03') {
    iVar3 = *param_2;
    uVar2 = *(uint *)((int)register0x00000038 + 0x48) >> 10 & 0xfc;
  }
  else if (*(char *)((int)param_2 + 0xd) == '\x02') {
    iVar3 = *param_2;
    uVar2 = *(word *)((int)register0x00000038 + 0x48) & 0xfc;
  }
  else {
    iVar3 = *param_2;
    uVar2 = (uint)*(byte *)((int)register0x00000038 + 0x48) << 2;
  }
  puVar5 = (uint *)(iVar3 + uVar2);
  if ((*puVar5 & 3) == 2) {
    if (*(char *)((int)param_2 + 0xd) == '\x03') {
      if (*puVar5 >> 8 == uVar12) {
        uVar2 = *(uint *)((int)register0x00000038 + 0x48) >> 0xf & 4;
        uVar6 = *(uint *)((int)param_2 + uVar2 + 0x10);
        uVar4 = 1 << ((byte)(*(uint *)((int)register0x00000038 + 0x48) >> 0xc) & 0x1e);
        uVar12 = uVar6 & uVar4;
        if ((iVar11 == 0) || (uVar12 != 0)) {
          if ((iVar11 == 0) && (uVar12 != 0)) {
            if (*(char *)((int)param_2 + 0xd) == '\x03') {
              uVar12 = *(uint *)((int)register0x00000038 + 0x48) >> 0xf;
              bVar8 = (byte)(*(uint *)((int)register0x00000038 + 0x48) >> 0xc) & 0x1e;
loc_F009E130:
              *(uint *)((int)param_2 + (uVar12 & 4) + 0x10) =
                   *(uint *)((int)param_2 + (uVar12 & 4) + 0x10) & ~(1 << bVar8);
            }
            else {
              if (*(char *)((int)param_2 + 0xd) == '\x02') {
                uVar12 = *(uint *)((int)register0x00000038 + 0x48) >> 0x15;
                bVar8 = (byte)(*(uint *)((int)register0x00000038 + 0x48) >> 0x12) & 0x1f;
                goto loc_F009E130;
              }
              bVar8 = *(byte *)((int)register0x00000038 + 0x48) >> 5;
              param_2[bVar8 + 4] =
                   param_2[bVar8 + 4] & ~(1 << (*(byte *)((int)register0x00000038 + 0x48) & 0x1f));
            }
            _pmap_unwire_mapping(param_1,*(undefined4 *)((int)register0x00000038 + 0x48));
          }
        }
        else {
          *(uint *)((int)param_2 + uVar2 + 0x10) = uVar6 | uVar4;
          _pmap_wire_mapping(param_1,*(undefined4 *)((int)register0x00000038 + 0x48));
        }
        piVar9 = param_1;
        _vm_to_srmmu_prot(param_1,param_5);
        *(int **)((int)register0x00000038 + -0xc) = param_2;
        _update_pte((undefined *)((int)register0x00000038 + -0xc),
                    *(undefined4 *)((int)register0x00000038 + 0x48),piVar9,param_6);
        goto loc_F009E40C;
      }
      uVar2 = *puVar5;
    }
    else {
      uVar2 = *puVar5;
    }
  }
  else {
    uVar2 = *puVar5;
  }
  if ((uVar2 & 3) == 2) {
    _splx(piVar1);
    if (*(char *)((int)param_2 + 0xd) != '\x03') {
      *(int **)((int)register0x00000038 + -0xc) = param_2;
      _pmap_scatter_pte(param_1,(undefined *)((int)register0x00000038 + -0xc),
                        *(undefined4 *)((int)register0x00000038 + 0x48));
    }
    _pmap_remove(param_1,*(int *)((int)register0x00000038 + 0x48),
                 *(int *)((int)register0x00000038 + 0x48) + _page_size);
    goto loc_F009DFAC;
  }
  if (((param_4 != 0) || (_physmax <= param_3)) || (uVar2 = param_3, _vm_valid_page(), uVar2 == 0))
  goto loc_F009E334;
  uVar2 = param_3;
  _vm_mem_ppi();
  iVar3 = _pg_desc_tbl;
  iVar7 = uVar2 * 0x14;
  piVar9 = (int *)(_pg_desc_tbl + iVar7);
  if (piVar9[1] == 0) {
    uVar2 = *(uint *)((int)register0x00000038 + 0x48);
    piVar9[1] = (int)param_1;
    piVar9[2] = (uint)*(byte *)((int)piVar9 + 0xb) | (uVar2 >> 0xc) << 8;
    *(undefined4 *)(iVar3 + iVar7) = 0;
    goto loc_F009E2CC;
  }
  uVar2 = *(uint *)((int)register0x00000038 + 0x48);
  if (puVar10 == (undefined4 *)0x0) {
    _splx(piVar1);
    puVar10 = _pv_entry_zone;
    _zalloc();
    goto loc_F009DFAC;
  }
  puVar10[1] = param_1;
  puVar10[2] = (uint)*(byte *)((int)puVar10 + 0xb) | (uVar2 >> 0xc) << 8;
  *puVar10 = *(undefined4 *)(iVar3 + iVar7);
  *(undefined4 **)(iVar3 + iVar7) = puVar10;
  puVar10 = (undefined4 *)0x0;
loc_F009E2CC:
  if ((int *)piVar9[1] == param_1) {
    iVar3 = *(int *)((int)register0x00000038 + 0x48);
    if (((uint)piVar9[2] >> 8) * 0x1000 - iVar3 != 0) {
      iVar3 = *piVar9;
      goto loc_F009E2FC;
    }
  }
  else {
    iVar3 = *piVar9;
loc_F009E2FC:
    if ((*(int **)(iVar3 + 4) != param_1) ||
       ((*(uint *)(iVar3 + 8) >> 8) * 0x1000 - *(int *)((int)register0x00000038 + 0x48) != 0)) {
      _panic(aPmapEnterDevWr);
    }
loc_F009E334:
    iVar3 = *(int *)((int)register0x00000038 + 0x48);
  }
  _pmap_allocate_mapping(param_1,iVar3,iVar11);
  *(int **)((int)register0x00000038 + -0xc) = param_2;
  piVar9 = param_1;
  _vm_to_srmmu_prot(param_1,param_5);
  _set_pte((undefined *)((int)register0x00000038 + -0xc),
           *(undefined4 *)((int)register0x00000038 + 0x48),uVar12,piVar9,param_6,0,0);
  if (iVar11 != 0) {
    if (*(char *)((int)param_2 + 0xd) == '\x03') {
      uVar12 = *(uint *)((int)register0x00000038 + 0x48) >> 0xf;
      bVar8 = (byte)(*(uint *)((int)register0x00000038 + 0x48) >> 0xc) & 0x1e;
    }
    else {
      if (*(char *)((int)param_2 + 0xd) != '\x02') {
        bVar8 = *(byte *)((int)register0x00000038 + 0x48) >> 5;
        param_2[bVar8 + 4] =
             param_2[bVar8 + 4] | 1 << (*(byte *)((int)register0x00000038 + 0x48) & 0x1f);
        goto loc_F009E40C;
      }
      uVar12 = *(uint *)((int)register0x00000038 + 0x48) >> 0x15;
      bVar8 = (byte)(*(uint *)((int)register0x00000038 + 0x48) >> 0x12) & 0x1f;
    }
    *(uint *)((int)param_2 + (uVar12 & 4) + 0x10) =
         *(uint *)((int)param_2 + (uVar12 & 4) + 0x10) | 1 << bVar8;
  }
loc_F009E40C:
  if (_level3_only._0_4_ == 0) {
    *(int **)((int)register0x00000038 + -0xc) = param_2;
    _pmap_gather_pte(param_1,(undefined *)((int)register0x00000038 + -0xc),
                     *(undefined4 *)((int)register0x00000038 + 0x48));
  }
  _splx(piVar1);
  if (puVar10 != (undefined4 *)0x0) {
    _zfree(_pv_entry_zone,puVar10);
  }
locret_F009E44C:
  return CONCAT44(param_2,param_1);
}
