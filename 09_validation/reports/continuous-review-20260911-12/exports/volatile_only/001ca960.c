
undefined4 * FUN_001ca960(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  do {
    do {
      iVar1 = DAT_001e5534;
    } while (iVar1 != 0);
    LOCK();
    iVar1 = DAT_001e5534;
    DAT_001e5534 = 1;
    UNLOCK();
  } while (iVar1 == 1);
  puVar3 = &DAT_001e551c;
  do {
    if (puVar3[4] == 0) {
      puVar3[4] = param_1;
      goto LAB_001ca9bc;
    }
    puVar3 = (undefined4 *)puVar3[5];
  } while (puVar3 != (undefined4 *)0x0);
  puVar3 = _calloc(0x18,1);
  puVar3[4] = param_1;
  puVar3[5] = DAT_001e5530;
  DAT_001e5530 = puVar3;
LAB_001ca9bc:
  LOCK();
  uVar2 = DAT_001e5534;
  DAT_001e5534 = 0;
  UNLOCK();
  return puVar3;
}

