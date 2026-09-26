/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cbf34 */

uint FUN_001cbf34(undefined4 param_1,undefined4 *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = _NXPtrHash(param_1,*param_2);
  uVar2 = _NXPtrHash(param_1,param_2[1]);
  uVar3 = _NXPtrHash(param_1,param_2[2]);
  return uVar1 ^ uVar2 ^ uVar3 ^ param_2[3];
}

