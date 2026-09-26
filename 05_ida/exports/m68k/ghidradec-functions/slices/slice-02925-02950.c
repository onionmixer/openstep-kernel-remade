/* GHIDRADEC_FUNCTION index=2925 start=0x403a216 */

int sub_403A216(int param_1,int param_2,uint param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  word wVar5;
  int iVar6;
  undefined uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int *piVar11;
  uint uVar12;
  int iStack_8;
  
  iStack_8 = 0;
  iVar1 = *(int *)(param_2 + 0x12);
  if (1 < param_3) {
                    /* WARNING: Subroutine does not return */
    _panic(&aRwip);
  }
  wVar5 = *(word *)(param_1 + 0x62) & 0xf000;
  if (((wVar5 != 0x8000) && (wVar5 != 0x4000)) && (wVar5 != 0xa000)) {
                    /* WARNING: Subroutine does not return */
    _panic(aRwipType);
  }
  if (-1 < *(int *)(param_2 + 8)) {
    uVar4 = *(int *)(param_2 + 0x12) + *(int *)(param_2 + 8);
    if (-1 < (int)uVar4) {
      if (*(int *)(param_2 + 0x12) == 0) {
        return 0;
      }
      if (param_3 == 1) {
        if ((wVar5 == 0x8000) && (*(uint *)((int)_active_u + 0x25e) < uVar4)) {
          _psignal(*_active_u,0x19);
          return 0x1b;
        }
      }
      else {
        *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 4;
      }
      uVar2 = *(undefined4 *)(param_1 + 0x3e);
      iVar3 = *(int *)(param_1 + 0x4e);
      uVar4 = *(uint *)(iVar3 + 0x30);
      *(undefined *)(dword_40B57D4 + 100) = 0;
      param_4 = param_4 & 4;
      while( true ) {
        uVar8 = *(uint *)(param_2 + 8);
        uVar10 = uVar8 % uVar4;
        uVar9 = uVar8 / uVar4;
        uVar12 = *(uint *)(param_2 + 0x12);
        if (uVar4 - uVar10 < *(uint *)(param_2 + 0x12)) {
          uVar12 = uVar4 - uVar10;
        }
        if (param_3 == 0) {
          uVar8 = *(int *)(param_1 + 0x6e) - uVar8;
          if ((int)uVar8 < 1) {
            return 0;
          }
          if ((int)uVar8 < (int)uVar12) {
            uVar12 = uVar8;
          }
        }
        piVar11 = (int *)0x0;
        if (param_4 != 0) {
          piVar11 = &iStack_8;
        }
        iVar6 = _bmap(param_1,uVar9,-(int)-(param_3 != 1),uVar12 + uVar10,piVar11);
        iVar6 = iVar6 << (*(uint *)(iVar3 + 100) & 0x3f);
        if (((*(char *)(dword_40B57D4 + 100) == '\x1c') && (param_3 == 1)) &&
           ((iVar1 != *(int *)(param_2 + 0x12) && -1 < iVar1 - *(int *)(param_2 + 0x12) &&
            ((*(byte *)(*_active_u + 0x16) & 0x40) != 0)))) break;
        if (*(char *)(dword_40B57D4 + 100) != '\0') {
loc_403A3CE:
          return (int)*(char *)(dword_40B57D4 + 100);
        }
        if (param_3 == 1) {
          if (iVar6 < 0) goto loc_403A3CE;
          if ((*(uint *)(param_1 + 0x6e) < uVar12 + *(int *)(param_2 + 8)) &&
             (((wVar5 == 0x4000 || (wVar5 == 0x8000)) || (wVar5 == 0xa000)))) {
            uVar8 = uVar12 + *(int *)(param_2 + 8);
            *(uint *)(param_1 + 0x6e) = uVar8;
            if (*(uint *)(*(int *)(param_1 + 0xc) + 0x14) < uVar8) {
              *(uint *)(*(int *)(param_1 + 0xc) + 0x14) = uVar8;
            }
            if (param_4 != 0) {
              iStack_8 = 1;
            }
          }
        }
        if (((int)uVar9 < 0xc) &&
           (*(uint *)(param_1 + 0x6e) < uVar9 + 1 << (*(uint *)(iVar3 + 0x50) & 0x3f))) {
          uVar8 = *(uint *)(iVar3 + 0x4c) &
                  (*(int *)(iVar3 + 0x34) + (*(uint *)(param_1 + 0x6e) & ~*(uint *)(iVar3 + 0x48)))
                  - 1;
        }
        else {
          uVar8 = *(uint *)(iVar3 + 0x30);
        }
        if (param_3 == 0) {
          if (iVar6 < 0) {
            iVar6 = _geteblk(uVar8);
            _blkclr(*(undefined4 *)(iVar6 + 0x20),*(undefined4 *)(iVar6 + 0x14));
            *(undefined4 *)(iVar6 + 0x28) = 0;
          }
          else if (*(int *)(param_1 + 0x56) + 1U == uVar9) {
            iVar6 = _breada(uVar2,iVar6,uVar8,_rablock,_rasize);
          }
          else {
            iVar6 = _bread(uVar2,iVar6,uVar8);
          }
          *(uint *)(param_1 + 0x56) = uVar9;
        }
        else if (uVar4 == uVar12) {
          iVar6 = _getblk(uVar2,iVar6,uVar8);
        }
        else {
          iVar6 = _bread(uVar2,iVar6,uVar8);
        }
        uVar8 = *(int *)(iVar6 + 0x14) - *(int *)(iVar6 + 0x28);
        if ((int)uVar8 < (int)uVar12) {
          uVar12 = uVar8;
        }
        if ((*(byte *)(iVar6 + 3) & 4) != 0) {
          _brelse(iVar6);
          return 5;
        }
        uVar7 = _uiomove(uVar10 + *(int *)(iVar6 + 0x20),uVar12,param_3,param_2);
        *(undefined *)(dword_40B57D4 + 100) = uVar7;
        if (((param_4 != 0) && ((*(word *)(param_1 + 0x62) & 0x200) != 0)) &&
           ((_stickyhack != 0 && ((*(word *)(param_1 + 0x62) & 0x49) == 0)))) {
          *(byte *)(iVar6 + 1) = *(byte *)(iVar6 + 1) | 0x40;
        }
        if (param_3 == 0) {
          if ((uVar4 == uVar10 + uVar12) || (*(int *)(param_2 + 8) == *(int *)(param_1 + 0x6e))) {
            *(word *)(iVar6 + 2) = *(word *)(iVar6 + 2) | 0x80;
          }
          _brelse(iVar6);
        }
        else {
          if ((param_4 == 0) && ((*(word *)(param_1 + 0x62) & 0xf000) != 0x4000)) {
            if (uVar4 == uVar10 + uVar12) {
              *(word *)(iVar6 + 2) = *(word *)(iVar6 + 2) | 0x80;
              _bawrite(iVar6);
            }
            else {
              _bdwrite(iVar6);
            }
          }
          else {
            _bwrite(iVar6);
          }
          *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x42;
          if (*(sword *)(*(int *)((int)_active_u + 0x1a) + 6) != 0) {
            *(word *)(param_1 + 0x62) = *(word *)(param_1 + 0x62) & 0xf3ff;
          }
        }
        if (((*(char *)(dword_40B57D4 + 100) != '\0') || (*(int *)(param_2 + 0x12) < 1)) ||
           (uVar12 == 0)) goto loc_403A5F6;
      }
      *(undefined *)(dword_40B57D4 + 100) = 0;
loc_403A5F6:
      if (iStack_8 != 0) {
        _iupdat(param_1,1);
      }
      return (int)*(char *)(dword_40B57D4 + 100);
    }
  }
  return 0x16;
}
/* GHIDRADEC_FUNCTION index=2926 start=0x403a9fe */

undefined4 sub_403A9FE(int param_1,sword param_2,sword param_3)

{
  int iVar1;
  
  if (param_2 == -1) {
    param_2 = *(sword *)(param_1 + 0x66);
  }
  if (param_3 == -1) {
    param_3 = *(sword *)(param_1 + 0x68);
  }
  if ((((param_2 != *(sword *)(*(int *)(_active_u + 0x1a) + 2)) ||
       (param_2 != *(sword *)(param_1 + 0x66))) || (iVar1 = _groupmember((int)param_3), iVar1 == 0))
     && (iVar1 = _suser(), iVar1 == 0)) {
    return 1;
  }
  *(sword *)(param_1 + 0x66) = param_2;
  *(sword *)(param_1 + 0x68) = param_3;
  *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x40;
  if (*(sword *)(*(int *)(_active_u + 0x1a) + 2) != 0) {
    *(word *)(param_1 + 0x62) = *(word *)(param_1 + 0x62) & 0xf3ff;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=2927 start=0x404310c */

void sub_404310C(uint param_1,int param_2,int *param_3,int *param_4,undefined4 *param_5,int *param_6
                ,undefined4 *param_7)

{
  int iVar1;
  uint uVar2;
  
  while (*(uint *)(param_2 + 0x10) != param_1) {
    if (param_1 < *(uint *)(param_2 + 0x10)) {
      iVar1 = *(int *)(param_2 + 0x18);
      if (iVar1 == 0) break;
      uVar2 = *(uint *)(iVar1 + 0x10);
      if ((param_1 < uVar2) && (*(int *)(iVar1 + 0x18) != 0)) {
        *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(iVar1 + 0x1c);
        *(int *)(iVar1 + 0x1c) = param_2;
        param_2 = iVar1;
      }
      *param_6 = param_2;
      param_6 = (int *)(param_2 + 0x18);
      param_2 = *param_6;
      if ((uVar2 < param_1) && (*(int *)(iVar1 + 0x1c) != 0)) {
        *param_4 = param_2;
        param_4 = (int *)(param_2 + 0x1c);
        param_2 = *param_4;
      }
    }
    else {
      iVar1 = *(int *)(param_2 + 0x1c);
      if (iVar1 == 0) break;
      uVar2 = *(uint *)(iVar1 + 0x10);
      if ((uVar2 < param_1) && (*(int *)(iVar1 + 0x1c) != 0)) {
        *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(iVar1 + 0x18);
        *(int *)(iVar1 + 0x18) = param_2;
        param_2 = iVar1;
      }
      *param_4 = param_2;
      param_4 = (int *)(param_2 + 0x1c);
      param_2 = *param_4;
      if ((param_1 < uVar2) && (*(int *)(iVar1 + 0x18) != 0)) {
        *param_6 = param_2;
        param_6 = (int *)(param_2 + 0x18);
        param_2 = *param_6;
      }
    }
  }
  *param_3 = param_2;
  *param_5 = param_4;
  *param_7 = param_6;
  return;
}
/* GHIDRADEC_FUNCTION index=2928 start=0x40431d2 */

void sub_40431D2(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
                undefined4 *param_5)

{
  *param_3 = *(undefined4 *)(param_1 + 0x18);
  *param_5 = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(param_1 + 0x18) = *param_2;
  *(undefined4 *)(param_1 + 0x1c) = *param_4;
  return;
}
/* GHIDRADEC_FUNCTION index=2929 start=0x404a45c */

void sub_404A45C(undefined4 *param_1)

{
  param_1[2] = 0;
  *dword_40B3716 = param_1;
  param_1[1] = dword_40B3716;
  *param_1 = &dword_40B3712;
  dword_40B3716 = param_1;
  dword_40AF7D4 = dword_40AF7D4 + 1;
  dword_40C2330 = dword_40C2330 + 1;
  return;
}
/* GHIDRADEC_FUNCTION index=2930 start=0x404a498 */

void sub_404A498(uint param_1)

{
  undefined4 *puVar1;
  bool bVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar6 = (undefined4 *)(param_1 & ~_page_mask);
  bVar2 = true;
  iVar4 = 0;
  puVar5 = puVar6;
  if (0 < dword_40B371E) {
    do {
      if (puVar5[2] != 0) {
        bVar2 = false;
      }
      iVar4 = iVar4 + 1;
      puVar5 = (undefined4 *)(dword_40B371A + (int)puVar5);
    } while (iVar4 < dword_40B371E);
  }
  if (bVar2) {
    iVar4 = 0;
    if (0 < dword_40B371E) {
      do {
        puVar5 = (undefined4 *)*puVar6;
        puVar1 = (undefined4 *)puVar6[1];
        puVar3 = puVar1;
        if (puVar5 != &dword_40B3712) {
          puVar5[1] = puVar1;
          puVar3 = dword_40B3716;
        }
        dword_40B3716 = puVar3;
        *puVar1 = puVar5;
        dword_40AF7D4 = dword_40AF7D4 + -1;
        dword_40C2330 = dword_40C2330 + -1;
        _stack_finalize(puVar6 + 3);
        puVar6 = (undefined4 *)(dword_40B371A + (int)puVar6);
        iVar4 = iVar4 + 1;
      } while (iVar4 < dword_40B371E);
    }
    _kmem_free(_kernel_map,param_1,dword_40B371A);
    _stackStats = _stackStats + -1;
  }
  else {
    iVar4 = _canSwap(param_1);
    if (iVar4 != 0) {
      _doSwapout(param_1);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2931 start=0x404b864 */

int * sub_404B864(int param_1)

{
  uint uVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 0x1c);
  uVar1 = 0;
  if (*(uint *)(param_1 + 0x10) != 0) {
    do {
      if (*piVar2 == 9) {
        return piVar2;
      }
      piVar2 = (int *)(piVar2[1] + (int)piVar2);
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)(param_1 + 0x10));
  }
  return (int *)0x0;
}
/* GHIDRADEC_FUNCTION index=2932 start=0x404b924 */

uint sub_404B924(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  for (iVar2 = _firstsegfromheader(param_1); iVar2 != 0; iVar2 = _nextsegfromheader(param_1,iVar2))
  {
    uVar1 = *(int *)(iVar2 + 0x24) + *(int *)(iVar2 + 0x20);
    if (uVar3 < uVar1) {
      uVar3 = uVar1;
    }
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=2933 start=0x404bc42 */

int sub_404BC42(int *param_1,undefined4 param_2,int param_3,undefined4 param_4,uint param_5,
               int param_6,int param_7,int param_8)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  word wVar6;
  sword sVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  int iStack_8;
  int iVar7;
  
  puVar10 = (undefined4 *)0x0;
  if (param_6 < 7) {
    param_6 = param_6 + 1;
    if ((*(int *)(param_3 + 4) != dword_40B5DCC) ||
       (iVar3 = _check_cpu_subtype(*(undefined4 *)(param_3 + 8)), iVar3 == 0)) {
      return 1;
    }
    switch(*(undefined4 *)(param_3 + 0xc)) {
    case :
    case :
    case :
      iVar3 = 1;
      break;
    case :
    case :
      if (param_6 == 1) {
        return 4;
      }
      goto loc_404BCCC;
    :
      goto loc_404BCC0;
    case :
      iVar3 = 2;
    }
    if (iVar3 == param_6) {
loc_404BCCC:
      uVar4 = _vnode_pager_setup(param_1,0,1);
      if ((param_5 < *(int *)(param_3 + 0x14) + 0x1cU) ||
         (uVar2 = ~_page_mask & *(int *)(param_3 + 0x14) + 0x1c + _page_mask, uVar2 == 0)) {
        return 2;
      }
      iStack_8 = 0;
      iVar3 = _vm_allocate_with_pager(_kernel_map,&iStack_8,uVar2,1,uVar4,param_4);
      if (iVar3 != 0) {
        return 5;
      }
      iVar3 = 1;
      iVar5 = 0;
      do {
        uVar9 = 0x1c;
        iVar7 = *(int *)(param_3 + 0x10) + -1;
        puVar11 = puVar10;
        if (iVar7 != -1) {
          do {
            puVar1 = (undefined4 *)(iStack_8 + uVar9);
            uVar9 = puVar1[1] + uVar9;
            if (*(int *)(param_3 + 0x14) + 0x1cU < uVar9) {
              _vm_map_remove(_kernel_map,iStack_8,uVar2 + iStack_8);
              return 2;
            }
            puVar10 = puVar11;
            switch(*puVar1) {
            case :
              if (iVar3 == 1) {
                iVar5 = sub_404BEE0(puVar1,uVar4,param_4,param_5,*(undefined4 *)(*param_1 + 0x14),
                                    param_2,param_8);
              }
              break;
            :
              iVar5 = 0;
              break;
            case :
              if (iVar3 == 2) {
                iVar5 = sub_404C1C8(puVar1,param_8);
              }
              break;
            case :
              if (iVar3 == 2) {
                iVar5 = sub_404C13C(puVar1,param_8);
              }
              break;
            case :
              if (iVar3 == 1) {
                iVar5 = sub_404C398(puVar1,param_2,param_6);
              }
              break;
            case :
              if ((iVar3 == 1) && (param_7 != 0)) {
                iVar5 = sub_404C44A(puVar1,param_7);
              }
              break;
            case :
              if (((iVar3 == 2) && (puVar10 = puVar1, param_6 != 1)) &&
                 (puVar11 != (undefined4 *)0x0)) {
                iVar5 = 4;
                goto loc_404BEAC;
              }
            }
            if (iVar5 != 0) goto loc_404BEAC;
            wVar6 = (word)((uint)iVar7 >> 0x10);
            sVar8 = (sword)iVar7 + -1;
            iVar7 = CONCAT22(wVar6,sVar8);
            puVar11 = puVar10;
          } while ((sVar8 != -1) || (iVar7 = (uint)wVar6 * 0x10000 + -1, wVar6 != 0));
        }
        if (iVar5 != 0) goto loc_404BEAC;
        iVar3 = iVar3 + 1;
      } while (iVar3 < 3);
      if (puVar10 != (undefined4 *)0x0) {
        iVar5 = sub_404C460(puVar10,param_2,param_6,param_8);
      }
loc_404BEAC:
      _vm_map_remove(_kernel_map,iStack_8,uVar2 + iStack_8);
      if (iVar5 != 0) {
        return iVar5;
      }
      if (param_6 == 1) {
        if (*(int *)(param_8 + 0xc) == 0) {
          return 4;
        }
        return 0;
      }
      return 0;
    }
  }
loc_404BCC0:
  return 4;
}
/* GHIDRADEC_FUNCTION index=2934 start=0x404bee0 */

undefined4
sub_404BEE0(int param_1,undefined4 param_2,int param_3,uint param_4,int param_5,undefined4 param_6,
           uint *param_7)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  undefined4 uVar5;
  uint *puVar6;
  uint **ppuVar7;
  uint *puStack_44;
  uint *puStack_40;
  int iStack_3c;
  uint uStack_10;
  uint *puStack_c;
  uint uStack_8;
  
  if ((uint)(*(int *)(param_1 + 0x24) + *(int *)(param_1 + 0x20)) <= param_4) {
    uVar2 = ~_page_mask & _page_mask + *(int *)(param_1 + 0x1c);
    if (-1 < (int)uVar2) {
      if (uVar2 != 0) {
        uStack_8 = *(uint *)(param_1 + 0x18) & ~_page_mask;
        iStack_3c = 0;
        puStack_44 = &uStack_8;
        puStack_40 = (uint *)uVar2;
        iVar4 = _vm_map_find(param_6,0,0);
        if (iVar4 != 0) {
          return 5;
        }
        puVar3 = (uint *)(~_page_mask & _page_mask + *(int *)(param_1 + 0x24));
        param_3 = param_3 + *(int *)(param_1 + 0x20);
        if ((int)puVar3 < 0) {
          return 2;
        }
        if (0 < (int)puVar3) {
          iStack_3c = 1;
          puStack_44 = (uint *)0x0;
          puStack_40 = puVar3;
          uVar5 = _pmap_create(puVar3);
          uVar5 = _vm_map_create(uVar5);
          puStack_c = (uint *)0x0;
          iVar4 = _vm_allocate_with_pager(uVar5,&puStack_c,puVar3,0,param_2,param_3);
          if (iVar4 != 0) {
loc_404BFFA:
            puStack_40 = (uint *)0x404c002;
            iStack_3c = uVar5;
            _vm_map_deallocate();
            return 5;
          }
          puVar1 = *(uint **)(param_1 + 0x24);
          puVar6 = puVar3;
          if ((puVar1 != puVar3) && ((param_5 == 0 || (param_5 != (int)puVar1 + param_3)))) {
            puVar6 = (uint *)(~_page_mask & (uint)puVar1);
            uStack_10 = 0;
            iStack_3c = 1;
            puStack_40 = (uint *)_page_size;
            puStack_44 = &uStack_10;
            iVar4 = _vm_map_find(_kernel_map,0,0);
            if (iVar4 != 0) goto loc_404BFFA;
            iStack_3c = 0;
            puStack_40 = (uint *)0x0;
            puStack_44 = puVar6;
            iVar4 = _vm_map_copy(_kernel_map,uVar5,uStack_10,_page_size);
            if (iVar4 != 0) {
              iStack_3c = _page_size;
              puStack_40 = (uint *)uStack_10;
              ppuVar7 = &puStack_44;
              puStack_44 = _kernel_map;
              _vm_deallocate();
loc_404C0A2:
              *(undefined4 *)((int)ppuVar7 + -4) = uVar5;
              *(undefined4 *)((int)ppuVar7 + -8) = 0x404c0aa;
              _vm_map_deallocate();
              return 4;
            }
            iStack_3c = (int)puVar3 - *(int *)(param_1 + 0x24);
            puStack_40 = (uint *)(uStack_10 + (*(int *)(param_1 + 0x24) - (int)puVar6));
            puStack_44 = (uint *)0x404c05e;
            _bzero();
            puStack_44 = (uint *)0x0;
            iVar4 = _vm_map_copy(param_6,_kernel_map,(int)puVar6 + uStack_8,_page_size,uStack_10,0);
            iStack_3c = _page_size;
            puStack_40 = (uint *)uStack_10;
            puStack_44 = _kernel_map;
            _vm_deallocate();
            ppuVar7 = (uint **)&stack0xffffffc8;
            if (iVar4 != 0) goto loc_404C0A2;
          }
          iStack_3c = 0;
          puStack_40 = (uint *)0x0;
          puStack_44 = puStack_c;
          iVar4 = _vm_map_copy(param_6,uVar5,uStack_8,puVar6);
          _vm_map_deallocate(uVar5);
          if (iVar4 != 0) {
            return 4;
          }
        }
        puStack_40 = *(uint **)(param_1 + 0x28);
        if (puStack_40 != (uint *)0x3) {
          iStack_3c = 1;
          puStack_44 = (uint *)(uStack_8 + uVar2);
          _vm_map_protect(param_6,uStack_8);
        }
        puStack_40 = *(uint **)(param_1 + 0x2c);
        if (puStack_40 != (uint *)0x3) {
          iStack_3c = 0;
          puStack_44 = (uint *)(uStack_8 + uVar2);
          _vm_map_protect(param_6,uStack_8);
        }
        if (*(int *)(param_1 + 0x20) == 0) {
          *param_7 = uStack_8;
        }
      }
      return 0;
    }
  }
  return 2;
}
/* GHIDRADEC_FUNCTION index=2935 start=0x404c13c */

int sub_404C13C(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = _active_threads;
  if (*(int *)(param_2 + 0xc) == 0) {
    iVar1 = param_1 + 8;
    iVar3 = sub_404C2E4(_active_threads,iVar1,*(int *)(param_1 + 4) + -8,param_2 + 8);
    if (iVar3 == 0) {
      iVar3 = sub_404C33E(uVar2,iVar1,*(int *)(param_1 + 4) + -8,param_2 + 4);
      if (iVar3 == 0) {
        iVar3 = sub_404C294(uVar2,iVar1,*(int *)(param_1 + 4) + -8);
        if (iVar3 == 0) {
          *(byte *)(param_2 + 0x10) = *(byte *)(param_2 + 0x10) | 0x80;
          *(int *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) + 1;
          iVar3 = 0;
        }
      }
    }
  }
  else {
    iVar3 = 4;
  }
  return iVar3;
}
/* GHIDRADEC_FUNCTION index=2936 start=0x404c1c8 */

int sub_404C1C8(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iStack_8;
  
  if (*(int *)(param_2 + 0xc) == 0) {
    iStack_8 = _active_threads;
  }
  else {
    iVar2 = _thread_create(*(undefined4 *)(_active_threads + 0xc),&iStack_8);
    if (iVar2 != 0) {
      return 7;
    }
    _thread_deallocate(iStack_8);
  }
  iVar2 = param_1 + 8;
  iVar1 = sub_404C294(iStack_8,iVar2,*(int *)(param_1 + 4) + -8);
  if (iVar1 == 0) {
    if (*(int *)(param_2 + 0xc) == 0) {
      iVar1 = sub_404C2E4(_active_threads,iVar2,*(int *)(param_1 + 4) + -8,param_2 + 8);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar2 = sub_404C33E(_active_threads,iVar2,*(int *)(param_1 + 4) + -8,param_2 + 4);
      if (iVar2 != 0) {
        return iVar2;
      }
    }
    else {
      _thread_resume(iStack_8);
    }
    *(int *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) + 1;
    iVar1 = 0;
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=2937 start=0x404c294 */

undefined4 sub_404C294(undefined4 param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  while( true ) {
    if (param_3 == 0) {
      return 0;
    }
    iVar1 = param_2[1];
    param_3 = param_3 + (iVar1 + 2) * -4;
    iVar2 = _thread_setstatus(param_1,*param_2,param_2 + 2,iVar1);
    if (iVar2 != 0) break;
    param_2 = param_2 + 2 + iVar1;
  }
  return 4;
}
/* GHIDRADEC_FUNCTION index=2938 start=0x404c2e4 */

undefined4 sub_404C2E4(undefined4 param_1,undefined4 *param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  
  *param_4 = 0;
  while( true ) {
    if (param_3 == 0) {
      return 0;
    }
    iVar1 = param_2[1];
    param_3 = param_3 + (iVar1 + 2) * -4;
    iVar2 = _thread_userstack(param_1,*param_2,param_2 + 2,iVar1,param_4);
    if (iVar2 != 0) break;
    param_2 = param_2 + 2 + iVar1;
  }
  return 4;
}
/* GHIDRADEC_FUNCTION index=2939 start=0x404c33e */

undefined4 sub_404C33E(undefined4 param_1,undefined4 *param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  
  *param_4 = 0;
  while( true ) {
    if (param_3 == 0) {
      return 0;
    }
    iVar1 = param_2[1];
    param_3 = param_3 + (iVar1 + 2) * -4;
    iVar2 = _thread_entrypoint(param_1,*param_2,param_2 + 2,iVar1,param_4);
    if (iVar2 != 0) break;
    param_2 = param_2 + 2 + iVar1;
  }
  return 4;
}
/* GHIDRADEC_FUNCTION index=2940 start=0x404c398 */

int sub_404C398(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  uint uStack_42;
  undefined4 uStack_3e;
  undefined4 uStack_3a;
  undefined4 uStack_36;
  undefined4 auStack_32 [4];
  undefined auStack_20 [28];
  
  pcVar2 = (char *)(*(int *)(param_1 + 8) + param_1);
  pcVar4 = pcVar2;
  do {
    if ((char *)(*(int *)(param_1 + 4) + param_1) <= pcVar4) {
      return 2;
    }
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  iVar3 = sub_404C5D6(pcVar2,auStack_20,&uStack_36,&uStack_3a,&uStack_3e);
  if (iVar3 == 0) {
    _bzero(auStack_32,0x12);
    auStack_32[0] = 0;
    iVar3 = sub_404BC42(uStack_3e,param_2,auStack_20,uStack_36,uStack_3a,param_3,&uStack_42,
                        auStack_32);
    if ((iVar3 == 0) && (uStack_42 < *(uint *)(param_1 + 0xc))) {
      iVar3 = 3;
    }
    _vn_rele(uStack_3e);
  }
  return iVar3;
}
/* GHIDRADEC_FUNCTION index=2941 start=0x404c44a */

undefined4 sub_404C44A(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0xc);
  return 0;
}
/* GHIDRADEC_FUNCTION index=2942 start=0x404c460 */

int sub_404C460(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  int iStack_42;
  undefined4 uStack_3e;
  undefined4 uStack_3a;
  undefined4 uStack_36;
  undefined4 uStack_32;
  int iStack_2e;
  undefined auStack_20 [28];
  
  pcVar3 = (char *)(*(int *)(param_1 + 8) + param_1);
  pcVar9 = pcVar3;
  do {
    if ((char *)(*(int *)(param_1 + 4) + param_1) <= pcVar9) {
      return 2;
    }
    cVar2 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar2 != '\0');
  iVar4 = sub_404C5D6(pcVar3,auStack_20,&uStack_36,&uStack_3a,&uStack_3e);
  if (iVar4 == 0) {
    uVar5 = _pmap_create(uStack_3a,*(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 0x14),1
                        );
    iVar4 = _vm_map_create(uVar5);
    _bzero(&uStack_32,0x12);
    uStack_32 = 0;
    iVar6 = sub_404BC42(uStack_3e,iVar4,auStack_20,uStack_36,uStack_3a,param_3,0,&uStack_32);
    if (iVar6 == 0) {
      if (*(int *)(iVar4 + 0x18) < 1) {
        iVar6 = 4;
      }
      else {
        iVar1 = *(int *)(*(int *)(iVar4 + 0xc) + 8);
        iVar8 = *(int *)(*(int *)(iVar4 + 8) + 0xc) - iVar1;
        iStack_42 = iVar1;
        iVar7 = _vm_map_find(param_2,0,0,&iStack_42,iVar8,0);
        if (((iVar7 != 0) && (iVar7 = _vm_map_find(param_2,0,0,&iStack_42,iVar8,1), iVar7 != 0)) ||
           (iVar8 = _vm_map_copy(param_2,iVar4,iStack_42,iVar8,iVar1,0,0), iVar8 != 0)) {
          iVar6 = 5;
        }
        if (iVar1 != iStack_42) {
          iStack_2e = (iStack_42 - iVar1) + iStack_2e;
        }
      }
      if (iVar6 == 0) {
        *(byte *)(param_4 + 0x10) = *(byte *)(param_4 + 0x10) | 0x40;
        *(int *)(param_4 + 4) = iStack_2e;
      }
    }
    _vm_map_deallocate(iVar4);
    _vn_rele(uStack_3e);
    return iVar6;
  }
  return iVar4;
}
/* GHIDRADEC_FUNCTION index=2943 start=0x404c5d6 */

int sub_404C5D6(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
               undefined4 *param_5)

{
  int iVar1;
  int *piStack_38;
  int iStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined auStack_18 [8];
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  iVar1 = _lookupname(param_1,1,1,0,&piStack_38);
  if (iVar1 != 0) {
    return 4;
  }
  iVar1 = _check_exec_access(piStack_38);
  if (iVar1 != 0) {
    iVar1 = 6;
    goto loc_404C742;
  }
  iVar1 = _vn_rdwr(0,piStack_38,&iStack_34,0x1c,0,1,1,0);
  if (iVar1 == 0) {
    if (iStack_34 == -0x1120532) {
      *param_2 = 0xfeedface;
      param_2[1] = uStack_30;
      param_2[2] = uStack_2c;
      param_2[3] = uStack_28;
      param_2[4] = uStack_24;
      param_2[5] = uStack_20;
      param_2[6] = uStack_1c;
      *param_3 = 0;
      *param_4 = *(undefined4 *)(*piStack_38 + 0x14);
loc_404C736:
      *param_5 = piStack_38;
      return 0;
    }
    if ((iStack_34 == -0x35014542) || (iStack_34 == -0x41450136)) {
      iVar1 = _fatfile_getarch(piStack_38,&iStack_34,auStack_18);
      if (iVar1 != 0) goto loc_404C742;
      iVar1 = _vn_rdwr(0,piStack_38,&iStack_34,0x1c,uStack_10,1,1,0);
      if (iVar1 != 0) goto loc_404C6D6;
      if (iStack_34 == -0x1120532) {
        *param_2 = 0xfeedface;
        param_2[1] = uStack_30;
        param_2[2] = uStack_2c;
        param_2[3] = uStack_28;
        param_2[4] = uStack_24;
        param_2[5] = uStack_20;
        param_2[6] = uStack_1c;
        *param_3 = uStack_10;
        *param_4 = uStack_c;
        goto loc_404C736;
      }
    }
    iVar1 = 2;
  }
  else {
loc_404C6D6:
    iVar1 = 4;
  }
loc_404C742:
  _vn_rele(piStack_38);
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=2944 start=0x404c758 */

void sub_404C758(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uStack_8;
  
  if (*(sword *)(*(int *)(_active_u + 0x1a) + 2) == 0) {
    uVar3 = *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x18);
    *(uint *)(param_1 + 0x18) = uVar3;
    if ((((-1 < *(int *)(param_1 + 0x14)) && (0x2b < uVar3)) &&
        (uVar5 = (uint)*(sword *)(param_1 + 0x2e), 0x14 < uVar5)) && (uVar5 <= uVar3 - 0x18)) {
      uStack_8 = 0;
      iVar6 = param_1 + 0x2c;
      puVar1 = &uStack_8;
      puVar2 = _mfree;
      for (; _mfree = puVar2, 0 < (int)uVar5; uVar5 = uVar5 - uVar3) {
        if (puVar2 == (undefined4 *)0x0) {
          puVar2 = (undefined4 *)_m_more(1,1);
        }
        else {
          if (*(sword *)((int)puVar2 + 10) != 0) {
                    /* WARNING: Subroutine does not return */
            _panic(&aMget);
          }
          *(undefined2 *)((int)puVar2 + 10) = 1;
          word_40B61CC = word_40B61CC + -1;
          word_40B61CE = word_40B61CE + 1;
          _mfree = (undefined4 *)*puVar2;
          *puVar2 = 0;
          puVar2[1] = 0xc;
        }
        if (puVar2 == (undefined4 *)0x0) {
          _m_freem(uStack_8);
          return;
        }
        uVar3 = _m68k_page_size;
        if ((int)_m68k_page_size < 0) {
          uVar3 = _m68k_page_size + 1;
        }
        if ((int)uVar5 < (int)uVar3 >> 1) {
loc_404C8BE:
          uVar3 = 0x70;
          if ((int)uVar5 < 0x71) {
loc_404C8C4:
            uVar3 = uVar5;
          }
        }
        else {
          if (_mclfree == (undefined4 *)0x0) {
            _m_clalloc(1,1,0);
          }
          if (_mclfree == (undefined4 *)0x0) {
            *(undefined2 *)(puVar2 + 2) = 0x70;
          }
          else {
            _mclrefcnt[(int)_mclfree - _mbutl >> 10] =
                 _mclrefcnt[(int)_mclfree - _mbutl >> 10] + '\x01';
            dword_40B61BC = dword_40B61BC + -1;
            iVar4 = (int)_mclfree - (int)puVar2;
            _mclfree = (undefined4 *)*_mclfree;
            puVar2[1] = iVar4;
            *(undefined2 *)(puVar2 + 2) = 0x400;
            *(undefined2 *)(puVar2 + 3) = 1;
          }
          uVar3 = (uint)*(sword *)(puVar2 + 2);
          if (uVar3 != _m68k_page_size) goto loc_404C8BE;
          if ((int)uVar5 < (int)uVar3) goto loc_404C8C4;
        }
        *(sword *)(puVar2 + 2) = (sword)uVar3;
        _bcopy(iVar6,puVar2[1] + (int)puVar2,uVar3);
        iVar6 = uVar3 + iVar6;
        *puVar1 = puVar2;
        puVar1 = puVar2;
        puVar2 = _mfree;
      }
      if (dword_40AF8B0 != *(int *)(param_1 + 0x3c)) {
        if (dword_40AF8A8 != 0) {
          if (*(sword *)(dword_40AF8A8 + 0x26) == 1) {
            _rtfree(dword_40AF8A8);
          }
          else {
            *(sword *)(dword_40AF8A8 + 0x26) = *(sword *)(dword_40AF8A8 + 0x26) + -1;
          }
        }
        dword_40AF8A8 = 0;
      }
      _ip_output(uStack_8,0,&dword_40AF8A8,0x21);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2945 start=0x404e00e */

undefined4 sub_404E00E(char *param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  
  while ((((*param_1 != '\0' && (cVar1 = *param_2, cVar1 != ' ')) && (1 < (byte)(cVar1 - 9U))) &&
         (cVar1 != '\0'))) {
    param_2 = param_2 + 1;
    cVar2 = *param_1;
    param_1 = param_1 + 1;
    if (cVar1 != cVar2) {
      return 1;
    }
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=2946 start=0x404e046 */

undefined4 sub_404E046(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  int *piVar4;
  bool bVar5;
  
  piVar4 = (int *)0x0;
  puVar3 = _miniMonCommands;
  iVar1 = _miniMonCommands._0_4_;
  while (iVar1 != 0) {
    iVar1 = sub_404E00E(*(int *)puVar3,param_1);
    if ((iVar1 == 0) && (bVar5 = piVar4 != (int *)0x0, piVar4 = (int *)puVar3, bVar5))
    goto loc_404E0B0;
    puVar3 = (undefined *)((int)puVar3 + 0xc);
    iVar1 = *(int *)puVar3;
  }
  puVar3 = _miniMonMDCommands;
  iVar1 = _miniMonMDCommands._0_4_;
  while (iVar1 != 0) {
    iVar1 = sub_404E00E(*(int *)puVar3,param_1);
    if ((iVar1 == 0) && (bVar5 = piVar4 != (int *)0x0, piVar4 = (int *)puVar3, bVar5))
    goto loc_404E0B0;
    puVar3 = (undefined *)((int)puVar3 + 0xc);
    iVar1 = *(int *)puVar3;
  }
  if (piVar4 != (int *)0x0) {
    uVar2 = (*(code *)piVar4[1])(param_1);
    return uVar2;
  }
  puVar3 = aInvalidCommand;
loc_404E0B6:
  _safe_prf(puVar3);
  return 1;
loc_404E0B0:
  puVar3 = aAmbiguousComma;
  goto loc_404E0B6;
}
/* GHIDRADEC_FUNCTION index=2947 start=0x404e0d2 */

void sub_404E0D2(undefined *param_1,int param_2)

{
  int iVar1;
  undefined *puVar2;
  
  param_2 = param_2 + -1;
  puVar2 = param_1;
loc_404E0EC:
  do {
    iVar1 = _miniMonGetchar();
    if (iVar1 == 10) {
loc_404E11A:
      *puVar2 = 0;
      return;
    }
    if (10 < iVar1) {
      if (iVar1 == 0xd) {
        _miniMonPutchar(10);
        goto loc_404E11A;
      }
      if (iVar1 == 0x15) {
        _miniMonPutchar(10);
        puVar2 = param_1;
      }
      else {
loc_404E148:
        if (param_2 == 0) {
          _miniMonPutchar(8);
          _miniMonPutchar(0x20);
          _miniMonPutchar(8);
        }
        else {
          *puVar2 = (char)iVar1;
          param_2 = param_2 + -1;
          puVar2 = puVar2 + 1;
        }
      }
      goto loc_404E0EC;
    }
    if (iVar1 != 8) goto loc_404E148;
    _miniMonPutchar(0x20);
    if (param_1 != puVar2) {
      _miniMonPutchar(8);
      param_2 = param_2 + 1;
      puVar2 = puVar2 + -1;
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2948 start=0x404e458 */

undefined4 sub_404E458(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  sqword sVar8;
  
  sVar8 = _clock_value(1);
  uVar3 = (uint)((qword)sVar8 >> 0x20);
  uVar5 = (uint)sVar8;
  do {
    if (_ns_calltodo == (undefined4 *)0x0) {
loc_404E510:
      puVar4 = (uint *)_timer_attributes(0);
      goto loc_404E518;
    }
    do {
      puVar2 = _ns_calltodo;
      if (uVar3 <= (uint)_ns_calltodo[1] &&
          (uVar5 <= (uint)_ns_calltodo[2] || _ns_calltodo[1] != uVar3)) break;
      if ((code *)_ns_calltodo[4] == _m68k_hardclock) {
        _hardclock_ps = param_3;
        _hardclock_pc = param_2;
      }
      _callout_dispatch(_ns_calltodo[5],_ns_calltodo[4],_ns_calltodo[3]);
      _ns_calltodo = (undefined4 *)*puVar2;
      *puVar2 = _ns_callfree;
      _ns_callfree = puVar2;
    } while (_ns_calltodo != (undefined4 *)0x0);
    if (_ns_calltodo == (undefined4 *)0x0) goto loc_404E510;
    uVar6 = _ns_calltodo[1];
    uVar1 = _ns_calltodo[2];
  } while ((uVar6 <= uVar3 && (uVar5 >= uVar1 || uVar3 != uVar6)) &&
           sVar8 != CONCAT44((uVar5 < uVar1) + uVar6,uVar1));
  uVar7 = uVar1 - uVar5;
  uVar6 = uVar6 - ((uVar1 < uVar5) + uVar3);
  puVar4 = (uint *)_timer_attributes(0);
  if (*puVar4 < uVar6 || puVar4[1] < uVar7 && *puVar4 == uVar6) {
    puVar4 = (uint *)_timer_attributes(0);
loc_404E518:
    uVar6 = *puVar4;
    uVar7 = puVar4[1];
  }
  __set_timer(0,uVar6,uVar7);
  return 0;
}
/* GHIDRADEC_FUNCTION index=2949 start=0x404eaae */

int sub_404EAAE(undefined4 *param_1)

{
  int iVar1;
  undefined4 uStack_8;
  
  iVar1 = _PMGetPowerEvent(&uStack_8);
  if (iVar1 == 0) {
    switch(uStack_8) {
    case :
    case :
      dword_40B39C2 = 1;
      _PMSetPowerState(0x10000,1);
      break;
    case :
    case :
    case :
      dword_40B39C2 = 2;
      _PMSetPowerState(0x10000,2);
      dword_40B39C2 = 0;
      _PMSetPowerState(0x10000,0);
      break;
    case :
    case :
    case :
      if (dword_40B39C2 != 0) {
        dword_40B39C2 = 0;
        _PMSetPowerState(0x10000,0);
      }
    case :
      _PMUpdateClock();
    }
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = uStack_8;
    }
  }
  return iVar1;
}

