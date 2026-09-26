/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ca4f4 */

undefined4 __internal_object_dispose(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    uVar1 = __objc_getFreedObjectClass();
    *param_1 = uVar1;
    _free(param_1);
  }
  return 0;
}

