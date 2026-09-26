/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001113c8 */

void _ttyselwait(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = _spltty();
  if (param_2 == 1) {
    iVar2 = _selthreadcache(param_1 + 0x28);
    if (iVar2 != 0) {
      *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x800;
    }
  }
  else if ((param_2 == 2) && (iVar2 = _selthreadcache(param_1 + 0x2c), iVar2 != 0)) {
    *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x1000;
  }
  _splx(uVar1);
  return;
}

