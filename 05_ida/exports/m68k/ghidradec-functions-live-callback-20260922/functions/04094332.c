
void _startup(uint param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined auStack_8 [4];
  
  iVar2 = _mon_global;
  _km_switch_to_vm();
  _panic_init();
  _printf(_version);
  _printf(aFpuVersion0xX,_fpu_version._0_1_);
  uVar5 = _mem_size + 0xfffff;
  uVar8 = uVar5 & 0xfff00000;
  iVar6 = (uVar8 + ((int)(sword)((sword)((int)uVar8 / 0x19999) + (sword)((int)uVar5 >> 0x1f)) -
                   ((int)uVar5 >> 0x1f)) * -0x19999) * 100;
  if (iVar6 < 0) {
    iVar6 = iVar6 + 0xfffff;
  }
  uVar5 = uVar8;
  if ((int)uVar8 < 0) {
    uVar5 = uVar8 + 0xfffff;
  }
  iVar7 = (uVar8 + ((int)uVar5 >> 0x14) * -0x100000) * 10;
  if (iVar7 < 0) {
    iVar7 = iVar7 + 0xfffff;
  }
  _printf(aPhysicalMemory,(int)uVar5 >> 0x14,iVar7 >> 0x14,iVar6 >> 0x14);
  param_1 = ~_page_mask & _page_mask + param_1;
  uVar3 = _vm_object_allocate(0,0,&param_1,0x800000,1);
  _vm_map_find(_kernel_map,uVar3);
  _vm_map_remove(_kernel_map,param_1,param_1 + 0x800000);
  _buffers = param_1;
  uVar8 = _bufpages % (int)_nbuf;
  iVar7 = _bufpages / (int)_nbuf;
  iVar6 = (~_page_mask & _page_mask + _nbuf * 0x2000 + param_1) - param_1;
  _buffer_map = _kmem_suballoc(_kernel_map,&param_1,auStack_8,iVar6,1);
  uVar3 = _vm_object_allocate(iVar6,0,&param_1,iVar6,0);
  _vm_map_find(_buffer_map,uVar3);
  uVar5 = 0;
  if (_nbuf != 0) {
    iVar6 = 0;
    do {
      iVar4 = iVar7;
      if (uVar5 < uVar8) {
        iVar4 = iVar7 + 1;
      }
      _vm_map_pageable(_buffer_map,iVar6 + _buffers,iVar6 + _buffers + iVar4 * _page_size,0);
      iVar6 = iVar6 + 0x2000;
      uVar5 = uVar5 + 1;
    } while (uVar5 < _nbuf);
  }
  iVar7 = _vm_page_free_count << (_page_shift & 0x3f);
  iVar6 = (iVar7 + ((int)(sword)((sword)(iVar7 / 0x19999) + (sword)(iVar7 >> 0x1f)) -
                   (iVar7 >> 0x1f)) * -0x19999) * 100;
  if (iVar6 < 0) {
    iVar6 = iVar6 + 0xfffff;
  }
  iVar4 = iVar7;
  if (iVar7 < 0) {
    iVar4 = iVar7 + 0xfffff;
  }
  iVar7 = (iVar7 + (iVar4 >> 0x14) * -0x100000) * 10;
  if (iVar7 < 0) {
    iVar7 = iVar7 + 0xfffff;
  }
  _printf(aAvailableMemor,iVar4 >> 0x14,iVar7 >> 0x14,iVar6 >> 0x14);
  iVar7 = _bufpages << (_page_shift & 0x3f);
  iVar6 = (iVar7 + ((int)(sword)((sword)(iVar7 / 0x19999) + (sword)(iVar7 >> 0x1f)) -
                   (iVar7 >> 0x1f)) * -0x19999) * 100;
  if (iVar6 < 0) {
    iVar6 = iVar6 + 0xfffff;
  }
  iVar4 = iVar7;
  if (iVar7 < 0) {
    iVar4 = iVar7 + 0xfffff;
  }
  iVar7 = (iVar7 + (iVar4 >> 0x14) * -0x100000) * 10;
  if (iVar7 < 0) {
    iVar7 = iVar7 + 0xfffff;
  }
  _printf(aUsingDBuffersC,_nbuf,iVar4 >> 0x14,iVar7 >> 0x14,iVar6 >> 0x14);
  _ns_callout_init();
  uVar8 = _nsoftint;
  _softint_free = _softint;
  uVar5 = 1;
  piVar1 = _softint;
  if (1 < _nsoftint) {
    do {
      *piVar1 = (int)(piVar1 + 3);
      uVar5 = uVar5 + 1;
      piVar1 = piVar1 + 3;
    } while (uVar5 < uVar8);
  }
  _softint[_nsoftint * 3 + -3] = 0;
  _mb_map = _kmem_suballoc(_kernel_map,&_mbutl,_embutl,_nmbclusters << 10,0);
  if (((((unk_40B6904 & 8) == 0) && (_console_o == 0)) && (0x17 < *(sword *)(iVar2 + 0x30c))) &&
     (iVar6 = *(int *)(iVar2 + 0x30e), iVar6 != 0)) {
    _callout_dispatch(2,iVar6,0);
  }
  if (_bmap_chip != 0) {
    if (_astune_rate == 0) {
      _astune_rate = 1;
    }
    _timeout(_as_tune,0,_hz * _astune_rate);
  }
  if (_dma_chip != 0x139) {
    _adb_initialize();
  }
  _configure();
  return;
}

