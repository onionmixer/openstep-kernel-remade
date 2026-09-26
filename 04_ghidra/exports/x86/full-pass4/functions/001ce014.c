/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ce014 */

void FUN_001ce014(int param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0xc) != 0) {
    pcVar1 = (code *)_class_lookupMethodInMethodList
                               (*(int *)(param_1 + 0xc),PTR_s_startUnloading_001f9cf8);
    uVar2 = _objc_getClass(*(undefined4 *)(param_1 + 4));
    if (pcVar1 != (code *)0x0) {
      (*pcVar1)(uVar2,PTR_s_startUnloading_001f9cf8);
    }
  }
  return;
}

