
int * sub_4028828(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined *puVar4;
  int *piVar5;
  
  if ((*(byte *)(param_1 + 0x14) & 0x90) == 0x10) {
    uVar2 = 1;
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 0x2e);
  }
  dword_40BBF18 = dword_40BBF18 + 1;
  piVar5 = &_chtable;
  if (&_chtable < &_chtable + _MAXCLIENTS * 3) {
    puVar4 = unk_40BBED4;
    piVar3 = &unk_40BBED0;
    do {
      if (*piVar3 == 0) {
        *piVar3 = 1;
        if (*(int *)puVar4 == 0) {
          iVar1 = _clntkudp_create(param_1,0x186a3,2,uVar2,param_2);
          *(int *)puVar4 = iVar1;
          if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
            _panic(aClgetNullClien);
          }
          (**(code **)(*(int *)(**(int **)puVar4 + 0x20) + 0x10))(**(int **)puVar4);
        }
        else {
          _clntkudp_init(*(int *)puVar4,param_1,uVar2,param_2);
        }
        uVar2 = sub_402872E(param_1,param_2);
        **(undefined4 **)puVar4 = uVar2;
        if (**(int **)puVar4 != 0) {
          *piVar5 = *piVar5 + 1;
          if ((*(byte *)(param_1 + 0x14) & 0xa0) == 0xa0) {
            _clntkudp_interruptable(*(int *)puVar4,1);
          }
          return *(int **)puVar4;
        }
                    /* WARNING: Subroutine does not return */
        _panic(aClgetNullAuth);
      }
      puVar4 = (undefined *)((int)puVar4 + 0xc);
      piVar3 = piVar3 + 3;
      piVar5 = piVar5 + 3;
    } while (piVar5 < &_chtable + _MAXCLIENTS * 3);
  }
  _cltoomany = _cltoomany + 1;
  piVar5 = (int *)_clntkudp_create(param_1,0x186a3,2,uVar2,param_2);
  if (piVar5 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    _panic(aClgetNullClien);
  }
  (**(code **)(*(int *)(*piVar5 + 0x20) + 0x10))(*piVar5);
  iVar1 = sub_402872E(param_1,param_2);
  *piVar5 = iVar1;
  if (iVar1 != 0) {
    if ((*(byte *)(param_1 + 0x14) & 0xa0) == 0xa0) {
      _clntkudp_interruptable(piVar5,1);
    }
    return piVar5;
  }
                    /* WARNING: Subroutine does not return */
  _panic(aClgetNullAuth);
}

