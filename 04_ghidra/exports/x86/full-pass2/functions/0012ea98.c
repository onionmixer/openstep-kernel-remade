/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012ea98 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_0012ea98(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  undefined4 uVar5;
  int *local_10;
  int *local_8;
  
  if ((*(byte *)(param_1 + 0x14) & 9) == 8) {
    uVar5 = 1;
  }
  else {
    uVar5 = *(undefined4 *)(param_1 + 0x30);
  }
  _DAT_001eef84 = _DAT_001eef84 + 1;
  local_8 = &_chtable;
  if (&_chtable + _MAXCLIENTS * 3 < (undefined4 *)0x1eef31) {
LAB_0012ec68:
    __cltoomany = __cltoomany + 1;
    piVar3 = (int *)_clntkudp_create(param_1,0x186a3,2,uVar5,param_2);
    if (piVar3 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_clget__null_client_001dc331);
    }
    (**(code **)(*(int *)(*piVar3 + 0x20) + 0x10))(*piVar3);
    iVar2 = *(int *)(param_1 + 0x5c);
    while ((1 < iVar2 || (uVar4 = _MAXCLIENTS, iVar2 < 0))) {
      _printf(s_authget__unknown_authflavor__d_001dc2cc,iVar2);
      iVar2 = 0;
    }
    do {
      uVar1 = _nextunixvictim;
      iVar2 = _nextunixvictim * 8;
      _nextunixvictim = _nextunixvictim + 1;
      _nextunixvictim = _nextunixvictim % _MAXCLIENTS;
      if (*(short *)(&_unixauthtab + iVar2) == 0) {
        if ((&DAT_001ef144)[uVar1 * 2] == 0) {
          uVar5 = _authkern_create();
          (&DAT_001ef144)[uVar1 * 2] = uVar5;
        }
        *(undefined2 *)(&_unixauthtab + iVar2) = 1;
        iVar2 = (&DAT_001ef144)[uVar1 * 2];
        goto LAB_0012ed40;
      }
      uVar4 = uVar4 - 1;
    } while (0 < (int)uVar4);
    iVar2 = _authkern_create();
LAB_0012ed40:
    *piVar3 = iVar2;
    if (iVar2 != 0) {
      if ((*(byte *)(param_1 + 0x14) & 5) == 5) {
        _clntkudp_interruptable(piVar3,1);
      }
      return piVar3;
    }
                    /* WARNING: Subroutine does not return */
    _panic(s_clget__null_auth_001dc344);
  }
  local_10 = &DAT_001eef38;
  while (local_10[-1] != 0) {
    local_10 = local_10 + 3;
    local_8 = local_8 + 3;
    if (&_chtable + _MAXCLIENTS * 3 <= local_8) goto LAB_0012ec68;
  }
  local_10[-1] = 1;
  if (*local_10 == 0) {
    iVar2 = _clntkudp_create(param_1,0x186a3,2,uVar5,param_2);
    *local_10 = iVar2;
    if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_clget__null_client_001dc30d);
    }
    (**(code **)(*(int *)(*(int *)*local_10 + 0x20) + 0x10))(*(int *)*local_10);
  }
  else {
    _clntkudp_init(*local_10,param_1,uVar5,param_2);
  }
  iVar2 = *(int *)(param_1 + 0x5c);
  while ((1 < iVar2 || (uVar4 = _MAXCLIENTS, iVar2 < 0))) {
    _printf(s_authget__unknown_authflavor__d_001dc2cc,iVar2);
    iVar2 = 0;
  }
  do {
    uVar1 = _nextunixvictim;
    iVar2 = _nextunixvictim * 8;
    _nextunixvictim = _nextunixvictim + 1;
    _nextunixvictim = _nextunixvictim % _MAXCLIENTS;
    if (*(short *)(&_unixauthtab + iVar2) == 0) {
      if ((&DAT_001ef144)[uVar1 * 2] == 0) {
        uVar5 = _authkern_create();
        (&DAT_001ef144)[uVar1 * 2] = uVar5;
      }
      *(undefined2 *)(&_unixauthtab + iVar2) = 1;
      uVar5 = (&DAT_001ef144)[uVar1 * 2];
      goto LAB_0012ec04;
    }
    uVar4 = uVar4 - 1;
  } while (0 < (int)uVar4);
  uVar5 = _authkern_create();
LAB_0012ec04:
  *(undefined4 *)*local_10 = uVar5;
  if (*(int *)*local_10 != 0) {
    *local_8 = *local_8 + 1;
    if ((*(byte *)(param_1 + 0x14) & 5) == 5) {
      _clntkudp_interruptable(*local_10,1);
    }
    return (int *)*local_10;
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_clget__null_auth_001dc320);
}

