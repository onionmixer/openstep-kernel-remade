/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c80bc */

int FUN_001c80bc(int param_1,undefined4 param_2,uint param_3)

{
  if (param_3 < 0x41) {
    *(uint *)(param_1 + 0x238) = param_3;
    _objc_msgSend(param_1,PTR_s_setGammaTable_001f9588);
  }
  else {
    _IOLog("QVision: Invalid brightness level `%d\'.\n",param_3);
    param_1 = 0;
  }
  return param_1;
}

