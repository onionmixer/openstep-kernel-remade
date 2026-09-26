
undefined4
_ipc_right_rename(undefined4 param_1,undefined4 param_2,uint *param_3,undefined4 param_4,
                 uint *param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = *param_3;
  uVar2 = param_3[2];
  uVar4 = param_3[1];
  if (uVar2 != 0) {
    iVar1 = _ipc_right_check(param_1,uVar4,param_2,param_3);
    if (iVar1 == 0) {
      *(undefined4 *)(uVar2 * 8 + *(int *)(uVar4 + 0x28) + 4) = param_4;
      param_3[2] = 0;
    }
    else {
      if ((uVar3 & 0x400000) != 0) {
        _ipc_entry_dealloc(param_1,param_4,param_5);
        return 0xf;
      }
      uVar3 = *param_3;
      uVar2 = 0;
      uVar4 = 0;
    }
  }
  if ((uVar3 & 0x200000) != 0) {
    _ipc_marequest_rename(param_1,param_2,param_4);
  }
  *param_5 = uVar3 & 0x7fffff | *param_5;
  param_5[2] = uVar2;
  param_5[1] = uVar4;
  uVar3 = uVar3 & 0x1f0000;
  if (uVar3 != 0x30000) {
    if (0x30000 < uVar3) {
      if (uVar3 == 0x80000) {
        *(undefined4 *)(uVar4 + 8) = param_4;
      }
      else if (uVar3 < 0x80001) {
        if (uVar3 != 0x40000) {
loc_4042B06:
                    /* WARNING: Subroutine does not return */
          _panic(aIpcRightRename);
        }
      }
      else if (uVar3 != 0x100000) goto loc_4042B06;
      goto loc_4042B14;
    }
    if (uVar3 == 0x10000) {
      _ipc_hash_delete(param_1,uVar4,param_2,param_3);
      _ipc_hash_insert(param_1,uVar4,param_4,param_5);
      goto loc_4042B14;
    }
    if (uVar3 != 0x20000) goto loc_4042B06;
  }
  *(undefined4 *)(uVar4 + 0xc) = param_4;
loc_4042B14:
  param_3[1] = 0;
  _ipc_entry_dealloc(param_1,param_2,param_3);
  return 0;
}
