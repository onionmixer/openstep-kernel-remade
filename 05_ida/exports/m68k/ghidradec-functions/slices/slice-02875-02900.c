/* GHIDRADEC_FUNCTION index=2875 start=0x4030cec */

undefined4 sub_4030CEC(int param_1,uint param_2,int param_3)

{
  int iVar1;
  sword sVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x2e);
  if (param_3 < 2) {
    if (((param_2 & 1) != 0) &&
       (sVar2 = *(sword *)(iVar1 + 0x80), *(sword *)(iVar1 + 0x80) = sVar2 + -1, sVar2 == 1)) {
      if ((*(word *)(iVar1 + 0x86) & 2) != 0) {
        *(word *)(iVar1 + 0x86) = *(word *)(iVar1 + 0x86) & 0xfffd;
        _wakeup(iVar1 + 0x7e);
      }
      if (*(int *)(iVar1 + 0x76) != 0) {
        _selwakeup(*(int *)(iVar1 + 0x76),*(byte *)(iVar1 + 0x87) & 0x10);
        _thread_deallocate(*(undefined4 *)(iVar1 + 0x76));
        *(word *)(iVar1 + 0x86) = *(word *)(iVar1 + 0x86) & 0xffef;
        *(undefined4 *)(iVar1 + 0x76) = 0;
      }
    }
    if (*(int *)(iVar1 + 0x72) != 0) {
      _thread_deallocate(*(int *)(iVar1 + 0x72));
      *(undefined4 *)(iVar1 + 0x72) = 0;
    }
    if (*(int *)(iVar1 + 0x6e) != 0) {
      _thread_deallocate(*(int *)(iVar1 + 0x6e));
      *(undefined4 *)(iVar1 + 0x6e) = 0;
    }
    if ((((param_2 & 2) != 0) &&
        (sVar2 = *(sword *)(iVar1 + 0x7e), *(sword *)(iVar1 + 0x7e) = sVar2 + -1, sVar2 == 1)) &&
       ((*(word *)(iVar1 + 0x86) & 1) != 0)) {
      *(word *)(iVar1 + 0x86) = *(word *)(iVar1 + 0x86) & 0xfffe;
      _wakeup(iVar1 + 0x80);
    }
    if ((*(sword *)(iVar1 + 0x80) == 0) && (*(sword *)(iVar1 + 0x7e) == 0)) {
      for (iVar3 = *(int *)(iVar1 + 0x66); iVar3 != 0; iVar3 = sub_40315CE(iVar3,iVar1)) {
      }
      if (*(int *)(iVar1 + 0x7a) != 0) {
        _smark(iVar1,0x42);
      }
      *(undefined4 *)(iVar1 + 0x66) = 0;
      *(undefined2 *)(iVar1 + 0x84) = 0;
      *(undefined2 *)(iVar1 + 0x82) = 0;
      *(undefined4 *)(iVar1 + 0x7a) = 0;
    }
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=2876 start=0x40314a2 */

undefined4 sub_40314A2(undefined4 *param_1)

{
  word wVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uStack_8;
  
  if (_fifo_alloc < dword_40AF744) {
    _fifo_alloc = dword_40AF740 + _fifo_alloc;
    _kmem_alloc_wired(_kernel_map,&uStack_8,dword_40AF740);
    *(sword *)(param_1 + 0x22) = *(sword *)(param_1 + 0x22) + 1;
  }
  else {
    wVar1 = *(word *)((int)param_1 + 0x3e);
    *(word *)((int)param_1 + 0x3e) = wVar1 & 0xfffe;
    if ((wVar1 & 0x10) != 0) {
      *(word *)((int)param_1 + 0x3e) = wVar1 & 0xffee;
      _wakeup(param_1);
    }
    uVar3 = 0x1a;
    puVar2 = &_fifo_alloc;
    while( true ) {
      _sleep(puVar2,uVar3);
      if ((*(word *)((int)param_1 + 0x3e) & 1) == 0) break;
      *(word *)((int)param_1 + 0x3e) = *(word *)((int)param_1 + 0x3e) | 0x10;
      uVar3 = 10;
      puVar2 = param_1;
    }
    *(word *)((int)param_1 + 0x3e) = *(word *)((int)param_1 + 0x3e) | 1;
    uStack_8 = 0;
  }
  return uStack_8;
}
/* GHIDRADEC_FUNCTION index=2877 start=0x40315ce */

undefined4 sub_40315CE(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  *(sword *)(param_2 + 0x88) = *(sword *)(param_2 + 0x88) + -1;
  if (param_1 == *(undefined4 **)(param_2 + 0x6a)) {
    *(undefined4 *)(param_2 + 0x6a) = 0;
    uVar1 = 0;
  }
  else {
    uVar1 = *param_1;
  }
  _kmem_free(_kernel_map,param_1,dword_40AF740);
  if (dword_40AF744 <= _fifo_alloc) {
    _wakeup(&_fifo_alloc);
  }
  _fifo_alloc = _fifo_alloc - dword_40AF740;
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2878 start=0x40318ce */

void sub_40318CE(undefined4 *param_1)

{
  *param_1 = *(undefined4 *)
              (_stable +
              ((*(word *)(param_1 + 0x10) & 0xff) + (uint)(*(word *)(param_1 + 0x10) >> 8) & 0xf) *
              4);
  *(undefined4 **)
   (_stable +
   ((*(word *)(param_1 + 0x10) & 0xff) + (uint)(*(word *)(param_1 + 0x10) >> 8) & 0xf) * 4) =
       param_1;
  return;
}
/* GHIDRADEC_FUNCTION index=2879 start=0x4031ade */

undefined4 * sub_4031ADE(word param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = *(undefined4 **)(_stable + ((uint)(byte)param_1 + (uint)(param_1 >> 8) & 0xf) * 4);
  do {
    if (puVar1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    if ((param_1 == *(word *)(puVar1 + 0x10)) && (param_3 == puVar1[0xb])) {
      iVar2 = *(int *)((int)puVar1 + 0x36);
      if (iVar2 != 0) {
        if (param_2 != 0) {
          if (param_2 == iVar2) goto loc_4031B52;
          if (iVar2 == 0) goto loc_4031B4E;
          if ((*(int *)(iVar2 + 0x1c) == *(int *)(param_2 + 0x1c)) &&
             (iVar2 = (**(code **)(*(int *)(iVar2 + 0x1c) + 0x6c))(iVar2,param_2), iVar2 != 0))
          goto loc_4031B52;
        }
        if (*(int *)((int)puVar1 + 0x36) != 0) goto loc_4031B5A;
      }
loc_4031B4E:
      if (param_2 == 0) {
loc_4031B52:
        *(sword *)((int)puVar1 + 10) = *(sword *)((int)puVar1 + 10) + 1;
        return puVar1;
      }
    }
loc_4031B5A:
    puVar1 = (undefined4 *)*puVar1;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2880 start=0x403272a */

void sub_403272A(int param_1,int param_2,uint param_3,uint param_4)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)(param_2 + *(int *)(param_1 + 0x14));
  *pbVar1 = (byte)((1 << (param_3 & 0x3f)) + -1 << (param_4 & 0x3f)) | *pbVar1;
  return;
}
/* GHIDRADEC_FUNCTION index=2881 start=0x4032752 */

uint sub_4032752(int *param_1,uint param_2,uint *param_3,int *param_4)

{
  uint uVar1;
  
  uVar1 = param_2 / _page_size;
  if (uVar1 < (uint)param_1[1]) {
    if ((*(byte *)(param_1[3] + 3 + uVar1 * 4) & 0xf0) != 0) {
      *param_3 = _page_size * (*(uint *)(param_1[3] + uVar1 * 4) >> 8);
      *param_4 = *param_1 * (*(byte *)(param_1[3] + 3 + uVar1 * 4) & 0xf);
      return *param_1 * (*(uint *)(param_1[3] + 3 + uVar1 * 4) >> 0x1c);
    }
    _printf(aPageinFromUnin);
  }
  else if (_swapfs_cangrow == 1) {
                    /* WARNING: Subroutine does not return */
    _panic(aPagingInBeyond);
  }
  *param_3 = param_2;
  *param_4 = 0;
  return _page_size;
}
/* GHIDRADEC_FUNCTION index=2882 start=0x40327f0 */

uint sub_40327F0(int param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  byte *pbVar5;
  
  uVar4 = 0;
  if (*(int *)(param_1 + 0x1c) != 0) {
    do {
      if (*(char *)(uVar4 + *(int *)(param_1 + 0x14)) == -1) {
        *param_3 = uVar4;
        pbVar5 = (byte *)(*(int *)(param_1 + 0x14) + uVar4);
        bVar3 = *pbVar5;
        if (bVar3 == 0) {
          return 0xffffffff;
        }
        uVar2 = (1 << (param_2 & 0x3f)) - 1;
        uVar4 = 0;
        if (-param_2 == -9) {
          return 0xffffffff;
        }
        do {
          uVar1 = uVar2 & bVar3;
          if (uVar2 == uVar1) {
            *pbVar5 = ~(byte)(uVar1 << (uVar4 & 0x3f)) & *pbVar5;
            return uVar4;
          }
          bVar3 = bVar3 >> 1;
          uVar4 = uVar4 + 1;
        } while (uVar4 < -param_2 + 9);
        return 0xffffffff;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(param_1 + 0x1c));
  }
  return 0xffffffff;
}
/* GHIDRADEC_FUNCTION index=2883 start=0x4032872 */

undefined4 sub_4032872(uint *param_1,uint param_2,uint param_3,int *param_4,int *param_5)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  byte *pbVar5;
  uint uStack_8;
  
  param_2 = param_2 / _page_size;
  param_3 = param_3 / *param_1;
  bVar4 = *(byte *)(param_1[3] + 3 + param_2 * 4);
  if ((bVar4 & 0xf0) == 0) {
    sub_403272A(param_1,param_2,8,0);
    if (param_1[7] <= param_2) {
      dword_40B35EA = param_2 + 1;
      param_1[7] = dword_40B35EA;
    }
  }
  else {
    sub_403272A(param_1,*(uint *)(param_1[3] + param_2 * 4) >> 8,bVar4 >> 4,bVar4 & 0xf);
  }
  uVar3 = param_1[8];
  if ((param_1[0xb] / _page_size == uVar3) || (*(uint *)((int)param_1 + 0x3e) / _page_size == uVar3)
     ) {
    pbVar5 = (byte *)(uVar3 + param_1[5]);
    bVar4 = *pbVar5;
    if (bVar4 != 0) {
      uVar2 = (1 << (param_3 & 0x3f)) - 1;
      uVar3 = 0;
      if (-param_3 != -9) {
        do {
          if (uVar2 == (uVar2 & bVar4)) {
            *pbVar5 = ~(byte)(uVar2 << (uVar3 & 0x3f)) & *pbVar5;
            goto loc_4032956;
          }
          bVar4 = bVar4 >> 1;
          uVar3 = uVar3 + 1;
        } while (uVar3 < -param_3 + 9);
      }
    }
  }
  else {
    uVar3 = 0xffffffff;
loc_4032956:
    if (-1 < (int)uVar3) {
      uStack_8 = param_1[8];
      dword_40B35DE = dword_40B35DE + 1;
      goto loc_4032980;
    }
  }
  uVar3 = sub_40327F0(param_1,param_3,&uStack_8);
  if ((int)uVar3 < 0) {
    return 0;
  }
  dword_40B35E2 = dword_40B35E2 + 1;
loc_4032980:
  if ((int)uVar3 < 0) {
    return 0;
  }
  *(uint *)(param_1[3] + param_2 * 4) =
       CONCAT31((int3)uStack_8,*(undefined *)(param_1[3] + 3 + param_2 * 4));
  puVar1 = (uint *)(param_1[3] + 3 + param_2 * 4);
  *puVar1 = *puVar1 & 0xf0ffffff | (uVar3 & 0xf) << 0x18;
  puVar1 = (uint *)(param_1[3] + 3 + param_2 * 4);
  *puVar1 = *puVar1 & 0xfffffff | param_3 << 0x1c;
  *param_4 = _page_size * uStack_8;
  *param_5 = *param_1 * uVar3;
  if (_page_size / *param_1 != param_3) {
    param_1[8] = uStack_8;
  }
  if (unk_40B35E6 < uStack_8) {
    unk_40B35E6 = uStack_8;
  }
  return 1;
}
/* GHIDRADEC_FUNCTION index=2884 start=0x4032aca */

void sub_4032ACA(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x2e);
  if ((*(byte *)(iVar1 + 0x75) & 1) != 0) {
    do {
      *(byte *)(iVar1 + 0x75) = *(byte *)(iVar1 + 0x75) | 2;
      _sleep((byte *)(iVar1 + 0x75),10);
    } while ((*(byte *)(iVar1 + 0x75) & 1) != 0);
  }
  *(byte *)(iVar1 + 0x75) = *(byte *)(iVar1 + 0x75) | 1;
  return;
}
/* GHIDRADEC_FUNCTION index=2885 start=0x4032b16 */

void sub_4032B16(int param_1)

{
  int iVar1;
  byte bVar2;
  
  iVar1 = *(int *)(param_1 + 0x2e);
  bVar2 = *(byte *)(iVar1 + 0x75);
  *(byte *)(iVar1 + 0x75) = bVar2 & 0xfe;
  if ((bVar2 & 2) != 0) {
    *(byte *)(iVar1 + 0x75) = bVar2 & 0xfc;
    _wakeup(iVar1 + 0x75);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2886 start=0x4032b4c */

void sub_4032B4C(int param_1,int param_2)

{
  if (param_2 == *(int *)(param_1 + 0x3e)) {
    dword_40B35CE = dword_40B35CE + 1;
    *(undefined4 *)(param_1 + 0x3e) = 0xffffffff;
  }
  if (param_2 == *(int *)(param_1 + 0x2c)) {
    dword_40B35D2 = dword_40B35D2 + 1;
    *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
    *(undefined *)(param_1 + 0x30) = 0;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2887 start=0x4032b84 */

void sub_4032B84(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  if (*(uint *)(*param_1 + 0x14) < (uint)(param_3 + param_4)) {
    *(int *)(*param_1 + 0x14) = param_3 + param_4;
  }
  (**(code **)(param_1[7] + 0x78))(param_1,param_2,param_3,param_4);
  return;
}
/* GHIDRADEC_FUNCTION index=2888 start=0x4032bc2 */

int sub_4032BC2(int param_1,int *param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  undefined auStack_32 [34];
  undefined4 uStack_10;
  
  dword_40B35AE = dword_40B35AE + 1;
  if (param_4 == *(int *)(param_1 + 0x2c)) {
    dword_40B35B2 = dword_40B35B2 + 1;
    iVar1 = *(int *)(param_1 + 0x24);
  }
  else {
    if (param_4 != *(int *)(param_1 + 0x3e)) {
      if (*(char *)(param_1 + 0x30) != '\0') {
        dword_40B35BA = dword_40B35BA + 1;
        iVar1 = sub_4032B84(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x28),_page_size,
                            *(undefined4 *)(param_1 + 0x2c));
        if (iVar1 != 0) {
          _printf(aCannotFlushInp);
          return iVar1;
        }
        *(undefined *)(param_1 + 0x30) = 0;
      }
      *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
      uStack_10 = *(undefined4 *)(param_1 + 0x28);
      iVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 8) + 0x1c) + 0x74))
                        (*(int *)(param_1 + 8),auStack_32,param_4);
      if (iVar1 != 0) {
        return iVar1;
      }
      *(int *)(param_1 + 0x2c) = param_4;
      *param_2 = *(int *)(param_1 + 0x24) + param_5;
      return 0;
    }
    dword_40B35B6 = dword_40B35B6 + 1;
    iVar1 = *(int *)(param_1 + 0x32);
  }
  *param_2 = iVar1 + param_5;
  return 0;
}
/* GHIDRADEC_FUNCTION index=2889 start=0x4032c82 */

int sub_4032C82(int param_1,undefined2 *param_2,undefined4 param_3,uint param_4,int param_5)

{
  int iVar1;
  
  dword_40B35BE = dword_40B35BE + 1;
  *param_2 = (sword)(param_4 >> 0xd);
  if (*(uint *)(param_1 + 0x3e) == param_4) {
    dword_40B35C2 = dword_40B35C2 + 1;
    _compress_backoff_cnt = _compress_backoff_cnt + 1;
    _bcopy(param_2,*(int *)(param_1 + 0x32) + param_5,param_3);
    if (param_4 == *(uint *)(param_1 + 0x2c)) {
      _swpgotcha = _swpgotcha + 1;
      *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
      *(undefined *)(param_1 + 0x30) = 0;
    }
  }
  else if (param_4 == *(uint *)(param_1 + 0x2c)) {
    dword_40B35C6 = dword_40B35C6 + 1;
    _compress_backoff_cnt = _compress_backoff_cnt + 1;
    _bcopy(param_2,*(int *)(param_1 + 0x24) + param_5,param_3);
    *(undefined *)(param_1 + 0x30) = 1;
  }
  else {
    if (*(uint *)(param_1 + 0x3e) != 0xffffffff) {
      dword_40B35CA = dword_40B35CA + 1;
      iVar1 = sub_4032B84(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x36),_page_size,
                          *(undefined4 *)(param_1 + 0x3e));
      if (iVar1 != 0) {
        _printf(aCannotFlushOut);
        return iVar1;
      }
    }
    *(uint *)(param_1 + 0x3e) = param_4;
    _bcopy(param_2,*(int *)(param_1 + 0x32) + param_5,param_3);
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=2890 start=0x4032f00 */

undefined4 sub_4032F00(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  iVar1 = *(int *)(param_1 + 0x2e);
  uVar4 = _page_size * (*(int *)(iVar1 + 0x42) + 1);
  iVar2 = _kmem_mb_alloc(_swapfs_rem_map,_page_size);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    if (*(int *)(iVar1 + 0x3e) + _page_size * *(int *)(iVar1 + 0x42) != iVar2) {
                    /* WARNING: Subroutine does not return */
      _panic(aSwapfsGrowBadR);
    }
    *(uint *)(iVar1 + 0x36) = uVar4 >> 2;
    *(int *)(iVar1 + 0x42) = *(int *)(iVar1 + 0x42) + 1;
    if ((uint)(_page_size * *(int *)(iVar1 + 0x4a)) < *(uint *)(iVar1 + 0x36)) {
      iVar2 = _kmem_mb_alloc(_swapfs_bit_map,_page_size);
      if (iVar2 == 0) {
        iVar2 = *(int *)(iVar1 + 0x42);
        *(int *)(iVar1 + 0x42) = iVar2 + -1;
        *(uint *)(iVar1 + 0x36) = (uint)(_page_size * (iVar2 + -1)) >> 2;
        return 0;
      }
      if (*(int *)(iVar1 + 0x46) + *(int *)(iVar1 + 0x4a) * _page_size != iVar2) {
                    /* WARNING: Subroutine does not return */
        _panic(aSwapfsGrowBadF);
      }
      *(int *)(iVar1 + 0x4a) = *(int *)(iVar1 + 0x4a) + 1;
    }
    uVar3 = 1;
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=2891 start=0x4033286 */

void sub_4033286(undefined2 *param_1,undefined2 param_2,undefined2 param_3,undefined4 param_4)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  *(undefined4 *)(param_1 + 2) = param_4;
  return;
}
/* GHIDRADEC_FUNCTION index=2892 start=0x4035ba6 */

int sub_4035BA6(int param_1,char *param_2,uint param_3,int *param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  int iVar9;
  uint uStack_8;
  
  iVar5 = 0;
  iVar9 = 0;
  uVar4 = 0;
  iVar2 = (param_3 + 4 & 0xfffffffc) + 8;
  uVar6 = *(int *)(param_1 + 0x6e) + 0x3ffU & 0xfffffc00;
  uStack_8 = 0;
  uVar3 = 0;
  if (uVar6 != 0) {
    do {
      if ((uVar3 & ~*(uint *)(*(int *)(param_1 + 0x4e) + 0x48)) == 0) {
        if (iVar9 != 0) {
          _brelse(iVar9);
        }
        iVar9 = _blkatoff(param_1,uVar3,0);
        if (iVar9 == 0) goto loc_4035D3A;
        uVar4 = 0;
      }
      if ((*param_4 == 0) && ((uVar4 & 0x3ff) == 0)) {
        param_4[1] = -1;
        iVar5 = 0;
      }
      piVar8 = (int *)(uVar4 + *(int *)(iVar9 + 0x20));
      if ((*(sword *)(piVar8 + 1) == 0) ||
         (iVar1 = sub_4036A22(param_1,piVar8,uVar4,uVar3), iVar1 != 0)) {
        uVar7 = 0x400 - (uVar4 & 0x3ff);
      }
      else {
        if (*param_4 != 2) {
          uVar7 = (uint)*(word *)(piVar8 + 1);
          if (*piVar8 != 0) {
            uVar7 = (uVar7 - 8) - (*(word *)((int)piVar8 + 6) + 4 & 0xfffffffc);
          }
          if (0 < (int)uVar7) {
            if ((int)uVar7 < iVar2) {
              if (*param_4 == 0) {
                iVar5 = uVar7 + iVar5;
                if (param_4[1] == -1) {
                  param_4[1] = uVar3;
                }
                if (iVar2 <= iVar5) {
                  *param_4 = 1;
                  uVar7 = (uVar3 + *(word *)(piVar8 + 1)) - param_4[1];
                  goto loc_4035CCC;
                }
              }
            }
            else {
              *param_4 = 2;
              param_4[1] = uVar3;
              uVar7 = (uint)*(word *)(piVar8 + 1);
loc_4035CCC:
              param_4[2] = uVar7;
            }
          }
        }
        if ((((*piVar8 != 0) && (*(word *)((int)piVar8 + 6) == param_3)) &&
            (*param_2 == *(char *)(piVar8 + 2))) &&
           (iVar1 = _bcmp(param_2,piVar8 + 2,param_3), iVar1 == 0)) {
          *(uint *)(param_1 + 0x4a) = uVar3;
          if (*piVar8 == *(int *)(param_1 + 0x46)) {
            *param_5 = param_1;
            *(sword *)(param_1 + 0x12) = *(sword *)(param_1 + 0x12) + 1;
          }
          else {
            iVar2 = _iget((int)*(sword *)(param_1 + 0x44),*(undefined4 *)(param_1 + 0x4e),*piVar8);
            *param_5 = iVar2;
            if (iVar2 == 0) {
              _brelse(iVar9);
loc_4035D3A:
              return (int)*(char *)(dword_40B57D4 + 100);
            }
          }
          *param_4 = 3;
          param_4[1] = uVar3;
          param_4[2] = uVar3 - uStack_8;
          param_4[3] = iVar9;
          param_4[4] = (int)piVar8;
          return 0;
        }
        uVar7 = (uint)*(word *)(piVar8 + 1);
        uStack_8 = uVar3;
      }
      uVar3 = uVar7 + uVar3;
      uVar4 = uVar7 + uVar4;
    } while (uVar3 < uVar6);
  }
  if (iVar9 != 0) {
    _brelse(iVar9);
  }
  if (*param_4 == 0) {
    param_4[1] = uVar6;
    param_4[2] = 0x400;
  }
  *param_5 = 0;
  return 0;
}
/* GHIDRADEC_FUNCTION index=2893 start=0x4035dae */

int sub_4035DAE(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
               int param_6,int param_7)

{
  sword sVar1;
  int iVar2;
  bool bVar3;
  
  if ((*(int *)(param_6 + 0x30) == *(int *)(param_3 + 0x30)) &&
     (*(int *)(param_6 + 0x30) == *(int *)(param_2 + 0x30))) {
    if (*(int *)(param_2 + 0x46) == *(int *)(param_6 + 0x46)) {
      iVar2 = -1;
    }
    else {
      iVar2 = _iaccess(param_3,0x80);
      if (iVar2 == 0) {
        if (((((*(byte *)(param_3 + 0x62) & 2) == 0) ||
             (sVar1 = *(sword *)(*(int *)(_active_u + 0x1a) + 2), sVar1 == 0)) ||
            (sVar1 == *(sword *)(param_3 + 0x66))) || (sVar1 == *(sword *)(param_6 + 0x66))) {
          bVar3 = (*(word *)(param_2 + 0x62) & 0xf000) != 0x4000;
          if ((*(word *)(param_6 + 0x62) & 0xf000) == 0x4000) {
            if (bVar3) {
              return 0x15;
            }
            iVar2 = sub_4036AE4(param_6,*(undefined4 *)(param_3 + 0x46));
            if ((iVar2 == 0) || (2 < *(sword *)(param_6 + 100))) {
              return 0x42;
            }
          }
          else if (!bVar3) {
            return 0x14;
          }
          _dnlc_remove(param_3 + 0xc,param_4);
          **(undefined4 **)(param_7 + 0x10) = *(undefined4 *)(param_2 + 0x46);
          _dnlc_enter(param_3 + 0xc,param_4,param_2 + 0xc,0);
          _bwrite(*(undefined4 *)(param_7 + 0xc));
          *(undefined4 *)(param_7 + 0xc) = 0;
          if (*(char *)(dword_40B57D4 + 100) == '\0') {
            *(word *)(param_3 + 0x42) = *(word *)(param_3 + 0x42) | 0x42;
            *(sword *)(param_6 + 100) = *(sword *)(param_6 + 100) + -1;
            *(word *)(param_6 + 0x42) = *(word *)(param_6 + 0x42) | 0x40;
            if (!bVar3) {
              sVar1 = *(sword *)(param_6 + 100);
              *(sword *)(param_6 + 100) = sVar1 + -1;
              if (sVar1 != 1) {
                    /* WARNING: Subroutine does not return */
                _panic(aDirenterTarget);
              }
              _itrunc(param_6,0);
              *(sword *)(param_3 + 100) = *(sword *)(param_3 + 100) + -1;
              *(word *)(param_3 + 0x42) = *(word *)(param_3 + 0x42) | 0x40;
              if ((param_3 != param_1) && (iVar2 = sub_4035F40(param_2,param_1,param_3), iVar2 != 0)
                 ) {
                return iVar2;
              }
            }
            iVar2 = 0;
          }
          else {
            iVar2 = (int)*(char *)(dword_40B57D4 + 100);
          }
        }
        else {
          iVar2 = 1;
        }
      }
    }
  }
  else {
    iVar2 = 0x12;
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=2894 start=0x4035f40 */

int sub_4035F40(int param_1,int param_2,int param_3)

{
  word wVar1;
  int iVar2;
  int iVar3;
  int iStack_8;
  
  iVar3 = 0;
  while ((*(word *)(param_1 + 0x42) & 1) != 0) {
    *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x10;
    _sleep(param_1,10);
  }
  wVar1 = *(word *)(param_1 + 0x42);
  *(word *)(param_1 + 0x42) = wVar1 | 1;
  if ((*(sword *)(param_1 + 100) == 0) || (*(uint *)(param_1 + 0x6e) < 0x18)) {
    *(word *)(param_1 + 0x42) = wVar1 & 0xfffe;
    if ((wVar1 & 0x10) != 0) {
      *(word *)(param_1 + 0x42) = wVar1 & 0xffee;
      _wakeup(param_1);
    }
loc_403616A:
    iVar3 = 0;
  }
  else {
    iVar2 = _blkatoff(param_1,0,&iStack_8);
    if (iVar2 == 0) {
      iVar3 = (int)*(char *)(dword_40B57D4 + 100);
    }
    else if (*(int *)(iStack_8 + 0xc) != *(int *)(param_3 + 0x46)) {
      if ((*(sword *)(iStack_8 + 0x12) == 2) && (*(sword *)(iStack_8 + 0x14) == 0x2e2e)) {
        *(sword *)(param_3 + 100) = *(sword *)(param_3 + 100) + 1;
        *(word *)(param_3 + 0x42) = *(word *)(param_3 + 0x42) | 0x40;
        _iupdat(param_3,1);
        _dnlc_remove(param_1 + 0xc,&asc_40A6712);
        *(undefined4 *)(iStack_8 + 0xc) = *(undefined4 *)(param_3 + 0x46);
        _dnlc_enter(param_1 + 0xc,&asc_40A6712,param_3 + 0xc,0);
        _bwrite(iVar2);
        iVar2 = 0;
        if (*(char *)(dword_40B57D4 + 100) == '\0') {
          wVar1 = *(word *)(param_1 + 0x42);
          *(word *)(param_1 + 0x42) = wVar1 & 0xfffe;
          if ((wVar1 & 0x10) != 0) {
            *(word *)(param_1 + 0x42) = wVar1 & 0xffee;
            _wakeup(param_1);
          }
          if (param_2 != 0) {
            wVar1 = *(word *)(param_3 + 0x42);
            *(word *)(param_3 + 0x42) = wVar1 & 0xfffe;
            if ((wVar1 & 0x10) != 0) {
              *(word *)(param_3 + 0x42) = wVar1 & 0xffee;
              _wakeup(param_3);
            }
            while ((*(word *)(param_2 + 0x42) & 1) != 0) {
              *(word *)(param_2 + 0x42) = *(word *)(param_2 + 0x42) | 0x10;
              _sleep(param_2,10);
            }
            *(word *)(param_2 + 0x42) = *(word *)(param_2 + 0x42) | 1;
            if (*(sword *)(param_2 + 100) != 0) {
              *(sword *)(param_2 + 100) = *(sword *)(param_2 + 100) + -1;
              *(word *)(param_2 + 0x42) = *(word *)(param_2 + 0x42) | 0x40;
              _iupdat(param_2,1);
            }
            wVar1 = *(word *)(param_2 + 0x42);
            *(word *)(param_2 + 0x42) = wVar1 & 0xfffe;
            if ((wVar1 & 0x10) != 0) {
              *(word *)(param_2 + 0x42) = wVar1 & 0xffee;
              _wakeup(param_2);
            }
            while ((*(word *)(param_3 + 0x42) & 1) != 0) {
              *(word *)(param_3 + 0x42) = *(word *)(param_3 + 0x42) | 0x10;
              _sleep(param_3,10);
            }
            *(word *)(param_3 + 0x42) = *(word *)(param_3 + 0x42) | 1;
          }
          goto loc_403616A;
        }
        iVar3 = (int)*(char *)(dword_40B57D4 + 100);
      }
      else {
        sub_4036AAC(param_1,aMangledEntry,0);
        iVar3 = 0x16;
      }
    }
    if (iVar2 != 0) {
      _brelse(iVar2);
    }
    wVar1 = *(word *)(param_1 + 0x42);
    *(word *)(param_1 + 0x42) = wVar1 & 0xfffe;
    if ((wVar1 & 0x10) != 0) {
      *(word *)(param_1 + 0x42) = wVar1 & 0xffee;
      _wakeup(param_1);
    }
  }
  return iVar3;
}
/* GHIDRADEC_FUNCTION index=2895 start=0x403627c */

int sub_403627C(int param_1,uint *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  sword sVar6;
  int *piVar7;
  
  uVar4 = param_2[2] + param_2[1];
  if (*param_2 == 0) {
    if ((param_2[1] & 0x3ff) != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(aDirprepareentr);
    }
    if (*(int *)(*(int *)(param_1 + 0x4e) + 0x34) < 0x400) {
                    /* WARNING: Subroutine does not return */
      _panic(aDirblksizFsize);
    }
    iVar3 = _bmap(param_1,param_2[1] >> (*(uint *)(*(int *)(param_1 + 0x4e) + 0x50) & 0x3f),0,
                  (param_2[1] & ~*(uint *)(*(int *)(param_1 + 0x4e) + 0x48)) + 0x400,0);
    if ((iVar3 < 1) || (*(char *)(dword_40B57D4 + 100) != '\0')) {
      if (*(char *)(dword_40B57D4 + 100) == '\0') {
        return 0x1c;
      }
      return (int)*(char *)(dword_40B57D4 + 100);
    }
    *(uint *)(param_1 + 0x6e) = uVar4;
  }
  else {
    if (uVar4 <= *(uint *)(param_1 + 0x6e)) goto loc_4036346;
    *(uint *)(param_1 + 0x6e) = uVar4 + 0x3ff & 0xfffffc00;
  }
  *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x42;
loc_4036346:
  uVar4 = _blkatoff(param_1,param_2[1],param_2 + 4);
  param_2[3] = uVar4;
  if (uVar4 == 0) {
    iVar3 = (int)*(char *)(dword_40B57D4 + 100);
  }
  else {
    piVar2 = (int *)param_2[4];
    piVar7 = piVar2;
    if (*param_2 == 0) {
      _bzero(piVar2,0x400);
      *(undefined2 *)(piVar2 + 1) = 0x400;
    }
    else {
      if (2 < *param_2) {
                    /* WARNING: Subroutine does not return */
        _panic(aDirprepareentr_0);
      }
      iVar3 = (*(word *)((int)piVar2 + 6) + 4 & 0xfffffffc) + 8;
      iVar5 = (uint)*(word *)(piVar2 + 1) - iVar3;
      sVar6 = (sword)iVar5;
      uVar4 = (uint)*(word *)(piVar2 + 1);
      if ((int)uVar4 < (int)param_2[2]) {
        do {
          iVar1 = (int)piVar2 + uVar4;
          if (*piVar7 == 0) {
            iVar5 = iVar3 + iVar5;
          }
          else {
            *(sword *)(piVar7 + 1) = (sword)iVar3;
            piVar7 = (int *)(iVar3 + (int)piVar7);
          }
          iVar3 = (*(word *)(iVar1 + 6) + 4 & 0xfffffffc) + 8;
          iVar5 = ((uint)*(word *)(iVar1 + 4) - iVar3) + iVar5;
          sVar6 = (sword)iVar5;
          uVar4 = *(word *)(iVar1 + 4) + uVar4;
          _bcopy(iVar1,piVar7,iVar3);
        } while ((int)uVar4 < (int)param_2[2]);
      }
      if (*piVar7 == 0) {
        *(sword *)(piVar7 + 1) = (sword)iVar3 + sVar6;
      }
      else {
        *(sword *)(piVar7 + 1) = (sword)iVar3;
        piVar7 = (int *)(iVar3 + (int)piVar7);
        *(sword *)(piVar7 + 1) = sVar6;
      }
    }
    param_2[4] = (uint)piVar7;
    iVar3 = 0;
  }
  return iVar3;
}
/* GHIDRADEC_FUNCTION index=2896 start=0x403643a */

int sub_403643A(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  sword sVar2;
  word wVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = 0;
  if (param_3 != (int *)0x0) {
    iVar1 = *param_3;
    if (iVar1 == 2) {
      uVar4 = _dirpref(*(undefined4 *)(param_1 + 0x4e));
    }
    else {
      uVar4 = *(undefined4 *)(param_1 + 0x46);
    }
    wVar3 = *(word *)(param_3 + 1) | (word)*(undefined4 *)(_vttoif_tab + iVar1 * 4);
    iVar5 = _ialloc(param_1,uVar4,
                    CONCAT22((sword)((uint)*(undefined4 *)(_vttoif_tab + iVar1 * 4) >> 0x10),wVar3))
    ;
    if (iVar5 == 0) {
      iVar7 = (int)*(char *)(dword_40B57D4 + 100);
    }
    else {
      *(word *)(iVar5 + 0x42) = *(word *)(iVar5 + 0x42) | 0x46;
      *(word *)(iVar5 + 0x62) = wVar3;
      if ((iVar1 - 3U < 2) || (iVar1 == 9)) {
        sVar2 = *(sword *)(param_3 + 0xd);
        *(int *)(iVar5 + 0x8a) = (int)sVar2;
        *(sword *)(iVar5 + 0x38) = sVar2;
      }
      *(int *)(iVar5 + 0x34) = iVar1;
      if (iVar1 == 2) {
        *(undefined2 *)(iVar5 + 100) = 2;
      }
      else {
        *(undefined2 *)(iVar5 + 100) = 1;
      }
      if (*(sword *)(*(int *)(iVar5 + 0x30) + 0x124) == 0) {
        *(undefined2 *)(iVar5 + 0x66) = *(undefined2 *)(*(int *)(_active_u + 0x1a) + 2);
        *(undefined2 *)(iVar5 + 0x68) = *(undefined2 *)(param_1 + 0x68);
      }
      else {
        *(undefined2 *)(iVar5 + 0xe2) = *(undefined2 *)(param_1 + 0xe2);
        *(undefined2 *)(iVar5 + 0xe4) = *(undefined2 *)(param_1 + 0xe4);
        *(undefined2 *)(iVar5 + 0x66) = *(undefined2 *)(*(int *)(iVar5 + 0x30) + 0x124);
        *(undefined2 *)(iVar5 + 0x68) = _nogroup;
      }
      if (((*(byte *)(iVar5 + 0x62) & 4) != 0) &&
         (iVar6 = _groupmember((int)*(sword *)(iVar5 + 0x68)), iVar6 == 0)) {
        *(word *)(iVar5 + 0x62) = *(word *)(iVar5 + 0x62) & 0xfbff;
      }
      _iupdat(iVar5,1);
      if (iVar1 == 2) {
        iVar7 = sub_40365BA(iVar5,param_1);
      }
      if (iVar7 == 0) {
        wVar3 = *(word *)(iVar5 + 0x42);
        *(word *)(iVar5 + 0x42) = wVar3 & 0xfffe;
        if ((wVar3 & 0x10) != 0) {
          *(word *)(iVar5 + 0x42) = wVar3 & 0xffee;
          _wakeup(iVar5);
        }
        *param_2 = iVar5;
      }
      else {
        *(undefined2 *)(iVar5 + 100) = 0;
        *(word *)(iVar5 + 0x42) = *(word *)(iVar5 + 0x42) | 0x40;
        _iput(iVar5);
      }
    }
    return iVar7;
  }
                    /* WARNING: Subroutine does not return */
  _panic(aDirmakeinodeNo);
}
/* GHIDRADEC_FUNCTION index=2897 start=0x40365ba */

int sub_40365BA(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  
  iVar3 = *(int *)(param_1 + 0x4e);
  iVar2 = _bmap(param_1,0,0,0x400,0);
  if ((iVar2 < 1) || (*(char *)(dword_40B57D4 + 100) != '\0')) {
    cVar4 = *(char *)(dword_40B57D4 + 100);
    if (cVar4 == '\0') {
      return 0x1c;
    }
  }
  else {
    if (*(int *)(iVar3 + 0x34) < 0x400) {
                    /* WARNING: Subroutine does not return */
      _panic(aDirblksizFsize);
    }
    *(undefined4 *)(param_1 + 0x6e) = 0x400;
    *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x42;
    *(sword *)(param_2 + 100) = *(sword *)(param_2 + 100) + 1;
    *(word *)(param_2 + 0x42) = *(word *)(param_2 + 0x42) | 0x40;
    _iupdat(param_2,1);
    iVar3 = _bread(*(undefined4 *)(param_1 + 0x3e),iVar2 << (*(uint *)(iVar3 + 100) & 0x3f),
                   *(undefined4 *)(iVar3 + 0x34));
    cVar4 = *(char *)(dword_40B57D4 + 100);
    if (cVar4 == '\0') {
      puVar1 = *(undefined4 **)(iVar3 + 0x20);
      *puVar1 = _mastertemplate;
      puVar1[1] = dword_40AF2BE;
      puVar1[2] = dword_40AF2C2;
      puVar1[3] = dword_40AF2C6;
      puVar1[4] = dword_40AF2CA;
      puVar1[5] = dword_40AF2CE;
      *puVar1 = *(undefined4 *)(param_1 + 0x46);
      puVar1[3] = *(undefined4 *)(param_2 + 0x46);
      _bwrite(iVar3);
      cVar4 = *(char *)(dword_40B57D4 + 100);
    }
  }
  return (int)cVar4;
}
/* GHIDRADEC_FUNCTION index=2898 start=0x4036a22 */

undefined4 sub_4036A22(undefined4 param_1,int param_2,uint param_3,undefined4 param_4)

{
  word wVar1;
  word wVar2;
  int iVar3;
  
  wVar1 = *(word *)(param_2 + 4);
  if (((wVar1 & 3) == 0) && ((int)(uint)wVar1 <= (int)(0x400 - (param_3 & 0x3ff)))) {
    wVar2 = *(word *)(param_2 + 6);
    if ((((wVar2 + 4 & 0xfffffffc) + 8 <= (uint)wVar1) && (wVar2 < 0x100)) &&
       ((_dirchk == 0 || (iVar3 = sub_4036ADA(param_2 + 8,(uint)wVar2), iVar3 == 0)))) {
      return 0;
    }
  }
  sub_4036AAC(param_1,aMangledEntry_0,param_4);
  return 1;
}
/* GHIDRADEC_FUNCTION index=2899 start=0x4036aac */

void sub_4036AAC(int param_1,undefined4 param_2,undefined4 param_3)

{
  _printf(aSBadDirInoDAtO,*(int *)(param_1 + 0x4e) + 0xd4,*(undefined4 *)(param_1 + 0x46),param_3,
          param_2);
  return;
}

