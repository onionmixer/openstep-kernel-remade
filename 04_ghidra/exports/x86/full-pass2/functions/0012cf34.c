/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012cf34 */

int _loadaddrs(uint *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  if (*param_1 < 0x401) {
    iVar4 = *param_1 << 4;
    uVar1 = param_1[1];
    if (iVar4 == 0) {
      param_1[1] = 0;
      iVar2 = 0;
    }
    else {
      uVar3 = _kalloc(iVar4);
      param_1[1] = uVar3;
      iVar2 = _copyin(uVar1,uVar3,iVar4);
      if (iVar2 != 0) {
        _kfree(param_1[1],iVar4);
      }
    }
  }
  else {
    iVar2 = 0x16;
  }
  return iVar2;
}

