/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a9dec */

void _IORemoveFromCdevsw(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined **ppuVar3;
  
  puVar2 = &DAT_001e5100;
  ppuVar3 = &_cdevsw + param_1 * 0xb;
  for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppuVar3 = (undefined *)*puVar2;
    puVar2 = puVar2 + 1;
    ppuVar3 = ppuVar3 + 1;
  }
  return;
}

