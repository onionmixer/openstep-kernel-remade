/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010c1c0 */

undefined4 _log(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = _splhigh();
  FUN_0010c248(param_1);
  _prf(param_2,&stack0x0000000c,4,0);
  _splx(uVar1);
  if (_log_open == 0) {
    _prf(param_2,&stack0x0000000c,1,0);
  }
  _logwakeup();
  _splx(uVar1);
  return 0;
}

