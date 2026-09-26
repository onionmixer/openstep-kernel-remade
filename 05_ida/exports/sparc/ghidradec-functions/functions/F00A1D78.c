
/* WARNING: Removing unreachable block (ram,0xf00a1e74) */
/* WARNING: Removing unreachable block (ram,0xf00a1df4) */
/* WARNING: Removing unreachable block (ram,0xf00a1e38) */
/* WARNING: Removing unreachable block (ram,0xf00a1e9c) */
/* WARNING: Removing unreachable block (ram,0xf00a1de8) */

undefined8 _init_kernel_page_tables(int param_1,undefined *param_2)

{
  byte bVar1;
  uint uVar2;
  undefined4 unaff_l0;
  undefined *puVar3;
  undefined4 unaff_l1;
  int iVar4;
  int *piVar5;
  undefined4 unaff_l3;
  int *piVar6;
  undefined4 unaff_l4;
  int iVar7;
  undefined4 unaff_l5;
  int iVar8;
  undefined4 unaff_l6;
  int iVar9;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar10;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  uint auStackX_0 [23];
  
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
  DAT_f013de34 = &_kseg_active;
  _kseg_active._0_4_ = &_kseg_active;
  dword_F013DE38 = 0;
  DAT_f013de44 = &_kseg_semi_active;
  _kseg_semi_active._0_4_ = &_kseg_semi_active;
  dword_F013DE48 = 0;
  iVar10 = 0;
  if (0 < param_1) {
    param_2 = DAT_f013dc00;
    piVar6 = (int *)(_kernel_seg_pools + 0x18);
    piVar5 = _kernel_seg_entries;
    iVar7 = _kernel_seg_tables;
    iVar8 = _kernel_seg_pools;
    iVar9 = _kernel_seg_tables_phys;
    do {
      _bzero(iVar7,_page_size);
      _bzero(iVar8,0x20);
      piVar6[-4] = iVar7;
      piVar6[-5] = iVar9;
      *(word *)(piVar6 + 1) = word_F013DE74;
      *(word *)((int)piVar6 + 6) = word_F013DE74;
      *piVar6 = (int)piVar5;
      iVar4 = 0;
      if (word_F013DE74 != 0) {
        puVar3 = (undefined *)((int)piVar5 + 0xe);
        do {
          _bzero(piVar5,0x28);
          *(int *)(puVar3 + -10) = iVar8;
          puVar3[-1] = 0;
          *puVar3 = (char)iVar4;
          *piVar5 = iVar7;
          iVar7 = iVar7 + 0x100;
          iVar9 = iVar9 + 0x100;
          puVar3 = puVar3 + 0x28;
          iVar4 = iVar4 + 1;
          piVar5 = piVar5 + 10;
        } while (iVar4 < (int)(uint)word_F013DE74);
      }
      _add_pool(&_kseg_semi_active,iVar8);
      iVar10 = iVar10 + 1;
      piVar6 = piVar6 + 8;
      iVar8 = iVar8 + 0x20;
    } while (iVar10 < param_1);
  }
  _bzero(_kernel_reg_entry,0x54);
  DAT_f013e07d[0] = 1;
  _kernel_pmap = _kernel_pmap_store;
  _kernel_pmap_store._0_4_ = _kernel_reg_entry;
  DAT_f013e078._0_4_ = _kernel_pmap_store;
  _active_pmap = _kernel_pmap_store;
  *(undefined4 *)((int)register0x00000038 + -0x34) = 0;
  iVar10 = 0;
  _kernel_reg_entry._0_4_ = _kernel_region;
  _kernel_pmap_store._20_4_ = _context_table;
  *(undefined **)(_context_table + 8) = _kernel_pmap_store;
  _kernel_pmap_store._28_4_ = 1;
  _kernel_pmap_store._36_4_ = 1;
  _kernel_pmap_store._32_4_ = 1;
  _kernel_pmap_store._24_4_ = 0;
  *(undefined *)((int)register0x00000038 + -0x23) = 3;
  *(undefined4 *)((int)register0x00000038 + -0x20) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
  do {
    if (*(char *)((int)register0x00000038 + -0x23) == '\x03') {
      uVar2 = *(uint *)((int)register0x00000038 + -0x34) >> 0xf & 4;
      bVar1 = (byte)(*(uint *)((int)register0x00000038 + -0x34) >> 0xc) & 0x1e;
    }
    else {
      bVar1 = *(byte *)((int)register0x00000038 + -0x34);
      if (*(char *)((int)register0x00000038 + -0x23) == '\x02') {
        bVar1 = (byte)(*(uint *)((int)register0x00000038 + -0x34) >> 0x12);
        uVar2 = *(uint *)((int)register0x00000038 + -0x34) >> 0x15 & 4;
      }
      else {
        uVar2 = (uint)(bVar1 >> 5) << 2;
      }
      bVar1 = bVar1 & 0x1f;
    }
    *(uint *)((int)register0x00000038 + (uVar2 - 0x20)) =
         *(uint *)((int)register0x00000038 + (uVar2 - 0x20)) | 1 << bVar1;
    if (*(char *)((int)register0x00000038 + -0x23) == '\x03') {
      uVar2 = *(uint *)((int)register0x00000038 + -0x34) >> 0xf;
      bVar1 = (byte)(*(uint *)((int)register0x00000038 + -0x34) >> 0xc) & 0x1e;
loc_F00A1FDC:
      *(uint *)((int)register0x00000038 + ((uVar2 & 4) - 0x18)) =
           *(uint *)((int)register0x00000038 + ((uVar2 & 4) - 0x18)) | 1 << bVar1;
    }
    else {
      if (*(char *)((int)register0x00000038 + -0x23) == '\x02') {
        uVar2 = *(uint *)((int)register0x00000038 + -0x34) >> 0x15;
        bVar1 = (byte)(*(uint *)((int)register0x00000038 + -0x34) >> 0x12) & 0x1f;
        goto loc_F00A1FDC;
      }
      iVar7 = (uint)(*(byte *)((int)register0x00000038 + -0x34) >> 5) * 4;
      *(uint *)((int)register0x00000038 + iVar7) =
           *(uint *)((int)register0x00000038 + iVar7) |
           1 << (*(byte *)((int)register0x00000038 + -0x34) & 0x1f);
    }
    iVar10 = iVar10 + 1;
    *(int *)((int)register0x00000038 + -0x34) = *(int *)((int)register0x00000038 + -0x34) + 0x1000;
    if (0x3f < iVar10) {
      _wmap0 = *(undefined4 *)((int)register0x00000038 + -0x20);
      _wmap1 = *(undefined4 *)((int)register0x00000038 + -0x1c);
      _mmap0 = *(undefined4 *)((int)register0x00000038 + -0x18);
      _mmap1 = *(undefined4 *)((int)register0x00000038 + -0x14);
      return CONCAT44(param_2,iVar10);
    }
  } while( true );
}
