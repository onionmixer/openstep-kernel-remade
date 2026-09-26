
void _sigpause(void)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  
  puVar2 = *(uint **)(dword_40B57D4 + 0x24);
  iVar1 = *_active_u;
  *(undefined4 *)((int)_active_u + 0x13a) = *(undefined4 *)(iVar1 + 0x1c);
  *(word *)(iVar1 + 0x2a) = *(word *)(iVar1 + 0x2a) | 0x200;
  if ((*(byte *)(*_active_u + 0x16) & 0x40) == 0) {
    uVar3 = *puVar2 & 0xfffafeff;
  }
  else {
    uVar3 = *puVar2 & 0xfffefeff;
  }
  *(uint *)(iVar1 + 0x1c) = uVar3;
  _sleep_with_continuation(&_active_u,0x28,_sigcont);
  return;
}

