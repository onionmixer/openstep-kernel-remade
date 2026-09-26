/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001801c4 */

void _IOEnableInterrupt(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  _KernLockAcquire(*(undefined4 *)(param_1 + 8));
  uVar2 = *(undefined4 *)(param_1 + 4);
  cVar1 = *(char *)(param_1 + 0x18);
  *(undefined1 *)(param_1 + 0x18) = 0;
  _KernLockRelease(*(undefined4 *)(param_1 + 8));
  if (cVar1 != '\0') {
    _KernBusInterruptResume(uVar2);
  }
  return;
}

