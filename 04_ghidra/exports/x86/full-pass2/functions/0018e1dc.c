/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018e1dc */

undefined4 _thread_setstatus(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (param_2 == -2) {
    uVar1 = _set_thread_fpstate(param_1,param_3,param_4);
  }
  else if (param_2 == -1) {
    uVar1 = _set_thread_state(param_1,param_3,param_4);
  }
  else {
    uVar1 = 4;
  }
  return uVar1;
}

