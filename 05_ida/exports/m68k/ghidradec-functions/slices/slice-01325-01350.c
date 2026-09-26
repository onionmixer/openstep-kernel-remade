/* GHIDRADEC_FUNCTION index=1325 start=0x4049870 */

int * _retrieve_task_self_fast(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x60);
  if (piVar1 == *(int **)(param_1 + 0x5c)) {
    *piVar1 = *piVar1 + 1;
    piVar1[6] = piVar1[6] + 1;
  }
  else {
    piVar1 = (int *)_ipc_port_copy_send(piVar1);
  }
  return piVar1;
}
/* GHIDRADEC_FUNCTION index=1326 start=0x404989a */

int * _retrieve_thread_self_fast(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0xa8);
  if (piVar1 == *(int **)(param_1 + 0xa4)) {
    *piVar1 = *piVar1 + 1;
    piVar1[6] = piVar1[6] + 1;
  }
  else {
    piVar1 = (int *)_ipc_port_copy_send(piVar1);
  }
  return piVar1;
}
/* GHIDRADEC_FUNCTION index=1327 start=0x40498c4 */

void _mach_task_self(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(_active_threads + 0xc);
  uVar2 = _retrieve_task_self_fast(iVar1);
  _ipc_port_copyout_send(uVar2,*(undefined4 *)(iVar1 + 0x7c));
  return;
}
/* GHIDRADEC_FUNCTION index=1328 start=0x40498f0 */

void _mach_thread_self(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(_active_threads + 0xc);
  uVar2 = _retrieve_thread_self_fast(_active_threads);
  _ipc_port_copyout_send(uVar2,*(undefined4 *)(iVar1 + 0x7c));
  return;
}
/* GHIDRADEC_FUNCTION index=1329 start=0x404991c */

undefined4 _mach_reply_port(void)

{
  int iVar1;
  undefined auStack_c [4];
  undefined4 uStack_8;
  
  iVar1 = _ipc_port_alloc(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x7c),&uStack_8,
                          auStack_c);
  if (iVar1 != 0) {
    uStack_8 = 0;
  }
  return uStack_8;
}
/* GHIDRADEC_FUNCTION index=1330 start=0x404994c */

int _retrieve_task_notify(int param_1)

{
  int iVar1;
  
  if (*(int *)(*(int *)(param_1 + 0x7c) + 4) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(*(int *)(param_1 + 0x7c) + 0x3c);
    if ((iVar1 != 0) && (iVar1 != -1)) {
      _ipc_object_reference(iVar1);
    }
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1331 start=0x4049982 */

int _retrieve_thread_reply(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0xa4) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0xb0);
    if ((iVar1 != 0) && (iVar1 != -1)) {
      _ipc_object_reference(iVar1);
    }
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1332 start=0x40499b4 */

void _task_self(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(_active_threads + 0xc);
  uVar2 = _retrieve_task_self_fast(iVar1);
  _ipc_port_copyout_send_compat(uVar2,*(undefined4 *)(iVar1 + 0x7c));
  return;
}
/* GHIDRADEC_FUNCTION index=1333 start=0x40499e0 */

void _task_notify(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(_active_threads + 0xc);
  uVar2 = _retrieve_task_notify(iVar1);
  _ipc_port_copyout_receiver(uVar2,*(undefined4 *)(iVar1 + 0x7c));
  return;
}
/* GHIDRADEC_FUNCTION index=1334 start=0x4049a0c */

void _thread_self(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(_active_threads + 0xc);
  uVar2 = _retrieve_thread_self_fast(_active_threads);
  _ipc_port_copyout_send_compat(uVar2,*(undefined4 *)(iVar1 + 0x7c));
  return;
}
/* GHIDRADEC_FUNCTION index=1335 start=0x4049a38 */

void _thread_reply(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(_active_threads + 0xc);
  uVar2 = _retrieve_thread_reply(_active_threads);
  _ipc_port_copyout_receiver(uVar2,*(undefined4 *)(iVar1 + 0x7c));
  return;
}
/* GHIDRADEC_FUNCTION index=1336 start=0x4049a64 */

undefined4 _task_get_special_port(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (param_1 == 0) {
    return 4;
  }
  if (param_2 == 2) {
    if (*(int *)(*(int *)(param_1 + 0x7c) + 4) == 0) {
      return 5;
    }
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x7c) + 0x3c);
  }
  else {
    if (param_2 < 3) {
      if (param_2 != 1) {
        return 4;
      }
      puVar2 = (undefined4 *)(param_1 + 0x60);
    }
    else if (param_2 == 3) {
      puVar2 = (undefined4 *)(param_1 + 100);
    }
    else {
      if (param_2 != 4) {
        return 4;
      }
      puVar2 = (undefined4 *)(param_1 + 0x68);
    }
    if (*(int *)(param_1 + 0x5c) == 0) {
      return 5;
    }
    uVar1 = *puVar2;
  }
  uVar1 = _ipc_port_copy_send(uVar1);
  *param_3 = uVar1;
  return 0;
}
/* GHIDRADEC_FUNCTION index=1337 start=0x4049ada */

undefined4 _task_set_special_port(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  if (param_1 == 0) {
    return 4;
  }
  if (param_2 == 2) {
    iVar1 = *(int *)(param_1 + 0x7c);
    if (*(int *)(iVar1 + 4) != 0) {
      iVar2 = *(int *)(iVar1 + 0x3c);
      *(int *)(iVar1 + 0x3c) = param_3;
      goto loc_4049B44;
    }
  }
  else {
    if (param_2 < 3) {
      if (param_2 != 1) {
        return 4;
      }
      piVar3 = (int *)(param_1 + 0x60);
    }
    else if (param_2 == 3) {
      piVar3 = (int *)(param_1 + 100);
    }
    else {
      if (param_2 != 4) {
        return 4;
      }
      piVar3 = (int *)(param_1 + 0x68);
    }
    if (*(int *)(param_1 + 0x5c) != 0) {
      iVar2 = *piVar3;
      *piVar3 = param_3;
loc_4049B44:
      if ((iVar2 != 0) && (iVar2 != -1)) {
        _ipc_port_release_send(iVar2);
      }
      return 0;
    }
  }
  return 5;
}
/* GHIDRADEC_FUNCTION index=1338 start=0x4049b60 */

undefined4 _thread_get_special_port(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (param_1 == 0) goto loc_4049B76;
  if (param_2 == 2) {
    puVar2 = (undefined4 *)(param_1 + 0xb0);
loc_4049BA2:
    if (*(int *)(param_1 + 0xa4) == 0) {
      uVar1 = 5;
    }
    else {
      uVar1 = _ipc_port_copy_send(*puVar2);
      *param_3 = uVar1;
      uVar1 = 0;
    }
  }
  else {
    if (param_2 < 3) {
      if (param_2 == 1) {
        puVar2 = (undefined4 *)(param_1 + 0xa8);
        goto loc_4049BA2;
      }
    }
    else if (param_2 == 3) {
      puVar2 = (undefined4 *)(param_1 + 0xac);
      goto loc_4049BA2;
    }
loc_4049B76:
    uVar1 = 4;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1339 start=0x4049bc0 */

undefined4 _thread_set_special_port(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1 == 0) goto loc_4049BD0;
  if (param_2 == 2) {
    piVar3 = (int *)(param_1 + 0xb0);
loc_4049BFC:
    if (*(int *)(param_1 + 0xa4) == 0) {
      uVar2 = 5;
    }
    else {
      iVar1 = *piVar3;
      *piVar3 = param_3;
      if ((iVar1 != 0) && (iVar1 != -1)) {
        _ipc_port_release_send(iVar1);
      }
      uVar2 = 0;
    }
  }
  else {
    if (param_2 < 3) {
      if (param_2 == 1) {
        piVar3 = (int *)(param_1 + 0xa8);
        goto loc_4049BFC;
      }
    }
    else if (param_2 == 3) {
      piVar3 = (int *)(param_1 + 0xac);
      goto loc_4049BFC;
    }
loc_4049BD0:
    uVar2 = 4;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1340 start=0x4049c24 */

undefined4 _mach_ports_register(int param_1,int *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int aiStack_14 [4];
  
  if ((param_1 != 0) && (param_3 < 5)) {
    uVar2 = 0;
    piVar4 = param_2;
    if (param_3 != 0) {
      do {
        aiStack_14[uVar2] = *piVar4;
        uVar2 = uVar2 + 1;
        piVar4 = piVar4 + 1;
      } while (uVar2 < param_3);
    }
    for (; (int)uVar2 < 4; uVar2 = uVar2 + 1) {
      aiStack_14[uVar2] = 0;
    }
    if (*(int *)(param_1 + 0x5c) != 0) {
      iVar3 = 0;
      do {
        iVar1 = *(int *)(param_1 + 0x6c + iVar3 * 4);
        *(int *)(param_1 + 0x6c + iVar3 * 4) = aiStack_14[iVar3];
        aiStack_14[iVar3] = iVar1;
        iVar3 = iVar3 + 1;
      } while (iVar3 < 4);
      iVar3 = 0;
      do {
        iVar1 = aiStack_14[iVar3];
        if ((iVar1 != 0) && (iVar1 != -1)) {
          _ipc_port_release_send(iVar1);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 4);
      if (param_3 != 0) {
        _kfree(param_2,param_3 << 2);
      }
      return 0;
    }
  }
  return 4;
}
/* GHIDRADEC_FUNCTION index=1341 start=0x4049cc2 */

undefined4 _mach_ports_lookup(int param_1,int *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else {
    puVar2 = (undefined4 *)_kalloc(0x10);
    if (puVar2 == (undefined4 *)0x0) {
      uVar1 = 6;
    }
    else if (*(int *)(param_1 + 0x5c) == 0) {
      _kfree(puVar2,0x10);
      uVar1 = 4;
    }
    else {
      iVar3 = 0;
      puVar4 = puVar2;
      do {
        uVar1 = _ipc_port_copy_send(*(undefined4 *)(param_1 + 0x6c + iVar3 * 4));
        *puVar4 = uVar1;
        iVar3 = iVar3 + 1;
        puVar4 = puVar4 + 1;
      } while (iVar3 < 4);
      *param_2 = (int)puVar2;
      *param_3 = 4;
      uVar1 = 0;
    }
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1342 start=0x4049d36 */

undefined4 _convert_port_to_task(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((((param_1 != 0) && (param_1 != -1)) && (*(int *)(param_1 + 4) < 0)) &&
     ((sword)*(int *)(param_1 + 4) == 2)) {
    uVar1 = *(undefined4 *)(param_1 + 0x10);
    _task_reference(uVar1);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1343 start=0x4049d6e */

undefined4 _convert_port_to_space(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((((param_1 != 0) && (param_1 != -1)) && (*(int *)(param_1 + 4) < 0)) &&
     ((sword)*(int *)(param_1 + 4) == 2)) {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x7c);
    _ipc_space_reference(uVar1);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1344 start=0x4049daa */

undefined4 _convert_port_to_map(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((((param_1 != 0) && (param_1 != -1)) && (*(int *)(param_1 + 4) < 0)) &&
     ((sword)*(int *)(param_1 + 4) == 2)) {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x10) + 8);
    _vm_map_reference(uVar1);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1345 start=0x4049de6 */

undefined4 _convert_port_to_thread(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((((param_1 != 0) && (param_1 != -1)) && (*(int *)(param_1 + 4) < 0)) &&
     ((sword)*(int *)(param_1 + 4) == 1)) {
    uVar1 = *(undefined4 *)(param_1 + 0x10);
    _thread_reference(uVar1);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1346 start=0x4049e1e */

undefined4 _convert_task_to_port(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x5c) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = _ipc_port_make_send(*(int *)(param_1 + 0x5c));
  }
  _task_deallocate(param_1);
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1347 start=0x4049e56 */

undefined4 _convert_thread_to_port(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0xa4) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = _ipc_port_make_send(*(int *)(param_1 + 0xa4));
  }
  _thread_deallocate(param_1);
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1348 start=0x4049e8e */

void _space_deallocate(int param_1)

{
  if (param_1 != 0) {
    _ipc_space_release(param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1349 start=0x4049ea4 */

undefined4 _host_priv_self(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uStack_8;
  
  iVar1 = *(int *)(_active_threads + 0xc);
  iVar2 = _suser();
  if (iVar2 == 0) {
    uStack_8 = 0;
  }
  else if (dword_40B67DC == 0) {
    uStack_8 = 0;
  }
  else {
    uVar3 = _ipc_port_copy_send(dword_40B67DC,0x11,1,&uStack_8);
    _ipc_object_copyout(*(undefined4 *)(iVar1 + 0x7c),uVar3);
  }
  return uStack_8;
}

