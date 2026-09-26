/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ca4c8 */

void __internal_object_copy(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = _NXZoneFromPtr(param_1);
  if (iVar1 == 0) {
    iVar1 = _NXDefaultMallocZone();
  }
  __internal_object_copyFromZone(param_1,param_2,iVar1);
  return;
}

