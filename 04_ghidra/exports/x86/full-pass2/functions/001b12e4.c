/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b12e4 */

void FUN_001b12e4(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  param_3 = param_3 + -0x100;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),PTR_s_lock_001f9220);
  if (((*(char *)(param_1 + 0x1d2) != '\0') && (-1 < param_3)) &&
     (param_3 < *(int *)(param_1 + 0x188))) {
    _objc_msgSend(param_1,PTR_s_hideCursor_001f9a38);
    *(undefined4 *)(*(int *)(param_1 + 0x180) + param_3 * 0x14) = 0;
    if (*(int *)(param_1 + 0x18c) == param_3) {
      iVar2 = *(int *)(param_1 + 0x188) + -1;
      if (iVar2 != -1) {
        iVar1 = iVar2 * 0x14;
        do {
          if (*(int *)(*(int *)(param_1 + 0x180) + iVar1) != 0) {
            *(int *)(param_1 + 0x18c) = iVar2;
            break;
          }
          iVar1 = iVar1 + -0x14;
          iVar2 = iVar2 + -1;
        } while (iVar2 != -1);
      }
      _objc_msgSend(param_1,PTR_s_setCursorPosition__001f9a18,*(int *)(param_1 + 0x168) + 0x18);
    }
    else {
      _objc_msgSend(param_1,PTR_s_showCursor_001f99fc);
    }
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),PTR_s_unlock_001f9474);
  return;
}

