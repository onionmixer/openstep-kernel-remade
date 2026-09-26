/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ca0d0 */

undefined4 FUN_001ca0d0(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _class_getInstanceMethod(*param_1,param_3);
  if (iVar1 != 0) {
    uVar2 = _method_getSizeOfArguments(iVar1);
    return uVar2;
  }
  return 0;
}

