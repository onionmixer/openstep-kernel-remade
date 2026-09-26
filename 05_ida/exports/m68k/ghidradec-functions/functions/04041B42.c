
void _ipc_right_clean(undefined4 param_1,undefined4 param_2,uint *param_3)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  uVar1 = *param_3;
  uVar4 = uVar1 & 0x1f0000;
  if (uVar4 == 0x30000) {
loc_4041BAA:
    piVar2 = (int *)param_3[1];
    iVar6 = 0;
    iVar7 = 0;
    if (piVar2[1] < 0) {
      if (param_3[2] == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = _ipc_right_dncancel(param_1,piVar2,param_2,param_3);
      }
      if ((((uVar1 & 0x10000) != 0) && (iVar3 = piVar2[6], piVar2[6] = iVar3 + -1, iVar3 == 1)) &&
         (iVar6 = piVar2[8], iVar6 != 0)) {
        piVar2[8] = 0;
        iVar7 = piVar2[5];
      }
      if ((uVar1 & 0x20000) == 0) {
        if ((uVar1 & 0x40000) == 0) {
          *piVar2 = *piVar2 + -1;
        }
        else {
          _ipc_notify_send_once(piVar2);
        }
      }
      else {
        _ipc_port_clear_receiver(piVar2);
        _ipc_port_destroy(piVar2);
      }
      if (iVar6 != 0) {
        _ipc_notify_no_senders(iVar6,iVar7);
      }
      if (iVar5 != 0) {
        _ipc_notify_port_deleted(iVar5,param_2);
      }
    }
    else {
      iVar6 = *piVar2;
      *piVar2 = iVar6 + -1;
      if (iVar6 == 1) {
        _zfree((&_ipc_object_zones)[*(word *)(piVar2 + 1) & 0x7fff],piVar2);
      }
    }
    return;
  }
  if (uVar4 < 0x30001) {
    if ((uVar4 == 0x10000) || (uVar4 == 0x20000)) goto loc_4041BAA;
  }
  else {
    if (uVar4 == 0x80000) {
      _ipc_pset_destroy(param_3[1]);
      return;
    }
    if (uVar4 < 0x80001) {
      if (uVar4 == 0x40000) goto loc_4041BAA;
    }
    else if (uVar4 == 0x100000) {
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  _panic(aIpcRightCleanS);
}
