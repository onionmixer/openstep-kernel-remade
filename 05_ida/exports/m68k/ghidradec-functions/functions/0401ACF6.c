
void _ftruncate(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined uVar3;
  undefined auStack_42 [20];
  undefined4 uStack_2e;
  int iStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  if ((int)puVar1[1] < 0) {
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
  }
  else {
    uVar3 = _getvnodefp(*puVar1,&iStack_8);
    *(undefined *)(dword_40B57D4 + 100) = uVar3;
    if (*(char *)(dword_40B57D4 + 100) == '\0') {
      iVar2 = *(int *)(iStack_8 + 0x16);
      if ((*(byte *)(iStack_8 + 0xb) & 2) == 0) {
        *(undefined *)(dword_40B57D4 + 100) = 0x16;
      }
      else if ((*(byte *)(*(int *)(iVar2 + 0x24) + 0xf) & 1) == 0) {
        _vattr_null(auStack_42);
        uStack_2e = puVar1[1];
        uVar3 = (**(code **)(*(int *)(iVar2 + 0x1c) + 0x18))
                          (iVar2,auStack_42,*(undefined4 *)(iStack_8 + 0x1e));
        *(undefined *)(dword_40B57D4 + 100) = uVar3;
      }
      else {
        *(undefined *)(dword_40B57D4 + 100) = 0x1e;
      }
    }
  }
  return;
}
