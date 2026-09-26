/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b5fe8 */

undefined4 FUN_001b5fe8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (DAT_001e5390 == 0) {
    uVar1 = _objc_msgSend(PTR_s_List_001f9d80,PTR_s_alloc_001f9210,PTR_s_init_001f924c);
    DAT_001e5390 = _objc_msgSend(uVar1);
  }
  _objc_msgSend(DAT_001e5390,PTR_s_addObject__001f92c4,param_3);
  return param_1;
}

