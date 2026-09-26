/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001165cc */

void _sbrelease(int param_1)

{
  undefined4 uVar1;
  
  _sbflush(param_1);
  *(undefined2 *)(param_1 + 6) = 0;
  *(undefined2 *)(param_1 + 2) = 0;
  uVar1 = _splimp();
  if (*(int *)(param_1 + 0x10) != 0) {
    _selthreadclear(param_1 + 0x10);
  }
  _splx(uVar1);
  return;
}

