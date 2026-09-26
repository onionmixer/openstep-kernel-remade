
void _pqinit(void)

{
  int iVar1;
  
  _proc_zone = _zinit(0x86,_max_proc * 0x3458,0,0,aProcStructures);
  dword_40B317C = 0;
  _freeproc = 0;
  iVar1 = _getproc();
  _bzero(iVar1,0x86);
  _allproc = iVar1;
  *(undefined4 *)(iVar1 + 8) = 0;
  *(int **)(iVar1 + 0xc) = &_allproc;
  _kernel_proc = iVar1;
  _zombproc = 0;
  return;
}

