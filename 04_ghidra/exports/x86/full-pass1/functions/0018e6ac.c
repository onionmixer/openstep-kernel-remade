/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018e6ac */

undefined4
_thread_getstatus(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  switch(param_2) {
  case 0:
    uVar1 = _get_thread_state_flavor_list(param_3,param_4);
    break;
  case 0xfffffffc:
    uVar1 = _get_thread_cthreadstate(param_1,param_3,param_4);
    break;
  case 0xfffffffd:
    uVar1 = _get_thread_exceptstate(param_1,param_3,param_4);
    break;
  case 0xfffffffe:
    uVar1 = _get_thread_fpstate(param_1,param_3,param_4);
    break;
  case 0xffffffff:
    uVar1 = _get_thread_state(param_1,param_3,param_4);
    break;
  default:
    uVar1 = 4;
  }
  return uVar1;
}

