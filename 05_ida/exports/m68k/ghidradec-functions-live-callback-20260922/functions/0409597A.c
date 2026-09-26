
void _gdb_from_trap(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  dword_40B5628 = dword_40B5628 + 1;
  if (dword_40B5628 == 1) {
    word_40C9720 = word_40C9720 & 0xf000 | 8;
    dword_40B5630 = 1;
    dword_40B5634 = param_4;
    _bcopy(param_1,&dword_40C96D8,0x48);
    dword_40C971C = param_3;
    word_40C971A = (undefined2)param_2;
    if (dword_40C9474 != 0) {
      _nmi_prf(aGdbFromTrapPcX,param_3,dword_40C9714,param_2,param_4);
                    /* WARNING: Subroutine does not return */
      _dbg_dispatch();
    }
  }
  return;
}

