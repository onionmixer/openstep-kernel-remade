/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019742c */

void _aprint(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char local_cc [200];
  
  pcVar3 = local_cc;
  _sprintf(pcVar3,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  do {
    iVar2 = (int)*pcVar3;
    pcVar3 = pcVar3 + 1;
    if (_kmId == 0) {
      iVar1 = _kmAlertConsole;
      if (_kmAlertConsole == 0) {
        iVar1 = _basicConsole;
      }
      if (iVar2 == 10) {
        (**(code **)(iVar1 + 0x14))(iVar1,0xd);
      }
      (**(code **)(iVar1 + 0x14))(iVar1,iVar2);
    }
    else {
      if (iVar2 == 10) {
        _objc_msgSend(_kmId,PTR_s_kmPutc__001f94a0,0xd);
      }
      _objc_msgSend(_kmId,PTR_s_kmPutc__001f94a0,iVar2);
    }
  } while (pcVar3 != (char *)0x0);
  return;
}

