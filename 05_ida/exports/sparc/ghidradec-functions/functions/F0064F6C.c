
/* WARNING: Removing unreachable block (ram,0xf0064ff4) */
/* WARNING: Removing unreachable block (ram,0xf0064fd8) */
/* WARNING: Removing unreachable block (ram,0xf0064fb0) */
/* WARNING: Removing unreachable block (ram,0xf0064f8c) */
/* WARNING: Removing unreachable block (ram,0xf0064fa4) */
/* WARNING: Removing unreachable block (ram,0xf0064fc8) */
/* WARNING: Removing unreachable block (ram,0xf0064fec) */
/* WARNING: Removing unreachable block (ram,0xf0065000) */
/* WARNING: Removing unreachable block (ram,0xf0064f74) */

undefined8 _ipc_host_init(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
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
  iVar1 = _ipc_space_kernel;
  _ipc_port_alloc_special();
  if (iVar1 == 0) {
    _panic(aIpcHostInit);
  }
  _ipc_kobject_set(iVar1,&_realhost,3);
  iVar2 = _ipc_space_kernel;
  _realhost = iVar1;
  _ipc_port_alloc_special();
  if (iVar2 == 0) {
    _panic(aIpcHostInit_0);
  }
  _ipc_kobject_set(iVar2,&_realhost,4);
  dword_F0135174 = iVar2;
  _ipc_pset_init(_default_pset);
  _ipc_pset_enable(_default_pset);
  _ipc_processor_init(_master_processor);
  return CONCAT44(param_2,param_1);
}
