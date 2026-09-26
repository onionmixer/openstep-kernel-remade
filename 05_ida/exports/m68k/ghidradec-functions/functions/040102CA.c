
void _ptsclose(byte param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (sword)(word)param_1 * 0xe;
  iVar1 = *(int *)((int)&dword_40B318A + iVar2);
  if ((*(byte *)((int)&DAT_40b3186 + iVar2 + 3) & 1) != 0) {
    (**(code **)(unk_40AE4B0 + *(char *)(iVar1 + 0x45) * 0x30))(iVar1);
    _ttyclose(iVar1);
    *(undefined4 *)((int)&DAT_40b3186 + iVar2) = 0;
  }
  _ptcwakeup(iVar1,3);
  return;
}
