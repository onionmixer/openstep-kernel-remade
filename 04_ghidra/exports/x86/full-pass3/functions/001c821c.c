/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c821c */

int FUN_001c821c(int param_1,undefined4 param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = _objc_msgSend(param_1,PTR_s_displayInfo_001f9610);
  switch(*(undefined4 *)(iVar1 + 0x18)) {
  case 0:
    uVar4 = 0;
    do {
      uVar2 = (uint)(byte)(&DAT_001e5420)[uVar4] * *(int *)(param_1 + 0x238) >> 6;
      uVar3 = 0;
      do {
        *param_3 = uVar2 | uVar2 << 0x10 | uVar2 << 8;
        param_3 = param_3 + 1;
        uVar3 = uVar3 + 1;
      } while (uVar3 < 0x40);
      uVar4 = uVar4 + 1;
    } while (uVar4 < 4);
    break;
  case 1:
  case 4:
    uVar4 = 0;
    do {
      uVar3 = (uint)(byte)(&DAT_001d637c)[uVar4] * *(int *)(param_1 + 0x238) >> 6;
      *param_3 = uVar3 << 0x10 | uVar3 << 8 | uVar3;
      param_3 = param_3 + 1;
      uVar4 = uVar4 + 1;
    } while (uVar4 < 0x100);
    break;
  case 2:
    uVar4 = 0;
    do {
      uVar2 = (uint)(byte)(&DAT_001e5424)[uVar4] * *(int *)(param_1 + 0x238) >> 6;
      uVar3 = 0;
      do {
        *param_3 = uVar2 | uVar2 << 0x10 | uVar2 << 8;
        param_3 = param_3 + 1;
        uVar3 = uVar3 + 1;
      } while (uVar3 < 0x10);
      uVar4 = uVar4 + 1;
    } while (uVar4 < 0x10);
    break;
  case 3:
    uVar4 = 0;
    do {
      uVar2 = (uint)(byte)(&DAT_001e5434)[uVar4] * *(int *)(param_1 + 0x238) >> 6;
      uVar3 = 0;
      do {
        *param_3 = uVar2 | uVar2 << 0x10 | uVar2 << 8;
        param_3 = param_3 + 1;
        uVar3 = uVar3 + 1;
      } while (uVar3 < 8);
      uVar4 = uVar4 + 1;
    } while (uVar4 < 0x20);
    break;
  default:
    goto switchD_001c8244_default;
  }
  iVar1 = _objc_msgSend(param_1,PTR_s_runVPCode_withRegs__001f9590,7,0);
  if (iVar1 == 0) {
    param_1 = 0;
  }
switchD_001c8244_default:
  return param_1;
}

