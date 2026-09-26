/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017cc30 */

undefined4 * _pagerfile_pager_create(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  
  puVar2 = (undefined4 *)_zalloc_noblock(_vstruct_zone);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    uVar3 = (param_2 + _page_mask & ~_page_mask) >> ((byte)_page_shift & 0x1f);
    puVar2[4] = uVar3;
    if (uVar3 == 0) {
      puVar2[2] = 0;
    }
    else {
      uVar6 = uVar3 * 4;
      if (0x40 < uVar6) {
        uVar6 = (uVar3 - 1 >> 4) * 4 + 4;
      }
      uVar4 = _kalloc_noblock(uVar6);
      puVar2[2] = uVar4;
      if ((void *)puVar2[2] == (void *)0x0) {
        _zfree(_vstruct_zone,puVar2);
        return (undefined4 *)0x0;
      }
      iVar1 = puVar2[4];
      if ((uint)(iVar1 * 4) < 0x41) {
        iVar5 = 0;
        if (0 < iVar1) {
          do {
            *(undefined1 *)(puVar2[2] + iVar5 * 4) = 0;
            iVar5 = iVar5 + 1;
          } while (iVar5 < (int)puVar2[4]);
        }
      }
      else {
        _bzero((void *)puVar2[2],(iVar1 - 1U >> 4) * 4 + 4);
      }
    }
    *puVar2 = 0;
    *(undefined2 *)((int)puVar2 + 0xe) = 1;
    puVar2[5] = *(undefined4 *)(param_1 + 8);
    *(byte *)(puVar2 + 3) = *(byte *)(puVar2 + 3) | 1;
    puVar2[1] = param_1;
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
    do {
    } while (_vstruct_lock != 0);
    LOCK();
    UNLOCK();
    *(short *)((int)puVar2 + 0xe) = *(short *)((int)puVar2 + 0xe) + -1;
    LOCK();
    _vstruct_lock = 0;
    UNLOCK();
  }
  return puVar2;
}

