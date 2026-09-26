
void _ptcclose(byte param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = (sword)(word)param_1 * 0xe;
  iVar1 = *(int *)((int)&dword_40B318E + iVar2);
  iVar3 = *(int *)((int)&dword_40B318A + iVar2);
  (**(code **)(DAT_40ae4d0 + *(char *)(iVar3 + 0x45) * 0x30))(iVar3,0);
  if ((*(byte *)((int)&unk_40B3184 + iVar2 + 5) & 1) != 0) {
    _forceclose((int)*(sword *)((int)&unk_40B3184 + iVar2));
    _ptsclose((int)*(sword *)((int)&unk_40B3184 + iVar2));
  }
  if (*(int *)(iVar1 + 4) != 0) {
    _selthreadclear(iVar1 + 4);
  }
  if (*(int *)(iVar1 + 8) != 0) {
    _selthreadclear(iVar1 + 8);
  }
  *(undefined4 *)(iVar3 + 0x24) = 0;
  iVar3 = _ttynty(iVar3);
  *(undefined4 *)(iVar3 + 8) = 0;
  return;
}

