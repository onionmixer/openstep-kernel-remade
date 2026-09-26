
undefined4 _vno_bsd_lock(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uStack_8;
  
  if ((((*(uint *)(param_1 + 8) & 0x100) == 0) || ((param_2 & 2) == 0)) &&
     ((-1 < (char)*(uint *)(param_1 + 8) || ((param_2 & 1) == 0)))) {
    uStack_8 = 0x23;
    iVar1 = *(int *)(param_1 + 0x16);
    if ((param_2 & 2) == 0) {
      uStack_8 = 0x24;
    }
    iVar2 = _setjmp(dword_40B57D4 + 0x28);
    if (iVar2 == 0) {
      do {
        while ((*(byte *)(iVar1 + 5) & 4) == 0) {
          if (((param_2 & 2) == 0) || ((*(word *)(iVar1 + 4) & 8) == 0)) {
            if ((*(byte *)(param_1 + 10) & 1) != 0) {
                    /* WARNING: Subroutine does not return */
              _panic(aVnoBsdLock);
            }
            if ((param_2 & 2) != 0) {
              *(sword *)(iVar1 + 10) = *(sword *)(iVar1 + 10) + 1;
              *(word *)(iVar1 + 4) = *(word *)(iVar1 + 4) | 4;
              *(word *)(param_1 + 10) = *(word *)(param_1 + 10) | 0x100;
            }
            if ((param_2 & 1) == 0) {
              return 0;
            }
            if (*(char *)(param_1 + 0xb) < '\0') {
              return 0;
            }
            *(sword *)(iVar1 + 8) = *(sword *)(iVar1 + 8) + 1;
            *(word *)(iVar1 + 4) = *(word *)(iVar1 + 4) | 8;
            *(word *)(param_1 + 10) = *(word *)(param_1 + 10) | 0x80;
            return 0;
          }
          if (*(char *)(param_1 + 0xb) < '\0') {
            _vno_bsd_unlock(param_1,0x80);
          }
          else {
            if ((param_2 & 4) != 0) {
              return 0x23;
            }
            *(word *)(iVar1 + 4) = *(word *)(iVar1 + 4) | 0x10;
            iVar2 = iVar1 + 8;
            uVar3 = 0x23;
loc_4019246:
            _sleep(iVar2,uVar3);
          }
        }
        if ((*(byte *)(param_1 + 10) & 1) == 0) {
          if ((param_2 & 4) != 0) {
            return 0x23;
          }
          *(word *)(iVar1 + 4) = *(word *)(iVar1 + 4) | 0x10;
          iVar2 = iVar1 + 10;
          uVar3 = uStack_8;
          goto loc_4019246;
        }
        _vno_bsd_unlock(param_1,0x100);
      } while( true );
    }
    if (*(int *)((int)_active_u + 0x136) << 0x20 - *(char *)(*_active_u + 0x17) < 0) {
      return 4;
    }
    *(undefined *)(dword_40B57D4 + 0x65) = 2;
  }
  return 0;
}

