/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001d02b0 */

void __sel_unloadSelectors(uint param_1,uint param_2)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (DAT_001e5628 != 0) {
    do {
      piVar1 = (int *)(PTR_DAT_001e5638 + uVar3 * 4);
      while (piVar2 = piVar1, *piVar2 != 0) {
        piVar1 = (int *)*piVar2;
        if ((param_1 <= (uint)piVar1[1]) && ((uint)piVar1[1] < param_2)) {
          *piVar2 = *piVar1;
          piVar1 = piVar2;
        }
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < DAT_001e5628);
  }
  return;
}

