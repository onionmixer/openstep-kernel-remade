/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011eb50 */

int _physio(void *param_1,buf_t param_2,dev_t param_3,int param_4,u_int *param_5,uio *param_6,
           int param_7)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_c;
  
  local_c = 0;
  do {
    if (*(int *)(param_6 + 4) == 0) {
      return 0;
    }
    puVar1 = *(undefined4 **)param_6;
    if ((*(int *)(param_6 + 0xc) != 1) &&
       (iVar2 = _useracc(*puVar1,puVar1[1],param_4 != 1), iVar2 == 0)) {
      return 0xe;
    }
    uVar3 = _splbio();
    while ((*(uint *)param_2 & 8) != 0) {
      *(uint *)param_2 = *(uint *)param_2 | 0x40;
      _sleep((uint)param_2);
    }
    _splx(uVar3);
    *(undefined2 *)(param_2 + 0x1c) = 0;
    *(int *)(param_2 + 0x2c) = *_active_u;
    *(undefined4 *)(param_2 + 0x20) = *puVar1;
    iVar2 = puVar1[1];
    while (0 < iVar2) {
      *(uint *)param_2 = param_4 | 0x18;
      *(undefined2 *)(param_2 + 0x1e) = (undefined2)param_3;
      *(uint *)(param_2 + 0x24) = *(uint *)(param_6 + 8) / (uint)param_7;
      *(undefined4 *)(param_2 + 0x14) = puVar1[1];
      (*(code *)param_5)(param_2);
      iVar2 = *(int *)(param_2 + 0x14);
      if (*(int *)(param_6 + 0xc) == 1) {
        *(uint *)param_2 = *(uint *)param_2 | 0x4000000;
      }
      else {
        *(uint *)(*_active_u + 0x28) = *(uint *)(*_active_u + 0x28) | 0x800;
        local_c = *(undefined4 *)(param_2 + 0x20);
        _vslock(local_c,iVar2);
      }
      _physstrat(param_2,param_1,0x14);
      if (*(int *)(param_6 + 0xc) != 1) {
        _vsunlock(local_c,iVar2,param_4);
        *(uint *)(*_active_u + 0x28) = *(uint *)(*_active_u + 0x28) & 0xfffff7ff;
      }
      _splbio();
      if (((byte)*param_2 & 0x40) != 0) {
        _wakeup(param_2);
      }
      _splx(uVar3);
      iVar2 = iVar2 - *(int *)(param_2 + 0x28);
      *(int *)(param_2 + 0x20) = *(int *)(param_2 + 0x20) + iVar2;
      puVar1[1] = puVar1[1] - iVar2;
      *(int *)(param_6 + 0x14) = *(int *)(param_6 + 0x14) - iVar2;
      *(int *)(param_6 + 8) = *(int *)(param_6 + 8) + iVar2;
      if ((*(int *)(param_2 + 0x28) != 0) || (((byte)*param_2 & 4) != 0)) break;
      iVar2 = puVar1[1];
    }
    *(uint *)param_2 = *(uint *)param_2 & 0xffffffa7;
    iVar2 = _geterror(param_2);
    if (*(int *)(param_2 + 0x28) != 0) {
      return iVar2;
    }
    if (iVar2 != 0) {
      return iVar2;
    }
    *(int *)param_6 = *(int *)param_6 + 8;
    *(int *)(param_6 + 4) = *(int *)(param_6 + 4) + -1;
  } while( true );
}

