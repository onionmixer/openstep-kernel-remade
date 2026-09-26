/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017f3fc */

undefined4
FUN_0017f3fc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _objc_msgSend(DAT_001e7320,PTR_s_valueForKey__001f928c,param_4);
  if (iVar1 == 0) {
    uVar2 = _objc_msgSend(PTR_s_HashTable_001f9d74,PTR_s_alloc_001f9210,PTR_s_initKeyDesc__001f9284,
                          &DAT_001e0fcc);
    iVar1 = _objc_msgSend(uVar2);
    _objc_msgSend(DAT_001e7320,PTR_s_insertKey_value__001f9288,param_4,iVar1);
  }
  _objc_msgSend(iVar1,PTR_s_insertKey_value__001f9288,param_5,param_3);
  return param_3;
}

