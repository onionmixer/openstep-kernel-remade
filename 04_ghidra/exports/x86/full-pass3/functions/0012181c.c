/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012181c */

undefined4 _raw_usrreq(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  
  iVar1 = *(int *)(param_1 + 8);
  uVar4 = 0;
  if (param_2 == 0xb) {
LAB_00121a32:
    return 0x2d;
  }
  if ((param_5 != 0) && (*(short *)(param_5 + 8) != 0)) {
switchD_00121871_caseD_3:
    uVar4 = 0x2d;
    goto LAB_00121a21;
  }
  if ((iVar1 == 0) && (param_2 != 0)) goto LAB_0012191e;
  switch(param_2) {
  case 0:
    if (-1 < *(char *)(param_1 + 6)) {
      uVar4 = 0xd;
      break;
    }
    if (iVar1 == 0) {
      uVar4 = _raw_attach(param_1,param_4);
      break;
    }
    goto LAB_0012191e;
  case 1:
    if (iVar1 != 0) {
      _raw_detach(iVar1);
      break;
    }
    goto LAB_00121992;
  case 2:
    if ((*(byte *)(iVar1 + 0x4c) & 1) == 0) {
      uVar4 = _raw_bind(param_1,param_4);
      break;
    }
LAB_0012191e:
    uVar4 = 0x16;
    break;
  case 3:
  case 5:
  case 0xe:
  case 0x11:
    goto switchD_00121871_caseD_3;
  case 4:
    if ((*(byte *)(iVar1 + 0x4c) & 2) == 0) {
      _raw_connaddr(iVar1,param_4);
      _soisconnected(param_1);
      break;
    }
LAB_00121976:
    uVar4 = 0x38;
    break;
  case 6:
    if ((*(byte *)(iVar1 + 0x4c) & 2) != 0) {
      _raw_disconnect(iVar1);
      _soisdisconnected(param_1);
      break;
    }
    goto LAB_00121992;
  case 7:
    _socantsendmore(param_1);
    break;
  case 8:
  case 0xd:
    goto LAB_00121a32;
  case 9:
    if (param_4 != 0) {
      if ((*(byte *)(iVar1 + 0x4c) & 2) == 0) {
        _raw_connaddr(iVar1,param_4);
LAB_0012199c:
        uVar4 = (**(code **)(*(int *)(param_1 + 0xc) + 0x10))(param_3,param_1);
        param_3 = 0;
        if (param_4 != 0) {
          *(byte *)(iVar1 + 0x4c) = *(byte *)(iVar1 + 0x4c) & 0xfd;
        }
        break;
      }
      goto LAB_00121976;
    }
    if ((*(byte *)(iVar1 + 0x4c) & 2) != 0) goto LAB_0012199c;
LAB_00121992:
    uVar4 = 0x39;
    break;
  case 10:
    _raw_disconnect(iVar1);
    _sofree(param_1);
    _soisdisconnected(param_1);
    break;
  default:
                    /* WARNING: Subroutine does not return */
    _panic(s_raw_usrreq_001db940);
  case 0xc:
    return 0;
  case 0xf:
    iVar2 = *(int *)(param_4 + 4);
    pvVar3 = (void *)(iVar1 + 0x1c);
    goto LAB_00121a03;
  case 0x10:
    iVar2 = *(int *)(param_4 + 4);
    pvVar3 = (void *)(iVar1 + 0xc);
LAB_00121a03:
    _bcopy(pvVar3,(void *)(param_4 + iVar2),0x10);
    *(undefined2 *)(param_4 + 8) = 0x10;
  }
LAB_00121a21:
  if (param_3 != 0) {
    _m_freem(param_3);
  }
  return uVar4;
}

