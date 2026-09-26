/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010bdd4 */

void _logclose(void)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = DAT_001e97cc;
  _log_open = 0;
  DAT_001e97cc = 0;
  _calloutEntryRemove(uVar2);
  _calloutEntryFree(uVar2);
  _logsoftc = 0;
  uVar2 = _splhigh();
  iVar1 = DAT_001e97c4;
  DAT_001e97c4 = 0;
  _splx(uVar2);
  if (iVar1 != 0) {
    _thread_deallocate(iVar1);
  }
  DAT_001e97c8 = 0;
  return;
}

