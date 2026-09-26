
void _revarpinput(int param_1,undefined4 *param_2)

{
  int iVar1;
  sword sVar2;
  int iVar3;
  undefined *puVar4;
  undefined4 *puVar5;
  undefined2 uStack_1a;
  undefined auStack_18 [6];
  undefined auStack_12 [6];
  undefined2 uStack_c;
  
  param_2[1] = param_2[1] + 4;
  sVar2 = *(sword *)(param_2 + 2);
  *(sword *)(param_2 + 2) = sVar2 + -4;
  puVar5 = param_2;
  if ((sword)(sVar2 + -4) == 0) {
    if (*(sword *)((int)param_2 + 10) == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(&aMfree);
    }
    (&word_40B61CC)[*(sword *)((int)param_2 + 10)] =
         (&word_40B61CC)[*(sword *)((int)param_2 + 10)] + -1;
    word_40B61CC = word_40B61CC + 1;
    *(undefined2 *)((int)param_2 + 10) = 0;
    if (0x7f < (uint)param_2[1]) {
      _mclput(param_2);
    }
    puVar5 = (undefined4 *)*param_2;
    *param_2 = _mfree;
    param_2[1] = 0;
    param_2[0x1f] = 0;
    _mfree = param_2;
    if (_m_want != 0) {
      _m_want = 0;
      _wakeup(&_mfree);
    }
  }
  iVar1 = puVar5[1];
  if ((((0x1b < *(word *)(puVar5 + 2)) && (-1 < *(char *)(param_1 + 0xd))) &&
      (*(sword *)((int)puVar5 + iVar1 + 2) == 0x800)) &&
     ((_revarp != 0 && (*(sword *)((int)puVar5 + iVar1 + 6) == 3)))) {
    puVar4 = _arptab;
    do {
      if (((*(byte *)((int)puVar4 + 0xb) & 4) != 0) &&
         (iVar3 = _bcmp((undefined4 *)((int)puVar4 + 4),(int)puVar5 + iVar1 + 0x12,6), iVar3 == 0))
      break;
      puVar4 = (undefined *)((int)puVar4 + 0x14);
    } while (puVar4 < &_in_ifaddr);
    if (puVar4 < &_in_ifaddr) {
      _bcopy((int)puVar5 + iVar1 + 8,auStack_18,6);
      _bcopy(puVar4,(int)puVar5 + iVar1 + 0x18,4);
      iVar3 = *(int *)(param_1 + 0x16);
      if (iVar3 != 0) {
        do {
          if (param_1 == *(int *)(iVar3 + 0x20)) {
            _bcopy(iVar3 + 4,(int)puVar5 + iVar1 + 0xe,4);
            break;
          }
          iVar3 = *(int *)(iVar3 + 0x24);
        } while (iVar3 != 0);
        if (iVar3 != 0) {
          _bcopy(param_1 + 0x5e,(int)puVar5 + iVar1 + 8,6);
          _bcopy(param_1 + 0x5e,auStack_12,6);
          uStack_c = 0x8035;
          *(undefined2 *)((int)puVar5 + iVar1 + 6) = 4;
          uStack_1a = 0;
          if (_revarpdebug != 0) {
            _printf(aRevarpReplyToX,*(undefined4 *)((int)puVar5 + iVar1 + 0x18),
                    *(undefined4 *)((int)puVar5 + iVar1 + 0xe));
          }
          (**(code **)(param_1 + 0x32))(param_1,puVar5,&uStack_1a);
          return;
        }
      }
      if (_revarpdebug != 0) {
        _printf(aRevarpCanTFind);
      }
    }
  }
  _m_freem(puVar5);
  return;
}
