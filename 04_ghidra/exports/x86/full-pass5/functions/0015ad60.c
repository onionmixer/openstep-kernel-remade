/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015ad60 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _newStack(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int local_8;
  
  iVar2 = _kmem_alloc_wired(_kernel_map,&local_8,DAT_001e5ba0);
  if (iVar2 == 0) {
    __stackStats = __stackStats + 1;
    *(undefined4 *)(local_8 + 8) = 2;
    _DAT_001f63b4 = _DAT_001f63b4 + 1;
    _stack_init(local_8 + 0xc);
    if (DAT_001e5ba4 < 2) {
      local_8 = local_8 + 0xc;
    }
    else {
      _lock_write(&_stack_queue_lock);
      iVar2 = 1;
      puVar1 = (undefined4 *)(local_8 + DAT_001e5ba0);
      if (1 < DAT_001e5ba4) {
        do {
          puVar3 = puVar1;
          _stack_init(puVar3 + 3);
          puVar3[2] = 0;
          puVar1 = puVar3;
          if ((undefined4 **)DAT_001e5b9c != &DAT_001e5b98) {
            *DAT_001e5b9c = puVar3;
            puVar1 = DAT_001e5b98;
          }
          DAT_001e5b98 = puVar1;
          puVar3[1] = DAT_001e5b9c;
          *puVar3 = &DAT_001e5b98;
          DAT_001ded68 = DAT_001ded68 + 1;
          _DAT_001f63b8 = _DAT_001f63b8 + 1;
          iVar2 = iVar2 + 1;
          puVar1 = (undefined4 *)((int)puVar3 + DAT_001e5ba0);
          DAT_001e5b9c = puVar3;
        } while (iVar2 < DAT_001e5ba4);
      }
      _lock_done(&_stack_queue_lock);
      local_8 = local_8 + 0xc;
    }
  }
  else {
    local_8 = 0;
  }
  return local_8;
}

