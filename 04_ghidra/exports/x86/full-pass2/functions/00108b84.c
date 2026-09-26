/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00108b84 */

void _boot(undefined4 param_1,uint param_2,undefined4 param_3)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int local_8;
  
  _md_prepare_for_shutdown(param_1,param_2,param_3);
  iVar3 = _acctp;
  if ((((param_2 & 4) == 0) && (_waittime < 0)) && (DAT_001e8764 != 0)) {
    _waittime = 0;
    if (_acctp != 0) {
      _acctp = 0;
      _vn_rele(iVar3);
    }
    _sync();
    _unmount_all();
    _if_down_all();
    local_8 = 0;
    iVar3 = 0;
    do {
      iVar2 = 0;
      for (puVar1 = _buf + _nbuf * 0x11 + -0x11; _buf <= puVar1; puVar1 = puVar1 + -0x11) {
        if ((*puVar1 & 10) == 8) {
          iVar2 = iVar2 + 1;
        }
      }
      if (iVar2 == 0) break;
      _printf(&DAT_001da994,iVar2);
      if (local_8 != iVar2) {
        iVar3 = 0;
      }
      _us_spin(iVar3 * 40000);
      iVar3 = iVar3 + 1;
      local_8 = iVar2;
    } while (iVar3 < 0x14);
  }
  _md_shutdown_devices(param_1,param_2,param_3);
  _md_do_shutdown(param_1,param_2,param_3);
  return;
}

