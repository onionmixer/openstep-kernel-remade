
/* WARNING: Removing unreachable block (ram,0xf0088c04) */
/* WARNING: Removing unreachable block (ram,0xf0088b88) */
/* WARNING: Removing unreachable block (ram,0xf0088b64) */
/* WARNING: Removing unreachable block (ram,0xf0088b40) */
/* WARNING: Removing unreachable block (ram,0xf0088adc) */
/* WARNING: Removing unreachable block (ram,0xf0088af0) */
/* WARNING: Removing unreachable block (ram,0xf0088b50) */
/* WARNING: Removing unreachable block (ram,0xf0088b74) */
/* WARNING: Removing unreachable block (ram,0xf0088b98) */
/* WARNING: Removing unreachable block (ram,0xf0088c40) */
/* WARNING: Removing unreachable block (ram,0xf0088acc) */

undefined8 _vm_page_startup(int *param_1,int param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  int *piVar9;
  uint *puVar10;
  undefined4 *puVar11;
  uint uVar12;
  uint uVar13;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar14;
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
  uRamf013d964 = 0;
  uRamf013d968 = 0;
  uRamf013d96c = (uint)uRamf013d96c._2_2_;
  uRamf013d974 = 0;
  uRamf013d978 = 0;
  uRamf013d97c = 0;
  uVar2 = 0;
  uRamf013d970 = uRamf013d970 & 0x8047ffff | 0x80000000;
  uRamf013d96c = uRamf013d96c & 0xffff07ff | 0x400;
  _vm_page_queue_free_lock = 0;
  _vm_page_queue_lock = 0;
  dword_F013CC14 = &_vm_page_queue_free;
  _vm_page_queue_free = &_vm_page_queue_free;
  dword_F013CC0C = &_vm_page_queue_active;
  _vm_page_queue_active = &_vm_page_queue_active;
  dword_F013C22C = &_vm_page_queue_inactive;
  _vm_page_queue_inactive = &_vm_page_queue_inactive;
  if (param_1 < param_1 + param_2 * 7) {
    piVar9 = param_1 + 5;
    piVar14 = param_1;
    do {
      piVar14 = piVar14 + 7;
      uVar2 = uVar2 + ((piVar9[1] & ~_page_mask) - (*piVar9 + _page_mask & ~_page_mask));
      piVar9 = piVar9 + 7;
    } while (piVar14 < param_1 + param_2 * 7);
  }
  if (_vm_page_bucket_count == 0) {
    uVar2 = uVar2 >> ((byte)_page_shift & 0x1f);
    _vm_page_bucket_count = 1;
    if (1 < uVar2) {
      do {
        _vm_page_bucket_count = _vm_page_bucket_count << 1;
      } while (_vm_page_bucket_count < uVar2);
    }
  }
  _vm_page_hash_mask = _vm_page_bucket_count - 1;
  if ((_vm_page_hash_mask & _vm_page_bucket_count) != 0) {
    _printf(aVmPageBootstra);
  }
  iVar4 = _vm_page_bucket_count << 3;
  _vm_alloc_from_regions(iVar4,4);
  _vm_page_buckets = iVar4;
  _bzero();
  iVar4 = _vm_page_buckets;
  uVar2 = _vm_page_bucket_count;
  uVar12 = 0;
  iVar7 = _vm_page_buckets;
  if (_vm_page_bucket_count != 0) {
    do {
      *(undefined4 *)(iVar7 + 4) = 0;
      *(undefined4 *)(iVar4 + uVar12 * 8) = 0;
      uVar12 = uVar12 + 1;
      iVar7 = iVar7 + 8;
    } while (uVar12 < uVar2);
  }
  iVar4 = _page_size << 3;
  _zdata_size = iVar4;
  _vm_alloc_from_regions();
  _zdata = iVar4;
  _bzero();
  uVar5 = 800;
  _map_data_size = 800;
  _vm_alloc_from_regions(800,4);
  _map_data = uVar5;
  _bzero();
  uVar5 = 0x16000;
  _kentry_data_size = 0x16000;
  _vm_alloc_from_regions(0x16000,4);
  _kentry_data = uVar5;
  _bzero();
  if (param_1 < param_1 + param_2 * 7) {
    piVar9 = param_1 + 5;
    piVar14 = param_1;
    do {
      iVar4 = ((piVar9[1] & ~_page_mask) - (*piVar9 + _page_mask & ~_page_mask) >>
              ((byte)_page_shift & 0x1f)) * 0x30;
      _vm_alloc_from_regions(iVar4,4);
      *piVar14 = iVar4;
      _bzero();
      piVar14 = piVar14 + 7;
      piVar9 = piVar9 + 7;
    } while (piVar14 < param_1 + param_2 * 7);
  }
  uVar5 = _page_shift;
  uVar2 = _page_mask;
  _vm_page_free_count = 0;
  if (param_1 < param_1 + param_2 * 7) {
    puVar10 = (uint *)(param_1 + 3);
    uVar12 = ~_page_mask;
    piVar14 = param_1;
    do {
      uVar13 = 0;
      puVar10[2] = puVar10[2] + uVar2 & uVar12;
      uVar3 = puVar10[2];
      puVar10[3] = puVar10[3] & uVar12;
      puVar10[-2] = puVar10[2] >> ((byte)uVar5 & 0x1f);
      uVar6 = puVar10[3] >> ((byte)uVar5 & 0x1f);
      puVar10[-1] = uVar6;
      uVar6 = uVar6 - puVar10[-2];
      *puVar10 = uVar6;
      iVar4 = _page_size;
      puVar11 = (undefined4 *)*piVar14;
      _vm_page_free_count = _vm_page_free_count + uVar6;
      if (*puVar10 != 0) {
        puVar8 = puVar11 + 7;
        do {
          puVar8[2] = uVar3;
          puVar1 = puVar11;
          if ((undefined4 **)dword_F013CC14 != &_vm_page_queue_free) {
            *dword_F013CC14 = puVar11;
            puVar1 = _vm_page_queue_free;
          }
          _vm_page_queue_free = puVar1;
          puVar8[-6] = (uint)dword_F013CC14;
          *puVar11 = &_vm_page_queue_free;
          dword_F013CC14 = puVar11;
          *puVar8 = *puVar8 | 0x1000;
          puVar8 = puVar8 + 0xc;
          puVar11 = puVar11 + 0xc;
          uVar13 = uVar13 + 1;
          uVar3 = uVar3 + iVar4;
        } while (uVar13 < *puVar10);
      }
      piVar14 = piVar14 + 7;
      puVar10 = puVar10 + 7;
    } while (piVar14 < param_1 + param_2 * 7);
  }
  _vm_pages_needed_lock = 0;
  return CONCAT44(param_2,_virtual_avail + _page_mask & ~_page_mask);
}
