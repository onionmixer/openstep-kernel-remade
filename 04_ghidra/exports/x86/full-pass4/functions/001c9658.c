/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c9658 */

undefined4 FUN_001c9658(undefined4 param_1)

{
  int iVar1;
  
  while( true ) {
    iVar1 = _objc_msgSend(param_1,PTR_s_removeLastObject_001f9d30);
    if (iVar1 == 0) break;
    _objc_msgSend(iVar1,PTR_s_free_001f921c);
  }
  return param_1;
}

