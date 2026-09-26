/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012eef4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _rfscall(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            int *param_6,int param_7)

{
  int *piVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  undefined2 *puVar6;
  undefined4 *puVar7;
  byte bVar8;
  int iVar9;
  int local_20;
  int local_1c;
  int local_10;
  int local_c;
  
  _DAT_001eef88 = _DAT_001eef88 + 1;
  *(int *)(&DAT_001eef90 + param_2 * 4) = *(int *)(&DAT_001eef90 + param_2 * 4) + 1;
  local_c = 0;
  local_10 = 0;
  local_1c = 0;
  local_20 = *(int *)(param_1 + 0x2c) << ((byte)*(undefined2 *)(&DAT_001dc41c + param_2 * 2) & 0x1f)
  ;
  bVar2 = false;
LAB_0012ef3c:
  do {
    piVar3 = (int *)FUN_0012ea98(param_1,param_7);
    if (param_2 == 9) {
      _clntkudp_once(piVar3,1);
    }
LAB_0012ef60:
    do {
      bVar8 = 0;
      iVar4 = (**(code **)piVar3[1])
                        (piVar3,param_2,param_3,param_4,param_5,param_6,local_20 / 10,
                         (local_20 % 10) * 100000);
      switch(iVar4) {
      case 0:
      case 1:
      case 2:
      case 6:
      case 7:
      case 9:
      case 0xb:
        break;
      default:
        if (iVar4 == 0x12) {
          if ((*(byte *)(param_1 + 0x14) & 5) == 1) goto LAB_0012ef60;
          local_10 = 0x12;
          local_c = 4;
          bVar8 = 0;
        }
        else {
          bVar8 = *(byte *)(param_1 + 0x14) & 1;
        }
        if (bVar8 == 0) goto LAB_0012f0a2;
        iVar9 = local_20 * 4;
        local_20 = 300;
        if (iVar9 < 0x12d) {
          local_20 = iVar9;
        }
        if ((*(byte *)(param_1 + 0x14) & 2) == 0) {
          *(byte *)(param_1 + 0x14) = *(byte *)(param_1 + 0x14) | 2;
          _printf(s_NFS_server__s_not_responding_sti_001dc440,param_1 + 0x34);
        }
        if ((!bVar2) && (*(int *)(_active_u + 0x168) != 0)) {
          bVar2 = true;
          _uprintf(s_NFS_server__s_not_responding_sti_001dc46b,param_1 + 0x34);
        }
      }
    } while (bVar8 != 0);
LAB_0012f0a2:
    _clntkudp_once(piVar3,0);
    if (iVar4 != 0) {
      _DAT_001eef8c = _DAT_001eef8c + 1;
      *(byte *)(param_1 + 0x14) = *(byte *)(param_1 + 0x14) | 8;
      if (iVar4 != 0x12) {
        local_c = 0x16;
        iVar9 = iVar4;
        pcVar5 = _clnt_sperrno();
        _printf(s_NFS__s_failed_for_server__s___s_001dc496,(&_rfsnames)[param_2],param_1 + 0x34,
                pcVar5,iVar9);
        local_10 = iVar4;
        if (*(int *)(_active_u + 0x168) != 0) {
          pcVar5 = _clnt_sperrno();
          _uprintf(s_NFS__s_failed_for_server__s___s_001dc4b7,(&_rfsnames)[param_2],param_1 + 0x34,
                   pcVar5,iVar4);
        }
      }
      goto LAB_0012f295;
    }
    if ((((param_6 == (int *)0x0) || (*param_6 != 0xd)) || (local_1c != 0)) ||
       ((*(short *)(param_7 + 2) != 0 || (*(short *)(param_7 + 6) == 0)))) break;
    param_7 = _crdup(param_7);
    *(undefined2 *)(param_7 + 2) = *(undefined2 *)(param_7 + 6);
    piVar1 = (int *)*piVar3;
    if ((*piVar1 < 2) && (-1 < *piVar1)) {
      for (puVar6 = (undefined2 *)&_unixauthtab; puVar6 < &_unixauthtab + _MAXCLIENTS * 8;
          puVar6 = puVar6 + 4) {
        if (*(int **)(puVar6 + 2) == piVar1) {
          *puVar6 = 0;
          goto LAB_0012f1fc;
        }
      }
      (**(code **)(piVar1[8] + 0x10))(piVar1);
    }
    else {
      _printf(s_authfree__unknown_authflavor__d_001dc2ec,*piVar1);
    }
LAB_0012f1fc:
    _clntkudp_freecred(piVar3);
    *piVar3 = 0;
    for (puVar7 = &_chtable; local_1c = param_7, puVar7 < &_chtable + _MAXCLIENTS * 3;
        puVar7 = puVar7 + 3) {
      if ((int *)puVar7[2] == piVar3) {
        puVar7[1] = 0;
        goto LAB_0012ef3c;
      }
    }
    (**(code **)(piVar3[1] + 0x10))(piVar3);
  } while( true );
  bVar8 = *(byte *)(param_1 + 0x14);
  if ((bVar8 & 1) == 0) {
    *(byte *)(param_1 + 0x14) = bVar8 & 0xf7;
  }
  else {
    if ((bVar8 & 2) != 0) {
      _printf(s_NFS_server__s_ok_001dc4d8,param_1 + 0x34);
      *(byte *)(param_1 + 0x14) = *(byte *)(param_1 + 0x14) & 0xfd;
    }
    if (bVar2) {
      _uprintf(s_NFS_server__s_ok_001dc4ea,param_1 + 0x34);
    }
  }
LAB_0012f295:
  piVar1 = (int *)*piVar3;
  if ((*piVar1 < 2) && (-1 < *piVar1)) {
    for (puVar6 = (undefined2 *)&_unixauthtab; puVar6 < &_unixauthtab + _MAXCLIENTS * 8;
        puVar6 = puVar6 + 4) {
      if (*(int **)(puVar6 + 2) == piVar1) {
        *puVar6 = 0;
        goto LAB_0012f300;
      }
    }
    (**(code **)(piVar1[8] + 0x10))(piVar1);
  }
  else {
    _printf(s_authfree__unknown_authflavor__d_001dc2ec,*piVar1);
  }
LAB_0012f300:
  _clntkudp_freecred(piVar3);
  *piVar3 = 0;
  puVar7 = &_chtable;
  do {
    if (&_chtable + _MAXCLIENTS * 3 <= puVar7) {
      (**(code **)(piVar3[1] + 0x10))(piVar3);
LAB_0012f340:
      if (local_1c != 0) {
        _crfree(local_1c);
      }
      if ((local_10 != 0) && (local_c == 0)) {
        _printf(s_rfscall__re_status__d__re_errno_0_001dc4fc,local_10);
                    /* WARNING: Subroutine does not return */
        _panic(s_rfscall_001dc520);
      }
      return local_c;
    }
    if ((int *)puVar7[2] == piVar3) {
      puVar7[1] = 0;
      goto LAB_0012f340;
    }
    puVar7 = puVar7 + 3;
  } while( true );
}

