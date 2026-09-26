/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a9334 */

undefined4 _IOPhysicalFromVirtual(undefined4 param_1,undefined4 param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = __io_vm_task_pmap(param_1,param_2);
  iVar2 = _pmap_extract(uVar1);
  *param_3 = iVar2;
  if (iVar2 == 0) {
    uVar1 = 0xfffffd3e;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

