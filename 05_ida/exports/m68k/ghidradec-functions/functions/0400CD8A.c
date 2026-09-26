
void _ttychars(int param_1)

{
  int iVar1;
  
  iVar1 = _ttynty(param_1);
  *(undefined4 *)(param_1 + 0x4c) = _ttydefaults;
  *(undefined4 *)(param_1 + 0x50) = dword_40AE4A2;
  *(undefined4 *)(param_1 + 0x54) = dword_40AE4A6;
  *(undefined2 *)(param_1 + 0x58) = word_40AE4AA;
  *(undefined *)(iVar1 + 0x14) = 0x5c;
  *(undefined *)(iVar1 + 0x15) = 1;
  *(undefined *)(iVar1 + 0x16) = 0;
  _ttysetspec(iVar1);
  return;
}
