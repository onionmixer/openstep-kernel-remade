/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014c9c4 */

int _ipc_port_alloc(undefined4 param_1,undefined4 *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int local_c;
  undefined4 local_8;
  
  iVar2 = _ipc_object_alloc(param_1,0,0x20000,0,&local_8,&local_c);
  iVar1 = local_c;
  if (iVar2 == 0) {
    *(undefined4 *)(local_c + 0xc) = param_1;
    *(undefined4 *)(local_c + 0x10) = local_8;
    *(undefined4 *)(local_c + 0x18) = 0;
    *(undefined4 *)(local_c + 0x1c) = 0;
    *(undefined4 *)(local_c + 0x20) = 0;
    *(undefined4 *)(local_c + 0x24) = 0;
    *(undefined4 *)(local_c + 0x28) = 0;
    *(undefined4 *)(local_c + 0x2c) = 0;
    *(undefined4 *)(local_c + 0x30) = 0;
    *(undefined4 *)(local_c + 0x34) = 0;
    *(undefined4 *)(local_c + 0x38) = 0;
    *(undefined4 *)(local_c + 0x3c) = 5;
    _ipc_mqueue_init(local_c + 0x40);
    *(undefined4 *)(iVar1 + 0x4c) = 0;
    *param_2 = local_8;
    *param_3 = local_c;
    iVar2 = 0;
  }
  return iVar2;
}

