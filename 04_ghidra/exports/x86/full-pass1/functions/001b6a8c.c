/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b6a8c */

void FUN_001b6a8c(int param_1,undefined4 param_2,undefined4 param_3,char param_4)

{
  undefined4 uVar1;
  
  switch(param_3) {
  case 0x19:
    *(char *)(*(int *)(param_1 + 0x174) + 0x16) = param_4;
    uVar1 = 0x13;
    if (param_4 != '\0') {
      uVar1 = 0x12;
    }
    break;
  case 0x1a:
    *(char *)(*(int *)(param_1 + 0x174) + 0x15) = param_4;
    uVar1 = 0x15;
    if (param_4 != '\0') {
      uVar1 = 0x14;
    }
    break;
  case 0x1b:
    *(char *)(*(int *)(param_1 + 0x174) + 0x17) = param_4;
    uVar1 = 0x17;
    if (param_4 != '\0') {
      uVar1 = 0x16;
    }
    break;
  case 0x1c:
    *(char *)(*(int *)(param_1 + 0x174) + 0x18) = param_4;
    uVar1 = 0x19;
    if (param_4 != '\0') {
      uVar1 = 0x18;
    }
    break;
  case 0x1d:
    *(char *)(*(int *)(param_1 + 0x174) + 0x19) = param_4;
    uVar1 = 0x1b;
    if (param_4 != '\0') {
      uVar1 = 0x1a;
    }
    break;
  default:
    _IOLog("Audio: unknown output source: %d\n",param_3);
    return;
  }
  uVar1 = _objc_msgSend(param_1,PTR_s__audioCommand_001f98e0,PTR_s_send__001f9b4c,uVar1);
  _objc_msgSend(uVar1);
  return;
}

