/* GHIDRADEC_FUNCTION index=1175 start=0x404283e */

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
/* GHIDRADEC_FUNCTION index=1176 start=0x404291c */

undefined4
_ipc_right_copyout(int param_1,int param_2,uint *param_3,uint param_4,int param_5,int *param_6)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *param_3;
  if (param_4 == 0x11) {
    if ((uVar1 & 0x10000) == 0) {
      if ((uVar1 & 0x20000) == 0) {
        _ipc_hash_insert(param_1,param_6,param_2,param_3);
      }
      else {
        *param_6 = *param_6 + -1;
      }
    }
    else {
      if ((sword)uVar1 == -2) {
        if (param_5 != 0) {
          param_6[6] = param_6[6] + -1;
          *param_6 = *param_6 + -1;
          return 0;
        }
        return 0x13;
      }
      param_6[6] = param_6[6] + -1;
      *param_6 = *param_6 + -1;
    }
    *param_3 = (uVar1 | 0x10000) + 1;
  }
  else if (param_4 < 0x12) {
    if (param_4 != 0x10) {
loc_40429E6:
                    /* WARNING: Subroutine does not return */
      _panic(aIpcRightCopyou);
    }
    iVar2 = param_6[2];
    param_6[3] = param_2;
    param_6[2] = param_1;
    if ((uVar1 & 0x10000) != 0) {
      *param_6 = *param_6 + -1;
      _ipc_hash_delete(param_1,param_6,param_2,param_3);
    }
    *param_3 = uVar1 | 0x20000;
    if (iVar2 != 0) {
      _ipc_object_release(iVar2);
    }
  }
  else {
    if (param_4 != 0x12) goto loc_40429E6;
    *param_3 = uVar1 | 0x40001;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=1177 start=0x40429fe */

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
/* GHIDRADEC_FUNCTION index=1178 start=0x4042b30 */

undefined4
_ipc_right_copyin_compat
          (undefined4 param_1,undefined4 param_2,uint *param_3,int param_4,int param_5,uint *param_6
          )

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  
  uVar4 = *param_3;
  if (param_4 == 5) {
    if (param_5 != 0) {
      iVar5 = 0;
      iVar3 = 0;
      iVar6 = 0;
      if ((uVar4 & 0x20000) == 0) {
        return 0x11;
      }
      piVar7 = (int *)param_3[1];
      if (param_3[2] != 0) {
        iVar5 = _ipc_right_dncancel(param_1,piVar7,param_2,param_3);
      }
      if ((uVar4 & 0x200000) != 0) {
        _ipc_marequest_cancel(param_1,param_2);
      }
      param_3[1] = 0;
      _ipc_entry_dealloc(param_1,param_2,param_3);
      if ((((uVar4 & 0x10000) != 0) && (iVar2 = piVar7[6], piVar7[6] = iVar2 + -1, iVar2 == 1)) &&
         (iVar3 = piVar7[8], iVar3 != 0)) {
        piVar7[8] = 0;
        iVar6 = piVar7[5];
      }
      _ipc_port_clear_receiver(piVar7);
      piVar7[3] = 0;
      piVar7[2] = 0;
      if (iVar3 != 0) {
        _ipc_notify_no_senders(iVar3,iVar6);
      }
      if (iVar5 != 0) {
        _ipc_notify_port_deleted(iVar5,param_2);
      }
      goto loc_4042D2C;
    }
    if ((uVar4 & 0x20000) == 0) {
      return 0x11;
    }
    piVar7 = (int *)param_3[1];
    if ((uVar4 & 0x10000) == 0) {
      piVar7[6] = piVar7[6] + 1;
      uVar4 = uVar4 | 0x10001;
    }
    _ipc_hash_insert(param_1,piVar7,param_2,param_3);
    *param_3 = uVar4 & 0xfffdffff;
    _ipc_port_clear_receiver(piVar7);
    piVar7[3] = 0;
    piVar7[2] = 0;
  }
  else {
    if (param_4 != 6) {
                    /* WARNING: Subroutine does not return */
      _panic(aIpcRightCopyin_1);
    }
    if (param_5 != 0) {
      if ((uVar4 & 0x1f0000) != 0x10000) {
        return 0x11;
      }
      uVar1 = param_3[1];
      iVar3 = _ipc_right_check(param_1,uVar1,param_2,param_3);
      if (iVar3 == 0) {
        if (param_3[2] == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = _ipc_right_dncancel(param_1,uVar1,param_2,param_3);
        }
        if ((uVar4 & 0x200000) != 0) {
          _ipc_marequest_cancel(param_1,param_2);
        }
        _ipc_hash_delete(param_1,uVar1,param_2,param_3);
        param_3[1] = 0;
        _ipc_entry_dealloc(param_1,param_2,param_3);
        if (iVar3 != 0) {
          _ipc_notify_port_deleted(iVar3,param_2);
        }
        *param_6 = uVar1;
        return 0;
      }
loc_4042C1E:
      if ((uVar4 & 0x400000) == 0) {
        return 0x11;
      }
      return 0xf;
    }
    if ((uVar4 & 0x30000) == 0) {
      return 0x11;
    }
    piVar7 = (int *)param_3[1];
    iVar3 = _ipc_right_check(param_1,piVar7,param_2,param_3);
    if (iVar3 != 0) goto loc_4042C1E;
    if ((uVar4 & 0x10000) == 0) {
      piVar7[5] = piVar7[5] + 1;
    }
    piVar7[6] = piVar7[6] + 1;
  }
  *piVar7 = *piVar7 + 1;
loc_4042D2C:
  *param_6 = (uint)piVar7;
  return 0;
}
/* GHIDRADEC_FUNCTION index=1179 start=0x4042d50 */

undefined4
_ipc_right_copyin_header
          (int param_1,undefined4 param_2,uint *param_3,uint *param_4,undefined4 *param_5)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  
  uVar1 = *param_3;
  uVar3 = uVar1 & 0x1f0000;
  if (uVar3 != 0x30000) {
    if (0x30000 < uVar3) {
      if (uVar3 == 0x80000) {
        return 0x11;
      }
      if (0x80000 < uVar3) {
        if (uVar3 == 0x100000) {
          return 0x11;
        }
loc_4042E84:
                    /* WARNING: Subroutine does not return */
        _panic(aIpcRightCopyin_2);
      }
      if (uVar3 != 0x40000) goto loc_4042E84;
      uVar3 = param_3[1];
      iVar4 = _ipc_right_check(param_1,uVar3,param_2,param_3);
      if (iVar4 == 0) {
        if (param_3[2] == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = _ipc_right_dncancel(param_1,uVar3,param_2,param_3);
        }
        param_3[1] = 0;
        _ipc_entry_dealloc(param_1,param_2,param_3);
        iVar5 = _ipc_port_copy_send(*(undefined4 *)(param_1 + 0x3c));
        if (iVar4 != 0) {
          _ipc_notify_port_deleted(iVar4,param_2);
        }
        if ((iVar5 != 0) && (iVar5 != -1)) {
          _ipc_notify_port_deleted_compat(iVar5,param_2);
        }
        *param_4 = uVar3;
        uVar6 = 0x12;
        goto loc_4042E7E;
      }
      goto loc_4042E0E;
    }
    if (uVar3 != 0x10000) {
      if (uVar3 != 0x20000) goto loc_4042E84;
      piVar2 = (int *)param_3[1];
      piVar2[5] = piVar2[5] + 1;
      piVar2[6] = piVar2[6] + 1;
      *piVar2 = *piVar2 + 1;
      *param_4 = (uint)piVar2;
      uVar6 = 0x11;
      goto loc_4042E7E;
    }
  }
  piVar2 = (int *)param_3[1];
  iVar4 = _ipc_right_check(param_1,piVar2,param_2,param_3);
  if (iVar4 == 0) {
    piVar2[6] = piVar2[6] + 1;
    *piVar2 = *piVar2 + 1;
    *param_4 = (uint)piVar2;
    uVar6 = 0x11;
loc_4042E7E:
    *param_5 = uVar6;
    return 0;
  }
loc_4042E0E:
  if ((uVar1 & 0x400000) == 0) {
    return 0x11;
  }
  return 0xf;
}
/* GHIDRADEC_FUNCTION index=1180 start=0x4042ea4 */

void _ipc_space_reference(int *param_1)

{
  *param_1 = *param_1 + 1;
  return;
}
/* GHIDRADEC_FUNCTION index=1181 start=0x4042eb2 */

void _ipc_space_release(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = iVar1 + -1;
  if (iVar1 == 1) {
    _zfree(_ipc_space_zone,param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1182 start=0x4042ee0 */

undefined4 _ipc_space_create(uint *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  
  puVar3 = (undefined4 *)_zalloc(_ipc_space_zone);
  if (puVar3 == (undefined4 *)0x0) {
    uVar4 = 6;
  }
  else {
    iVar5 = _ipc_table_alloc(*param_1 << 4);
    if (iVar5 == 0) {
      _zfree(_ipc_space_zone,puVar3);
      uVar4 = 6;
    }
    else {
      uVar2 = *param_1;
      _bzero(iVar5,uVar2 << 4);
      uVar6 = 0;
      if (uVar2 != 0) {
        do {
          puVar1 = (undefined4 *)(iVar5 + uVar6 * 0x10);
          *puVar1 = 0xff000000;
          uVar6 = uVar6 + 1;
          puVar1[2] = uVar6;
        } while (uVar6 < uVar2);
      }
      *(undefined4 *)(iVar5 + -8 + uVar2 * 0x10) = 0;
      *puVar3 = 2;
      puVar3[1] = 1;
      puVar3[2] = 0;
      puVar3[3] = iVar5;
      puVar3[4] = uVar2;
      puVar3[5] = param_1 + 1;
      _ipc_splay_tree_init(puVar3 + 6);
      puVar3[0xc] = 0;
      puVar3[0xd] = 0;
      puVar3[0xe] = 0;
      puVar3[0xf] = 0;
      *param_2 = puVar3;
      uVar4 = 0;
    }
  }
  return uVar4;
}
/* GHIDRADEC_FUNCTION index=1183 start=0x4042fb0 */

undefined4 _ipc_space_create_special(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)_zalloc(_ipc_space_zone);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 6;
  }
  else {
    *puVar1 = 1;
    puVar1[1] = 0;
    *param_1 = puVar1;
    uVar2 = 0;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1184 start=0x4042fe4 */

void _ipc_space_destroy(int param_1)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  
  iVar1 = *(int *)(param_1 + 4);
  *(undefined4 *)(param_1 + 4) = 0;
  if (iVar1 != 0) {
    iVar1 = *(int *)(param_1 + 8);
    while (iVar1 != 0) {
      _assert_wait(param_1,0);
      _thread_block_with_continuation(0);
      iVar1 = *(int *)(param_1 + 8);
    }
    puVar3 = *(uint **)(param_1 + 0xc);
    uVar2 = *(uint *)(param_1 + 0x10);
    uVar4 = 0;
    puVar5 = puVar3;
    if (uVar2 != 0) {
      do {
        if ((*puVar5 & 0x1f0000) != 0) {
          _ipc_right_clean(param_1,*puVar5 >> 0x18 | uVar4 << 8,puVar5);
        }
        uVar4 = uVar4 + 1;
        puVar5 = puVar5 + 4;
      } while (uVar4 < uVar2);
    }
    _ipc_table_free(*(int *)(*(int *)(param_1 + 0x14) + -4) << 4,puVar3);
    puVar3 = (uint *)_ipc_splay_traverse_start(param_1 + 0x18);
    while (puVar3 != (uint *)0x0) {
      uVar2 = puVar3[4];
      if ((*puVar3 & 0x1f0000) == 0x10000) {
        _ipc_hash_global_delete(param_1,puVar3[1],uVar2,puVar3);
      }
      _ipc_right_clean(param_1,uVar2,puVar3);
      puVar3 = (uint *)_ipc_splay_traverse_next(param_1 + 0x18,1);
    }
    _ipc_splay_traverse_finish(param_1 + 0x18);
    iVar1 = *(int *)(param_1 + 0x3c);
    if ((iVar1 != 0) && (iVar1 != -1)) {
      _ipc_port_release_send(iVar1);
    }
    _ipc_space_release(param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1185 start=0x4043208 */

void _ipc_splay_tree_init(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=1186 start=0x4043218 */

int _ipc_splay_tree_pick(int param_1,undefined4 *param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    *param_2 = *(undefined4 *)(iVar1 + 0x10);
    *param_3 = iVar1;
  }
  return -(int)-(iVar1 != 0);
}
/* GHIDRADEC_FUNCTION index=1187 start=0x4043248 */

int _ipc_splay_tree_lookup(int *param_1,int param_2)

{
  int iStack_8;
  
  iStack_8 = param_1[1];
  if (iStack_8 != 0) {
    if (param_2 != *param_1) {
      sub_40431D2(iStack_8,param_1 + 2,param_1[3],param_1 + 4,param_1[5]);
      sub_404310C(param_2,iStack_8,&iStack_8,param_1 + 2,param_1 + 3,param_1 + 4,param_1 + 5);
      *param_1 = param_2;
      param_1[1] = iStack_8;
    }
    if (param_2 != *(int *)(iStack_8 + 0x10)) {
      iStack_8 = 0;
    }
  }
  return iStack_8;
}
/* GHIDRADEC_FUNCTION index=1188 start=0x40432c2 */

void _ipc_splay_tree_insert(uint *param_1,uint param_2,uint param_3)

{
  uint uStack_8;
  
  uStack_8 = param_1[1];
  if (uStack_8 == 0) {
    *(undefined4 *)(param_3 + 0x18) = 0;
    *(undefined4 *)(param_3 + 0x1c) = 0;
  }
  else {
    if (param_2 != *param_1) {
      sub_40431D2(uStack_8,param_1 + 2,param_1[3],param_1 + 4,param_1[5]);
      sub_404310C(param_2,uStack_8,&uStack_8,param_1 + 2,param_1 + 3,param_1 + 4,param_1 + 5);
    }
    if (param_2 < *(uint *)(uStack_8 + 0x10)) {
      *(undefined4 *)param_1[3] = 0;
      *(uint *)param_1[5] = uStack_8;
    }
    else {
      *(uint *)param_1[3] = uStack_8;
      *(undefined4 *)param_1[5] = 0;
    }
    *(uint *)(param_3 + 0x18) = param_1[2];
    *(uint *)(param_3 + 0x1c) = param_1[4];
  }
  *(uint *)(param_3 + 0x10) = param_2;
  param_1[1] = param_3;
  *param_1 = param_2;
  param_1[3] = (uint)(param_1 + 2);
  param_1[5] = (uint)(param_1 + 4);
  return;
}
/* GHIDRADEC_FUNCTION index=1189 start=0x404337c */

void _ipc_splay_tree_delete(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iStack_8;
  
  iStack_8 = param_1[1];
  if (param_2 != *param_1) {
    sub_40431D2(iStack_8,param_1 + 2,param_1[3],param_1 + 4,param_1[5]);
    sub_404310C(param_2,iStack_8,&iStack_8,param_1 + 2,param_1 + 3,param_1 + 4,param_1 + 5);
  }
  *(undefined4 *)param_1[3] = *(undefined4 *)(iStack_8 + 0x18);
  *(undefined4 *)param_1[5] = *(undefined4 *)(iStack_8 + 0x1c);
  _zfree(_ipc_tree_entry_zone,iStack_8);
  iStack_8 = param_1[2];
  iVar1 = param_1[4];
  iVar2 = iVar1;
  if ((iStack_8 != 0) && (iVar2 = iStack_8, iVar1 != 0)) {
    sub_404310C(0xffffffff,iStack_8,&iStack_8,param_1 + 2,param_1 + 3,param_1 + 4,param_1 + 5);
    sub_40431D2(iStack_8,param_1 + 2,param_1[3],param_1 + 4,param_1[5]);
    *(int *)(iStack_8 + 0x1c) = iVar1;
    iVar2 = iStack_8;
  }
  iStack_8 = iVar2;
  param_1[1] = iStack_8;
  if (iStack_8 != 0) {
    *param_1 = *(int *)(iStack_8 + 0x10);
    param_1[3] = (int)(param_1 + 2);
    param_1[5] = (int)(param_1 + 4);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1190 start=0x4043498 */

void _ipc_splay_tree_split(uint *param_1,uint param_2,undefined4 *param_3)

{
  uint uVar1;
  uint uStack_8;
  
  _ipc_splay_tree_init(param_3);
  uStack_8 = param_1[1];
  if (uStack_8 != 0) {
    if (param_2 != *param_1) {
      sub_40431D2(uStack_8,param_1 + 2,param_1[3],param_1 + 4,param_1[5]);
      sub_404310C(param_2,uStack_8,&uStack_8,param_1 + 2,param_1 + 3,param_1 + 4,param_1 + 5);
    }
    if (*(uint *)(uStack_8 + 0x10) < param_2) {
      *(undefined4 *)param_1[3] = *(undefined4 *)(uStack_8 + 0x18);
      *(undefined4 *)param_1[5] = 0;
      *(uint *)(uStack_8 + 0x18) = param_1[2];
      param_3[1] = uStack_8;
      *param_3 = *(undefined4 *)(uStack_8 + 0x10);
      param_3[3] = param_3 + 2;
      param_3[5] = param_3 + 4;
      uVar1 = param_1[4];
      param_1[1] = uVar1;
      if (uVar1 != 0) {
        *param_1 = *(uint *)(uVar1 + 0x10);
        param_1[3] = (uint)(param_1 + 2);
        param_1[5] = (uint)(param_1 + 4);
      }
    }
    else {
      *(undefined4 *)param_1[3] = *(undefined4 *)(uStack_8 + 0x18);
      *(undefined4 *)(uStack_8 + 0x18) = 0;
      param_1[1] = uStack_8;
      *param_1 = param_2;
      param_1[3] = (uint)(param_1 + 2);
      uVar1 = param_1[2];
      param_3[1] = uVar1;
      if (uVar1 != 0) {
        *param_3 = *(undefined4 *)(uVar1 + 0x10);
        param_3[3] = param_3 + 2;
        param_3[5] = param_3 + 4;
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1191 start=0x40435b0 */

void _ipc_splay_tree_join(int *param_1,int param_2)

{
  int iVar1;
  int iStack_8;
  
  iVar1 = *(int *)(param_2 + 4);
  if (iVar1 != 0) {
    sub_40431D2(iVar1,param_2 + 8,*(undefined4 *)(param_2 + 0xc),param_2 + 0x10,
                *(undefined4 *)(param_2 + 0x14));
    *(undefined4 *)(param_2 + 4) = 0;
    iStack_8 = param_1[1];
    if (iStack_8 != 0) {
      if (*param_1 != 0) {
        sub_40431D2(iStack_8,param_1 + 2,param_1[3],param_1 + 4,param_1[5]);
        sub_404310C(0,iStack_8,&iStack_8,param_1 + 2,param_1 + 3,param_1 + 4,param_1 + 5);
      }
      sub_40431D2(iStack_8,param_1 + 2,param_1[3],param_1 + 4,param_1[5]);
      *(int *)(iStack_8 + 0x18) = iVar1;
      iVar1 = iStack_8;
    }
    iStack_8 = iVar1;
    param_1[1] = iStack_8;
    *param_1 = *(int *)(iStack_8 + 0x10);
    param_1[3] = (int)(param_1 + 2);
    param_1[5] = (int)(param_1 + 4);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1192 start=0x404367c */

void _ipc_splay_tree_bounds(uint *param_1,uint param_2,uint *param_3,uint *param_4)

{
  uint uVar1;
  uint uStack_8;
  
  uStack_8 = param_1[1];
  if (uStack_8 == 0) {
    *param_3 = 0xffffffff;
  }
  else {
    if (param_2 != *param_1) {
      sub_40431D2(uStack_8,param_1 + 2,param_1[3],param_1 + 4,param_1[5]);
      sub_404310C(param_2,uStack_8,&uStack_8,param_1 + 2,param_1 + 3,param_1 + 4,param_1 + 5);
      *param_1 = param_2;
      param_1[1] = uStack_8;
    }
    uVar1 = *(uint *)(uStack_8 + 0x10);
    if (param_2 < uVar1) {
      if (param_1 + 2 == (uint *)param_1[3]) {
        *param_3 = 0xffffffff;
      }
      else {
        *param_3 = ((uint *)param_1[3])[-3];
      }
    }
    else {
      *param_3 = uVar1;
    }
    if (param_2 <= uVar1) {
      *param_4 = uVar1;
      return;
    }
    if (param_1 + 4 != (uint *)param_1[5]) {
      *param_4 = ((uint *)param_1[5])[-2];
      return;
    }
  }
  *param_4 = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=1193 start=0x404373c */

int _ipc_splay_traverse_start(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 4);
  if (iVar4 != 0) {
    sub_40431D2(iVar4,param_1 + 8,*(undefined4 *)(param_1 + 0xc),param_1 + 0x10,
                *(undefined4 *)(param_1 + 0x14));
    iVar1 = *(int *)(iVar4 + 0x18);
    iVar2 = iVar4;
    iVar3 = 0;
    while (iVar4 = iVar2, iVar1 != 0) {
      iVar2 = *(int *)(iVar4 + 0x18);
      *(int *)(iVar4 + 0x18) = iVar3;
      iVar1 = *(int *)(iVar2 + 0x18);
      iVar3 = iVar4;
    }
    *(int *)(param_1 + 8) = iVar4;
    *(int *)(param_1 + 0x10) = iVar3;
  }
  return iVar4;
}
/* GHIDRADEC_FUNCTION index=1194 start=0x4043798 */

int _ipc_splay_traverse_next(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uStack_18;
  undefined auStack_14 [4];
  undefined4 uStack_10;
  undefined auStack_c [4];
  int iStack_8;
  
  iVar4 = *(int *)(param_1 + 8);
  iVar1 = *(int *)(param_1 + 0x10);
  iStack_8 = iVar4;
  iVar3 = iVar1;
  if (param_2 == 0) {
loc_40438D8:
    iVar4 = *(int *)(iStack_8 + 0x1c);
    if (iVar4 != 0) {
      *(int *)(iStack_8 + 0x1c) = iVar1;
      iVar3 = iStack_8;
      iStack_8 = iVar4;
loc_40438B6:
      while (iVar4 = *(int *)(iStack_8 + 0x18), iVar4 != 0) {
        *(int *)(iStack_8 + 0x18) = iVar3;
        iVar3 = iStack_8;
        iStack_8 = iVar4;
      }
      goto loc_40438C6;
    }
  }
  else {
    iVar2 = *(int *)(iVar4 + 0x18);
    if (iVar2 == 0) {
      iStack_8 = *(int *)(iVar4 + 0x1c);
      if (iStack_8 != 0) {
        _zfree(_ipc_tree_entry_zone,iVar4);
        goto loc_40438B6;
      }
      if (iVar1 == 0) {
        iStack_8 = iVar4;
        _zfree(_ipc_tree_entry_zone,iVar4);
        *(undefined4 *)(param_1 + 4) = 0;
        return 0;
      }
      if (*(uint *)(iVar4 + 0x10) < *(uint *)(iVar1 + 0x10)) {
        iStack_8 = iVar4;
        _zfree(_ipc_tree_entry_zone,iVar4);
        iVar3 = *(int *)(iVar1 + 0x18);
        *(undefined4 *)(iVar1 + 0x18) = 0;
        iStack_8 = iVar1;
        goto loc_40438C6;
      }
      iStack_8 = iVar4;
      _zfree(_ipc_tree_entry_zone,iVar4);
      iVar3 = *(int *)(iVar1 + 0x1c);
      *(undefined4 *)(iVar1 + 0x1c) = 0;
      iStack_8 = iVar1;
    }
    else {
      if (*(int *)(iVar4 + 0x1c) != 0) {
        sub_404310C(0xffffffff,iVar2,&iStack_8,auStack_c,&uStack_10,auStack_14,&uStack_18);
        sub_40431D2(iStack_8,auStack_c,uStack_10,auStack_14,uStack_18);
        *(undefined4 *)(iStack_8 + 0x1c) = *(undefined4 *)(iVar4 + 0x1c);
        _zfree(_ipc_tree_entry_zone,iVar4);
        goto loc_40438D8;
      }
      iStack_8 = iVar2;
      _zfree(_ipc_tree_entry_zone,iVar4);
    }
  }
  while( true ) {
    iVar4 = iVar3;
    if (iVar4 == 0) {
      *(int *)(param_1 + 4) = iStack_8;
      return 0;
    }
    if (*(uint *)(iStack_8 + 0x10) < *(uint *)(iVar4 + 0x10)) break;
    iVar3 = *(int *)(iVar4 + 0x1c);
    *(int *)(iVar4 + 0x1c) = iStack_8;
    iStack_8 = iVar4;
  }
  iVar3 = *(int *)(iVar4 + 0x18);
  *(int *)(iVar4 + 0x18) = iStack_8;
  iStack_8 = iVar4;
loc_40438C6:
  *(int *)(param_1 + 8) = iStack_8;
  *(int *)(param_1 + 0x10) = iVar3;
  return iStack_8;
}
/* GHIDRADEC_FUNCTION index=1195 start=0x4043936 */

void _ipc_splay_traverse_finish(undefined4 *param_1)

{
  if (param_1[1] != 0) {
    *param_1 = *(undefined4 *)(param_1[1] + 0x10);
    param_1[3] = param_1 + 2;
    param_1[5] = param_1 + 4;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1196 start=0x4043964 */

void _ipc_table_fill(uint *param_1,uint param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  
  uVar3 = _page_size;
  uVar4 = param_4 * param_3;
  uVar7 = 0;
  uVar2 = 1;
  puVar5 = param_1;
  uVar1 = _page_size;
  if (param_2 != 0) {
    do {
      uVar1 = _page_size;
      if (uVar3 <= uVar2) break;
      puVar6 = puVar5;
      if (uVar4 < uVar2 || uVar4 - uVar2 == 0) {
        puVar6 = puVar5 + 1;
        *puVar5 = uVar2 / param_4;
        uVar7 = uVar7 + 1;
      }
      uVar2 = uVar2 * 2;
      puVar5 = puVar6;
      uVar1 = _page_size;
    } while (uVar7 < param_2);
  }
  do {
    if (param_2 <= uVar7) {
      return;
    }
    uVar3 = 0;
    puVar5 = param_1 + uVar7;
    do {
      if (param_2 <= uVar7) break;
      puVar6 = puVar5;
      if (uVar4 < uVar2 || uVar4 - uVar2 == 0) {
        puVar6 = puVar5 + 1;
        *puVar5 = uVar2 / param_4;
        uVar7 = uVar7 + 1;
      }
      uVar3 = uVar3 + 1;
      uVar2 = uVar1 + uVar2;
      puVar5 = puVar6;
    } while (uVar3 < 0xf);
    uVar1 = uVar1 * 2;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1197 start=0x40439e4 */

void _ipc_table_init(void)

{
  _ipc_table_entries = _kalloc(_ipc_table_entries_size << 2);
  _ipc_table_fill(_ipc_table_entries,_ipc_table_entries_size + -1,4,0x10);
  *(undefined4 *)(_ipc_table_entries + -4 + _ipc_table_entries_size * 4) =
       *(undefined4 *)(_ipc_table_entries + -8 + _ipc_table_entries_size * 4);
  _ipc_table_dnrequests = _kalloc(_ipc_table_dnrequests_size << 2);
  _ipc_table_fill(_ipc_table_dnrequests,_ipc_table_dnrequests_size + -1,2,8);
  *(undefined4 *)(_ipc_table_dnrequests + -4 + _ipc_table_dnrequests_size * 4) = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=1198 start=0x4043a76 */

undefined4 _ipc_table_alloc(uint param_1)

{
  int iVar1;
  undefined4 uStack_8;
  
  if (param_1 < _page_size) {
    uStack_8 = _kalloc(param_1);
  }
  else {
    iVar1 = _kmem_alloc(_kalloc_map,&uStack_8,param_1);
    if (iVar1 != 0) {
      uStack_8 = 0;
    }
  }
  return uStack_8;
}
/* GHIDRADEC_FUNCTION index=1199 start=0x4043ab6 */

undefined4 _ipc_table_realloc(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uStack_8;
  
  iVar1 = _kmem_realloc(_kalloc_map,param_2,param_1,&uStack_8,param_3);
  if (iVar1 != 0) {
    uStack_8 = 0;
  }
  return uStack_8;
}

