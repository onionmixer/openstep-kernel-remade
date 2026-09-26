/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a9630 */

undefined4 FUN_001a9630(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _if_private(param_1);
  if (iVar1 != 0) {
    uVar2 = _objc_msgSend(iVar1,PTR_s_allocateNetbuf_001f9b70);
    return uVar2;
  }
  return 0;
}

