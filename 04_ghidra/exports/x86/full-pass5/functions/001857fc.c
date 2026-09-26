/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001857fc */

undefined ** FUN_001857fc(undefined *param_1)

{
  undefined **ppuVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  undefined **ppuVar4;
  
  ppuVar3 = (undefined **)PTR_LOOP_001e1404;
  while( true ) {
    if (ppuVar3 == &PTR_LOOP_001e1404) {
      return (undefined **)0x0;
    }
    if (ppuVar3[2] == param_1) break;
    ppuVar3 = (undefined **)*ppuVar3;
  }
  ppuVar1 = (undefined **)*ppuVar3;
  ppuVar2 = (undefined **)ppuVar3[1];
  ppuVar4 = ppuVar2;
  if (ppuVar1 != &PTR_LOOP_001e1404) {
    ppuVar1[1] = (undefined *)ppuVar2;
    ppuVar4 = DAT_001e1408;
  }
  DAT_001e1408 = ppuVar4;
  if (ppuVar2 != &PTR_LOOP_001e1404) {
    *ppuVar2 = (undefined *)ppuVar1;
    return ppuVar3;
  }
  PTR_LOOP_001e1404 = (undefined *)ppuVar1;
  return ppuVar3;
}

