
undefined ** FUN_04064092(undefined *param_1)

{
  undefined **ppuVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  undefined **ppuVar4;
  
  ppuVar4 = (undefined **)PTR_LOOP_040b0704;
  if ((undefined **)PTR_LOOP_040b0704 != &PTR_LOOP_040b0704) {
    do {
      if (param_1 == ppuVar4[2]) {
        ppuVar1 = (undefined **)*ppuVar4;
        ppuVar2 = (undefined **)ppuVar4[1];
        ppuVar3 = ppuVar2;
        if (ppuVar1 != &PTR_LOOP_040b0704) {
          ppuVar1[1] = (undefined *)ppuVar2;
          ppuVar3 = DAT_040b0708;
        }
        DAT_040b0708 = ppuVar3;
        if (ppuVar2 == &PTR_LOOP_040b0704) {
          PTR_LOOP_040b0704 = (undefined *)ppuVar1;
          return ppuVar4;
        }
        *ppuVar2 = (undefined *)ppuVar1;
        return ppuVar4;
      }
      ppuVar4 = (undefined **)*ppuVar4;
    } while (ppuVar4 != &PTR_LOOP_040b0704);
  }
  return (undefined **)0x0;
}

