/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00195ec0 */

void _DoAlert(undefined4 param_1,char *param_2)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (_kmId == 0) {
    if (_kmAlertConsole == 0) {
      if ((_basicConsoleMode == 3) || (_basicConsoleMode == 1)) {
        if (_basicConsole != 0) {
          cVar2 = *param_2;
          while (cVar2 != '\0') {
            cVar2 = *param_2;
            param_2 = param_2 + 1;
            (**(code **)(_basicConsole + 0x14))(_basicConsole,(int)cVar2);
            cVar2 = *param_2;
          }
        }
      }
      else {
        _kmAlertConsole = _BasicAllocateConsole();
        if (_kmAlertConsole != 0) {
          (**(code **)(_kmAlertConsole + 4))(_kmAlertConsole,3,0,1,param_1);
          cVar2 = *param_2;
          while (cVar2 != '\0') {
            cVar2 = *param_2;
            param_2 = param_2 + 1;
            (**(code **)(_kmAlertConsole + 0x14))(_kmAlertConsole,(int)cVar2);
            cVar2 = *param_2;
          }
        }
      }
    }
  }
  else {
    (*DAT_001e776c)(*(undefined4 *)(_kmId + 0x108),PTR_s_lock_001f9220);
    iVar4 = _kmId;
    if ((*(int *)(_kmId + 0x114) != 1) && (*(int *)(_kmId + 0x114) != 3)) {
      if (DAT_001e7768 == 0) {
        uVar3 = _BasicAllocateConsole();
      }
      else {
        uVar3 = _objc_msgSend(DAT_001e7768,PTR_s_allocateConsoleInfo_001f949c);
      }
      *(undefined4 *)(iVar4 + 0x110) = uVar3;
      if (*(int *)(_kmId + 0x110) == 0) {
        *(int *)(_kmId + 0x110) = _basicConsole;
      }
      (**(code **)(*(int *)(_kmId + 0x110) + 4))(*(int *)(_kmId + 0x110),3,0,1,param_1);
      iVar4 = _kmId;
      *(undefined4 *)(_kmId + 0x118) = *(undefined4 *)(_kmId + 0x114);
      *(undefined4 *)(iVar4 + 0x114) = 3;
      piVar1 = (int *)(iVar4 + 0x11c);
      *piVar1 = *piVar1 + 1;
    }
    (*DAT_001e7770)(*(undefined4 *)(_kmId + 0x108),PTR_s_unlock_001f9474);
    if (*(int *)(_kmId + 0x114) == 3) {
      iVar4 = *(int *)(_kmId + 0x110);
    }
    else {
      iVar4 = *(int *)(_kmId + 0x10c);
    }
    for (; *param_2 != '\0'; param_2 = param_2 + 1) {
      (**(code **)(iVar4 + 0x14))(iVar4,(int)*param_2);
    }
  }
  return;
}

