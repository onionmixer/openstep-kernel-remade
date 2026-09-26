
void _obreak(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iStack_c;
  int iStack_8;
  
  uVar1 = ~_page_mask & _page_mask + **(int **)(dword_40B57D4 + 0x24);
  if (*(int *)(_active_u + 0x266) < (int)uVar1) {
    *(undefined *)(dword_40B57D4 + 100) = 0xc;
  }
  else {
    iVar3 = *(int *)(*(int *)(_active_threads + 0xc) + 8);
    _lock_write(iVar3);
    *(int *)(iVar3 + 0x40) = *(int *)(iVar3 + 0x40) + 1;
    iVar2 = _vm_map_lookup_entry(iVar3,uVar1,&iStack_8);
    if (iVar2 == 0) {
      iStack_c = *(int *)(iStack_8 + 0xc);
      _lock_done(iVar3);
      iVar3 = _vm_allocate(iVar3,&iStack_c,uVar1 - iStack_c,0);
      if (iVar3 != 0) {
        _uprintf(aCouldNotSbrkRe,iVar3);
      }
    }
    else {
      _lock_done(iVar3);
    }
  }
  return;
}
