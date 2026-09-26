/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015d57c */

int FUN_0015d57c(undefined4 param_1,int *param_2,undefined4 *param_3,undefined4 *param_4,
                undefined4 *param_5)

{
  int iVar1;
  int *piVar2;
  int *local_38;
  int local_34 [7];
  undefined1 local_18 [8];
  undefined4 local_10;
  undefined4 local_c;
  
  iVar1 = _lookupname(param_1,1,1,0,&local_38);
  if (iVar1 != 0) {
    return 4;
  }
  iVar1 = _check_exec_access(local_38);
  if (iVar1 != 0) {
    iVar1 = 6;
    goto LAB_0015d69c;
  }
  iVar1 = _vn_rdwr(0,local_38,local_34,0x1c,0,1,1,0);
  if (iVar1 == 0) {
    if (local_34[0] == -0x1120532) {
      piVar2 = local_34;
      for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
        *param_2 = *piVar2;
        piVar2 = piVar2 + 1;
        param_2 = param_2 + 1;
      }
      *param_3 = 0;
      *param_4 = *(undefined4 *)(*local_38 + 0x14);
LAB_0015d68e:
      *param_5 = local_38;
      return 0;
    }
    if ((local_34[0] == -0x35014542) || (local_34[0] == -0x41450136)) {
      iVar1 = _fatfile_getarch(local_38,local_34,local_18);
      if (iVar1 != 0) goto LAB_0015d69c;
      iVar1 = _vn_rdwr(0,local_38,local_34,0x1c,local_10,1,1,0);
      if (iVar1 != 0) goto LAB_0015d63d;
      if (local_34[0] == -0x1120532) {
        piVar2 = local_34;
        for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
          *param_2 = *piVar2;
          piVar2 = piVar2 + 1;
          param_2 = param_2 + 1;
        }
        *param_3 = local_10;
        *param_4 = local_c;
        goto LAB_0015d68e;
      }
    }
    iVar1 = 2;
  }
  else {
LAB_0015d63d:
    iVar1 = 4;
  }
LAB_0015d69c:
  _vn_rele(local_38);
  return iVar1;
}

