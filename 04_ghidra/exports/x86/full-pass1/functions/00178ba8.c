/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00178ba8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __vm_object_allocate(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar3 = &_vm_object_template;
  puVar4 = param_2;
  for (iVar2 = 0x16; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  param_2[1] = param_2;
  *param_2 = param_2;
  param_2[4] = 0;
  param_2[5] = param_1;
  do {
  } while (_vm_object_list_lock != 0);
  LOCK();
  _vm_object_list_lock = 1;
  UNLOCK();
  if (DAT_001f7354 == (undefined4 *)&_vm_object_list) {
    __vm_object_list = param_2;
  }
  else {
    *(undefined4 **)((int)DAT_001f7354 + 8) = param_2;
  }
  param_2[3] = DAT_001f7354;
  param_2[2] = &_vm_object_list;
  uVar1 = _vm_object_list_lock;
  DAT_001f7354 = param_2;
  __vm_object_count = __vm_object_count + 1;
  LOCK();
  _vm_object_list_lock = 0;
  UNLOCK();
  return uVar1;
}

