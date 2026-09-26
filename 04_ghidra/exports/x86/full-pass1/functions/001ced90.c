/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ced90 */

undefined4 _objc_getMetaClass(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_objc_getClass(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    return 0;
  }
  return *puVar1;
}

