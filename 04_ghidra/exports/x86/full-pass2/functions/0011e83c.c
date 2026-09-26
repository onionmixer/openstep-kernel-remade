/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011e83c */

int _vn_remove(undefined4 param_1,undefined4 param_2,int param_3)

{
  short sVar1;
  int iVar2;
  code *pcVar3;
  undefined4 uVar4;
  int local_18;
  int local_14;
  undefined1 local_10 [4];
  undefined4 local_c;
  
  iVar2 = _pn_get(param_1,param_2,local_10);
  if (iVar2 != 0) {
    return iVar2;
  }
  local_18 = 0;
  iVar2 = _lookuppn(local_10,0,&local_14,&local_18);
  if (iVar2 != 0) {
    _pn_free(local_10);
    return iVar2;
  }
  if (local_18 == 0) {
    iVar2 = 2;
  }
  else if ((*(byte *)(*(int *)(local_18 + 0x24) + 0xc) & 1) == 0) {
    if ((*(byte *)(local_18 + 4) & 1) == 0) {
      _vnode_uncache(local_18);
      if (*(int *)(local_18 + 0x28) == 2) {
        if (param_3 != 1) {
          iVar2 = 1;
          goto LAB_0011e9c5;
        }
        if (*(int *)(local_18 + 0x10) != 0) {
          iVar2 = 0x42;
          goto LAB_0011e9c5;
        }
        if (*(short *)(local_18 + 6) == 0) {
                    /* WARNING: Subroutine does not return */
          _panic(s_vn_rele_001db786);
        }
        sVar1 = *(short *)(local_18 + 6);
        *(short *)(local_18 + 6) = sVar1 + -1;
        if (sVar1 == 1) {
          (**(code **)(*(int *)(local_18 + 0x1c) + 0x4c))
                    (local_18,*(undefined4 *)(_active_u + 0x1c));
        }
        uVar4 = *(undefined4 *)(_active_u + 0x1c);
        pcVar3 = *(code **)(*(int *)(local_14 + 0x1c) + 0x38);
      }
      else {
        if (param_3 != 0) {
          iVar2 = 0x14;
          goto LAB_0011e9c5;
        }
        if (*(short *)(local_18 + 6) == 0) {
                    /* WARNING: Subroutine does not return */
          _panic(s_vn_rele_001db786);
        }
        sVar1 = *(short *)(local_18 + 6);
        *(short *)(local_18 + 6) = sVar1 + -1;
        if (sVar1 == 1) {
          (**(code **)(*(int *)(local_18 + 0x1c) + 0x4c))
                    (local_18,*(undefined4 *)(_active_u + 0x1c));
        }
        uVar4 = *(undefined4 *)(_active_u + 0x1c);
        pcVar3 = *(code **)(*(int *)(local_14 + 0x1c) + 0x28);
      }
      local_18 = 0;
      iVar2 = (*pcVar3)(local_14,local_c,uVar4);
    }
    else {
      iVar2 = 0x10;
    }
  }
  else {
    iVar2 = 0x1e;
  }
LAB_0011e9c5:
  _pn_free(local_10);
  if (local_18 != 0) {
    if (*(short *)(local_18 + 6) == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_vn_rele_001db786);
    }
    sVar1 = *(short *)(local_18 + 6);
    *(short *)(local_18 + 6) = sVar1 + -1;
    if (sVar1 == 1) {
      (**(code **)(*(int *)(local_18 + 0x1c) + 0x4c))(local_18,*(undefined4 *)(_active_u + 0x1c));
    }
  }
  if (*(short *)(local_14 + 6) != 0) {
    sVar1 = *(short *)(local_14 + 6);
    *(short *)(local_14 + 6) = sVar1 + -1;
    if (sVar1 == 1) {
      (**(code **)(*(int *)(local_14 + 0x1c) + 0x4c))(local_14,*(undefined4 *)(_active_u + 0x1c));
    }
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_vn_rele_001db786);
}

