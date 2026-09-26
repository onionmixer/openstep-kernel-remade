
void _bind(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined uVar3;
  undefined4 uStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  iVar2 = _getsock(*puVar1);
  if (iVar2 != 0) {
    uVar3 = _sockargs(&uStack_8,puVar1[1],puVar1[2],8);
    *(undefined *)(dword_40B57D4 + 100) = uVar3;
    if (*(char *)(dword_40B57D4 + 100) == '\0') {
      uVar3 = _sobind(*(undefined4 *)(iVar2 + 0x16),uStack_8);
      *(undefined *)(dword_40B57D4 + 100) = uVar3;
      _m_freem(uStack_8);
    }
  }
  return;
}

