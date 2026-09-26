/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b8f64 */

uint FUN_001b8f64(int param_1,undefined4 param_2,int param_3,uint param_4,int *param_5,int *param_6,
                 int *param_7,undefined4 param_8,char param_9)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  if (*(char *)(param_1 + 0x24) == '\0') {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x28),PTR_s_lock_001f9220);
    iVar3 = *(int *)(param_1 + 0x2c);
    if (param_1 + 0x2c == iVar3) {
      _objc_msgSend(*(undefined4 *)(param_1 + 0x28),PTR_s_unlock_001f9474);
      uVar4 = 0;
    }
    else {
      do {
        if ((*(uint *)(iVar3 + 8) < *(uint *)(iVar3 + 4)) && (*(int *)(iVar3 + 0x34) == 0)) {
          if (*param_5 == 0) {
            *param_5 = *(int *)(param_1 + 100);
          }
          if (*param_6 == -1) {
            *param_6 = *(int *)(param_1 + 0x68);
          }
          if (*param_7 == 0) {
            *param_7 = *(int *)(param_1 + 0x6c);
          }
          cVar1 = _objc_msgSend(param_1,PTR_s_canConvertRegion_rate_format_cha_001f9734,iVar3,
                                *param_5,*param_6,*param_7);
          if (cVar1 != '\0') {
            iVar2 = _objc_msgSend(param_1,PTR_s_mixRegion_descriptor_buffer_maxC_001f9730,iVar3,
                                  param_8,param_3 + uVar4,param_4 - uVar4,(int)param_9,*param_5,
                                  *param_6,*param_7);
            if (*(int *)(iVar3 + 0x28) == 0) {
              *(undefined4 *)(iVar3 + 0x20) = param_8;
              *(undefined4 *)(iVar3 + 0x28) = 1;
            }
            if ((*(uint *)(iVar3 + 4) <= *(uint *)(iVar3 + 8)) && (*(int *)(iVar3 + 0x2c) == 0)) {
              *(undefined4 *)(iVar3 + 0x24) = param_8;
              *(undefined4 *)(iVar3 + 0x2c) = 1;
            }
            uVar4 = uVar4 + iVar2;
            if (param_4 <= uVar4) break;
          }
        }
        iVar3 = *(int *)(iVar3 + 0x3c);
      } while (param_1 + 0x2c != iVar3);
      _objc_msgSend(*(undefined4 *)(param_1 + 0x28),PTR_s_unlock_001f9474);
      if ((param_9 != '\0') && (uVar4 < param_4)) {
        _objc_msgSend(param_1,PTR_s_clearForMix_size_format__001f972c,param_3 + uVar4,
                      param_4 - uVar4,*param_6);
      }
    }
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}

