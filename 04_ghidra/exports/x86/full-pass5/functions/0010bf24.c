/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010bf24 */

undefined4 _logselect(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = _splhigh();
  if (param_2 == 1) {
    if (*(int *)(_pmsgbuf + 8) != *(int *)(_pmsgbuf + 4)) {
      _splx(uVar1);
      return 1;
    }
    _selthreadcache(&DAT_001e97c4);
  }
  _splx(uVar1);
  return 0;
}

