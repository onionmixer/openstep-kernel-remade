
undefined4
_ipc_right_copyin_two
          (undefined4 param_1,undefined4 param_2,uint *param_3,uint *param_4,undefined4 *param_5)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar3 = *param_3;
  uVar4 = 0;
  if (((uVar3 & 0x10000) != 0) && (1 < (uVar3 & 0xffff))) {
    piVar1 = (int *)param_3[1];
    iVar2 = _ipc_right_check(param_1,piVar1,param_2,param_3);
    if (iVar2 == 0) {
      if ((uVar3 & 0xffff) == 2) {
        if ((uVar3 & 0x20000) == 0) {
          if (param_3[2] != 0) {
            uVar4 = _ipc_right_dncancel(param_1,piVar1,param_2,param_3);
          }
          _ipc_hash_delete(param_1,piVar1,param_2,param_3);
          if ((uVar3 & 0x200000) != 0) {
            _ipc_marequest_cancel(param_1,param_2);
          }
          piVar1[6] = piVar1[6] + 1;
          *piVar1 = *piVar1 + 1;
          param_3[1] = 0;
        }
        else {
          piVar1[6] = piVar1[6] + 1;
          *piVar1 = *piVar1 + 2;
        }
        uVar3 = uVar3 & 0xfffe0000;
      }
      else {
        piVar1[6] = piVar1[6] + 2;
        *piVar1 = *piVar1 + 2;
        uVar3 = uVar3 - 2;
      }
      *param_3 = uVar3;
      *param_4 = (uint)piVar1;
      *param_5 = uVar4;
      return 0;
    }
    if ((uVar3 & 0x400000) != 0) {
      return 0xf;
    }
  }
  return 0x11;
}
