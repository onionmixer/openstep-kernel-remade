/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00187844 */

void _system_timer_dispatch(undefined4 param_1,int param_2,undefined4 param_3)

{
  bool bVar1;
  undefined4 local_10;
  uint local_c;
  undefined4 local_8;
  
  bVar1 = 0xff67697f < DAT_001e75d0;
  DAT_001e75d0 = DAT_001e75d0 + 10000000;
  DAT_001e75d4 = DAT_001e75d4 + bVar1;
  DAT_001e75d8 = DAT_001e75da;
  if (param_2 == 0) {
    local_10 = 0;
    local_c = 0;
  }
  else {
    local_10 = *(undefined4 *)(param_2 + 0x38);
    if ((*(byte *)(param_2 + 0x42) & 2) == 0) {
      local_c = *(byte *)(param_2 + 0x3c) & 3;
    }
    else {
      local_c = 3;
    }
  }
  local_8 = param_3;
  if (DAT_001e75e8 != 0) {
    FUN_00187938(&local_10);
  }
  if (((DAT_001e75e4 != (code *)0x0) &&
      (((DAT_001e75dc != 0 || (DAT_001e75e0 != 0)) && (DAT_001e75e0 <= DAT_001e75d4)))) &&
     ((DAT_001e75e0 != DAT_001e75d4 || (DAT_001e75dc <= DAT_001e75d0)))) {
    DAT_001e75dc = 0;
    DAT_001e75e0 = 0;
    (*DAT_001e75e4)(0,0,0);
  }
  return;
}

