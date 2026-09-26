
/* WARNING: Removing unreachable block (ram,0xf00a29f0) */
/* WARNING: Removing unreachable block (ram,0xf00a2c20) */
/* WARNING: Removing unreachable block (ram,0xf00a2b4c) */
/* WARNING: Removing unreachable block (ram,0xf00a2b0c) */
/* WARNING: Removing unreachable block (ram,0xf00a2ae8) */
/* WARNING: Removing unreachable block (ram,0xf00a2ab4) */
/* WARNING: Removing unreachable block (ram,0xf00a2d08) */
/* WARNING: Removing unreachable block (ram,0xf00a2c98) */
/* WARNING: Removing unreachable block (ram,0xf00a2c58) */
/* WARNING: Removing unreachable block (ram,0xf00a2c8c) */
/* WARNING: Removing unreachable block (ram,0xf00a2cd4) */
/* WARNING: Removing unreachable block (ram,0xf00a2d40) */
/* WARNING: Removing unreachable block (ram,0xf00a2acc) */
/* WARNING: Removing unreachable block (ram,0xf00a2afc) */
/* WARNING: Removing unreachable block (ram,0xf00a2b44) */
/* WARNING: Removing unreachable block (ram,0xf00a2bac) */
/* WARNING: Removing unreachable block (ram,0xf00a29c8) */
/* WARNING: Removing unreachable block (ram,0xf00a2a70) */
/* WARNING: Removing unreachable block (ram,0xf00a2c44) */
/* WARNING: Removing unreachable block (ram,0xf00a29a4) */

undefined8 _pmap_alloc_seg_entry(int param_1,uint param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 unaff_l0;
  undefined *puVar6;
  undefined4 unaff_l1;
  int iVar7;
  undefined4 unaff_l3;
  int iVar8;
  int iVar9;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar10;
  int *piVar11;
  int iVar12;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
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
  dword_F013DF64 = dword_F013DF64 + 1;
  if ((param_1 == _kernel_pmap) || (0xefffffff < param_2)) {
    _pmap_alloc_kseg_entry(param_1,param_2,param_3);
    iVar10 = param_1;
  }
  else {
    while (dword_F013DFE8 == 0) {
      if (dword_F013DFD8 == 0) {
        *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
        iVar10 = _kernel_map;
        _kmem_alloc_wired(_kernel_map,(undefined *)((int)register0x00000038 + -0xc),_page_size);
        if (iVar10 != 0) {
          _panic(aPmapAllocSegEn_3);
        }
        iVar10 = 0;
        iVar9 = 0;
        iVar12 = *(int *)((int)register0x00000038 + -0xc);
        iVar8 = iVar10;
        if (word_F013DE78 != 0) {
          do {
            iVar10 = _pool_zone;
            _zalloc();
            _bzero();
            *(int *)(iVar10 + 0x18) = iVar12;
            *(word *)(iVar10 + 0x1c) = word_F013DE74;
            *(word *)(iVar10 + 0x1e) = word_F013DE74;
            iVar7 = 0;
            if (word_F013DE74 == 0) {
              *(int *)(iVar10 + 0x14) = iVar8;
            }
            else {
              puVar6 = (undefined *)(iVar12 + 0xe);
              do {
                _bzero(iVar12,0x28);
                *(int *)(puVar6 + -10) = iVar10;
                puVar6[-1] = 0;
                *puVar6 = (char)iVar7;
                puVar6 = puVar6 + 0x28;
                iVar7 = iVar7 + 1;
                iVar12 = iVar12 + 0x28;
              } while (iVar7 < (int)(uint)word_F013DE74);
              *(int *)(iVar10 + 0x14) = iVar8;
            }
            _add_pool(&_seg_free,iVar10);
            iVar9 = iVar9 + 1;
            iVar8 = iVar10;
          } while (iVar9 < (int)(uint)word_F013DE78);
        }
        DAT_f013de88._8_4_ = DAT_f013de88._8_4_ + (uint)word_F013DE78;
        puVar5 = _garbage_zone;
        _zalloc();
        puVar5[2] = iVar10;
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
        piVar4 = (int *)&_seg_free;
        _del_first_pool();
        if (piVar4 == (int *)0x0) {
          _panic(aPmapAllocSegEn_1);
          uRam00000008 = 0;
        }
        else {
          piVar4[2] = 0;
        }
        iVar10 = _kernel_map;
        _kmem_alloc_wired(_kernel_map,piVar4 + 2,_page_size);
        if (iVar10 != 0) {
          _panic(aPmapAllocSegEn_2);
        }
        iVar10 = _kernel_pmap;
        _pmap_resident_extract(_kernel_pmap,piVar4[2]);
        bVar13 = _mxcc == 0;
        piVar4[1] = iVar10;
        if (bVar13) {
          _pmap_enter_dev(_kernel_pmap,piVar4[2],iVar10,0,7,0,1);
        }
        iVar10 = piVar4[1];
        _vm_mem_ppi();
        iVar8 = _pg_desc_tbl + iVar10 * 0x14;
        if (((*(int *)(iVar8 + 4) != _kernel_pmap) ||
            ((*(uint *)(iVar8 + 8) >> 8) * 0x1000 - piVar4[2] != 0)) ||
           (*(int *)(_pg_desc_tbl + iVar10 * 0x14) != 0)) {
          _panic(aPmapAllocSegEn_5);
        }
        *piVar4 = iVar8;
        *(int **)(iVar8 + 0xc) = piVar4;
        piVar11 = (int *)piVar4[6];
        *(sword *)((int)piVar4 + 0x1e) = *(sword *)((int)piVar4 + 0x1e) + -1;
        iVar8 = 0;
        iVar10 = piVar4[2];
        if (word_F013DE74 != 0) {
          do {
            *piVar11 = iVar10;
            iVar10 = iVar10 + 0x100;
            iVar8 = iVar8 + 1;
            piVar11 = piVar11 + 10;
          } while (iVar8 < (int)(uint)word_F013DE74);
        }
        DAT_f013de88._4_4_ = DAT_f013de88._4_4_ + (uint)word_F013DE74;
        _add_pool(&_seg_semi_active,piVar4);
      }
    }
    puVar2 = &_seg_semi_active;
    _del_first_pool();
    if ((puVar2 == (undefined8 *)0x0) || (*(sword *)((int)puVar2 + 0x1e) == 0)) {
      _panic(aPmapAllocSegEn_4);
      iVar10 = *(int *)(puVar2 + 3);
    }
    else {
      iVar10 = *(int *)(puVar2 + 3);
    }
    iVar8 = *(word *)((int)puVar2 + 0x1c) - 1;
    *(sword *)((int)puVar2 + 0x1e) = *(sword *)((int)puVar2 + 0x1e) + -1;
    if (iVar8 != -1) {
      puVar6 = (undefined *)(iVar10 + 0xd);
      do {
        if (*(int *)(puVar6 + -5) == 0) {
          *(int *)(puVar6 + -5) = param_1;
          puVar6[2] = 0;
          *(undefined4 *)(puVar6 + 3) = 0;
          *(undefined4 *)(puVar6 + 7) = 0;
          *(undefined4 *)(puVar6 + 0xb) = 0;
          *(undefined4 *)(puVar6 + 0xf) = 0;
          *(undefined4 *)(puVar6 + 0x13) = 0;
          *(uint *)(puVar6 + 0x17) = param_2;
          puVar3 = &_seg_semi_active;
          if (*(sword *)((int)puVar2 + 0x1e) == 0) {
            puVar3 = &_seg_active;
          }
          _add_pool(puVar3,puVar2);
          *puVar6 = (char)param_3;
          DAT_f013de88._0_4_ = DAT_f013de88._0_4_ + 1;
          break;
        }
        puVar6 = puVar6 + 0x28;
        iVar8 = iVar8 + -1;
        iVar10 = iVar10 + 0x28;
      } while (iVar8 != -1);
    }
  }
  return CONCAT44(param_2,iVar10);
}
