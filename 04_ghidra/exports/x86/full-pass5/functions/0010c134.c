/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010c134 */

void _tprintf(tpr_t param_1,char *fmt,...)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 6;
  FUN_0010c248(6);
  if (param_1 == (tpr_t)0x0) {
    param_1 = (tpr_t)&_cons;
  }
  iVar1 = _ttycheckoutq(param_1,0);
  if (iVar1 == 0) {
    uVar2 = 4;
  }
  _prf(fmt,&stack0x0000000c,uVar2,param_1);
  _logwakeup();
  return;
}

