/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010ab38 */

void _wakeup(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = _splhigh();
  _thread_wakeup_prim(param_1,0,0);
  _splx(uVar1);
  return;
}

