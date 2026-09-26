/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a846c */

void FUN_001a846c(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  undefined *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int local_24;
  undefined *local_20;
  undefined4 local_1c [4];
  undefined4 local_c;
  undefined4 local_8;
  
  piVar1 = *(int **)(param_1 + 0x11c);
  piVar2 = *(int **)(param_1 + 0x118);
  puVar6 = &DAT_001d5c60;
  puVar7 = local_1c;
  for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
  }
  if (*(int *)(param_1 + 0x10c) != 0) {
    if (*(int *)(param_1 + 0x110) != 0) {
      local_1c[1] = 0x18;
      local_8 = 0x232336;
      local_c = _IOGetKernPort(*(undefined4 *)(param_1 + 0x10c));
      _msg_send_from_kernel(local_1c,0,0);
    }
    uVar3 = _objc_msgSend(*(undefined4 *)(param_1 + 0x114),PTR_s_device_001f9bec,
                          PTR_s_detachInterruptPort_001f92d0);
    _objc_msgSend(uVar3);
    uVar3 = _task_self(*(undefined4 *)(param_1 + 0x10c));
    _port_deallocate_EXTERNAL(uVar3);
    *(undefined4 *)(param_1 + 0x10c) = 0;
  }
  if ((piVar2 != (int *)0x0) &&
     (((iVar4 = *piVar2, puVar5 = PTR_s_freeEISA_001f9be8, iVar4 == 1 ||
       (puVar5 = PTR_s_freeHPPA_001f9be4, iVar4 == 2)) ||
      (puVar5 = PTR_s_freeSPARC_001f9be0, iVar4 == 3)))) {
    _objc_msgSend(param_1,puVar5);
  }
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      _objc_msgSend(*piVar1,PTR_s_free_001f921c);
    }
    if (piVar1[1] != 0) {
      _objc_msgSend(piVar1[1],PTR_s_free_001f921c);
    }
    _IOFree(piVar1,8);
  }
  local_24 = param_1;
  local_20 = PTR_s_IODevice_001fa1a8;
  _objc_msgSendSuper(&local_24,PTR_s_free_001f921c);
  return;
}

