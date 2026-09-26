/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010d7e4 */

void _selwakeup(int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_2 != 0) {
    _nselcoll = _nselcoll + 1;
    _wakeup(&_selwait);
  }
  if ((param_1 != 0) && (*(int *)(param_1 + 0x178) != 0)) {
    uVar3 = _splhigh();
    if (*(undefined **)(param_1 + 0x3c) == &_selwait) {
      _clear_wait(param_1,0,1);
    }
    iVar2 = *(int *)(*(int *)(param_1 + 0xc) + 0x3c);
    if (iVar2 != 0) {
      puVar1 = (uint *)(iVar2 + 0x28);
      *puVar1 = *puVar1 & 0xffbfffff;
    }
    _splx(uVar3);
  }
  return;
}

