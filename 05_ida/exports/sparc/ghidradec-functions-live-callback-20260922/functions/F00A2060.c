
/* WARNING: Removing unreachable block (ram,0xf00a225c) */
/* WARNING: Removing unreachable block (ram,0xf00a21f4) */
/* WARNING: Removing unreachable block (ram,0xf00a21ac) */
/* WARNING: Removing unreachable block (ram,0xf00a217c) */
/* WARNING: Removing unreachable block (ram,0xf00a23f4) */
/* WARNING: Removing unreachable block (ram,0xf00a2380) */
/* WARNING: Removing unreachable block (ram,0xf00a2338) */
/* WARNING: Removing unreachable block (ram,0xf00a2120) */
/* WARNING: Removing unreachable block (ram,0xf00a20b8) */
/* WARNING: Removing unreachable block (ram,0xf00a2308) */
/* WARNING: Removing unreachable block (ram,0xf00a2344) */
/* WARNING: Removing unreachable block (ram,0xf00a23b8) */
/* WARNING: Removing unreachable block (ram,0xf00a2164) */
/* WARNING: Removing unreachable block (ram,0xf00a2198) */
/* WARNING: Removing unreachable block (ram,0xf00a21bc) */
/* WARNING: Removing unreachable block (ram,0xf00a21fc) */
/* WARNING: Removing unreachable block (ram,0xf00a22d0) */
/* WARNING: Removing unreachable block (ram,0xf00a22f4) */
/* WARNING: Removing unreachable block (ram,0xf00a2090) */

undefined8 _pmap_alloc_reg_entry(int *param_1)

{
  undefined4 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar7;
  undefined4 unaff_l3;
  int iVar8;
  int *piVar9;
  undefined4 unaff_l4;
  int iVar10;
  int iVar11;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  int iVar12;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar13;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar14;
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
  dword_F013DF50 = dword_F013DF50 + 1;
  piVar13 = param_1;
  while (dword_F013DFB8 == 0) {
    if (dword_F013DFA8 == 0) {
      *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
      iVar8 = _kernel_map;
      _kmem_alloc_wired(_kernel_map,(undefined *)((int)register0x00000038 + -0xc),_page_size);
      if (iVar8 != 0) {
        _panic(aPmapAllocRegEn_3);
      }
      iVar8 = 0;
      iVar11 = 0;
      iVar10 = *(int *)((int)register0x00000038 + -0xc);
      if (word_F013DE76 != 0) {
        piVar13 = (int *)0x1;
        iVar12 = iVar8;
        do {
          iVar8 = _pool_zone;
          _zalloc();
          _bzero();
          *(int *)(iVar8 + 0x18) = iVar10;
          *(word *)(iVar8 + 0x1c) = word_F013DE72;
          *(word *)(iVar8 + 0x1e) = word_F013DE72;
          iVar7 = 0;
          if (word_F013DE72 == 0) {
            *(int *)(iVar8 + 0x14) = iVar12;
          }
          else {
            puVar6 = (undefined *)(iVar10 + 0xe);
            do {
              _bzero(iVar10,0x54);
              *(int *)(puVar6 + -10) = iVar8;
              puVar6[-1] = 1;
              *puVar6 = (char)iVar7;
              puVar6 = puVar6 + 0x54;
              iVar7 = iVar7 + 1;
              iVar10 = iVar10 + 0x54;
            } while (iVar7 < (int)(uint)word_F013DE72);
            *(int *)(iVar8 + 0x14) = iVar12;
          }
          _add_pool(&_reg_free,iVar8);
          iVar11 = iVar11 + 1;
          iVar12 = iVar8;
        } while (iVar11 < (int)(uint)word_F013DE76);
      }
      DAT_f013de94._8_4_ = DAT_f013de94._8_4_ + (uint)word_F013DE76;
      puVar5 = _garbage_zone;
      _zalloc();
      puVar5[2] = iVar8;
      puVar1 = puVar5;
      if ((undefined4 **)dword_F013DE1C != &_garbage) {
        *dword_F013DE1C = puVar5;
        puVar1 = _garbage;
      }
      _garbage = puVar1;
      puVar5[1] = dword_F013DE1C;
      *puVar5 = &_garbage;
      dword_F013DE1C = puVar5;
    }
    else {
      piVar4 = (int *)&_reg_free;
      _del_first_pool();
      if (piVar4 == (int *)0x0) {
        _panic(aPmapAllocRegEn_1);
        uRam00000008 = 0;
      }
      else {
        piVar4[2] = 0;
      }
      iVar8 = _kernel_map;
      _kmem_alloc_wired(_kernel_map,piVar4 + 2,_page_size);
      if (iVar8 != 0) {
        _panic(aPmapAllocRegEn_2);
      }
      iVar8 = _kernel_pmap;
      _pmap_resident_extract(_kernel_pmap,piVar4[2]);
      bVar14 = _mxcc == 0;
      piVar4[1] = iVar8;
      if (bVar14) {
        _pmap_enter_dev(_kernel_pmap,piVar4[2],iVar8,0,7,0,1);
      }
      iVar8 = piVar4[1];
      _vm_mem_ppi();
      iVar10 = _pg_desc_tbl + iVar8 * 0x14;
      if (((*(int *)(iVar10 + 4) != _kernel_pmap) ||
          ((*(uint *)(iVar10 + 8) >> 8) * 0x1000 - piVar4[2] != 0)) ||
         (*(int *)(_pg_desc_tbl + iVar8 * 0x14) != 0)) {
        _panic(aPmapAllocRegEn_5);
      }
      *piVar4 = iVar10;
      *(int **)(iVar10 + 0xc) = piVar4;
      piVar9 = (int *)piVar4[6];
      *(sword *)((int)piVar4 + 0x1e) = *(sword *)((int)piVar4 + 0x1e) + -1;
      iVar10 = 0;
      iVar8 = piVar4[2];
      if (word_F013DE72 != 0) {
        do {
          *piVar9 = iVar8;
          iVar8 = iVar8 + 0x400;
          iVar10 = iVar10 + 1;
          piVar9 = piVar9 + 0x15;
        } while (iVar10 < (int)(uint)word_F013DE72);
      }
      DAT_f013de94._4_4_ = DAT_f013de94._4_4_ + (uint)word_F013DE72;
      _add_pool(&_reg_semi_active,piVar4);
    }
  }
  puVar2 = &_reg_semi_active;
  _del_first_pool();
  if ((puVar2 == (undefined8 *)0x0) || (*(sword *)((int)puVar2 + 0x1e) == 0)) {
    _panic(aPmapAllocRegEn_4);
    iVar8 = *(int *)(puVar2 + 3);
  }
  else {
    iVar8 = *(int *)(puVar2 + 3);
  }
  iVar10 = *(word *)((int)puVar2 + 0x1c) - 1;
  *(sword *)((int)puVar2 + 0x1e) = *(sword *)((int)puVar2 + 0x1e) + -1;
  if (iVar10 != -1) {
    puVar6 = (undefined *)(iVar8 + 0xf);
    do {
      if (*(int *)(puVar6 + -7) == 0) {
        *(int **)(puVar6 + -7) = param_1;
        *puVar6 = 0;
        puVar3 = &_reg_semi_active;
        if (*(sword *)((int)puVar2 + 0x1e) == 0) {
          puVar3 = &_reg_active;
        }
        _add_pool(puVar3,puVar2);
        *param_1 = iVar8;
        DAT_f013de94._0_4_ = DAT_f013de94._0_4_ + 1;
        break;
      }
      puVar6 = puVar6 + 0x54;
      iVar10 = iVar10 + -1;
      iVar8 = iVar8 + 0x54;
    } while (iVar10 != -1);
  }
  return CONCAT44(param_1,piVar13);
}

