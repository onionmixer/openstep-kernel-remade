
/* WARNING: Removing unreachable block (ram,0xf00655e4) */
/* WARNING: Removing unreachable block (ram,0xf00657b4) */
/* WARNING: Removing unreachable block (ram,0xf0065794) */
/* WARNING: Removing unreachable block (ram,0xf0065734) */
/* WARNING: Removing unreachable block (ram,0xf0065714) */
/* WARNING: Removing unreachable block (ram,0xf00656b0) */
/* WARNING: Removing unreachable block (ram,0xf0065688) */
/* WARNING: Removing unreachable block (ram,0xf0065660) */
/* WARNING: Removing unreachable block (ram,0xf0065648) */
/* WARNING: Removing unreachable block (ram,0xf0065674) */
/* WARNING: Removing unreachable block (ram,0xf006569c) */
/* WARNING: Removing unreachable block (ram,0xf00656d8) */
/* WARNING: Removing unreachable block (ram,0xf0065724) */
/* WARNING: Removing unreachable block (ram,0xf00657a4) */
/* WARNING: Removing unreachable block (ram,0xf00657c4) */
/* WARNING: Removing unreachable block (ram,0xf00657e8) */
/* WARNING: Removing unreachable block (ram,0xf0065810) */
/* WARNING: Removing unreachable block (ram,0xf00655cc) */

undefined8 _ipc_kobject_server(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  char cVar4;
  int iVar5;
  undefined4 unaff_l0;
  code *pcVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar1 = 0x800;
  _kalloc();
  if (iVar1 == 0) {
    _printf(aIpcKobjectServ);
    iVar1 = param_1;
  }
  else {
    *(undefined4 *)(iVar1 + 8) = 0x800;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *(undefined4 *)(iVar1 + 0x10) = 0;
    *(uint *)(iVar1 + 0x14) = (*(uint *)(param_1 + 0x14) & 0xff00) >> 8;
    *(undefined4 *)(iVar1 + 0x18) = 0x20;
    *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(param_1 + 0x20);
    *(undefined4 *)(iVar1 + 0x20) = 0;
    *(undefined4 *)(iVar1 + 0x24) = 0;
    *(int *)(iVar1 + 0x28) = *(int *)(param_1 + 0x28) + 100;
    *(undefined4 *)(iVar1 + 0x2c) = dword_F010F988;
    iVar8 = param_1;
    _netipc_msg_send();
    uVar2 = 0xfffffecf;
    if (iVar8 == 0) {
      pcVar6 = (code *)(param_1 + 0x14);
      pcVar3 = pcVar6;
      _mach_server_routine();
      if ((((pcVar3 == (code *)0x0) &&
           (pcVar3 = pcVar6, _mach_port_server_routine(), pcVar3 == (code *)0x0)) &&
          (pcVar3 = pcVar6, _mach_host_server_routine(), pcVar3 == (code *)0x0)) &&
         ((pcVar3 = pcVar6, _mach_debug_server_routine(), pcVar3 == (code *)0x0 &&
          (pcVar3 = pcVar6, _driverServer_server_routine(), pcVar3 == (code *)0x0)))) {
        _ipc_kobject_notify(pcVar6,iVar1 + 0x14);
        if (pcVar6 == (code *)0x0) {
          uVar2 = 0xfffffed1;
          goto loc_F00656F0;
        }
        cVar4 = *(char *)(param_1 + 0x17);
      }
      else {
        (*pcVar3)(param_1 + 0x14,iVar1 + 0x14);
        cVar4 = *(char *)(param_1 + 0x17);
      }
    }
    else {
loc_F00656F0:
      *(undefined4 *)(iVar1 + 0x30) = uVar2;
      cVar4 = *(char *)(param_1 + 0x17);
    }
    puVar7 = (undefined4 *)(param_1 + 0x1c);
    if (cVar4 == '\x11') {
      _ipc_port_release_send(*(undefined4 *)(param_1 + 0x1c));
      *puVar7 = 0;
    }
    else if (cVar4 == '\x12') {
      _ipc_port_release_sonce(*(undefined4 *)(param_1 + 0x1c));
      *puVar7 = 0;
    }
    else {
      _panic(aIpcObjectDestr);
      *puVar7 = 0;
    }
    iVar8 = *(int *)(iVar1 + 0x30);
    if ((iVar8 == 0) || (iVar8 == -0x131)) {
      *(undefined4 *)(param_1 + 0x10) = 0;
      if (*(int *)(param_1 + 8) == 0x100) {
        iVar5 = param_1;
        if (_ipc_kmsg_cache == 0) goto loc_F00657D0;
        iVar5 = *(int *)(param_1 + 8);
      }
      else {
        iVar5 = *(int *)(param_1 + 8);
      }
      if (iVar5 < 1) {
        _ipc_kmsg_free(param_1);
        iVar5 = _ipc_kmsg_cache;
      }
      else {
        _kfree(param_1);
        iVar5 = _ipc_kmsg_cache;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x20) = 0;
      _ipc_kmsg_destroy(param_1);
      iVar5 = _ipc_kmsg_cache;
    }
loc_F00657D0:
    _ipc_kmsg_cache = iVar5;
    if (iVar8 == -0x131) {
      if (*(int *)(iVar1 + 8) < 1) {
        _ipc_kmsg_free(iVar1);
        iVar1 = 0;
      }
      else {
        _kfree(iVar1);
        iVar1 = 0;
      }
      goto locret_F0065818;
    }
    if ((*(int *)(iVar1 + 0x1c) != 0) && (*(int *)(iVar1 + 0x1c) != -1)) goto locret_F0065818;
  }
  _ipc_kmsg_destroy(iVar1);
  iVar1 = 0;
locret_F0065818:
  return CONCAT44(param_2,iVar1);
}
