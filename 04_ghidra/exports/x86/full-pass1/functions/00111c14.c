/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00111c14 */

undefined * _pty_alloc(byte param_1)

{
  int iVar1;
  void *pvVar2;
  
  iVar1 = (uint)param_1 * 0x10;
  if (*(int *)(&DAT_001e56d0 + iVar1) == 0) {
    _lock_write(&_pty_alloc_lock);
    if (*(int *)(&DAT_001e56d0 + iVar1) == 0) {
      pvVar2 = (void *)_kalloc(0x88);
      *(void **)(&DAT_001e56d0 + iVar1) = pvVar2;
      _bzero(pvVar2,0x88);
      pvVar2 = (void *)_kalloc(0x10);
      *(void **)(&DAT_001e56d4 + iVar1) = pvVar2;
      _bzero(pvVar2,0x10);
    }
    _lock_done(&_pty_alloc_lock);
  }
  return &DAT_001e56c8 + iVar1;
}

