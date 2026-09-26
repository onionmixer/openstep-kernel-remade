/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c69dc */

undefined4 FUN_001c69dc(undefined4 param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  
  if (0x40 < param_3) {
    uVar1 = _objc_msgSend(param_1,PTR_s_name_001f9228,param_3);
    _IOLog("%s: Invalid arg to setBrightness:%d\n",uVar1);
  }
  return param_1;
}

