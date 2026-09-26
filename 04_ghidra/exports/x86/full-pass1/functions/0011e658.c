/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011e658 */

int _vn_rename(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  int iVar2;
  int local_28;
  int local_24;
  int local_20;
  undefined1 local_1c [4];
  undefined4 local_18;
  undefined1 local_10 [4];
  undefined4 local_c;
  
  local_24 = 0;
  local_28 = 0;
  local_20 = 0;
  iVar2 = _pn_get(param_1,param_3,local_10);
  if (iVar2 == 0) {
    iVar2 = _pn_get(param_2,param_3,local_1c);
    if (iVar2 == 0) {
      iVar2 = _lookuppn(local_10,0,&local_20,&local_24);
      if (iVar2 == 0) {
        if (local_24 == 0) {
          iVar2 = 2;
        }
        else {
          iVar2 = _lookuppn(local_1c,0,&local_28,0);
          if (iVar2 == 0) {
            if (*(int *)(local_28 + 0x24) == *(int *)(local_24 + 0x24)) {
              if ((*(byte *)(*(int *)(local_24 + 0x24) + 0xc) & 1) == 0) {
                _vnode_uncache(local_28);
                iVar2 = (**(code **)(*(int *)(local_20 + 0x1c) + 0x30))
                                  (local_20,local_c,local_28,local_18,
                                   *(undefined4 *)(_active_u + 0x1c));
              }
              else {
                iVar2 = 0x1e;
              }
            }
            else {
              iVar2 = 0x12;
            }
          }
        }
      }
      _pn_free(local_10);
      _pn_free(local_1c);
      if (local_24 != 0) {
        if (*(short *)(local_24 + 6) == 0) {
                    /* WARNING: Subroutine does not return */
          _panic(s_vn_rele_001db786);
        }
        sVar1 = *(short *)(local_24 + 6);
        *(short *)(local_24 + 6) = sVar1 + -1;
        if (sVar1 == 1) {
          (**(code **)(*(int *)(local_24 + 0x1c) + 0x4c))
                    (local_24,*(undefined4 *)(_active_u + 0x1c));
        }
      }
      if (local_20 != 0) {
        if (*(short *)(local_20 + 6) == 0) {
                    /* WARNING: Subroutine does not return */
          _panic(s_vn_rele_001db786);
        }
        sVar1 = *(short *)(local_20 + 6);
        *(short *)(local_20 + 6) = sVar1 + -1;
        if (sVar1 == 1) {
          (**(code **)(*(int *)(local_20 + 0x1c) + 0x4c))
                    (local_20,*(undefined4 *)(_active_u + 0x1c));
        }
      }
      if (local_28 != 0) {
        if (*(short *)(local_28 + 6) == 0) {
                    /* WARNING: Subroutine does not return */
          _panic(s_vn_rele_001db786);
        }
        sVar1 = *(short *)(local_28 + 6);
        *(short *)(local_28 + 6) = sVar1 + -1;
        if (sVar1 == 1) {
          (**(code **)(*(int *)(local_28 + 0x1c) + 0x4c))
                    (local_28,*(undefined4 *)(_active_u + 0x1c));
        }
      }
    }
    else {
      _pn_free(local_10);
    }
  }
  return iVar2;
}

