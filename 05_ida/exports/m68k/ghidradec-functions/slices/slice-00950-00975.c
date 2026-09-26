/* GHIDRADEC_FUNCTION index=950 start=0x403164a */

void _bdevvp(sword param_1)

{
  _specvp(0,(int)param_1,3);
  return;
}
/* GHIDRADEC_FUNCTION index=951 start=0x4031664 */

void _set_blocksize(int param_1,word param_2)

{
  int iVar1;
  int iVar2;
  
  if (((_nblkdev <= (int)(uint)(param_2 >> 8)) ||
      ((&off_40B088C)[(uint)(param_2 >> 8) * 6] == (code *)0x0)) ||
     (iVar2 = (*(&off_40B088C)[(uint)(param_2 >> 8) * 6])((int)(sword)param_2), iVar2 == -1)) {
    *(undefined4 *)(param_1 + 0x46) = 0;
    return;
  }
  *(int *)(param_1 + 0x46) = iVar2;
  if (*(int *)(param_1 + 0x3a) == 0) {
    return;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x3a) + 0x2e);
  if (*(int *)(iVar1 + 0x46) != 0) {
    return;
  }
  *(int *)(iVar1 + 0x46) = iVar2;
  return;
}
/* GHIDRADEC_FUNCTION index=952 start=0x40316ce */

int _specvp(int param_1,sword param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined auStack_3e [28];
  undefined4 uStack_22;
  undefined4 uStack_1e;
  undefined4 uStack_1a;
  undefined4 uStack_16;
  undefined4 uStack_12;
  undefined4 uStack_e;
  
  iVar1 = sub_4031ADE((int)param_2,param_1,param_3);
  if (iVar1 == 0) {
    if ((param_1 == 0) || (*(int *)(param_1 + 0x28) != 8)) {
      iVar1 = _kalloc(0x66);
      _bzero(iVar1,0x66);
      *(undefined **)(iVar1 + 0x20) = _spec_vnodeops;
      if (param_1 != 0) {
        iVar2 = (**(code **)(*(int *)(param_1 + 0x1c) + 0x14))
                          (param_1,auStack_3e,*(undefined4 *)(_active_u + 0x1a));
        if (iVar2 == 0) {
          *(undefined4 *)(iVar1 + 0x4a) = uStack_22;
          *(undefined4 *)(iVar1 + 0x4e) = uStack_1e;
          *(undefined4 *)(iVar1 + 0x52) = uStack_1a;
          *(undefined4 *)(iVar1 + 0x56) = uStack_16;
          *(undefined4 *)(iVar1 + 0x5a) = uStack_12;
          *(undefined4 *)(iVar1 + 0x5e) = uStack_e;
        }
      }
    }
    else {
      iVar1 = _fifosp(param_1);
    }
    *(int *)(iVar1 + 0x36) = param_1;
    *(sword *)(iVar1 + 0x40) = param_2;
    *(sword *)(iVar1 + 0x30) = param_2;
    *(undefined2 *)(iVar1 + 10) = 1;
    *(int *)(iVar1 + 0x32) = iVar1;
    if (param_1 == 0) {
      *(undefined4 *)(iVar1 + 0x2c) = 3;
      *(undefined4 *)(iVar1 + 0x28) = 0;
      *(int *)(iVar1 + 0x3a) = iVar1 + 4;
    }
    else {
      *(sword *)(param_1 + 6) = *(sword *)(param_1 + 6) + 1;
      *(undefined4 *)(iVar1 + 0x2c) = *(undefined4 *)(param_1 + 0x28);
      *(undefined4 *)(iVar1 + 0x28) = *(undefined4 *)(param_1 + 0x24);
      if (*(int *)(param_1 + 0x28) == 3) {
        iVar2 = _bdevvp((int)param_2);
        *(int *)(iVar1 + 0x3a) = iVar2;
        *(undefined4 *)(iVar1 + 0x46) = *(undefined4 *)(*(int *)(iVar2 + 0x2e) + 0x46);
      }
    }
    sub_40318CE(iVar1);
  }
  _set_blocksize(iVar1,(int)param_2);
  return iVar1 + 4;
}
/* GHIDRADEC_FUNCTION index=953 start=0x4031814 */

int _makespecvp(sword param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  while( true ) {
    iVar1 = sub_4031ADE((int)param_1,0,param_2);
    if (iVar1 == 0) break;
    if ((*(word *)(iVar1 + 0x3e) & 1) == 0) goto loc_40318C0;
    *(word *)(iVar1 + 0x3e) = *(word *)(iVar1 + 0x3e) | 0x10;
    _sleep(iVar1,10);
  }
  iVar1 = _kalloc(0x66);
  _bzero(iVar1,0x66);
  *(undefined **)(iVar1 + 0x20) = _spec_vnodeops;
  *(int *)(iVar1 + 0x2c) = param_2;
  if (param_2 == 3) {
    uVar2 = _bdevvp((int)param_1);
    *(undefined4 *)(iVar1 + 0x3a) = uVar2;
  }
  *(undefined4 *)(iVar1 + 0x36) = 0;
  *(sword *)(iVar1 + 0x40) = param_1;
  *(sword *)(iVar1 + 0x30) = param_1;
  *(undefined2 *)(iVar1 + 10) = 1;
  *(int *)(iVar1 + 0x32) = iVar1;
  *(undefined4 *)(iVar1 + 0x28) = 0;
  sub_40318CE(iVar1);
loc_40318C0:
  return iVar1 + 4;
}
/* GHIDRADEC_FUNCTION index=954 start=0x4031914 */

void _sunsave(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)0x0;
  puVar2 = *(undefined4 **)
            (_stable +
            ((*(word *)(param_1 + 0x10) & 0xff) + (uint)(*(word *)(param_1 + 0x10) >> 8) & 0xf) * 4)
  ;
  while( true ) {
    if (puVar2 == (undefined4 *)0x0) {
      return;
    }
    if (param_1 == puVar2) break;
    puVar1 = puVar2;
    puVar2 = (undefined4 *)*puVar2;
  }
  if (puVar1 == (undefined4 *)0x0) {
    *(undefined4 *)
     (_stable +
     ((*(word *)(puVar2 + 0x10) & 0xff) + (uint)(*(word *)(puVar2 + 0x10) >> 8) & 0xf) * 4) =
         *puVar2;
    return;
  }
  *puVar1 = *puVar2;
  return;
}
/* GHIDRADEC_FUNCTION index=955 start=0x403197c */

int _stillopen(word param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  for (puVar1 = *(undefined4 **)(_stable + ((uint)(byte)param_1 + (uint)(param_1 >> 8) & 0xf) * 4);
      puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
    if ((param_1 == *(word *)(puVar1 + 0x10)) && (param_2 == puVar1[0xb])) {
      iVar2 = *(int *)((int)puVar1 + 0x62) + iVar2;
    }
  }
  return -(int)-(iVar2 != 0);
}
/* GHIDRADEC_FUNCTION index=956 start=0x40319d2 */

undefined4 _isclosing(word param_1,int param_2)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(_stable + ((uint)(byte)param_1 + (uint)(param_1 >> 8) & 0xf) * 4);
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return 0;
    }
    if (((param_1 == *(word *)(puVar1 + 0x10)) && (param_2 == puVar1[0xb])) &&
       ((*(byte *)((int)puVar1 + 0x3f) & 8) != 0)) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return 1;
}
/* GHIDRADEC_FUNCTION index=957 start=0x4031a2a */

undefined4 * _other_specvp(undefined4 *param_1)

{
  undefined4 *puVar1;
  word wVar2;
  
  wVar2 = *(word *)(*(int *)((int)param_1 + 0x2e) + 0x40);
  puVar1 = *(undefined4 **)(_stable + ((uint)(byte)wVar2 + (uint)(wVar2 >> 8) & 0xf) * 4);
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    if (((wVar2 == *(word *)(puVar1 + 0x10)) && (param_1 != puVar1 + 1)) &&
       (puVar1[0xb] == param_1[10])) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return puVar1 + 1;
}
/* GHIDRADEC_FUNCTION index=958 start=0x4031a88 */

undefined4 * _slookup(int param_1,word param_2)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(_stable + ((uint)(byte)param_2 + (uint)(param_2 >> 8) & 0xf) * 4);
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    if ((param_2 == *(word *)(puVar1 + 0x10)) && (param_1 == puVar1[0xb])) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  *(sword *)((int)puVar1 + 10) = *(sword *)((int)puVar1 + 10) + 1;
  return puVar1 + 1;
}
/* GHIDRADEC_FUNCTION index=959 start=0x4031b6c */

void _smark(int param_1,word param_2)

{
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  _microtime(&uStack_c);
  *(word *)(param_1 + 0x3e) = param_2 | *(word *)(param_1 + 0x3e);
  if ((param_2 & 4) != 0) {
    *(undefined4 *)(param_1 + 0x4a) = uStack_c;
    *(undefined4 *)(param_1 + 0x4e) = uStack_8;
  }
  if ((param_2 & 2) != 0) {
    *(undefined4 *)(param_1 + 0x52) = uStack_c;
    *(undefined4 *)(param_1 + 0x56) = uStack_8;
  }
  if ((param_2 & 0x40) != 0) {
    *(undefined4 *)(param_1 + 0x5a) = uStack_c;
    *(undefined4 *)(param_1 + 0x5e) = uStack_8;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=960 start=0x4031bd6 */

void _spec_badop(void)

{
                    /* WARNING: Subroutine does not return */
  _panic(aSpecBadop);
}
/* GHIDRADEC_FUNCTION index=961 start=0x403235c */

int _spec_setattr(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char cVar4;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iVar1 = *(int *)(param_1 + 0x2e);
  iVar3 = *(int *)(iVar1 + 0x36);
  if (iVar3 != 0) {
    *(undefined4 *)(param_2 + 0x14) = 0xffffffff;
    iVar3 = (**(code **)(*(int *)(iVar3 + 0x1c) + 0x18))(iVar3,param_2,param_3);
    if (iVar3 != 0) {
      return iVar3;
    }
  }
  cVar4 = *(int *)(param_2 + 0x24) != -1;
  if ((bool)cVar4) {
    uVar2 = *(undefined4 *)(param_2 + 0x28);
    *(undefined4 *)(iVar1 + 0x52) = *(undefined4 *)(param_2 + 0x24);
    *(undefined4 *)(iVar1 + 0x56) = uVar2;
  }
  if (*(int *)(param_2 + 0x1c) != -1) {
    uVar2 = *(undefined4 *)(param_2 + 0x20);
    *(undefined4 *)(iVar1 + 0x4a) = *(undefined4 *)(param_2 + 0x1c);
    *(undefined4 *)(iVar1 + 0x4e) = uVar2;
    cVar4 = cVar4 + '\x01';
  }
  if (cVar4 != '\0') {
    _getthetime(&uStack_c);
    *(undefined4 *)(iVar1 + 0x5a) = uStack_c;
    *(undefined4 *)(iVar1 + 0x5e) = uStack_8;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=962 start=0x40323fc */

undefined4 _spec_access(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x2e) + 0x36);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = (**(code **)(*(int *)(iVar1 + 0x1c) + 0x1c))(iVar1,param_2,param_3);
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=963 start=0x403242c */

undefined4 _spec_link(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x2e) + 0x36);
  if (iVar1 == 0) {
    uVar2 = 2;
  }
  else {
    uVar2 = (**(code **)(*(int *)(param_2 + 0x1c) + 0x2c))(iVar1,param_2,param_3,param_4);
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=964 start=0x4032474 */

undefined4 _spec_fsync(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  iVar1 = *(int *)(param_1 + 0x2e);
  if ((((*(word *)(iVar1 + 0x3e) & 0x46) != 0) || (*(int *)(param_1 + 0x28) == 3)) &&
     (iVar2 = *(int *)(iVar1 + 0x36), iVar2 != 0)) {
    iVar3 = _kalloc(0x3a);
    iVar4 = (**(code **)(*(int *)(*(int *)(iVar1 + 0x36) + 0x1c) + 0x14))
                      (*(int *)(iVar1 + 0x36),iVar3,param_2);
    if (iVar4 == 0) {
      iVar4 = _kalloc(0x3a);
      _vattr_null(iVar4);
      if ((*(int *)(iVar1 + 0x4a) < *(int *)(iVar3 + 0x1c)) ||
         ((*(int *)(iVar1 + 0x4a) == *(int *)(iVar3 + 0x1c) &&
          (*(int *)(iVar1 + 0x4e) < *(int *)(iVar3 + 0x20))))) {
        uVar5 = *(undefined4 *)(iVar3 + 0x1c);
        uVar6 = *(undefined4 *)(iVar3 + 0x20);
      }
      else {
        uVar5 = *(undefined4 *)(iVar1 + 0x4a);
        uVar6 = *(undefined4 *)(iVar1 + 0x4e);
      }
      *(undefined4 *)(iVar4 + 0x1c) = uVar5;
      *(undefined4 *)(iVar4 + 0x20) = uVar6;
      if ((*(int *)(iVar1 + 0x52) < *(int *)(iVar3 + 0x24)) ||
         ((*(int *)(iVar1 + 0x52) == *(int *)(iVar3 + 0x24) &&
          (*(int *)(iVar1 + 0x56) < *(int *)(iVar3 + 0x28))))) {
        uVar5 = *(undefined4 *)(iVar3 + 0x24);
        uVar6 = *(undefined4 *)(iVar3 + 0x28);
      }
      else {
        uVar5 = *(undefined4 *)(iVar1 + 0x52);
        uVar6 = *(undefined4 *)(iVar1 + 0x56);
      }
      *(undefined4 *)(iVar4 + 0x24) = uVar5;
      *(undefined4 *)(iVar4 + 0x28) = uVar6;
      (**(code **)(*(int *)(iVar2 + 0x1c) + 0x18))(iVar2,iVar4,param_2);
      _kfree(iVar4,0x3a);
    }
    _kfree(iVar3,0x3a);
    (**(code **)(*(int *)(iVar2 + 0x1c) + 0x48))(iVar2,param_2);
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=965 start=0x40325d0 */

undefined4 _spec_lockctl(void)

{
  return 0x16;
}
/* GHIDRADEC_FUNCTION index=966 start=0x40325da */

undefined4 _spec_fid(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x2e) + 0x36);
  if (iVar1 == 0) {
    uVar2 = 0x16;
  }
  else {
    uVar2 = (**(code **)(*(int *)(iVar1 + 0x1c) + 100))(iVar1,param_2);
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=967 start=0x403261c */

undefined4 _spec_realvp(int param_1,int *param_2)

{
  int iVar1;
  int iStack_8;
  
  if (param_1 != 0) {
    if ((*(undefined **)(param_1 + 0x1c) == _spec_vnodeops) ||
       (*(undefined **)(param_1 + 0x1c) == _fifo_vnodeops)) {
      param_1 = *(int *)(*(int *)(param_1 + 0x2e) + 0x36);
    }
    if (param_1 != 0) {
      iVar1 = (**(code **)(*(int *)(param_1 + 0x1c) + 0x70))(param_1,&iStack_8);
      if (iVar1 == 0) {
        param_1 = iStack_8;
      }
    }
  }
  *param_2 = param_1;
  return 0;
}
/* GHIDRADEC_FUNCTION index=968 start=0x40326ac */

void _logswap(undefined param_1,undefined4 param_2,undefined4 param_3,byte param_4,byte param_5)

{
  int iVar1;
  
  if (1999 < _logswapindex) {
    _logswapindex = 0;
  }
  iVar1 = _logswapindex * 10;
  *(undefined4 *)(_logswp + iVar1) = param_2;
  *(undefined4 *)(_logswp + iVar1 + 4) = param_3;
  *(uint *)(_logswp + iVar1 + 8) =
       *(uint *)(_logswp + iVar1 + 8) & 0xfffffff | (uint)param_4 << 0x1c;
  *(uint *)(_logswp + _logswapindex * 10 + 8) =
       *(uint *)(_logswp + _logswapindex * 10 + 8) & 0xf0ffffff | (param_5 & 0xf) << 0x18;
  _logswp[_logswapindex * 10 + 9] = param_1;
  _logswapindex = _logswapindex + 1;
  return;
}
/* GHIDRADEC_FUNCTION index=969 start=0x40329fe */

int _compress_data(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  byte *pbVar9;
  
  uVar5 = param_2 + 3U >> 2;
  piVar7 = (int *)((int)param_3 + (param_2 + 3U >> 5) + 4);
  bVar3 = 0;
  iVar4 = 0;
  iVar8 = 0;
  pbVar9 = (byte *)(param_3 + 1);
  if (uVar5 != 0) {
    do {
      uVar2 = 0;
      piVar6 = piVar7;
      do {
        piVar7 = piVar6;
        if ((int)uVar5 <= iVar8) break;
        bVar3 = bVar3 << 1;
        iVar1 = *param_1;
        if (iVar1 != iVar4) {
          bVar3 = bVar3 | 1;
          piVar7 = piVar6 + 1;
          *piVar6 = iVar1;
          iVar4 = iVar1;
          if (param_2 == (int)piVar7 - (int)param_3) {
            return param_2;
          }
        }
        param_1 = param_1 + 1;
        uVar2 = uVar2 + 1;
        iVar8 = iVar8 + 1;
        piVar6 = piVar7;
      } while (uVar2 < 8);
      *pbVar9 = bVar3;
      pbVar9 = pbVar9 + 1;
    } while (iVar8 < (int)uVar5);
  }
  *param_3 = param_2;
  return (int)piVar7 - (int)param_3;
}
/* GHIDRADEC_FUNCTION index=970 start=0x4032a72 */

uint _uncompress_data(int param_1,undefined4 param_2,undefined4 *param_3,int param_4)

{
  uint uVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  char *pcVar9;
  
  uVar4 = param_4 + 3U >> 2;
  puVar8 = (undefined4 *)(param_1 + 4 + (param_4 + 3U >> 5));
  uVar3 = 0;
  iVar6 = 0;
  pcVar9 = (char *)(param_1 + 4);
  if (uVar4 != 0) {
    do {
      cVar2 = *pcVar9;
      uVar1 = 0;
      puVar5 = param_3;
      puVar7 = puVar8;
      do {
        if ((int)uVar4 <= iVar6) {
          return uVar4;
        }
        puVar8 = puVar7;
        if (cVar2 < '\0') {
          puVar8 = puVar7 + 1;
          uVar3 = *puVar7;
        }
        param_3 = puVar5 + 1;
        *puVar5 = uVar3;
        cVar2 = cVar2 << 1;
        uVar1 = uVar1 + 1;
        iVar6 = iVar6 + 1;
        puVar5 = param_3;
        puVar7 = puVar8;
      } while (uVar1 < 8);
      pcVar9 = pcVar9 + 1;
    } while (iVar6 < (int)uVar4);
  }
  return uVar4;
}
/* GHIDRADEC_FUNCTION index=971 start=0x40335f0 */

int _alloc(int param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = *(int *)(param_1 + 0x4e);
  if ((*(uint *)(iVar3 + 0x30) < param_3) || ((param_3 & ~*(uint *)(iVar3 + 0x4c)) != 0)) {
    _printf(aDev0xXBsizeDSi,(int)*(sword *)(param_1 + 0x44),*(uint *)(iVar3 + 0x30),param_3,
            iVar3 + 0xd4);
                    /* WARNING: Subroutine does not return */
    _panic(aAllocBadSize);
  }
  if (((param_3 != *(uint *)(iVar3 + 0x30)) || (*(int *)(iVar3 + 0xc4) != 0)) &&
     ((*(sword *)(*(int *)(_active_u + 0x1a) + 2) == 0 ||
      (iVar1 = *(int *)(iVar3 + 0xcc) + (*(int *)(iVar3 + 0xc4) << (*(uint *)(iVar3 + 0x60) & 0x3f))
      , iVar2 = (*(int *)(iVar3 + 0x3c) * *(int *)(iVar3 + 0x28)) / 100,
      iVar1 != iVar2 && -1 < iVar1 - iVar2)))) {
    if (*(int *)(iVar3 + 0x24) <= param_2) {
      param_2 = 0;
    }
    if (param_2 == 0) {
      uVar4 = *(uint *)(param_1 + 0x46) / *(uint *)(iVar3 + 0xb8);
    }
    else {
      uVar4 = param_2 / *(int *)(iVar3 + 0xbc);
    }
    iVar1 = _hashalloc(param_1,uVar4,param_2,param_3,_alloccg);
    if (0 < iVar1) {
      iVar2 = (**(code **)(*(int *)(param_1 + 0x28) + 0x80))(param_1 + 0xc);
      *(int *)(param_1 + 0xca) = (int)param_3 / iVar2 + *(int *)(param_1 + 0xca);
      *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x42;
      iVar3 = _getblk(*(undefined4 *)(param_1 + 0x3e),iVar1 << (*(uint *)(iVar3 + 100) & 0x3f),
                      param_3);
      _blkclr(*(undefined4 *)(iVar3 + 0x20),*(undefined4 *)(iVar3 + 0x14));
      *(undefined4 *)(iVar3 + 0x28) = 0;
      return iVar3;
    }
  }
  _fsfull(iVar3,1);
  return 0;
}
/* GHIDRADEC_FUNCTION index=972 start=0x4033736 */

uint _fsfull(int param_1,uint param_2)

{
  uint uVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  if ((param_2 & 1) == 0) {
    if ((param_2 & 2) == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(&aFsfull);
    }
    puVar2 = aOutOfInodes;
    puVar3 = aCreateSymlinkF;
  }
  else {
    puVar2 = aFileSystemFull;
    puVar3 = aWriteFailedFil;
  }
  uVar1 = param_2 & (int)*(char *)(param_1 + 0xd3);
  if (uVar1 == 0) {
    uVar1 = _fserr(param_1,puVar2);
  }
  *(byte *)(param_1 + 0xd3) = (byte)param_2 | *(byte *)(param_1 + 0xd3);
  if ((*(byte *)(_active_u + 0x254) & 8) == 0) {
    uVar1 = _uprintf(aSS_0,param_1 + 0xd4,puVar3);
  }
  if (*(int *)(dword_40B57D4 + 0x66) == 0) {
    *(int *)(dword_40B57D4 + 0x66) = param_1;
    *(byte *)(dword_40B57D4 + 0x6a) = (byte)param_2;
  }
  *(undefined *)(dword_40B57D4 + 100) = 0x1c;
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=973 start=0x40337ea */

void _fssleep(int param_1,uint param_2)

{
  if ((param_2 & 1) == 0) {
    if ((param_2 & 2) == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(&aFssleep);
    }
    if (*(int *)(param_1 + 200) <= *(int *)(param_1 + 0x90)) {
      do {
        _sleep((int *)(param_1 + 200),0x1a);
      } while (*(int *)(param_1 + 200) <= *(int *)(param_1 + 0x90));
    }
  }
  else if (*(int *)(param_1 + 0xcc) +
           (*(int *)(param_1 + 0xc4) << (*(uint *)(param_1 + 0x60) & 0x3f)) <=
           *(int *)(param_1 + 0x88)) {
    do {
      _sleep((int *)(param_1 + 0xcc),0x1a);
    } while (*(int *)(param_1 + 0xcc) +
             (*(int *)(param_1 + 0xc4) << (*(uint *)(param_1 + 0x60) & 0x3f)) <=
             *(int *)(param_1 + 0x88));
  }
  return;
}
/* GHIDRADEC_FUNCTION index=974 start=0x403387e */

undefined4 _fspause(int param_1)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *(int *)(dword_40B57D4 + 0x66);
  uVar3 = (uint)*(char *)(dword_40B57D4 + 0x6a);
  *(undefined4 *)(dword_40B57D4 + 0x66) = 0;
  *(undefined *)(dword_40B57D4 + 0x6a) = 0;
  if ((((iVar2 != 0) && (uVar3 != 0)) && (*(char *)(dword_40B57D4 + 100) == '\x1c')) &&
     (((*(byte *)(_active_u + 0x254) & 8) != 0 && (param_1 == 0)))) {
    *(undefined *)(dword_40B57D4 + 100) = 0;
    puVar1 = aFileSystemIsFu;
    if ((uVar3 & 1) == 0) {
      puVar1 = aOutOfInodes_0;
    }
    iVar2 = _rpsleep(_fssleep,iVar2,uVar3,iVar2 + 0xd4,puVar1);
    if (iVar2 != 0) {
      return 1;
    }
    *(undefined *)(dword_40B57D4 + 100) = 0x1c;
  }
  return 0;
}

