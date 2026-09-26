/* GHIDRADEC_FUNCTION index=1200 start=0x4043ae6 */

void _ipc_table_free(uint param_1,undefined4 param_2)

{
  if (param_1 < _page_size) {
    _kfree(param_2,param_1);
  }
  else {
    _kmem_free(_kalloc_map,param_2,param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1201 start=0x4043b1a */

void _ipc_thread_enqueue(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    *param_1 = param_2;
  }
  else {
    iVar2 = *(int *)(iVar1 + 0x90);
    *(int *)(param_2 + 0x8c) = iVar1;
    *(int *)(param_2 + 0x90) = iVar2;
    *(int *)(iVar1 + 0x90) = param_2;
    *(int *)(iVar2 + 0x8c) = param_2;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1202 start=0x4043b4e */

int _ipc_thread_dequeue(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 0x8c);
    if (iVar1 == iVar2) {
      *param_1 = 0;
    }
    else {
      iVar3 = *(int *)(iVar1 + 0x90);
      *param_1 = iVar2;
      *(int *)(iVar2 + 0x90) = iVar3;
      *(int *)(iVar3 + 0x8c) = iVar2;
      *(int *)(iVar1 + 0x8c) = iVar1;
      *(int *)(iVar1 + 0x90) = iVar1;
    }
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1203 start=0x4043b90 */

void _ipc_thread_rmqueue(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_2 + 0x8c);
  iVar2 = *(int *)(param_2 + 0x90);
  if (param_2 == iVar1) {
    *param_1 = 0;
  }
  else {
    if (param_2 == *param_1) {
      *param_1 = iVar1;
    }
    *(int *)(iVar1 + 0x90) = iVar2;
    *(int *)(iVar2 + 0x8c) = iVar1;
    *(int *)(param_2 + 0x8c) = param_2;
    *(int *)(param_2 + 0x90) = param_2;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1204 start=0x4043bd2 */

int _mach_port_get_srights(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int iStack_8;
  
  if (param_1 == 0) {
    iVar1 = 0x10;
  }
  else {
    iVar1 = _ipc_object_translate(param_1,param_2,1,&iStack_8);
    if (iVar1 == 0) {
      *param_3 = *(undefined4 *)(iStack_8 + 0x18);
      iVar1 = 0;
    }
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1205 start=0x4043c10 */

undefined4 _host_ipc_hash_info(int param_1,int *param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iStack_c;
  int iStack_8;
  
  uVar4 = 0;
  if (param_1 == 0) {
    return 0x16;
  }
  uVar3 = *param_3;
  iVar2 = *param_2;
  while( true ) {
    uVar1 = _ipc_hash_info(iVar2,uVar3);
    if (uVar1 <= uVar3) {
      if (iVar2 != *param_2) {
        if (uVar1 == 0) {
          _kmem_free(_ipc_kernel_map,iStack_8,uVar4);
          *param_3 = 0;
          return 0;
        }
        uVar3 = ~_page_mask & _page_mask + uVar1 * 4;
        if (uVar4 != uVar3) {
          _kmem_free(_ipc_kernel_map,uVar3 + iStack_8,uVar4 - uVar3);
        }
        _vm_move(_ipc_kernel_map,iStack_8,_ipc_soft_map,uVar3,1,&iStack_c);
        *param_2 = iStack_c;
      }
      *param_3 = uVar1;
      return 0;
    }
    if (iVar2 != *param_2) {
      _kmem_free(_ipc_kernel_map,iStack_8,uVar4);
    }
    uVar4 = ~_page_mask & _page_mask + uVar1 * 4;
    iVar2 = _kmem_alloc_pageable(_ipc_kernel_map,&iStack_8,uVar4);
    if (iVar2 != 0) break;
    uVar3 = uVar4 >> 2;
    iVar2 = iStack_8;
  }
  return 6;
}
/* GHIDRADEC_FUNCTION index=1206 start=0x4043d1e */

undefined4 _host_ipc_marequest_info(int param_1,undefined4 param_2,int *param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iStack_c;
  int iStack_8;
  
  uVar4 = 0;
  if (param_1 == 0) {
    return 0x16;
  }
  uVar3 = *param_4;
  iVar2 = *param_3;
  while( true ) {
    uVar1 = _ipc_marequest_info(param_2,iVar2,uVar3);
    if (uVar1 <= uVar3) {
      if (iVar2 != *param_3) {
        if (uVar1 == 0) {
          _kmem_free(_ipc_kernel_map,iStack_8,uVar4);
          *param_4 = 0;
          return 0;
        }
        uVar3 = ~_page_mask & _page_mask + uVar1 * 4;
        if (uVar4 != uVar3) {
          _kmem_free(_ipc_kernel_map,uVar3 + iStack_8,uVar4 - uVar3);
        }
        _vm_move(_ipc_kernel_map,iStack_8,_ipc_soft_map,uVar3,1,&iStack_c);
        *param_3 = iStack_c;
      }
      *param_4 = uVar1;
      return 0;
    }
    if (iVar2 != *param_3) {
      _kmem_free(_ipc_kernel_map,iStack_8,uVar4);
    }
    uVar4 = ~_page_mask & _page_mask + uVar1 * 4;
    iVar2 = _kmem_alloc_pageable(_ipc_kernel_map,&iStack_8,uVar4);
    if (iVar2 != 0) break;
    uVar3 = uVar4 >> 2;
    iVar2 = iStack_8;
  }
  return 6;
}
/* GHIDRADEC_FUNCTION index=1207 start=0x4043e34 */

undefined4
_mach_port_space_info
          (int param_1,undefined4 *param_2,int *param_3,uint *param_4,int *param_5,uint *param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  uint *puStack_1c;
  uint *puStack_18;
  int iStack_14;
  int iStack_10;
  uint *puStack_c;
  uint *puStack_8;
  
  uVar8 = 0;
  uVar9 = 0;
  if (param_1 != 0) {
    puStack_1c = (uint *)*param_3;
    uVar7 = *param_4;
    puStack_18 = (uint *)*param_5;
    uVar6 = *param_6;
    while (*(int *)(param_1 + 4) != 0) {
      uVar2 = *(uint *)(param_1 + 0x10);
      uVar3 = *(uint *)(param_1 + 0x30);
      if (uVar7 < uVar2) {
        if (puStack_1c != (uint *)*param_3) {
          _kmem_free(_ipc_kernel_map,puStack_8,uVar8);
        }
        uVar8 = ~_page_mask & _page_mask + uVar2 * 0x24;
        iVar4 = _kmem_alloc(_ipc_kernel_map,&puStack_8,uVar8);
        if (iVar4 == 0) {
          puStack_1c = puStack_8;
          uVar7 = uVar8 / 0x24;
          goto loc_4043F52;
        }
        uVar8 = uVar9;
        if (puStack_18 == (uint *)*param_5) {
          return 6;
        }
        goto loc_4043FC4;
      }
      if (uVar3 <= uVar6) {
        *param_2 = 0xff;
        param_2[1] = *(undefined4 *)(param_1 + 0x10);
        param_2[2] = **(undefined4 **)(param_1 + 0x14);
        param_2[3] = *(undefined4 *)(param_1 + 0x30);
        param_2[4] = *(undefined4 *)(param_1 + 0x34);
        param_2[5] = *(undefined4 *)(param_1 + 0x38);
        puVar5 = *(uint **)(param_1 + 0xc);
        uVar7 = *(uint *)(param_1 + 0x10);
        uVar6 = 0;
        puVar10 = puStack_1c;
        if (uVar7 != 0) {
          do {
            uVar1 = *puVar5;
            *puVar10 = CONCAT31((int3)uVar6,*(undefined *)puVar5);
            puVar10[1] = (uVar1 & 0xffffff) >> 0x17;
            puVar10[2] = (uVar1 & 0x7fffff) >> 0x16;
            puVar10[3] = (uVar1 & 0x3fffff) >> 0x15;
            puVar10[4] = uVar1 & 0x1f0000;
            *(undefined2 *)(puVar10 + 5) = 0;
            *(sword *)((int)puVar10 + 0x16) = (sword)uVar1;
            puVar10[6] = puVar5[1];
            puVar10[7] = puVar5[2];
            puVar10[8] = puVar5[3];
            puVar5 = puVar5 + 4;
            uVar6 = uVar6 + 1;
            puVar10 = puVar10 + 9;
          } while (uVar6 < uVar7);
        }
        puVar5 = (uint *)_ipc_splay_traverse_start(param_1 + 0x18);
        puVar10 = puStack_18;
        while (puVar5 != (uint *)0x0) {
          uVar7 = *puVar5;
          *puVar10 = puVar5[4];
          puVar10[1] = (uVar7 & 0xffffff) >> 0x17;
          puVar10[2] = (uVar7 & 0x7fffff) >> 0x16;
          puVar10[3] = (uVar7 & 0x3fffff) >> 0x15;
          puVar10[4] = uVar7 & 0x1f0000;
          *(undefined2 *)(puVar10 + 5) = 0;
          *(sword *)((int)puVar10 + 0x16) = (sword)uVar7;
          puVar10[6] = puVar5[1];
          puVar10[7] = puVar5[2];
          puVar10[8] = puVar5[3];
          if (puVar5[6] == 0) {
            puVar10[9] = 0;
          }
          else {
            puVar10[9] = *(uint *)(puVar5[6] + 0x10);
          }
          if (puVar5[7] == 0) {
            puVar10[10] = 0;
          }
          else {
            puVar10[10] = *(uint *)(puVar5[7] + 0x10);
          }
          puVar5 = (uint *)_ipc_splay_traverse_next(param_1 + 0x18,0);
          puVar10 = puVar10 + 0xb;
        }
        _ipc_splay_traverse_finish(param_1 + 0x18);
        if (puStack_1c == (uint *)*param_3) {
          *param_4 = uVar2;
        }
        else if (uVar2 == 0) {
          _kmem_free(_ipc_kernel_map,puStack_8,uVar8);
          *param_4 = 0;
        }
        else {
          uVar7 = ~_page_mask & _page_mask + uVar2 * 0x24;
          if (uVar8 != uVar7) {
            _kmem_free(_ipc_kernel_map,uVar7 + (int)puStack_8,uVar8 - uVar7);
          }
          if (uVar7 != uVar2 * 0x24) {
            _bzero(puStack_8 + uVar2 * 9,uVar7 + uVar2 * -0x24);
          }
          _vm_move(_ipc_kernel_map,puStack_8,_ipc_soft_map,uVar7,1,&iStack_10);
          *param_3 = iStack_10;
          *param_4 = uVar2;
        }
        if (puStack_18 != (uint *)*param_5) {
          if (uVar3 == 0) {
            _kmem_free(_ipc_kernel_map,puStack_c,uVar9);
            *param_6 = 0;
            return 0;
          }
          uVar8 = ~_page_mask & _page_mask + uVar3 * 0x2c;
          if (uVar9 != uVar8) {
            _kmem_free(_ipc_kernel_map,uVar8 + (int)puStack_c,uVar9 - uVar8);
          }
          if (uVar8 != uVar3 * 0x2c) {
            _bzero(puStack_c + uVar3 * 0xb,uVar8 + uVar3 * -0x2c);
          }
          _vm_move(_ipc_kernel_map,puStack_c,_ipc_soft_map,uVar8,1,&iStack_14);
          *param_5 = iStack_14;
        }
        *param_6 = uVar3;
        return 0;
      }
loc_4043F52:
      if (uVar6 < uVar3) {
        if (puStack_18 != (uint *)*param_5) {
          _kmem_free(_ipc_kernel_map,puStack_c,uVar9);
        }
        uVar9 = ~_page_mask & _page_mask + uVar3 * 0x2c;
        iVar4 = _kmem_alloc(_ipc_kernel_map,&puStack_c,uVar9);
        if (iVar4 != 0) {
          puStack_c = puStack_8;
          if (puStack_1c != (uint *)*param_3) {
loc_4043FC4:
            _kmem_free(_ipc_kernel_map,puStack_c,uVar8);
          }
          return 6;
        }
        puStack_18 = puStack_c;
        uVar6 = uVar9 / 0x2c;
      }
    }
    if (puStack_1c != (uint *)*param_3) {
      _kmem_free(_ipc_kernel_map,puStack_8,uVar8);
    }
    if (puStack_18 != (uint *)*param_5) {
      _kmem_free(_ipc_kernel_map,puStack_c,uVar9);
    }
  }
  return 0x10;
}
/* GHIDRADEC_FUNCTION index=1208 start=0x40442ae */

int _mach_port_dnrequest_info(int param_1,undefined4 param_2,uint *param_3,int *param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iStack_8;
  
  if (param_1 == 0) {
    iVar1 = 0x10;
  }
  else {
    iVar1 = _ipc_object_translate(param_1,param_2,1,&iStack_8);
    if (iVar1 == 0) {
      iVar1 = *(int *)(iStack_8 + 0x28);
      if (iVar1 == 0) {
        uVar4 = 0;
        iVar3 = 0;
      }
      else {
        uVar4 = **(uint **)(iVar1 + 4);
        uVar2 = 1;
        iVar3 = 0;
        if (1 < uVar4) {
          do {
            if (*(int *)(iVar1 + 0xc) != 0) {
              iVar3 = iVar3 + 1;
            }
            uVar2 = uVar2 + 1;
            iVar1 = iVar1 + 8;
          } while (uVar2 < uVar4);
        }
      }
      *param_3 = uVar4;
      *param_4 = iVar3;
      iVar1 = 0;
    }
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1209 start=0x4044324 */

int _mach_port_kernel_object
              (undefined4 param_1,undefined4 param_2,undefined2 *param_3,undefined4 *param_4)

{
  uint uVar1;
  int iVar2;
  uint *puStack_8;
  
  iVar2 = _ipc_right_lookup_write(param_1,param_2,&puStack_8);
  if (iVar2 == 0) {
    if ((*puStack_8 & 0x30000) != 0) {
      uVar1 = puStack_8[1];
      iVar2 = *(int *)(uVar1 + 4);
      if (iVar2 < 0) {
        *param_3 = 0;
        param_3[1] = (sword)iVar2;
        *param_4 = *(undefined4 *)(uVar1 + 0x10);
        return 0;
      }
    }
    iVar2 = 0x11;
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=1210 start=0x404437e */

uint _mach_msg_send(undefined4 param_1,byte param_2,undefined4 param_3,undefined4 param_4,
                   int param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iStack_8;
  
  uVar1 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x7c);
  uVar2 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 8);
  uVar3 = _ipc_kmsg_get(param_1,param_3,0,&iStack_8);
  if (uVar3 != 0) {
    return uVar3;
  }
  if ((char)param_2 < '\0') {
    iVar6 = param_5;
    if (param_5 == 0) {
      uVar3 = 0x1000000b;
      goto loc_40443FE;
    }
  }
  else {
    iVar6 = 0;
  }
  uVar3 = _ipc_kmsg_copyin(iStack_8,uVar1,uVar2,iVar6);
  if (uVar3 != 0) {
loc_40443FE:
    if (*(int *)(iStack_8 + 8) < 1) {
      _ipc_kmsg_free(iStack_8);
    }
    else {
      _kfree(iStack_8,*(int *)(iStack_8 + 8));
    }
    return uVar3;
  }
  if ((param_2 & 0x20) == 0) {
    uVar3 = _ipc_mqueue_send(iStack_8,param_2 & 0x10,param_4,0);
  }
  else {
    uVar4 = 0;
    if ((param_2 & 0x10) != 0) {
      uVar4 = param_4;
    }
    uVar3 = _ipc_mqueue_send(iStack_8,0x10,uVar4,0);
    if (uVar3 == 0x10000004) {
      if (param_5 == 0) {
        uVar3 = 0x1000000b;
      }
      else {
        uVar3 = _ipc_marequest_create(uVar1,*(undefined4 *)(iStack_8 + 0x1c),param_5,iStack_8 + 0xc)
        ;
        if (uVar3 == 0) {
          _ipc_mqueue_send(iStack_8,0x10000,0,0);
          return 0x10000005;
        }
      }
      goto loc_40444A8;
    }
  }
  if (uVar3 == 0) {
    return 0;
  }
loc_40444A8:
  uVar5 = _ipc_kmsg_copyout_pseudo(iStack_8,uVar1,uVar2);
  _ipc_kmsg_put(param_1,iStack_8,*(int *)(iStack_8 + 0x10) + *(int *)(iStack_8 + 0x18));
  return uVar5 | uVar3;
}
/* GHIDRADEC_FUNCTION index=1211 start=0x40444dc */

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
/* GHIDRADEC_FUNCTION index=1212 start=0x40446c6 */

void _mach_msg_receive_continue(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  int iStack_10;
  undefined4 uStack_c;
  int iStack_8;
  
  uVar6 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x7c);
  uVar1 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 8);
  iVar2 = *(int *)(_active_threads + 0xbc);
  uVar7 = *(uint *)(_active_threads + 0xc0);
  uVar3 = *(uint *)(_active_threads + 0xc4);
  iVar8 = *(int *)(_active_threads + 0xcc);
  uVar4 = *(undefined4 *)(_active_threads + 0xd0);
  if ((uVar7 & 0x800) == 0) {
    iVar5 = _ipc_mqueue_receive(*(undefined4 *)(_active_threads + 0xd4),uVar7 & 0x100,0xffffffff,
                                *(undefined4 *)(_active_threads + 200),1,_mach_msg_receive_continue,
                                &iStack_8,&uStack_c);
    _ipc_object_release(uVar4);
    if (iVar5 != 0) {
      _thread_syscall_return(iVar5);
    }
    *(undefined4 *)(iStack_8 + 0x24) = uStack_c;
    if (uVar3 < *(uint *)(iStack_8 + 0x18)) {
      _ipc_kmsg_copyout_dest(iStack_8,uVar6);
      _ipc_kmsg_put(iVar2,iStack_8,0x18);
      _thread_syscall_return(0x10004004);
    }
  }
  else {
    iVar5 = _ipc_mqueue_receive(*(undefined4 *)(_active_threads + 0xd4),uVar7 & 0x100,uVar3,
                                *(undefined4 *)(_active_threads + 200),1,_mach_msg_receive_continue,
                                &iStack_8,&uStack_c);
    _ipc_object_release(uVar4);
    if (iVar5 != 0) {
      if (iVar5 == 0x10004004) {
        iStack_10 = iStack_8;
        _copyoutmsg(&iStack_10,iVar2 + 4,4);
      }
      _thread_syscall_return(iVar5);
    }
    *(undefined4 *)(iStack_8 + 0x24) = uStack_c;
  }
  if ((uVar7 & 0x200) == 0) {
    iVar8 = 0;
loc_4044816:
    uVar7 = _ipc_kmsg_copyout(iStack_8,uVar6,uVar1,iVar8);
    if (uVar7 == 0) goto loc_4044882;
  }
  else {
    if (iVar8 != 0) goto loc_4044816;
    uVar7 = 0x10004007;
  }
  if ((uVar7 & 0xffffc3ff) == 0x1000400c) {
    _ipc_kmsg_put(iVar2,iStack_8,*(int *)(iStack_8 + 0x10) + *(int *)(iStack_8 + 0x18));
  }
  else {
    _ipc_kmsg_copyout_dest(iStack_8,uVar6);
    _ipc_kmsg_put(iVar2,iStack_8,0x18);
  }
  _thread_syscall_return(uVar7);
loc_4044882:
  uVar6 = _ipc_kmsg_put(iVar2,iStack_8,*(int *)(iStack_8 + 0x10) + *(int *)(iStack_8 + 0x18));
  _thread_syscall_return(uVar6);
  return;
}
/* GHIDRADEC_FUNCTION index=1213 start=0x40448ac */

/* WARNING: Type propagation algorithm not settling */

uint _mach_msg_trap(code ***param_1,code ***param_2,code ***param_3,code ***param_4,code **param_5,
                   code ***param_6,undefined4 param_7)

{
  code **ppcVar1;
  code *pcVar2;
  code *pcVar3;
  word wVar4;
  int iVar5;
  code **ppcVar6;
  code ***pppcVar7;
  uint uVar8;
  uint uVar9;
  code **ppcVar10;
  code **ppcVar11;
  code ***pppcVar12;
  code ***pppcVar13;
  code ***pppcVar14;
  code ***pppcVar15;
  code ****ppppcVar16;
  code ***pppcStack_64;
  code ***pppcStack_60;
  code ****ppppcStack_5c;
  code ****ppppcStack_58;
  code **ppcStack_28;
  code ***pppcStack_24;
  code **ppcStack_20;
  code **ppcStack_1c;
  code ***pppcStack_18;
  code **ppcStack_14;
  code **ppcStack_10;
  code **ppcStack_c;
  code ***pppcStack_8;
  
  pppcVar7 = _ipc_kmsg_cache;
  pppcVar13 = _active_threads;
  if (param_2 != (code ***)0x3) {
    if (param_2 == (code ***)0x1) {
      pppcVar13 = (code ***)_active_threads[3][0x1f];
      pppcVar7 = (code ***)_active_threads[3][2];
      ppppcStack_58 = &pppcStack_18;
      ppppcStack_5c = (code ****)0x0;
      pppcStack_60 = param_3;
      pppcStack_64 = param_1;
      uVar9 = _ipc_kmsg_get();
      if (uVar9 != 0) {
        return uVar9;
      }
      ppppcStack_58 = (code ****)0x0;
      pppcStack_64 = pppcStack_18;
      pppcStack_60 = pppcVar13;
      ppppcStack_5c = (code ****)pppcVar7;
      uVar9 = _ipc_kmsg_copyin();
      if (uVar9 == 0) {
        ppppcStack_58 = (code ****)0x0;
        ppppcStack_5c = (code ****)0x0;
        pppcStack_60 = (code ***)0x0;
        pppcStack_64 = pppcStack_18;
        uVar9 = _ipc_mqueue_send();
        if (uVar9 != 0) {
          pppcStack_60 = pppcStack_18;
          pppcStack_64 = (code ***)0x4045300;
          ppppcStack_5c = (code ****)pppcVar13;
          ppppcStack_58 = (code ****)pppcVar7;
          uVar8 = _ipc_kmsg_copyout_pseudo();
          pppcStack_64 = (code ***)((int)pppcStack_18[4] + (int)pppcStack_18[6]);
          _ipc_kmsg_put(param_1,pppcStack_18);
          return uVar8 | uVar9;
        }
        return 0;
      }
      ppppcStack_58 = (code ****)pppcStack_18[2];
      if (0 < (int)ppppcStack_58) {
        ppppcStack_5c = (code ****)pppcStack_18;
        pppcStack_60 = (code ***)0x40452a6;
        _kfree();
        return uVar9;
      }
      ppppcStack_58 = (code ****)pppcStack_18;
      ppppcStack_5c = (code ****)0x40452d4;
      _ipc_kmsg_free();
      return uVar9;
    }
    if (param_2 == (code ***)0x2) {
      pppcVar7 = (code ***)_active_threads[3][0x1f];
      pppcVar14 = (code ***)_active_threads[3][2];
      ppppcStack_58 = (code ****)&ppcStack_20;
      ppppcStack_5c = (code ****)&ppcStack_1c;
      pppcStack_60 = (code ***)param_5;
      pppcStack_64 = pppcVar7;
      uVar9 = _ipc_mqueue_copyin();
      if (uVar9 != 0) {
        return uVar9;
      }
      pppcVar13[0x2f] = (code **)param_1;
      pppcVar13[0x31] = (code **)param_4;
      pppcVar13[0x34] = ppcStack_20;
      pppcVar13[0x35] = ppcStack_1c;
      ppppcStack_58 = (code ****)&ppcStack_28;
      ppppcStack_5c = &pppcStack_24;
      pppcStack_60 = (code ***)_mach_msg_continue;
      pppcStack_64 = (code ***)0x0;
      uVar9 = _ipc_mqueue_receive(ppcStack_1c,0,0xffffffff,0);
      ppppcStack_58 = (code ****)ppcStack_20;
      ppppcStack_5c = (code ****)0x40453a2;
      _ipc_object_release();
      if (uVar9 != 0) {
        return uVar9;
      }
      pppcStack_24[9] = ppcStack_28;
      if (param_4 < pppcStack_24[6]) {
        ppppcStack_5c = (code ****)pppcStack_24;
        pppcStack_60 = (code ***)0x40453cc;
        ppppcStack_58 = (code ****)pppcVar7;
        _ipc_kmsg_copyout_dest();
        pppcStack_60 = (code ***)0x18;
        pppcStack_64 = pppcStack_24;
        _ipc_kmsg_put(param_1);
        return 0x10004004;
      }
      ppppcStack_58 = (code ****)0x0;
      pppcStack_64 = pppcStack_24;
      pppcStack_60 = pppcVar7;
      ppppcStack_5c = (code ****)pppcVar14;
      uVar9 = _ipc_kmsg_copyout();
      if (uVar9 == 0) {
        ppppcStack_58 = (code ****)((int)pppcStack_24[4] + (int)pppcStack_24[6]);
        ppppcStack_5c = (code ****)pppcStack_24;
        pppcStack_60 = param_1;
        pppcStack_64 = (code ***)0x4045452;
        uVar9 = _ipc_kmsg_put();
        return uVar9;
      }
      if ((uVar9 & 0xffffc3ff) == 0x1000400c) {
        ppppcStack_58 = (code ****)((int)pppcStack_24[4] + (int)pppcStack_24[6]);
        ppppcVar16 = (code ****)&ppppcStack_5c;
        ppppcStack_5c = (code ****)pppcStack_24;
      }
      else {
        ppppcStack_5c = (code ****)pppcStack_24;
        pppcStack_60 = (code ***)0x4045426;
        ppppcStack_58 = (code ****)pppcVar7;
        _ipc_kmsg_copyout_dest();
        pppcStack_60 = (code ***)0x18;
        ppppcVar16 = &pppcStack_64;
        pppcStack_64 = pppcStack_24;
      }
      *(code ****)((int)ppppcVar16 + -4) = param_1;
      *(undefined4 *)((int)ppppcVar16 + -8) = 0x4045436;
      _ipc_kmsg_put();
      return uVar9;
    }
    if (param_2 == (code ***)0x0) {
      ppppcStack_58 = (code ****)0x0;
      ppppcStack_5c = (code ****)0x4045462;
      _thread_syscall_return();
    }
    goto loc_4045464;
  }
  pppcVar14 = (code ***)_active_threads[3][0x1f];
  if (((param_3 + -6 < (code ***)0xd5) && (((uint)param_3 & 3) == 0)) &&
     (_ipc_kmsg_cache != (code ***)0x0)) {
    _ipc_kmsg_cache = (code ***)0x0;
    pppcVar7[4] = (code **)0x0;
    ppppcStack_58 = (code ****)param_3;
    ppppcStack_5c = (code ****)(pppcVar7 + 5);
    pppcStack_60 = param_1;
    pppcStack_64 = (code ***)0x4044910;
    iVar5 = _copyinmsg();
    if (iVar5 != 0) {
      ppppcStack_58 = (code ****)pppcVar7[2];
      if ((int)ppppcStack_58 < 1) {
        ppppcStack_58 = (code ****)pppcVar7;
        ppppcStack_5c = (code ****)0x4044928;
        _ipc_kmsg_free();
      }
      else {
        ppppcStack_5c = (code ****)pppcVar7;
        pppcStack_60 = (code ***)0x4044f4c;
        _kfree();
      }
      goto loc_4044F4E;
    }
    pppcVar7[4] = (code **)0x0;
    pppcVar7[6] = (code **)param_3;
  }
  else {
loc_4044F4E:
    ppppcStack_58 = &pppcStack_8;
    ppppcStack_5c = (code ****)0x0;
    pppcStack_60 = param_3;
    pppcStack_64 = param_1;
    ppppcStack_58 = (code ****)_ipc_kmsg_get();
    pppcVar7 = pppcStack_8;
    if (ppppcStack_58 != (code ****)0x0) {
      ppppcStack_5c = (code ****)0x4044f70;
      _thread_syscall_return();
      pppcVar7 = pppcStack_8;
    }
  }
  if (pppcVar7[5] == (code **)0x12) {
    if (pppcVar7[8] == (code **)0x0) {
      ppcVar10 = pppcVar14[4];
      ppcVar6 = pppcVar14[3];
      ppcVar11 = (code **)((uint)pppcVar7[7] >> 8);
      pcVar3 = (code *)((int)pppcVar7[7] << 0x18);
      if ((((ppcVar10 <= ppcVar11) ||
           (ppcVar1 = ppcVar6 + (int)ppcVar11 * 4,
           ((uint)pcVar3 | 0x40000) != ((uint)*ppcVar1 & 0xff840000))) ||
          (ppcVar1[2] != (code *)0x0)) || (pppcVar15 = (code ***)ppcVar1[1], -1 < (int)pppcVar15[1])
         ) goto loc_4044F88;
      ppcVar1[2] = ppcVar6[2];
      ppcVar6[2] = (code *)ppcVar11;
      *ppcVar1 = pcVar3;
      ppcVar1[1] = (code *)0x0;
      pppcVar7[5] = (code **)0x12;
      pppcVar7[7] = (code **)pppcVar15;
      if (ppcVar10 <= (code **)((uint)param_5 >> 8)) goto loc_40450B2;
      ppcVar6 = ppcVar6 + (int)((uint)param_5 >> 8) * 4;
      pcVar3 = *ppcVar6;
      if ((int)param_5 << 0x18 != ((uint)pcVar3 & 0xff000000)) goto loc_40450B2;
      if (((uint)pcVar3 & 0x80000) == 0) {
        if ((((uint)pcVar3 & 0x20000) == 0) ||
           (ppcVar6 = (code **)ppcVar6[1], ppcVar6[0xb] != (code *)0x0)) goto loc_40450B2;
        iVar5 = 0x3c;
      }
      else {
        ppcVar6 = (code **)ppcVar6[1];
        iVar5 = 0xc;
      }
      ppcVar10 = (code **)((int)ppcVar6 + iVar5);
      *ppcVar6 = *ppcVar6 + 1;
loc_4044ACA:
      if (pppcVar15[0xb] == (code **)0x0) {
        pppcVar12 = pppcVar15 + 0xf;
      }
      else {
        pppcVar12 = (code ***)(pppcVar15[0xb] + 3);
      }
      ppcVar11 = pppcVar12[1];
      if ((ppcVar11 != (code **)0x0) && (*ppcVar10 == (code *)0x0)) {
        pppcVar13[0x2f] = (code **)param_1;
        pppcVar13[0x31] = (code **)param_4;
        pppcVar13[0x34] = ppcVar6;
        pppcVar13[0x35] = ppcVar10;
        if (ppcVar11[0xc] == _mach_msg_continue) {
          ppppcStack_5c = (code ****)_mach_msg_continue;
          pppcStack_60 = pppcVar13;
          pppcStack_64 = (code ***)0x4044b42;
          ppppcStack_58 = (code ****)ppcVar11;
          iVar5 = _thread_handoff();
          if (iVar5 == 0) goto loc_4044B50;
loc_4044CBC:
          ppcVar6 = (code **)ppcVar10[1];
          if (ppcVar6 == (code **)0x0) {
            ppcVar10[1] = (code *)pppcVar13;
          }
          else {
            ppcVar10 = (code **)ppcVar6[0x24];
            pppcVar13[0x23] = ppcVar6;
            pppcVar13[0x24] = ppcVar10;
            ppcVar6[0x24] = (code *)pppcVar13;
            ppcVar10[0x23] = (code *)pppcVar13;
          }
          pppcVar13[0x25] = (code **)0x10004001;
          pppcVar13[0x26] = (code **)0xffffffff;
          ppcVar6 = (code **)ppcVar11[0x23];
          if (ppcVar11 == ppcVar6) {
            pppcVar12[1] = (code **)0x0;
          }
          else {
            pcVar3 = ppcVar11[0x24];
            pppcVar12[1] = ppcVar6;
            ppcVar6[0x24] = pcVar3;
            *(code ***)(pcVar3 + 0x8c) = ppcVar6;
            ppcVar11[0x23] = (code *)ppcVar11;
            ppcVar11[0x24] = (code *)ppcVar11;
          }
          pppcVar7[9] = pppcVar15[0xc];
          pppcVar15[0xc] = (code **)((int)pppcVar15[0xc] + 1);
          pppcVar14 = *(code ****)(ppcVar11[3] + 0x7c);
          param_1 = (code ***)ppcVar11[0x2f];
          param_4 = (code ***)ppcVar11[0x31];
          ppppcStack_58 = (code ****)ppcVar11[0x34];
          ppcVar6 = (code **)*ppppcStack_58;
          *ppppcStack_58 = (code ***)((int)ppcVar6 + -1);
          if (ppcVar6 == (code **)0x1) {
            wVar4 = *(word *)(ppppcStack_58 + 1);
            goto loc_4044D44;
          }
          goto loc_4044D5C;
        }
loc_4044B50:
        if (ppcVar11[0xc] == _exception_raise_continue) {
          ppppcStack_5c = (code ****)_mach_msg_continue;
          pppcStack_60 = pppcVar13;
          pppcStack_64 = (code ***)0x4044b70;
          ppppcStack_58 = (code ****)ppcVar11;
          iVar5 = _thread_handoff();
          if (iVar5 != 0) {
            ppcVar6 = (code **)ppcVar10[1];
            if (ppcVar6 == (code **)0x0) {
              ppcVar10[1] = (code *)pppcVar13;
            }
            else {
              ppcVar10 = (code **)ppcVar6[0x24];
              pppcVar13[0x23] = ppcVar6;
              pppcVar13[0x24] = ppcVar10;
              ppcVar6[0x24] = (code *)pppcVar13;
              ppcVar10[0x23] = (code *)pppcVar13;
            }
            pppcVar13[0x25] = (code **)0x10004001;
            pppcVar13[0x26] = (code **)0xffffffff;
            ppcVar6 = (code **)ppcVar11[0x23];
            if (ppcVar11 == ppcVar6) {
              pppcVar12[1] = (code **)0x0;
            }
            else {
              pcVar3 = ppcVar11[0x24];
              pppcVar12[1] = ppcVar6;
              ppcVar6[0x24] = pcVar3;
              *(code ***)(pcVar3 + 0x8c) = ppcVar6;
              ppcVar11[0x23] = (code *)ppcVar11;
              ppcVar11[0x24] = (code *)ppcVar11;
            }
            pppcStack_60 = (code ***)0x4044bdc;
            ppppcStack_5c = (code ****)pppcVar15;
            ppppcStack_58 = (code ****)pppcVar7;
            _exception_raise_continue_fast();
            return 0;
          }
        }
        if (param_3 <= ppcVar11[0x26]) {
          ppppcStack_5c = (code ****)_mach_msg_continue;
          pppcStack_60 = pppcVar13;
          pppcStack_64 = (code ***)0x4044c12;
          ppppcStack_58 = (code ****)ppcVar11;
          iVar5 = _thread_handoff();
          if (iVar5 != 0) {
            if ((ppcVar11[0xc] != _mach_msg_receive_continue) ||
               (((byte)*(code *)((int)ppcVar11 + 0xc2) & 2) != 0)) {
              pppcVar15[0xd] = (code **)((int)pppcVar15[0xd] + 1);
              ppcVar6 = (code **)ppcVar10[1];
              if (ppcVar6 == (code **)0x0) {
                ppcVar10[1] = (code *)pppcVar13;
              }
              else {
                ppcVar10 = (code **)ppcVar6[0x24];
                pppcVar13[0x23] = ppcVar6;
                pppcVar13[0x24] = ppcVar10;
                ppcVar6[0x24] = (code *)pppcVar13;
                ppcVar10[0x23] = (code *)pppcVar13;
              }
              pppcVar13[0x25] = (code **)0x10004001;
              pppcVar13[0x26] = (code **)0xffffffff;
              ppcVar6 = (code **)ppcVar11[0x23];
              if (ppcVar11 == ppcVar6) {
                pppcVar12[1] = (code **)0x0;
              }
              else {
                pcVar3 = ppcVar11[0x24];
                pppcVar12[1] = ppcVar6;
                ppcVar6[0x24] = pcVar3;
                *(code ***)(pcVar3 + 0x8c) = ppcVar6;
                ppcVar11[0x23] = (code *)ppcVar11;
                ppcVar11[0x24] = (code *)ppcVar11;
              }
              ppcVar11[0x25] = (code *)0x0;
              ppcVar11[0x26] = (code *)pppcVar7;
              ppcVar11[0x27] = (code *)pppcVar15[0xc];
              pppcVar15[0xc] = (code **)((int)pppcVar15[0xc] + 1);
              ppcVar11[0x10] = (code *)0x0;
              ppppcStack_58 = (code ****)0x4044ca8;
              (*ppcVar11[0xc])();
              return 0;
            }
            goto loc_4044CBC;
          }
        }
      }
      ppppcStack_5c = (code ****)0x4044ae6;
      ppppcStack_58 = (code ****)ppcVar6;
      _ipc_object_release();
    }
    else {
loc_4044F88:
      ppppcStack_58 = (code ****)0x0;
      ppppcStack_5c = (code ****)_active_threads[3][2];
      pppcStack_64 = pppcVar7;
      pppcStack_60 = pppcVar14;
      iVar5 = _ipc_kmsg_copyin();
      if (iVar5 != 0) {
        ppppcStack_58 = (code ****)pppcVar7[2];
        if ((int)ppppcStack_58 < 1) {
          ppppcStack_5c = (code ****)0x4044fb8;
          ppppcStack_58 = (code ****)pppcVar7;
          _ipc_kmsg_free();
        }
        else {
          pppcStack_60 = (code ***)0x4044f84;
          ppppcStack_5c = (code ****)pppcVar7;
          _kfree();
        }
        ppppcStack_5c = (code ****)0x4044fc2;
        ppppcStack_58 = (code ****)iVar5;
        _thread_syscall_return();
      }
      if (((uint)pppcVar7[5] & 0x40000000) == 0) {
        pppcVar15 = (code ***)pppcVar7[7];
        if (pppcVar15[2] == _ipc_space_kernel) goto loc_404503C;
        if (((((int)pppcVar15[1] < 0) &&
             (((pppcVar15[0xd] < pppcVar15[0xe] || ((char)pppcVar7[5] == '\x12')) &&
              (ppcVar6 = pppcVar7[8], ppcVar6 != (code **)0x0)))) &&
            ((ppcVar6 != (code **)0xffffffff && ((int)ppcVar6[1] < 0)))) &&
           ((pppcVar14 == (code ***)ppcVar6[2] && (param_5 == (code **)ppcVar6[3])))) {
loc_4045028:
          if (ppcVar6[0xb] == (code *)0x0) {
            *ppcVar6 = *ppcVar6 + 1;
            ppcVar10 = ppcVar6 + 0xf;
            goto loc_4044ACA;
          }
        }
      }
    }
loc_40450B2:
    ppppcStack_58 = (code ****)0x0;
    ppppcStack_5c = (code ****)0x0;
    pppcStack_60 = (code ***)0x0;
    pppcStack_64 = pppcVar7;
    uVar9 = _ipc_mqueue_send();
    if (uVar9 != 0) {
      ppppcStack_58 = (code ****)_active_threads[3][2];
      pppcStack_64 = (code ***)0x40450e0;
      pppcStack_60 = pppcVar7;
      ppppcStack_5c = (code ****)pppcVar14;
      uVar8 = _ipc_kmsg_copyout_pseudo();
      pppcStack_64 = (code ***)((int)pppcVar7[4] + (int)pppcVar7[6]);
      _ipc_kmsg_put(param_1,pppcVar7);
      _thread_syscall_return(uVar8 | uVar9);
    }
loc_4045102:
    ppppcStack_58 = (code ****)&ppcStack_10;
    ppppcStack_5c = (code ****)&ppcStack_c;
    pppcStack_60 = (code ***)param_5;
    pppcStack_64 = pppcVar14;
    ppppcStack_58 = (code ****)_ipc_mqueue_copyin();
    if (ppppcStack_58 != (code ****)0x0) {
      ppppcStack_5c = (code ****)0x4045126;
      _thread_syscall_return();
    }
    pppcVar13[0x2f] = (code **)param_1;
    pppcVar13[0x31] = (code **)param_4;
    pppcVar13[0x34] = ppcStack_10;
    pppcVar13[0x35] = ppcStack_c;
    ppppcStack_58 = (code ****)&ppcStack_14;
    ppppcStack_5c = &pppcStack_8;
    pppcStack_60 = (code ***)_mach_msg_continue;
    pppcStack_64 = (code ***)0x0;
    iVar5 = _ipc_mqueue_receive(ppcStack_c,0,0xffffffff,0);
    ppppcStack_58 = (code ****)ppcStack_10;
    ppppcStack_5c = (code ****)0x404517a;
    _ipc_object_release();
    if (iVar5 != 0) {
      ppppcStack_5c = (code ****)0x4045188;
      ppppcStack_58 = (code ****)iVar5;
      _thread_syscall_return();
    }
    pppcStack_8[9] = ppcStack_14;
    pppcVar15 = (code ***)pppcStack_8[7];
    pppcVar7 = pppcStack_8;
  }
  else {
    if ((pppcVar7[5] != (code **)0x1513) || (param_5 != pppcVar7[8])) goto loc_4044F88;
    if ((pppcVar14[4] <= (code **)((uint)param_5 >> 8)) ||
       (ppcVar6 = pppcVar14[3] + (int)((uint)param_5 >> 8) * 4,
       ((int)param_5 << 0x18 | 0x20000U) != ((uint)*ppcVar6 & 0xff020000))) goto loc_4044F88;
    ppcVar6 = (code **)ppcVar6[1];
    ppcVar10 = (code **)((uint)pppcVar7[7] >> 8);
    if (((pppcVar14[4] <= ppcVar10) ||
        (ppcVar10 = pppcVar14[3] + (int)ppcVar10 * 4,
        ((int)pppcVar7[7] << 0x18 | 0x10000U) != ((uint)*ppcVar10 & 0xff010000))) ||
       (pppcVar15 = (code ***)ppcVar10[1], -1 < (int)pppcVar15[1])) goto loc_4044F88;
    pppcVar15[6] = (code **)((int)pppcVar15[6] + 1);
    *pppcVar15 = (code **)((int)*pppcVar15 + 1);
    ppcVar6[7] = ppcVar6[7] + 1;
    *ppcVar6 = *ppcVar6 + 1;
    pppcVar7[5] = (code **)0x1211;
    pppcVar7[7] = (code **)pppcVar15;
    pppcVar7[8] = ppcVar6;
    if (pppcVar15[2] != _ipc_space_kernel) {
      if (pppcVar15[0xe] <= pppcVar15[0xd]) goto loc_40450B2;
      goto loc_4045028;
    }
loc_404503C:
    ppppcStack_5c = (code ****)0x4045044;
    ppppcStack_58 = (code ****)pppcVar7;
    pppcVar7 = (code ***)_ipc_kobject_server();
    if (pppcVar7 == (code ***)0x0) goto loc_4045102;
    pppcVar15 = (code ***)pppcVar7[7];
    if (((-1 < (int)pppcVar15[1]) || (pppcVar14 != (code ***)pppcVar15[2])) ||
       (((param_5 != pppcVar15[3] ||
         ((pppcVar15[0xb] != (code **)0x0 || (pppcVar15[0x10] != (code **)0x0)))) ||
        (pppcVar15[0xf] != (code **)0x0)))) {
      ppppcStack_58 = (code ****)0x0;
      ppppcStack_5c = (code ****)0x0;
      pppcStack_60 = (code ***)0x10000;
      pppcStack_64 = pppcVar7;
      _ipc_mqueue_send();
      goto loc_4045102;
    }
    pppcVar7[9] = pppcVar15[0xc];
    pppcVar15[0xc] = (code **)((int)pppcVar15[0xc] + 1);
    if (*pppcVar15 == (code **)0x0) {
      wVar4 = *(word *)(pppcVar15 + 1);
      ppppcStack_58 = (code ****)pppcVar15;
loc_4044D44:
      ppppcStack_5c = (code ****)(&_ipc_object_zones)[wVar4 & 0x7fff];
      pppcStack_60 = (code ***)0x4044d5a;
      _zfree();
    }
  }
loc_4044D5C:
  pppcVar13 = (code ***)((int)pppcVar7[4] + (int)pppcVar7[6]);
  if (param_4 < pppcVar13) {
loc_404519C:
    pppcVar13 = (code ***)((int)pppcVar7[4] + (int)pppcVar7[6]);
    if (param_4 < pppcVar13) {
      pppcStack_60 = (code ***)0x40451b4;
      ppppcStack_5c = (code ****)pppcVar7;
      ppppcStack_58 = (code ****)pppcVar14;
      _ipc_kmsg_copyout_dest();
      pppcStack_60 = (code ***)0x18;
      pppcStack_64 = pppcVar7;
      _ipc_kmsg_put(param_1);
      _thread_syscall_return(0x10004004);
    }
    ppppcStack_58 = (code ****)0x0;
    ppppcStack_5c = (code ****)_active_threads[3][2];
    pppcStack_64 = pppcVar7;
    pppcStack_60 = pppcVar14;
    uVar9 = _ipc_kmsg_copyout();
    if (uVar9 != 0) {
      if ((uVar9 & 0xffffc3ff) == 0x1000400c) {
        ppppcStack_58 = (code ****)((int)pppcVar7[4] + (int)pppcVar7[6]);
        pppcStack_64 = (code ***)0x4045216;
        pppcStack_60 = param_1;
        ppppcStack_5c = (code ****)pppcVar7;
        _ipc_kmsg_put();
      }
      else {
        pppcStack_60 = (code ***)0x4045226;
        ppppcStack_5c = (code ****)pppcVar7;
        ppppcStack_58 = (code ****)pppcVar14;
        _ipc_kmsg_copyout_dest();
        pppcStack_60 = (code ***)0x18;
        pppcStack_64 = pppcVar7;
        _ipc_kmsg_put(param_1);
      }
      ppppcStack_5c = (code ****)0x4045240;
      ppppcStack_58 = (code ****)uVar9;
      _thread_syscall_return();
    }
  }
  else {
    ppcVar6 = pppcVar7[5];
    if (ppcVar6 == (code **)0x1211) {
      ppcVar6 = pppcVar7[8];
      if ((((ppcVar6 != (code **)0x0) && (ppcVar6 != (code **)0xffffffff)) &&
          ((int)pppcVar15[1] < 0)) && ((int)ppcVar6[1] < 0)) {
        ppcVar10 = pppcVar14[3];
        pcVar3 = ppcVar10[2];
        if (pcVar3 != (code *)0x0) {
          ppcVar11 = ppcVar10 + (int)pcVar3 * 4;
          ppcVar10[2] = ppcVar11[2];
          ppcVar11[2] = (code *)0x0;
          pcVar2 = *ppcVar11;
          *ppcVar11 = (code *)((uint)(pcVar2 + 0x1000000) | 0x40001);
          ppcVar11[1] = (code *)ppcVar6;
          *pppcVar15 = (code **)((int)*pppcVar15 + -1);
          ppcVar6 = (code **)0x0;
          if (pppcVar14 == (code ***)pppcVar15[2]) {
            ppcVar6 = pppcVar15[3];
          }
          ppcVar10 = pppcVar15[6];
          pppcVar15[6] = (code **)((int)ppcVar10 + -1);
          if ((ppcVar10 == (code **)0x1) &&
             (ppppcStack_5c = (code ****)pppcVar15[8], ppppcStack_5c != (code ****)0x0)) {
            ppppcStack_58 = (code ****)pppcVar15[5];
            pppcVar15[8] = (code **)0x0;
            pppcStack_60 = (code ***)0x4044e2e;
            _ipc_notify_no_senders();
          }
          pppcVar7[5] = (code **)0x1112;
          pppcVar7[7] = (code **)((uint)(pcVar2 + 0x1000000) >> 0x18 | (int)pcVar3 << 8);
          pppcVar7[8] = ppcVar6;
          goto loc_4044F00;
        }
      }
      goto loc_404519C;
    }
    ppppcStack_58 = (code ****)pppcVar15;
    if (ppcVar6 < (code **)0x1212) {
      if ((ppcVar6 != (code **)0x12) || (-1 < (int)pppcVar15[1])) goto loc_404519C;
      if (pppcVar14 == (code ***)pppcVar15[2]) {
        *pppcVar15 = (code **)((int)*pppcVar15 + -1);
        pppcVar15[7] = (code **)((int)pppcVar15[7] + -1);
        ppcVar6 = pppcVar15[3];
      }
      else {
        ppppcStack_5c = (code ****)0x4044e66;
        _ipc_notify_send_once();
        ppcVar6 = (code **)0x0;
      }
      pppcVar7[5] = (code **)0x1200;
      pppcVar7[7] = (code **)0x0;
      pppcVar7[8] = ppcVar6;
    }
    else {
      if ((ppcVar6 != (code **)0x80000012) || (-1 < (int)pppcVar15[1])) goto loc_404519C;
      if (pppcVar14 == (code ***)pppcVar15[2]) {
        *pppcVar15 = (code **)((int)*pppcVar15 + -1);
        pppcVar15[7] = (code **)((int)pppcVar15[7] + -1);
        ppcVar6 = pppcVar15[3];
      }
      else {
        ppppcStack_5c = (code ****)0x4044ea0;
        _ipc_notify_send_once();
        ppcVar6 = (code **)0x0;
      }
      pppcVar7[5] = (code **)0x80001200;
      pppcVar7[7] = (code **)0x0;
      pppcVar7[8] = ppcVar6;
      ppppcStack_58 = (code ****)_active_threads[3][2];
      pppcStack_60 = (code ***)((int)pppcVar7 + (int)(pppcVar7[6] + 5));
      pppcStack_64 = pppcVar7 + 0xb;
      ppppcStack_5c = (code ****)pppcVar14;
      uVar9 = _ipc_kmsg_copyout_body();
      if (uVar9 != 0) {
        ppppcStack_58 = (code ****)((int)pppcVar7[4] + (int)pppcVar7[6]);
        pppcStack_64 = (code ***)0x4044ef4;
        pppcStack_60 = param_1;
        ppppcStack_5c = (code ****)pppcVar7;
        _ipc_kmsg_put();
        return uVar9 | 0x1000400c;
      }
    }
  }
loc_4044F00:
  pppcVar7[4] = (code **)0x0;
  if (pppcVar7[2] == (code **)0x100) {
    pppcStack_60 = pppcVar7 + 5;
    pppcStack_64 = (code ***)0x4044f1e;
    ppppcStack_5c = (code ****)param_1;
    ppppcStack_58 = (code ****)pppcVar13;
    iVar5 = _copyoutmsg();
    if ((iVar5 == 0) && (_ipc_kmsg_cache == (code ***)0x0)) {
      ppppcStack_58 = (code ****)0x0;
      ppppcStack_5c = (code ****)0x4044f3e;
      _ipc_kmsg_cache = pppcVar7;
      _thread_syscall_return();
      return 0;
    }
  }
  pppcStack_64 = (code ***)0x4045252;
  pppcStack_60 = param_1;
  ppppcStack_5c = (code ****)pppcVar7;
  ppppcStack_58 = (code ****)pppcVar13;
  pppcStack_64 = (code ***)_ipc_kmsg_put();
  _thread_syscall_return();
loc_4045464:
  if (((uint)param_2 & 1) != 0) {
    ppppcStack_58 = (code ****)param_7;
    ppppcStack_5c = (code ****)param_6;
    pppcStack_60 = param_3;
    pppcStack_64 = param_2;
    uVar9 = _mach_msg_send(param_1);
    if (uVar9 != 0) {
      return uVar9;
    }
  }
  if (((uint)param_2 & 2) != 0) {
    ppppcStack_58 = (code ****)param_7;
    ppppcStack_5c = (code ****)param_6;
    pppcStack_60 = (code ***)param_5;
    pppcStack_64 = param_4;
    uVar9 = _mach_msg_receive(param_1,param_2);
    if (uVar9 != 0) {
      return uVar9;
    }
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=1214 start=0x40454c0 */

void _mach_msg_continue(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uStack_c;
  int iStack_8;
  
  uVar6 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x7c);
  uVar1 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 8);
  uVar2 = *(undefined4 *)(_active_threads + 0xbc);
  uVar5 = *(uint *)(_active_threads + 0xc4);
  uVar3 = *(undefined4 *)(_active_threads + 0xd0);
  iVar4 = _ipc_mqueue_receive(*(undefined4 *)(_active_threads + 0xd4),0,0xffffffff,0,1,
                              _mach_msg_continue,&iStack_8,&uStack_c);
  _ipc_object_release(uVar3);
  if (iVar4 != 0) {
    _thread_syscall_return(iVar4);
  }
  *(undefined4 *)(iStack_8 + 0x24) = uStack_c;
  if (uVar5 < *(uint *)(iStack_8 + 0x18)) {
    _ipc_kmsg_copyout_dest(iStack_8,uVar6);
    _ipc_kmsg_put(uVar2,iStack_8,0x18);
    _thread_syscall_return(0x10004004);
  }
  uVar5 = _ipc_kmsg_copyout(iStack_8,uVar6,uVar1,0);
  if (uVar5 != 0) {
    if ((uVar5 & 0xffffc3ff) == 0x1000400c) {
      _ipc_kmsg_put(uVar2,iStack_8,*(int *)(iStack_8 + 0x10) + *(int *)(iStack_8 + 0x18));
    }
    else {
      _ipc_kmsg_copyout_dest(iStack_8,uVar6);
      _ipc_kmsg_put(uVar2,iStack_8,0x18);
    }
    _thread_syscall_return(uVar5);
  }
  uVar6 = _ipc_kmsg_put(uVar2,iStack_8,*(int *)(iStack_8 + 0x10) + *(int *)(iStack_8 + 0x18));
  _thread_syscall_return(uVar6);
  return;
}
/* GHIDRADEC_FUNCTION index=1215 start=0x40455f8 */

bool _mach_msg_interrupt(int param_1)

{
  bool bVar1;
  
  bVar1 = *(int *)(param_1 + 0x94) == 0x10004001;
  if (bVar1) {
    _ipc_thread_rmqueue(*(int *)(param_1 + 0xd4) + 4,param_1);
    _ipc_object_release(*(undefined4 *)(param_1 + 0xd0));
    _thread_set_syscall_return(param_1,0x10004005);
    *(code **)(param_1 + 0x30) = _thread_exception_return;
  }
  return bVar1;
}
/* GHIDRADEC_FUNCTION index=1216 start=0x404564a */

undefined4 _msg_return_translate(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 & 0xffffc3ff;
  if ((int)uVar1 < 0x1000000f) {
    if (0x1000000c < (int)uVar1) {
      _printf(aMsgReturnTrans,param_1);
      return 0xffffff94;
    }
    if (uVar1 == 0x10000006) {
      return 0xffffff96;
    }
    if ((int)uVar1 < 0x10000007) {
      if (uVar1 == 0x10000002) {
        return 0xffffff9b;
      }
      if (0x10000002 < (int)uVar1) {
        if (uVar1 == 0x10000004) {
          return 0xffffff99;
        }
        if ((int)uVar1 < 0x10000005) {
          return 0xffffff9a;
        }
        return 0xffffff97;
      }
      if (uVar1 == 0) {
        return 0;
      }
    }
    else if ((int)uVar1 < 0x1000000b) {
      if (0x10000008 < (int)uVar1) {
        return 0xffffff9a;
      }
      if (uVar1 == 0x10000007) {
        return 0xffffff94;
      }
      if (uVar1 == 0x10000008) {
        return 0xffffff92;
      }
    }
    else if ((uVar1 != 0x1000000b) && (uVar1 == 0x1000000c)) {
      return 0xffffff9b;
    }
  }
  else {
    if (uVar1 == 0x10004005) {
      return 0xffffff31;
    }
    if ((int)uVar1 < 0x10004006) {
      if (uVar1 != 0x10004001) {
        if (0x10004001 < (int)uVar1) {
          if (uVar1 == 0x10004003) {
            return 0xffffff35;
          }
          if ((int)uVar1 < 0x10004004) {
            return 0xffffff36;
          }
          return 0xffffff34;
        }
        if (uVar1 == 0x1000000f) {
          return 0xffffff9a;
        }
      }
    }
    else if ((int)uVar1 < 0x1000400b) {
      if (0x10004008 < (int)uVar1) {
        return 0xffffff36;
      }
      if (uVar1 != 0x10004007) {
        if (0x10004007 < (int)uVar1) {
          return 0xffffff37;
        }
        return 0xffffff30;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  _panic(aMsgReturnTrans_0);
}
/* GHIDRADEC_FUNCTION index=1217 start=0x4045786 */

undefined4 _msg_send_trap(undefined4 param_1,uint param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  code *pcVar6;
  int iStack_8;
  
  uVar5 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x7c);
  uVar3 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 8);
  uVar1 = param_3 + 3U & 0xfffffffc;
  if (0x2000 < uVar1) {
    return 0xffffff93;
  }
  iVar2 = _ipc_kmsg_get(param_1,uVar1,param_3 - uVar1,&iStack_8);
  if (iVar2 != 0) goto loc_40458DE;
  iVar2 = _ipc_kmsg_copyin_compat(iStack_8,uVar5,uVar3);
  if (iVar2 != 0) {
    if (*(int *)(iStack_8 + 8) < 1) {
      _ipc_kmsg_free(iStack_8);
    }
    else {
      _kfree(iStack_8,*(int *)(iStack_8 + 8));
    }
    goto loc_40458DE;
  }
  if ((param_2 & 2) == 0) {
    if ((param_2 & 0x20) == 0) {
      pcVar6 = (code *)0x0;
      uVar5 = 0;
      if ((param_2 & 1) != 0) {
        uVar5 = 0x10;
      }
    }
    else {
      pcVar6 = _msg_send_switch_continue;
      uVar5 = 0x20000;
      if ((param_2 & 1) != 0) {
        uVar5 = 0x20010;
      }
    }
    iVar2 = _ipc_mqueue_send(iStack_8,uVar5,param_4,pcVar6);
loc_40458CE:
    if (iVar2 == 0) goto loc_40458DE;
  }
  else {
    uVar3 = 0;
    if ((param_2 & 1) != 0) {
      uVar3 = param_4;
    }
    uVar4 = 0x10;
    if ((param_2 & 0x20) != 0) {
      uVar4 = 0x20010;
    }
    iVar2 = _ipc_mqueue_send(iStack_8,uVar4,uVar3,0);
    if (iVar2 != 0x10000004) goto loc_40458CE;
    iVar2 = _ipc_marequest_create(uVar5,*(undefined4 *)(iStack_8 + 0x1c),0,iStack_8 + 0xc);
    if (iVar2 == 0) {
      _ipc_mqueue_send(iStack_8,0x10000,0,0);
      return 0xffffff97;
    }
  }
  _ipc_kmsg_destroy(iStack_8);
loc_40458DE:
  uVar5 = _msg_return_translate(iVar2);
  return uVar5;
}
/* GHIDRADEC_FUNCTION index=1218 start=0x40458f0 */

void _msg_send_switch_continue(void)

{
  _thread_syscall_return(0);
  return;
}
/* GHIDRADEC_FUNCTION index=1219 start=0x4045900 */

undefined4
_msg_receive_trap(int param_1,uint param_2,uint param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int iStack_18;
  undefined auStack_14 [4];
  int iStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uVar5 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x7c);
  uVar1 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 8);
  iVar3 = _ipc_mqueue_copyin(uVar5,param_4,&uStack_8,&uStack_c);
  iVar2 = _active_threads;
  if (iVar3 == 0) {
    *(int *)(_active_threads + 0xbc) = param_1;
    *(uint *)(iVar2 + 0xc0) = param_2;
    *(uint *)(iVar2 + 0xc4) = param_3;
    *(undefined4 *)(iVar2 + 200) = param_5;
    *(undefined4 *)(iVar2 + 0xd0) = uStack_c;
    *(undefined4 *)(iVar2 + 0xd4) = uStack_8;
    uVar4 = 0xffffffff;
    if ((param_2 & 0x1000) != 0) {
      uVar4 = param_3;
    }
    iVar3 = _ipc_mqueue_receive(uStack_8,param_2 & 0x100,uVar4,param_5,0,_msg_receive_continue,
                                &iStack_10,auStack_14);
    _ipc_object_release(uStack_c);
    if (iVar3 == 0) {
      if (*(uint *)(iStack_10 + 0x18) <= param_3) {
        _ipc_kmsg_copyout_compat(iStack_10,uVar5,uVar1);
        iVar2 = *(int *)(iStack_10 + 0x10) + *(int *)(iStack_10 + 0x18);
        *(int *)(iStack_10 + 0x18) = iVar2;
        uVar5 = _ipc_kmsg_put(param_1,iStack_10,iVar2);
        uVar5 = _msg_return_translate(uVar5);
        return uVar5;
      }
      _ipc_kmsg_destroy(iStack_10);
      return 0xffffff34;
    }
    if (iVar3 == 0x10004004) {
      iStack_18 = iStack_10;
      _copyoutmsg(&iStack_18,param_1 + 4,4);
    }
  }
  uVar5 = _msg_return_translate(iVar3);
  return uVar5;
}
/* GHIDRADEC_FUNCTION index=1220 start=0x4045a30 */

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
/* GHIDRADEC_FUNCTION index=1221 start=0x4045dd6 */

void _msg_receive_continue(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iStack_10;
  undefined auStack_c [4];
  int iStack_8;
  
  iVar1 = *(int *)(_active_threads + 0xbc);
  uVar2 = *(uint *)(_active_threads + 0xc4);
  uVar5 = *(undefined4 *)(_active_threads + 0xd0);
  uVar3 = 0xffffffff;
  if ((*(uint *)(_active_threads + 0xc0) & 0x1000) != 0) {
    uVar3 = uVar2;
  }
  iVar4 = _ipc_mqueue_receive(*(undefined4 *)(_active_threads + 0xd4),
                              *(uint *)(_active_threads + 0xc0) & 0x100,uVar3,
                              *(undefined4 *)(_active_threads + 200),1,_msg_receive_continue,
                              &iStack_8,auStack_c);
  _ipc_object_release(uVar5);
  if (iVar4 != 0) {
    if (iVar4 == 0x10004004) {
      iStack_10 = iStack_8;
      _copyoutmsg(&iStack_10,iVar1 + 4,4);
    }
    uVar5 = _msg_return_translate(iVar4);
    _thread_syscall_return(uVar5);
  }
  if (uVar2 < *(uint *)(iStack_8 + 0x18)) {
    _ipc_kmsg_destroy(iStack_8);
    _thread_syscall_return(0xffffff34);
  }
  _ipc_kmsg_copyout_compat
            (iStack_8,*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x7c),
             *(undefined4 *)(*(int *)(_active_threads + 0xc) + 8));
  iVar4 = *(int *)(iStack_8 + 0x10) + *(int *)(iStack_8 + 0x18);
  *(int *)(iStack_8 + 0x18) = iVar4;
  uVar5 = _ipc_kmsg_put(iVar1,iStack_8,iVar4);
  uVar5 = _msg_return_translate(uVar5);
  _thread_syscall_return(uVar5);
  return;
}
/* GHIDRADEC_FUNCTION index=1222 start=0x4045ee4 */

uint _mach_port_names_helper
               (int param_1,uint *param_2,undefined4 param_3,int param_4,int param_5,int *param_6)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = *param_2;
  uVar5 = param_2[2];
  uVar3 = uVar4 & 0x50000;
  if (uVar3 != 0) {
    bVar2 = false;
    if ((-1 < *(int *)(param_2[1] + 4)) &&
       (uVar3 = *(int *)(param_2[1] + 8) - param_1, (int)uVar3 < 0)) {
      bVar2 = true;
    }
    if (bVar2) {
      if ((uVar4 & 0x400000) != 0) {
        return uVar3;
      }
      uVar4 = uVar4 & 0xffc0ffff | 0x100000;
      if (uVar5 != 0) {
        uVar4 = uVar4 + 1;
      }
      uVar5 = 0;
    }
  }
  uVar3 = uVar4 & 0x1f0000;
  if ((uVar4 & 0x400000) == 0) {
    if (uVar5 != 0) {
      uVar3 = uVar3 | 0x80000000;
    }
  }
  else {
    uVar3 = uVar3 | 0x20000000;
  }
  if ((uVar4 & 0x200000) != 0) {
    uVar3 = uVar3 | 0x40000000;
  }
  iVar1 = *param_6;
  *(undefined4 *)(param_4 + iVar1 * 4) = param_3;
  *(uint *)(param_5 + iVar1 * 4) = uVar3;
  *param_6 = iVar1 + 1;
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=1223 start=0x4045f82 */

undefined4
_mach_port_names(int param_1,undefined4 *param_2,int *param_3,undefined4 *param_4,int *param_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  undefined4 uStack_18;
  undefined4 uStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  if (param_1 != 0) {
    uVar8 = 0;
    while (iVar2 = iStack_8, iVar3 = iStack_c, *(int *)(param_1 + 4) != 0) {
      uVar1 = ~_page_mask & _page_mask + (*(int *)(param_1 + 0x30) + *(int *)(param_1 + 0x10)) * 4;
      if (uVar1 <= uVar8) {
        iStack_10 = 0;
        uVar4 = _ipc_port_timestamp();
        puVar7 = *(uint **)(param_1 + 0xc);
        uVar1 = *(uint *)(param_1 + 0x10);
        uVar6 = 0;
        if (uVar1 != 0) {
          do {
            if ((*puVar7 & 0x1f0000) != 0) {
              _mach_port_names_helper
                        (uVar4,puVar7,*puVar7 >> 0x18 | uVar6 << 8,iVar2,iVar3,&iStack_10);
            }
            puVar7 = puVar7 + 4;
            uVar6 = uVar6 + 1;
          } while (uVar6 < uVar1);
        }
        iVar5 = _ipc_splay_traverse_start(param_1 + 0x18);
        while (iVar5 != 0) {
          _mach_port_names_helper(uVar4,iVar5,*(undefined4 *)(iVar5 + 0x10),iVar2,iVar3,&iStack_10);
          iVar5 = _ipc_splay_traverse_next(param_1 + 0x18,0);
        }
        _ipc_splay_traverse_finish(param_1 + 0x18);
        if (iStack_10 == 0) {
          uStack_14 = 0;
          uStack_18 = 0;
          if (uVar8 == 0) goto loc_4046238;
          _kmem_free(_ipc_kernel_map,iStack_8,uVar8);
        }
        else {
          uVar1 = ~_page_mask & _page_mask + iStack_10 * 4;
          _vm_map_pageable(_ipc_kernel_map,iStack_8,iStack_8 + uVar1,1);
          _vm_map_pageable(_ipc_kernel_map,iStack_c,iStack_c + uVar1,1);
          _vm_move(_ipc_kernel_map,iStack_8,_ipc_soft_map,uVar1,1,&uStack_14);
          _vm_move(_ipc_kernel_map,iStack_c,_ipc_soft_map,uVar1,1,&uStack_18);
          if (uVar8 == uVar1) goto loc_4046238;
          uVar8 = uVar8 - uVar1;
          _kmem_free(_ipc_kernel_map,uVar1 + iStack_8,uVar8);
          iStack_c = iStack_c + uVar1;
        }
        _kmem_free(_ipc_kernel_map,iStack_c,uVar8);
loc_4046238:
        *param_2 = uStack_14;
        *param_3 = iStack_10;
        *param_4 = uStack_18;
        *param_5 = iStack_10;
        return 0;
      }
      if (uVar8 != 0) {
        _kmem_free(_ipc_kernel_map,iStack_8,uVar8);
        _kmem_free(_ipc_kernel_map,iStack_c,uVar8);
      }
      iVar3 = _vm_allocate(_ipc_kernel_map,&iStack_8,uVar1,1);
      if (iVar3 != 0) {
        return 6;
      }
      iVar3 = _vm_allocate(_ipc_kernel_map,&iStack_c,uVar1,1);
      if (iVar3 != 0) {
        _kmem_free(_ipc_kernel_map,iStack_8,uVar1);
        return 6;
      }
      _vm_map_pageable(_ipc_kernel_map,iStack_8,uVar1 + iStack_8,0);
      _vm_map_pageable(_ipc_kernel_map,iStack_c,uVar1 + iStack_c,0);
      uVar8 = uVar1;
    }
    if (uVar8 != 0) {
      _kmem_free(_ipc_kernel_map,iStack_8,uVar8);
      _kmem_free(_ipc_kernel_map,iStack_c,uVar8);
    }
  }
  return 0x10;
}
/* GHIDRADEC_FUNCTION index=1224 start=0x4046264 */

int _mach_port_type(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined auStack_c [4];
  undefined4 uStack_8;
  
  if (param_1 == 0) {
    iVar1 = 0x10;
  }
  else {
    iVar1 = _ipc_right_lookup_write(param_1,param_2,&uStack_8);
    if (iVar1 == 0) {
      iVar1 = _ipc_right_info(param_1,param_2,uStack_8,param_3,auStack_c);
    }
  }
  return iVar1;
}

