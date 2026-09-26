/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00178400 */

undefined4
_vm_map_machine_attribute
          (int param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  
  if ((param_2 < *(uint *)(param_1 + 0x14)) || (*(uint *)(param_1 + 0x18) < param_3 + param_2)) {
    uVar1 = 4;
  }
  else {
    _lock_write(param_1);
    *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
    uVar1 = _pmap_attribute(*(undefined4 *)(param_1 + 0x24),param_2,param_3,param_4,param_5);
    _lock_done(param_1);
  }
  return uVar1;
}

