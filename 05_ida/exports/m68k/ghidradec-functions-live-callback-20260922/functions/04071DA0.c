
void _km_begin_access(void)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = dword_40B1BBE + 1;
  bVar2 = dword_40B1BBE == 0;
  dword_40B1BBE = iVar1;
  if ((bVar2) && (dword_40B6968 != 0)) {
    _km_run_pcode(dword_40B6968);
  }
  return;
}

