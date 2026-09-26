/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001035f0 */

void _gatherstats(undefined4 param_1,uint param_2)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  
  if ((param_2 & 3) == 3) {
    iVar3 = 0;
    if ('\0' < *(char *)(*_active_u + 0x15)) {
      iVar3 = 1;
    }
  }
  else {
    iVar3 = 2;
    if ((*(char *)(_active_threads + 0x4c) < '\0') && ((char)(param_2 >> 8) == '\0')) {
      iVar3 = 3;
    }
  }
  (&_cp_time)[iVar3] = (&_cp_time)[iVar3] + 1;
  uVar1 = _dk_busy;
  uVar4 = 0;
  piVar2 = &_dk_time;
  do {
    if ((uVar1 >> (uVar4 & 0x1f) & 1) != 0) {
      *piVar2 = *piVar2 + 1;
    }
    piVar2 = piVar2 + 1;
    uVar4 = uVar4 + 1;
  } while ((int)uVar4 < 4);
  return;
}

