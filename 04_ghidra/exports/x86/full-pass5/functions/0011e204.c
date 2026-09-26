/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011e204 */

int _vn_create(undefined4 param_1,undefined4 param_2,int *param_3,int param_4,undefined4 param_5,
              int *param_6)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int local_14;
  undefined1 local_10 [4];
  undefined4 local_c;
  
  local_14 = 0;
  *param_6 = 0;
  iVar3 = _pn_get(param_1,param_2,local_10);
  if (iVar3 != 0) {
    return iVar3;
  }
  if ((param_4 == 1) && (*param_3 != 2)) {
    uVar4 = 0;
    piVar5 = (int *)0x0;
  }
  else {
    uVar4 = 1;
    piVar5 = param_6;
  }
  iVar3 = _lookuppn(local_10,uVar4,&local_14,piVar5);
  if (iVar3 != 0) {
    _pn_free(local_10);
    return iVar3;
  }
  if ((*param_6 != 0) && (*(int *)(*param_6 + 0x28) == 6)) {
    return 0x2d;
  }
  if ((*(byte *)(*(int *)(local_14 + 0x24) + 0xc) & 1) == 0) {
LAB_0011e2f8:
    iVar3 = 0;
    if ((param_4 == 0) && (iVar2 = *param_6, iVar2 != 0)) {
      if (((char)param_5 < '\0') &&
         (((*(byte *)(iVar2 + 4) & 2) != 0 &&
          (_vnode_uncache(iVar2), (*(byte *)(*param_6 + 4) & 2) != 0)))) {
        iVar3 = 0x1a;
      }
      iVar2 = *param_6;
      if (*(short *)(iVar2 + 6) == 0) {
                    /* WARNING: Subroutine does not return */
        _panic(s_vn_rele_001db786);
      }
      sVar1 = *(short *)(iVar2 + 6);
      *(short *)(iVar2 + 6) = sVar1 + -1;
      if (sVar1 == 1) {
        (**(code **)(*(int *)(iVar2 + 0x1c) + 0x4c))(iVar2,*(undefined4 *)(_active_u + 0x1c));
      }
    }
    if (iVar3 == 0) {
      if (*param_3 == 2) {
        iVar3 = *param_6;
        if (iVar3 == 0) {
          iVar3 = (**(code **)(*(int *)(local_14 + 0x1c) + 0x34))
                            (local_14,local_c,param_3,param_6,*(undefined4 *)(_active_u + 0x1c));
        }
        else {
          if (*(short *)(iVar3 + 6) == 0) {
                    /* WARNING: Subroutine does not return */
            _panic(s_vn_rele_001db786);
          }
          sVar1 = *(short *)(iVar3 + 6);
          *(short *)(iVar3 + 6) = sVar1 + -1;
          if (sVar1 == 1) {
            (**(code **)(*(int *)(iVar3 + 0x1c) + 0x4c))(iVar3,*(undefined4 *)(_active_u + 0x1c));
          }
          iVar3 = 0x11;
        }
      }
      else {
        iVar3 = (**(code **)(*(int *)(local_14 + 0x1c) + 0x24))
                          (local_14,local_c,param_3,param_4,param_5,param_6,
                           *(undefined4 *)(_active_u + 0x1c));
      }
    }
  }
  else {
    iVar3 = *param_6;
    if (iVar3 != 0) {
      if (*(int *)(iVar3 + 0x28) - 3U < 2) goto LAB_0011e2f8;
      if (*(short *)(iVar3 + 6) == 0) {
                    /* WARNING: Subroutine does not return */
        _panic(s_vn_rele_001db786);
      }
      sVar1 = *(short *)(iVar3 + 6);
      *(short *)(iVar3 + 6) = sVar1 + -1;
      if (sVar1 == 1) {
        (**(code **)(*(int *)(iVar3 + 0x1c) + 0x4c))(iVar3,*(undefined4 *)(_active_u + 0x1c));
      }
    }
    iVar3 = 0x1e;
  }
  _pn_free(local_10);
  if (*(short *)(local_14 + 6) != 0) {
    sVar1 = *(short *)(local_14 + 6);
    *(short *)(local_14 + 6) = sVar1 + -1;
    if (sVar1 == 1) {
      (**(code **)(*(int *)(local_14 + 0x1c) + 0x4c))(local_14,*(undefined4 *)(_active_u + 0x1c));
    }
    return iVar3;
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_vn_rele_001db786);
}

