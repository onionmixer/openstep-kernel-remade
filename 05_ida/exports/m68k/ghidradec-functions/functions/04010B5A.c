
int _ptcwrite(byte param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined *puVar7;
  int *piVar8;
  undefined auStack_68 [100];
  
  piVar2 = *(int **)((int)&dword_40B318A + (sword)(word)param_1 * 0xe);
  piVar8 = (int *)*param_2;
  puVar7 = (undefined *)0x0;
  iVar3 = 0;
  iVar6 = 0;
  iVar4 = *(int *)((int)&dword_40B318E + (sword)(word)param_1 * 0xe);
  do {
    if ((*(byte *)((int)piVar2 + 0x41) & 4) != 0) {
      if ((*(byte *)(iVar4 + 3) & 0x20) == 0) {
        iVar1 = param_2[1];
        do {
          if (iVar1 < 1) {
            return 0;
          }
          piVar8 = (int *)*param_2;
          if (iVar3 == 0) {
            iVar5 = piVar8[1];
            if (iVar5 != 0) {
              if (100 < iVar5) {
                iVar5 = 100;
              }
              puVar7 = auStack_68;
              iVar3 = _uiomove(puVar7,iVar5,1,param_2);
              if (iVar3 != 0) {
                return iVar3;
              }
              iVar3 = iVar5;
              if ((*(byte *)((int)piVar2 + 0x41) & 4) == 0) {
                return 5;
              }
              goto joined_r0x04010ca8;
            }
            param_2[1] = iVar1 + -1;
            *param_2 = *param_2 + 8;
          }
          else {
joined_r0x04010ca8:
            for (; 0 < iVar3; iVar3 = iVar3 + -1) {
              if ((0x3fd < piVar2[3] + *piVar2) &&
                 ((0 < piVar2[3] || ((*(uint *)((int)piVar2 + 0x3a) & 0x22) != 0)))) {
                _wakeup(piVar2);
                goto loc_4010D0E;
              }
              (**(code **)(DAT_40ae4c0 + *(char *)((int)piVar2 + 0x45) * 0x30))(*puVar7,piVar2);
              iVar6 = iVar6 + 1;
              puVar7 = puVar7 + 1;
            }
            iVar3 = 0;
          }
          iVar1 = param_2[1];
        } while( true );
      }
      if (piVar2[3] == 0) break;
    }
loc_4010D0E:
    if ((*(byte *)((int)piVar2 + 0x41) & 0x10) == 0) {
      return 5;
    }
    if ((*(byte *)(iVar4 + 3) & 4) != 0) {
      *piVar8 = *piVar8 - iVar3;
      piVar8[1] = iVar3 + piVar8[1];
      *(int *)((int)param_2 + 0x12) = iVar3 + *(int *)((int)param_2 + 0x12);
      param_2[2] = param_2[2] - iVar3;
      if (iVar6 != 0) {
        return 0;
      }
      if ((*(byte *)(*_active_u + 0x16) & 0x40) != 0) {
        return 0xb;
      }
      return 0x23;
    }
    _sleep(piVar2 + 1,0x1d);
  } while( true );
loc_4010C20:
  while( true ) {
    if ((param_2[1] < 1) || (0x3fe < piVar2[3])) {
      _putc(0,piVar2 + 3);
      _ttwakeup(piVar2);
      _wakeup(piVar2 + 3);
      return 0;
    }
    iVar4 = *(int *)(*param_2 + 4);
    if (iVar4 != 0) break;
    param_2[1] = param_2[1] + -1;
    *param_2 = *param_2 + 8;
  }
  if (iVar3 == 0) {
    if (100 < iVar4) {
      iVar4 = 100;
    }
    iVar6 = 0x3ff - piVar2[3];
    iVar3 = iVar4;
    if (iVar6 < iVar4) {
      iVar3 = iVar6;
    }
    puVar7 = auStack_68;
    iVar4 = _uiomove(puVar7,iVar3,1,param_2);
    if (iVar4 != 0) {
      return iVar4;
    }
    if ((*(byte *)((int)piVar2 + 0x41) & 4) == 0) {
      return 5;
    }
    if (iVar3 != 0) goto loc_4010C0C;
  }
  else {
loc_4010C0C:
    _b_to_q(puVar7,iVar3,piVar2 + 3);
  }
  iVar3 = 0;
  goto loc_4010C20;
}
