/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a949c */

undefined4 FUN_001a949c(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)(param_1 + 0x128 + param_3 * 0x5c);
  if (*piVar1 == 0) {
    uVar2 = 0xfffffcdf;
  }
  else {
    _objc_msgSend(param_1,PTR_s_shutdownUnit__001f9b7c,param_3);
    *piVar1 = 0;
    *(undefined1 *)(piVar1 + 2) = 0;
    uVar2 = 0;
  }
  return uVar2;
}

