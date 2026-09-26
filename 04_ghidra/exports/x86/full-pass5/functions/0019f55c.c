/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019f55c */

void FUN_0019f55c(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = param_3[1];
  *(undefined4 *)(param_1 + 0x158) = *param_3;
  *(undefined4 *)(param_1 + 0x15c) = uVar1;
  uVar2 = param_3[2];
  if (uVar2 == 0x7f) {
    return;
  }
  if (uVar2 == 0x36) {
    uVar2 = 4;
    goto LAB_0019f5da;
  }
  if (uVar2 < 0x37) {
    if (uVar2 == 0x1d) {
LAB_0019f5d0:
      uVar2 = 1;
      goto LAB_0019f5da;
    }
    if (uVar2 == 0x2a) {
      uVar2 = 2;
      goto LAB_0019f5da;
    }
  }
  else {
    if (uVar2 == 0x60) goto LAB_0019f5d0;
    if (uVar2 < 0x61) {
      if (uVar2 == 0x38) {
        uVar2 = 0x20;
        goto LAB_0019f5da;
      }
    }
    else if (uVar2 == 0x61) {
      uVar2 = 0x40;
      goto LAB_0019f5da;
    }
  }
  uVar2 = 0;
LAB_0019f5da:
  if (*(char *)(param_3 + 3) == '\0') {
    *(uint *)(param_1 + 0x148) = *(uint *)(param_1 + 0x148) & ~uVar2;
  }
  else {
    *(uint *)(param_1 + 0x148) = *(uint *)(param_1 + 0x148) | uVar2;
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x124),PTR_s_lock_001f9220);
  _objc_msgSend(*(undefined4 *)(param_1 + 0x128),PTR_s_doKeyboardEvent_direction_keyBit_001f94ec,
                param_3[2],(int)*(char *)(param_3 + 3),param_1 + 0x134);
  _objc_msgSend(*(undefined4 *)(param_1 + 0x124),PTR_s_unlock_001f9474);
  return;
}

