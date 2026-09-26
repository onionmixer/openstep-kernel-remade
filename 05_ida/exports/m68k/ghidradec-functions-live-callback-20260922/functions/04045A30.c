
/* WARNING: Type propagation algorithm not settling */

undefined4
_msg_rpc_trap(undefined4 *******param_1,uint param_2,int param_3,undefined4 *******param_4,
             undefined4 param_5,undefined4 *******param_6)

{
  undefined4 *****pppppuVar1;
  undefined4 *******pppppppuVar2;
  undefined4 ******ppppppuVar3;
  int iVar4;
  undefined4 ******ppppppuVar5;
  undefined4 ******ppppppuVar6;
  undefined4 uVar7;
  undefined4 *******pppppppuVar8;
  uint uStack_54;
  undefined4 *******pppppppuStack_50;
  undefined4 *******pppppppuStack_4c;
  undefined4 *******pppppppuStack_48;
  undefined4 *******pppppppuStack_44;
  undefined4 *******pppppppuStack_40;
  undefined4 *******pppppppuStack_3c;
  undefined4 *******pppppppuStack_10;
  undefined4 *****pppppuStack_c;
  undefined4 *******pppppppuStack_8;
  
  pppppppuVar2 = *(undefined4 ********)(*(int *)(_active_threads + 0xc) + 0x7c);
  ppppppuVar3 = *(undefined4 *******)(*(int *)(_active_threads + 0xc) + 8);
  pppppppuStack_44 = (undefined4 *******)(param_3 + 3U & 0xfffffffc);
  pppppppuStack_40 = (undefined4 *******)(param_3 - (int)pppppppuStack_44);
  if ((undefined4 *******)0x2000 < pppppppuStack_44) {
    return 0xffffff93;
  }
  pppppppuStack_3c = &pppppppuStack_8;
  pppppppuStack_48 = param_1;
  pppppppuStack_4c = (undefined4 *******)0x4045a8a;
  pppppppuStack_3c = (undefined4 *******)_ipc_kmsg_get();
  if (pppppppuStack_3c != (undefined4 *******)0x0) {
    pppppppuVar8 = &pppppppuStack_3c;
    goto loc_4045DC6;
  }
  pppppppuStack_44 = pppppppuStack_8;
  pppppppuStack_48 = (undefined4 *******)0x4045ab6;
  pppppppuStack_40 = pppppppuVar2;
  pppppppuStack_3c = (undefined4 *******)ppppppuVar3;
  ppppppuVar5 = (undefined4 ******)_ipc_kmsg_copyin_compat();
  if (ppppppuVar5 != (undefined4 ******)0x0) {
    pppppppuStack_3c = (undefined4 *******)pppppppuStack_8[2];
    if ((int)pppppppuStack_3c < 1) {
      pppppppuStack_3c = pppppppuStack_8;
      pppppppuStack_40 = (undefined4 *******)0x4045ad2;
      _ipc_kmsg_free();
    }
    else {
      pppppppuStack_40 = pppppppuStack_8;
      pppppppuStack_44 = (undefined4 *******)0x4045aa4;
      _kfree();
    }
    pppppppuVar8 = &pppppppuStack_3c;
    pppppppuStack_3c = (undefined4 *******)ppppppuVar5;
    goto loc_4045DC6;
  }
  ppppppuVar5 = pppppppuStack_8[8];
  if ((ppppppuVar5 == (undefined4 ******)0x0) || (ppppppuVar5 == (undefined4 ******)0xffffffff)) {
loc_4045B80:
    if ((param_2 & 2) == 0) {
      if ((param_2 & 0x20) == 0) {
        pppppppuStack_44 = (undefined4 *******)0x0;
        if ((param_2 & 1) != 0) {
          pppppppuStack_44 = (undefined4 *******)0x10;
        }
      }
      else {
        pppppppuStack_44 = (undefined4 *******)0x20000;
        if ((param_2 & 1) != 0) {
          pppppppuStack_44 = (undefined4 *******)0x20010;
        }
      }
      pppppppuStack_3c = (undefined4 *******)0x0;
      pppppppuStack_40 = (undefined4 *******)param_5;
      pppppppuStack_48 = pppppppuStack_8;
      pppppppuStack_4c = (undefined4 *******)0x4045c44;
      ppppppuVar6 = (undefined4 ******)_ipc_mqueue_send();
loc_4045C4A:
      if (ppppppuVar6 == (undefined4 ******)0x0) goto loc_4045C74;
    }
    else {
      pppppppuStack_3c = (undefined4 *******)0x0;
      pppppppuStack_40 = (undefined4 *******)0;
      if ((param_2 & 1) != 0) {
        pppppppuStack_40 = (undefined4 *******)param_5;
      }
      pppppppuStack_44 = (undefined4 *******)0x10;
      if ((param_2 & 0x20) != 0) {
        pppppppuStack_44 = (undefined4 *******)0x20010;
      }
      pppppppuStack_48 = pppppppuStack_8;
      pppppppuStack_4c = (undefined4 *******)0x4045bb2;
      ppppppuVar6 = (undefined4 ******)_ipc_mqueue_send();
      if (ppppppuVar6 != (undefined4 ******)0x10000004) goto loc_4045C4A;
      pppppppuStack_3c = pppppppuStack_8 + 3;
      pppppppuStack_40 = (undefined4 *******)0x0;
      pppppppuStack_44 = (undefined4 *******)pppppppuStack_8[7];
      pppppppuStack_4c = (undefined4 *******)0x4045bd8;
      pppppppuStack_48 = pppppppuVar2;
      ppppppuVar6 = (undefined4 ******)_ipc_marequest_create();
      if (ppppppuVar6 == (undefined4 ******)0x0) {
        pppppppuStack_3c = (undefined4 *******)0x0;
        pppppppuStack_40 = (undefined4 *******)0x0;
        pppppppuStack_44 = (undefined4 *******)0x10000;
        pppppppuStack_48 = pppppppuStack_8;
        pppppppuStack_4c = (undefined4 *******)0x4045bf2;
        _ipc_mqueue_send();
        if ((ppppppuVar5 != (undefined4 ******)0x0) &&
           (ppppppuVar5 != (undefined4 ******)0xffffffff)) {
          pppppppuStack_40 = (undefined4 *******)0x4045c08;
          pppppppuStack_3c = (undefined4 *******)ppppppuVar5;
          _ipc_object_release();
        }
        return 0xffffff97;
      }
    }
    pppppppuStack_3c = pppppppuStack_8;
    pppppppuStack_40 = (undefined4 *******)0x4045c58;
    _ipc_kmsg_destroy();
    if ((ppppppuVar5 != (undefined4 ******)0x0) && (ppppppuVar5 != (undefined4 ******)0xffffffff)) {
      pppppppuStack_40 = (undefined4 *******)0x4045c6c;
      pppppppuStack_3c = (undefined4 *******)ppppppuVar5;
      _ipc_object_release();
    }
    pppppppuVar8 = &pppppppuStack_3c;
    pppppppuStack_3c = (undefined4 *******)ppppppuVar6;
  }
  else {
    ppppppuVar6 = pppppppuStack_8[7];
    pppppppuStack_40 = (undefined4 *******)0x4045afc;
    pppppppuStack_3c = (undefined4 *******)ppppppuVar5;
    _ipc_object_reference();
    if (ppppppuVar6[2] != _ipc_space_kernel) goto loc_4045B80;
    pppppppuStack_3c = pppppppuStack_8;
    pppppppuStack_40 = (undefined4 *******)0x4045b14;
    pppppppuStack_8 = (undefined4 *******)_ipc_kobject_server();
    if (pppppppuStack_8 == (undefined4 *******)0x0) {
loc_4045C74:
      if ((ppppppuVar5 == (undefined4 ******)0x0) || (ppppppuVar5 == (undefined4 ******)0xffffffff))
      {
        return 0xffffff36;
      }
      if (pppppppuVar2 != (undefined4 *******)ppppppuVar5[2]) {
        pppppuVar1 = *ppppppuVar5;
        *ppppppuVar5 = (undefined4 *****)((int)pppppuVar1 + -1);
        if (pppppuVar1 != (undefined4 *****)0x1) {
          return 0xffffff36;
        }
        pppppppuStack_40 =
             (undefined4 *******)(&_ipc_object_zones)[*(word *)(ppppppuVar5 + 1) & 0x7fff];
        pppppppuStack_44 = (undefined4 *******)0x4045cae;
        pppppppuStack_3c = (undefined4 *******)ppppppuVar5;
        _zfree();
        return 0xffffff36;
      }
      ppppppuVar6 = (undefined4 ******)ppppppuVar5[0xb];
      if (ppppppuVar6 != (undefined4 ******)0x0) {
        if ((int)ppppppuVar6[1] < 0) {
          *ppppppuVar5 = (undefined4 *****)((int)*ppppppuVar5 + -1);
          return 0xffffff36;
        }
        pppppppuStack_44 = (undefined4 *******)0x4045cd2;
        pppppppuStack_40 = (undefined4 *******)ppppppuVar6;
        pppppppuStack_3c = (undefined4 *******)ppppppuVar5;
        _ipc_pset_remove();
        if (*ppppppuVar6 == (undefined4 *****)0x0) {
          pppppppuStack_40 =
               (undefined4 *******)(&_ipc_object_zones)[*(word *)(ppppppuVar6 + 1) & 0x7fff];
          pppppppuStack_44 = (undefined4 *******)0x4045cf4;
          pppppppuStack_3c = (undefined4 *******)ppppppuVar6;
          _zfree();
        }
      }
      iVar4 = _active_threads;
      *(undefined4 ********)(_active_threads + 0xbc) = param_1;
      *(uint *)(iVar4 + 0xc0) = param_2;
      *(undefined4 ********)(iVar4 + 0xc4) = param_4;
      *(undefined4 ********)(iVar4 + 200) = param_6;
      *(undefined4 *******)(iVar4 + 0xd0) = ppppppuVar5;
      *(undefined4 *******)(iVar4 + 0xd4) = ppppppuVar5 + 0xf;
      pppppppuStack_3c = (undefined4 *******)&pppppuStack_c;
      pppppppuStack_40 = &pppppppuStack_8;
      pppppppuStack_44 = (undefined4 *******)_msg_receive_continue;
      pppppppuStack_48 = (undefined4 *******)0x0;
      pppppppuStack_4c = param_6;
      pppppppuStack_50 = (undefined4 *******)0xffffffff;
      if ((param_2 & 0x1000) != 0) {
        pppppppuStack_50 = param_4;
      }
      uStack_54 = param_2 & 0x100;
      ppppppuVar6 = (undefined4 ******)_ipc_mqueue_receive(ppppppuVar5 + 0xf);
      pppppppuStack_40 = (undefined4 *******)0x4045d54;
      pppppppuStack_3c = (undefined4 *******)ppppppuVar5;
      _ipc_object_release();
      if (ppppppuVar6 != (undefined4 ******)0x0) {
        if (ppppppuVar6 == (undefined4 ******)0x10004004) {
          pppppppuStack_10 = pppppppuStack_8;
          pppppppuStack_3c = (undefined4 *******)0x4;
          pppppppuStack_40 = param_1 + 1;
          pppppppuStack_44 = &pppppppuStack_10;
          pppppppuStack_48 = (undefined4 *******)0x4045d7a;
          _copyoutmsg();
        }
        pppppppuVar8 = &pppppppuStack_3c;
        pppppppuStack_3c = (undefined4 *******)ppppppuVar6;
        goto loc_4045DC6;
      }
      if (param_4 < pppppppuStack_8[6]) {
        pppppppuStack_3c = pppppppuStack_8;
        pppppppuStack_40 = (undefined4 *******)0x4045d94;
        _ipc_kmsg_destroy();
        return 0xffffff34;
      }
    }
    else {
      if (((((-1 < (int)ppppppuVar5[1]) || (pppppppuVar2 != (undefined4 *******)ppppppuVar5[2])) ||
           (ppppppuVar5[0xb] != (undefined4 *****)0x0)) ||
          ((param_4 < (undefined4 *******)((int)pppppppuStack_8[4] + (int)pppppppuStack_8[6]) ||
           (ppppppuVar5[0x10] != (undefined4 *****)0x0)))) ||
         (ppppppuVar5[0xf] != (undefined4 *****)0x0)) {
        pppppppuStack_3c = (undefined4 *******)0x0;
        pppppppuStack_40 = (undefined4 *******)0x0;
        pppppppuStack_44 = (undefined4 *******)0x10000;
        pppppppuStack_4c = (undefined4 *******)0x4045b6e;
        pppppppuStack_48 = pppppppuStack_8;
        _ipc_mqueue_send();
        goto loc_4045C74;
      }
      ppppppuVar5[0xc] = (undefined4 *****)((int)ppppppuVar5[0xc] + 1);
      *ppppppuVar5 = (undefined4 *****)((int)*ppppppuVar5 + -1);
    }
    pppppppuStack_44 = pppppppuStack_8;
    pppppppuStack_48 = (undefined4 *******)0x4045da8;
    pppppppuStack_40 = pppppppuVar2;
    pppppppuStack_3c = (undefined4 *******)ppppppuVar3;
    _ipc_kmsg_copyout_compat();
    pppppppuStack_48 = (undefined4 *******)((int)pppppppuStack_8[4] + (int)pppppppuStack_8[6]);
    pppppppuStack_8[6] = pppppppuStack_48;
    pppppppuStack_4c = pppppppuStack_8;
    pppppppuStack_50 = param_1;
    uStack_54 = 0x4045dc4;
    uStack_54 = _ipc_kmsg_put();
    pppppppuVar8 = (undefined4 *******)&uStack_54;
  }
loc_4045DC6:
  *(undefined4 *)((int)pppppppuVar8 + -4) = 0x4045dcc;
  uVar7 = _msg_return_translate();
  return uVar7;
}

