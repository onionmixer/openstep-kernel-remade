/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b62ac */

void FUN_001b62ac(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x13c) == 0) {
    iVar2 = _IOMalloc(0x18);
    *(int *)(param_1 + 0x13c) = iVar2;
    *(undefined1 *)(iVar2 + 3) = 1;
    *(undefined4 *)(*(int *)(param_1 + 0x13c) + 4) = 0x18;
    *(undefined4 *)(*(int *)(param_1 + 0x13c) + 8) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x13c) + 0xc) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x13c) + 0x10) = *(undefined4 *)(param_1 + 0x134);
  }
  cVar1 = _objc_msgSend(param_3,PTR_s_isRead_001f98fc);
  if (cVar1 == '\0') {
    *(undefined4 *)(*(int *)(param_1 + 0x13c) + 0x14) = 900;
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x13c) + 0x14) = 0x385;
  }
  iVar2 = _msg_send_from_kernel(*(undefined4 *)(param_1 + 0x13c),1,1000);
  if ((iVar2 != 0) && (iVar2 != -0x67)) {
    _IOLog("Audio: data pending msg_send error: %d\n",iVar2);
  }
  return;
}

