
void _boot(undefined4 param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  
  _md_prepare_for_shutdown(param_1,param_2,param_3);
  iVar2 = _acctp;
  if ((((param_2 & 4) == 0) && (_waittime < 0)) && (dword_40B57DC != 0)) {
    _waittime = 0;
    if (_acctp != 0) {
      _acctp = 0;
      _vn_rele(iVar2);
    }
    _sync();
    _unmount_all();
    _if_down_all();
    iVar2 = 0;
    iVar3 = 0;
    do {
      iVar1 = 0;
      for (puVar4 = _buf + _nbuf * 0x11 + -0x11; _buf <= puVar4; puVar4 = puVar4 + -0x11) {
        if ((*puVar4 & 10) == 8) {
          iVar1 = iVar1 + 1;
        }
      }
      if (iVar1 == 0) break;
      _printf(&aD,iVar1);
      if (iVar3 != iVar1) {
        iVar2 = 0;
      }
      _delay(iVar2 * 40000);
      iVar2 = iVar2 + 1;
      iVar3 = iVar1;
    } while (iVar2 < 0x14);
  }
  _md_shutdown_devices(param_1,param_2,param_3);
  _md_do_shutdown(param_1,param_2,param_3);
  return;
}
