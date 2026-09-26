/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b2c6c */

int FUN_001b2c6c(int param_1,undefined4 param_2,uint param_3,int param_4,int param_5,uint param_6,
                int param_7)

{
  uint uVar1;
  
  uVar1 = param_6 >> 0x18 | param_7 << 8;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),PTR_s_lock_001f9220);
  if (*(char *)(param_1 + 0x1d2) != '\0') {
    if ((param_3 & 4) != (*(uint *)(*(int *)(param_1 + 0x168) + 8) & 4)) {
      if ((param_3 & 4) == 0) {
        *(undefined1 *)(param_1 + 0x1c0) = 0;
      }
      else {
        *(undefined1 *)(param_1 + 0x1c0) = 0xff;
      }
    }
    _objc_msgSend(param_1,PTR_s__setButtonState_atTime__001f9970,param_3,uVar1);
    if ((param_4 != 0) || (param_5 != 0)) {
      *(short *)(param_1 + 0x1a8) = *(short *)(param_1 + 0x1a8) + (short)param_4;
      *(short *)(param_1 + 0x1aa) = *(short *)(param_1 + 0x1aa) + (short)param_5;
      if (*(char *)(param_1 + 0x209) == '\0') {
        _objc_msgSend(param_1,PTR_s__setCursorPosition_atTime__001f99ac,param_1 + 0x1a8,uVar1);
      }
    }
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),PTR_s_unlock_001f9474);
  return param_1;
}

