/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a943c */

undefined4
FUN_001a943c(int param_1,undefined4 param_2,int param_3,char *param_4,int param_5,int param_6)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)(param_1 + 0x128 + param_3 * 0x5c);
  if (*piVar1 == 0) {
    _strncpy((char *)(piVar1 + 2),param_4,0x51);
    *piVar1 = param_5;
    piVar1[1] = param_6;
    _objc_msgSend(param_1,PTR_s_initializeUnit__001f9b80,param_3);
    uVar2 = 0;
  }
  else {
    uVar2 = 0xfffffd2b;
  }
  return uVar2;
}

