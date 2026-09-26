/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b19a4 */

int FUN_001b19a4(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int *piVar1;
  undefined4 uVar2;
  undefined *puVar3;
  undefined4 local_8;
  
  piVar1 = (int *)(*(int *)(param_1 + 0x180) + param_3 * 0x14);
  if (*(char *)(param_1 + 0x1d2) == '\0') {
    return param_1;
  }
  local_8 = *(undefined4 *)(*(int *)(param_1 + 0x168) + 0x18);
  if (*piVar1 == 0) {
    return param_1;
  }
  if (param_4 == 2) {
    uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x168) + 0x1c);
    puVar3 = PTR_s_showCursor_frame_token__001f99dc;
  }
  else {
    if (param_4 < 3) {
      if (param_4 != 1) {
        return param_1;
      }
      _objc_msgSend(*piVar1,PTR_s_hideCursor__001f99d8,param_3 + 0x100);
      return param_1;
    }
    if (param_4 != 3) {
      if (param_4 != 4) {
        return param_1;
      }
      uVar2 = _objc_msgSend(param_1,PTR_s_currentBrightness_001f99d4,param_3 + 0x100);
      _objc_msgSend(*piVar1,PTR_s_setBrightness_token__001f99d0,uVar2);
      return param_1;
    }
    uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x168) + 0x1c);
    puVar3 = PTR_s_moveCursor_frame_token__001f99e0;
  }
  _objc_msgSend(*piVar1,puVar3,&local_8,uVar2,param_3 + 0x100);
  return param_1;
}

