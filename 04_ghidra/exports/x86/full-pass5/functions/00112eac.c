/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00112eac */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _q_to_b(size_t *param_1,void *param_2,size_t param_3)

{
  size_t sVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  size_t sVar7;
  
  pvVar3 = param_2;
  if ((int)param_3 < 1) {
    iVar4 = 0;
  }
  else {
    uVar5 = _spltty();
    if ((int)*param_1 < 1) {
      *param_1 = 0;
      param_1[2] = 0;
      param_1[1] = 0;
      _splx(uVar5);
      iVar4 = 0;
    }
    else {
      do {
        sVar7 = 0x40 - ((uint)param_1[1] & 0x3f);
        if ((int)param_3 < (int)sVar7) {
          sVar7 = param_3;
        }
        if ((int)*param_1 < (int)sVar7) {
          sVar7 = *param_1;
        }
        _bcopy((void *)param_1[1],param_2,sVar7);
        param_1[1] = param_1[1] + sVar7;
        sVar1 = *param_1;
        *param_1 = sVar1 - sVar7;
        param_3 = param_3 - sVar7;
        param_2 = (void *)((int)param_2 + sVar7);
        if ((int)(sVar1 - sVar7) < 1) {
          puVar6 = (undefined4 *)(param_1[1] - 1 & 0xffffffc0);
          param_1[2] = 0;
          param_1[1] = 0;
          *puVar6 = _cfreelist;
          __cfreecount = __cfreecount + 0x34;
          _cfreelist = puVar6;
          if (_cwaiting != '\0') {
            _wakeup(&_cwaiting);
            _cwaiting = '\0';
          }
          break;
        }
        uVar2 = param_1[1];
        if ((uVar2 & 0x3f) == 0) {
          param_1[1] = *(int *)(uVar2 - 0x40) + 0xc;
          *(undefined4 **)(uVar2 - 0x40) = _cfreelist;
          _cfreelist = (undefined4 *)(uVar2 - 0x40);
          __cfreecount = __cfreecount + 0x34;
          if (_cwaiting != '\0') {
            _wakeup(&_cwaiting);
            _cwaiting = '\0';
          }
        }
      } while (param_3 != 0);
      _splx(uVar5);
      iVar4 = (int)param_2 - (int)pvVar3;
    }
  }
  return iVar4;
}

