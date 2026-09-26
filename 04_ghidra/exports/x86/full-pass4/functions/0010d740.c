/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010d740 */

undefined4 _selthreadcache(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = _splhigh();
  iVar1 = *param_1;
  if (iVar1 == 0) {
    _splx(uVar2);
  }
  else {
    if ((*(int *)(iVar1 + 0x178) != 0) && (*(undefined **)(iVar1 + 0x3c) == &_selwait)) {
      _splx(uVar2);
      return 1;
    }
    *param_1 = 0;
    _splx(uVar2);
    _thread_deallocate(iVar1);
  }
  iVar1 = _active_threads;
  _thread_reference(_active_threads);
  *param_1 = iVar1;
  return 0;
}

