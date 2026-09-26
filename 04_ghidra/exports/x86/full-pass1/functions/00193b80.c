/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00193b80 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _startup(uint param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  mach_port_t unaff_EBX;
  int iVar5;
  uint uVar6;
  undefined1 local_8 [4];
  
  _cons_tp = &_cons;
  _DAT_001e9808 = 0xc00;
  _kminit();
  _panic_init(unaff_EBX);
  _printf(_version);
  _printf(s_physical_memory____d__d_d_megaby_001e28ac,_mem_size >> 0x14,
          (_mem_size & 0xfffff) * 10 >> 0x14,(_mem_size % 0x19999) * 0x19 >> 0x12);
  param_1 = _page_mask + param_1 & ~_page_mask;
  uVar1 = _vm_object_allocate(0,0,&param_1,0x800000,1);
  _vm_map_find(_kernel_map,uVar1);
  _vm_map_remove(_kernel_map,param_1,param_1 + 0x800000);
  _buffers = param_1;
  iVar2 = _bufpages / (int)_nbuf;
  uVar4 = _bufpages % (int)_nbuf;
  iVar5 = (param_1 + _nbuf * 0x2000 + _page_mask & ~_page_mask) - param_1;
  _buffer_map = _kmem_suballoc(_kernel_map,&param_1,local_8,iVar5,1);
  uVar1 = _vm_object_allocate(iVar5,0,&param_1,iVar5,0);
  _vm_map_find(_buffer_map,uVar1);
  uVar6 = 0;
  if (_nbuf != 0) {
    iVar5 = 0;
    do {
      iVar3 = iVar2;
      if (uVar6 < uVar4) {
        iVar3 = iVar2 + 1;
      }
      _vm_map_pageable(_buffer_map,_buffers + iVar5,iVar3 * _page_size + _buffers + iVar5,0);
      iVar5 = iVar5 + 0x2000;
      uVar6 = uVar6 + 1;
    } while (uVar6 < _nbuf);
  }
  iVar5 = _bufpages << ((byte)_page_shift & 0x1f);
  iVar2 = (iVar5 % 0x19999) * 100;
  if (iVar2 < 0) {
    iVar2 = iVar2 + 0xfffff;
  }
  iVar3 = iVar5;
  if (iVar5 < 0) {
    iVar3 = iVar5 + 0xfffff;
  }
  iVar5 = (iVar5 + (iVar3 >> 0x14) * -0x100000) * 10;
  if (iVar5 < 0) {
    iVar5 = iVar5 + 0xfffff;
  }
  _printf(s_using__d_buffers_containing__d___001e28d2,_nbuf,iVar3 >> 0x14,iVar5 >> 0x14,
          iVar2 >> 0x14);
  iVar5 = _vm_page_free_count << ((byte)_page_shift & 0x1f);
  iVar2 = (iVar5 % 0x19999) * 100;
  if (iVar2 < 0) {
    iVar2 = iVar2 + 0xfffff;
  }
  iVar3 = iVar5;
  if (iVar5 < 0) {
    iVar3 = iVar5 + 0xfffff;
  }
  iVar5 = (iVar5 + (iVar3 >> 0x14) * -0x100000) * 10;
  if (iVar5 < 0) {
    iVar5 = iVar5 + 0xfffff;
  }
  _printf(s_available_memory____d__d_d_megab_001e290b,iVar3 >> 0x14,iVar5 >> 0x14,iVar2 >> 0x14,
          _vm_page_free_count);
  _mb_map = _kmem_suballoc(_kernel_map,&_mbutl,&_embutl,_nmbclusters << 10,0);
  return;
}

