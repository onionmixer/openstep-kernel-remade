
int _km_end_access(void)

{
  int iVar1;
  int iVar2;
  
  if (dword_40B1BBE != 0) {
    iVar1 = dword_40B1BBE + -1;
    iVar2 = dword_40B1BBE + -1;
    dword_40B1BBE = iVar1;
    if (0 < iVar2) {
      return iVar2;
    }
  }
  if (dword_40B696C != 0) {
    _km_run_pcode(dword_40B696C);
  }
  if ((byte_40B6953 & 2) != 0) {
    pushInvalidateCaches(1);
  }
  return 0;
}
