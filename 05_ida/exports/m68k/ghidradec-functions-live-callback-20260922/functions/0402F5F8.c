
void _svc_getreq(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  bool bVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iStack_54;
  uint uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 *puStack_44;
  undefined4 uStack_40;
  undefined4 *puStack_3c;
  int iStack_38;
  undefined auStack_34 [12];
  int iStack_28;
  uint uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 *puStack_18;
  undefined4 uStack_14;
  undefined4 *puStack_c;
  
  if (_rqcred_head == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)_kalloc(0x4b0);
  }
  else {
    puVar4 = _rqcred_head;
    _rqcred_head = (undefined4 *)*_rqcred_head;
  }
  puStack_c = puVar4 + 100;
  puStack_3c = puVar4 + 200;
  puStack_18 = puVar4;
  do {
    iVar5 = (*(code *)**(undefined4 **)(param_1 + 6))(param_1,auStack_34);
    if (iVar5 != 0) {
      iStack_38 = param_1;
      iStack_54 = iStack_28;
      uStack_50 = uStack_24;
      uStack_4c = uStack_20;
      uStack_48 = uStack_1c;
      puStack_44 = puStack_18;
      uStack_40 = uStack_14;
      iVar5 = __authenticate(&iStack_54,auStack_34);
      if (iVar5 == 0) {
        bVar3 = false;
        uVar7 = 0xffffffff;
        uVar6 = 0;
        for (puVar1 = dword_40B3596; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
          if (iStack_54 == puVar1[1]) {
            uVar2 = puVar1[2];
            if (uStack_50 == uVar2) {
              (*(code *)puVar1[3])(&iStack_54,param_1);
              goto loc_402F72A;
            }
            bVar3 = true;
            if (uVar2 < uVar7) {
              uVar7 = uVar2;
            }
            if (uVar6 < uVar2) {
              uVar6 = uVar2;
            }
          }
        }
        if (bVar3) {
          _svcerr_progvers(param_1,uVar7,uVar6);
        }
        else {
          _svcerr_noprog(param_1);
        }
        (**(code **)(*(int *)(param_1 + 6) + 0x10))(param_1,0,0);
      }
      else {
        _svcerr_auth(param_1,iVar5);
      }
    }
loc_402F72A:
    iVar5 = (**(code **)(*(int *)(param_1 + 6) + 4))(param_1);
    if (iVar5 == 0) {
      (**(code **)(*(int *)(param_1 + 6) + 0x14))(param_1);
      goto loc_402F746;
    }
    if (iVar5 != 1) {
loc_402F746:
      *puVar4 = _rqcred_head;
      _rqcred_head = puVar4;
      return;
    }
  } while( true );
}

