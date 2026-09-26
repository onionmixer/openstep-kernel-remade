/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011807c */

int _sockargs(int *param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  if (param_3 < 0x71) {
    iVar2 = _m_get(1,param_4);
    if (iVar2 == 0) {
      iVar1 = 0x37;
    }
    else {
      *(short *)(iVar2 + 8) = (short)param_3;
      iVar1 = _copyin(param_2,iVar2 + *(int *)(iVar2 + 4),param_3);
      if (iVar1 == 0) {
        *param_1 = iVar2;
      }
      else {
        _m_free(iVar2);
      }
    }
  }
  else {
    iVar1 = 0x16;
  }
  return iVar1;
}

