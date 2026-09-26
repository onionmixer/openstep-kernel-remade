/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a9184 */

undefined4 _IOSetThreadPriority(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = _thread_priority(param_1,param_2,0);
  if (iVar1 == 4) {
    return 0xfffffd3e;
  }
  if (iVar1 != 5) {
    return 0;
  }
  return 0xfffffd3f;
}

