
void _vno_flush(int *param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  iVar1 = *(int *)(*param_1 + 0x20);
  if (iVar1 == 0) {
    return;
  }
  uVar2 = _page_mask + param_2 + param_3;
  uVar3 = ~_page_mask;
  param_2 = uVar3 & param_2;
  do {
    while( true ) {
      if ((uVar3 & uVar2) <= param_2) {
        return;
      }
      iVar4 = _vm_page_lookup(iVar1,param_2);
      if (iVar4 != 0) break;
loc_404DC76:
      param_2 = _page_size + param_2;
    }
    if (-1 < (char)*(byte *)(iVar4 + 0x20)) {
      _vm_page_free(iVar4);
      goto loc_404DC76;
    }
    *(byte *)(iVar4 + 0x20) = *(byte *)(iVar4 + 0x20) | 0x40;
    _assert_wait(iVar4,0);
    _thread_block();
  } while( true );
}
