/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001306a8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_001306a8(undefined4 param_1,char *param_2,undefined2 *param_3,char *param_4)

{
  int iVar1;
  int iVar2;
  int local_58;
  int local_4c;
  undefined1 local_48 [4];
  undefined1 *local_44 [2];
  char **local_3c;
  code *local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined **local_24;
  code *local_20;
  undefined *local_1c;
  undefined4 local_18;
  char *local_14;
  int local_10;
  undefined1 local_c [4];
  char *local_8;
  
  local_1c = &_hostname;
  local_18 = param_1;
  _bzero(&local_14,0x10);
  iVar1 = FUN_00130344();
  if (iVar1 == 0) {
    local_14 = (char *)_kalloc(0x100);
    local_8 = (char *)_kalloc(0x100);
    local_58 = 0;
    do {
      _DAT_001e59da = 0x6f00;
      iVar1 = _clntkudp_create(&DAT_001e59d8,100000,2,5,*(undefined4 *)(_active_u + 0x1c));
      if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
        _panic(s_pmap_rmtcall__clntkudp_create_fa_001dc746);
      }
      local_34 = 0x186ba;
      local_30 = 1;
      local_2c = 2;
      local_24 = &local_1c;
      local_20 = _xdr_bp_getfile_arg;
      local_44[0] = local_48;
      local_3c = &local_14;
      local_38 = _xdr_bp_getfile_res;
      iVar2 = _clntkudp_callit_addr
                        (iVar1,5,_xdr_rmtcall_args,&local_34,_xdr_rmtcallres,local_44,5,0,0);
      (**(code **)(*(int *)(iVar1 + 4) + 0x10))(iVar1);
    } while ((iVar2 == 5) && (local_58 = local_58 + 1, local_58 < 5));
    if (iVar2 == 0) {
      _strcpy(param_2,local_14);
      _strcpy(param_4,local_8);
    }
    _kfree(local_14,0x100);
    _kfree(local_8,0x100);
    if (iVar2 == 0) {
      _bcopy(local_c,&local_4c,4);
      if (((*param_2 == '\0') || (*param_4 == '\0')) || (local_4c == 0)) {
        iVar1 = 0x16;
      }
      else if (local_10 == 1) {
        _bzero(param_3,0x10);
        *param_3 = 2;
        *(int *)(param_3 + 2) = local_4c;
        _printf(s_NFS_mounting___s__from__s__s_001dc91d,param_1,param_2,param_4);
        iVar1 = 0;
      }
      else {
        _printf(s_getfile__unknown_address_type__d_001dc8fb,local_10);
        iVar1 = 0x2b;
      }
    }
    else {
      iVar1 = 0x3c;
      if (iVar2 != 5) {
        iVar1 = iVar2;
      }
    }
  }
  return iVar1;
}

