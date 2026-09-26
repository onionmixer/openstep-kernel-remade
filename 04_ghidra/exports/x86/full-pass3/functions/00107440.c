/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00107440 */

void _pqinit(void)

{
  void *pvVar1;
  
  _proc_zone = _zinit(0x88,_max_proc * 0x3520,0,0,s_proc_structures_001da8a6);
  DAT_001e56c0 = 0;
  _freeproc = 0;
  if (_max_proc < 1) {
    pvVar1 = (void *)0x0;
  }
  else {
    DAT_001e56c0 = 1;
    pvVar1 = (void *)_zalloc(_proc_zone);
  }
  _bzero(pvVar1,0x88);
  _allproc = pvVar1;
  *(undefined4 *)((int)pvVar1 + 8) = 0;
  *(void ***)((int)pvVar1 + 0xc) = &_allproc;
  _kernel_proc = pvVar1;
  _zombproc = 0;
  return;
}

