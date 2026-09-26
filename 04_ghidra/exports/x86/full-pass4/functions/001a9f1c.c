/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a9f1c */

void FUN_001a9f1c(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_1c [4];
  undefined4 local_c;
  undefined4 local_8;
  
  puVar3 = &DAT_001d5cb4;
  puVar4 = local_1c;
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  if ((*(int *)(param_1 + 0x130) != 0) || (*(int *)(param_1 + 0x134) != 0)) {
    *(undefined4 *)(param_1 + 0x130) = 0;
    *(undefined4 *)(param_1 + 0x134) = 0;
    local_1c[1] = 0x18;
    uVar1 = _objc_msgSend(param_1,PTR_s_interruptPort_001f9b58);
    local_c = _IOGetKernPort(uVar1);
    local_8 = 0x232323;
    _msg_send_from_kernel(local_1c,0,0);
  }
  return;
}

