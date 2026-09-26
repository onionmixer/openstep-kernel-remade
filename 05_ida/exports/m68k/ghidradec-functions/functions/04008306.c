
void _getrlimit(void)

{
  uint uVar1;
  undefined uVar2;
  
  uVar1 = **(uint **)(dword_40B57D4 + 0x24);
  if (uVar1 < 6) {
    uVar2 = _copyoutmsg(_active_u + uVar1 * 8 + 0x256,(*(uint **)(dword_40B57D4 + 0x24))[1],8);
    *(undefined *)(dword_40B57D4 + 100) = uVar2;
  }
  else {
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
  }
  return;
}
