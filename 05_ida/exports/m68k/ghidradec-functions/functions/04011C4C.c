
void _pfctlinput(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  
  for (iVar1 = _domains; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x1c)) {
    uVar2 = *(uint *)(iVar1 + 0x14);
    if (uVar2 < *(uint *)(iVar1 + 0x18)) {
      do {
        if (*(code **)(uVar2 + 0x12) != (code *)0x0) {
          (**(code **)(uVar2 + 0x12))(param_1,param_2,0);
        }
        uVar2 = uVar2 + 0x2e;
      } while (uVar2 < *(uint *)(iVar1 + 0x18));
    }
  }
  return;
}
