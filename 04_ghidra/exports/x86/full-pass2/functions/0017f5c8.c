/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017f5c8 */

undefined4 FUN_0017f5c8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)_objc_msgSend(param_1,PTR_s_resourceNames_001f9294);
  while( true ) {
    if (piVar1 == (int *)0x0) {
      return param_3;
    }
    if (*piVar1 == 0) break;
    iVar2 = _objc_msgSend(param_3,PTR_s_allocateResourcesForKey__001f9298,*piVar1);
    if (iVar2 == 0) {
      return 0;
    }
    piVar1 = piVar1 + 1;
  }
  return param_3;
}

