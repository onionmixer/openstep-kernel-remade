/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b60a4 */

undefined4 FUN_001b60a4(undefined4 param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  while( true ) {
    uVar1 = _objc_msgSend(DAT_001e5390,PTR_s_count_001f92d8);
    if (uVar1 <= uVar4) {
      return 0;
    }
    uVar2 = _objc_msgSend(DAT_001e5390,PTR_s_objectAt__001f92e8,uVar4);
    iVar3 = _objc_msgSend(uVar2,PTR_s_exclusiveUser_001f9910);
    if (iVar3 == param_3) break;
    uVar4 = uVar4 + 1;
  }
  return uVar2;
}

