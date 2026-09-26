
int _ptcread(byte param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined uStack_82;
  undefined uStack_81;
  undefined uStack_80;
  undefined uStack_7f;
  undefined2 uStack_7e;
  undefined auStack_7c [6];
  undefined auStack_76 [6];
  undefined4 uStack_70;
  uint uStack_6c;
  undefined auStack_68 [100];
  
  iVar2 = *(int *)((int)&dword_40B318A + (sword)(word)param_1 * 0xe);
  iVar3 = *(int *)((int)&dword_40B318E + (sword)(word)param_1 * 0xe);
  iVar4 = 0;
  do {
    if ((*(byte *)(iVar2 + 0x41) & 4) != 0) {
      if (((*(byte *)(iVar3 + 3) & 8) != 0) && (*(char *)(iVar3 + 0xc) != '\0')) {
        iVar4 = _ureadc(*(char *)(iVar3 + 0xc),param_2);
        if (iVar4 != 0) {
          return iVar4;
        }
        if ((*(byte *)(iVar3 + 0xc) & 0x40) != 0) {
          uStack_82 = *(undefined *)(iVar2 + 0x47);
          uStack_81 = *(undefined *)(iVar2 + 0x48);
          uStack_80 = *(undefined *)(iVar2 + 0x4c);
          uStack_7f = *(undefined *)(iVar2 + 0x4d);
          uStack_7e = *(undefined2 *)(iVar2 + 0x3c);
          _bcopy(iVar2 + 0x4e,auStack_7c,6);
          _bcopy(iVar2 + 0x54,auStack_76,6);
          uStack_70 = *(undefined4 *)(iVar2 + 0x3e);
          uStack_6c = (uint)*(word *)(iVar2 + 0x3a);
          uVar1 = 0x1a;
          if (*(uint *)(param_2 + 0x12) < 0x1a) {
            uVar1 = *(uint *)(param_2 + 0x12);
          }
          _uiomove(&uStack_82,uVar1,0,param_2);
        }
        *(undefined *)(iVar3 + 0xc) = 0;
        return 0;
      }
      if ((*(char *)(iVar3 + 3) < '\0') && (*(char *)(iVar3 + 0xd) != '\0')) {
        iVar2 = _ureadc(*(char *)(iVar3 + 0xd),param_2);
        if (iVar2 != 0) {
          return iVar2;
        }
        *(undefined *)(iVar3 + 0xd) = 0;
        return 0;
      }
      if ((*(int *)(iVar2 + 0x18) != 0) && ((*(byte *)(iVar2 + 0x40) & 1) == 0)) {
        if ((*(byte *)(iVar3 + 3) & 0x88) != 0) {
          iVar4 = _ureadc(0,param_2);
        }
        iVar3 = *(int *)(param_2 + 0x12);
        if ((iVar3 < 1) || (iVar4 != 0)) goto loc_4010988;
        break;
      }
    }
    if ((*(byte *)(iVar2 + 0x41) & 0x10) == 0) {
      return 5;
    }
    if ((*(byte *)(iVar3 + 3) & 4) != 0) {
      iVar2 = 0x23;
      if ((*(byte *)(*_active_u + 0x16) & 0x40) != 0) {
        iVar2 = 0xb;
      }
      return iVar2;
    }
    _sleep(iVar2 + 0x1c,0x1c);
  } while( true );
loc_401094C:
  if (100 < iVar3) {
    iVar3 = 100;
  }
  iVar3 = _q_to_b(iVar2 + 0x18,auStack_68,iVar3);
  if (iVar3 < 1) {
loc_4010988:
    if ((int)*(sword *)(_ttlowat + (*(byte *)(iVar2 + 0x48) & 0x1f) * 2) < *(int *)(iVar2 + 0x18)) {
      return iVar4;
    }
    if ((*(uint *)(iVar2 + 0x3e) & 0x40) != 0) {
      *(uint *)(iVar2 + 0x3e) = *(uint *)(iVar2 + 0x3e) & 0xffffffbf;
      _wakeup(iVar2 + 0x18);
    }
    if (*(int *)(iVar2 + 0x2c) == 0) {
      return iVar4;
    }
    _selwakeup(*(int *)(iVar2 + 0x2c),*(uint *)(iVar2 + 0x3e) & 0x1000);
    _thread_deallocate(*(undefined4 *)(iVar2 + 0x2c));
    *(undefined4 *)(iVar2 + 0x2c) = 0;
    *(word *)(iVar2 + 0x40) = *(word *)(iVar2 + 0x40) & 0xefff;
    return iVar4;
  }
  iVar4 = _uiomove(auStack_68,iVar3,0,param_2);
  iVar3 = *(int *)(param_2 + 0x12);
  if ((iVar3 < 1) || (iVar4 != 0)) goto loc_4010988;
  goto loc_401094C;
}

