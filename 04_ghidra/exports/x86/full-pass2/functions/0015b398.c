/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015b398 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _stack_alloc_try(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  _lock_write(&_stack_queue_lock);
  if (DAT_001ded68 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    if ((int **)DAT_001e5b98 == &DAT_001e5b98) {
      piVar2 = (int *)0x0;
    }
    else {
      *(int ***)(*DAT_001e5b98 + 4) = &DAT_001e5b98;
      piVar2 = DAT_001e5b98;
      DAT_001e5b98 = (int *)*DAT_001e5b98;
    }
    piVar2[2] = 2;
    piVar2 = piVar2 + 3;
    DAT_001ded68 = DAT_001ded68 + -1;
    _DAT_001f63b8 = _DAT_001f63b8 + -1;
    _DAT_001f63b4 = _DAT_001f63b4 + 1;
  }
  _lock_done(&_stack_queue_lock);
  if ((piVar2 == (int *)0x0) && (piVar2 = *(int **)(param_1 + 0x30), piVar2 == (int *)0x0)) {
    uVar1 = 0;
  }
  else {
    _stack_attach(param_1,piVar2,param_2);
    uVar1 = 1;
  }
  return uVar1;
}

