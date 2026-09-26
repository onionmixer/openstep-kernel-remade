/* GHIDRADEC_FUNCTION index=1300 start=0xf0064f30 */

/* WARNING: Removing unreachable block (ram,0xf0064f58) */

undefined8 _host_processor_set_priv(int param_1,int param_2,int *param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  if ((param_1 == 0) || (param_2 == 0)) {
    *param_3 = 0;
    uVar1 = 4;
  }
  else {
    *param_3 = param_2;
    _pset_reference();
    uVar1 = 0;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=1301 start=0xf0064f6c */

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
/* GHIDRADEC_FUNCTION index=1302 start=0xf0065010 */

/* WARNING: Removing unreachable block (ram,0xf006502c) */
/* WARNING: Removing unreachable block (ram,0xf0065018) */

undefined8 _mach_host_self(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
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
  uVar1 = _realhost;
  _ipc_port_make_send(_realhost);
  _ipc_port_copyout_send();
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=1303 start=0xf006503c */

/* WARNING: Removing unreachable block (ram,0xf0065058) */
/* WARNING: Removing unreachable block (ram,0xf0065044) */

undefined8 _host_self(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
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
  uVar1 = _realhost;
  _ipc_port_make_send(_realhost);
  _ipc_port_copyout_send_compat();
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=1304 start=0xf0065068 */

/* WARNING: Removing unreachable block (ram,0xf0065088) */
/* WARNING: Removing unreachable block (ram,0xf006509c) */
/* WARNING: Removing unreachable block (ram,0xf0065070) */

undefined8 _ipc_processor_init(int param_1,undefined4 param_2)

{
  int iVar1;
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
    _panic(aIpcProcessorIn);
    *(undefined4 *)(param_1 + 0x140) = 0;
  }
  else {
    *(int *)(param_1 + 0x140) = iVar1;
  }
  _ipc_kobject_set(iVar1,param_1,5);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1305 start=0xf00650ac */

/* WARNING: Removing unreachable block (ram,0xf00650d8) */
/* WARNING: Removing unreachable block (ram,0xf00650cc) */
/* WARNING: Removing unreachable block (ram,0xf00650f0) */
/* WARNING: Removing unreachable block (ram,0xf00650b4) */

undefined8 _ipc_pset_init(int param_1,undefined4 param_2)

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
    _panic(aIpcPsetInit);
  }
  iVar2 = _ipc_space_kernel;
  *(int *)(param_1 + 0x15c) = iVar1;
  _ipc_port_alloc_special();
  if (iVar2 == 0) {
    _panic(aIpcPsetInit_0);
    *(undefined4 *)(param_1 + 0x160) = 0;
  }
  else {
    *(int *)(param_1 + 0x160) = iVar2;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1306 start=0xf0065104 */

/* WARNING: Removing unreachable block (ram,0xf0065158) */
/* WARNING: Removing unreachable block (ram,0xf0065148) */
/* WARNING: Removing unreachable block (ram,0xf0065170) */
/* WARNING: Removing unreachable block (ram,0xf006511c) */

undefined8 _ipc_pset_enable(int param_1,undefined4 param_2)

{
  int *piVar1;
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
  do {
    do {
    } while (*(int *)(param_1 + 0x158) != 0);
    piVar1 = (int *)(param_1 + 0x158);
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  if (*(int *)(param_1 + 0x154) != 0) {
    _ipc_kobject_set(*(undefined4 *)(param_1 + 0x15c),param_1,6);
    _ipc_kobject_set(*(undefined4 *)(param_1 + 0x160),param_1,7);
    do {
      do {
      } while (*(int *)(param_1 + 0x148) != 0);
      piVar1 = (int *)(param_1 + 0x148);
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    *(undefined4 *)(param_1 + 0x148) = 0;
    *(int *)(param_1 + 0x144) = *(int *)(param_1 + 0x144) + 2;
  }
  *(undefined4 *)(param_1 + 0x158) = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1307 start=0xf00651a0 */

/* WARNING: Removing unreachable block (ram,0xf00651c0) */
/* WARNING: Removing unreachable block (ram,0xf00651d8) */
/* WARNING: Removing unreachable block (ram,0xf00651b0) */

undefined8 _ipc_pset_disable(int param_1,undefined4 param_2)

{
  int *piVar1;
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
  _ipc_kobject_set(*(undefined4 *)(param_1 + 0x15c),0,0);
  _ipc_kobject_set(*(undefined4 *)(param_1 + 0x160),0,0);
  do {
    do {
    } while (*(int *)(param_1 + 0x148) != 0);
    piVar1 = (int *)(param_1 + 0x148);
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  *(undefined4 *)(param_1 + 0x148) = 0;
  *(int *)(param_1 + 0x144) = *(int *)(param_1 + 0x144) + -2;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1308 start=0xf0065204 */

/* WARNING: Removing unreachable block (ram,0xf006521c) */
/* WARNING: Removing unreachable block (ram,0xf0065210) */

undefined8 _ipc_pset_terminate(int param_1,undefined4 param_2)

{
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
  _ipc_port_dealloc_special(*(undefined4 *)(param_1 + 0x15c),_ipc_space_kernel);
  _ipc_port_dealloc_special(*(undefined4 *)(param_1 + 0x160),_ipc_space_kernel);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1309 start=0xf006522c */

/* WARNING: Removing unreachable block (ram,0xf0065240) */

undefined8 _processor_set_default(int param_1,undefined4 *param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else {
    *param_2 = _default_pset;
    _pset_reference();
    uVar1 = 0;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=1310 start=0xf006525c */

/* WARNING: Removing unreachable block (ram,0xf0065270) */

undefined8 _xxx_processor_set_default_priv(int param_1,undefined4 *param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else {
    *param_2 = _default_pset;
    _pset_reference();
    uVar1 = 0;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=1311 start=0xf006528c */

/* WARNING: Removing unreachable block (ram,0xf00652b8) */

undefined8 _convert_port_to_host(int *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 unaff_l0;
  int iVar2;
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
  iVar2 = 0;
  if ((param_1 != (int *)0x0) && (param_1 != (int *)0xffffffff)) {
    do {
      do {
      } while (*param_1 != 0);
      piVar1 = param_1;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    if ((param_1[2] < 0) && ((param_1[2] & 0xffffU) - 3 < 2)) {
      iVar2 = param_1[5];
    }
    *param_1 = 0;
  }
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=1312 start=0xf0065300 */

/* WARNING: Removing unreachable block (ram,0xf006532c) */

undefined8 _convert_port_to_host_priv(int *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 unaff_l0;
  int iVar2;
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
  iVar2 = 0;
  if ((param_1 != (int *)0x0) && (param_1 != (int *)0xffffffff)) {
    do {
      do {
      } while (*param_1 != 0);
      piVar1 = param_1;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    if ((param_1[2] < 0) && ((param_1[2] & 0xffffU) == 4)) {
      iVar2 = param_1[5];
    }
    *param_1 = 0;
  }
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=1313 start=0xf0065370 */

/* WARNING: Removing unreachable block (ram,0xf006539c) */

undefined8 _convert_port_to_processor(int *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 unaff_l0;
  int iVar2;
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
  iVar2 = 0;
  if ((param_1 != (int *)0x0) && (param_1 != (int *)0xffffffff)) {
    do {
      do {
      } while (*param_1 != 0);
      piVar1 = param_1;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    if ((param_1[2] < 0) && ((param_1[2] & 0xffffU) == 5)) {
      iVar2 = param_1[5];
    }
    *param_1 = 0;
  }
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=1314 start=0xf00653e0 */

/* WARNING: Removing unreachable block (ram,0xf006544c) */
/* WARNING: Removing unreachable block (ram,0xf006540c) */

undefined8 _convert_port_to_pset(int *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 unaff_l0;
  int iVar2;
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
  iVar2 = 0;
  if ((param_1 != (int *)0x0) && (param_1 != (int *)0xffffffff)) {
    do {
      do {
      } while (*param_1 != 0);
      piVar1 = param_1;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    if ((param_1[2] < 0) && ((param_1[2] & 0xffffU) == 6)) {
      iVar2 = param_1[5];
      _pset_reference(iVar2);
    }
    *param_1 = 0;
  }
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=1315 start=0xf0065460 */

/* WARNING: Removing unreachable block (ram,0xf00654d0) */
/* WARNING: Removing unreachable block (ram,0xf006548c) */

undefined8 _convert_port_to_pset_name(int *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 unaff_l0;
  int iVar2;
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
  iVar2 = 0;
  if ((param_1 != (int *)0x0) && (param_1 != (int *)0xffffffff)) {
    do {
      do {
      } while (*param_1 != 0);
      piVar1 = param_1;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    if ((param_1[2] < 0) && ((param_1[2] & 0xffffU) - 6 < 2)) {
      iVar2 = param_1[5];
      _pset_reference(iVar2);
    }
    *param_1 = 0;
  }
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=1316 start=0xf00654e4 */

/* WARNING: Removing unreachable block (ram,0xf00654e8) */

undefined8 _convert_host_to_port(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
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
  uVar1 = *param_1;
  _ipc_port_make_send(uVar1);
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=1317 start=0xf00654f8 */

/* WARNING: Removing unreachable block (ram,0xf00654fc) */

undefined8 _convert_processor_to_port(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
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
  uVar1 = *(undefined4 *)(param_1 + 0x140);
  _ipc_port_make_send(uVar1);
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=1318 start=0xf006550c */

/* WARNING: Removing unreachable block (ram,0xf0065548) */
/* WARNING: Removing unreachable block (ram,0xf0065558) */
/* WARNING: Removing unreachable block (ram,0xf0065524) */

undefined8 _convert_pset_to_port(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 unaff_l0;
  undefined4 uVar2;
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
  do {
    do {
    } while (*(int *)(param_1 + 0x158) != 0);
    piVar1 = (int *)(param_1 + 0x158);
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  uVar2 = 0;
  if (*(int *)(param_1 + 0x154) != 0) {
    uVar2 = *(undefined4 *)(param_1 + 0x15c);
    _ipc_port_make_send(uVar2);
  }
  *(undefined4 *)(param_1 + 0x158) = 0;
  _pset_deallocate(param_1);
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=1319 start=0xf0065568 */

/* WARNING: Removing unreachable block (ram,0xf00655a4) */
/* WARNING: Removing unreachable block (ram,0xf00655b4) */
/* WARNING: Removing unreachable block (ram,0xf0065580) */

undefined8 _convert_pset_name_to_port(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 unaff_l0;
  undefined4 uVar2;
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
  do {
    do {
    } while (*(int *)(param_1 + 0x158) != 0);
    piVar1 = (int *)(param_1 + 0x158);
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  uVar2 = 0;
  if (*(int *)(param_1 + 0x154) != 0) {
    uVar2 = *(undefined4 *)(param_1 + 0x160);
    _ipc_port_make_send(uVar2);
  }
  *(undefined4 *)(param_1 + 0x158) = 0;
  _pset_deallocate(param_1);
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=1320 start=0xf00655c4 */

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
/* GHIDRADEC_FUNCTION index=1321 start=0xf0065820 */

/* WARNING: Removing unreachable block (ram,0xf0065834) */

undefined8 _ipc_kobject_set(int *param_1,int param_2,uint param_3)

{
  int *piVar1;
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
  do {
    do {
    } while (*param_1 != 0);
    piVar1 = param_1;
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  param_1[5] = param_2;
  *param_1 = 0;
  param_1[2] = param_1[2] & 0xffff0000U | param_3;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1322 start=0xf006586c */

/* WARNING: Removing unreachable block (ram,0xf00658c8) */
/* WARNING: Removing unreachable block (ram,0xf00658b0) */
/* WARNING: Removing unreachable block (ram,0xf00658bc) */

undefined8 _ipc_kobject_destroy(int param_1,undefined4 param_2)

{
  uint uVar1;
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
  uVar1 = *(uint *)(param_1 + 8) & 0xffff;
  if (uVar1 == 9) {
    _vm_object_pager_wakeup(param_1);
  }
  else if (uVar1 < 10) {
    if (uVar1 == 8) {
      _vm_object_destroy(param_1);
    }
  }
  else if (uVar1 == 0x11) {
    _netipc_ignore(0,param_1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1323 start=0xf00658d8 */

/* WARNING: Removing unreachable block (ram,0xf0065938) */

undefined8 _ipc_kobject_notify(int param_1,int param_2)

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
  iVar2 = *(int *)(param_1 + 8);
  *(undefined4 *)(param_2 + 0x1c) = 0xfffffecf;
  iVar1 = *(int *)(param_1 + 0x14);
  if (0x40 < iVar1) {
    if (0x42 < iVar1) {
      if (0x48 < iVar1) {
        param_1 = 0;
        goto locret_F0065944;
      }
      if (iVar1 < 0x45) {
        param_1 = 0;
        goto locret_F0065944;
      }
    }
    if ((*(uint *)(iVar2 + 8) & 0xffff) == 0xc) {
      _ds_notify(param_1);
      goto locret_F0065944;
    }
  }
  param_1 = 0;
locret_F0065944:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1324 start=0xf006594c */

/* WARNING: Removing unreachable block (ram,0xf0065998) */
/* WARNING: Removing unreachable block (ram,0xf0065990) */
/* WARNING: Removing unreachable block (ram,0xf00659ac) */
/* WARNING: Removing unreachable block (ram,0xf006597c) */

undefined8 _mach_msg_send_from_kernel(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  if ((*(int *)(param_1 + 8) == 0) || (*(int *)(param_1 + 8) == -1)) {
    uVar1 = 0x10000003;
  }
  else {
    _ipc_kmsg_get_from_kernel(param_1,param_2,0,(undefined *)((int)register0x00000038 + -0xc));
    if (param_1 != 0) {
      _panic(aMachMsgSendFro);
    }
    _ipc_kmsg_copyin_from_kernel(*(undefined4 *)((int)register0x00000038 + -0xc));
    _ipc_mqueue_send(*(undefined4 *)((int)register0x00000038 + -0xc),0x10000,0,0);
    uVar1 = 0;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=1325 start=0xf00659c0 */

/* WARNING: Removing unreachable block (ram,0xf0065a1c) */
/* WARNING: Removing unreachable block (ram,0xf00659dc) */

undefined8 _mach_msg_abort_rpc(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar2;
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
  iVar2 = 0;
  do {
    do {
    } while (*(int *)(param_1 + 0xa8) != 0);
    piVar1 = (int *)(param_1 + 0xa8);
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  if (*(int *)(param_1 + 0xac) != 0) {
    iVar2 = *(int *)(param_1 + 0xc0);
    *(undefined4 *)(param_1 + 0xc0) = 0;
  }
  *(undefined4 *)(param_1 + 0xa8) = 0;
  if (iVar2 != 0) {
    _ipc_port_dealloc_special(iVar2,_ipc_space_reply);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1326 start=0xf0065a2c */

/* WARNING: Removing unreachable block (ram,0xf0065be0) */
/* WARNING: Removing unreachable block (ram,0xf0065bec) */
/* WARNING: Removing unreachable block (ram,0xf0065b84) */
/* WARNING: Removing unreachable block (ram,0xf0065b3c) */
/* WARNING: Removing unreachable block (ram,0xf0065b04) */
/* WARNING: Removing unreachable block (ram,0xf0065a84) */
/* WARNING: Removing unreachable block (ram,0xf0065a70) */
/* WARNING: Removing unreachable block (ram,0xf0065acc) */
/* WARNING: Removing unreachable block (ram,0xf0065b30) */
/* WARNING: Removing unreachable block (ram,0xf0065b74) */
/* WARNING: Removing unreachable block (ram,0xf0065ba4) */
/* WARNING: Removing unreachable block (ram,0xf0065bfc) */
/* WARNING: Removing unreachable block (ram,0xf0065c18) */
/* WARNING: Removing unreachable block (ram,0xf0065a5c) */

undefined8
_mach_msg(int param_1,undefined *param_2,undefined4 param_3,uint param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 unaff_l0;
  uint uVar5;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 uVar6;
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
  bool bVar7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  uVar5 = *(uint *)(*(int *)(_active_threads + 0xc) + 0x88);
  uVar6 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc);
  if (((uint)param_2 & 1) != 0) {
    iVar1 = param_1;
    _ipc_kmsg_get_from_kernel(param_1,param_3,0,(undefined *)((int)register0x00000038 + -0xc));
    if (iVar1 != 0) {
      _panic(aMachMsg);
    }
    iVar1 = *(int *)((int)register0x00000038 + -0xc);
    _ipc_kmsg_copyin(iVar1,uVar5,uVar6,0);
    iVar2 = *(int *)((int)register0x00000038 + -0xc);
    if (iVar1 != 0) {
      iVar1 = *(int *)(iVar2 + 8);
      if (0 < iVar1) {
        _kfree();
        return CONCAT44(iVar1,iVar2);
      }
      _ipc_kmsg_free();
      return CONCAT44(iVar1,iVar2);
    }
    iVar1 = *(int *)((int)register0x00000038 + -0xc);
    do {
      _ipc_mqueue_send(iVar1,0,0,0);
      bVar7 = iVar1 == 0x10000007;
      iVar1 = *(int *)((int)register0x00000038 + -0xc);
    } while (bVar7);
  }
  if (((uint)param_2 & 2) != 0) {
    param_2 = (undefined *)((int)register0x00000038 + -0x18);
    do {
      uVar3 = uVar5;
      _ipc_mqueue_copyin(uVar5,param_5,(undefined *)((int)register0x00000038 + -0x10),
                         (undefined *)((int)register0x00000038 + -0x14));
      if (uVar3 != 0) goto locret_F0065C24;
      uVar3 = *(uint *)((int)register0x00000038 + -0x10);
      _ipc_mqueue_receive(uVar3,0,0xffffffff,0,0,0,(undefined *)((int)register0x00000038 + -0xc),
                          param_2);
      _ipc_object_release(*(undefined4 *)((int)register0x00000038 + -0x14));
    } while (uVar3 == 0x10004005);
    uVar4 = *(uint *)((int)register0x00000038 + -0xc);
    if (uVar3 != 0) goto locret_F0065C24;
    *(undefined4 *)(uVar4 + 0x24) = *(undefined4 *)((int)register0x00000038 + -0x18);
    if (param_4 < *(uint *)(uVar4 + 0x18)) {
      _ipc_kmsg_copyout_dest(uVar4,uVar5);
      _ipc_kmsg_put_to_kernel(param_1,*(undefined4 *)((int)register0x00000038 + -0xc),0x18);
      uVar3 = 0x10004004;
      goto locret_F0065C24;
    }
    _ipc_kmsg_copyout(uVar4,uVar5,uVar6,0);
    if (uVar4 != 0) {
      uVar3 = uVar4;
      if ((uVar4 & 0xffffc3ff) == 0x1000400c) {
        iVar1 = *(int *)((int)register0x00000038 + -0xc);
        _ipc_kmsg_put_to_kernel(param_1,iVar1,*(int *)(iVar1 + 0x18) + *(int *)(iVar1 + 0x10));
      }
      else {
        _ipc_kmsg_copyout_dest(*(undefined4 *)((int)register0x00000038 + -0xc),uVar5);
        _ipc_kmsg_put_to_kernel(param_1,*(undefined4 *)((int)register0x00000038 + -0xc),0x18);
      }
      goto locret_F0065C24;
    }
    iVar1 = *(int *)((int)register0x00000038 + -0xc);
    _ipc_kmsg_put_to_kernel(param_1,iVar1,*(int *)(iVar1 + 0x18) + *(int *)(iVar1 + 0x10));
  }
  uVar3 = 0;
locret_F0065C24:
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=1327 start=0xf0065c2c */

/* WARNING: Removing unreachable block (ram,0xf0065cb8) */
/* WARNING: Removing unreachable block (ram,0xf0065ca4) */
/* WARNING: Removing unreachable block (ram,0xf0065c5c) */
/* WARNING: Removing unreachable block (ram,0xf0065c70) */
/* WARNING: Removing unreachable block (ram,0xf0065cc4) */
/* WARNING: Removing unreachable block (ram,0xf0065c48) */

undefined8 _msg_send_from_kernel(int param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 uVar2;
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
  undefined auStackX_0 [92];
  
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
  uVar1 = *(int *)(param_1 + 4) + 3U & 0xfffffffc;
  _ipc_kmsg_get_from_kernel
            (param_1,uVar1,*(int *)(param_1 + 4) - uVar1,
             (undefined *)((int)register0x00000038 + -0xc));
  if (param_1 == 0) {
    _ipc_kmsg_copyin_compat_from_kernel(*(undefined4 *)((int)register0x00000038 + -0xc));
    if ((param_2 & 2) == 0) {
      param_1 = *(int *)((int)register0x00000038 + -0xc);
      if ((param_2 & 1) == 0) {
        uVar2 = 0x30000;
      }
      else {
        uVar2 = 0x30010;
      }
      _ipc_mqueue_send(param_1,uVar2,param_3,0);
    }
    else {
      _panic(aMsgSendFromKer);
    }
    if (param_1 != 0) {
      _ipc_kmsg_destroy(*(undefined4 *)((int)register0x00000038 + -0xc));
    }
  }
  _msg_return_translate();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1328 start=0xf0065cd4 */

/* WARNING: Removing unreachable block (ram,0xf0065d68) */
/* WARNING: Removing unreachable block (ram,0xf0065e3c) */
/* WARNING: Removing unreachable block (ram,0xf0065e04) */
/* WARNING: Removing unreachable block (ram,0xf0065d44) */
/* WARNING: Removing unreachable block (ram,0xf0065dd4) */
/* WARNING: Removing unreachable block (ram,0xf0065d84) */
/* WARNING: Removing unreachable block (ram,0xf0065d30) */
/* WARNING: Removing unreachable block (ram,0xf0065e48) */
/* WARNING: Removing unreachable block (ram,0xf0065d18) */

undefined8 _msg_send(int param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 unaff_l0;
  undefined4 uVar2;
  undefined4 unaff_l1;
  undefined4 uVar3;
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
  undefined auStackX_0 [92];
  
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
  uVar1 = *(int *)(param_1 + 4) + 3U & 0xfffffffc;
  uVar3 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x88);
  uVar2 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc);
  if (uVar1 < 0x2001) {
    _ipc_kmsg_get_from_kernel
              (param_1,uVar1,*(int *)(param_1 + 4) - uVar1,
               (undefined *)((int)register0x00000038 + -0xc));
    if (param_1 == 0) {
      param_1 = *(int *)((int)register0x00000038 + -0xc);
      _ipc_kmsg_copyin_compat(param_1,uVar3,uVar2);
      if (param_1 == 0) {
        if ((param_2 & 2) == 0) {
          do {
            if ((param_2 & 0x20) == 0) {
              param_1 = *(int *)((int)register0x00000038 + -0xc);
              uVar1 = -(param_2 & 1) & 0x10;
            }
            else {
              param_1 = *(int *)((int)register0x00000038 + -0xc);
              uVar1 = 0x20000;
              if ((param_2 & 1) != 0) {
                uVar1 = 0x20010;
              }
            }
            _ipc_mqueue_send(param_1,uVar1,param_3,0);
            if (param_1 == 0x10000007) {
              uVar1 = *(uint *)(_active_threads + 0x18c);
              while ((uVar1 & 3) != 0) {
                _thread_halt_self_with_continuation(0);
                uVar1 = *(uint *)(_active_threads + 0x18c);
              }
              if ((param_2 & 4) != 0) break;
            }
          } while (param_1 == 0x10000007);
        }
        else {
          _panic(aMsgSendNotify);
        }
        if (param_1 != 0) {
          _ipc_kmsg_destroy(*(undefined4 *)((int)register0x00000038 + -0xc));
        }
      }
      else if (*(int *)(*(int *)((int)register0x00000038 + -0xc) + 8) < 1) {
        _ipc_kmsg_free();
      }
      else {
        _kfree();
      }
    }
    _msg_return_translate();
  }
  else {
    param_1 = -0x6d;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1329 start=0xf0065e5c */

/* WARNING: Removing unreachable block (ram,0xf0065fa4) */
/* WARNING: Removing unreachable block (ram,0xf0065fbc) */
/* WARNING: Removing unreachable block (ram,0xf0065ee8) */
/* WARNING: Removing unreachable block (ram,0xf0065edc) */
/* WARNING: Removing unreachable block (ram,0xf0065f14) */
/* WARNING: Removing unreachable block (ram,0xf0065f84) */
/* WARNING: Removing unreachable block (ram,0xf0065fcc) */
/* WARNING: Removing unreachable block (ram,0xf0065e94) */

undefined8 _msg_receive(int param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar3;
  undefined4 unaff_l3;
  uint uVar4;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 uVar5;
  undefined4 unaff_l7;
  undefined4 uVar6;
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
  undefined auStackX_0 [92];
  
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
  uVar5 = *(undefined4 *)(param_1 + 0xc);
  uVar4 = *(uint *)(param_1 + 4);
  iVar3 = *(int *)(*(int *)(_active_threads + 0xc) + 0x88);
  uVar6 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc);
  do {
    iVar2 = iVar3;
    _ipc_mqueue_copyin(iVar3,uVar5,(undefined *)((int)register0x00000038 + -0xc),
                       (undefined *)((int)register0x00000038 + -0x10));
    if (iVar2 != 0) goto loc_F0065FCC;
    iVar2 = *(int *)((int)register0x00000038 + -0xc);
    uVar1 = 0xffffffff;
    if ((param_2 & 0x1000) != 0) {
      uVar1 = uVar4;
    }
    _ipc_mqueue_receive(iVar2,param_2 & 0x100,uVar1,param_3,0,0,
                        (undefined *)((int)register0x00000038 + -0x14),
                        (undefined *)((int)register0x00000038 + -0x18));
    _ipc_object_release(*(undefined4 *)((int)register0x00000038 + -0x10));
    if (iVar2 == 0x10004005) {
      uVar1 = *(uint *)(_active_threads + 0x18c);
      while ((uVar1 & 3) != 0) {
        _thread_halt_self_with_continuation(0);
        uVar1 = *(uint *)(_active_threads + 0x18c);
      }
      if ((param_2 & 0x400) != 0) break;
    }
  } while (iVar2 == 0x10004005);
  if (iVar2 == 0) {
    iVar2 = *(int *)((int)register0x00000038 + -0x14);
    if (uVar4 < *(uint *)(iVar2 + 0x18)) {
      _ipc_kmsg_destroy(iVar2);
      iVar2 = 0x10004004;
    }
    else {
      _ipc_kmsg_copyout_compat(iVar2,iVar3,uVar6);
      iVar3 = *(int *)((int)register0x00000038 + -0x14);
      *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) + *(int *)(iVar3 + 0x10);
      _ipc_kmsg_put_to_kernel(param_1);
    }
  }
  else if (iVar2 == 0x10004004) {
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)((int)register0x00000038 + -0x14);
  }
loc_F0065FCC:
  _msg_return_translate(iVar2);
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=1330 start=0xf0065fdc */

/* WARNING: Removing unreachable block (ram,0xf0066070) */
/* WARNING: Removing unreachable block (ram,0xf0066558) */
/* WARNING: Removing unreachable block (ram,0xf006635c) */
/* WARNING: Removing unreachable block (ram,0xf00664b4) */
/* WARNING: Removing unreachable block (ram,0xf0066474) */
/* WARNING: Removing unreachable block (ram,0xf006641c) */
/* WARNING: Removing unreachable block (ram,0xf00663c8) */
/* WARNING: Removing unreachable block (ram,0xf0066304) */
/* WARNING: Removing unreachable block (ram,0xf0066170) */
/* WARNING: Removing unreachable block (ram,0xf00660e0) */
/* WARNING: Removing unreachable block (ram,0xf00662b4) */
/* WARNING: Removing unreachable block (ram,0xf006627c) */
/* WARNING: Removing unreachable block (ram,0xf00660b4) */
/* WARNING: Removing unreachable block (ram,0xf006604c) */
/* WARNING: Removing unreachable block (ram,0xf006609c) */
/* WARNING: Removing unreachable block (ram,0xf006624c) */
/* WARNING: Removing unreachable block (ram,0xf00661fc) */
/* WARNING: Removing unreachable block (ram,0xf00662d0) */
/* WARNING: Removing unreachable block (ram,0xf0066104) */
/* WARNING: Removing unreachable block (ram,0xf00661b8) */
/* WARNING: Removing unreachable block (ram,0xf0066388) */
/* WARNING: Removing unreachable block (ram,0xf0066400) */
/* WARNING: Removing unreachable block (ram,0xf0066468) */
/* WARNING: Removing unreachable block (ram,0xf0066520) */
/* WARNING: Removing unreachable block (ram,0xf00664e0) */
/* WARNING: Removing unreachable block (ram,0xf0066538) */
/* WARNING: Removing unreachable block (ram,0xf0066038) */
/* WARNING: Removing unreachable block (ram,0xf0066564) */
/* WARNING: Removing unreachable block (ram,0xf0066020) */

undefined8 _msg_rpc(int *param_1,uint param_2,uint param_3,undefined4 param_4,undefined4 param_5)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  undefined4 unaff_l0;
  int *piVar5;
  undefined4 unaff_l1;
  int *piVar6;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  int iVar7;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 uVar8;
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
  undefined auStackX_0 [92];
  
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
  uVar4 = param_1[1] + 3U & 0xfffffffc;
  iVar7 = *(int *)(*(int *)(_active_threads + 0xc) + 0x88);
  uVar8 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc);
  if (0x2000 < uVar4) {
    param_1 = (int *)0xffffff93;
    goto locret_F0066570;
  }
  piVar1 = param_1;
  _ipc_kmsg_get_from_kernel
            (param_1,uVar4,param_1[1] - uVar4,(undefined *)((int)register0x00000038 + -0xc));
  if (piVar1 == (int *)0x0) {
    piVar1 = *(int **)((int)register0x00000038 + -0xc);
    _ipc_kmsg_copyin_compat(piVar1,iVar7,uVar8);
    iVar2 = *(int *)((int)register0x00000038 + -0xc);
    if (piVar1 == (int *)0x0) {
      piVar6 = *(int **)(iVar2 + 0x20);
      if ((piVar6 == (int *)0x0) || (piVar6 == (int *)0xffffffff)) {
loc_F00661F4:
        if ((param_2 & 2) == 0) {
          do {
            if ((param_2 & 0x20) == 0) {
              piVar1 = *(int **)((int)register0x00000038 + -0xc);
              uVar4 = -(param_2 & 1) & 0x10;
            }
            else {
              piVar1 = *(int **)((int)register0x00000038 + -0xc);
              uVar4 = 0x20000;
              if ((param_2 & 1) != 0) {
                uVar4 = 0x20010;
              }
            }
            _ipc_mqueue_send(piVar1,uVar4,param_4,0);
            if (piVar1 == (int *)0x10000007) {
              uVar4 = *(uint *)(_active_threads + 0x18c);
              while ((uVar4 & 3) != 0) {
                _thread_halt_self_with_continuation(0);
                uVar4 = *(uint *)(_active_threads + 0x18c);
              }
              if ((param_2 & 4) != 0) break;
            }
          } while (piVar1 == (int *)0x10000007);
        }
        else {
          _panic(aMsgRpcNotify);
        }
        if (piVar1 == (int *)0x0) {
loc_F00662E4:
          if (piVar6 != (int *)0x0) {
            if (piVar6 == (int *)0xffffffff) {
              param_1 = (int *)0xffffff36;
              goto locret_F0066570;
            }
            do {
              do {
              } while (*piVar6 != 0);
              piVar1 = piVar6;
              _simple_lock_try();
            } while (piVar1 == (int *)0x0);
            if (piVar6[3] == iVar7) {
              piVar1 = (int *)piVar6[0xc];
              if (piVar1 != (int *)0x0) {
                do {
                  do {
                  } while (*piVar1 != 0);
                  piVar5 = piVar1;
                  _simple_lock_try();
                } while (piVar5 == (int *)0x0);
                if (piVar1[2] < 0) {
                  *piVar1 = 0;
                  piVar6[1] = piVar6[1] + -1;
                  *piVar6 = 0;
                  goto loc_F00663C0;
                }
                _ipc_pset_remove(piVar1,piVar6);
                *piVar1 = 0;
                if (piVar1[1] == 0) {
                  _zfree((&_ipc_object_zones)[(piVar1[2] & 0x7fffffffU) >> 0x10],piVar1);
                }
              }
              do {
                do {
                  piVar1 = piVar6 + 0x10;
                } while (*piVar1 != 0);
                piVar5 = piVar1;
                _simple_lock_try();
              } while (piVar5 == (int *)0x0);
              *piVar6 = 0;
              uVar4 = 0xffffffff;
              if ((param_2 & 0x1000) != 0) {
                uVar4 = param_3;
              }
              _ipc_mqueue_receive(piVar1,param_2 & 0x100,uVar4,param_5,0,0,
                                  (undefined *)((int)register0x00000038 + -0xc),
                                  (undefined *)((int)register0x00000038 + -0x10));
              _ipc_object_release(piVar6);
              if (piVar1 == (int *)0x0) {
                if (*(uint *)(*(int *)((int)register0x00000038 + -0xc) + 0x18) <= param_3)
                goto loc_F0066534;
                _ipc_kmsg_destroy(*(int *)((int)register0x00000038 + -0xc));
                piVar1 = (int *)0x10004004;
              }
              else if (piVar1 == (int *)0x10004005) {
                uVar4 = *(uint *)(_active_threads + 0x18c);
                while ((uVar4 & 3) != 0) {
                  _thread_halt_self_with_continuation(0);
                  uVar4 = *(uint *)(_active_threads + 0x18c);
                }
                param_1[1] = param_3;
                if ((param_2 & 0x400) == 0) {
                  _msg_receive(param_1,param_2,param_5);
                  goto locret_F0066570;
                }
              }
              else if (piVar1 == (int *)0x10004004) {
                param_1[1] = *(int *)((int)register0x00000038 + -0xc);
              }
              goto loc_F0066564;
            }
            iVar7 = piVar6[1];
            piVar6[1] = iVar7 + -1;
            *piVar6 = 0;
            if (iVar7 + -1 == 0) {
              _zfree((&_ipc_object_zones)[(piVar6[2] & 0x7fffffffU) >> 0x10],piVar6);
              param_1 = (int *)0xffffff36;
              goto locret_F0066570;
            }
          }
loc_F00663C0:
          param_1 = (int *)0xffffff36;
          goto locret_F0066570;
        }
        _ipc_kmsg_destroy(*(undefined4 *)((int)register0x00000038 + -0xc));
        if ((piVar6 != (int *)0x0) && (piVar6 != (int *)0xffffffff)) {
          _ipc_object_release(piVar6);
        }
      }
      else {
        piVar5 = *(int **)(iVar2 + 0x1c);
        _ipc_object_reference(piVar6);
        do {
          do {
          } while (*piVar5 != 0);
          piVar3 = piVar5;
          _simple_lock_try();
        } while (piVar3 == (int *)0x0);
        iVar2 = *(int *)((int)register0x00000038 + -0xc);
        if (piVar5[3] != _ipc_space_kernel) {
          *piVar5 = 0;
          goto loc_F00661F4;
        }
        *piVar5 = 0;
        _ipc_kobject_server();
        *(int *)((int)register0x00000038 + -0xc) = iVar2;
        if (iVar2 == 0) goto loc_F00662E4;
        do {
          do {
          } while (*piVar6 != 0);
          piVar1 = piVar6;
          _simple_lock_try();
        } while (piVar1 == (int *)0x0);
        if ((((-1 < piVar6[2]) || (piVar6[3] != iVar7)) || (piVar6[0xc] != 0)) ||
           (piVar1 = piVar6 + 0x10,
           param_3 < (uint)(*(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x18) +
                           *(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x10)))) {
loc_F00661A8:
          *piVar6 = 0;
          _ipc_mqueue_send(*(undefined4 *)((int)register0x00000038 + -0xc),0x10000,0,0);
          goto loc_F00662E4;
        }
        do {
          do {
          } while (*piVar1 != 0);
          piVar5 = piVar1;
          _simple_lock_try();
        } while (piVar5 == (int *)0x0);
        if ((piVar6[0x12] != 0) || (piVar6[0x11] != 0)) {
          *piVar1 = 0;
          goto loc_F00661A8;
        }
        piVar6[0xd] = piVar6[0xd] + 1;
        *piVar1 = 0;
        piVar6[1] = piVar6[1] + -1;
        *piVar6 = 0;
loc_F0066534:
        piVar1 = *(int **)((int)register0x00000038 + -0xc);
        _ipc_kmsg_copyout_compat(piVar1,iVar7,uVar8);
        iVar7 = *(int *)((int)register0x00000038 + -0xc);
        *(int *)(iVar7 + 0x18) = *(int *)(iVar7 + 0x18) + *(int *)(iVar7 + 0x10);
        _ipc_kmsg_put_to_kernel(param_1);
      }
    }
    else if (*(int *)(iVar2 + 8) < 1) {
      _ipc_kmsg_free();
    }
    else {
      _kfree();
    }
  }
loc_F0066564:
  _msg_return_translate();
  param_1 = piVar1;
locret_F0066570:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1331 start=0xf0066578 */

/* WARNING: Removing unreachable block (ram,0xf0066594) */

undefined8 _mig_get_reply_port(undefined4 param_1,undefined4 param_2)

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
  undefined4 uVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  iVar1 = _active_threads;
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
  iVar2 = *(int *)(_active_threads + 0xbc);
  if (iVar2 == 0) {
    _mach_reply_port();
    *(int *)(iVar1 + 0xbc) = iVar2;
    uVar3 = *(undefined4 *)(iVar1 + 0xbc);
  }
  else {
    uVar3 = *(undefined4 *)(_active_threads + 0xbc);
  }
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=1332 start=0xf00665ac */

/* WARNING: Removing unreachable block (ram,0xf00665b4) */

undefined8 _mig_dealloc_reply_port(undefined4 param_1,undefined4 param_2)

{
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
  _panic(aMigDeallocRepl);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1333 start=0xf00665c4 */

undefined8 _mig_strncpy(char *param_1,char *param_2,int param_3)

{
  char cVar1;
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
  iVar2 = 1;
  if (0 < param_3) {
    if (param_3 < 2) {
      *param_1 = '\0';
    }
    else {
      cVar1 = *param_2;
      while( true ) {
        *param_1 = cVar1;
        param_2 = param_2 + 1;
        param_1 = param_1 + 1;
        if (cVar1 == '\0') break;
        iVar2 = iVar2 + 1;
        if (param_3 <= iVar2) {
          *param_1 = '\0';
          break;
        }
        cVar1 = *param_2;
      }
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1334 start=0xf0066614 */

/* WARNING: Removing unreachable block (ram,0xf00666dc) */
/* WARNING: Removing unreachable block (ram,0xf0066634) */
/* WARNING: Removing unreachable block (ram,0xf0066658) */
/* WARNING: Removing unreachable block (ram,0xf00666f8) */
/* WARNING: Removing unreachable block (ram,0xf0066618) */

undefined8 _thread_go(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
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
  iVar1 = param_1;
  _splusclock();
  do {
    do {
    } while (*(int *)(param_1 + 0x20) != 0);
    piVar2 = (int *)(param_1 + 0x20);
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  if (*(int *)(param_1 + 0x14c) == 0) {
    uVar3 = *(uint *)(param_1 + 0x4c);
  }
  else {
    _reset_timeout(param_1 + 0x118);
    uVar3 = *(uint *)(param_1 + 0x4c);
  }
  switch(uVar3 & 0xf) {
  case :
  case :
  case :
    *(uint *)(param_1 + 0x4c) = uVar3 & 0xfffffffe | 4;
    *(undefined4 *)(param_1 + 0x44) = 0;
    _thread_setrun(param_1,1);
    break;
  case :
  case :
  case :
  case :
  case :
    *(uint *)(param_1 + 0x4c) = uVar3 & 0xfffffffe;
    *(undefined4 *)(param_1 + 0x44) = 0;
  }
  *(undefined4 *)(param_1 + 0x20) = 0;
  _splx(iVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1335 start=0xf0066708 */

/* WARNING: Removing unreachable block (ram,0xf006683c) */
/* WARNING: Removing unreachable block (ram,0xf00667f8) */
/* WARNING: Removing unreachable block (ram,0xf006674c) */
/* WARNING: Removing unreachable block (ram,0xf0066728) */
/* WARNING: Removing unreachable block (ram,0xf006680c) */
/* WARNING: Removing unreachable block (ram,0xf0066834) */
/* WARNING: Removing unreachable block (ram,0xf0066844) */
/* WARNING: Removing unreachable block (ram,0xf006670c) */

undefined8 _thread_go_and_switch(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
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
  iVar1 = param_1;
  _splusclock();
  do {
    do {
    } while (*(int *)(param_2 + 0x20) != 0);
    piVar2 = (int *)(param_2 + 0x20);
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  if (*(int *)(param_2 + 0x14c) == 0) {
    uVar3 = *(uint *)(param_2 + 0x4c);
  }
  else {
    _reset_timeout(param_2 + 0x118);
    uVar3 = *(uint *)(param_2 + 0x4c);
  }
  switch(uVar3 & 0xf) {
  case :
  case :
  case :
    *(uint *)(param_2 + 0x4c) = uVar3 & 0xfffffffe | 4;
    *(undefined4 *)(param_2 + 0x44) = 0;
    if ((*(int *)(*(int *)(param_2 + 400) + 0x114) < 1) &&
       (*(int *)(param_2 + 400) == *(int *)(_active_threads + 400))) {
      *(undefined4 *)(param_2 + 0x20) = 0;
      _thread_run(param_1,param_2);
      goto loc_F0066844;
    }
    _thread_setrun(param_2,1);
    break;
  case :
  case :
  case :
  case :
  case :
    *(uint *)(param_2 + 0x4c) = uVar3 & 0xfffffffe;
    *(undefined4 *)(param_2 + 0x44) = 0;
  }
  *(undefined4 *)(param_2 + 0x20) = 0;
  if (param_1 != 0) {
    _spl0();
    _call_continuation(param_1);
  }
loc_F0066844:
  _splx(iVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1336 start=0xf0066854 */

/* WARNING: Removing unreachable block (ram,0xf0066874) */
/* WARNING: Removing unreachable block (ram,0xf0066898) */
/* WARNING: Removing unreachable block (ram,0xf0066858) */

undefined8 _thread_will_wait(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
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
  iVar1 = param_1;
  _splusclock();
  do {
    do {
    } while (*(int *)(param_1 + 0x20) != 0);
    piVar2 = (int *)(param_1 + 0x20);
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 1;
  _splx(iVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1337 start=0xf00668a8 */

/* WARNING: Removing unreachable block (ram,0xf006691c) */
/* WARNING: Removing unreachable block (ram,0xf00668cc) */
/* WARNING: Removing unreachable block (ram,0xf00668c4) */
/* WARNING: Removing unreachable block (ram,0xf00668e8) */
/* WARNING: Removing unreachable block (ram,0xf0066928) */
/* WARNING: Removing unreachable block (ram,0xf00668b8) */

undefined8 _thread_will_wait_with_timeout(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
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
  iVar1 = param_2;
  .umul(param_2,_hz);
  iVar1 = iVar1 + 999;
  .udiv(iVar1,1000);
  iVar2 = iVar1;
  _splusclock();
  do {
    do {
    } while (*(int *)(param_1 + 0x20) != 0);
    piVar3 = (int *)(param_1 + 0x20);
    _simple_lock_try();
  } while (piVar3 == (int *)0x0);
  *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 1;
  if ((iVar1 != 0) || (param_2 == 0)) {
    _set_timeout(param_1 + 0x118,iVar1);
  }
  *(undefined4 *)(param_1 + 0x20) = 0;
  _splx(iVar2);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1338 start=0xf0066938 */

/* WARNING: Removing unreachable block (ram,0xf0066a78) */
/* WARNING: Removing unreachable block (ram,0xf0066a18) */
/* WARNING: Removing unreachable block (ram,0xf00669f0) */
/* WARNING: Removing unreachable block (ram,0xf0066994) */
/* WARNING: Removing unreachable block (ram,0xf0066958) */
/* WARNING: Removing unreachable block (ram,0xf00669c0) */
/* WARNING: Removing unreachable block (ram,0xf00669fc) */
/* WARNING: Removing unreachable block (ram,0xf0066a84) */
/* WARNING: Removing unreachable block (ram,0xf0066a90) */
/* WARNING: Removing unreachable block (ram,0xf006693c) */

undefined8 _thread_handoff(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
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
  iVar1 = param_1;
  _splusclock();
  do {
    do {
    } while (*(int *)(param_3 + 0x20) != 0);
    piVar2 = (int *)(param_3 + 0x20);
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  if ((*(int *)(param_1 + 0x30) == _active_stacks) || (*(int *)(param_3 + 0x4c) != 0x101)) {
    *(undefined4 *)(param_3 + 0x20) = 0;
    _splx(iVar1);
    uVar3 = 0;
    _c_thread_handoff_misses = _c_thread_handoff_misses + 1;
    goto locret_F0066AAC;
  }
  if (*(int *)(param_3 + 0x14c) != 0) {
    _reset_timeout(param_3 + 0x118);
  }
  *(undefined4 *)(param_3 + 0x4c) = 4;
  *(undefined4 *)(param_3 + 0x20) = 0;
  _need_ast = _need_ast & 0xfffffffc | *(uint *)(param_3 + 0x18c);
  _switch_unix_context(param_3);
  _stack_handoff(param_1,param_3);
  do {
    do {
    } while (*(int *)(param_1 + 0x20) != 0);
    piVar2 = (int *)(param_1 + 0x20);
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  *(undefined4 *)(param_1 + 0x34) = param_2;
  if (*(int *)(param_1 + 0x4c) == 4) {
    *(undefined4 *)(param_1 + 0x4c) = 0x101;
loc_F0066A8C:
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  else {
    if (*(int *)(param_1 + 0x4c) != 6) {
      _panic(aThreadHandoff);
      goto loc_F0066A8C;
    }
    *(undefined4 *)(param_1 + 0x4c) = 0x103;
    if (*(int *)(param_1 + 0x48) == 0) goto loc_F0066A8C;
    *(undefined4 *)(param_1 + 0x48) = 0;
    *(undefined4 *)(param_1 + 0x20) = 0;
    _thread_wakeup_prim(param_1 + 0x48,0,0);
  }
  _splx(iVar1);
  uVar3 = 1;
  _c_thread_handoff_hits = _c_thread_handoff_hits + 1;
locret_F0066AAC:
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=1339 start=0xf0066ab4 */

/* WARNING: Removing unreachable block (ram,0xf0066b98) */
/* WARNING: Removing unreachable block (ram,0xf0066b5c) */
/* WARNING: Removing unreachable block (ram,0xf0066af8) */
/* WARNING: Removing unreachable block (ram,0xf0066ad8) */
/* WARNING: Removing unreachable block (ram,0xf0066ae4) */
/* WARNING: Removing unreachable block (ram,0xf0066b08) */
/* WARNING: Removing unreachable block (ram,0xf0066b7c) */
/* WARNING: Removing unreachable block (ram,0xf0066ba4) */
/* WARNING: Removing unreachable block (ram,0xf0066ac0) */

undefined8 _ipc_task_init(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar4;
  int iVar5;
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
  undefined auStackX_0 [92];
  
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
  iVar1 = _ipc_table_entries;
  _ipc_space_create(_ipc_table_entries,(undefined *)((int)register0x00000038 + -0xc));
  if (iVar1 != 0) {
    _panic(aIpcTaskInit);
  }
  iVar1 = _ipc_space_kernel;
  _ipc_port_alloc_special();
  if (iVar1 == 0) {
    _panic(aIpcTaskInit_0);
  }
  *(undefined4 *)(param_1 + 100) = 0;
  *(int *)(param_1 + 0x68) = iVar1;
  _ipc_port_make_send();
  *(int *)(param_1 + 0x6c) = iVar1;
  *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)((int)register0x00000038 + -0xc);
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0x70) = 0;
    *(undefined4 *)(param_1 + 0x74) = 0;
    *(undefined4 *)(param_1 + 0x84) = 0;
    iVar1 = param_1 + 0xc;
    while (param_1 <= iVar1 + -4) {
      *(undefined4 *)(iVar1 + 0x74) = 0;
      iVar1 = iVar1 + -4;
    }
  }
  else {
    do {
      do {
      } while (*(int *)(param_2 + 100) != 0);
      piVar2 = (int *)(param_2 + 100);
      _simple_lock_try();
      iVar5 = 0;
      iVar1 = param_2;
      iVar4 = param_1;
    } while (piVar2 == (int *)0x0);
    do {
      uVar3 = *(undefined4 *)(iVar1 + 0x78);
      iVar5 = iVar5 + 1;
      _ipc_port_copy_send();
      *(undefined4 *)(iVar4 + 0x78) = uVar3;
      iVar1 = iVar1 + 4;
      iVar4 = iVar4 + 4;
    } while (iVar5 < 4);
    uVar3 = *(undefined4 *)(param_2 + 0x70);
    _ipc_port_copy_send();
    *(undefined4 *)(param_1 + 0x70) = uVar3;
    uVar3 = *(undefined4 *)(param_2 + 0x74);
    _ipc_port_copy_send();
    *(undefined4 *)(param_1 + 0x74) = uVar3;
    *(undefined4 *)(param_2 + 100) = 0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1340 start=0xf0066bbc */

/* WARNING: Removing unreachable block (ram,0xf0066bf8) */
/* WARNING: Removing unreachable block (ram,0xf0066bd4) */

undefined8 _ipc_task_enable(int param_1,undefined4 param_2)

{
  int *piVar1;
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
  do {
    do {
    } while (*(int *)(param_1 + 100) != 0);
    piVar1 = (int *)(param_1 + 100);
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  if (*(int *)(param_1 + 0x68) != 0) {
    _ipc_kobject_set(*(int *)(param_1 + 0x68),param_1,2);
  }
  *(undefined4 *)(param_1 + 100) = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1341 start=0xf0066c0c */

/* WARNING: Removing unreachable block (ram,0xf0066c48) */
/* WARNING: Removing unreachable block (ram,0xf0066c24) */

undefined8 _ipc_task_disable(int param_1,undefined4 param_2)

{
  int *piVar1;
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
  do {
    do {
    } while (*(int *)(param_1 + 100) != 0);
    piVar1 = (int *)(param_1 + 100);
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  if (*(int *)(param_1 + 0x68) != 0) {
    _ipc_kobject_set(*(int *)(param_1 + 0x68),0,0);
  }
  *(undefined4 *)(param_1 + 100) = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1342 start=0xf0066c5c */

/* WARNING: Removing unreachable block (ram,0xf0066d3c) */
/* WARNING: Removing unreachable block (ram,0xf0066cfc) */
/* WARNING: Removing unreachable block (ram,0xf0066cbc) */
/* WARNING: Removing unreachable block (ram,0xf0066cdc) */
/* WARNING: Removing unreachable block (ram,0xf0066d28) */
/* WARNING: Removing unreachable block (ram,0xf0066d4c) */
/* WARNING: Removing unreachable block (ram,0xf0066c74) */

undefined8 _ipc_task_terminate(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar3;
  int iVar4;
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
  do {
    do {
    } while (*(int *)(param_1 + 100) != 0);
    piVar1 = (int *)(param_1 + 100);
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  iVar4 = *(int *)(param_1 + 0x68);
  if (iVar4 == 0) {
    *(undefined4 *)(param_1 + 100) = 0;
    goto locret_F0066D54;
  }
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  if (*(int *)(param_1 + 0x6c) == 0) {
loc_F0066CC4:
    iVar2 = *(int *)(param_1 + 0x70);
  }
  else {
    if (*(int *)(param_1 + 0x6c) != -1) {
      _ipc_port_release_send();
      goto loc_F0066CC4;
    }
    iVar2 = *(int *)(param_1 + 0x70);
  }
  if (iVar2 == 0) {
loc_F0066CE4:
    iVar2 = *(int *)(param_1 + 0x74);
  }
  else {
    if (iVar2 != -1) {
      _ipc_port_release_send();
      goto loc_F0066CE4;
    }
    iVar2 = *(int *)(param_1 + 0x74);
  }
  if ((iVar2 != 0) && (iVar2 != -1)) {
    _ipc_port_release_send();
  }
  iVar3 = 0;
  iVar2 = param_1;
  do {
    iVar3 = iVar3 + 1;
    if ((*(int *)(iVar2 + 0x78) != 0) && (*(int *)(iVar2 + 0x78) != -1)) {
      _ipc_port_release_send();
    }
    iVar2 = iVar2 + 4;
  } while (iVar3 < 4);
  _ipc_space_destroy(*(undefined4 *)(param_1 + 0x88));
  _ipc_port_dealloc_special(iVar4,_ipc_space_kernel);
locret_F0066D54:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1343 start=0xf0066d5c */

/* WARNING: Removing unreachable block (ram,0xf0066dbc) */
/* WARNING: Removing unreachable block (ram,0xf0066d7c) */
/* WARNING: Removing unreachable block (ram,0xf0066d98) */
/* WARNING: Removing unreachable block (ram,0xf0066dd0) */
/* WARNING: Removing unreachable block (ram,0xf0066d64) */

undefined8 _ipc_thread_init(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
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
  undefined auStackX_0 [92];
  
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
    _panic(aIpcThreadInit);
    *(int *)(param_1 + 0x90) = param_1;
  }
  else {
    *(int *)(param_1 + 0x90) = param_1;
  }
  *(int *)(param_1 + 0x94) = param_1;
  *(undefined4 *)(param_1 + 0xa4) = 0;
  *(undefined4 *)(param_1 + 0xa8) = 0;
  *(int *)(param_1 + 0xac) = iVar1;
  _ipc_port_make_send();
  *(int *)(param_1 + 0xb0) = iVar1;
  *(undefined4 *)(param_1 + 0xb4) = 0;
  *(undefined4 *)(param_1 + 0xbc) = 0;
  *(undefined4 *)(param_1 + 0xc0) = 0;
  iVar1 = *(int *)(*(int *)(param_1 + 0xc) + 0x88);
  _ipc_port_alloc_compat
            (iVar1,(undefined *)((int)register0x00000038 + -0xc),
             (undefined *)((int)register0x00000038 + -0x10));
  if (iVar1 != 0) {
    _panic(aIpcThreadInit_0);
  }
  puVar2 = *(undefined4 **)((int)register0x00000038 + -0x10);
  puVar2[7] = puVar2[7] + 1;
  puVar2[1] = puVar2[1] + 1;
  *puVar2 = 0;
  *(undefined4 **)(param_1 + 0xb8) = puVar2;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1344 start=0xf0066e04 */

/* WARNING: Removing unreachable block (ram,0xf0066e40) */
/* WARNING: Removing unreachable block (ram,0xf0066e1c) */

undefined8 _ipc_thread_enable(int param_1,undefined4 param_2)

{
  int *piVar1;
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
  do {
    do {
    } while (*(int *)(param_1 + 0xa8) != 0);
    piVar1 = (int *)(param_1 + 0xa8);
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  if (*(int *)(param_1 + 0xac) != 0) {
    _ipc_kobject_set(*(int *)(param_1 + 0xac),param_1,1);
  }
  *(undefined4 *)(param_1 + 0xa8) = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1345 start=0xf0066e54 */

/* WARNING: Removing unreachable block (ram,0xf0066e90) */
/* WARNING: Removing unreachable block (ram,0xf0066e6c) */

undefined8 _ipc_thread_disable(int param_1,undefined4 param_2)

{
  int *piVar1;
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
  do {
    do {
    } while (*(int *)(param_1 + 0xa8) != 0);
    piVar1 = (int *)(param_1 + 0xa8);
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  if (*(int *)(param_1 + 0xac) != 0) {
    _ipc_kobject_set(*(int *)(param_1 + 0xac),0,0);
  }
  *(undefined4 *)(param_1 + 0xa8) = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1346 start=0xf0066ea4 */

/* WARNING: Removing unreachable block (ram,0xf0066fe4) */
/* WARNING: Removing unreachable block (ram,0xf0066fb8) */
/* WARNING: Removing unreachable block (ram,0xf0066f4c) */
/* WARNING: Removing unreachable block (ram,0xf0066f04) */
/* WARNING: Removing unreachable block (ram,0xf0066f24) */
/* WARNING: Removing unreachable block (ram,0xf0066f8c) */
/* WARNING: Removing unreachable block (ram,0xf0066fd4) */
/* WARNING: Removing unreachable block (ram,0xf0066ff4) */
/* WARNING: Removing unreachable block (ram,0xf0066ebc) */

undefined8 _ipc_thread_terminate(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar5;
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
  undefined auStackX_0 [92];
  
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
  do {
    do {
    } while (*(int *)(param_1 + 0xa8) != 0);
    piVar1 = (int *)(param_1 + 0xa8);
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  iVar5 = *(int *)(param_1 + 0xac);
  if (iVar5 == 0) {
    *(undefined4 *)(param_1 + 0xa8) = 0;
    goto locret_F0066FFC;
  }
  *(undefined4 *)(param_1 + 0xac) = 0;
  *(undefined4 *)(param_1 + 0xa8) = 0;
  if (*(int *)(param_1 + 0xb0) == 0) {
loc_F0066F0C:
    iVar2 = *(int *)(param_1 + 0xb4);
  }
  else {
    if (*(int *)(param_1 + 0xb0) != -1) {
      _ipc_port_release_send();
      goto loc_F0066F0C;
    }
    iVar2 = *(int *)(param_1 + 0xb4);
  }
  if (iVar2 == 0) {
loc_F0066F2C:
    iVar2 = *(int *)(param_1 + 0xc0);
  }
  else {
    if (iVar2 != -1) {
      _ipc_port_release_send();
      goto loc_F0066F2C;
    }
    iVar2 = *(int *)(param_1 + 0xc0);
  }
  if (iVar2 == 0) {
loc_F0066F54:
    puVar3 = *(undefined4 **)(param_1 + 0xb8);
  }
  else {
    if (iVar2 != -1) {
      _ipc_port_dealloc_special(iVar2,_ipc_space_reply);
      goto loc_F0066F54;
    }
    puVar3 = *(undefined4 **)(param_1 + 0xb8);
  }
  if ((puVar3 != (undefined4 *)0x0) && (puVar3 != (undefined4 *)0xffffffff)) {
    param_1 = *(int *)(*(int *)(param_1 + 0xc) + 0x88);
    do {
      do {
      } while (*(int *)(param_1 + 8) != 0);
      piVar1 = (int *)(param_1 + 8);
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    if (*(int *)(param_1 + 0xc) == 0) {
loc_F0066FE0:
      *(undefined4 *)(param_1 + 8) = 0;
    }
    else {
      iVar2 = param_1;
      _ipc_right_reverse(param_1,puVar3,(undefined *)((int)register0x00000038 + -0xc),
                         (undefined *)((int)register0x00000038 + -0x10));
      uVar4 = *(undefined4 *)((int)register0x00000038 + -0xc);
      if (iVar2 == 0) goto loc_F0066FE0;
      *puVar3 = 0;
      _ipc_right_destroy(param_1,uVar4,*(undefined4 *)((int)register0x00000038 + -0x10));
    }
    _ipc_port_release_send(puVar3);
  }
  _ipc_port_dealloc_special(iVar5,_ipc_space_kernel);
locret_F0066FFC:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1347 start=0xf0067004 */

/* WARNING: Removing unreachable block (ram,0xf006708c) */
/* WARNING: Removing unreachable block (ram,0xf0067058) */
/* WARNING: Removing unreachable block (ram,0xf0067020) */

undefined8 _retrieve_task_self_fast(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar2;
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
  do {
    do {
    } while (*(int *)(param_1 + 100) != 0);
    piVar2 = (int *)(param_1 + 100);
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  piVar2 = *(int **)(param_1 + 0x6c);
  if (piVar2 == *(int **)(param_1 + 0x68)) {
    do {
      do {
      } while (*piVar2 != 0);
      piVar1 = piVar2;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    piVar2[1] = piVar2[1] + 1;
    piVar2[7] = piVar2[7] + 1;
    *piVar2 = 0;
  }
  else {
    _ipc_port_copy_send(piVar2);
  }
  *(undefined4 *)(param_1 + 100) = 0;
  return CONCAT44(param_2,piVar2);
}
/* GHIDRADEC_FUNCTION index=1348 start=0xf00670a4 */

/* WARNING: Removing unreachable block (ram,0xf006712c) */
/* WARNING: Removing unreachable block (ram,0xf00670f8) */
/* WARNING: Removing unreachable block (ram,0xf00670c0) */

undefined8 _retrieve_thread_self_fast(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar2;
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
  do {
    do {
    } while (*(int *)(param_1 + 0xa8) != 0);
    piVar2 = (int *)(param_1 + 0xa8);
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  piVar2 = *(int **)(param_1 + 0xb0);
  if (piVar2 == *(int **)(param_1 + 0xac)) {
    do {
      do {
      } while (*piVar2 != 0);
      piVar1 = piVar2;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    piVar2[1] = piVar2[1] + 1;
    piVar2[7] = piVar2[7] + 1;
    *piVar2 = 0;
  }
  else {
    _ipc_port_copy_send(piVar2);
  }
  *(undefined4 *)(param_1 + 0xa8) = 0;
  return CONCAT44(param_2,piVar2);
}
/* GHIDRADEC_FUNCTION index=1349 start=0xf0067144 */

/* WARNING: Removing unreachable block (ram,0xf006715c) */
/* WARNING: Removing unreachable block (ram,0xf0067154) */

undefined8 _mach_task_self(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 uVar1;
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
  uVar1 = *(undefined4 *)(_active_threads + 0xc);
  _retrieve_task_self_fast(uVar1);
  _ipc_port_copyout_send();
  return CONCAT44(param_2,uVar1);
}

