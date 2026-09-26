/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001809f0 */

int FUN_001809f0(int param_1)

{
  char cVar1;
  int iVar2;
  
  _objc_msgSend(*(undefined4 *)(param_1 + 8),PTR_s_acquire_001f92b8);
  iVar2 = *(int *)(param_1 + 4);
  if (iVar2 == 0) {
    _objc_msgSend(*(undefined4 *)(param_1 + 8),PTR_s_release_001f92bc);
    param_1 = 0;
  }
  else {
    cVar1 = *(char *)(param_1 + 0x18);
    *(undefined1 *)(param_1 + 0x18) = 0;
    _objc_msgSend(*(undefined4 *)(param_1 + 8),PTR_s_release_001f92bc);
    if (cVar1 != '\0') {
      _objc_msgSend(iVar2,PTR_s_resume_001f92f8);
    }
  }
  return param_1;
}

