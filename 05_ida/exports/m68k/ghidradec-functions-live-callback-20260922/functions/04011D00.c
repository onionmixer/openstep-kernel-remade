
void _pffasttimo(void)

{
  int iVar1;
  uint uVar2;
  
  for (iVar1 = _domains; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x1c)) {
    uVar2 = *(uint *)(iVar1 + 0x14);
    if (uVar2 < *(uint *)(iVar1 + 0x18)) {
      do {
        if (*(code **)(uVar2 + 0x22) != (code *)0x0) {
          (**(code **)(uVar2 + 0x22))();
        }
        uVar2 = uVar2 + 0x2e;
      } while (uVar2 < *(uint *)(iVar1 + 0x18));
    }
  }
  _timeout(_pffasttimo,0,_hz / 5);
  return;
}

