/* GHIDRADEC_FUNCTION index=575 start=0x401af50 */

void _forceclose(sword param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = _file_list;
  if ((undefined4 **)_file_list != &_file_list) {
    do {
      if ((((*(sword *)((int)puVar2 + 0xe) != 0) && (*(sword *)(puVar2 + 3) == 1)) &&
          (iVar1 = *(int *)((int)puVar2 + 0x16), iVar1 != 0)) &&
         (((*(int *)(iVar1 + 0x28) == 4 || (*(int *)(iVar1 + 0x28) == 9)) &&
          (param_1 == *(sword *)(iVar1 + 0x2c))))) {
        puVar2[2] = puVar2[2] & 0xfffffffc;
      }
      puVar2 = (undefined4 *)*puVar2;
    } while ((undefined4 **)puVar2 != &_file_list);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=576 start=0x401afae */

undefined4 _getvnodefp(undefined4 param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _getf(param_1);
  if (iVar1 == 0) {
    uVar2 = 9;
  }
  else if (*(sword *)(iVar1 + 0xc) == 1) {
    *param_2 = iVar1;
    uVar2 = 0;
  }
  else {
    uVar2 = 0x16;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=577 start=0x401afe4 */

int _vn_rdwr(int param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,int *param_8)

{
  int iVar1;
  undefined4 uStack_22;
  int iStack_1e;
  undefined4 *puStack_1a;
  undefined4 uStack_16;
  undefined4 uStack_12;
  undefined4 uStack_e;
  int iStack_8;
  
  if ((param_1 == 1) && ((*(byte *)(*(int *)(param_2 + 0x24) + 0xf) & 1) != 0)) {
    iVar1 = 0x1e;
  }
  else {
    uStack_22 = param_3;
    iStack_1e = param_4;
    puStack_1a = &uStack_22;
    uStack_16 = 1;
    uStack_12 = param_5;
    uStack_e = param_6;
    iStack_8 = param_4;
    if ((*(int *)(param_2 + 0x28) == 1) && ((*(byte *)(*_active_u + 0x16) & 0x40) == 0)) {
      _map_vnode(param_2);
      iVar1 = _mfs_io(param_2,&puStack_1a,param_1,param_7,*(undefined4 *)((int)_active_u + 0x1a));
      _unmap_vnode(param_2);
    }
    else {
      iVar1 = (**(code **)(*(int *)(param_2 + 0x1c) + 8))
                        (param_2,&puStack_1a,param_1,param_7,*(undefined4 *)((int)_active_u + 0x1a))
      ;
    }
    if (param_8 == (int *)0x0) {
      if ((iStack_8 != 0) && (iVar1 == 0)) {
        iVar1 = 5;
      }
    }
    else {
      *param_8 = iStack_8;
    }
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=578 start=0x401b0c6 */

void _vn_rele(int param_1)

{
  sword sVar1;
  
  if (*(sword *)(param_1 + 6) == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(&aVnRele);
  }
  sVar1 = *(sword *)(param_1 + 6);
  *(sword *)(param_1 + 6) = sVar1 + -1;
  if (sVar1 == 1) {
    (**(code **)(*(int *)(param_1 + 0x1c) + 0x4c))(param_1,*(undefined4 *)(_active_u + 0x1a));
  }
  return;
}
/* GHIDRADEC_FUNCTION index=579 start=0x401b114 */

/* WARNING: Type propagation algorithm not settling */

int _vn_open(undefined4 param_1,undefined4 param_2,uint param_3,undefined2 param_4,int *param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined auStack_7c [20];
  undefined4 uStack_68;
  int aiStack_42 [2];
  undefined2 uStack_3a;
  undefined4 uStack_2a;
  
  uVar3 = 0;
  if ((param_3 & 1) != 0) {
    uVar3 = 0x100;
  }
  if ((param_3 & 0x402) != 0) {
    uVar3 = uVar3 | 0x80;
  }
  if ((param_3 & 0x200) == 0) {
    iVar2 = _lookupname(param_1,param_2,1,0,aiStack_42);
    if (iVar2 != 0) {
      return iVar2;
    }
    if ((param_3 & 0x402) != 0) {
      if (*(int *)(aiStack_42[0] + 0x28) == 2) {
        iVar2 = 0x15;
        goto loc_401B306;
      }
      if (((*(byte *)(*(int *)(aiStack_42[0] + 0x24) + 0xf) & 1) != 0) &&
         (1 < *(int *)(aiStack_42[0] + 0x28) - 3U)) {
        iVar2 = 0x1e;
        goto loc_401B306;
      }
      if (((*(byte *)(aiStack_42[0] + 5) & 2) != 0) &&
         (_vnode_uncache(aiStack_42[0]), (*(byte *)(aiStack_42[0] + 5) & 2) != 0)) {
        iVar2 = 0x1a;
        goto loc_401B306;
      }
    }
    iVar2 = (**(code **)(*(int *)(aiStack_42[0] + 0x1c) + 0x1c))
                      (aiStack_42[0],uVar3,*(undefined4 *)(_active_u + 0x1a));
    if (iVar2 != 0) goto loc_401B306;
    if (((*(byte *)(*(int *)(aiStack_42[0] + 0x24) + 0xf) & 8) != 0) &&
       (*(int *)(aiStack_42[0] + 0x28) - 3U < 2)) {
      iVar2 = 1;
      goto loc_401B306;
    }
  }
  else {
    _vattr_null(aiStack_42 + 1);
    aiStack_42[1] = 1;
    uStack_3a = param_4;
    if ((param_3 & 0x400) != 0) {
      uStack_2a = 0;
    }
    uVar1 = param_3 & 0x800;
    param_3 = param_3 & 0xfffff1ff;
    iVar2 = _vn_create(param_1,param_2,aiStack_42 + 1,uVar1 != 0,uVar3,aiStack_42);
    if (iVar2 != 0) {
      return iVar2;
    }
  }
  if (*(int *)(aiStack_42[0] + 0x28) == 6) {
    iVar2 = 0x2d;
  }
  else {
    iVar2 = (*(code *)**(undefined4 **)(aiStack_42[0] + 0x1c))
                      (aiStack_42,param_3,*(undefined4 *)(_active_u + 0x1a));
    if (iVar2 == 0) {
      if ((param_3 & 0x400) != 0) {
        param_3 = param_3 & 0xfffffbff;
        _vattr_null(auStack_7c);
        uStack_68 = 0;
        iVar2 = (**(code **)(*(int *)(aiStack_42[0] + 0x1c) + 0x18))
                          (aiStack_42[0],auStack_7c,*(undefined4 *)(_active_u + 0x1a));
      }
      if (iVar2 == 0) {
        if (((param_3 & 0x40000000) == 0) && (*(int *)(aiStack_42[0] + 0x28) == 1)) {
          _map_vnode(aiStack_42[0]);
        }
        *param_5 = aiStack_42[0];
        return 0;
      }
    }
  }
loc_401B306:
  _vn_rele(aiStack_42[0]);
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=580 start=0x401b322 */

int _vn_create(undefined4 param_1,undefined4 param_2,int *param_3,int param_4,undefined4 param_5,
              int *param_6)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iStack_14;
  undefined auStack_10 [4];
  undefined4 uStack_c;
  
  iStack_14 = 0;
  *param_6 = 0;
  iVar2 = _pn_get(param_1,param_2,auStack_10);
  if (iVar2 != 0) {
    return iVar2;
  }
  if ((param_4 == 1) && (*param_3 != 2)) {
    uVar3 = 0;
    piVar4 = (int *)0x0;
  }
  else {
    uVar3 = 1;
    piVar4 = param_6;
  }
  iVar2 = _lookuppn(auStack_10,uVar3,&iStack_14,piVar4);
  if (iVar2 != 0) {
    _pn_free(auStack_10);
    return iVar2;
  }
  if ((*param_6 != 0) && (*(int *)(*param_6 + 0x28) == 6)) {
    return 0x2d;
  }
  if ((*(byte *)(*(int *)(iStack_14 + 0x24) + 0xf) & 1) == 0) {
loc_401B3EC:
    iVar2 = 0;
    if ((param_4 == 0) && (iVar1 = *param_6, iVar1 != 0)) {
      if (((char)param_5 < '\0') &&
         (((*(byte *)(iVar1 + 5) & 2) != 0 &&
          (_vnode_uncache(iVar1), (*(byte *)(*param_6 + 5) & 2) != 0)))) {
        iVar2 = 0x1a;
      }
      _vn_rele(*param_6);
    }
    if (iVar2 == 0) {
      if (*param_3 == 2) {
        if (*param_6 == 0) {
          iVar2 = (**(code **)(*(int *)(iStack_14 + 0x1c) + 0x34))
                            (iStack_14,uStack_c,param_3,param_6,*(undefined4 *)(_active_u + 0x1a));
        }
        else {
          _vn_rele(*param_6);
          iVar2 = 0x11;
        }
      }
      else {
        iVar2 = (**(code **)(*(int *)(iStack_14 + 0x1c) + 0x24))
                          (iStack_14,uStack_c,param_3,param_4,param_5,param_6,
                           *(undefined4 *)(_active_u + 0x1a));
      }
    }
  }
  else {
    iVar2 = *param_6;
    if (iVar2 != 0) {
      if (*(int *)(iVar2 + 0x28) - 3U < 2) goto loc_401B3EC;
      _vn_rele(iVar2);
    }
    iVar2 = 0x1e;
  }
  _pn_free(auStack_10);
  _vn_rele(iStack_14);
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=581 start=0x401b4b8 */

int _vn_close(int *param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1[10] == 1) {
    _unmap_vnode(param_1);
  }
  iVar1 = (**(code **)(param_1[7] + 4))(param_1,param_2,param_3,*(undefined4 *)(_active_u + 0x1a));
  iVar2 = *param_1;
  if ((iVar2 != 0) && (iVar3 = *(int *)(iVar2 + 0x30), iVar3 != 0)) {
    *(undefined4 *)(iVar2 + 0x30) = 0;
    *(char *)(dword_40B57D4 + 100) = (char)iVar3;
    do {
      iVar2 = _fspause(param_2 & 0x1000);
      if (iVar2 == 0) {
        return iVar3;
      }
      iVar3 = *(int *)(*param_1 + 0x30);
      *(undefined4 *)(*param_1 + 0x30) = 0;
      *(char *)(dword_40B57D4 + 100) = (char)iVar3;
      _mfs_fsync(param_1);
      iVar1 = 0;
    } while (iVar3 != 0);
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=582 start=0x401b55c */

int _vn_link(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iStack_18;
  int iStack_14;
  undefined auStack_10 [4];
  undefined4 uStack_c;
  
  iStack_18 = 0;
  iStack_14 = 0;
  iVar1 = _pn_get(param_2,param_3,auStack_10);
  if (iVar1 == 0) {
    iVar1 = _lookupname(param_1,param_3,1,0,&iStack_14);
    if ((iVar1 == 0) && (iVar1 = _lookuppn(auStack_10,1,&iStack_18,0), iVar1 == 0)) {
      if (*(int *)(iStack_14 + 0x24) == *(int *)(iStack_18 + 0x24)) {
        if ((*(byte *)(*(int *)(iStack_14 + 0x24) + 0xf) & 1) == 0) {
          iVar1 = (**(code **)(*(int *)(iStack_18 + 0x1c) + 0x2c))
                            (iStack_14,iStack_18,uStack_c,*(undefined4 *)(_active_u + 0x1a));
        }
        else {
          iVar1 = 0x1e;
        }
      }
      else {
        iVar1 = 0x12;
      }
    }
    _pn_free(auStack_10);
    if (iStack_14 != 0) {
      _vn_rele(iStack_14);
    }
    if (iStack_18 != 0) {
      _vn_rele(iStack_18);
    }
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=583 start=0x401b63e */

int _vn_rename(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  undefined auStack_1c [4];
  undefined4 uStack_18;
  undefined auStack_10 [4];
  undefined4 uStack_c;
  
  iStack_24 = 0;
  iStack_28 = 0;
  iStack_20 = 0;
  iVar1 = _pn_get(param_1,param_3,auStack_10);
  if (iVar1 == 0) {
    iVar1 = _pn_get(param_2,param_3,auStack_1c);
    if (iVar1 == 0) {
      iVar1 = _lookuppn(auStack_10,0,&iStack_20,&iStack_24);
      if (iVar1 == 0) {
        if (iStack_24 == 0) {
          iVar1 = 2;
        }
        else {
          iVar1 = _lookuppn(auStack_1c,0,&iStack_28,0);
          if (iVar1 == 0) {
            if (*(int *)(iStack_24 + 0x24) == *(int *)(iStack_28 + 0x24)) {
              if ((*(byte *)(*(int *)(iStack_24 + 0x24) + 0xf) & 1) == 0) {
                _vnode_uncache(iStack_28);
                iVar1 = (**(code **)(*(int *)(iStack_20 + 0x1c) + 0x30))
                                  (iStack_20,uStack_c,iStack_28,uStack_18,
                                   *(undefined4 *)(_active_u + 0x1a));
              }
              else {
                iVar1 = 0x1e;
              }
            }
            else {
              iVar1 = 0x12;
            }
          }
        }
      }
      _pn_free(auStack_10);
      _pn_free(auStack_1c);
      if (iStack_24 != 0) {
        _vn_rele(iStack_24);
      }
      if (iStack_20 != 0) {
        _vn_rele(iStack_20);
      }
      if (iStack_28 != 0) {
        _vn_rele(iStack_28);
      }
    }
    else {
      _pn_free(auStack_10);
    }
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=584 start=0x401b774 */

int _vn_remove(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  int iStack_18;
  int iStack_14;
  undefined auStack_10 [4];
  undefined4 uStack_c;
  
  iVar1 = _pn_get(param_1,param_2,auStack_10);
  if (iVar1 != 0) {
    return iVar1;
  }
  iStack_18 = 0;
  iVar1 = _lookuppn(auStack_10,0,&iStack_14,&iStack_18);
  if (iVar1 != 0) {
    _pn_free(auStack_10);
    return iVar1;
  }
  if (iStack_18 == 0) {
    iVar1 = 2;
  }
  else if ((*(byte *)(*(int *)(iStack_18 + 0x24) + 0xf) & 1) == 0) {
    if ((*(byte *)(iStack_18 + 5) & 1) == 0) {
      _vnode_uncache(iStack_18);
      if (*(int *)(iStack_18 + 0x28) == 2) {
        if (param_3 != 1) {
          iVar1 = 1;
          goto loc_401B892;
        }
        if (*(int *)(iStack_18 + 0x10) != 0) {
          iVar1 = 0x42;
          goto loc_401B892;
        }
        _vn_rele(iStack_18);
        uVar3 = *(undefined4 *)(_active_u + 0x1a);
        pcVar2 = *(code **)(*(int *)(iStack_14 + 0x1c) + 0x38);
      }
      else {
        if (param_3 != 0) {
          iVar1 = 0x14;
          goto loc_401B892;
        }
        _vn_rele(iStack_18);
        uVar3 = *(undefined4 *)(_active_u + 0x1a);
        pcVar2 = *(code **)(*(int *)(iStack_14 + 0x1c) + 0x28);
      }
      iStack_18 = 0;
      iVar1 = (*pcVar2)(iStack_14,uStack_c,uVar3);
    }
    else {
      iVar1 = 0x10;
    }
  }
  else {
    iVar1 = 0x1e;
  }
loc_401B892:
  _pn_free(auStack_10);
  if (iStack_18 != 0) {
    _vn_rele(iStack_18);
  }
  _vn_rele(iStack_14);
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=585 start=0x401b8c4 */

undefined4 _isrofile(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((1 < *(int *)(param_1 + 0x28) - 3U) && (*(int *)(param_1 + 0x28) != 8)) &&
     ((*(byte *)(*(int *)(param_1 + 0x24) + 0xf) & 1) != 0)) {
    uVar1 = 1;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=586 start=0x401b8fa */

void _vattr_null(undefined *param_1)

{
  word wVar1;
  int iVar2;
  sword sVar3;
  undefined *puVar4;
  
  iVar2 = 0x39;
  do {
    do {
      puVar4 = param_1 + 1;
      *param_1 = 0xff;
      wVar1 = (word)((uint)iVar2 >> 0x10);
      sVar3 = (sword)iVar2 + -1;
      iVar2 = CONCAT22(wVar1,sVar3);
      param_1 = puVar4;
    } while (sVar3 != -1);
    iVar2 = (uint)wVar1 * 0x10000 + -1;
  } while (wVar1 != 0);
  return;
}
/* GHIDRADEC_FUNCTION index=587 start=0x401b914 */

void _ustat(void)

{
  int iVar1;
  undefined uVar2;
  int iStack_5c;
  int iStack_58;
  undefined4 uStack_54;
  undefined auStack_44 [4];
  int iStack_40;
  int iStack_34;
  undefined4 uStack_2c;
  
  iVar1 = *(int *)(dword_40B57D4 + 0x24);
  uVar2 = _vafsidtovfs(*(undefined2 *)(iVar1 + 2),&iStack_5c);
  *(undefined *)(dword_40B57D4 + 100) = uVar2;
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    uVar2 = (**(code **)(*(int *)(iStack_5c + 4) + 0xc))(iStack_5c,auStack_44);
    *(undefined *)(dword_40B57D4 + 100) = uVar2;
    if (*(char *)(dword_40B57D4 + 100) == '\0') {
      _bzero(&iStack_58,0x14);
      iStack_58 = iStack_40 * iStack_34 + 0x1ff;
      if (iStack_58 < 0) {
        iStack_58 = iStack_40 * iStack_34 + 0x3fe;
      }
      iStack_58 = iStack_58 >> 9;
      uStack_54 = uStack_2c;
      uVar2 = _copyoutmsg(&iStack_58,*(undefined4 *)(iVar1 + 4),0x14);
      *(undefined *)(dword_40B57D4 + 100) = uVar2;
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=588 start=0x401b9dc */

int _physio(undefined4 param_1,uint *param_2,undefined2 param_3,uint param_4,code *param_5,
           int *param_6,uint param_7)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  do {
    if (param_6[1] == 0) {
      return 0;
    }
    puVar1 = (uint *)*param_6;
    if ((param_6[3] != 1) && (iVar3 = _useracc(*puVar1,puVar1[1],-(int)-(param_4 != 1)), iVar3 == 0)
       ) {
      return 0xe;
    }
    while ((*param_2 & 8) != 0) {
      *param_2 = *param_2 | 0x40;
      _sleep(param_2,0x15);
    }
    *(undefined2 *)(param_2 + 7) = 0;
    param_2[0xb] = *_active_u;
    param_2[8] = *puVar1;
    uVar2 = puVar1[1];
    while (0 < (int)uVar2) {
      *param_2 = param_4 | 0x18;
      *(undefined2 *)((int)param_2 + 0x1e) = param_3;
      param_2[9] = (uint)param_6[2] / param_7;
      param_2[5] = puVar1[1];
      (*param_5)(param_2);
      uVar2 = param_2[5];
      if (param_6[3] == 1) {
        *(byte *)param_2 = *(byte *)param_2 | 4;
      }
      else {
        *(word *)(*_active_u + 0x2a) = *(word *)(*_active_u + 0x2a) | 0x800;
        uVar4 = param_2[8];
        _vslock(uVar4,uVar2);
      }
      _physstrat(param_2,param_1,0x14);
      if (param_6[3] != 1) {
        _vsunlock(uVar4,uVar2,param_4);
        *(word *)(*_active_u + 0x2a) = *(word *)(*_active_u + 0x2a) & 0xf7ff;
      }
      if ((*param_2 & 0x40) != 0) {
        _wakeup(param_2);
      }
      iVar3 = uVar2 - param_2[10];
      param_2[8] = iVar3 + param_2[8];
      puVar1[1] = puVar1[1] - iVar3;
      *(int *)((int)param_6 + 0x12) = *(int *)((int)param_6 + 0x12) - iVar3;
      param_6[2] = iVar3 + param_6[2];
      if ((param_2[10] != 0) || ((*param_2 & 4) != 0)) break;
      uVar2 = puVar1[1];
    }
    *param_2 = *param_2 & 0xffffffa7;
    iVar3 = _geterror(param_2);
    if (param_2[10] != 0) {
      return iVar3;
    }
    if (iVar3 != 0) {
      return iVar3;
    }
    *param_6 = *param_6 + 8;
    param_6[1] = param_6[1] + -1;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=589 start=0x401bb7c */

word _physstrat(int param_1,code *param_2,undefined4 param_3)

{
  byte bVar1;
  word wVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  
  wVar2 = (*param_2)(param_1);
  if ((*(byte *)(param_1 + 2) & 0x20) == 0) {
    cVar3 = '\0';
    cVar4 = '\0';
    cVar5 = '\0';
    bVar6 = 0;
    bVar1 = *(byte *)(param_1 + 3);
    while ((bVar1 & 2) == 0) {
      cVar4 = param_1 < 0;
      cVar5 = '\0';
      bVar6 = 0;
      _sleep(param_1,param_3);
      bVar1 = *(byte *)(param_1 + 3);
    }
    wVar2 = (word)(byte)(cVar3 << 4 | cVar4 << 3 | cVar5 << 1 | bVar6);
  }
  return wVar2;
}
/* GHIDRADEC_FUNCTION index=590 start=0x401bbd2 */

void _null_init(void)

{
  int *piVar1;
  
  piVar1 = &_afswitch;
  do {
    if (*piVar1 == 0) {
      *piVar1 = (int)_null_hash;
    }
    piVar1 = piVar1 + 2;
  } while (piVar1 < &_ifqmaxlen);
  return;
}
/* GHIDRADEC_FUNCTION index=591 start=0x401bbfa */

void _null_hash(undefined4 param_1,undefined4 *param_2)

{
  *param_2 = 0;
  param_2[1] = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=592 start=0x401bc0c */

undefined4 _null_netmatch(void)

{
  return 0;
}
/* GHIDRADEC_FUNCTION index=593 start=0x401bc16 */

void _ifinit(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=594 start=0x401bc1e */

sword * _ifa_ifwithaddr(sword *param_1)

{
  sword *psVar1;
  int iVar2;
  int iVar3;
  
  if (_ifnet != 0) {
    iVar3 = _ifnet;
    do {
      for (psVar1 = *(sword **)(iVar3 + 0x16); psVar1 != (sword *)0x0;
          psVar1 = *(sword **)(psVar1 + 0x12)) {
        if (*param_1 == *psVar1) {
          iVar2 = _bcmp(psVar1 + 1,param_1 + 1,0xe);
          if (iVar2 == 0) {
            return psVar1;
          }
          if (((*(byte *)(iVar3 + 0xd) & 2) != 0) &&
             (iVar2 = _bcmp(psVar1 + 9,param_1 + 1,0xe), iVar2 == 0)) {
            return psVar1;
          }
        }
      }
      iVar3 = *(int *)(iVar3 + 0x5a);
    } while (iVar3 != 0);
  }
  return (sword *)0x0;
}
/* GHIDRADEC_FUNCTION index=595 start=0x401bc9e */

sword * _ifa_ifwithdstaddr(sword *param_1)

{
  sword *psVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = _ifnet;
  do {
    if (iVar2 == 0) {
      return (sword *)0x0;
    }
    if ((*(byte *)(iVar2 + 0xd) & 0x10) != 0) {
      for (psVar1 = *(sword **)(iVar2 + 0x16); psVar1 != (sword *)0x0;
          psVar1 = *(sword **)(psVar1 + 0x12)) {
        if ((*param_1 == *psVar1) && (iVar3 = _bcmp(psVar1 + 9,param_1 + 1,0xe), iVar3 == 0)) {
          return psVar1;
        }
      }
    }
    iVar2 = *(int *)(iVar2 + 0x5a);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=596 start=0x401bd04 */

word * _ifa_ifwithnet(word *param_1)

{
  word *pwVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  
  if (*param_1 < 0x11) {
    pcVar3 = (&off_40AE86A)[(uint)*param_1 * 2];
    for (iVar2 = _ifnet; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x5a)) {
      for (pwVar1 = *(word **)(iVar2 + 0x16); pwVar1 != (word *)0x0;
          pwVar1 = *(word **)(pwVar1 + 0x12)) {
        if ((*param_1 == *pwVar1) && (iVar4 = (*pcVar3)(pwVar1,param_1), iVar4 != 0)) {
          return pwVar1;
        }
      }
    }
  }
  return (word *)0x0;
}
/* GHIDRADEC_FUNCTION index=597 start=0x401bd6a */

undefined4 _ifb_ifwithaf(void)

{
  return _ifnet;
}
/* GHIDRADEC_FUNCTION index=598 start=0x401bd78 */

void _if_down(int param_1)

{
  int iVar1;
  
  *(word *)(param_1 + 0xc) = *(word *)(param_1 + 0xc) & 0xffbe;
  for (iVar1 = *(int *)(param_1 + 0x16); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x24)) {
    _pfctlinput(0,iVar1);
  }
  _if_qflush(param_1 + 0x1a);
  return;
}
/* GHIDRADEC_FUNCTION index=599 start=0x401bdbc */

void _if_qflush(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  while (iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 0x7c);
    _m_freem(iVar2);
    iVar2 = iVar1;
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}

