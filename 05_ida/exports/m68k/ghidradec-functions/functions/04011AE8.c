
void _domaininit(void)

{
  uint uVar1;
  undefined *puVar2;
  
  unk_40AE73A = _domains;
  unk_40AEABC = _unixdomain;
  _domains = _inetdomain;
  puVar2 = _inetdomain;
  do {
    if (*(code **)(puVar2 + 8) != (code *)0x0) {
      (**(code **)(puVar2 + 8))();
    }
    uVar1 = *(uint *)(puVar2 + 0x14);
    if (uVar1 < *(uint *)(puVar2 + 0x18)) {
      do {
        if (*(code **)(uVar1 + 0x1e) != (code *)0x0) {
          (**(code **)(uVar1 + 0x1e))();
        }
        uVar1 = uVar1 + 0x2e;
      } while (uVar1 < *(uint *)(puVar2 + 0x18));
    }
    puVar2 = *(undefined **)(puVar2 + 0x1c);
  } while (puVar2 != (undefined *)0x0);
  _null_init();
  _pffasttimo();
  _pfslowtimo();
  return;
}
