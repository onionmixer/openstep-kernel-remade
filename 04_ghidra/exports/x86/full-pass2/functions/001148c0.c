/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001148c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool _mclget(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  
  uVar1 = _splimp();
  if (_mclfree == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)_kmem_mb_alloc(_mb_map,_page_size + _page_mask & ~_page_mask);
    if (puVar2 != (undefined4 *)0x0) {
      uVar4 = _page_size >> 10;
      iVar5 = 0;
      if (uVar4 != 0) {
        do {
          puVar3 = puVar2;
          puVar3[1] = 0;
          *puVar3 = _mclfree;
          _DAT_001e916c = _DAT_001e916c + 1;
          iVar5 = iVar5 + 1;
          puVar2 = puVar3 + 0x100;
          _mclfree = puVar3;
        } while (iVar5 < (int)uVar4);
      }
      _DAT_001e9164 = _DAT_001e9164 + uVar4;
    }
  }
  puVar2 = _mclfree;
  if (_mclfree != (undefined4 *)0x0) {
    (&_mclrefcnt)[(int)_mclfree - __mbutl >> 10] =
         (&_mclrefcnt)[(int)_mclfree - __mbutl >> 10] + '\x01';
    _DAT_001e916c = _DAT_001e916c + -1;
    _mclfree = (undefined4 *)*_mclfree;
    *(undefined2 *)(param_1 + 8) = 0x400;
    *(int *)(param_1 + 4) = (int)puVar2 - param_1;
    *(undefined2 *)(param_1 + 0xc) = 1;
  }
  _splx(uVar1);
  return puVar2 != (undefined4 *)0x0;
}

