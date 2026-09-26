/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b6998 */

void FUN_001b6998(int param_1,undefined4 param_2,undefined4 param_3,char param_4)

{
  undefined4 uVar1;
  
  switch(param_3) {
  case 0x1e:
    *(char *)(*(int *)(param_1 + 0x174) + 0x10) = param_4;
    uVar1 = 9;
    if (param_4 != '\0') {
      uVar1 = 8;
    }
    break;
  case 0x1f:
    *(char *)(*(int *)(param_1 + 0x174) + 0x11) = param_4;
    uVar1 = 0xb;
    if (param_4 != '\0') {
      uVar1 = 10;
    }
    break;
  case 0x20:
    *(char *)(*(int *)(param_1 + 0x174) + 0x12) = param_4;
    uVar1 = 0xd;
    if (param_4 != '\0') {
      uVar1 = 0xc;
    }
    break;
  case 0x21:
    *(char *)(*(int *)(param_1 + 0x174) + 0x13) = param_4;
    uVar1 = 0xf;
    if (param_4 != '\0') {
      uVar1 = 0xe;
    }
    break;
  case 0x22:
    *(char *)(*(int *)(param_1 + 0x174) + 0x14) = param_4;
    uVar1 = 0x11;
    if (param_4 != '\0') {
      uVar1 = 0x10;
    }
    break;
  default:
    _IOLog("Audio: unknown input source: %d\n",param_3);
    return;
  }
  uVar1 = _objc_msgSend(param_1,PTR_s__audioCommand_001f98e0,PTR_s_send__001f9b4c,uVar1);
  _objc_msgSend(uVar1);
  return;
}

