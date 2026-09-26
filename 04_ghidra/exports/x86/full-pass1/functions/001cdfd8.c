/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cdfd8 */

void FUN_001cdfd8(undefined4 *param_1)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = FUN_001cdf30(*param_1);
  if (iVar1 != 0) {
    pcVar2 = (code *)_class_lookupMethodInMethodList(iVar1,PTR_s_startUnloading_001f9cf8);
    if (pcVar2 != (code *)0x0) {
      (*pcVar2)(param_1,PTR_s_startUnloading_001f9cf8);
    }
  }
  return;
}

