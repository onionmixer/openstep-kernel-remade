
void _getlastaddr(void)

{
  uint uVar1;
  undefined *puVar2;
  uint uVar3;
  
  uVar1 = 0;
  puVar2 = stru_400001C;
  uVar3 = 0;
  do {
    if ((*(int *)puVar2 == 1) &&
       (uVar1 < (uint)(*(int *)((int)puVar2 + 0x1c) + *(int *)((int)puVar2 + 0x18)))) {
      uVar1 = *(int *)((int)puVar2 + 0x1c) + *(int *)((int)puVar2 + 0x18);
    }
    puVar2 = (undefined *)(*(int *)((int)puVar2 + 4) + (int)puVar2);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 5);
  return;
}

