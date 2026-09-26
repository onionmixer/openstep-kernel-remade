/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00113bd0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * _m_clalloc(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  undefined2 *puVar4;
  undefined4 *puVar5;
  
  puVar1 = (undefined4 *)_kmem_mb_alloc(_mb_map,param_1 * _page_size + _page_mask & ~_page_mask);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else if (param_2 == 1) {
    uVar3 = (uint)(param_1 * _page_size) >> 10;
    iVar2 = 0;
    if (uVar3 != 0) {
      do {
        puVar5 = puVar1;
        puVar5[1] = 0;
        *puVar5 = _mclfree;
        puVar1 = puVar5 + 0x100;
        _DAT_001e916c = _DAT_001e916c + 1;
        iVar2 = iVar2 + 1;
        _mclfree = puVar5;
      } while (iVar2 < (int)uVar3);
    }
    _DAT_001e9164 = _DAT_001e9164 + uVar3;
  }
  else if (param_2 < 2) {
    if ((param_2 == 0) && (uVar3 = (uint)(param_1 * _page_size) >> 7, uVar3 != 0)) {
      puVar4 = (undefined2 *)((int)puVar1 + 10);
      do {
        *(undefined4 *)(puVar4 + -3) = 0;
        *puVar4 = 1;
        _DAT_001e917e = _DAT_001e917e + 1;
        __mbstat = __mbstat + 1;
        _m_free(puVar1);
        puVar4 = puVar4 + 0x40;
        puVar1 = puVar1 + 0x20;
        uVar3 = uVar3 - 1;
      } while (0 < (int)uVar3);
    }
  }
  else if (param_2 == 2) {
    _DAT_001e9168 = _DAT_001e9168 + param_1;
  }
  return puVar1;
}

