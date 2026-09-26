
void _sethostid(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  iVar2 = _suser();
  if (iVar2 != 0) {
    _hostid = *puVar1;
  }
  return;
}
