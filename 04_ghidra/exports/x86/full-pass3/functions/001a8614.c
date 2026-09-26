/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a8614 */

undefined4 FUN_001a8614(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x10c) == 0) {
    uVar1 = _task_self(param_1 + 0x10c);
    iVar2 = _port_allocate_EXTERNAL(uVar1);
    if (iVar2 != 0) {
      return 0xfffffd27;
    }
    uVar1 = _objc_msgSend(*(undefined4 *)(param_1 + 0x114),PTR_s_device_001f9bec,
                          PTR_s_attachInterruptPort__001f9bdc,*(undefined4 *)(param_1 + 0x10c));
    iVar2 = _objc_msgSend(uVar1);
    if (iVar2 == 0) {
      uVar1 = _task_self(*(undefined4 *)(param_1 + 0x10c));
      _port_deallocate_EXTERNAL(uVar1);
      *(undefined4 *)(param_1 + 0x10c) = 0;
      return 0xfffffd27;
    }
  }
  return 0;
}

