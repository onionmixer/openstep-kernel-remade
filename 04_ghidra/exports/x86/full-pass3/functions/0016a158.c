/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016a158 */

bool _kern_timestamp(undefined4 param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 local_c [8];
  
  uVar2 = _clock_value(1);
  _ns_time_to_tsval(uVar2,local_c);
  iVar1 = _copyout(local_c,param_1,8);
  return iVar1 != 0;
}

