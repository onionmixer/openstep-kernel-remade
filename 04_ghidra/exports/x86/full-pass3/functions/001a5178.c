/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a5178 */

undefined4 FUN_001a5178(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  puVar1 = DAT_001e866c;
  uVar2 = _objc_msgSend(PTR_s_List_001f9d80,PTR_s_alloc_001f9210,PTR_s_init_001f924c);
  uVar2 = _objc_msgSend(uVar2);
  _objc_msgSend(DAT_001e8674,PTR_s_lock_001f9220);
  for (; (undefined4 **)puVar1 != &DAT_001e866c; puVar1 = (undefined4 *)puVar1[2]) {
    iVar3 = _objc_msgSend(*puVar1,PTR_s_class_001f9234);
    if (iVar3 == param_3) {
      _objc_msgSend(uVar2,PTR_s_addObject__001f92c4,*puVar1);
    }
  }
  _objc_msgSend(DAT_001e8674,PTR_s_unlock_001f9474);
  return uVar2;
}

