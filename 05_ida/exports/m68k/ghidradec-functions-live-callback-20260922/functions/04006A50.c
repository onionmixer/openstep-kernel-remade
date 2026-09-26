
uint _munmap(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = **(uint **)(dword_40B57D4 + 0x24);
  uVar2 = (*(uint **)(dword_40B57D4 + 0x24))[1];
  uVar3 = _page_mask & uVar1;
  if ((uVar3 == 0) && (uVar3 = _page_mask & uVar2, uVar3 == 0)) {
    uVar3 = _vm_deallocate(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 8),uVar1,uVar2);
    if (uVar3 != 0) {
      *(undefined *)(dword_40B57D4 + 100) = 0x16;
    }
  }
  else {
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
  }
  return uVar3;
}

