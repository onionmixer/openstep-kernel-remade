/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00178b80 */

undefined4 _vm_object_allocate(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = _zalloc(_vm_object_zone);
  __vm_object_allocate(param_1,uVar1);
  return uVar1;
}

