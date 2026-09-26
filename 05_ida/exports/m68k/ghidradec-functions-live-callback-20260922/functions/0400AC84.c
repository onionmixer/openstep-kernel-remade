
void _getdomainname(void)

{
  uint uVar1;
  undefined uVar2;
  
  uVar1 = (*(undefined4 **)(dword_40B57D4 + 0x24))[1];
  if (_domainnamelen + 1U < uVar1) {
    uVar1 = _domainnamelen + 1U;
  }
  uVar2 = _copyoutmsg(_domainname,**(undefined4 **)(dword_40B57D4 + 0x24),uVar1);
  *(undefined *)(dword_40B57D4 + 100) = uVar2;
  return;
}

