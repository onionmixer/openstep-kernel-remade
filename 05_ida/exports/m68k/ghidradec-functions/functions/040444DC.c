
/* WARNING: Type propagation algorithm not settling */

uint _mach_msg_receive(int param_1,uint param_2,code **param_3,undefined4 param_4,undefined4 param_5
                      ,int param_6)

{
  undefined4 ***pppuVar1;
  code ***pppcVar2;
  int iVar3;
  uint uVar4;
  code ****ppppcVar5;
  code ***pppcStack_4c;
  undefined4 ****ppppuStack_48;
  undefined4 ****ppppuStack_44;
  undefined4 ***pppuStack_40;
  code ***pppcStack_18;
  code **ppcStack_14;
  code ***pppcStack_10;
  undefined4 uStack_c;
  code **ppcStack_8;
  
  iVar3 = _active_threads;
  pppuVar1 = *(undefined4 ****)(*(int *)(_active_threads + 0xc) + 0x7c);
  pppcVar2 = *(code ****)(*(int *)(_active_threads + 0xc) + 8);
  pppuStack_40 = (undefined4 ***)&uStack_c;
  ppppuStack_44 = (undefined4 ****)&ppcStack_8;
  ppppuStack_48 = (undefined4 ****)param_4;
  pppcStack_4c = (code ***)pppuVar1;
  uVar4 = _ipc_mqueue_copyin();
  if (uVar4 != 0) {
    return uVar4;
  }
  *(int *)(iVar3 + 0xbc) = param_1;
  *(uint *)(iVar3 + 0xc0) = param_2;
  *(code ***)(iVar3 + 0xc4) = param_3;
  *(undefined4 *)(iVar3 + 200) = param_5;
  *(int *)(iVar3 + 0xcc) = param_6;
  *(undefined4 *)(iVar3 + 0xd0) = uStack_c;
  *(code ***)(iVar3 + 0xd4) = ppcStack_8;
  if ((param_2 & 0x800) == 0) {
    pppuStack_40 = (undefined4 ***)&ppcStack_14;
    ppppuStack_44 = (undefined4 ****)&pppcStack_10;
    ppppuStack_48 = (undefined4 ****)_mach_msg_receive_continue;
    pppcStack_4c = (code ***)0x0;
    uVar4 = _ipc_mqueue_receive(ppcStack_8,param_2 & 0x100,0xffffffff,param_5);
    pppuStack_40 = (undefined4 ***)uStack_c;
    ppppuStack_44 = (undefined4 ****)0x40445f6;
    _ipc_object_release();
    if (uVar4 != 0) {
      return uVar4;
    }
    pppcStack_10[9] = ppcStack_14;
    if (param_3 < pppcStack_10[6]) {
      ppppuStack_44 = (undefined4 ****)pppcStack_10;
      ppppuStack_48 = (undefined4 ****)0x404461c;
      pppuStack_40 = pppuVar1;
      _ipc_kmsg_copyout_dest();
      ppppuStack_48 = (undefined4 ****)0x18;
      pppcStack_4c = pppcStack_10;
      _ipc_kmsg_put(param_1);
      return 0x10004004;
    }
  }
  else {
    pppuStack_40 = (undefined4 ***)&ppcStack_14;
    ppppuStack_44 = (undefined4 ****)&pppcStack_10;
    ppppuStack_48 = (undefined4 ****)_mach_msg_receive_continue;
    pppcStack_4c = (code ***)0x0;
    uVar4 = _ipc_mqueue_receive(ppcStack_8,param_2 & 0x100,param_3,param_5);
    pppuStack_40 = (undefined4 ***)uStack_c;
    ppppuStack_44 = (undefined4 ****)0x4044588;
    _ipc_object_release();
    if (uVar4 != 0) {
      if (uVar4 != 0x10004004) {
        return uVar4;
      }
      pppcStack_18 = pppcStack_10;
      pppuStack_40 = (undefined4 ***)0x4;
      ppppuStack_44 = (undefined4 ****)(param_1 + 4);
      ppppuStack_48 = (undefined4 ****)&pppcStack_18;
      pppcStack_4c = (code ***)0x40445ae;
      _copyoutmsg();
      return 0x10004004;
    }
    pppcStack_10[9] = ppcStack_14;
  }
  if ((param_2 & 0x200) == 0) {
    pppuStack_40 = (undefined4 ***)0x0;
  }
  else {
    if (param_6 == 0) {
      uVar4 = 0x10004007;
      goto loc_4044664;
    }
    pppuStack_40 = (undefined4 ***)param_6;
  }
  pppcStack_4c = pppcStack_10;
  ppppuStack_48 = (undefined4 ****)pppuVar1;
  ppppuStack_44 = (undefined4 ****)pppcVar2;
  uVar4 = _ipc_kmsg_copyout();
  if (uVar4 == 0) {
    pppuStack_40 = (undefined4 ***)((int)pppcStack_10[4] + (int)pppcStack_10[6]);
    ppppuStack_44 = (undefined4 ****)pppcStack_10;
    ppppuStack_48 = (undefined4 ****)param_1;
    pppcStack_4c = (code ***)0x40446bc;
    uVar4 = _ipc_kmsg_put();
    return uVar4;
  }
loc_4044664:
  if ((uVar4 & 0xffffc3ff) == 0x1000400c) {
    pppuStack_40 = (undefined4 ***)((int)pppcStack_10[4] + (int)pppcStack_10[6]);
    ppppcVar5 = (code ****)&ppppuStack_44;
    ppppuStack_44 = (undefined4 ****)pppcStack_10;
  }
  else {
    ppppuStack_44 = (undefined4 ****)pppcStack_10;
    ppppuStack_48 = (undefined4 ****)0x4044690;
    pppuStack_40 = pppuVar1;
    _ipc_kmsg_copyout_dest();
    ppppuStack_48 = (undefined4 ****)0x18;
    ppppcVar5 = &pppcStack_4c;
    pppcStack_4c = pppcStack_10;
  }
  *(int *)((int)ppppcVar5 + -4) = param_1;
  *(undefined4 *)((int)ppppcVar5 + -8) = 0x40446a0;
  _ipc_kmsg_put();
  return uVar4;
}
