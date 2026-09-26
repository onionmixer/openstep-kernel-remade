/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cdf50 */

void FUN_001cdf50(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = FUN_001cdf30(*param_1);
  if (iVar1 != 0) {
    pcVar2 = (code *)_class_lookupMethodInMethodList(iVar1,PTR_s_finishLoading__001f9cfc);
    if (pcVar2 != (code *)0x0) {
      (*pcVar2)(param_1,PTR_s_finishLoading__001f9cfc,param_2);
    }
  }
  return;
}

