
undefined4 * _m_clalloc(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  puVar1 = (undefined4 *)
           _kmem_mb_alloc(_mb_map,~_page_mask & _page_mask + _m68k_page_size * param_1);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else if (param_2 == 1) {
    param_1 = _m68k_page_size * param_1;
    if (param_1 < 0) {
      param_1 = param_1 + 0x3ff;
    }
    param_1 = param_1 >> 10;
    iVar2 = 0;
    if (0 < param_1) {
      do {
        puVar4 = puVar1;
        puVar4[1] = 0;
        *puVar4 = _mclfree;
        puVar1 = puVar4 + 0x100;
        dword_40B61BC = dword_40B61BC + 1;
        iVar2 = iVar2 + 1;
        _mclfree = puVar4;
      } while (iVar2 < param_1);
    }
    dword_40B61B4 = param_1 + dword_40B61B4;
  }
  else if (param_2 < 2) {
    if ((param_2 == 0) && (uVar3 = (uint)(_m68k_page_size * param_1) >> 7, uVar3 != 0)) {
      do {
        puVar1[1] = 0;
        *(undefined2 *)((int)puVar1 + 10) = 1;
        word_40B61CE = word_40B61CE + 1;
        _mbstat = _mbstat + 1;
        _m_free(puVar1);
        puVar1 = puVar1 + 0x20;
        uVar3 = uVar3 - 1;
      } while (0 < (int)uVar3);
    }
  }
  else if (param_2 == 2) {
    dword_40B61B8 = param_1 + dword_40B61B8;
  }
  return puVar1;
}

