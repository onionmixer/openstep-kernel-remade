
void _cache_flush(uint param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (_dma_chip == 0x139) {
    param_1 = param_1 & 0x3fffffff;
    param_2 = param_2 & 0x3fffffff;
  }
  while( true ) {
    if (param_2 <= param_1) {
      return;
    }
    iVar3 = _m68k_page_size - (_m68k_page_mask & param_1);
    if (param_2 < iVar3 + param_1) {
      iVar3 = param_2 - param_1;
    }
    uVar1 = _pmap_kernel(param_1);
    iVar2 = _pmap_resident_extract(uVar1);
    if (iVar2 == 0) break;
    if (param_3 == 0) {
      _cache_push_page(iVar2);
    }
    else {
      _cache_inval_page(iVar2);
      if (_ncc_chip != 0) {
        _nitro_cache_flush(iVar2,iVar3);
      }
    }
    param_1 = iVar3 + param_1;
  }
                    /* WARNING: Subroutine does not return */
  _panic(aCacheFlushPage);
}

