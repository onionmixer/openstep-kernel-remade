
undefined4 _ipc_kmsg_copyout_header(uint *param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  int *piVar8;
  uint uStack_14;
  undefined4 uStack_10;
  int iStack_c;
  int *piStack_8;
  
  uVar5 = *param_1;
  piVar1 = (int *)param_1[2];
  if (param_3 == 0) {
    uVar6 = uVar5 & 0xffff;
    uVar2 = (undefined2)(uVar5 >> 0x10);
    if (uVar6 == 0x12) {
      if (piVar1[1] < 0) {
        if (param_2 == piVar1[2]) {
          *piVar1 = *piVar1 + -1;
          piVar1[7] = piVar1[7] + -1;
          uVar5 = piVar1[3];
        }
        else {
          _ipc_notify_send_once(piVar1);
          uVar5 = 0;
        }
        *param_1 = CONCAT22(uVar2,0x1200);
        param_1[3] = uVar5;
        param_1[2] = 0;
        return 0;
      }
    }
    else if (uVar6 < 0x13) {
      if ((uVar6 == 0x11) && (piVar1[1] < 0)) {
        *piVar1 = *piVar1 + -1;
        uVar5 = 0;
        if (param_2 == piVar1[2]) {
          uVar5 = piVar1[3];
        }
        iVar3 = piVar1[6];
        piVar1[6] = iVar3 + -1;
        if ((iVar3 == 1) && (iVar3 = piVar1[8], iVar3 != 0)) {
          piVar1[8] = 0;
          _ipc_notify_no_senders(iVar3,piVar1[5]);
        }
        *param_1 = CONCAT22(uVar2,0x1100);
        param_1[3] = uVar5;
        param_1[2] = 0;
        return 0;
      }
    }
    else if ((((uVar6 == 0x1211) && (uVar6 = param_1[3], uVar6 != 0)) && (uVar6 != 0xffffffff)) &&
            (*(int *)(param_2 + 4) != 0)) {
      iVar3 = *(int *)(param_2 + 0xc);
      iVar4 = *(int *)(iVar3 + 8);
      if (((iVar4 != 0) && (piVar1[1] < 0)) && (*(int *)(uVar6 + 4) < 0)) {
        puVar7 = (uint *)(iVar4 * 0x10 + iVar3);
        *(uint *)(iVar3 + 8) = puVar7[2];
        puVar7[2] = 0;
        uVar5 = *puVar7;
        *puVar7 = uVar5 + 0x1000000 | 0x40001;
        puVar7[1] = uVar6;
        *piVar1 = *piVar1 + -1;
        uVar6 = 0;
        if (param_2 == piVar1[2]) {
          uVar6 = piVar1[3];
        }
        iVar3 = piVar1[6];
        piVar1[6] = iVar3 + -1;
        if ((iVar3 == 1) && (iVar3 = piVar1[8], iVar3 != 0)) {
          piVar1[8] = 0;
          _ipc_notify_no_senders(iVar3,piVar1[5]);
        }
        *param_1 = CONCAT22(uVar2,0x1112);
        param_1[3] = uVar6;
        param_1[2] = uVar5 + 0x1000000 >> 0x18 | iVar4 << 8;
        return 0;
      }
    }
  }
  uVar6 = (uVar5 & 0xffff) >> 8;
  piVar8 = (int *)param_1[3];
  if ((piVar8 == (int *)0x0) || (piVar8 == (int *)0xffffffff)) {
    if (*(int *)(param_2 + 4) == 0) {
      return 0x1000600b;
    }
    piStack_8 = piVar8;
    if ((param_3 != 0) &&
       ((iVar3 = _ipc_entry_lookup(param_2,param_3), iVar3 == 0 || ((*(byte *)(iVar3 + 1) & 2) == 0)
        ))) {
      return 0x10004007;
    }
loc_403E1B4:
    if (piVar1[1] < 0) {
      _ipc_object_copyout_dest(param_2,piVar1,uVar5 & 0xff,&uStack_14);
    }
    else {
      iVar4 = piVar1[2];
      iVar3 = *piVar1;
      *piVar1 = iVar3 + -1;
      if (iVar3 == 1) {
        _zfree((&_ipc_object_zones)[*(word *)(piVar1 + 1) & 0x7fff],piVar1);
      }
      if ((((piVar8 == (int *)0x0) || (piVar8 == (int *)0xffffffff)) || (piVar8[1] < 0)) ||
         (iVar4 - piVar8[2] < 0)) {
        uStack_14 = 0xffffffff;
      }
      else {
        uStack_14 = 0;
      }
    }
    if ((piVar8 != (int *)0x0) && (piVar8 != (int *)0xffffffff)) {
      _ipc_object_release(piVar8);
    }
    *param_1 = uVar6 | (uVar5 & 0xff) << 8 | uVar5 & 0xffff0000;
    param_1[3] = uStack_14;
    param_1[2] = (uint)piStack_8;
    return 0;
  }
loc_403DFFC:
  if (*(int *)(param_2 + 4) == 0) {
    return 0x1000600b;
  }
  if (param_3 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = _ipc_port_lookup_notify(param_2,param_3);
    if (iVar3 == 0) {
      return 0x10004007;
    }
  }
  if ((uVar6 == 0x12) ||
     (iVar4 = _ipc_right_reverse(param_2,piVar8,&piStack_8,&iStack_c), iVar4 == 0)) {
    if (-1 < piVar8[1]) {
      iVar4 = *piVar8;
      *piVar8 = iVar4 + -1;
      if (iVar4 == 1) {
        _zfree((&_ipc_object_zones)[*(word *)(piVar8 + 1) & 0x7fff],piVar8);
      }
      if (iVar3 != 0) {
        _ipc_port_release_sonce(iVar3);
      }
      piVar8 = (int *)0xffffffff;
      piStack_8 = (int *)0xffffffff;
      goto loc_403E1B4;
    }
    iVar4 = _ipc_entry_get(param_2,&piStack_8,&iStack_c);
    if (iVar4 != 0) {
      if (iVar3 != 0) {
        _ipc_port_release_sonce(iVar3);
      }
      iVar3 = _ipc_entry_grow_table(param_2);
      if (iVar3 != 0) {
        if (iVar3 == 6) {
          return 0x1000480b;
        }
        return 0x1000600b;
      }
      goto loc_403DFFC;
    }
    if (iVar3 != 0) {
      iVar4 = _ipc_port_dnrequest(piVar8,piStack_8,iVar3,&uStack_10);
      if (iVar4 == 0) {
        iVar3 = 0;
        *(int **)(iStack_c + 4) = piVar8;
        *(undefined4 *)(iStack_c + 8) = uStack_10;
        goto loc_403E150;
      }
      _ipc_port_release_sonce(iVar3);
      _ipc_entry_dealloc(param_2,piStack_8,iStack_c);
      if ((piVar8[1] < 0) && (iVar3 = _ipc_port_dngrow(piVar8), iVar3 != 0)) {
        return 0x1000480b;
      }
      goto loc_403DFFC;
    }
    *(int **)(iStack_c + 4) = piVar8;
  }
loc_403E150:
  *piVar8 = *piVar8 + 1;
  _ipc_right_copyout(param_2,piStack_8,iStack_c,uVar6,1,piVar8);
  if (iVar3 != 0) {
    _ipc_port_release_sonce(iVar3);
  }
  goto loc_403E1B4;
}

