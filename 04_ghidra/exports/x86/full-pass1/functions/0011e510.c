/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011e510 */

int _vn_link(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  int iVar2;
  int local_18;
  int local_14;
  undefined1 local_10 [4];
  undefined4 local_c;
  
  local_18 = 0;
  local_14 = 0;
  iVar2 = _pn_get(param_2,param_3,local_10);
  if (iVar2 == 0) {
    iVar2 = _lookupname(param_1,param_3,1,0,&local_14);
    if ((iVar2 == 0) && (iVar2 = _lookuppn(local_10,1,&local_18,0), iVar2 == 0)) {
      if (*(int *)(local_18 + 0x24) == *(int *)(local_14 + 0x24)) {
        if ((*(byte *)(*(int *)(local_14 + 0x24) + 0xc) & 1) == 0) {
          iVar2 = (**(code **)(*(int *)(local_18 + 0x1c) + 0x2c))
                            (local_14,local_18,local_c,*(undefined4 *)(_active_u + 0x1c));
        }
        else {
          iVar2 = 0x1e;
        }
      }
      else {
        iVar2 = 0x12;
      }
    }
    _pn_free(local_10);
    if (local_14 != 0) {
      if (*(short *)(local_14 + 6) == 0) {
                    /* WARNING: Subroutine does not return */
        _panic(s_vn_rele_001db786);
      }
      sVar1 = *(short *)(local_14 + 6);
      *(short *)(local_14 + 6) = sVar1 + -1;
      if (sVar1 == 1) {
        (**(code **)(*(int *)(local_14 + 0x1c) + 0x4c))(local_14,*(undefined4 *)(_active_u + 0x1c));
      }
    }
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
  }
  return iVar2;
}

