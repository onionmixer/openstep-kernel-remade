/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010890c */

int _setrlimit(int param_1,rlimit *param_2)

{
  int *piVar1;
  uint *puVar2;
  int in_EAX;
  uint uVar3;
  int iVar4;
  uint local_10;
  int local_c;
  int local_8;
  
  puVar2 = *(uint **)(DAT_001e875c + 0x24);
  if (*puVar2 < 6) {
    piVar1 = _active_u + *puVar2 * 2 + 0x99;
    in_EAX = _copyin(puVar2[1],&local_c,8);
    *(char *)(DAT_001e875c + 0x68) = (char)in_EAX;
    if (*(char *)(DAT_001e875c + 0x68) == '\0') {
      if (((piVar1[1] < local_c) || (piVar1[1] < local_8)) && (in_EAX = _suser(), in_EAX == 0)) {
        return 0;
      }
      if (*puVar2 == 3) {
        if (*piVar1 < local_c) {
          uVar3 = ~_page_mask;
          local_10 = *(int *)(*_active_u + 0x84) - local_c & uVar3;
          iVar4 = _vm_allocate(*(vm_map_t *)(*(int *)(_active_threads + 0xc) + 0xc),&local_10,
                               (local_c + _page_mask & uVar3) - (_page_mask + *piVar1 & uVar3),0);
        }
        else {
          uVar3 = ~_page_mask;
          local_10 = *(int *)(*_active_u + 0x84) - *piVar1 & uVar3;
          iVar4 = _vm_deallocate(*(vm_map_t *)(*(int *)(_active_threads + 0xc) + 0xc),local_10,
                                 (*piVar1 + _page_mask & uVar3) - (_page_mask + local_c & uVar3));
        }
        in_EAX = 0;
        if (iVar4 != 0) {
          *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
          return iVar4;
        }
      }
      *piVar1 = local_c;
      piVar1[1] = local_8;
    }
  }
  else {
    *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
  }
  return in_EAX;
}

