/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00187bd4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _set_clock(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  undefined1 local_c [8];
  
  if (param_1 == 0) {
    uVar1 = _splusclock();
    __time_of_boot = param_2 - DAT_001e75d0;
    _DAT_001f63e4 = (param_3 - DAT_001e75d4) - (uint)(param_2 < DAT_001e75d0);
    _splx(uVar1);
    _ns_time_to_timeval(param_2,param_3,local_c);
    _writetodc(local_c);
  }
  return;
}

