/* GHIDRADEC_FUNCTION index=1225 start=0x40462b4 */

undefined4 _mach_port_rename(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0x10;
  }
  else if ((param_3 == 0) || (param_3 == -1)) {
    uVar1 = 0x12;
  }
  else {
    uVar1 = _ipc_object_rename(param_1,param_2,param_3);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1226 start=0x40462ee */

undefined4 _mach_port_allocate_name(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  undefined auStack_c [4];
  undefined auStack_8 [4];
  
  if (param_1 == 0) {
    uVar1 = 0x10;
  }
  else {
    if ((param_3 != 0) && (param_3 != -1)) {
      if (param_2 == 3) {
        uVar1 = _ipc_pset_alloc_name(param_1,param_3,auStack_c);
        return uVar1;
      }
      if (param_2 < 4) {
        if (param_2 == 1) {
          uVar1 = _ipc_port_alloc_name(param_1,param_3,auStack_8);
          return uVar1;
        }
      }
      else if (param_2 == 4) {
        uVar1 = _ipc_object_alloc_dead_name(param_1,param_3);
        return uVar1;
      }
    }
    uVar1 = 0x12;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1227 start=0x4046360 */

undefined4 _mach_port_allocate(int param_1,uint param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined auStack_c [4];
  undefined auStack_8 [4];
  
  if (param_1 == 0) {
    uVar1 = 0x10;
  }
  else if (param_2 == 3) {
    uVar1 = _ipc_pset_alloc(param_1,param_3,auStack_c);
  }
  else {
    if (param_2 < 4) {
      if (param_2 == 1) {
        uVar1 = _ipc_port_alloc(param_1,param_3,auStack_8);
        return uVar1;
      }
    }
    else if (param_2 == 4) {
      uVar1 = _ipc_object_alloc_dead(param_1,param_3);
      return uVar1;
    }
    uVar1 = 0x12;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1228 start=0x40463c8 */

int _mach_port_destroy(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uStack_8;
  
  if (param_1 == 0) {
    iVar1 = 0x10;
  }
  else {
    iVar1 = _ipc_right_lookup_write(param_1,param_2,&uStack_8);
    if (iVar1 == 0) {
      iVar1 = _ipc_right_destroy(param_1,param_2,uStack_8);
    }
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1229 start=0x4046410 */

int _mach_port_deallocate(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uStack_8;
  
  if (param_1 == 0) {
    iVar1 = 0x10;
  }
  else {
    iVar1 = _ipc_right_lookup_write(param_1,param_2,&uStack_8);
    if (iVar1 == 0) {
      iVar1 = _ipc_right_dealloc(param_1,param_2,uStack_8);
    }
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1230 start=0x4046458 */

int _mach_port_get_refs(int param_1,undefined4 param_2,uint param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uStack_10;
  uint uStack_c;
  undefined4 uStack_8;
  
  if (param_1 == 0) {
    iVar1 = 0x10;
  }
  else if (param_3 < 5) {
    iVar1 = _ipc_right_lookup_write(param_1,param_2,&uStack_8);
    if ((iVar1 == 0) &&
       (iVar1 = _ipc_right_info(param_1,param_2,uStack_8,&uStack_c,&uStack_10), iVar1 == 0)) {
      if ((1 << (param_3 + 0x10 & 0x3f) & uStack_c) == 0) {
        *param_4 = 0;
      }
      else {
        if (param_3 < 4) {
          if (param_3 != 0) {
            *param_4 = 1;
            return 0;
          }
        }
        else if (param_3 != 4) {
                    /* WARNING: Subroutine does not return */
          _panic(aMachPortGetRef);
        }
        *param_4 = uStack_10;
      }
    }
  }
  else {
    iVar1 = 0x12;
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1231 start=0x4046506 */

int _mach_port_mod_refs(int param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uStack_8;
  
  if (param_1 == 0) {
    iVar1 = 0x10;
  }
  else if (param_3 < 5) {
    iVar1 = _ipc_right_lookup_write(param_1,param_2,&uStack_8);
    if (iVar1 == 0) {
      iVar1 = _ipc_right_delta(param_1,param_2,uStack_8,param_3,param_4);
    }
  }
  else {
    iVar1 = 0x12;
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1232 start=0x4046560 */

int _old_mach_port_get_receive_status(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 auStack_28 [2];
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iVar1 = _mach_port_get_receive_status(param_1,param_2,auStack_28);
  if (iVar1 == 0) {
    *param_3 = auStack_28[0];
    param_3[1] = uStack_20;
    param_3[2] = uStack_1c;
    param_3[3] = uStack_18;
    param_3[4] = uStack_14;
    param_3[5] = uStack_10;
    param_3[6] = uStack_c;
    param_3[7] = uStack_8;
    iVar1 = 0;
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1233 start=0x40465b8 */

int _mach_port_set_qlimit(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  undefined4 uStack_8;
  
  if (param_1 == 0) {
    iVar1 = 0x10;
  }
  else if (param_3 < 0x11) {
    iVar1 = _ipc_object_translate(param_1,param_2,1,&uStack_8);
    if (iVar1 == 0) {
      _ipc_port_set_qlimit(uStack_8,param_3);
      iVar1 = 0;
    }
  }
  else {
    iVar1 = 0x12;
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1234 start=0x404660a */

int _mach_port_set_mscount(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iStack_8;
  
  if (param_1 == 0) {
    iVar1 = 0x10;
  }
  else {
    iVar1 = _ipc_object_translate(param_1,param_2,1,&iStack_8);
    if (iVar1 == 0) {
      *(undefined4 *)(iStack_8 + 0x14) = param_3;
      iVar1 = 0;
    }
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1235 start=0x4046640 */

int _mach_port_set_seqno(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uStack_8;
  
  if (param_1 == 0) {
    iVar1 = 0x10;
  }
  else {
    iVar1 = _ipc_object_translate(param_1,param_2,1,&uStack_8);
    if (iVar1 == 0) {
      _ipc_port_set_seqno(uStack_8,param_3);
      iVar1 = 0;
    }
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1236 start=0x404667e */

void _mach_port_gst_helper(int param_1,int param_2,uint param_3,int param_4,uint *param_5)

{
  uint uVar1;
  
  if (param_1 == *(int *)(param_2 + 0x2c)) {
    uVar1 = *param_5;
    if (uVar1 < param_3) {
      *(undefined4 *)(param_4 + uVar1 * 4) = *(undefined4 *)(param_2 + 0xc);
    }
    *param_5 = uVar1 + 1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1237 start=0x40466b6 */

int _mach_port_get_set_status(int param_1,undefined4 param_2,undefined4 *param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uStack_14;
  uint uStack_10;
  uint *puStack_c;
  int iStack_8;
  
  uVar7 = _page_size;
  if (param_1 == 0) {
    iVar3 = 0x10;
  }
  else {
    while (iVar3 = _vm_allocate(_ipc_kernel_map,&iStack_8,uVar7,1), iVar3 == 0) {
      _vm_map_pageable(_ipc_kernel_map,iStack_8,iStack_8 + uVar7,0);
      iVar4 = _ipc_right_lookup_write(param_1,param_2,&puStack_c);
      iVar3 = iStack_8;
      if (iVar4 != 0) {
        _kmem_free(_ipc_kernel_map,iStack_8,uVar7);
        return iVar4;
      }
      if ((*puStack_c & 0x1f0000) != 0x80000) {
        _kmem_free(_ipc_kernel_map,iStack_8,uVar7);
        return 0x11;
      }
      uVar1 = puStack_c[1];
      uVar6 = uVar7 >> 2;
      uStack_10 = 0;
      iVar4 = *(int *)(param_1 + 0xc);
      uVar2 = *(uint *)(param_1 + 0x10);
      uVar5 = 0;
      if (uVar2 != 0) {
        do {
          if ((*(byte *)(iVar4 + 1) & 2) != 0) {
            _mach_port_gst_helper(uVar1,*(undefined4 *)(iVar4 + 4),uVar6,iVar3,&uStack_10);
          }
          iVar4 = iVar4 + 0x10;
          uVar5 = uVar5 + 1;
        } while (uVar5 < uVar2);
      }
      iVar4 = _ipc_splay_traverse_start(param_1 + 0x18);
      while (iVar4 != 0) {
        if ((*(byte *)(iVar4 + 1) & 2) != 0) {
          _mach_port_gst_helper(uVar1,*(undefined4 *)(iVar4 + 4),uVar6,iVar3,&uStack_10);
        }
        iVar4 = _ipc_splay_traverse_next(param_1 + 0x18,0);
      }
      _ipc_splay_traverse_finish(param_1 + 0x18);
      if (uStack_10 <= uVar6) {
        if (uStack_10 == 0) {
          uStack_14 = 0;
        }
        else {
          uVar1 = ~_page_mask & _page_mask + uStack_10 * 4;
          _vm_map_pageable(_ipc_kernel_map,iStack_8,iStack_8 + uVar1,1);
          _vm_move(_ipc_kernel_map,iStack_8,_ipc_soft_map,uVar1,1,&uStack_14);
          if (uVar7 == uVar1) goto loc_40468D0;
          uVar7 = uVar7 - uVar1;
          iStack_8 = iStack_8 + uVar1;
        }
        _kmem_free(_ipc_kernel_map,iStack_8,uVar7);
loc_40468D0:
        *param_3 = uStack_14;
        *param_4 = uStack_10;
        return 0;
      }
      _kmem_free(_ipc_kernel_map,iStack_8,uVar7);
      uVar7 = _page_size + (~_page_mask & _page_mask + uStack_10 * 4);
    }
    iVar3 = 6;
  }
  return iVar3;
}
/* GHIDRADEC_FUNCTION index=1238 start=0x40468e8 */

int _mach_port_move_member(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iStack_8;
  
  if (param_1 == 0) {
    return 0x10;
  }
  iVar2 = _ipc_right_lookup_write(param_1,param_2,&iStack_8);
  if (iVar2 != 0) {
    return iVar2;
  }
  if ((*(byte *)(iStack_8 + 1) & 2) == 0) {
loc_4046950:
    iVar2 = 0x11;
  }
  else {
    uVar1 = *(undefined4 *)(iStack_8 + 4);
    if (param_3 == 0) {
      uVar3 = 0;
    }
    else {
      iStack_8 = _ipc_entry_lookup(param_1,param_3);
      if (iStack_8 == 0) {
        return 0xf;
      }
      if ((*(byte *)(iStack_8 + 1) & 8) == 0) goto loc_4046950;
      uVar3 = *(undefined4 *)(iStack_8 + 4);
    }
    iVar2 = _ipc_pset_move(param_1,uVar1,uVar3);
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=1239 start=0x404696e */

int _mach_port_request_notification
              (int param_1,undefined4 param_2,int param_3,int param_4,int param_5,uint *param_6)

{
  int iVar1;
  undefined4 uStack_10;
  uint uStack_c;
  undefined4 uStack_8;
  
  if (param_1 == 0) {
    return 0x10;
  }
  if (param_5 == -1) {
    return 0x14;
  }
  if (param_3 == 0x46) {
    iVar1 = _ipc_object_translate(param_1,param_2,1,&uStack_10);
    if (iVar1 != 0) {
      return iVar1;
    }
    _ipc_port_nsrequest(uStack_10,param_4,param_5,param_6);
loc_4046A62:
    iVar1 = 0;
  }
  else {
    if (param_3 < 0x47) {
      if ((param_3 == 0x45) && (param_4 == 0)) {
        iVar1 = _ipc_object_translate(param_1,param_2,1,&uStack_8);
        if (iVar1 != 0) {
          return iVar1;
        }
        _ipc_port_pdrequest(uStack_8,param_5,&uStack_c);
        if ((uStack_c != 0) && ((uStack_c & 1) != 0)) {
          _ipc_port_release_send(uStack_c & 0xfffffffe);
          uStack_c = 0;
        }
        *param_6 = uStack_c;
        goto loc_4046A62;
      }
    }
    else if (param_3 == 0x48) {
      iVar1 = _ipc_right_dnrequest(param_1,param_2,-(int)-(param_4 != 0),param_5,param_6);
      if (iVar1 != 0) {
        return iVar1;
      }
      goto loc_4046A62;
    }
    iVar1 = 0x12;
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1240 start=0x4046a6e */

undefined4 _mach_port_insert_right(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0x10;
  }
  else if (((param_2 == 0) || (param_2 == -1)) || (2 < param_4 - 0x10U)) {
    uVar1 = 0x12;
  }
  else if ((param_3 == 0) || (param_3 == -1)) {
    uVar1 = 0x14;
  }
  else {
    uVar1 = _ipc_object_copyout_name(param_1,param_3,param_4,0,param_2);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1241 start=0x4046ad0 */

int _mach_port_extract_right
              (int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 *param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    iVar1 = 0x10;
  }
  else if (param_3 - 0x10U < 6) {
    iVar1 = _ipc_object_copyin(param_1,param_2,param_3,param_4);
    if (iVar1 == 0) {
      uVar2 = _ipc_object_copyin_type(param_3);
      *param_5 = uVar2;
    }
  }
  else {
    iVar1 = 0x12;
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1242 start=0x4046b28 */

int _mach_port_get_receive_status(int param_1,undefined4 param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int iStack_8;
  
  if (param_1 == 0) {
    return 0x10;
  }
  iVar2 = _ipc_object_translate(param_1,param_2,1,&iStack_8);
  if (iVar2 != 0) {
    return iVar2;
  }
  piVar1 = *(int **)(iStack_8 + 0x2c);
  if (piVar1 != (int *)0x0) {
    if (piVar1[1] < 0) {
      *param_3 = piVar1[2];
      goto loc_4046BA8;
    }
    _ipc_pset_remove(piVar1,iStack_8);
    if (*piVar1 == 0) {
      _zfree((&_ipc_object_zones)[*(word *)(piVar1 + 1) & 0x7fff],piVar1);
    }
  }
  *param_3 = 0;
loc_4046BA8:
  param_3[1] = *(int *)(iStack_8 + 0x30);
  param_3[2] = *(int *)(iStack_8 + 0x14);
  param_3[3] = *(int *)(iStack_8 + 0x38);
  param_3[4] = *(int *)(iStack_8 + 0x34);
  param_3[5] = *(int *)(iStack_8 + 0x1c);
  param_3[6] = -(int)-(*(int *)(iStack_8 + 0x18) != 0);
  param_3[7] = -(int)-(*(int *)(iStack_8 + 0x24) != 0);
  param_3[8] = -(int)-(*(int *)(iStack_8 + 0x20) != 0);
  return 0;
}
/* GHIDRADEC_FUNCTION index=1243 start=0x4046c02 */

undefined4 _port_translate_compat(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined auStack_10 [4];
  uint uStack_c;
  int iStack_8;
  
  iVar1 = _ipc_right_lookup_write(param_1,param_2,&iStack_8);
  if ((iVar1 != 0) ||
     (iVar1 = _ipc_right_info(param_1,param_2,iStack_8,&uStack_c,auStack_10), iVar1 != 0)) {
    return 4;
  }
  if ((uStack_c & 0x20000) != 0) {
    *param_3 = *(undefined4 *)(iStack_8 + 4);
    return 0;
  }
  if ((uStack_c & 0x170000) == 0) {
    return 4;
  }
  return 7;
}
/* GHIDRADEC_FUNCTION index=1244 start=0x4046c78 */

undefined4 _convert_port_type(uint param_1)

{
  undefined4 uVar1;
  
  param_1 = param_1 & 0x1f0000;
  if (param_1 == 0x30000) {
loc_4046CC2:
    uVar1 = 7;
  }
  else {
    if (param_1 < 0x30001) {
      if (param_1 != 0x10000) {
        if (param_1 != 0x20000) goto loc_4046CCA;
        goto loc_4046CC2;
      }
    }
    else {
      if (param_1 == 0x80000) {
        return 9;
      }
      if (param_1 < 0x80001) {
        if (param_1 != 0x40000) {
loc_4046CCA:
                    /* WARNING: Subroutine does not return */
          _panic(aConvertPortTyp);
        }
      }
      else if (param_1 != 0x100000) goto loc_4046CCA;
    }
    uVar1 = 1;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1245 start=0x4046cda */

int _port_names(undefined4 param_1,undefined4 *param_2,int *param_3,undefined4 *param_4,
               uint *param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 uStack_c;
  undefined4 *puStack_8;
  
  iVar3 = _mach_port_names(param_1,param_2,param_3,param_4,param_5);
  if (iVar3 == 0) {
    uVar1 = *param_5;
    uStack_c = *param_4;
    uVar2 = ~_page_mask & _page_mask + uVar1 * 4;
    iVar3 = _vm_move(_ipc_soft_map,uStack_c,_ipc_kernel_map,uVar2,0,&puStack_8);
    if (iVar3 == 0) {
      _vm_deallocate(_ipc_soft_map,uStack_c,uVar2);
      uVar5 = 0;
      puVar6 = puStack_8;
      if (uVar1 != 0) {
        do {
          uVar4 = _convert_port_type(*puVar6);
          *puVar6 = uVar4;
          uVar5 = uVar5 + 1;
          puVar6 = puVar6 + 1;
        } while (uVar5 < uVar1);
      }
      iVar3 = _vm_move(_ipc_kernel_map,puStack_8,_ipc_soft_map,uVar2,1,&uStack_c);
      *param_4 = uStack_c;
    }
    else {
      _kmem_free(_ipc_soft_map,*param_4,~_page_mask & _page_mask + *param_5 * 4);
      _kmem_free(_ipc_soft_map,*param_2,~_page_mask & _page_mask + *param_3 * 4);
      iVar3 = 6;
    }
  }
  else if (iVar3 != 6) {
    iVar3 = 4;
  }
  return iVar3;
}
/* GHIDRADEC_FUNCTION index=1246 start=0x4046e10 */

undefined4 _port_type(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_8;
  
  iVar1 = _mach_port_type(param_1,param_2,&uStack_8);
  if (iVar1 == 0) {
    uVar2 = _convert_port_type(uStack_8);
    *param_3 = uVar2;
    uVar2 = 0;
  }
  else {
    uVar2 = 4;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1247 start=0x4046e4e */

int _port_rename(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = _mach_port_rename(param_1,param_2,param_3);
  if ((iVar1 != 0) && (iVar1 != 0xd)) {
    iVar1 = 4;
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1248 start=0x4046e74 */

undefined4 _port_allocate(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined auStack_8 [4];
  
  if (param_1 != 0) {
    iVar1 = _ipc_port_alloc_compat(param_1,param_2,auStack_8);
    if (iVar1 == 0) {
      return 0;
    }
    if (iVar1 == 6) {
      return 6;
    }
  }
  return 4;
}
/* GHIDRADEC_FUNCTION index=1249 start=0x4046e9e */

undefined4 _port_deallocate(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined auStack_10 [4];
  uint uStack_c;
  undefined4 uStack_8;
  
  if ((((param_1 != 0) && (iVar1 = _ipc_right_lookup_write(param_1,param_2,&uStack_8), iVar1 == 0))
      && (iVar1 = _ipc_right_info(param_1,param_2,uStack_8,&uStack_c,auStack_10), iVar1 == 0)) &&
     ((uStack_c & 0x170000) != 0)) {
    _ipc_right_destroy(param_1,param_2,uStack_8);
    return 0;
  }
  return 4;
}

