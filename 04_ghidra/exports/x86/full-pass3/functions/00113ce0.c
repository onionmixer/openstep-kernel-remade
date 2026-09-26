/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00113ce0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _m_expand(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined2 *puVar3;
  uint uVar4;
  
  bVar1 = false;
  do {
    iVar2 = _kmem_mb_alloc(_mb_map,_page_size + _page_mask & ~_page_mask);
    if (iVar2 != 0) {
      uVar4 = _page_size >> 7;
      if (uVar4 != 0) {
        puVar3 = (undefined2 *)(iVar2 + 10);
        do {
          *(undefined4 *)(puVar3 + -3) = 0;
          *puVar3 = 1;
          _DAT_001e917e = _DAT_001e917e + 1;
          __mbstat = __mbstat + 1;
          _m_free(iVar2);
          puVar3 = puVar3 + 0x40;
          iVar2 = iVar2 + 0x80;
          uVar4 = uVar4 - 1;
        } while (0 < (int)uVar4);
      }
      if (iVar2 != 0) {
        return 1;
      }
    }
    if ((param_1 == 0) || (iVar2 = _domains, bVar1)) {
      return 0;
    }
    for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x1c)) {
      uVar4 = *(uint *)(iVar2 + 0x14);
      if (uVar4 < *(uint *)(iVar2 + 0x18)) {
        do {
          if (*(code **)(uVar4 + 0x2c) != (code *)0x0) {
            (**(code **)(uVar4 + 0x2c))();
          }
          uVar4 = uVar4 + 0x30;
        } while (uVar4 < *(uint *)(iVar2 + 0x18));
      }
    }
    _DAT_001e9178 = _DAT_001e9178 + 1;
    bVar1 = true;
  } while( true );
}

