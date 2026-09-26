/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a6200 */

undefined4 FUN_001a6200(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x184);
  do {
    iVar2 = _objc_msgSend(iVar2,PTR_s_nextLogicalDisk_001f9c8c);
    if (iVar2 == 0) {
      return 0;
    }
  } while ((iVar2 == param_1) ||
          (cVar1 = _objc_msgSend(iVar2,PTR_s_isInstanceOpen_001f9394), cVar1 == '\0'));
  return 1;
}

