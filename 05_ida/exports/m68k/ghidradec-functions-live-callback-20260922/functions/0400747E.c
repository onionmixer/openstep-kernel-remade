
void _setposix(void)

{
  uint uVar1;
  
  uVar1 = **(uint **)(dword_40B57D4 + 0x24);
  if (uVar1 < 2) {
    *(int *)(dword_40B57D4 + 0x5c) = (*(int *)(*_active_u + 0x16) << 1) >> 0x1f;
    *(uint *)(*_active_u + 0x16) = *(uint *)(*_active_u + 0x16) & 0xbfffffff | (uVar1 & 1) << 0x1e;
  }
  else {
    *(undefined4 *)(dword_40B57D4 + 0x5c) = 0xffffffff;
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
  }
  return;
}

