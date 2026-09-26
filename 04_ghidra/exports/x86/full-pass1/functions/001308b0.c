/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001308b0 */

int FUN_001308b0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int local_28;
  undefined4 local_24 [8];
  
  while( true ) {
    iVar1 = _pmap_kgetport(param_1,0x186a5,1,0x11);
    if (iVar1 == -1) {
      return 0xf;
    }
    if (iVar1 != 1) break;
    _printf(s_mountnfs___s__s_portmap_not_resp_001dc93c,param_2,param_3);
  }
  while( true ) {
    piVar2 = (int *)_clntkudp_create(param_1,0x186a5,1,5,*(undefined4 *)(_active_u + 0x1c));
    iVar1 = (**(code **)piVar2[1])(piVar2,1,_xdr_bp_path_t,&param_3,_xdr_fhstatus,&local_28,3,0);
    (**(code **)(*(int *)(*piVar2 + 0x20) + 0x10))(*piVar2);
    (**(code **)(piVar2[1] + 0x10))(piVar2);
    if (iVar1 != 5) break;
    _printf(s_mountnfs___s__s_mount_server_not_001dc964,param_2,param_3);
  }
  if (iVar1 != 0) {
    return iVar1;
  }
  *(undefined2 *)(param_1 + 2) = 0x108;
  puVar3 = local_24;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_4 = *puVar3;
    puVar3 = puVar3 + 1;
    param_4 = param_4 + 1;
  }
  return local_28;
}

