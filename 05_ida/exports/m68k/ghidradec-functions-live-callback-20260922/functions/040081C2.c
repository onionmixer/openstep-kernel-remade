
void _setrlimit(void)

{
  uint *puVar1;
  uint uVar2;
  undefined uVar4;
  int iVar3;
  int *piVar5;
  uint uStack_10;
  int iStack_c;
  int iStack_8;
  
  puVar1 = *(uint **)(dword_40B57D4 + 0x24);
  if (*puVar1 < 6) {
    piVar5 = (int *)(*puVar1 * 8 + 0x256 + (int)_active_u);
    uVar4 = _copyinmsg(puVar1[1],&iStack_c,8);
    *(undefined *)(dword_40B57D4 + 100) = uVar4;
    if (*(char *)(dword_40B57D4 + 100) == '\0') {
      if (((piVar5[1] < iStack_c) || (piVar5[1] < iStack_8)) && (iVar3 = _suser(), iVar3 == 0)) {
        return;
      }
      if (*puVar1 == 3) {
        if (*piVar5 < iStack_c) {
          uVar2 = ~_page_mask;
          uStack_10 = uVar2 & *(int *)(*_active_u + 0x82) - iStack_c;
          iVar3 = _vm_allocate(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 8),&uStack_10,
                               (uVar2 & _page_mask + iStack_c) - (uVar2 & *piVar5 + _page_mask),0);
        }
        else {
          uVar2 = ~_page_mask;
          uStack_10 = uVar2 & *(int *)(*_active_u + 0x82) - *piVar5;
          iVar3 = _vm_deallocate(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 8),uStack_10,
                                 (uVar2 & _page_mask + *piVar5) - (uVar2 & iStack_c + _page_mask));
        }
        if (iVar3 != 0) {
          *(undefined *)(dword_40B57D4 + 100) = 0x16;
          return;
        }
      }
      *piVar5 = iStack_c;
      piVar5[1] = iStack_8;
    }
  }
  else {
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
  }
  return;
}

