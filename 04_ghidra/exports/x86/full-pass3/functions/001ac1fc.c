/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ac1fc */

uint FUN_001ac1fc(int param_1,undefined4 param_2,int param_3,uint *param_4,int *param_5)

{
  uint uVar1;
  uint uVar2;
  
  param_3 = *(int *)(param_1 + 0x230) * 2 + param_3;
  uVar2 = _IOMalloc(param_3);
  *param_4 = uVar2;
  *param_5 = param_3;
  uVar1 = *(uint *)(param_1 + 0x230);
  if (1 < uVar1) {
    uVar2 = -uVar1 & (uVar1 - 1) + uVar2;
  }
  return uVar2;
}

