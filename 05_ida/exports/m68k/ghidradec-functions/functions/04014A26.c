
void _listen(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined uVar3;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  iVar2 = _getsock(*puVar1);
  if (iVar2 != 0) {
    uVar3 = _solisten(*(undefined4 *)(iVar2 + 0x16),puVar1[1]);
    *(undefined *)(dword_40B57D4 + 100) = uVar3;
  }
  return;
}
