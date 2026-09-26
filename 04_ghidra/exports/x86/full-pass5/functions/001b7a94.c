/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b7a94 */

uint FUN_001b7a94(int param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = _objc_msgSend(param_1,PTR_s_dmaSize_001f9778);
  *(uint *)(param_1 + 0x3c) = uVar1 / param_3;
  if (0xc < uVar1 / param_3 - 4) {
    *(undefined4 *)(param_1 + 0x3c) = 8;
    param_3 = _objc_msgSend(param_1,PTR_s_dmaSize_001f9778);
    param_3 = param_3 / *(uint *)(param_1 + 0x3c);
  }
  *(uint *)(param_1 + 0x40) = param_3;
  return param_3;
}

