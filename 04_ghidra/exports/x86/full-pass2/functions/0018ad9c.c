/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018ad9c */

uint _alloc_cnvmem(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (DAT_001e75fc == 0) {
    DAT_001e75fc = DAT_001e7610;
    DAT_001e7600 = DAT_001e7614;
  }
  uVar1 = DAT_001e75fc + -1 + param_2 & -param_2;
  uVar2 = uVar1 + param_1;
  if (uVar2 <= DAT_001e7600) {
    DAT_001e75fc = uVar2;
    return uVar1;
  }
  return 0;
}

