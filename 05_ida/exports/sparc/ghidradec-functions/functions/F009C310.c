
/* WARNING: Removing unreachable block (ram,0xf009c494) */
/* WARNING: Removing unreachable block (ram,0xf009c4f8) */
/* WARNING: Removing unreachable block (ram,0xf009c39c) */
/* WARNING: Removing unreachable block (ram,0xf009c4c0) */
/* WARNING: Removing unreachable block (ram,0xf009c594) */
/* WARNING: Removing unreachable block (ram,0xf009c3b4) */
/* WARNING: Removing unreachable block (ram,0xf009c340) */

qword _pmap_map(undefined4 param_1,uint param_2,uint param_3,int param_4,undefined4 param_5,
               uint param_6)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 unaff_l0;
  uint uVar7;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar8;
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
  *(undefined4 *)((int)register0x00000038 + 0x44) = param_1;
  dword_F013DEA4 = dword_F013DEA4 + 1;
  if (_pmap_initialized != 0) {
    _panic(aPmapMapPmapIni);
  }
  uVar7 = (param_3 & 0xf) << 0x14 | param_2 >> 0xc;
  uVar4 = *(uint *)((int)register0x00000038 + 0x44) & 0xfffff000;
  uVar1 = *(uint *)((int)register0x00000038 + 0x44) + param_4 + 0xfff;
  uVar8 = uVar1 & 0xfffff000;
  *(uint *)((int)register0x00000038 + 0x44) = uVar4;
  if (uVar4 < uVar8) {
    do {
      while (piVar2 = _kernel_pmap,
            _pmap_page_table_entry(_kernel_pmap,*(undefined4 *)((int)register0x00000038 + 0x44),0),
            piVar2 == (int *)0x0) {
        _pmap_expand(_kernel_pmap,*(undefined4 *)((int)register0x00000038 + 0x44),3);
      }
      if (*(char *)((int)piVar2 + 0xd) == '\x03') {
        iVar5 = *piVar2;
        uVar4 = *(uint *)((int)register0x00000038 + 0x44) >> 10 & 0xfc;
      }
      else if (*(char *)((int)piVar2 + 0xd) == '\x02') {
        iVar5 = *piVar2;
        uVar4 = *(word *)((int)register0x00000038 + 0x44) & 0xfc;
      }
      else {
        iVar5 = *piVar2;
        uVar4 = (uint)*(byte *)((int)register0x00000038 + 0x44) << 2;
      }
      uVar4 = *(uint *)(iVar5 + uVar4);
      uVar6 = *(uint *)((int)register0x00000038 + 0x44);
      if ((uVar4 & 3) == 2) {
        if (*(char *)((int)piVar2 + 0xd) == '\x03') {
          if (uVar4 >> 8 != uVar7) {
loc_F009C494:
            _panic(aPmapMapInconsi);
          }
        }
        else {
          if (*(char *)((int)piVar2 + 0xd) == '\x02') {
            uVar6 = param_2 & 0xfffc0000;
          }
          else {
            uVar6 = param_2 & 0xff000000;
          }
          if (uVar4 >> 8 != uVar6 >> 0xc) goto loc_F009C494;
        }
      }
      else {
        iVar5 = *piVar2;
        *(uint *)((int)register0x00000038 + -0xc) = uVar7 << 8;
        piVar3 = _kernel_pmap;
        _vm_to_srmmu_prot(_kernel_pmap,param_5);
        uVar4 = *(uint *)((int)register0x00000038 + -0xc) & 0xffffff60 | ((uint)piVar3 & 7) << 2 |
                (param_6 & 1) << 7 | 2;
        *(uint *)((int)register0x00000038 + -0xc) = uVar4;
        _mmu_writepte(uVar4,iVar5 + (uVar6 >> 10 & 0xfc),
                      *(undefined4 *)((int)register0x00000038 + 0x44),3,0);
        if (*(uint *)((int)register0x00000038 + 0x44) ==
            (*(uint *)((int)register0x00000038 + 0x44) + _page_mask & ~_page_mask)) {
          *(char *)((int)piVar2 + 0xf) = *(char *)((int)piVar2 + 0xf) + '\x01';
          piVar3 = _kernel_pmap;
          uVar4 = *(uint *)((int)register0x00000038 + 0x44) >> 0xf & 4;
          *(uint *)((int)piVar2 + uVar4 + 0x10) =
               *(uint *)((int)piVar2 + uVar4 + 0x10) |
               1 << ((byte)(*(uint *)((int)register0x00000038 + 0x44) >> 0xc) & 0x1e);
          piVar3[8] = piVar3[8] + 1;
          piVar3[9] = piVar3[9] + 1;
        }
        if (_level3_only._0_4_ == 0) {
          *(int **)((int)register0x00000038 + -0x10) = piVar2;
          _pmap_gather_pte(_kernel_pmap,(undefined *)((int)register0x00000038 + -0x10),
                           *(undefined4 *)((int)register0x00000038 + 0x44));
        }
      }
      param_2 = param_2 + 0x1000;
      iVar5 = *(int *)((int)register0x00000038 + 0x44);
      uVar7 = uVar7 + 1;
      *(uint *)((int)register0x00000038 + 0x44) = iVar5 + 0x1000U;
    } while (iVar5 + 0x1000U < uVar8);
  }
  return CONCAT44(param_2,uVar1) & 0xfffffffffffff000;
}
