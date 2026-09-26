
void _pfslowtimo(void)

{
  int iVar1;
  uint uVar2;
  
  for (iVar1 = _domains; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x1c)) {
    uVar2 = *(uint *)(iVar1 + 0x14);
    if (uVar2 < *(uint *)(iVar1 + 0x18)) {
      do {
        if (*(code **)(uVar2 + 0x26) != (code *)0x0) {
          (**(code **)(uVar2 + 0x26))();
        }
        uVar2 = uVar2 + 0x2e;
      } while (uVar2 < *(uint *)(iVar1 + 0x18));
    }
  }
  iVar1 = _hz;
  if (_hz < 0) {
    iVar1 = _hz + 1;
  }
  _timeout(_pfslowtimo,0,iVar1 >> 1);
  return;
}

