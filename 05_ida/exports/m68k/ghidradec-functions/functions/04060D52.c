
void _vm_set_page_size(void)

{
  int iVar1;
  uint uVar2;
  
  _page_mask = _page_size - 1;
  if ((_page_size & _page_mask) == 0) {
    _page_shift = 0;
    if (_page_size != 1) {
      do {
        iVar1 = _page_shift + 1;
        uVar2 = _page_shift + 1;
        _page_shift = iVar1;
      } while (_page_size != 1 << (uVar2 & 0x3f));
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  _panic(aVmSetPageSizeP);
}
