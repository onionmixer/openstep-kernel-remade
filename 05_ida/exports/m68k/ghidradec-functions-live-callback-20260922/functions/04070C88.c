
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _km_clear_screen(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = dword_40B6980;
  _km_begin_access();
  uVar1 = (uint)(_unk_40B694C * dword_40B6940) >> 2;
  iVar2 = 0;
  if (uVar1 != 0) {
    do {
      *puVar3 = dword_40B695C;
      iVar2 = iVar2 + 1;
      puVar3 = puVar3 + 1;
    } while (iVar2 < (int)uVar1);
  }
  _km_end_access();
  return;
}

