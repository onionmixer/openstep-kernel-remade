/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001d0288 */

void _sel_registerName(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _sel_getUid(param_1);
  if (iVar1 == 0) {
    uVar2 = _NXUniqueString(param_1);
    __sel_registerName(uVar2);
  }
  return;
}

