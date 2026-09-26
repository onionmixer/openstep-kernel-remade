
void _sethostname(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined uVar3;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  iVar2 = _suser();
  if (iVar2 != 0) {
    if ((uint)puVar1[1] < 0x100) {
      _hostnamelen = puVar1[1];
      uVar3 = _copyinmsg(*puVar1,_hostname,puVar1[1]);
      *(undefined *)(dword_40B57D4 + 100) = uVar3;
      _hostname[_hostnamelen] = 0;
    }
    else {
      *(undefined *)(dword_40B57D4 + 100) = 0x16;
    }
  }
  return;
}

