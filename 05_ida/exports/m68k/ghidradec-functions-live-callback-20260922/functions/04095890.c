
void _dbg_dispatch(void)

{
  int iVar1;
  
  iVar1 = dword_40B5610;
  if (dword_40B5610 != 0) {
    dword_40B5610 = 0;
    _dbg_longjmp(iVar1,dword_40B5630);
  }
                    /* WARNING: Subroutine does not return */
  _dbg_panic(aDebuggerScrewU);
}

