
undefined4 _m_expand(int param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  
  bVar1 = false;
  while( true ) {
    iVar2 = _m_clalloc(1,0,param_1);
    if (iVar2 != 0) {
      return 1;
    }
    if ((param_1 == 0) || (iVar2 = _domains, bVar1)) break;
    for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x1c)) {
      uVar3 = *(uint *)(iVar2 + 0x14);
      if (uVar3 < *(uint *)(iVar2 + 0x18)) {
        do {
          if (*(code **)(uVar3 + 0x2a) != (code *)0x0) {
            (**(code **)(uVar3 + 0x2a))();
          }
          uVar3 = uVar3 + 0x2e;
        } while (uVar3 < *(uint *)(iVar2 + 0x18));
      }
    }
    unk_40B61C8 = unk_40B61C8 + 1;
    bVar1 = true;
  }
  return 0;
}
