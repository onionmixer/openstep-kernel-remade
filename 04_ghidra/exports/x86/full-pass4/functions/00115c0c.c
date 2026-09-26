/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00115c0c */

undefined4 _soshutdown(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if ((param_2 + 1U & 1) != 0) {
    _sorflush(param_1);
  }
  if ((param_2 + 1U & 2) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = (**(code **)(iVar1 + 0x1c))(param_1,7,0,0,0);
  }
  return uVar2;
}

