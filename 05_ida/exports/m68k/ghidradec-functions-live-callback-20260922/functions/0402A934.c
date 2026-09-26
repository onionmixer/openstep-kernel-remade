
undefined * sub_402A934(word param_1,undefined *param_2)

{
  word wVar1;
  uint uVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined auStack_10 [12];
  
  puVar4 = auStack_10;
  do {
    uVar2 = (uint)param_1;
    wVar1 = (word)(uVar2 / 10);
    puVar3 = puVar4 + 1;
    *puVar4 = a0123456789[(word)(param_1 + wVar1 * -10)];
    puVar4 = puVar3;
    param_1 = wVar1;
  } while (uVar2 / 10 != 0);
  do {
    puVar3 = puVar3 + -1;
    puVar4 = param_2 + 1;
    *param_2 = *puVar3;
    param_2 = puVar4;
  } while (auStack_10 < puVar3);
  return puVar4;
}

