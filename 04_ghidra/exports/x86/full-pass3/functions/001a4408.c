/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a4408 */

undefined4 FUN_001a4408(undefined4 param_1)

{
  int iVar1;
  int local_8;
  
  iVar1 = FUN_001a3e30(param_1,&local_8);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  return *(undefined4 *)(local_8 + 8);
}

