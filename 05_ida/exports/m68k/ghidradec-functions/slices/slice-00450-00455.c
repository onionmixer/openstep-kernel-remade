/* GHIDRADEC_FUNCTION index=450 start=0x40157e4 */

void _pipe(void)

{
  int iVar1;
  undefined uVar4;
  int iVar2;
  int iVar3;
  char cVar5;
  int iStack_c;
  int iStack_8;
  
  uVar4 = _socreate(1,&iStack_8,1,0);
  *(undefined *)(dword_40B57D4 + 100) = uVar4;
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    uVar4 = _socreate(1,&iStack_c,1,0);
    *(undefined *)(dword_40B57D4 + 100) = uVar4;
    if (*(char *)(dword_40B57D4 + 100) == '\0') {
      iVar2 = _falloc();
      if (iVar2 != 0) {
        iVar1 = *(int *)(dword_40B57D4 + 0x5c);
        *(undefined4 *)(iVar2 + 8) = 1;
        if ((*(byte *)(*_active_u + 0x16) & 0x40) != 0) {
          *(undefined4 *)(iVar2 + 8) = 0x2001;
        }
        *(undefined2 *)(iVar2 + 0xc) = 2;
        *(undefined **)(iVar2 + 0x12) = _socketops;
        *(int *)(iVar2 + 0x16) = iStack_8;
        *(int *)(*(int *)((int)_active_u + 0x146) + *(int *)(dword_40B57D4 + 0x5c) * 4) = iVar2;
        iVar3 = _falloc();
        if (iVar3 != 0) {
          *(undefined4 *)(iVar3 + 8) = 2;
          if ((*(byte *)(*_active_u + 0x16) & 0x40) != 0) {
            *(undefined4 *)(iVar3 + 8) = 0x2002;
          }
          *(undefined2 *)(iVar3 + 0xc) = 2;
          *(undefined **)(iVar3 + 0x12) = _socketops;
          *(int *)(iVar3 + 0x16) = iStack_c;
          *(int *)(*(int *)((int)_active_u + 0x146) + *(int *)(dword_40B57D4 + 0x5c) * 4) = iVar3;
          *(undefined4 *)(dword_40B57D4 + 0x60) = *(undefined4 *)(dword_40B57D4 + 0x5c);
          *(int *)(dword_40B57D4 + 0x5c) = iVar1;
          cVar5 = _unp_connect2(iStack_c,iStack_8);
          *(char *)(dword_40B57D4 + 100) = cVar5;
          if (cVar5 == '\0') {
            *(word *)(iStack_c + 6) = *(word *)(iStack_c + 6) | 0x20;
            *(word *)(iStack_8 + 6) = *(word *)(iStack_8 + 6) | 0x10;
            return;
          }
          *(undefined2 *)(iVar3 + 0xe) = 0;
          *(undefined4 *)(*(int *)((int)_active_u + 0x146) + *(int *)(dword_40B57D4 + 0x60) * 4) = 0
          ;
        }
        *(undefined2 *)(iVar2 + 0xe) = 0;
        *(undefined4 *)(*(int *)((int)_active_u + 0x146) + iVar1 * 4) = 0;
      }
      _soclose(iStack_c);
    }
    _soclose(iStack_8);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=451 start=0x4015998 */

void _getsockname(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined uVar4;
  int iVar3;
  int iStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  iVar2 = _getsock(*puVar1);
  if (iVar2 != 0) {
    uVar4 = _copyinmsg(puVar1[2],&iStack_8,4);
    *(undefined *)(dword_40B57D4 + 100) = uVar4;
    if (*(char *)(dword_40B57D4 + 100) == '\0') {
      iVar2 = *(int *)(iVar2 + 0x16);
      iVar3 = _m_getclr(1,8);
      if (iVar3 == 0) {
        *(undefined *)(dword_40B57D4 + 100) = 0x37;
      }
      else {
        uVar4 = (**(code **)(*(int *)(iVar2 + 0xc) + 0x1a))(iVar2,0xf,0,iVar3,0);
        *(undefined *)(dword_40B57D4 + 100) = uVar4;
        if (*(char *)(dword_40B57D4 + 100) == '\0') {
          if (*(sword *)(iVar3 + 8) < iStack_8) {
            iStack_8 = (int)*(sword *)(iVar3 + 8);
          }
          uVar4 = _copyoutmsg(*(int *)(iVar3 + 4) + iVar3,puVar1[1],iStack_8);
          *(undefined *)(dword_40B57D4 + 100) = uVar4;
          if (*(char *)(dword_40B57D4 + 100) == '\0') {
            uVar4 = _copyoutmsg(&iStack_8,puVar1[2],4);
            *(undefined *)(dword_40B57D4 + 100) = uVar4;
          }
        }
        _m_freem(iVar3);
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=452 start=0x4015ab2 */

void _getpeername(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined uVar4;
  int iStack_8;
  
  puVar1 = *(undefined4 **)(dword_40B57D4 + 0x24);
  iVar2 = _getsock(*puVar1);
  if (iVar2 != 0) {
    iVar2 = *(int *)(iVar2 + 0x16);
    if ((*(byte *)(iVar2 + 7) & 2) == 0) {
      *(undefined *)(dword_40B57D4 + 100) = 0x39;
    }
    else {
      iVar3 = _m_getclr(1,8);
      if (iVar3 == 0) {
        *(undefined *)(dword_40B57D4 + 100) = 0x37;
      }
      else {
        uVar4 = _copyinmsg(puVar1[2],&iStack_8,4);
        *(undefined *)(dword_40B57D4 + 100) = uVar4;
        if (*(char *)(dword_40B57D4 + 100) == '\0') {
          uVar4 = (**(code **)(*(int *)(iVar2 + 0xc) + 0x1a))(iVar2,0x10,0,iVar3,0);
          *(undefined *)(dword_40B57D4 + 100) = uVar4;
          if (*(char *)(dword_40B57D4 + 100) == '\0') {
            if (*(sword *)(iVar3 + 8) < iStack_8) {
              iStack_8 = (int)*(sword *)(iVar3 + 8);
            }
            uVar4 = _copyoutmsg(*(int *)(iVar3 + 4) + iVar3,puVar1[1],iStack_8);
            *(undefined *)(dword_40B57D4 + 100) = uVar4;
            if (*(char *)(dword_40B57D4 + 100) == '\0') {
              uVar4 = _copyoutmsg(&iStack_8,puVar1[2],4);
              *(undefined *)(dword_40B57D4 + 100) = uVar4;
            }
          }
          _m_freem(iVar3);
        }
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=453 start=0x4015be4 */

int _sockargs(int *param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  if (param_3 < 0x71) {
    iVar2 = _m_get(1,param_4);
    if (iVar2 == 0) {
      iVar1 = 0x37;
    }
    else {
      *(sword *)(iVar2 + 8) = (sword)param_3;
      iVar1 = _copyinmsg(param_2,*(int *)(iVar2 + 4) + iVar2,param_3);
      if (iVar1 == 0) {
        *param_1 = iVar2;
      }
      else {
        _m_free(iVar2);
      }
    }
  }
  else {
    iVar1 = 0x16;
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=454 start=0x4015c50 */

int _getsock(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = _getf(param_1);
  if (iVar1 != 0) {
    if (*(sword *)(iVar1 + 0xc) == 2) {
      return iVar1;
    }
    *(undefined *)(dword_40B57D4 + 100) = 0x26;
  }
  return 0;
}

