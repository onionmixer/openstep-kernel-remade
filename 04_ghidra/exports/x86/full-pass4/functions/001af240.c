/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001af240 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_001af240(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  undefined *local_8;
  
  uVar1 = _objc_msgSend(PTR_s_NXLock_001f9da4,PTR_s_new_001f9468);
  *(undefined4 *)(param_1 + 0x110) = uVar1;
  uVar1 = _objc_msgSend(PTR_s_NXLock_001f9da4,PTR_s_new_001f9468);
  *(undefined4 *)(param_1 + 0x170) = uVar1;
  uVar1 = _objc_msgSend(PTR_s_NXLock_001f9da4,PTR_s_new_001f9468);
  *(undefined4 *)(param_1 + 0x20c) = uVar1;
  uVar1 = _task_self(param_1 + 0x134);
  iVar2 = _port_allocate_EXTERNAL(uVar1);
  if (iVar2 == 0) {
    uVar1 = _task_self(param_1 + 0x138);
    iVar2 = _port_allocate_EXTERNAL(uVar1);
    if (iVar2 == 0) {
      uVar1 = _task_self(param_1 + 0x13c);
      iVar2 = _port_allocate_EXTERNAL(uVar1);
      if (iVar2 == 0) {
        _ev_port_list = _IOGetKernPort(*(undefined4 *)(param_1 + 0x134));
        _DAT_001ded04 = _IOGetKernPort(*(undefined4 *)(param_1 + 0x138));
        uVar1 = _IOGetKernPort(*(undefined4 *)(param_1 + 0x13c));
        *(undefined4 *)(param_1 + 0x140) = uVar1;
        uVar1 = _task_self(param_1 + 0x148);
        iVar2 = _port_set_allocate_EXTERNAL(uVar1);
        if (iVar2 == 0) {
          uVar1 = _task_self(*(undefined4 *)(param_1 + 0x148),*(undefined4 *)(param_1 + 0x134));
          iVar2 = _port_set_add_EXTERNAL(uVar1);
          if (iVar2 == 0) {
            uVar1 = _task_self(*(undefined4 *)(param_1 + 0x148),*(undefined4 *)(param_1 + 0x138));
            iVar2 = _port_set_add_EXTERNAL(uVar1);
            if (iVar2 == 0) {
              uVar1 = _task_self(*(undefined4 *)(param_1 + 0x148),*(undefined4 *)(param_1 + 0x13c));
              iVar2 = _port_set_add_EXTERNAL(uVar1);
              if (iVar2 == 0) {
                *(int *)(param_1 + 0x178) = param_1 + 0x174;
                *(int *)(param_1 + 0x174) = param_1 + 0x174;
                local_c = param_1;
                local_8 = PTR_s_IODevice_001fa400;
                _objc_msgSendSuper(&local_c,PTR_s_init_001f924c);
                *(undefined2 *)(param_1 + 0x1a8) = 100;
                *(undefined2 *)(param_1 + 0x1aa) = 100;
                uVar1 = _IOForkThread(FUN_001b0858,param_1);
                _IOSetThreadPolicy(uVar1,2);
                _IOSetThreadPriority(uVar1,0x1c);
                if (*(char *)(param_1 + 0x108) != '\0') {
                  return param_1;
                }
                _objc_msgSend(param_1,PTR_s_registerDevice_001f948c);
                *(undefined1 *)(param_1 + 0x108) = 1;
                return param_1;
              }
            }
          }
        }
      }
    }
  }
  return 0;
}

