/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bac5c */

int FUN_001bac5c(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_1c [4];
  undefined4 local_c;
  undefined4 local_8;
  
  puVar2 = &DAT_001d5e94;
  puVar3 = local_1c;
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 8),PTR_s_lockWhen__001f9218,3);
  *(undefined4 *)(param_1 + 0xc) = param_3;
  local_1c[1] = 0x18;
  local_c = *(undefined4 *)(param_1 + 4);
  local_8 = 0x386;
  _objc_msgSend(*(undefined4 *)(param_1 + 8),PTR_s_unlockWith__001f9224,2);
  iVar1 = _msg_send_from_kernel(local_1c,1,1000);
  if (iVar1 == 0) {
    _objc_msgSend(*(undefined4 *)(param_1 + 8),PTR_s_lockWhen__001f9218,1);
    iVar1 = *(int *)(param_1 + 0x10);
  }
  else {
    _objc_msgSend(*(undefined4 *)(param_1 + 8),PTR_s_lock_001f9220);
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 8),PTR_s_unlockWith__001f9224,3);
  return iVar1;
}

