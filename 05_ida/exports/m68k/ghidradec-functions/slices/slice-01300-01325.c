/* GHIDRADEC_FUNCTION index=1300 start=0x404882c */

void _ipc_kobject_destroy(int param_1)

{
  word wVar1;
  
  wVar1 = *(word *)(param_1 + 6);
  if (wVar1 == 9) {
    _vm_object_pager_wakeup(param_1);
  }
  else if (wVar1 < 10) {
    if (wVar1 == 8) {
      _vm_object_destroy(param_1);
    }
  }
  else if (wVar1 == 0x11) {
    _netipc_ignore(0,param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1301 start=0x4048874 */

undefined4 _ipc_kobject_notify(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 8);
  *(undefined4 *)(param_2 + 0x1c) = 0xfffffecf;
  iVar2 = *(int *)(param_1 + 0x14);
  if ((iVar2 < 0x41) ||
     (((0x42 < iVar2 && ((0x48 < iVar2 || (iVar2 < 0x45)))) || (*(sword *)(iVar1 + 6) != 0xc)))) {
    uVar3 = 0;
  }
  else {
    uVar3 = _ds_notify(param_1);
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=1302 start=0x40488c6 */

undefined4 _mach_msg_send_from_kernel(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uStack_8;
  
  if ((*(int *)(param_1 + 8) == 0) || (*(int *)(param_1 + 8) == -1)) {
    uVar1 = 0x10000003;
  }
  else {
    iVar2 = _ipc_kmsg_get_from_kernel(param_1,param_2,0,&uStack_8);
    if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(aMachMsgSendFro);
    }
    _ipc_kmsg_copyin_from_kernel(uStack_8);
    _ipc_mqueue_send(uStack_8,0x10000,0,0);
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1303 start=0x404892e */

void _mach_msg_abort_rpc(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (*(int *)(param_1 + 0xa4) != 0) {
    iVar1 = *(int *)(param_1 + 0xb8);
    *(undefined4 *)(param_1 + 0xb8) = 0;
  }
  if (iVar1 != 0) {
    _ipc_port_dealloc_special(iVar1,_ipc_space_reply);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1304 start=0x404895c */

uint _mach_msg(undefined4 ***param_1,uint param_2,undefined4 param_3,int **param_4,
              undefined4 param_5)

{
  undefined4 ***pppuVar1;
  int ***pppiVar2;
  int iVar3;
  uint uVar4;
  int ****ppppiVar5;
  undefined4 ***pppuStack_3c;
  int **ppiStack_38;
  int ***pppiStack_34;
  int ***pppiStack_30;
  undefined4 **ppuStack_14;
  undefined4 uStack_10;
  undefined4 **ppuStack_c;
  undefined4 ***pppuStack_8;
  
  pppuVar1 = *(undefined4 ****)(*(int *)(_active_threads + 0xc) + 0x7c);
  pppiVar2 = *(int ****)(*(int *)(_active_threads + 0xc) + 8);
  if ((param_2 & 1) != 0) {
    pppiStack_30 = (int ***)&pppuStack_8;
    pppiStack_34 = (int ***)0x0;
    ppiStack_38 = (int **)param_3;
    pppuStack_3c = param_1;
    iVar3 = _ipc_kmsg_get_from_kernel();
    if (iVar3 != 0) {
      pppiStack_30 = (int ***)aMachMsg;
                    /* WARNING: Subroutine does not return */
      pppiStack_34 = (int ***)0x40489ae;
      _panic();
    }
    pppiStack_30 = (int ***)0x0;
    pppuStack_3c = pppuStack_8;
    ppiStack_38 = (int **)pppuVar1;
    pppiStack_34 = pppiVar2;
    uVar4 = _ipc_kmsg_copyin();
    if (uVar4 != 0) {
      pppiStack_30 = (int ***)pppuStack_8[2];
      if ((int)pppiStack_30 < 1) {
        pppiStack_30 = pppuStack_8;
        pppiStack_34 = (int ***)0x40489da;
        _ipc_kmsg_free();
        return uVar4;
      }
      pppiStack_34 = pppuStack_8;
      ppiStack_38 = (int **)0x40489e8;
      _kfree();
      return uVar4;
    }
    do {
      pppiStack_30 = (int ***)0x0;
      pppiStack_34 = (int ***)0x0;
      ppiStack_38 = (int **)0x0;
      pppuStack_3c = pppuStack_8;
      iVar3 = _ipc_mqueue_send();
    } while (iVar3 == 0x10000007);
  }
  if ((param_2 & 2) != 0) {
    do {
      pppiStack_30 = (int ***)&uStack_10;
      pppiStack_34 = &ppuStack_c;
      ppiStack_38 = (int **)param_5;
      pppuStack_3c = pppuVar1;
      uVar4 = _ipc_mqueue_copyin();
      if (uVar4 != 0) {
        return uVar4;
      }
      pppiStack_30 = &ppuStack_14;
      pppiStack_34 = (int ***)&pppuStack_8;
      ppiStack_38 = (int **)0x0;
      pppuStack_3c = (undefined4 ***)0x0;
      uVar4 = _ipc_mqueue_receive(ppuStack_c,0,0xffffffff,0);
      pppiStack_30 = (int ***)uStack_10;
      pppiStack_34 = (int ***)0x4048a56;
      _ipc_object_release();
    } while (uVar4 == 0x10004005);
    if (uVar4 != 0) {
      return uVar4;
    }
    pppuStack_8[9] = ppuStack_14;
    if (param_4 < pppuStack_8[6]) {
      pppiStack_34 = pppuStack_8;
      ppiStack_38 = (int **)0x4048a88;
      pppiStack_30 = pppuVar1;
      _ipc_kmsg_copyout_dest();
      ppiStack_38 = (int **)0x18;
      pppuStack_3c = pppuStack_8;
      _ipc_kmsg_put_to_kernel(param_1);
      return 0x10004004;
    }
    pppiStack_30 = (int ***)0x0;
    pppuStack_3c = pppuStack_8;
    ppiStack_38 = (int **)pppuVar1;
    pppiStack_34 = pppiVar2;
    uVar4 = _ipc_kmsg_copyout();
    if (uVar4 != 0) {
      if ((uVar4 & 0xffffc3ff) == 0x1000400c) {
        pppiStack_30 = (int ***)((int)pppuStack_8[4] + (int)pppuStack_8[6]);
        ppppiVar5 = &pppiStack_34;
        pppiStack_34 = pppuStack_8;
      }
      else {
        pppiStack_34 = pppuStack_8;
        ppiStack_38 = (int **)0x4048ae0;
        pppiStack_30 = pppuVar1;
        _ipc_kmsg_copyout_dest();
        ppiStack_38 = (int **)0x18;
        ppppiVar5 = &pppuStack_3c;
        pppuStack_3c = pppuStack_8;
      }
      *(undefined4 ****)((int)ppppiVar5 + -4) = param_1;
      *(undefined4 *)((int)ppppiVar5 + -8) = 0x4048af0;
      _ipc_kmsg_put_to_kernel();
      return uVar4;
    }
    pppiStack_30 = (int ***)((int)pppuStack_8[4] + (int)pppuStack_8[6]);
    pppiStack_34 = pppuStack_8;
    ppiStack_38 = (int **)param_1;
    pppuStack_3c = (undefined4 ***)0x4048b0c;
    _ipc_kmsg_put_to_kernel();
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=1305 start=0x4048b18 */

void _msg_send_from_kernel(int param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uStack_8;
  
  uVar1 = *(int *)(param_1 + 4) + 3U & 0xfffffffc;
  iVar2 = _ipc_kmsg_get_from_kernel(param_1,uVar1,*(int *)(param_1 + 4) - uVar1,&uStack_8);
  if (iVar2 == 0) {
    _ipc_kmsg_copyin_compat_from_kernel(uStack_8);
    if ((param_2 & 2) != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(aMsgSendFromKer);
    }
    uVar3 = 0x30000;
    if ((param_2 & 1) != 0) {
      uVar3 = 0x30010;
    }
    iVar2 = _ipc_mqueue_send(uStack_8,uVar3,param_3,0);
    if (iVar2 != 0) {
      _ipc_kmsg_destroy(uStack_8);
    }
  }
  _msg_return_translate(iVar2);
  return;
}
/* GHIDRADEC_FUNCTION index=1306 start=0x4048bba */

undefined4 _msg_send(int param_1,uint param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iStack_8;
  
  uVar3 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x7c);
  uVar1 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 8);
  uVar2 = *(int *)(param_1 + 4) + 3U & 0xfffffffc;
  if (uVar2 < 0x2001) {
    iVar4 = _ipc_kmsg_get_from_kernel(param_1,uVar2,*(int *)(param_1 + 4) - uVar2,&iStack_8);
    if (iVar4 == 0) {
      iVar4 = _ipc_kmsg_copyin_compat(iStack_8,uVar3,uVar1);
      if (iVar4 == 0) {
        if ((param_2 & 2) != 0) {
                    /* WARNING: Subroutine does not return */
          _panic(aMsgSendNotify);
        }
        do {
          if ((param_2 & 0x20) == 0) {
            uVar3 = 0;
            if ((param_2 & 1) != 0) {
              uVar3 = 0x10;
            }
          }
          else {
            uVar3 = 0x20000;
            if ((param_2 & 1) != 0) {
              uVar3 = 0x20010;
            }
          }
          iVar4 = _ipc_mqueue_send(iStack_8,uVar3,param_3,0);
          if (iVar4 != 0x10000007) break;
          while ((*(uint *)(_active_threads + 0x177) & 0x3ffffff) >> 0x18 != 0) {
            _thread_halt_self_with_continuation(0);
          }
        } while ((param_2 & 4) == 0);
        if (iVar4 != 0) {
          _ipc_kmsg_destroy(iStack_8);
        }
      }
      else if (*(int *)(iStack_8 + 8) < 1) {
        _ipc_kmsg_free(iStack_8);
      }
      else {
        _kfree(iStack_8,*(int *)(iStack_8 + 8));
      }
    }
    uVar3 = _msg_return_translate(iVar4);
  }
  else {
    uVar3 = 0xffffff93;
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=1307 start=0x4048cf8 */

void _msg_receive(undefined4 **param_1,uint param_2,undefined4 ***param_3)

{
  undefined4 ***pppuVar1;
  undefined4 ***pppuVar2;
  undefined4 ***pppuVar3;
  undefined4 **ppuVar4;
  undefined4 ***pppuVar5;
  uint uVar6;
  undefined4 ****ppppuVar7;
  uint uStack_50;
  undefined4 *puStack_4c;
  undefined4 **ppuStack_48;
  undefined4 **ppuStack_44;
  undefined4 **ppuStack_40;
  undefined4 ***pppuStack_3c;
  undefined4 ***pppuStack_38;
  undefined4 *puStack_14;
  undefined4 **ppuStack_10;
  undefined4 **ppuStack_c;
  undefined4 *puStack_8;
  
  pppuVar1 = *(undefined4 ****)(*(int *)(_active_threads + 0xc) + 0x7c);
  pppuVar2 = *(undefined4 ****)(*(int *)(_active_threads + 0xc) + 8);
  pppuVar3 = (undefined4 ***)param_1[3];
  ppuVar4 = (undefined4 **)param_1[1];
  do {
    pppuStack_38 = &ppuStack_c;
    pppuStack_3c = (undefined4 ***)&puStack_8;
    ppuStack_48 = (undefined4 ***)0x4048d38;
    ppuStack_44 = pppuVar1;
    ppuStack_40 = pppuVar3;
    pppuStack_38 = (undefined4 ***)_ipc_mqueue_copyin();
    if (pppuStack_38 != (undefined4 ***)0x0) {
      ppppuVar7 = &pppuStack_38;
      goto loc_4048E14;
    }
    pppuStack_38 = (undefined4 ***)&puStack_14;
    pppuStack_3c = &ppuStack_10;
    ppuStack_40 = (undefined4 ***)0x0;
    ppuStack_44 = (undefined4 ***)0x0;
    ppuStack_48 = param_3;
    puStack_4c = (undefined4 **)0xffffffff;
    if ((param_2 & 0x1000) != 0) {
      puStack_4c = ppuVar4;
    }
    uStack_50 = param_2 & 0x100;
    pppuVar5 = (undefined4 ***)_ipc_mqueue_receive(puStack_8);
    pppuStack_38 = (undefined4 ***)ppuStack_c;
    pppuStack_3c = (undefined4 ***)0x4048d80;
    _ipc_object_release();
    if (pppuVar5 != (undefined4 ***)0x10004005) break;
    while ((*(uint *)(_active_threads + 0x177) & 0x3ffffff) >> 0x18 != 0) {
      pppuStack_38 = (undefined4 ***)0x0;
      pppuStack_3c = (undefined4 ***)0x4048d94;
      _thread_halt_self_with_continuation();
    }
  } while ((param_2 & 0x400) == 0);
  if (pppuVar5 == (undefined4 ***)0x0) {
    if (ppuVar4 < ppuStack_10[6]) {
      pppuStack_38 = (undefined4 ***)ppuStack_10;
      pppuStack_3c = (undefined4 ***)0x4048e0e;
      _ipc_kmsg_destroy();
      ppppuVar7 = &pppuStack_3c;
      pppuStack_3c = (undefined4 ***)0x10004004;
    }
    else {
      ppuStack_40 = ppuStack_10;
      ppuStack_44 = (undefined4 **)0x4048de0;
      pppuStack_3c = pppuVar1;
      pppuStack_38 = pppuVar2;
      uVar6 = _ipc_kmsg_copyout_compat();
      ppuStack_44 = (undefined4 **)((int)ppuStack_10[4] + (int)ppuStack_10[6]);
      ppuStack_10[6] = ppuStack_44;
      ppuStack_48 = ppuStack_10;
      puStack_4c = param_1;
      uStack_50 = 0x4048dfe;
      _ipc_kmsg_put_to_kernel();
      ppppuVar7 = (undefined4 ****)&uStack_50;
      uStack_50 = uVar6;
    }
  }
  else {
    if (pppuVar5 == (undefined4 ***)0x10004004) {
      param_1[1] = ppuStack_10;
    }
    ppppuVar7 = &pppuStack_38;
    pppuStack_38 = pppuVar5;
  }
loc_4048E14:
  *(undefined4 *)((int)ppppuVar7 + -4) = 0x4048e1a;
  _msg_return_translate();
  return;
}
/* GHIDRADEC_FUNCTION index=1308 start=0x4048e24 */

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
/* GHIDRADEC_FUNCTION index=1309 start=0x4049184 */

undefined4 _mig_get_reply_port(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _active_threads;
  if (*(int *)(_active_threads + 0xb4) == 0) {
    uVar2 = _mach_reply_port();
    *(undefined4 *)(iVar1 + 0xb4) = uVar2;
  }
  return *(undefined4 *)(iVar1 + 0xb4);
}
/* GHIDRADEC_FUNCTION index=1310 start=0x40491ac */

void _mig_dealloc_reply_port(void)

{
                    /* WARNING: Subroutine does not return */
  _panic(aMigDeallocRepl);
}
/* GHIDRADEC_FUNCTION index=1311 start=0x40491c0 */

void _mig_strncpy(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  if (0 < param_3) {
    iVar2 = 1;
    pcVar3 = param_1;
    if (1 < param_3) {
      do {
        cVar1 = *param_2;
        param_1 = pcVar3 + 1;
        *pcVar3 = cVar1;
        if (cVar1 == '\0') {
          return;
        }
        iVar2 = iVar2 + 1;
        param_2 = param_2 + 1;
        pcVar3 = param_1;
      } while (iVar2 < param_3);
    }
    *param_1 = '\0';
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1312 start=0x40491f0 */

byte _thread_go(int param_1)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  byte bVar7;
  
  if (*(int *)(param_1 + 0x13c) != 0) {
    _reset_timeout(param_1 + 0x110);
  }
  uVar1 = *(uint *)(param_1 + 0x48);
  uVar2 = (uVar1 & 0xf) - 1;
  cVar6 = 0xe < uVar2;
  cVar5 = SBORROW4(0xe,uVar2);
  cVar3 = (int)(0xe - uVar2) < 0;
  cVar4 = uVar2 == 0xe;
  bVar7 = cVar6;
  switch(uVar2) {
  case :
  case :
  case :
    *(uint *)(param_1 + 0x48) = uVar1 & 0xfffffffe | 4;
    *(undefined4 *)(param_1 + 0x40) = 0;
    cVar3 = param_1 < 0;
    cVar4 = param_1 == 0;
    cVar5 = '\0';
    bVar7 = 0;
    _thread_setrun(param_1,1);
    break;
  case :
  case :
  case :
  case :
  case :
    *(uint *)(param_1 + 0x48) = uVar1 & 0xfffffffe;
    *(undefined4 *)(param_1 + 0x40) = 0;
    cVar3 = '\0';
    cVar4 = '\x01';
    cVar5 = '\0';
    bVar7 = 0;
  }
  return cVar6 << 4 | cVar3 << 3 | cVar4 << 2 | cVar5 << 1 | bVar7;
}
/* GHIDRADEC_FUNCTION index=1313 start=0x40492a8 */

byte _thread_go_and_switch(int param_1,int param_2)

{
  uint uVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  
  if (*(int *)(param_2 + 0x13c) != 0) {
    _reset_timeout(param_2 + 0x110);
  }
  uVar1 = *(uint *)(param_2 + 0x48);
  cVar5 = 0xe < (uVar1 & 0xf) - 1;
  switch(uVar1 & 0xf) {
  case :
  case :
  case :
    *(uint *)(param_2 + 0x48) = uVar1 & 0xfffffffe | 4;
    *(undefined4 *)(param_2 + 0x40) = 0;
    uVar1 = *(uint *)(param_2 + 0x178);
    if ((*(int *)(uVar1 + 0x110) < 1) &&
       (cVar5 = uVar1 < *(uint *)(_active_threads + 0x178),
       uVar1 == *(uint *)(_active_threads + 0x178))) {
      cVar2 = param_1 < 0;
      cVar3 = param_1 == 0;
      cVar4 = '\0';
      bVar6 = 0;
      _thread_run(param_1,param_2);
      return cVar5 << 4 | cVar2 << 3 | cVar3 << 2 | cVar4 << 1 | bVar6;
    }
    _thread_setrun(param_2,1);
    break;
  case :
  case :
  case :
  case :
  case :
    *(uint *)(param_2 + 0x48) = uVar1 & 0xfffffffe;
    *(undefined4 *)(param_2 + 0x40) = 0;
  }
  cVar4 = '\0';
  bVar6 = 0;
  cVar2 = param_1 < 0;
  cVar3 = param_1 == 0;
  if (!(bool)cVar3) {
    cVar5 = '\0';
    cVar2 = param_1 < 0;
    cVar3 = param_1 == 0;
    cVar4 = '\0';
    bVar6 = 0;
    _call_continuation(param_1);
  }
  return cVar5 << 4 | cVar2 << 3 | cVar3 << 2 | cVar4 << 1 | bVar6;
}
/* GHIDRADEC_FUNCTION index=1314 start=0x40493a0 */

byte _thread_will_wait(int param_1)

{
  int unaff_D2;
  char in_XF;
  
  *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) | 1;
  return in_XF << 4 | (unaff_D2 < 0) << 3 | (unaff_D2 == 0) << 2;
}
/* GHIDRADEC_FUNCTION index=1315 start=0x40493c4 */

undefined4 _thread_will_wait_with_timeout(int param_1,int param_2)

{
  uint uVar1;
  undefined2 extraout_D0u;
  undefined2 uVar2;
  uint uVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  byte bVar8;
  
  uVar1 = _hz * param_2 + 999;
  uVar3 = uVar1 / 1000;
  uVar2 = (undefined2)(uVar1 / 0xfa000);
  cVar4 = '\0';
  *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) | 1;
  if (uVar3 == 0) {
    cVar7 = '\0';
    bVar8 = 0;
    cVar5 = param_2 < 0;
    cVar6 = param_2 == 0;
    if (!(bool)cVar6) goto loc_4049416;
  }
  cVar5 = '\0';
  cVar6 = uVar3 == 0;
  cVar7 = '\0';
  bVar8 = 0;
  _set_timeout(param_1 + 0x110,uVar3);
  uVar2 = extraout_D0u;
loc_4049416:
  return CONCAT22(uVar2,(word)(byte)(cVar4 << 4 | cVar5 << 3 | cVar6 << 2 | cVar7 << 1 | bVar8));
}
/* GHIDRADEC_FUNCTION index=1316 start=0x4049424 */

undefined4 _thread_handoff(int param_1,undefined4 param_2,int param_3)

{
  byte *pbVar1;
  undefined4 uVar2;
  
  if ((*(int *)(param_1 + 0x2c) == _active_stacks) || (*(int *)(param_3 + 0x48) != 0x101)) {
    _c_thread_handoff_misses = _c_thread_handoff_misses + 1;
    uVar2 = 0;
  }
  else {
    if (*(int *)(param_3 + 0x13c) != 0) {
      _reset_timeout(param_3 + 0x110);
    }
    *(undefined4 *)(param_3 + 0x48) = 4;
    _need_ast = *(uint *)(param_3 + 0x174) | _need_ast & 0xfffffffc;
    if (_need_ast == 0) {
      pbVar1 = (byte *)(*(int *)(_active_threads + 0x24) + 0x54);
      *pbVar1 = *pbVar1 & 0xef;
    }
    else {
      pbVar1 = (byte *)(*(int *)(_active_threads + 0x24) + 0x54);
      *pbVar1 = *pbVar1 | 0x10;
    }
    _switch_unix_context(param_3);
    _stack_handoff(param_1,param_3);
    *(undefined4 *)(param_1 + 0x30) = param_2;
    if (*(int *)(param_1 + 0x48) == 4) {
      *(undefined4 *)(param_1 + 0x48) = 0x101;
    }
    else {
      if (*(int *)(param_1 + 0x48) != 6) {
                    /* WARNING: Subroutine does not return */
        _panic(aThreadHandoff);
      }
      *(undefined4 *)(param_1 + 0x48) = 0x103;
      if (*(int *)(param_1 + 0x44) != 0) {
        *(undefined4 *)(param_1 + 0x44) = 0;
        _thread_wakeup_prim(param_1 + 0x44,0,0);
      }
    }
    _c_thread_handoff_hits = _c_thread_handoff_hits + 1;
    uVar2 = 1;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1317 start=0x404952e */

void _ipc_task_init(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  word wVar3;
  sword sVar4;
  undefined4 uStack_8;
  
  iVar1 = _ipc_space_create(_ipc_table_entries,&uStack_8);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aIpcTaskInit);
  }
  iVar1 = _ipc_port_alloc_special(_ipc_space_kernel);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aIpcTaskInit);
  }
  *(int *)(param_1 + 0x5c) = iVar1;
  uVar2 = _ipc_port_make_send(iVar1);
  *(undefined4 *)(param_1 + 0x60) = uVar2;
  *(undefined4 *)(param_1 + 0x7c) = uStack_8;
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 100) = 0;
    *(undefined4 *)(param_1 + 0x68) = 0;
    iVar1 = 3;
    do {
      do {
        *(undefined4 *)(param_1 + 0x6c + iVar1 * 4) = 0;
        wVar3 = (word)((uint)iVar1 >> 0x10);
        sVar4 = (sword)iVar1 + -1;
        iVar1 = CONCAT22(wVar3,sVar4);
      } while (sVar4 != -1);
      iVar1 = (uint)wVar3 * 0x10000 + -1;
    } while (wVar3 != 0);
  }
  else {
    iVar1 = 0;
    do {
      uVar2 = _ipc_port_copy_send(*(undefined4 *)(param_2 + 0x6c + iVar1 * 4));
      *(undefined4 *)(param_1 + 0x6c + iVar1 * 4) = uVar2;
      iVar1 = iVar1 + 1;
    } while (iVar1 < 4);
    uVar2 = _ipc_port_copy_send(*(undefined4 *)(param_2 + 100));
    *(undefined4 *)(param_1 + 100) = uVar2;
    uVar2 = _ipc_port_copy_send(*(undefined4 *)(param_2 + 0x68));
    *(undefined4 *)(param_1 + 0x68) = uVar2;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1318 start=0x40495f6 */

void _ipc_task_enable(int param_1)

{
  if (*(int *)(param_1 + 0x5c) != 0) {
    _ipc_kobject_set(*(int *)(param_1 + 0x5c),param_1,2);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1319 start=0x4049616 */

void _ipc_task_disable(int param_1)

{
  if (*(int *)(param_1 + 0x5c) != 0) {
    _ipc_kobject_set(*(int *)(param_1 + 0x5c),0,0);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1320 start=0x4049634 */

void _ipc_task_terminate(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x5c);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0x5c) = 0;
    iVar3 = *(int *)(param_1 + 0x60);
    if ((iVar3 != 0) && (iVar3 != -1)) {
      _ipc_port_release_send(iVar3);
    }
    iVar3 = *(int *)(param_1 + 100);
    if ((iVar3 != 0) && (iVar3 != -1)) {
      _ipc_port_release_send(iVar3);
    }
    iVar3 = *(int *)(param_1 + 0x68);
    if ((iVar3 != 0) && (iVar3 != -1)) {
      _ipc_port_release_send(iVar3);
    }
    iVar3 = 0;
    do {
      iVar2 = *(int *)(param_1 + 0x6c + iVar3 * 4);
      if ((iVar2 != 0) && (iVar2 != -1)) {
        _ipc_port_release_send(iVar2);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 4);
    _ipc_space_destroy(*(undefined4 *)(param_1 + 0x7c));
    _ipc_port_dealloc_special(iVar1,_ipc_space_kernel);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1321 start=0x40496ce */

void _ipc_thread_init(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piStack_c;
  undefined auStack_8 [4];
  
  iVar1 = _ipc_port_alloc_special(_ipc_space_kernel);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aIpcThreadInit);
  }
  *(int *)(param_1 + 0x8c) = param_1;
  *(int *)(param_1 + 0x90) = param_1;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(int *)(param_1 + 0xa4) = iVar1;
  uVar2 = _ipc_port_make_send(iVar1);
  *(undefined4 *)(param_1 + 0xa8) = uVar2;
  *(undefined4 *)(param_1 + 0xac) = 0;
  *(undefined4 *)(param_1 + 0xb4) = 0;
  *(undefined4 *)(param_1 + 0xb8) = 0;
  iVar1 = _ipc_port_alloc_compat
                    (*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x7c),auStack_8,&piStack_c);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aIpcThreadInit);
  }
  piStack_c[6] = piStack_c[6] + 1;
  *piStack_c = *piStack_c + 1;
  *(int **)(param_1 + 0xb0) = piStack_c;
  return;
}
/* GHIDRADEC_FUNCTION index=1322 start=0x4049766 */

void _ipc_thread_enable(int param_1)

{
  if (*(int *)(param_1 + 0xa4) != 0) {
    _ipc_kobject_set(*(int *)(param_1 + 0xa4),param_1,1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1323 start=0x4049786 */

void _ipc_thread_disable(int param_1)

{
  if (*(int *)(param_1 + 0xa4) != 0) {
    _ipc_kobject_set(*(int *)(param_1 + 0xa4),0,0);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1324 start=0x40497a4 */

void _ipc_thread_terminate(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iVar1 = *(int *)(param_1 + 0xa4);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0xa4) = 0;
    iVar2 = *(int *)(param_1 + 0xa8);
    if ((iVar2 != 0) && (iVar2 != -1)) {
      _ipc_port_release_send(iVar2);
    }
    iVar2 = *(int *)(param_1 + 0xac);
    if ((iVar2 != 0) && (iVar2 != -1)) {
      _ipc_port_release_send(iVar2);
    }
    iVar2 = *(int *)(param_1 + 0xb8);
    if ((iVar2 != 0) && (iVar2 != -1)) {
      _ipc_port_dealloc_special(iVar2,_ipc_space_reply);
    }
    iVar2 = *(int *)(param_1 + 0xb0);
    if ((iVar2 != 0) && (iVar2 != -1)) {
      iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 0x7c);
      if (*(int *)(iVar3 + 4) != 0) {
        iVar4 = _ipc_right_reverse(iVar3,iVar2,&uStack_8,&uStack_c);
        if (iVar4 != 0) {
          _ipc_right_destroy(iVar3,uStack_8,uStack_c);
        }
      }
      _ipc_port_release_send(iVar2);
    }
    _ipc_port_dealloc_special(iVar1,_ipc_space_kernel);
  }
  return;
}

