
int _logclose(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char in_XF;
  
  uVar2 = dword_40B67F0;
  _log_open = 0;
  dword_40B67F0 = 0;
  _calloutEntryRemove(uVar2);
  _calloutEntryFree(uVar2);
  iVar1 = dword_40B67E8;
  _logsoftc = 0;
  iVar3 = (int)(sword)(word)(byte)(in_XF << 4 | 4);
  dword_40B67E8 = 0;
  if (iVar1 != 0) {
    iVar3 = _thread_deallocate(iVar1);
  }
  dword_40B67EC = 0;
  return iVar3;
}

