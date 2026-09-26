/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b2904 */

undefined4 FUN_001b2904(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)_defaultEventSources();
  iVar1 = *piVar2;
  while (iVar1 != 0) {
    _objc_msgSend(param_1,PTR_s_attachEventSource__001f9978,*piVar2);
    piVar2 = piVar2 + 1;
    iVar1 = *piVar2;
  }
  return param_1;
}

