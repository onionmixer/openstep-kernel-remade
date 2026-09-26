
void _getrusage(void)

{
  int *piVar1;
  int iVar2;
  undefined uVar3;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  piVar1 = *(int **)(dword_40B57D4 + 0x24);
  iVar2 = *piVar1;
  if (iVar2 == -1) {
    iVar2 = _active_u + 0x1ae;
  }
  else {
    if (iVar2 != 0) {
      *(undefined *)(dword_40B57D4 + 100) = 0x16;
      return;
    }
    _thread_read_times(_active_threads,&uStack_c,&uStack_14);
    iVar2 = _active_u;
    *(undefined4 *)(_active_u + 0x166) = uStack_c;
    *(undefined4 *)(iVar2 + 0x16a) = uStack_8;
    iVar2 = _active_u;
    *(undefined4 *)(_active_u + 0x16e) = uStack_14;
    *(undefined4 *)(iVar2 + 0x172) = uStack_10;
    iVar2 = _active_u + 0x166;
  }
  uVar3 = _copyoutmsg(iVar2,piVar1[1],0x48);
  *(undefined *)(dword_40B57D4 + 100) = uVar3;
  return;
}

