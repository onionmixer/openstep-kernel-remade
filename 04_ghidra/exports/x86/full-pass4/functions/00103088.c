/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00103088 */

void _sysacct(void)

{
  int *piVar1;
  undefined1 uVar2;
  int iVar3;
  int local_8;
  
  piVar1 = *(int **)(DAT_001e875c + 0x24);
  iVar3 = _suser();
  if (iVar3 != 0) {
    if (_savacctp != 0) {
      _acctp = _savacctp;
      _savacctp = 0;
    }
    iVar3 = _acctp;
    if (*piVar1 == 0) {
      local_8 = _acctp;
      if (_acctp != 0) {
        _acctp = 0;
        _vn_rele(iVar3);
      }
    }
    else {
      uVar2 = _lookupname(*piVar1,0,1,0,&local_8);
      *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
      iVar3 = _acctp;
      if (*(char *)(DAT_001e875c + 0x68) == '\0') {
        if (*(int *)(local_8 + 0x28) == 1) {
          if ((*(byte *)(*(int *)(local_8 + 0x24) + 0xc) & 1) == 0) {
            if (_acctp == 0) {
              _acctp = local_8;
            }
            else {
              _acctp = local_8;
              _vn_rele(iVar3);
            }
            if (_acctcred != 0) {
              _crfree(_acctcred);
            }
            _acctcred = _crdup(*(undefined4 *)(_active_u + 0x1c));
            return;
          }
          *(undefined1 *)(DAT_001e875c + 0x68) = 0x1e;
        }
        else {
          *(undefined1 *)(DAT_001e875c + 0x68) = 0xd;
        }
        _vn_rele(local_8);
      }
    }
  }
  return;
}

