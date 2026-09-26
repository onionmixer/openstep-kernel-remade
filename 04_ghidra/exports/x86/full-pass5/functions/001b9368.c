/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b9368 */

void FUN_001b9368(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  undefined *local_8;
  
  if (*(int *)(param_1 + 0x38) != 0) {
    uVar1 = _task_self(*(int *)(param_1 + 0x38));
    _port_deallocate_EXTERNAL(uVar1);
  }
  if (*(int *)(param_1 + 0x3c) != 0) {
    uVar1 = _task_self(*(int *)(param_1 + 0x3c));
    _port_deallocate_EXTERNAL(uVar1);
  }
  if (*(int *)(param_1 + 0x40) != 0) {
    uVar1 = _task_self(*(int *)(param_1 + 0x40));
    _port_deallocate_EXTERNAL(uVar1);
  }
  _objc_msgSend(param_1,PTR_s_freeRegions_001f9718);
  uVar1 = _task_self(*(undefined4 *)(param_1 + 0xc));
  iVar2 = _port_deallocate_EXTERNAL(uVar1);
  if (iVar2 != 0) {
    _IOLog("Audio: stream port_deallocate: %s\n","MACH ERR");
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x28),PTR_s_free_001f921c);
  if (*(int *)(param_1 + 0x34) != 0) {
    _IOFree(*(int *)(param_1 + 0x34),0x2000);
  }
  local_c = param_1;
  local_8 = PTR_s_Object_001fa4c8;
  _objc_msgSendSuper(&local_c,PTR_s_free_001f921c);
  return;
}

