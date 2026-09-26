
/* WARNING: Removing unreachable block (ram,0xf0094054) */
/* WARNING: Removing unreachable block (ram,0xf00940cc) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_f0094054(undefined *param_1,undefined **param_2)

{
  undefined **ppuVar1;
  undefined *puVar2;
  undefined **ppuVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  
  ppuVar4 = (undefined **)PTR_LOOP_f0112528;
  if ((undefined **)PTR_LOOP_f0112528 == &PTR_LOOP_f0112528) {
    ppuVar5 = (undefined **)0x0;
  }
  else {
    param_2 = &PTR_LOOP_f0112528;
    puVar2 = *(undefined **)(PTR_LOOP_f0112528 + 8);
    ppuVar5 = (undefined **)PTR_LOOP_f0112528;
    while (puVar2 != param_1) {
      ppuVar5 = (undefined **)*ppuVar5;
      if (ppuVar5 == &PTR_LOOP_f0112528) {
        ppuVar5 = (undefined **)0x0;
        goto LAB_f00940cc;
      }
      puVar2 = ppuVar5[2];
    }
    ppuVar4 = (undefined **)*ppuVar5;
    ppuVar3 = (undefined **)ppuVar5[1];
    ppuVar1 = ppuVar3;
    if (ppuVar4 != &PTR_LOOP_f0112528) {
      ppuVar4[1] = (undefined *)ppuVar3;
      ppuVar1 = _DAT_f011252c;
    }
    _DAT_f011252c = ppuVar1;
    if (ppuVar3 != &PTR_LOOP_f0112528) {
      *ppuVar3 = (undefined *)ppuVar4;
      ppuVar4 = (undefined **)PTR_LOOP_f0112528;
    }
  }
LAB_f00940cc:
  PTR_LOOP_f0112528 = (undefined *)ppuVar4;
  return CONCAT44(param_2,ppuVar5);
}

