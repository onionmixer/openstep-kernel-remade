
void sub_40870BA(int param_1)

{
  int iVar1;
  word wVar2;
  uint uVar3;
  sword sVar4;
  
  if (param_1 == _snd_var) {
    _snd_var = 0;
    uVar3 = 0x12;
    do {
      do {
        _port_deallocate(dword_40C6EC0,uVar3 | 0x10000);
        wVar2 = (word)(uVar3 >> 0x10);
        sVar4 = (sword)uVar3 + -1;
        uVar3 = CONCAT22(wVar2,sVar4);
      } while (sVar4 != -1);
      uVar3 = (uint)wVar2 * 0x10000 - 1;
    } while (wVar2 != 0);
    _port_deallocate(dword_40C6EC0,0x10013);
    _dsp_dev_reset_hard();
    if (dword_40C6E52 != 0) {
      _kfree(dword_40C6E52,dword_40C6E56 - dword_40C6E52 & 0xfffffffc);
      dword_40C6E5A = 0;
      dword_40C6E56 = 0;
      dword_40C6E52 = 0;
    }
    if (dword_40C6E5E != 0) {
      _kfree(dword_40C6E5E,dword_40C6E62 - dword_40C6E5E & 0xfffffffc);
      dword_40C6E66 = 0;
      dword_40C6E62 = 0;
      dword_40C6E5E = 0;
    }
  }
  iVar1 = _snd_get_owner(&dword_40C6E8C,param_1);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 4) != 0) {
      (*___NXAudioRemoveStream)(*(int *)(iVar1 + 4));
    }
    sub_4085CEA(&dword_40C6E8C,iVar1);
    if ((undefined4 **)dword_40C6E8C == &dword_40C6E8C) {
      _port_deallocate(dword_40C6EC0,0x10082);
    }
  }
  iVar1 = _snd_get_owner(&dword_40C6E94,param_1);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 4) != 0) {
      (*___NXAudioRemoveStream)(*(int *)(iVar1 + 4));
    }
    sub_4085CEA(&dword_40C6E94,iVar1);
    if ((undefined4 **)dword_40C6E94 == &dword_40C6E94) {
      _port_deallocate(dword_40C6EC0,0x10080);
      _port_deallocate(dword_40C6EC0,0x10081);
    }
  }
  if (((((undefined4 **)dword_40C6E8C == &dword_40C6E8C) &&
       ((undefined4 **)dword_40C6E94 == &dword_40C6E94)) && (_snd_var == 0)) &&
     (*(int *)(dword_40C6EBC + 0x24) != 0)) {
    _vm_deallocate(dword_40C6EBC,*(undefined4 *)(dword_40C6EBC + 0x10),
                   *(undefined4 *)(dword_40C6EBC + 0x14));
  }
  return;
}

