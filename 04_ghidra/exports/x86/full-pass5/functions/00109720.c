/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00109720 */

int _killpg1(char *param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int local_8;
  
  local_8 = 0;
  if (((param_3 != 0) || (param_2 != 0)) ||
     (param_2 = (int)*(short *)(*_active_u + 0x2e), param_2 != 0)) {
    iVar3 = 0;
    for (uVar1 = _allproc; uVar1 != 0; uVar1 = *(uint *)(uVar1 + 8)) {
      if ((((*(short *)(uVar1 + 0x2e) == param_2) || (param_3 != 0)) &&
          ((*(short *)(uVar1 + 0x32) != 0 && ((*(byte *)(uVar1 + 0x28) & 2) == 0)))) &&
         ((param_3 == 0 || (*_active_u != uVar1)))) {
        if ((*(short *)(_active_u[7] + 2) == 0) ||
           ((*(short *)(uVar1 + 0x2c) == *(short *)(_active_u[7] + 2) ||
            ((param_1 == (char *)0x13 && (iVar2 = _inferior(uVar1), iVar2 != 0)))))) {
          iVar3 = iVar3 + 1;
          if (param_1 != (char *)0x0) {
            _psignal(uVar1,param_1);
          }
        }
        else if (param_3 == 0) {
          local_8 = 1;
        }
      }
    }
    if (local_8 != 0) {
      return local_8;
    }
    if (iVar3 != 0) {
      return 0;
    }
  }
  return 3;
}

