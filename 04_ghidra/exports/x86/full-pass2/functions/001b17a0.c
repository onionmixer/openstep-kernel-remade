/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b17a0 */

int FUN_001b17a0(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (param_3 == 0) {
    *(undefined4 *)(param_1 + 0x144) = 0;
  }
  else if (*(int *)(param_1 + 0x114) != param_3) {
    uVar1 = _IOGetKernPort(param_3);
    *(undefined4 *)(param_1 + 0x144) = uVar1;
    _port_request_notification(uVar1,*(undefined4 *)(param_1 + 0x140));
  }
  if (*(int *)(param_1 + 0x14c) == 0) {
    uVar1 = _IOMalloc(0x1c);
    *(undefined4 *)(param_1 + 0x14c) = uVar1;
  }
  *(int *)(param_1 + 0x114) = param_3;
  puVar3 = &DAT_001e5364;
  puVar4 = *(undefined4 **)(param_1 + 0x14c);
  for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  *(int *)(*(int *)(param_1 + 0x14c) + 0x10) = param_3;
  return param_1;
}

