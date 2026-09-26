/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015abe0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _freeStack(int param_1)

{
  undefined4 *puVar1;
  bool bVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  
  _DAT_001f63b4 = _DAT_001f63b4 + -1;
  puVar7 = (undefined4 *)(param_1 + -0xc);
  _lock_write(&_stack_queue_lock);
  *(undefined4 *)(param_1 + -4) = 0;
  puVar5 = puVar7;
  if ((undefined4 **)DAT_001e5b9c != &DAT_001e5b98) {
    *DAT_001e5b9c = puVar7;
    puVar5 = DAT_001e5b98;
  }
  DAT_001e5b98 = puVar5;
  *(undefined4 **)(param_1 + -8) = DAT_001e5b9c;
  *puVar7 = &DAT_001e5b98;
  DAT_001ded68 = DAT_001ded68 + 1;
  _DAT_001f63b8 = _DAT_001f63b8 + 1;
  DAT_001e5b9c = puVar7;
  _lock_done(&_stack_queue_lock);
  if (DAT_001ded70 != 0) {
    DAT_001ded70 = 0;
    _thread_wakeup_prim(&DAT_001e5b98,0,0);
  }
  if (DAT_001ded6c < DAT_001ded68) {
    puVar4 = (undefined4 *)((uint)puVar7 & ~_page_mask);
    bVar2 = true;
    iVar6 = 0;
    puVar5 = puVar4;
    if (0 < DAT_001e5ba4) {
      do {
        if (puVar5[2] != 0) {
          bVar2 = false;
        }
        iVar6 = iVar6 + 1;
        puVar5 = (undefined4 *)((int)puVar5 + DAT_001e5ba0);
      } while (iVar6 < DAT_001e5ba4);
    }
    if (bVar2) {
      iVar6 = 0;
      if (0 < DAT_001e5ba4) {
        do {
          puVar5 = (undefined4 *)*puVar4;
          puVar1 = (undefined4 *)puVar4[1];
          puVar3 = puVar1;
          if ((undefined4 **)puVar5 != &DAT_001e5b98) {
            puVar5[1] = puVar1;
            puVar3 = DAT_001e5b9c;
          }
          DAT_001e5b9c = puVar3;
          if ((undefined4 **)puVar1 != &DAT_001e5b98) {
            *puVar1 = puVar5;
            puVar5 = DAT_001e5b98;
          }
          DAT_001e5b98 = puVar5;
          DAT_001ded68 = DAT_001ded68 + -1;
          _DAT_001f63b8 = _DAT_001f63b8 + -1;
          _stack_finalize(puVar4 + 3);
          puVar4 = (undefined4 *)((int)puVar4 + DAT_001e5ba0);
          iVar6 = iVar6 + 1;
        } while (iVar6 < DAT_001e5ba4);
      }
      _kmem_free(_kernel_map,puVar7,DAT_001e5ba0);
      __stackStats = __stackStats + -1;
    }
    else {
      iVar6 = _canSwap(puVar7);
      if (iVar6 != 0) {
        _doSwapout(puVar7);
      }
    }
  }
  return;
}

