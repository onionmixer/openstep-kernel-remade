
/* WARNING: Type propagation algorithm not settling */

undefined4
_msg_rpc(int *******param_1,int ******param_2,int *******param_3,int ******param_4,
        int *******param_5)

{
  int *******pppppppiVar1;
  int *******pppppppiVar2;
  int *******pppppppiVar3;
  int ******ppppppiVar4;
  int iVar5;
  undefined4 uVar6;
  int *******pppppppiVar7;
  int *******pppppppiVar8;
  int *******pppppppiStack_4c;
  int *******pppppppiStack_48;
  int *******pppppppiStack_44;
  int *******pppppppiStack_40;
  int *******pppppppiStack_3c;
  int *******pppppppiStack_38;
  undefined auStack_c [4];
  int *******pppppppiStack_8;
  
  pppppppiVar1 = *(int ********)(*(int *)(_active_threads + 0xc) + 0x7c);
  pppppppiVar2 = *(int ********)(*(int *)(_active_threads + 0xc) + 8);
  pppppppiStack_40 = (int *******)((int)param_1[1] + 3U & 0xfffffffc);
  pppppppiStack_3c = (int *******)((int)param_1[1] - (int)pppppppiStack_40);
  if ((int *******)0x2000 < pppppppiStack_40) {
    return 0xffffff93;
  }
  pppppppiStack_38 = (int *******)&pppppppiStack_8;
  pppppppiStack_44 = param_1;
  pppppppiStack_48 = (int *******)0x4048e7a;
  iVar5 = _ipc_kmsg_get_from_kernel();
  pppppppiVar7 = (int *******)&stack0xffffffcc;
  if (iVar5 == 0) {
    pppppppiStack_40 = pppppppiStack_8;
    pppppppiStack_44 = (int *******)0x4048ea4;
    pppppppiStack_3c = pppppppiVar1;
    pppppppiStack_38 = pppppppiVar2;
    iVar5 = _ipc_kmsg_copyin_compat();
    if (iVar5 == 0) {
      pppppppiVar3 = (int *******)pppppppiStack_8[8];
      if ((pppppppiVar3 == (int *******)0x0) || (pppppppiVar3 == (int *******)0xffffffff)) {
loc_4048F6A:
        if (((uint)param_2 & 2) != 0) {
          pppppppiStack_38 = (int *******)aMsgRpcNotify;
                    /* WARNING: Subroutine does not return */
          pppppppiStack_3c = (int *******)0x4048f7c;
          _panic();
        }
        do {
          if (((uint)param_2 & 0x20) == 0) {
            pppppppiStack_40 = (int *******)0x0;
            if (((uint)param_2 & 1) != 0) {
              pppppppiStack_40 = (int *******)0x10;
            }
          }
          else {
            pppppppiStack_40 = (int *******)0x20000;
            if (((uint)param_2 & 1) != 0) {
              pppppppiStack_40 = (int *******)0x20010;
            }
          }
          pppppppiStack_38 = (int *******)0x0;
          pppppppiStack_3c = (int *******)param_4;
          pppppppiStack_44 = pppppppiStack_8;
          pppppppiStack_48 = (int *******)0x4048fb6;
          iVar5 = _ipc_mqueue_send();
          if (iVar5 != 0x10000007) break;
          while ((*(uint *)(_active_threads + 0x177) & 0x3ffffff) >> 0x18 != 0) {
            pppppppiStack_38 = (int *******)0x0;
            pppppppiStack_3c = (int *******)0x4048fce;
            _thread_halt_self_with_continuation();
          }
        } while (((uint)param_2 & 4) == 0);
        if (iVar5 == 0) {
loc_4049018:
          if ((pppppppiVar3 == (int *******)0x0) || (pppppppiVar3 == (int *******)0xffffffff)) {
            return 0xffffff36;
          }
          if (pppppppiVar1 != (int *******)pppppppiVar3[2]) {
            ppppppiVar4 = *pppppppiVar3;
            *pppppppiVar3 = (int ******)((int)ppppppiVar4 + -1);
            if (ppppppiVar4 != (int ******)0x1) {
              return 0xffffff36;
            }
            pppppppiStack_3c =
                 (int *******)(&_ipc_object_zones)[*(word *)(pppppppiVar3 + 1) & 0x7fff];
            pppppppiStack_40 = (int *******)0x4049052;
            pppppppiStack_38 = pppppppiVar3;
            _zfree();
            return 0xffffff36;
          }
          ppppppiVar4 = pppppppiVar3[0xb];
          if (ppppppiVar4 != (int ******)0x0) {
            if ((int)ppppppiVar4[1] < 0) {
              *pppppppiVar3 = (int ******)((int)*pppppppiVar3 + -1);
              return 0xffffff36;
            }
            pppppppiStack_40 = (int *******)0x4049076;
            pppppppiStack_3c = (int *******)ppppppiVar4;
            pppppppiStack_38 = pppppppiVar3;
            _ipc_pset_remove();
            if (*ppppppiVar4 == (int *****)0x0) {
              pppppppiStack_3c =
                   (int *******)(&_ipc_object_zones)[*(word *)(ppppppiVar4 + 1) & 0x7fff];
              pppppppiStack_40 = (int *******)0x4049098;
              pppppppiStack_38 = (int *******)ppppppiVar4;
              _zfree();
            }
          }
          pppppppiStack_38 = (int *******)auStack_c;
          pppppppiStack_3c = (int *******)&pppppppiStack_8;
          pppppppiStack_40 = (int *******)0x0;
          pppppppiStack_44 = (int *******)0x0;
          pppppppiStack_48 = param_5;
          pppppppiStack_4c = (int *******)0xffffffff;
          if (((uint)param_2 & 0x1000) != 0) {
            pppppppiStack_4c = param_3;
          }
          iVar5 = _ipc_mqueue_receive(pppppppiVar3 + 0xf,(uint)param_2 & 0x100);
          pppppppiStack_3c = (int *******)0x40490da;
          pppppppiStack_38 = pppppppiVar3;
          _ipc_object_release();
          if (iVar5 == 0) {
            if (param_3 < pppppppiStack_8[6]) {
              pppppppiStack_38 = pppppppiStack_8;
              pppppppiStack_3c = (int *******)0x404913e;
              _ipc_kmsg_destroy();
              pppppppiVar8 = (int *******)&pppppppiStack_3c;
              pppppppiStack_3c = (int *******)0x10004004;
              goto loc_4049174;
            }
            goto loc_4049146;
          }
          if (iVar5 == 0x10004005) {
            while ((*(uint *)(_active_threads + 0x177) & 0x3ffffff) >> 0x18 != 0) {
              pppppppiStack_38 = (int *******)0x0;
              pppppppiStack_3c = (int *******)0x40490f2;
              _thread_halt_self_with_continuation();
            }
            param_1[1] = (int ******)param_3;
            pppppppiVar7 = (int *******)&stack0xffffffcc;
            if (((uint)param_2 & 0x400) == 0) {
              pppppppiStack_38 = param_5;
              pppppppiStack_3c = (int *******)param_2;
              pppppppiStack_40 = param_1;
              pppppppiStack_44 = (int *******)0x404911a;
              uVar6 = _msg_receive();
              return uVar6;
            }
          }
          else {
            pppppppiVar7 = (int *******)&stack0xffffffcc;
            if (iVar5 == 0x10004004) {
              param_1[1] = (int ******)pppppppiStack_8;
              pppppppiVar7 = (int *******)&stack0xffffffcc;
            }
          }
        }
        else {
          pppppppiStack_38 = pppppppiStack_8;
          pppppppiStack_3c = (int *******)0x4048ffa;
          _ipc_kmsg_destroy();
          pppppppiVar7 = (int *******)&stack0xffffffcc;
          if ((pppppppiVar3 != (int *******)0x0) &&
             (pppppppiVar7 = (int *******)&stack0xffffffcc, pppppppiVar3 != (int *******)0xffffffff)
             ) {
            pppppppiStack_3c = (int *******)0x4049012;
            pppppppiStack_38 = pppppppiVar3;
            _ipc_object_release();
            pppppppiVar7 = (int *******)&stack0xffffffcc;
          }
        }
      }
      else {
        ppppppiVar4 = pppppppiStack_8[7];
        pppppppiStack_3c = (int *******)0x4048ee6;
        pppppppiStack_38 = pppppppiVar3;
        _ipc_object_reference();
        if (ppppppiVar4[2] != _ipc_space_kernel) goto loc_4048F6A;
        pppppppiStack_38 = pppppppiStack_8;
        pppppppiStack_3c = (int *******)0x4048efe;
        pppppppiStack_8 = (int *******)_ipc_kobject_server();
        if (pppppppiStack_8 == (int *******)0x0) goto loc_4049018;
        if (((((-1 < (int)pppppppiVar3[1]) || (pppppppiVar1 != (int *******)pppppppiVar3[2])) ||
             (pppppppiVar3[0xb] != (int ******)0x0)) ||
            ((param_3 < (int *******)((int)pppppppiStack_8[4] + (int)pppppppiStack_8[6]) ||
             (pppppppiVar3[0x10] != (int ******)0x0)))) || (pppppppiVar3[0xf] != (int ******)0x0)) {
          pppppppiStack_38 = (int *******)0x0;
          pppppppiStack_3c = (int *******)0x0;
          pppppppiStack_40 = (int *******)0x10000;
          pppppppiStack_48 = (int *******)0x4048f58;
          pppppppiStack_44 = pppppppiStack_8;
          _ipc_mqueue_send();
          goto loc_4049018;
        }
        pppppppiVar3[0xc] = (int ******)((int)pppppppiVar3[0xc] + 1);
        *pppppppiVar3 = (int ******)((int)*pppppppiVar3 + -1);
loc_4049146:
        pppppppiStack_40 = pppppppiStack_8;
        pppppppiStack_44 = (int *******)0x4049154;
        pppppppiStack_3c = pppppppiVar1;
        pppppppiStack_38 = pppppppiVar2;
        iVar5 = _ipc_kmsg_copyout_compat();
        pppppppiStack_44 = (int *******)((int)pppppppiStack_8[4] + (int)pppppppiStack_8[6]);
        pppppppiStack_8[6] = (int ******)pppppppiStack_44;
        pppppppiStack_48 = pppppppiStack_8;
        pppppppiStack_4c = param_1;
        _ipc_kmsg_put_to_kernel();
        pppppppiVar7 = (int *******)&pppppppiStack_4c;
      }
    }
    else {
      pppppppiStack_38 = (int *******)pppppppiStack_8[2];
      if ((int)pppppppiStack_38 < 1) {
        pppppppiStack_38 = pppppppiStack_8;
        pppppppiStack_3c = (int *******)0x4048ebe;
        _ipc_kmsg_free();
        pppppppiVar7 = (int *******)&stack0xffffffcc;
      }
      else {
        pppppppiStack_3c = pppppppiStack_8;
        pppppppiStack_40 = (int *******)0x4048e90;
        _kfree();
        pppppppiVar7 = (int *******)&stack0xffffffcc;
      }
    }
  }
  pppppppiVar8 = (int *******)((int)pppppppiVar7 + -4);
  *(int *)((int)pppppppiVar7 + -4) = iVar5;
loc_4049174:
  *(undefined4 *)((int)pppppppiVar8 + -4) = 0x404917a;
  uVar6 = _msg_return_translate();
  return uVar6;
}
