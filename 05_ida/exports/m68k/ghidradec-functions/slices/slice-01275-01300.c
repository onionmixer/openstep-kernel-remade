/* GHIDRADEC_FUNCTION index=1275 start=0x4048022 */

undefined4 _host_info(int param_1,int param_2,int *param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  
  if (param_1 != 0) {
    if (param_2 != 2) {
      if (param_2 < 3) {
        if (param_2 != 1) {
          return 4;
        }
        if (*param_4 < 5) {
          return 5;
        }
        *param_3 = dword_40C22D0;
        param_3[1] = dword_40C22D4;
        param_3[2] = dword_40C22D8;
        iVar1 = _master_processor;
        param_3[3] = (&dword_40B5DCC)[*(int *)(_master_processor + 0x13c) * 8];
        param_3[4] = (&dword_40B5DD0)[*(int *)(iVar1 + 0x13c) * 8];
        uVar2 = 5;
      }
      else if (param_2 == 3) {
        if (*param_4 < 2) {
          return 5;
        }
        iVar1 = _tick / 1000;
        *param_3 = iVar1;
        param_3[1] = iVar1;
        uVar2 = 2;
      }
      else {
        if (param_2 != 4) {
          return 4;
        }
        if (*param_4 < 6) {
          return 5;
        }
        _bcopy(_avenrun,param_3,0xc);
        _bcopy(_mach_factor,param_3 + 3,0xc);
        uVar2 = 6;
      }
      *param_4 = uVar2;
      return 0;
    }
    if (*param_4 != 0) {
      *param_4 = 0;
      iVar1 = 0;
      piVar3 = &_machine_slot;
      do {
        piVar4 = param_3;
        if ((*piVar3 != 0) && ((&dword_40B5DD4)[iVar1 * 8] != 0)) {
          piVar4 = param_3 + 1;
          *param_3 = iVar1;
          *param_4 = *param_4 + 1;
        }
        piVar3 = piVar3 + 8;
        iVar1 = iVar1 + 1;
        param_3 = piVar4;
      } while (iVar1 < 1);
      return 0;
    }
  }
  return 4;
}
/* GHIDRADEC_FUNCTION index=1276 start=0x404814a */

undefined4 _host_kernel_version(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else {
    _strncpy(param_2,_version,0x200);
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1277 start=0x4048172 */

undefined4 _host_processor_sets(int param_1,int *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else {
    puVar2 = (undefined4 *)_kalloc(4);
    if (puVar2 == (undefined4 *)0x0) {
      uVar1 = 6;
    }
    else {
      _pset_reference(_default_pset);
      uVar1 = _convert_pset_name_to_port(_default_pset);
      *puVar2 = uVar1;
      *param_2 = (int)puVar2;
      *param_3 = 1;
      uVar1 = 0;
    }
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1278 start=0x40481ce */

undefined4 _host_processor_set_priv(int param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    *param_3 = 0;
    uVar1 = 4;
  }
  else {
    *param_3 = param_2;
    _pset_reference(param_2);
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1279 start=0x40481fa */

void _ipc_host_init(void)

{
  int iVar1;
  
  iVar1 = _ipc_port_alloc_special(_ipc_space_kernel);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aIpcHostInit);
  }
  _ipc_kobject_set(iVar1,&_realhost,3);
  _realhost = iVar1;
  iVar1 = _ipc_port_alloc_special(_ipc_space_kernel);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aIpcHostInit);
  }
  _ipc_kobject_set(iVar1,&_realhost,4);
  dword_40B67DC = iVar1;
  _ipc_pset_init(_default_pset);
  _ipc_pset_enable(_default_pset);
  _ipc_processor_init(_master_processor);
  return;
}
/* GHIDRADEC_FUNCTION index=1280 start=0x404829c */

void _mach_host_self(void)

{
  undefined4 uVar1;
  
  uVar1 = _ipc_port_make_send(_realhost);
  _ipc_port_copyout_send(uVar1,*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x7c));
  return;
}
/* GHIDRADEC_FUNCTION index=1281 start=0x40482c6 */

void _host_self(void)

{
  undefined4 uVar1;
  
  uVar1 = _ipc_port_make_send(_realhost);
  _ipc_port_copyout_send_compat(uVar1,*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x7c));
  return;
}
/* GHIDRADEC_FUNCTION index=1282 start=0x40482f0 */

void _ipc_processor_init(int param_1)

{
  int iVar1;
  
  iVar1 = _ipc_port_alloc_special(_ipc_space_kernel);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aIpcProcessorIn);
  }
  *(int *)(param_1 + 0x138) = iVar1;
  _ipc_kobject_set(iVar1,param_1,5);
  return;
}
/* GHIDRADEC_FUNCTION index=1283 start=0x404833a */

void _ipc_pset_init(int param_1)

{
  int iVar1;
  
  iVar1 = _ipc_port_alloc_special(_ipc_space_kernel);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aIpcPsetInit);
  }
  *(int *)(param_1 + 0x14c) = iVar1;
  iVar1 = _ipc_port_alloc_special(_ipc_space_kernel);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aIpcPsetInit);
  }
  *(int *)(param_1 + 0x150) = iVar1;
  return;
}
/* GHIDRADEC_FUNCTION index=1284 start=0x4048394 */

void _ipc_pset_enable(int param_1)

{
  if (*(int *)(param_1 + 0x148) != 0) {
    _ipc_kobject_set(*(undefined4 *)(param_1 + 0x14c),param_1,6);
    _ipc_kobject_set(*(undefined4 *)(param_1 + 0x150),param_1,7);
    *(int *)(param_1 + 0x13c) = *(int *)(param_1 + 0x13c) + 2;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1285 start=0x40483d4 */

void _ipc_pset_disable(int param_1)

{
  _ipc_kobject_set(*(undefined4 *)(param_1 + 0x14c),0,0);
  _ipc_kobject_set(*(undefined4 *)(param_1 + 0x150),0,0);
  *(int *)(param_1 + 0x13c) = *(int *)(param_1 + 0x13c) + -2;
  return;
}
/* GHIDRADEC_FUNCTION index=1286 start=0x404840a */

void _ipc_pset_terminate(int param_1)

{
  _ipc_port_dealloc_special(*(undefined4 *)(param_1 + 0x14c),_ipc_space_kernel);
  _ipc_port_dealloc_special(*(undefined4 *)(param_1 + 0x150),_ipc_space_kernel);
  return;
}
/* GHIDRADEC_FUNCTION index=1287 start=0x4048440 */

undefined4 _processor_set_default(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else {
    *param_2 = _default_pset;
    _pset_reference(_default_pset);
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1288 start=0x404846a */

undefined4 _xxx_processor_set_default_priv(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else {
    *param_2 = _default_pset;
    _pset_reference(_default_pset);
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1289 start=0x4048494 */

undefined4 _convert_port_to_host(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((((param_1 != 0) && (param_1 != -1)) && ((int)*(uint *)(param_1 + 4) < 0)) &&
     ((*(uint *)(param_1 + 4) & 0xffff) - 3 < 2)) {
    uVar1 = *(undefined4 *)(param_1 + 0x10);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1290 start=0x40484cc */

undefined4 _convert_port_to_host_priv(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((((param_1 != 0) && (param_1 != -1)) && (*(int *)(param_1 + 4) < 0)) &&
     ((sword)*(int *)(param_1 + 4) == 4)) {
    uVar1 = *(undefined4 *)(param_1 + 0x10);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1291 start=0x40484fa */

undefined4 _convert_port_to_processor(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((((param_1 != 0) && (param_1 != -1)) && (*(int *)(param_1 + 4) < 0)) &&
     ((sword)*(int *)(param_1 + 4) == 5)) {
    uVar1 = *(undefined4 *)(param_1 + 0x10);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1292 start=0x4048528 */

undefined4 _convert_port_to_pset(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((((param_1 != 0) && (param_1 != -1)) && (*(int *)(param_1 + 4) < 0)) &&
     ((sword)*(int *)(param_1 + 4) == 6)) {
    uVar1 = *(undefined4 *)(param_1 + 0x10);
    _pset_reference(uVar1);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1293 start=0x4048560 */

undefined4 _convert_port_to_pset_name(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((((param_1 != 0) && (param_1 != -1)) && ((int)*(uint *)(param_1 + 4) < 0)) &&
     ((*(uint *)(param_1 + 4) & 0xffff) - 6 < 2)) {
    uVar1 = *(undefined4 *)(param_1 + 0x10);
    _pset_reference(uVar1);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1294 start=0x40485a0 */

void _convert_host_to_port(undefined4 *param_1)

{
  _ipc_port_make_send(*param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=1295 start=0x40485b4 */

void _convert_processor_to_port(int param_1)

{
  _ipc_port_make_send(*(undefined4 *)(param_1 + 0x138));
  return;
}
/* GHIDRADEC_FUNCTION index=1296 start=0x40485ca */

undefined4 _convert_pset_to_port(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x148) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = _ipc_port_make_send(*(undefined4 *)(param_1 + 0x14c));
  }
  _pset_deallocate(param_1);
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1297 start=0x4048604 */

undefined4 _convert_pset_name_to_port(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x148) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = _ipc_port_make_send(*(undefined4 *)(param_1 + 0x150));
  }
  _pset_deallocate(param_1);
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1298 start=0x404863e */

undefined * _ipc_kobject_server(undefined *param_1)

{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  int iVar4;
  code *pcVar5;
  undefined **ppuVar6;
  undefined *puStack_1c;
  undefined *puStack_18;
  
  puStack_18 = (undefined *)0x800;
  puStack_1c = (undefined *)0x4048658;
  puVar3 = (undefined *)_kalloc();
  if (puVar3 == (undefined *)0x0) {
    puStack_18 = aIpcKobjectServ;
    puStack_1c = (undefined *)0x404866c;
    _printf();
    ppuVar6 = &puStack_1c;
    puStack_1c = param_1;
    goto loc_40487F6;
  }
  *(undefined4 *)(puVar3 + 8) = 0x800;
  *(undefined4 *)(puVar3 + 0xc) = 0;
  *(undefined4 *)(puVar3 + 0x10) = 0;
  *(uint *)(puVar3 + 0x14) = (uint)(byte)param_1[0x16];
  *(undefined4 *)(puVar3 + 0x18) = 0x20;
  *(undefined4 *)(puVar3 + 0x1c) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(puVar3 + 0x20) = 0;
  *(undefined4 *)(puVar3 + 0x24) = 0;
  *(int *)(puVar3 + 0x28) = *(int *)(param_1 + 0x28) + 100;
  *(undefined4 *)(puVar3 + 0x2c) = dword_40AF788;
  puStack_18 = param_1;
  puStack_1c = (undefined *)0x40486b6;
  iVar4 = _netipc_msg_send();
  if (iVar4 == 0) {
    puVar1 = param_1 + 0x14;
    puStack_1c = (undefined *)0x40486d2;
    puStack_18 = puVar1;
    pcVar5 = (code *)_mach_server_routine();
    if (pcVar5 == (code *)0x0) {
      puStack_1c = (undefined *)0x40486e2;
      puStack_18 = puVar1;
      pcVar5 = (code *)_mach_port_server_routine();
      if (pcVar5 == (code *)0x0) {
        puStack_1c = (undefined *)0x40486f2;
        puStack_18 = puVar1;
        pcVar5 = (code *)_mach_host_server_routine();
        if (pcVar5 == (code *)0x0) {
          puStack_1c = (undefined *)0x4048702;
          puStack_18 = puVar1;
          pcVar5 = (code *)_mach_debug_server_routine();
          if (pcVar5 == (code *)0x0) {
            puStack_18 = puVar3 + 0x14;
            puStack_1c = puVar1;
            iVar4 = _ipc_kobject_notify();
            if (iVar4 == 0) {
              *(undefined4 *)(puVar3 + 0x30) = 0xfffffed1;
            }
            goto loc_4048732;
          }
        }
      }
    }
    puStack_18 = puVar3 + 0x14;
    puStack_1c = param_1 + 0x14;
    (*pcVar5)();
  }
  else {
    *(undefined4 *)(puVar3 + 0x30) = 0xfffffecf;
  }
loc_4048732:
  puVar2 = (undefined4 *)(param_1 + 0x1c);
  if (param_1[0x17] == '\x11') {
    puStack_18 = (undefined *)*puVar2;
    puStack_1c = (undefined *)0x4048752;
    _ipc_port_release_send();
  }
  else {
    if (param_1[0x17] != '\x12') {
      puStack_18 = aIpcObjectDestr;
                    /* WARNING: Subroutine does not return */
      puStack_1c = (undefined *)0x404876a;
      _panic();
    }
    puStack_18 = (undefined *)*puVar2;
    puStack_1c = (undefined *)0x404875c;
    _ipc_port_release_sonce();
  }
  *puVar2 = 0;
  iVar4 = *(int *)(puVar3 + 0x30);
  if ((iVar4 == 0) || (iVar4 == -0x131)) {
    *(undefined4 *)(param_1 + 0x10) = 0;
    if ((*(int *)(param_1 + 8) == 0x100) && (_ipc_kmsg_cache == (undefined *)0x0)) {
      _ipc_kmsg_cache = param_1;
    }
    else {
      puStack_18 = *(undefined **)(param_1 + 8);
      if ((int)puStack_18 < 1) {
        puStack_18 = param_1;
        puStack_1c = (undefined *)0x40487a6;
        _ipc_kmsg_free();
      }
      else {
        puStack_1c = param_1;
        _kfree();
      }
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x20) = 0;
    puStack_18 = param_1;
    puStack_1c = (undefined *)0x40487ce;
    _ipc_kmsg_destroy();
  }
  if (iVar4 == -0x131) {
    puStack_18 = *(undefined **)(puVar3 + 8);
    if ((int)puStack_18 < 1) {
      puStack_1c = (undefined *)0x40487e6;
      puStack_18 = puVar3;
      _ipc_kmsg_free();
      return (undefined *)0x0;
    }
    puStack_1c = puVar3;
    _kfree();
    return (undefined *)0x0;
  }
  if ((*(int *)(puVar3 + 0x1c) != 0) && (*(int *)(puVar3 + 0x1c) != -1)) {
    return puVar3;
  }
  ppuVar6 = &puStack_18;
  puStack_18 = puVar3;
loc_40487F6:
  *(undefined4 *)((int)ppuVar6 + -4) = 0x40487fc;
  _ipc_kmsg_destroy();
  return (undefined *)0x0;
}
/* GHIDRADEC_FUNCTION index=1299 start=0x404880c */

void _ipc_kobject_set(int param_1,undefined4 param_2,uint param_3)

{
  *(uint *)(param_1 + 4) = param_3 | *(uint *)(param_1 + 4) & 0xffff0000;
  *(undefined4 *)(param_1 + 0x10) = param_2;
  return;
}

