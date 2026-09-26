/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018cca4 */

void _mini_mon(char *param_1,undefined4 param_2,undefined1 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  bool bVar5;
  bool bVar6;
  
  uVar1 = _splhigh();
  iVar2 = 8;
  bVar5 = true;
  pcVar3 = param_1;
  pcVar4 = s_restart_001e22c8;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar5 = *pcVar3 == *pcVar4;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar5);
  iVar2 = 6;
  bVar6 = true;
  pcVar3 = param_1;
  pcVar4 = s_panic_001e22d0;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar6 = *pcVar3 == *pcVar4;
    pcVar3 = pcVar3 + 1;
    pcVar4 = pcVar4 + 1;
  } while (bVar6);
  if (bVar6 != false) {
    param_3 = &stack0xfffffffc;
  }
  if (!bVar5) {
    _DoAlert(param_2,s_panic_001e22d0 + 6);
  }
  else {
    _DoAlert(param_2,s_Restart_or_halt__Type_r_to_resta_001e227c);
  }
  if (bVar6 != false) {
    _kmdumplog();
  }
  if (!bVar5) {
    do {
      _miniMonLoop(param_1,bVar6,param_3);
    } while (bVar6 != false);
  }
  else {
    do {
      iVar2 = _kmtrygetc();
      if (iVar2 == 0x72) {
        if (_kernel_task == 0) {
          _boot(1,4);
        }
        else {
          _reboot_how = 0;
          _calloutDispatch(_halt_thread,0);
        }
      }
      if (iVar2 == 0x68) {
        if (_kernel_task == 0) {
          _boot(1,0xc);
        }
        else {
          _reboot_how = 8;
          _calloutDispatch(_halt_thread,0);
        }
      }
    } while (iVar2 == -1);
  }
  if (_nmi_stay == 0) {
    _DoRestore();
  }
  _nmi_stay = 0;
  _splx(uVar1);
  return;
}

