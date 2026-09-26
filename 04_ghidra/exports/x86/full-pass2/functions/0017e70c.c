/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017e70c */

void _KernLockAcquire(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _curipl();
  if (param_1 != 0) {
    if (iVar1 < *(int *)(param_1 + 8)) {
      uVar2 = _ipltospl(*(int *)(param_1 + 8));
      _spln(uVar2);
    }
    *(int *)(param_1 + 0xc) = iVar1;
  }
  return;
}

