/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00191144 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _pmap_update(void)

{
  byte bVar1;
  undefined4 *puVar2;
  int iVar3;
  byte bVar4;
  int *piVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  int *piVar9;
  undefined4 *puVar10;
  byte *pbVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  int in_FS_OFFSET;
  char local_c;
  
  if (DAT_001e773c == 0) {
    DAT_001e773c = _sched_tick;
  }
  iVar12 = _sched_tick - DAT_001e773c;
  if (1 < iVar12) {
    while( true ) {
      if ((int **)_pt_free_queue == &_pt_free_queue) {
        piVar5 = (int *)0x0;
        piVar9 = _pt_free_queue;
      }
      else {
        *(int ***)(*_pt_free_queue + 4) = &_pt_free_queue;
        piVar5 = _pt_free_queue;
        piVar9 = (int *)*_pt_free_queue;
        if (_pt_free_queue != (int *)0x0) {
          __pt_free_count = __pt_free_count + -1;
        }
      }
      _pt_free_queue = piVar9;
      piVar9 = _pd_free_queue;
      if (piVar5 == (int *)0x0) break;
      uVar7 = *(undefined4 *)(piVar5[2] + 8);
      *(undefined4 *)(piVar5[2] + 0xc) = 0;
      _zfree(_pg_exten_zone,piVar5);
      _kmem_free(_kernel_map,uVar7,_page_size);
      __pt_alloc_count = __pt_alloc_count + -1;
    }
    while ((int **)piVar9 != &_pd_free_queue) {
      if ((short)piVar9[6] == 0) {
        *(int *)(*piVar9 + 4) = piVar9[1];
        *(int *)piVar9[1] = *piVar9;
        __pd_free_count = __pd_free_count + -1;
        uVar7 = *(undefined4 *)(piVar9[2] + 8);
        *(undefined4 *)(piVar9[2] + 0xc) = 0;
        _zfree(_pg_exten_zone,piVar9);
        _kmem_free(_kernel_map,uVar7,_page_size);
        __pd_alloc_count = __pd_alloc_count + -1;
        piVar9 = _pd_free_queue;
      }
      else {
        piVar9 = (int *)*piVar9;
      }
    }
  }
  puVar2 = _pt_active_queue;
  if (DAT_001e2614 + -1 < iVar12 >> 3) {
    uVar6 = *(uint *)(s_pmap_deallocate_mappings_001e25e5 + DAT_001e2614 * 4 + 0x17);
  }
  else {
    uVar6 = *(uint *)(&DAT_001e2600 + (iVar12 >> 3) * 4);
  }
LAB_00191293:
  while( true ) {
    while( true ) {
      puVar10 = puVar2;
      if ((undefined4 **)puVar10 == &_pt_active_queue) {
        DAT_001e773c = DAT_001e773c + iVar12;
        return;
      }
      pbVar11 = (byte *)(*(int *)puVar10[4] + ((uint)puVar10[5] >> 0x16) * 4);
      if ((*(short *)((int)puVar10 + 0x1a) == 0) && (bVar1 = *pbVar11, (bVar1 & 1) != 0)) break;
      *(undefined1 *)((int)puVar10 + 0x1d) = 0;
      puVar2 = (undefined4 *)*puVar10;
    }
    puVar2 = (undefined4 *)*puVar10;
    if (iVar12 < 1) goto LAB_001913b8;
    if ((bVar1 & 0x20) != 0) break;
    bVar1 = *(byte *)((int)puVar10 + 0x1d);
    local_c = (char)iVar12;
    bVar4 = local_c + bVar1;
    *(byte *)((int)puVar10 + 0x1d) = bVar4;
    if ((bVar4 < bVar1) || (uVar6 < bVar4)) {
      iVar3 = puVar10[4];
      uVar13 = puVar10[5];
      uVar14 = uVar13 + _section_size;
      if (iVar3 != 0) {
        uVar7 = _splvm();
        if (((iVar3 == _kernel_pmap) || (*(int *)(iVar3 + 0x18) != 0)) &&
           (__tlb_stat = __tlb_stat + 1, uVar8 = uVar13, uVar14 - uVar13 <= _page_size)) {
          for (; uVar8 < uVar14; uVar8 = uVar8 + 0x1000) {
            if (iVar3 == _kernel_pmap) {
              invlpg(uVar8);
            }
            else {
              invlpg(in_FS_OFFSET + uVar8);
            }
          }
          _DAT_001f7af4 = _DAT_001f7af4 + 1;
        }
        while (uVar13 < uVar14) {
          uVar8 = -_section_size & _section_size + -1 + uVar13 + _page_size;
          if (uVar14 < uVar8) {
            uVar8 = uVar14;
          }
          FUN_0018f7f8(iVar3,uVar13,uVar8,1);
          uVar13 = uVar8;
        }
        _splx(uVar7);
      }
    }
  }
  goto LAB_001913bc;
LAB_001913b8:
  if ((bVar1 & 0x20) != 0) {
LAB_001913bc:
    *pbVar11 = *pbVar11 & 0xdf;
    *(undefined1 *)((int)puVar10 + 0x1d) = 0;
  }
  goto LAB_00191293;
}

