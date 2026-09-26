/* GHIDRADEC_FUNCTION index=460 start=0x4016366 */

undefined4 _unp_connect2(sword *param_1,sword *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if (*param_1 == *param_2) {
    iVar2 = *(int *)(param_2 + 4);
    *(int *)(iVar1 + 0xc) = iVar2;
    if (*param_1 == 1) {
      *(int *)(iVar2 + 0xc) = iVar1;
      _soisconnected(param_2);
      _soisconnected(param_1);
    }
    else {
      if (*param_1 != 2) {
                    /* WARNING: Subroutine does not return */
        _panic(aUnpConnect2);
      }
      *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(iVar2 + 0x10);
      *(int *)(iVar2 + 0x10) = iVar1;
      _soisconnected(param_1);
    }
    uVar3 = 0;
  }
  else {
    uVar3 = 0x29;
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=461 start=0x40163dc */

void _unp_disconnect(int *param_1)

{
  undefined4 *puVar1;
  sword sVar2;
  int *piVar3;
  int *piVar4;
  
  puVar1 = (undefined4 *)param_1[3];
  if (puVar1 != (undefined4 *)0x0) {
    param_1[3] = 0;
    sVar2 = *(sword *)*param_1;
    if (sVar2 == 1) {
      _soisdisconnected((sword *)*param_1);
      puVar1[3] = 0;
      _soisdisconnected(*puVar1);
    }
    else if (sVar2 == 2) {
      piVar3 = (int *)puVar1[4];
      if (param_1 == (int *)puVar1[4]) {
        puVar1[4] = param_1[5];
      }
      else {
        do {
          piVar4 = piVar3;
          if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            _panic(aUnpDisconnect);
          }
          piVar3 = (int *)piVar4[5];
        } while (param_1 != (int *)piVar4[5]);
        piVar4[5] = param_1[5];
      }
      param_1[5] = 0;
      *(word *)(*param_1 + 6) = *(word *)(*param_1 + 6) & 0xfffd;
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=462 start=0x4016462 */

void _unp_usrclosed(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=463 start=0x401646a */

void _unp_drop(int *param_1,undefined2 param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *(undefined2 *)(iVar1 + 0x50) = param_2;
  _unp_disconnect(param_1);
  if (*(int *)(iVar1 + 0x10) != 0) {
    *(undefined4 *)(iVar1 + 8) = 0;
    _m_freem(param_1[6]);
    _kfree(param_1,0x24);
    _sofree(iVar1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=464 start=0x40164bc */

undefined4 _unp_externalize(int param_1)

{
  int iVar1;
  sword *psVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  
  uVar6 = (uint)(int)*(sword *)(param_1 + 8) >> 2;
  piVar7 = (int *)(*(int *)(param_1 + 4) + param_1);
  iVar3 = _ufavail();
  if (iVar3 < (int)uVar6) {
    iVar3 = 0;
    if (uVar6 != 0) {
      do {
        _unp_discard(*piVar7);
        *piVar7 = 0;
        iVar3 = iVar3 + 1;
        piVar7 = piVar7 + 1;
      } while (iVar3 < (int)uVar6);
    }
    uVar4 = 0x28;
  }
  else {
    iVar3 = 0;
    if (uVar6 != 0) {
      do {
        iVar5 = _ufalloc(0);
        if (iVar5 < 0) {
                    /* WARNING: Subroutine does not return */
          _panic(aUnpExternalize);
        }
        iVar1 = *piVar7;
        *(int *)(*(int *)(_active_u + 0x146) + iVar5 * 4) = iVar1;
        psVar2 = (sword *)(iVar1 + 0x10);
        *psVar2 = *psVar2 + -1;
        _unp_rights = _unp_rights + -1;
        *piVar7 = iVar5;
        iVar3 = iVar3 + 1;
        piVar7 = piVar7 + 1;
      } while (iVar3 < (int)uVar6);
    }
    uVar4 = 0;
  }
  return uVar4;
}

