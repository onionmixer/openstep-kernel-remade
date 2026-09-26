/* GHIDRADEC_FUNCTION index=950 start=0x403154c */

int _fifosp(int param_1)

{
  int iVar1;
  undefined auStack_3e [28];
  undefined4 uStack_22;
  undefined4 uStack_1e;
  undefined4 uStack_1a;
  undefined4 uStack_16;
  undefined4 uStack_12;
  undefined4 uStack_e;
  
  iVar1 = _kalloc(0x8a);
  _bzero(iVar1,0x8a);
  *(undefined **)(iVar1 + 0x20) = _fifo_vnodeops;
  (**(code **)(*(int *)(param_1 + 0x1c) + 0x14))
            (param_1,auStack_3e,*(undefined4 *)(_active_u + 0x1a));
  *(undefined4 *)(iVar1 + 0x4a) = uStack_22;
  *(undefined4 *)(iVar1 + 0x4e) = uStack_1e;
  *(undefined4 *)(iVar1 + 0x52) = uStack_1a;
  *(undefined4 *)(iVar1 + 0x56) = uStack_16;
  *(undefined4 *)(iVar1 + 0x5a) = uStack_12;
  *(undefined4 *)(iVar1 + 0x5e) = uStack_e;
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=951 start=0x403164a */

void _bdevvp(sword param_1)

{
  _specvp(0,(int)param_1,3);
  return;
}
/* GHIDRADEC_FUNCTION index=952 start=0x4031664 */

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
/* GHIDRADEC_FUNCTION index=953 start=0x40316ce */

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
/* GHIDRADEC_FUNCTION index=954 start=0x4031814 */

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
/* GHIDRADEC_FUNCTION index=955 start=0x4031914 */

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
/* GHIDRADEC_FUNCTION index=956 start=0x403197c */

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
/* GHIDRADEC_FUNCTION index=957 start=0x40319d2 */

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
/* GHIDRADEC_FUNCTION index=958 start=0x4031a2a */

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
/* GHIDRADEC_FUNCTION index=959 start=0x4031a88 */

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
/* GHIDRADEC_FUNCTION index=960 start=0x4031b6c */

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
/* GHIDRADEC_FUNCTION index=961 start=0x4031bd6 */

void _spec_badop(void)

{
                    /* WARNING: Subroutine does not return */
  _panic(aSpecBadop);
}
/* GHIDRADEC_FUNCTION index=962 start=0x403235c */

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
/* GHIDRADEC_FUNCTION index=963 start=0x40323fc */

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
/* GHIDRADEC_FUNCTION index=964 start=0x403242c */

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
/* GHIDRADEC_FUNCTION index=965 start=0x4032474 */

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
/* GHIDRADEC_FUNCTION index=966 start=0x40325d0 */

undefined4 _spec_lockctl(void)

{
  return 0x16;
}
/* GHIDRADEC_FUNCTION index=967 start=0x40325da */

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
/* GHIDRADEC_FUNCTION index=968 start=0x403261c */

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
/* GHIDRADEC_FUNCTION index=969 start=0x40326ac */

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
/* GHIDRADEC_FUNCTION index=970 start=0x40329fe */

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
/* GHIDRADEC_FUNCTION index=971 start=0x4032a72 */

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
/* GHIDRADEC_FUNCTION index=972 start=0x40335f0 */

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
/* GHIDRADEC_FUNCTION index=973 start=0x4033736 */

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
/* GHIDRADEC_FUNCTION index=974 start=0x40337ea */

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
/* GHIDRADEC_FUNCTION index=975 start=0x403387e */

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
/* GHIDRADEC_FUNCTION index=976 start=0x4033916 */

uint * _realloccg(int param_1,int param_2,int param_3,uint param_4,uint param_5)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  uint uStack_8;
  
  iVar3 = *(int *)(param_1 + 0x4e);
  if ((((*(uint *)(iVar3 + 0x30) < param_4) || ((~*(uint *)(iVar3 + 0x4c) & param_4) != 0)) ||
      (*(uint *)(iVar3 + 0x30) < param_5)) || ((~*(uint *)(iVar3 + 0x4c) & param_5) != 0)) {
    _printf(aDev0xXBsizeDOs,(int)*(sword *)(param_1 + 0x44),*(undefined4 *)(iVar3 + 0x30),param_4,
            param_5,iVar3 + 0xd4);
                    /* WARNING: Subroutine does not return */
    _panic(aRealloccgBadSi);
  }
  if ((*(sword *)(*(int *)(_active_u + 0x1a) + 2) != 0) &&
     (iVar1 = *(int *)(iVar3 + 0xcc) + (*(int *)(iVar3 + 0xc4) << (*(uint *)(iVar3 + 0x60) & 0x3f)),
     iVar5 = (*(int *)(iVar3 + 0x3c) * *(int *)(iVar3 + 0x28)) / 100,
     iVar1 == iVar5 || iVar1 - iVar5 < 0)) {
loc_4033C44:
    _fsfull(iVar3,1);
    return (uint *)0x0;
  }
  if (param_2 == 0) {
    _printf(aDev0xXBsizeDBp,(int)*(sword *)(param_1 + 0x44),*(undefined4 *)(iVar3 + 0x30),0,
            iVar3 + 0xd4);
                    /* WARNING: Subroutine does not return */
    _panic(aRealloccgBadBp);
  }
  iVar5 = param_2 / *(int *)(iVar3 + 0xbc);
  iVar1 = _fragextend(param_1,iVar5,param_2,param_4,param_5);
  if (iVar1 == 0) {
    if (*(int *)(iVar3 + 0x24) <= param_3) {
      param_3 = 0;
    }
    if (*(int *)(iVar3 + 0x80) == 0) {
      uStack_8 = *(uint *)(iVar3 + 0x30);
      if (((*(int *)(iVar3 + 0x3c) + -2) * *(int *)(iVar3 + 0x28)) / 100 <= *(int *)(iVar3 + 0xcc))
      {
        _log(5,aSOptimizationC_0,iVar3 + 0xd4);
        *(undefined4 *)(iVar3 + 0x80) = 1;
      }
    }
    else if (*(int *)(iVar3 + 0x80) == 1) {
      uStack_8 = param_5;
      if ((4 < *(int *)(iVar3 + 0x3c)) &&
         (*(int *)(iVar3 + 0xcc) <= (*(int *)(iVar3 + 0x28) * *(int *)(iVar3 + 0x3c)) / 200)) {
        _log(5,aSOptimizationC,iVar3 + 0xd4);
        *(undefined4 *)(iVar3 + 0x80) = 0;
      }
    }
    else {
      *(undefined4 *)(iVar3 + 0x80) = 1;
      uStack_8 = param_5;
    }
    iVar1 = _hashalloc(param_1,iVar5,param_3,uStack_8,_alloccg);
    if (iVar1 < 1) goto loc_4033C44;
    puVar4 = (uint *)_bread(*(undefined4 *)(param_1 + 0x3e),
                            param_2 << (*(uint *)(iVar3 + 100) & 0x3f),param_4);
    if ((*puVar4 & 4) != 0) {
      _brelse(puVar4);
      return (uint *)0x0;
    }
    puVar2 = (uint *)_getblk(*(undefined4 *)(param_1 + 0x3e),
                             iVar1 << (*(uint *)(iVar3 + 100) & 0x3f),param_5);
    _bcopy(puVar4[8],puVar2[8],param_4);
    _bzero(param_4 + puVar2[8],param_5 - param_4);
    if ((*puVar4 & 0x200) != 0) {
      *puVar4 = *puVar4 & 0xfffffdff;
      *(int *)(_active_u + 0x196) = *(int *)(_active_u + 0x196) + -1;
    }
    _brelse(puVar4);
    _free_block(param_1,param_2,param_4);
    if ((int)param_5 < (int)uStack_8) {
      _free_block(param_1,iVar1 + ((int)param_5 >> (*(uint *)(iVar3 + 0x54) & 0x3f)),
                  uStack_8 - param_5);
    }
    iVar3 = (**(code **)(*(int *)(param_1 + 0x28) + 0x80))(param_1 + 0xc);
    *(int *)(param_1 + 0xca) = (int)(param_5 - param_4) / iVar3 + *(int *)(param_1 + 0xca);
  }
  else {
    do {
      puVar2 = (uint *)_bread(*(undefined4 *)(param_1 + 0x3e),
                              iVar1 << (*(uint *)(iVar3 + 100) & 0x3f),param_4);
      if ((*puVar2 & 4) != 0) {
        _brelse(puVar2);
        return (uint *)0x0;
      }
      iVar5 = _brealloc(puVar2,param_5);
    } while (iVar5 == 0);
    *puVar2 = *puVar2 | 2;
    _bzero(puVar2[8] + param_4,param_5 - param_4);
    iVar3 = (**(code **)(*(int *)(param_1 + 0x28) + 0x80))(param_1 + 0xc);
    *(int *)(param_1 + 0xca) = (int)(param_5 - param_4) / iVar3 + *(int *)(param_1 + 0xca);
  }
  *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x42;
  return puVar2;
}
/* GHIDRADEC_FUNCTION index=977 start=0x4033c5c */

int _ialloc(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 0x4e);
  if (((*(sword *)(*(int *)(_active_u + 0x1a) + 2) == 0) ||
      (*(int *)(iVar1 + 0x94) < *(int *)(iVar1 + 200))) && (*(int *)(iVar1 + 200) != 0)) {
    uVar2 = *(uint *)(iVar1 + 0xb8) * *(int *)(iVar1 + 0x2c);
    if (uVar2 < param_2 || uVar2 - param_2 == 0) {
      param_2 = 0;
    }
    iVar3 = _hashalloc(param_1,param_2 / *(uint *)(iVar1 + 0xb8),param_2,param_3,_ialloccg);
    if (iVar3 != 0) {
      iVar4 = _iget((int)*(sword *)(param_1 + 0x44),*(undefined4 *)(param_1 + 0x4e),iVar3);
      if (iVar4 == 0) {
        _ifree(param_1,iVar3,0);
        return 0;
      }
      if (*(sword *)(iVar4 + 0x62) != 0) {
        _printf(aMode0OInumDFsS,*(sword *)(iVar4 + 0x62),*(undefined4 *)(iVar4 + 0x46),iVar1 + 0xd4)
        ;
                    /* WARNING: Subroutine does not return */
        _panic(aIallocDupAlloc);
      }
      if (*(int *)(iVar4 + 0xca) != 0) {
        _printf(aFreeInodeSDHad,iVar1 + 0xd4,iVar3,*(int *)(iVar4 + 0xca));
        *(undefined4 *)(iVar4 + 0xca) = 0;
      }
      *(undefined4 *)(iVar4 + 0xc6) = 0;
      return iVar4;
    }
  }
  _fsfull(iVar1,2);
  return 0;
}
/* GHIDRADEC_FUNCTION index=978 start=0x4033d60 */

int _dirpref(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  iVar1 = *(int *)(param_1 + 0x2c);
  iVar6 = *(int *)(param_1 + 0xb8);
  uVar7 = 0;
  uVar5 = 0;
  if (0 < iVar1) {
    do {
      iVar2 = *(int *)(param_1 + ((int)uVar5 >> (*(uint *)(param_1 + 0x70) & 0x3f)) * 4 + 0x2d8);
      iVar4 = (~*(uint *)(param_1 + 0x6c) & uVar5) * 0x10;
      iVar3 = *(int *)(iVar2 + iVar4);
      if ((iVar3 < iVar6) && (*(int *)(param_1 + 200) / iVar1 <= *(int *)(iVar2 + 8 + iVar4))) {
        iVar6 = iVar3;
        uVar7 = uVar5;
      }
      uVar5 = uVar5 + 1;
    } while ((int)uVar5 < iVar1);
  }
  return uVar7 * *(int *)(param_1 + 0xb8);
}
/* GHIDRADEC_FUNCTION index=979 start=0x4033dca */

undefined8 _blkpref(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  iVar1 = *(int *)(param_1 + 0x4e);
  iVar6 = *(int *)(iVar1 + 0x5c);
  uVar3 = param_3 / iVar6;
  if ((param_3 % iVar6 != 0) && (iVar2 = *(int *)(param_4 + -4 + param_3 * 4), iVar2 != 0)) {
    iVar2 = *(int *)(iVar1 + 0x38) + iVar2;
    iVar6 = *(int *)(iVar1 + 0x58);
    if ((param_3 <= iVar6) ||
       (uVar3 = param_3 - iVar6,
       iVar2 == *(int *)(param_4 + uVar3 * 4) + (iVar6 << (*(uint *)(iVar1 + 0x60) & 0x3f)))) {
      uVar3 = 0;
      if (*(int *)(iVar1 + 0x40) != 0) {
        iVar6 = *(int *)(iVar1 + 0x38);
        uVar3 = iVar6 * (((*(int *)(iVar1 + 0xa8) * *(int *)(iVar1 + 0x44) * *(int *)(iVar1 + 0x40))
                          / (*(int *)(iVar1 + 0x7c) * 1000) + -1 + iVar6) / iVar6);
        iVar2 = uVar3 + iVar2;
      }
    }
    goto loc_4033F22;
  }
  if (0xb < param_2) {
    if ((param_3 == 0) || (iVar2 = *(int *)(param_4 + -4 + param_3 * 4), iVar2 == 0)) {
      iVar6 = param_2 / iVar6 + *(uint *)(param_1 + 0x46) / *(uint *)(iVar1 + 0xb8);
    }
    else {
      iVar6 = iVar2 / *(int *)(iVar1 + 0xbc) + 1;
    }
    uVar3 = *(uint *)(iVar1 + 0x2c);
    uVar5 = iVar6 % (int)uVar3;
    iVar6 = *(int *)(iVar1 + 0xc4) / (int)uVar3;
    if ((int)uVar5 < (int)uVar3) {
      uVar4 = uVar5;
      do {
        if (iVar6 <= *(int *)(*(int *)(iVar1 + ((int)uVar4 >> (*(uint *)(iVar1 + 0x70) & 0x3f)) * 4
                                      + 0x2d8) + 4 + (~*(uint *)(iVar1 + 0x6c) & uVar4) * 0x10))
        goto loc_4033ECE;
        uVar4 = uVar4 + 1;
      } while ((int)uVar4 < (int)uVar3);
    }
    uVar4 = 0;
    if (-1 < (int)uVar5) {
      uVar3 = ~*(uint *)(iVar1 + 0x6c);
      do {
        if (iVar6 <= *(int *)(*(int *)(iVar1 + ((int)uVar4 >> (*(uint *)(iVar1 + 0x70) & 0x3f)) * 4
                                      + 0x2d8) + 4 + (uVar3 & uVar4) * 0x10)) goto loc_4033ECE;
        uVar4 = uVar4 + 1;
      } while ((int)uVar4 <= (int)uVar5);
    }
    iVar2 = 0;
    goto loc_4033F22;
  }
  uVar4 = *(uint *)(param_1 + 0x46) / *(uint *)(iVar1 + 0xb8);
loc_4033ED2:
  iVar2 = *(int *)(iVar1 + 0x38) + uVar4 * *(int *)(iVar1 + 0xbc);
loc_4033F22:
  return CONCAT44(iVar2,uVar3);
loc_4033ECE:
  *(uint *)(iVar1 + 0x2d4) = uVar4;
  goto loc_4033ED2;
}
/* GHIDRADEC_FUNCTION index=980 start=0x4033f2c */

int _hashalloc(int param_1,int param_2,undefined4 param_3,undefined4 param_4,code *param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 0x4e);
  iVar2 = (*param_5)(param_1,param_2,param_3,param_4);
  if (iVar2 == 0) {
    iVar2 = param_2;
    for (iVar4 = 1; iVar3 = *(int *)(iVar1 + 0x2c), iVar4 < iVar3; iVar4 = iVar4 * 2) {
      iVar2 = iVar4 + iVar2;
      if (iVar3 <= iVar2) {
        iVar2 = iVar2 - iVar3;
      }
      iVar3 = (*param_5)(param_1,iVar2,0,param_4);
      if (iVar3 != 0) {
        return iVar3;
      }
    }
    iVar2 = (param_2 + 2) % *(int *)(iVar1 + 0x2c);
    iVar4 = 2;
    if (2 < *(int *)(iVar1 + 0x2c)) {
      do {
        iVar3 = (*param_5)(param_1,iVar2,0,param_4);
        if (iVar3 != 0) {
          return iVar3;
        }
        iVar2 = iVar2 + 1;
        if (*(int *)(iVar1 + 0x2c) == iVar2) {
          iVar2 = 0;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)(iVar1 + 0x2c));
    }
    iVar2 = 0;
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=981 start=0x4033fc8 */

uint _fragextend(int param_1,uint param_2,uint param_3,int param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 auStack_c [2];
  
  iVar2 = *(int *)(param_1 + 0x4e);
  if (param_5 - param_4 >> (*(uint *)(iVar2 + 0x54) & 0x3f) <=
      *(int *)(*(int *)(iVar2 + ((int)param_2 >> (*(uint *)(iVar2 + 0x70) & 0x3f)) * 4 + 0x2d8) +
               0xc + (~*(uint *)(iVar2 + 0x6c) & param_2) * 0x10)) {
    param_5 = param_5 >> (*(uint *)(iVar2 + 0x54) & 0x3f);
    uVar6 = *(int *)(iVar2 + 0x38) - 1;
    uVar5 = uVar6 & param_3;
    if ((int)uVar5 <= (int)(uVar6 & (param_3 - 1) + param_5)) {
      iVar8 = _bread(*(undefined4 *)(param_1 + 0x3e),
                     *(int *)(iVar2 + 0xc) +
                     *(int *)(iVar2 + 0x18) * (param_2 & ~*(uint *)(iVar2 + 0x1c)) +
                     param_2 * *(int *)(iVar2 + 0xbc) << (*(uint *)(iVar2 + 100) & 0x3f),
                     *(undefined4 *)(iVar2 + 0xa0));
      iVar3 = *(int *)(iVar8 + 0x20);
      if (((*(byte *)(iVar8 + 3) & 4) == 0) && (*(int *)(iVar3 + 0x3d4) == 0x90255)) {
        _getthetime(auStack_c);
        *(undefined4 *)(iVar3 + 8) = auStack_c[0];
        iVar10 = (int)param_3 % *(int *)(iVar2 + 0xbc);
        for (iVar7 = param_4 >> (*(uint *)(iVar2 + 0x54) & 0x3f); iVar7 < param_5; iVar7 = iVar7 + 1
            ) {
          iVar11 = iVar7 + iVar10;
          iVar9 = iVar11;
          if (iVar11 < 0) {
            iVar9 = iVar11 + 7;
          }
          if (((int)*(char *)(iVar3 + (iVar9 >> 3) + 0x3d8) &
              1 << (iVar11 + (iVar9 >> 3) * -8 & 0x1fU)) == 0) goto loc_403407C;
        }
        for (iVar7 = param_5; iVar7 < (int)(*(int *)(iVar2 + 0x38) - uVar5); iVar7 = iVar7 + 1) {
          iVar11 = iVar7 + iVar10;
          iVar9 = iVar11;
          if (iVar11 < 0) {
            iVar9 = iVar11 + 7;
          }
          if (((int)*(char *)(iVar3 + (iVar9 >> 3) + 0x3d8) &
              1 << (iVar11 + (iVar9 >> 3) * -8 & 0x1fU)) == 0) break;
        }
        piVar1 = (int *)(iVar3 + 0x34 + (iVar7 - (param_4 >> (*(uint *)(iVar2 + 0x54) & 0x3f))) * 4)
        ;
        *piVar1 = *piVar1 + -1;
        if (param_5 != iVar7) {
          piVar1 = (int *)(iVar3 + 0x34 + (iVar7 - param_5) * 4);
          *piVar1 = *piVar1 + 1;
        }
        for (param_4 = param_4 >> (*(uint *)(iVar2 + 0x54) & 0x3f); param_4 < param_5;
            param_4 = param_4 + 1) {
          iVar7 = param_4 + iVar10;
          iVar9 = iVar7;
          if (iVar7 < 0) {
            iVar9 = iVar7 + 7;
          }
          pbVar4 = (byte *)(iVar3 + (iVar9 >> 3) + 0x3d8);
          *pbVar4 = ~(byte)(1 << (iVar7 + (iVar9 >> 3) * -8 & 0x3fU)) & *pbVar4;
          *(int *)(iVar3 + 0x24) = *(int *)(iVar3 + 0x24) + -1;
          *(int *)(iVar2 + 0xcc) = *(int *)(iVar2 + 0xcc) + -1;
          piVar1 = (int *)(*(int *)(iVar2 + ((int)param_2 >> (*(uint *)(iVar2 + 0x70) & 0x3f)) * 4 +
                                   0x2d8) + 0xc + (param_2 & ~*(uint *)(iVar2 + 0x6c)) * 0x10);
          *piVar1 = *piVar1 + -1;
        }
        *(char *)(iVar2 + 0xd0) = *(char *)(iVar2 + 0xd0) + '\x01';
        _bdwrite(iVar8);
        return param_3;
      }
loc_403407C:
      _brelse(iVar8);
    }
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=982 start=0x40341a6 */

int _alloccg(int param_1,uint param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int iStack_40;
  int iStack_3c;
  undefined4 *puStack_38;
  undefined4 auStack_c [2];
  
  iVar2 = *(int *)(param_1 + 0x4e);
  if ((*(int *)(*(int *)(iVar2 + ((int)param_2 >> (*(uint *)(iVar2 + 0x70) & 0x3f)) * 4 + 0x2d8) + 4
               + (param_2 & ~*(uint *)(iVar2 + 0x6c)) * 0x10) == 0) &&
     (param_4 == *(int *)(iVar2 + 0x30))) {
    return 0;
  }
  puStack_38 = *(undefined4 **)(iVar2 + 0xa0);
  iStack_3c = *(int *)(iVar2 + 0xc) +
              *(int *)(iVar2 + 0x18) * (param_2 & ~*(uint *)(iVar2 + 0x1c)) +
              param_2 * *(int *)(iVar2 + 0xbc) << (*(uint *)(iVar2 + 100) & 0x3f);
  iStack_40 = *(int *)(param_1 + 0x3e);
  iVar6 = _bread();
  iVar3 = *(int *)(iVar6 + 0x20);
  if ((((*(byte *)(iVar6 + 3) & 4) == 0) && (*(int *)(iVar3 + 0x3d4) == 0x90255)) &&
     ((*(int *)(iVar3 + 0x1c) != 0 || (param_4 != *(int *)(iVar2 + 0x30))))) {
    puStack_38 = auStack_c;
    iStack_3c = 0x4034258;
    _getthetime();
    *(undefined4 *)(iVar3 + 8) = auStack_c[0];
    iStack_3c = iVar3;
    if (param_4 == *(int *)(iVar2 + 0x30)) {
      puStack_38 = (undefined4 *)param_3;
      piVar11 = &iStack_40;
      iStack_40 = iVar2;
      iVar7 = _alloccgblk();
loc_4034326:
      *(int *)((int)piVar11 + -4) = iVar6;
      *(undefined4 *)((int)piVar11 + -8) = 0x403432e;
      _bdwrite();
      return iVar7;
    }
    param_4 = param_4 >> (*(uint *)(iVar2 + 0x54) & 0x3f);
    for (iVar7 = param_4;
        (iVar7 < *(int *)(iVar2 + 0x38) && (*(int *)(iVar3 + 0x34 + iVar7 * 4) == 0));
        iVar7 = iVar7 + 1) {
    }
    if (iVar7 == *(int *)(iVar2 + 0x38)) {
      if (*(int *)(iVar3 + 0x1c) != 0) {
        puStack_38 = (undefined4 *)param_3;
        iStack_40 = iVar2;
        iVar7 = _alloccgblk();
        iVar8 = *(int *)(iVar2 + 0xbc);
        piVar11 = (int *)&stack0xffffffcc;
        iVar10 = param_4;
        if (param_4 < *(int *)(iVar2 + 0x38)) {
          do {
            iVar5 = iVar10 + iVar7 % iVar8;
            iVar9 = iVar5;
            if (iVar5 < 0) {
              iVar9 = iVar5 + 7;
            }
            pbVar4 = (byte *)(iVar3 + (iVar9 >> 3) + 0x3d8);
            *pbVar4 = (byte)(1 << (iVar5 + (iVar9 >> 3) * -8 & 0x3fU)) | *pbVar4;
            iVar10 = iVar10 + 1;
          } while (iVar10 < *(int *)(iVar2 + 0x38));
        }
        param_4 = *(int *)(iVar2 + 0x38) - param_4;
        *(int *)(iVar3 + 0x24) = param_4 + *(int *)(iVar3 + 0x24);
        *(int *)(iVar2 + 0xcc) = param_4 + *(int *)(iVar2 + 0xcc);
        piVar1 = (int *)(*(int *)(iVar2 + ((int)param_2 >> (*(uint *)(iVar2 + 0x70) & 0x3f)) * 4 +
                                 0x2d8) + 0xc + (param_2 & ~*(uint *)(iVar2 + 0x6c)) * 0x10);
        *piVar1 = param_4 + *piVar1;
        *(char *)(iVar2 + 0xd0) = *(char *)(iVar2 + 0xd0) + '\x01';
        piVar1 = (int *)(iVar3 + 0x34 + param_4 * 4);
        *piVar1 = *piVar1 + 1;
        goto loc_4034326;
      }
    }
    else {
      iStack_3c = param_3;
      iStack_40 = iVar3;
      puStack_38 = (undefined4 *)iVar7;
      iVar8 = _mapsearch(iVar2);
      if (-1 < iVar8) {
        iVar10 = 0;
        if (0 < param_4) {
          do {
            iVar5 = iVar10 + iVar8;
            iVar9 = iVar5;
            if (iVar5 < 0) {
              iVar9 = iVar5 + 7;
            }
            pbVar4 = (byte *)(iVar3 + (iVar9 >> 3) + 0x3d8);
            *pbVar4 = ~(byte)(1 << (iVar5 + (iVar9 >> 3) * -8 & 0x3fU)) & *pbVar4;
            iVar10 = iVar10 + 1;
          } while (iVar10 < param_4);
        }
        *(int *)(iVar3 + 0x24) = *(int *)(iVar3 + 0x24) - param_4;
        *(int *)(iVar2 + 0xcc) = *(int *)(iVar2 + 0xcc) - param_4;
        piVar1 = (int *)(*(int *)(iVar2 + ((int)param_2 >> (*(uint *)(iVar2 + 0x70) & 0x3f)) * 4 +
                                 0x2d8) + 0xc + (param_2 & ~*(uint *)(iVar2 + 0x6c)) * 0x10);
        *piVar1 = *piVar1 - param_4;
        *(char *)(iVar2 + 0xd0) = *(char *)(iVar2 + 0xd0) + '\x01';
        piVar1 = (int *)(iVar3 + 0x34 + iVar7 * 4);
        *piVar1 = *piVar1 + -1;
        if (iVar7 != param_4) {
          piVar1 = (int *)(iVar3 + 0x34 + (iVar7 - param_4) * 4);
          *piVar1 = *piVar1 + 1;
        }
        iStack_3c = 0x40343ca;
        puStack_38 = (undefined4 *)iVar6;
        _bdwrite();
        return iVar8 + *(int *)(iVar2 + 0xbc) * param_2;
      }
    }
  }
  iStack_3c = 0x4034352;
  puStack_38 = (undefined4 *)iVar6;
  _brelse();
  return 0;
}
/* GHIDRADEC_FUNCTION index=983 start=0x40343de */

int _alloccgblk(int param_1,int param_2,uint param_3)

{
  int *piVar1;
  sword *psVar2;
  uint uVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  sword *psVar12;
  
  if (param_3 == 0) {
    iVar7 = *(int *)(param_2 + 0x28);
  }
  else {
    iVar7 = (int)(-*(int *)(param_1 + 0x38) & param_3) % *(int *)(param_1 + 0xbc);
    iVar8 = _isblock(param_1,param_2 + 0x3d8,iVar7 >> (*(uint *)(param_1 + 0x60) & 0x3f));
    if (iVar8 != 0) goto loc_40345A8;
    iVar8 = *(int *)(param_1 + 0x7c);
    iVar11 = *(int *)(param_1 + 0xac);
    iVar10 = (iVar8 * iVar7) / iVar11;
    if (*(int *)(param_2 + 0x54 + iVar10 * 4) != 0) {
      if (*(int *)(param_1 + 0x358) == 0) {
        iVar7 = (iVar10 * iVar11 + -1 + iVar8) / iVar8;
      }
      else {
        psVar2 = (sword *)(param_2 + iVar10 * 0x10 + 0xd4);
        iVar11 = (((iVar8 * iVar7) % iVar11) % *(int *)(param_1 + 0xa8) << 3) /
                 *(int *)(param_1 + 0xa8);
        iVar8 = iVar11;
        if (iVar11 < 8) {
          psVar12 = psVar2 + iVar11;
          do {
            if (0 < *psVar12) break;
            psVar12 = psVar12 + 1;
            iVar8 = iVar8 + 1;
          } while (iVar8 < 8);
        }
        if ((iVar8 == 8) && (iVar8 = 0, psVar12 = psVar2, 0 < iVar11)) {
          do {
            if (0 < *psVar12) goto loc_40344C4;
            iVar8 = iVar8 + 1;
            psVar12 = psVar12 + 1;
          } while (iVar8 < iVar11);
        }
        if (0 < psVar2[iVar8]) {
loc_40344C4:
          iVar9 = iVar10 % *(int *)(param_1 + 0x358);
          iVar5 = *(int *)(param_1 + 0xac);
          iVar11 = *(int *)(param_1 + 0x7c);
          uVar3 = *(uint *)(param_1 + 0x60);
          iVar7 = param_1 + iVar9 * 0x10 + 0x35c;
          if (*(sword *)(iVar7 + iVar8 * 2) == -1) {
            _printf(aPosDIDFsS,iVar9,iVar8,param_1 + 0xd4);
                    /* WARNING: Subroutine does not return */
            _panic(aAlloccgblkCylG);
          }
          iVar8 = (int)*(sword *)(iVar7 + iVar8 * 2);
          while( true ) {
            iVar7 = iVar8 + (iVar5 * (iVar10 - iVar9)) / (iVar11 << (uVar3 & 0x3f));
            iVar6 = _isblock(param_1,param_2 + 0x3d8,iVar7);
            if (iVar6 != 0) break;
            bVar4 = *(byte *)(param_1 + iVar8 + 0x560);
            if ((bVar4 == 0) || (0x1a9eU - iVar8 < (uint)bVar4)) {
              _printf(aPosDIDFsS,iVar9,iVar8,param_1 + 0xd4);
                    /* WARNING: Subroutine does not return */
              _panic(aAlloccgblkCanT);
            }
            iVar8 = (uint)bVar4 + iVar8;
          }
          iVar7 = iVar7 << (*(uint *)(param_1 + 0x60) & 0x3f);
          goto loc_40345A8;
        }
      }
    }
  }
  iVar7 = _mapsearch(param_1,param_2,iVar7,*(undefined4 *)(param_1 + 0x38));
  if (iVar7 < 0) {
    return 0;
  }
  *(int *)(param_2 + 0x28) = iVar7;
loc_40345A8:
  _clrblock(param_1,param_2 + 0x3d8,iVar7 >> (*(uint *)(param_1 + 0x60) & 0x3f));
  *(int *)(param_2 + 0x1c) = *(int *)(param_2 + 0x1c) + -1;
  *(int *)(param_1 + 0xc4) = *(int *)(param_1 + 0xc4) + -1;
  piVar1 = (int *)(*(int *)(param_1 + ((int)*(uint *)(param_2 + 0xc) >>
                                      (*(uint *)(param_1 + 0x70) & 0x3f)) * 4 + 0x2d8) + 4 +
                  (~*(uint *)(param_1 + 0x6c) & *(uint *)(param_2 + 0xc)) * 0x10);
  *piVar1 = *piVar1 + -1;
  iVar8 = *(int *)(param_1 + 0x7c) * iVar7;
  iVar11 = iVar8 / *(int *)(param_1 + 0xac);
  psVar2 = (sword *)(param_2 + iVar11 * 0x10 + 0xd4 +
                    (((iVar8 % *(int *)(param_1 + 0xac)) % *(int *)(param_1 + 0xa8) << 3) /
                    *(int *)(param_1 + 0xa8)) * 2);
  *psVar2 = *psVar2 + -1;
  piVar1 = (int *)(param_2 + 0x54 + iVar11 * 4);
  *piVar1 = *piVar1 + -1;
  *(char *)(param_1 + 0xd0) = *(char *)(param_1 + 0xd0) + '\x01';
  return iVar7 + *(int *)(param_1 + 0xbc) * *(int *)(param_2 + 0xc);
}
/* GHIDRADEC_FUNCTION index=984 start=0x4034634 */

int _ialloccg(int param_1,uint param_2,int param_3,uint param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 auStack_c [2];
  
  iVar2 = *(int *)(param_1 + 0x4e);
  if (*(int *)(*(int *)(iVar2 + ((int)param_2 >> (*(uint *)(iVar2 + 0x70) & 0x3f)) * 4 + 0x2d8) + 8
              + (param_2 & ~*(uint *)(iVar2 + 0x6c)) * 0x10) == 0) {
    return 0;
  }
  iVar5 = _bread(*(undefined4 *)(param_1 + 0x3e),
                 *(int *)(iVar2 + 0xc) +
                 *(int *)(iVar2 + 0x18) * (param_2 & ~*(uint *)(iVar2 + 0x1c)) +
                 param_2 * *(int *)(iVar2 + 0xbc) << (*(uint *)(iVar2 + 100) & 0x3f),
                 *(undefined4 *)(iVar2 + 0xa0));
  iVar3 = *(int *)(iVar5 + 0x20);
  if ((((*(byte *)(iVar5 + 3) & 4) != 0) || (*(int *)(iVar3 + 0x3d4) != 0x90255)) ||
     (*(int *)(iVar3 + 0x20) == 0)) {
    _brelse(iVar5);
    return 0;
  }
  _getthetime(auStack_c);
  *(undefined4 *)(iVar3 + 8) = auStack_c[0];
  if (param_3 != 0) {
    uVar7 = param_3 % *(int *)(iVar2 + 0xb8);
    uVar6 = uVar7;
    if ((int)uVar7 < 0) {
      uVar6 = uVar7 + 7;
    }
    if (((int)*(char *)(iVar3 + ((int)uVar6 >> 3) + 0x2d4) &
        1 << (uVar7 + ((int)uVar6 >> 3) * -8 & 0x1f)) == 0) goto loc_40347EC;
  }
  iVar10 = *(int *)(iVar3 + 0x30);
  iVar9 = iVar10;
  if (iVar10 < 0) {
    iVar9 = iVar10 + 7;
  }
  iVar9 = iVar9 >> 3;
  iVar10 = *(int *)(iVar2 + 0xb8) - iVar10;
  iVar8 = iVar10 + 7;
  if (iVar8 < 0) {
    iVar8 = iVar10 + 0xe;
  }
  iVar8 = iVar8 >> 3;
  iVar10 = _skpc(0xff,iVar8,iVar3 + iVar9 + 0x2d4);
  if (iVar10 == 0) {
    iVar8 = iVar9 + 1;
    iVar9 = 0;
    iVar10 = _skpc(0xff,iVar8,iVar3 + 0x2d4);
    if (iVar10 == 0) {
      _printf(aCgSIrotorDFsS,param_2,*(undefined4 *)(iVar3 + 0x30),iVar2 + 0xd4);
                    /* WARNING: Subroutine does not return */
      _panic(aIalloccgMapCor);
    }
  }
  iVar10 = (iVar8 + iVar9) - iVar10;
  uVar7 = iVar10 * 8;
  uVar6 = 1;
  while ((uVar6 & (int)*(char *)(iVar3 + iVar10 + 0x2d4)) != 0) {
    uVar6 = uVar6 * 2;
    uVar7 = uVar7 + 1;
    if (0xff < (int)uVar6) {
      _printf(aFsS,iVar2 + 0xd4);
                    /* WARNING: Subroutine does not return */
      _panic(aIalloccgBlockN);
    }
  }
  *(uint *)(iVar3 + 0x30) = uVar7;
loc_40347EC:
  uVar6 = uVar7;
  if ((int)uVar7 < 0) {
    uVar6 = uVar7 + 7;
  }
  pbVar4 = (byte *)(iVar3 + ((int)uVar6 >> 3) + 0x2d4);
  *pbVar4 = *pbVar4 | '\x01' << (uVar7 & 7);
  *(int *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + -1;
  *(int *)(iVar2 + 200) = *(int *)(iVar2 + 200) + -1;
  piVar1 = (int *)(*(int *)(iVar2 + ((int)param_2 >> (*(uint *)(iVar2 + 0x70) & 0x3f)) * 4 + 0x2d8)
                   + 8 + (param_2 & ~*(uint *)(iVar2 + 0x6c)) * 0x10);
  *piVar1 = *piVar1 + -1;
  *(char *)(iVar2 + 0xd0) = *(char *)(iVar2 + 0xd0) + '\x01';
  if ((param_4 & 0xf000) == 0x4000) {
    *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) + 1;
    *(int *)(iVar2 + 0xc0) = *(int *)(iVar2 + 0xc0) + 1;
    piVar1 = (int *)(*(int *)(iVar2 + ((int)param_2 >> (*(uint *)(iVar2 + 0x70) & 0x3f)) * 4 + 0x2d8
                             ) + (param_2 & ~*(uint *)(iVar2 + 0x6c)) * 0x10);
    *piVar1 = *piVar1 + 1;
  }
  _bdwrite(iVar5);
  return uVar7 + *(int *)(iVar2 + 0xb8) * param_2;
}
/* GHIDRADEC_FUNCTION index=985 start=0x4034882 */

void _free_block(int param_1,int param_2,uint param_3)

{
  int *piVar1;
  sword *psVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  undefined4 auStack_c [2];
  
  iVar4 = *(int *)(param_1 + 0x4e);
  if ((*(uint *)(iVar4 + 0x30) < param_3) || ((param_3 & ~*(uint *)(iVar4 + 0x4c)) != 0)) {
    _printf(aDev0xXBsizeDSi,(int)*(sword *)(param_1 + 0x44),*(uint *)(iVar4 + 0x30),param_3,
            iVar4 + 0xd4);
                    /* WARNING: Subroutine does not return */
    _panic(aFreeBlockBadSi);
  }
  uVar14 = param_2 / *(int *)(iVar4 + 0xbc);
  iVar7 = _badblock(iVar4,param_2);
  if (iVar7 == 0) {
    iVar8 = _bread(*(undefined4 *)(param_1 + 0x3e),
                   *(int *)(iVar4 + 0xc) +
                   *(int *)(iVar4 + 0x18) * (uVar14 & ~*(uint *)(iVar4 + 0x1c)) +
                   *(int *)(iVar4 + 0xbc) * uVar14 << (*(uint *)(iVar4 + 100) & 0x3f),
                   *(undefined4 *)(iVar4 + 0xa0));
    iVar7 = *(int *)(iVar8 + 0x20);
    if (((*(byte *)(iVar8 + 3) & 4) == 0) && (*(int *)(iVar7 + 0x3d4) == 0x90255)) {
      _getthetime(auStack_c);
      *(undefined4 *)(iVar7 + 8) = auStack_c[0];
      uVar13 = param_2 % *(int *)(iVar4 + 0xbc);
      if (param_3 == *(uint *)(iVar4 + 0x30)) {
        iVar9 = _isblock(iVar4,iVar7 + 0x3d8,(int)uVar13 >> (*(uint *)(iVar4 + 0x60) & 0x3f));
        if (iVar9 != 0) {
          _printf(aDev0xXBlockDFs,(int)*(sword *)(param_1 + 0x44),uVar13,iVar4 + 0xd4);
                    /* WARNING: Subroutine does not return */
          _panic(aFreeBlockFreei);
        }
        _setblock(iVar4,iVar7 + 0x3d8,(int)uVar13 >> (*(uint *)(iVar4 + 0x60) & 0x3f));
        *(int *)(iVar7 + 0x1c) = *(int *)(iVar7 + 0x1c) + 1;
        *(int *)(iVar4 + 0xc4) = *(int *)(iVar4 + 0xc4) + 1;
        piVar1 = (int *)(*(int *)(iVar4 + ((int)uVar14 >> (*(uint *)(iVar4 + 0x70) & 0x3f)) * 4 +
                                 0x2d8) + 4 + (uVar14 & ~*(uint *)(iVar4 + 0x6c)) * 0x10);
        *piVar1 = *piVar1 + 1;
        iVar9 = *(int *)(iVar4 + 0x7c) * uVar13;
        iVar12 = iVar9 / *(int *)(iVar4 + 0xac);
        psVar2 = (sword *)(iVar7 + iVar12 * 0x10 + 0xd4 +
                          (((iVar9 % *(int *)(iVar4 + 0xac)) % *(int *)(iVar4 + 0xa8) << 3) /
                          *(int *)(iVar4 + 0xa8)) * 2);
        *psVar2 = *psVar2 + 1;
        piVar1 = (int *)(iVar7 + 0x54 + iVar12 * 4);
        *piVar1 = *piVar1 + 1;
      }
      else {
        uVar6 = uVar13 & -*(int *)(iVar4 + 0x38);
        uVar10 = uVar6;
        if ((int)uVar6 < 0) {
          uVar10 = uVar6 + 7;
        }
        _fragacct(iVar4,0xff >> (8U - *(int *)(iVar4 + 0x38) & 0x3f) &
                        (int)(uint)*(byte *)(iVar7 + ((int)uVar10 >> 3) + 0x3d8) >>
                        (uVar6 + ((int)uVar10 >> 3) * -8 & 0x3f),iVar7 + 0x34,0xffffffff);
        param_3 = param_3 >> (*(uint *)(iVar4 + 0x54) & 0x3f);
        iVar9 = 0;
        if (0 < (int)param_3) {
          do {
            iVar12 = iVar9 + uVar13;
            iVar11 = iVar12;
            if (iVar12 < 0) {
              iVar11 = iVar12 + 7;
            }
            iVar3 = iVar7 + (iVar11 >> 3);
            uVar10 = iVar12 + (iVar11 >> 3) * -8;
            if (((int)*(char *)(iVar3 + 0x3d8) & 1 << (uVar10 & 0x1f)) != 0) {
              _printf(aDev0xXBlockDFs,(int)*(sword *)(param_1 + 0x44),iVar12,iVar4 + 0xd4);
                    /* WARNING: Subroutine does not return */
              _panic(aFreeBlockFreei_0);
            }
            pbVar5 = (byte *)(iVar3 + 0x3d8);
            *pbVar5 = *pbVar5 | '\x01' << (uVar10 & 7);
            iVar9 = iVar9 + 1;
          } while (iVar9 < (int)param_3);
        }
        *(int *)(iVar7 + 0x24) = iVar9 + *(int *)(iVar7 + 0x24);
        *(int *)(iVar4 + 0xcc) = iVar9 + *(int *)(iVar4 + 0xcc);
        piVar1 = (int *)(*(int *)(iVar4 + ((int)uVar14 >> (*(uint *)(iVar4 + 0x70) & 0x3f)) * 4 +
                                 0x2d8) + 0xc + (uVar14 & ~*(uint *)(iVar4 + 0x6c)) * 0x10);
        *piVar1 = iVar9 + *piVar1;
        uVar13 = uVar6;
        if ((int)uVar6 < 0) {
          uVar13 = uVar6 + 7;
        }
        _fragacct(iVar4,0xff >> (8U - *(int *)(iVar4 + 0x38) & 0x3f) &
                        (int)(uint)*(byte *)(iVar7 + ((int)uVar13 >> 3) + 0x3d8) >>
                        (uVar6 + ((int)uVar13 >> 3) * -8 & 0x3f),iVar7 + 0x34,1);
        iVar9 = _isblock(iVar4,iVar7 + 0x3d8,(int)uVar6 >> (*(uint *)(iVar4 + 0x60) & 0x3f));
        if (iVar9 != 0) {
          *(int *)(iVar7 + 0x24) = *(int *)(iVar7 + 0x24) - *(int *)(iVar4 + 0x38);
          *(int *)(iVar4 + 0xcc) = *(int *)(iVar4 + 0xcc) - *(int *)(iVar4 + 0x38);
          piVar1 = (int *)(*(int *)(iVar4 + ((int)uVar14 >> (*(uint *)(iVar4 + 0x70) & 0x3f)) * 4 +
                                   0x2d8) + 0xc + (uVar14 & ~*(uint *)(iVar4 + 0x6c)) * 0x10);
          *piVar1 = *piVar1 - *(int *)(iVar4 + 0x38);
          *(int *)(iVar7 + 0x1c) = *(int *)(iVar7 + 0x1c) + 1;
          *(int *)(iVar4 + 0xc4) = *(int *)(iVar4 + 0xc4) + 1;
          piVar1 = (int *)(*(int *)(iVar4 + ((int)uVar14 >> (*(uint *)(iVar4 + 0x70) & 0x3f)) * 4 +
                                   0x2d8) + 4 + (uVar14 & ~*(uint *)(iVar4 + 0x6c)) * 0x10);
          *piVar1 = *piVar1 + 1;
          iVar9 = *(int *)(iVar4 + 0x7c) * uVar6;
          iVar12 = iVar9 / *(int *)(iVar4 + 0xac);
          psVar2 = (sword *)(iVar7 + iVar12 * 0x10 + 0xd4 +
                            (((iVar9 % *(int *)(iVar4 + 0xac)) % *(int *)(iVar4 + 0xa8) << 3) /
                            *(int *)(iVar4 + 0xa8)) * 2);
          *psVar2 = *psVar2 + 1;
          piVar1 = (int *)(iVar7 + 0x54 + iVar12 * 4);
          *piVar1 = *piVar1 + 1;
        }
      }
      *(char *)(iVar4 + 0xd0) = *(char *)(iVar4 + 0xd0) + '\x01';
      _bdwrite(iVar8);
      if (((*(byte *)(iVar4 + 0xd3) & 1) != 0) &&
         (*(int *)(iVar4 + 0x88) <
          *(int *)(iVar4 + 0xcc) + (*(int *)(iVar4 + 0xc4) << (*(uint *)(iVar4 + 0x60) & 0x3f)))) {
        _wakeup(iVar4 + 0xcc);
        *(byte *)(iVar4 + 0xd3) = *(byte *)(iVar4 + 0xd3) & 0xfe;
      }
    }
    else {
      _brelse(iVar8);
    }
  }
  else {
    _printf(aBadBlockDInoD,param_2,*(undefined4 *)(param_1 + 0x46));
  }
  return;
}
/* GHIDRADEC_FUNCTION index=986 start=0x4034c66 */

void _ifree(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  uint uVar6;
  int iVar7;
  undefined4 auStack_c [2];
  
  iVar3 = *(int *)(param_1 + 0x4e);
  uVar6 = *(int *)(iVar3 + 0x2c) * *(int *)(iVar3 + 0xb8);
  if (uVar6 < param_2 || uVar6 - param_2 == 0) {
    _printf(aDev0xXInoDFsS,(int)*(sword *)(param_1 + 0x44),param_2,iVar3 + 0xd4);
                    /* WARNING: Subroutine does not return */
    _panic(aIfreeRange);
  }
  uVar6 = param_2 / *(uint *)(iVar3 + 0xb8);
  iVar7 = _bread(*(undefined4 *)(param_1 + 0x3e),
                 *(int *)(iVar3 + 0xc) +
                 *(int *)(iVar3 + 0x18) * (uVar6 & ~*(uint *)(iVar3 + 0x1c)) +
                 uVar6 * *(int *)(iVar3 + 0xbc) << (*(uint *)(iVar3 + 100) & 0x3f),
                 *(undefined4 *)(iVar3 + 0xa0));
  iVar4 = *(int *)(iVar7 + 0x20);
  if (((*(byte *)(iVar7 + 3) & 4) == 0) && (*(int *)(iVar4 + 0x3d4) == 0x90255)) {
    _getthetime(auStack_c);
    *(undefined4 *)(iVar4 + 8) = auStack_c[0];
    param_2 = param_2 % *(uint *)(iVar3 + 0xb8);
    iVar1 = iVar4 + (param_2 >> 3);
    if (((int)*(char *)(iVar1 + 0x2d4) & 1 << (param_2 & 7)) == 0) {
      _printf(aDev0xXInoDFsS,(int)*(sword *)(param_1 + 0x44),param_2,iVar3 + 0xd4);
                    /* WARNING: Subroutine does not return */
      _panic(aIfreeFreeingFr);
    }
    pbVar5 = (byte *)(iVar1 + 0x2d4);
    *pbVar5 = *pbVar5 & ~('\x01' << (param_2 & 7));
    if (param_2 < *(uint *)(iVar4 + 0x30)) {
      *(uint *)(iVar4 + 0x30) = param_2;
    }
    *(int *)(iVar4 + 0x20) = *(int *)(iVar4 + 0x20) + 1;
    *(int *)(iVar3 + 200) = *(int *)(iVar3 + 200) + 1;
    piVar2 = (int *)(*(int *)(iVar3 + ((int)uVar6 >> (*(uint *)(iVar3 + 0x70) & 0x3f)) * 4 + 0x2d8)
                     + 8 + (uVar6 & ~*(uint *)(iVar3 + 0x6c)) * 0x10);
    *piVar2 = *piVar2 + 1;
    if ((param_3 & 0xf000) == 0x4000) {
      *(int *)(iVar4 + 0x18) = *(int *)(iVar4 + 0x18) + -1;
      *(int *)(iVar3 + 0xc0) = *(int *)(iVar3 + 0xc0) + -1;
      piVar2 = (int *)(*(int *)(iVar3 + ((int)uVar6 >> (*(uint *)(iVar3 + 0x70) & 0x3f)) * 4 + 0x2d8
                               ) + (uVar6 & ~*(uint *)(iVar3 + 0x6c)) * 0x10);
      *piVar2 = *piVar2 + -1;
    }
    *(char *)(iVar3 + 0xd0) = *(char *)(iVar3 + 0xd0) + '\x01';
    _bdwrite(iVar7);
    if (((*(byte *)(iVar3 + 0xd3) & 2) != 0) && (*(int *)(iVar3 + 0x90) < *(int *)(iVar3 + 200))) {
      _wakeup(iVar3 + 200);
      *(byte *)(iVar3 + 0xd3) = *(byte *)(iVar3 + 0xd3) & 0xfd;
    }
  }
  else {
    _brelse(iVar7);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=987 start=0x4034e16 */

int _mapsearch(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  if (param_3 == 0) {
    param_3 = *(int *)(param_2 + 0x2c);
    if (param_3 < 0) {
      param_3 = param_3 + 7;
    }
  }
  else {
    param_3 = param_3 % *(int *)(param_1 + 0xbc);
    if (param_3 < 0) {
      param_3 = param_3 + 7;
    }
  }
  param_3 = param_3 >> 3;
  iVar6 = *(int *)(param_1 + 0xbc) + 7;
  if (iVar6 < 0) {
    iVar6 = *(int *)(param_1 + 0xbc) + 0xe;
  }
  iVar6 = (iVar6 >> 3) - param_3;
  iVar2 = _scanc(iVar6,param_2 + param_3 + 0x3d8,
                 *(undefined4 *)(_fragtbl + *(int *)(param_1 + 0x38) * 4),
                 1 << (param_4 + -1 + *(int *)(param_1 + 0x38) % 8 & 0x3fU));
  if (iVar2 == 0) {
    iVar6 = param_3 + 1;
    param_3 = 0;
    iVar2 = _scanc(iVar6,param_2 + 0x3d8,*(undefined4 *)(_fragtbl + *(int *)(param_1 + 0x38) * 4),
                   1 << (param_4 + -1 + *(int *)(param_1 + 0x38) % 8 & 0x3fU));
    if (iVar2 == 0) {
      _printf(aStartDLenDFsS,0,iVar6,param_1 + 0xd4);
                    /* WARNING: Subroutine does not return */
      _panic(aAlloccgMapCorr);
    }
  }
  iVar2 = ((iVar6 + param_3) - iVar2) * 8;
  *(int *)(param_2 + 0x2c) = iVar2;
  iVar6 = iVar2 + 8;
  do {
    if (iVar6 <= iVar2) {
      _printf(aBnoDFsS,iVar2,param_1 + 0xd4);
                    /* WARNING: Subroutine does not return */
      _panic(aAlloccgBlockNo);
    }
    iVar3 = iVar2;
    if (iVar2 < 0) {
      iVar3 = iVar2 + 7;
    }
    uVar5 = (&_around)[param_4];
    uVar4 = (&_inside)[param_4];
    iVar7 = 0;
    iVar1 = *(int *)(param_1 + 0x38) - param_4;
    if (-1 < iVar1) {
      do {
        if (uVar4 == (uVar5 & (0xff >> (8U - *(int *)(param_1 + 0x38) & 0x3f) &
                              (int)(uint)*(byte *)((iVar3 >> 3) + param_2 + 0x3d8) >>
                              (iVar2 + (iVar3 >> 3) * -8 & 0x3fU)) * 2)) {
          return iVar7 + iVar2;
        }
        uVar5 = uVar5 * 2;
        uVar4 = uVar4 * 2;
        iVar7 = iVar7 + 1;
      } while (iVar7 <= iVar1);
    }
    iVar2 = *(int *)(param_1 + 0x38) + iVar2;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=988 start=0x4034fcc */

void _fserr(int param_1,undefined4 param_2)

{
  _log(3,&aSS,param_1 + 0xd4,param_2);
  return;
}
/* GHIDRADEC_FUNCTION index=989 start=0x4034ff4 */

int _bmap(int param_1,int param_2,uint param_3,int param_4,undefined4 *param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iStack_14;
  int iStack_10;
  int iStack_8;
  
  iStack_8 = 0;
  iStack_10 = 0;
  if (param_2 < 0) {
loc_40352C4:
    *(undefined *)(dword_40B57D4 + 100) = 0x1b;
    return 0;
  }
  iVar1 = *(int *)(param_1 + 0x4e);
  _rablock = 0;
  _rasize = 0;
  if ((param_3 & 0x20) != 0) {
    param_3 = param_3 & 0xffffffdf;
  }
  uVar4 = *(uint *)(param_1 + 0x6e);
  uVar7 = uVar4 >> (*(uint *)(iVar1 + 0x50) & 0x3f);
  if ((((param_3 == 0) && ((int)uVar7 < 0xc)) && ((int)uVar7 < param_2)) &&
     (*(int *)(param_1 + uVar7 * 4 + 0x8a) != 0)) {
    if (((int)uVar7 < 0xc) && (uVar4 < uVar7 + 1 << (*(uint *)(iVar1 + 0x50) & 0x3f))) {
      uVar4 = *(uint *)(iVar1 + 0x4c) &
              (*(int *)(iVar1 + 0x34) + (uVar4 & ~*(uint *)(iVar1 + 0x48))) - 1;
    }
    else {
      uVar4 = *(uint *)(iVar1 + 0x30);
    }
    if ((uVar4 < *(uint *)(iVar1 + 0x30)) && (uVar4 != 0)) {
      uVar2 = _blkpref(param_1,uVar7,uVar7,param_1 + 0x8a,uVar4,*(uint *)(iVar1 + 0x30));
      iVar8 = param_1 + uVar7 * 4;
      iVar3 = _realloccg(param_1,*(undefined4 *)(iVar8 + 0x8a),uVar2);
      if (iVar3 == 0) {
        return -1;
      }
      *(uint *)(param_1 + 0x6e) = *(int *)(iVar1 + 0x30) * (uVar7 + 1);
      *(int *)(iVar8 + 0x8a) = *(int *)(iVar3 + 0x24) >> (*(uint *)(iVar1 + 100) & 0x3f);
      *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x42;
      if (param_5 == (undefined4 *)0x0) {
        _bdwrite(iVar3);
      }
      else {
        _bwrite(iVar3);
        _iupdat(param_1,1);
      }
    }
  }
  if (param_2 < 0xc) {
    iVar8 = *(int *)(param_1 + param_2 * 4 + 0x8a);
    if (param_3 == 1) {
      if (iVar8 == 0) {
        return -1;
      }
      goto loc_4035240;
    }
    if (iVar8 == 0) {
      uVar4 = *(uint *)(iVar1 + 0x30);
      uVar7 = uVar4 * (param_2 + 1);
      if (*(uint *)(param_1 + 0x6e) <= uVar7 && uVar7 - *(uint *)(param_1 + 0x6e) != 0) {
        uVar4 = *(uint *)(iVar1 + 0x4c) & (*(int *)(iVar1 + 0x34) + param_4) - 1U;
      }
      uVar2 = _blkpref(param_1,param_2,param_2,param_1 + 0x8a,uVar4);
      iVar3 = _alloc(param_1,uVar2);
    }
    else {
      uVar7 = *(int *)(iVar1 + 0x30) * (param_2 + 1);
      uVar4 = *(uint *)(param_1 + 0x6e);
      if (uVar7 < uVar4 || uVar7 - uVar4 == 0) goto loc_4035240;
      uVar4 = *(uint *)(iVar1 + 0x4c) &
              *(int *)(iVar1 + 0x34) + -1 + (uVar4 & ~*(uint *)(iVar1 + 0x48));
      uVar7 = *(uint *)(iVar1 + 0x4c) & *(int *)(iVar1 + 0x34) + -1 + param_4;
      if (uVar7 <= uVar4) goto loc_4035240;
      uVar2 = _blkpref(param_1,param_2,param_2,param_1 + 0x8a,uVar4,uVar7);
      iVar3 = _realloccg(param_1,iVar8,uVar2);
    }
    if (iVar3 != 0) {
      iVar8 = *(int *)(iVar3 + 0x24) >> (*(uint *)(iVar1 + 100) & 0x3f);
      if (param_5 != (undefined4 *)0x0) {
        *param_5 = 1;
      }
      if ((*(word *)(param_1 + 0x62) & 0xf000) == 0x4000) {
        _bwrite(iVar3);
      }
      else {
        _bdwrite(iVar3);
      }
      *(int *)(param_1 + param_2 * 4 + 0x8a) = iVar8;
      *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x42;
loc_4035240:
      if (10 < param_2) {
        return iVar8;
      }
      _rablock = *(int *)(param_1 + param_2 * 4 + 0x8e) << (*(uint *)(iVar1 + 100) & 0x3f);
      if ((param_2 + 1 < 0xc) &&
         (*(uint *)(param_1 + 0x6e) < (uint)(param_2 + 2 << (*(uint *)(iVar1 + 0x50) & 0x3f)))) {
        _rasize = *(uint *)(iVar1 + 0x4c) &
                  (*(int *)(iVar1 + 0x34) + (*(uint *)(param_1 + 0x6e) & ~*(uint *)(iVar1 + 0x48)))
                  - 1;
        return iVar8;
      }
      _rasize = *(undefined4 *)(iVar1 + 0x30);
      return iVar8;
    }
  }
  else {
    iStack_14 = 0;
    iVar10 = 1;
    iVar8 = param_2 + -0xc;
    iVar3 = 3;
    do {
      iVar10 = *(int *)(iVar1 + 0x74) * iVar10;
      if (iVar10 - iVar8 != 0 && iVar8 <= iVar10) break;
      iVar8 = iVar8 - iVar10;
      iVar3 = iVar3 + -1;
    } while (0 < iVar3);
    if (iVar3 == 0) goto loc_40352C4;
    iVar6 = param_1 + (3 - iVar3) * 4;
    iVar9 = *(int *)(iVar6 + 0xba);
    if (iVar9 == 0) {
      if (param_3 == 1) {
        return -1;
      }
      iStack_14 = _blkpref(param_1,param_2,0,0);
      iVar5 = _alloc(param_1,iStack_14,*(undefined4 *)(iVar1 + 0x30));
      if (iVar5 == 0) {
        return -1;
      }
      iVar9 = *(int *)(iVar5 + 0x24) >> (*(uint *)(iVar1 + 100) & 0x3f);
      _bwrite(iVar5);
      *(int *)(iVar6 + 0xba) = iVar9;
      *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x42;
      if (param_5 != (undefined4 *)0x0) {
        *param_5 = 1;
      }
    }
    while( true ) {
      if (3 < iVar3) {
        if (iStack_8 < *(int *)(iVar1 + 0x74) + -1) {
          _rablock = *(int *)(iStack_10 + 4 + iStack_8 * 4) << (*(uint *)(iVar1 + 100) & 0x3f);
          _rasize = *(undefined4 *)(iVar1 + 0x30);
          return iVar9;
        }
        return iVar9;
      }
      iVar6 = _bread(*(undefined4 *)(param_1 + 0x3e),iVar9 << (*(uint *)(iVar1 + 100) & 0x3f),
                     *(undefined4 *)(iVar1 + 0x30));
      if ((*(byte *)(iVar6 + 3) & 4) != 0) {
        _brelse(iVar6);
        return 0;
      }
      iStack_10 = *(int *)(iVar6 + 0x20);
      iVar10 = iVar10 / *(int *)(iVar1 + 0x74);
      iStack_8 = (iVar8 / iVar10) % *(int *)(iVar1 + 0x74);
      iVar9 = *(int *)(iStack_10 + iStack_8 * 4);
      if (iVar9 == 0) break;
      _brelse(iVar6);
loc_403547A:
      iVar3 = iVar3 + 1;
    }
    if (param_3 != 1) {
      if (iStack_14 == 0) {
        iVar9 = iStack_8;
        iVar5 = iStack_10;
        if (iVar3 < 3) {
          iVar9 = 0;
          iVar5 = 0;
        }
        iStack_14 = _blkpref(param_1,param_2,iVar9,iVar5);
      }
      iVar5 = _alloc(param_1,iStack_14,*(undefined4 *)(iVar1 + 0x30));
      if (iVar5 != 0) {
        iVar9 = *(int *)(iVar5 + 0x24) >> (*(uint *)(iVar1 + 100) & 0x3f);
        if (((iVar3 < 3) || ((*(word *)(param_1 + 0x62) & 0xf000) == 0x4000)) ||
           (param_5 != (undefined4 *)0x0)) {
          _bwrite(iVar5);
        }
        else {
          _bdwrite(iVar5);
        }
        *(int *)(iStack_10 + iStack_8 * 4) = iVar9;
        if (param_5 == (undefined4 *)0x0) {
          _bdwrite(iVar6);
        }
        else {
          _bwrite(iVar6);
        }
        goto loc_403547A;
      }
    }
    _brelse(iVar6);
  }
  return -1;
}
/* GHIDRADEC_FUNCTION index=990 start=0x40354be */

int _dirlook(int param_1,char *param_2,int *param_3)

{
  word wVar1;
  word *pwVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int *piVar10;
  int iVar11;
  
  iVar11 = 0;
  uVar7 = 0;
  uVar3 = _strlen(param_2);
  if ((*(word *)(param_1 + 0x62) & 0xf000) != 0x4000) {
    return 0x14;
  }
  iVar4 = _iaccess(param_1,0x40);
  if (iVar4 != 0) {
    return iVar4;
  }
  iVar4 = _dnlc_lookup(param_1 + 0xc,param_2,0);
  if (iVar4 != 0) {
    *(sword *)(iVar4 + 6) = *(sword *)(iVar4 + 6) + 1;
    *param_3 = *(int *)(iVar4 + 0x2e);
    while ((*(byte *)(*param_3 + 0x43) & 1) != 0) {
      pwVar2 = (word *)(*param_3 + 0x42);
      *pwVar2 = *pwVar2 | 0x10;
      _sleep(*param_3,10);
    }
    *(word *)(*param_3 + 0x42) = *(word *)(*param_3 + 0x42) | 1;
    return 0;
  }
  while ((*(word *)(param_1 + 0x42) & 1) != 0) {
    *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x10;
    _sleep(param_1,10);
  }
  *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 1;
  if (*(uint *)(param_1 + 0x6e) < *(uint *)(param_1 + 0x4a)) {
    *(undefined4 *)(param_1 + 0x4a) = 0;
  }
  uVar6 = *(uint *)(param_1 + 0x4a);
  if (uVar6 == 0) {
    uVar6 = 0;
    iVar4 = 1;
  }
  else {
    uVar7 = ~*(uint *)(*(int *)(param_1 + 0x4e) + 0x48) & uVar6;
    if ((uVar7 != 0) && (iVar11 = _blkatoff(param_1,uVar6,0), iVar11 == 0)) {
loc_4035788:
      iVar4 = (int)*(char *)(dword_40B57D4 + 100);
      goto loc_40357A6;
    }
    iVar4 = 2;
  }
  uVar8 = *(int *)(param_1 + 0x6e) + 0x3ffU & 0xfffffc00;
joined_r0x040355e2:
  for (; uVar6 < uVar8; uVar6 = uVar9 + uVar6) {
    if ((uVar6 & ~*(uint *)(*(int *)(param_1 + 0x4e) + 0x48)) == 0) {
      if (iVar11 != 0) {
        _brelse(iVar11);
      }
      iVar11 = _blkatoff(param_1,uVar6,0);
      if (iVar11 == 0) goto loc_4035788;
      uVar7 = 0;
    }
    piVar10 = (int *)(uVar7 + *(int *)(iVar11 + 0x20));
    if ((*(sword *)(piVar10 + 1) == 0) ||
       ((_dirchk != 0 && (iVar5 = sub_4036A22(param_1,piVar10,uVar7,uVar6), iVar5 != 0)))) {
      uVar9 = 0x400 - (uVar7 & 0x3ff);
    }
    else {
      if ((((*piVar10 != 0) && (uVar3 == *(word *)((int)piVar10 + 6))) &&
          (*param_2 == *(char *)(piVar10 + 2))) &&
         (iVar5 = _bcmp(param_2,piVar10 + 2,uVar3), iVar5 == 0)) {
        iVar4 = *piVar10;
        _brelse(iVar11);
        iVar11 = 0;
        *(uint *)(param_1 + 0x4a) = uVar6;
        if (((uVar3 == 2) && (*param_2 == '.')) && (param_2[1] == '.')) {
          wVar1 = *(word *)(param_1 + 0x42);
          *(word *)(param_1 + 0x42) = wVar1 & 0xfffe;
          if ((wVar1 & 0x10) != 0) {
            *(word *)(param_1 + 0x42) = wVar1 & 0xffee;
            _wakeup(param_1);
          }
          iVar4 = _iget((int)*(sword *)(param_1 + 0x44),*(undefined4 *)(param_1 + 0x4e),iVar4);
        }
        else {
          if (iVar4 == *(int *)(param_1 + 0x46)) {
            *(sword *)(param_1 + 0x12) = *(sword *)(param_1 + 0x12) + 1;
            iVar4 = param_1;
            goto loc_403574A;
          }
          iVar4 = _iget((int)*(sword *)(param_1 + 0x44),*(undefined4 *)(param_1 + 0x4e),iVar4);
          wVar1 = *(word *)(param_1 + 0x42);
          *(word *)(param_1 + 0x42) = wVar1 & 0xfffe;
          if ((wVar1 & 0x10) != 0) {
            *(word *)(param_1 + 0x42) = wVar1 & 0xffee;
            _wakeup(param_1);
          }
        }
        if (iVar4 != 0) {
loc_403574A:
          *param_3 = iVar4;
          _dnlc_enter(param_1 + 0xc,param_2,iVar4 + 0xc,0);
          return 0;
        }
        iVar4 = (int)*(char *)(dword_40B57D4 + 100);
        goto loc_40357CC;
      }
      uVar9 = (uint)*(word *)(piVar10 + 1);
    }
    uVar7 = uVar9 + uVar7;
  }
  if (iVar4 == 2) {
    iVar4 = 1;
    uVar6 = 0;
    uVar8 = *(uint *)(param_1 + 0x4a);
    goto joined_r0x040355e2;
  }
  iVar4 = 2;
loc_40357A6:
  wVar1 = *(word *)(param_1 + 0x42);
  *(word *)(param_1 + 0x42) = wVar1 & 0xfffe;
  if ((wVar1 & 0x10) != 0) {
    *(word *)(param_1 + 0x42) = wVar1 & 0xffee;
    _wakeup(param_1);
  }
loc_40357CC:
  if (iVar11 != 0) {
    _brelse(iVar11);
  }
  return iVar4;
}
/* GHIDRADEC_FUNCTION index=991 start=0x40357e4 */

/* WARNING: Type propagation algorithm not settling */

int _direnter(int param_1,char *param_2,int param_3,int param_4,int param_5,undefined4 param_6,
             int *param_7)

{
  word wVar1;
  sword sVar2;
  char cVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  int aiStack_1c [4];
  int iStack_c;
  
  piVar5 = param_7;
  iVar7 = 0;
  cVar3 = *param_2;
  pcVar8 = param_2;
  while (cVar3 != '\0') {
    if (*pcVar8 == '/') {
      return 0xd;
    }
    pcVar8 = pcVar8 + 1;
    iVar7 = iVar7 + 1;
    cVar3 = *pcVar8;
  }
  if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aDirenter);
  }
  if ((*param_2 != '.') || ((iVar7 != 1 && ((iVar7 != 2 || (param_2[1] != '.')))))) {
    aiStack_1c[1] = 0;
    iStack_c = 0;
    if (param_3 != 0) {
      while ((*(byte *)(param_5 + 0x43) & 1) != 0) {
        *(word *)(param_5 + 0x42) = *(word *)(param_5 + 0x42) | 0x10;
        _sleep(param_5,10);
      }
      wVar1 = *(word *)(param_5 + 0x42);
      *(word *)(param_5 + 0x42) = wVar1 | 1;
      sVar2 = *(sword *)(param_5 + 100);
      if (sVar2 == 0) {
        *(word *)(param_5 + 0x42) = wVar1 & 0xfffe;
        if ((wVar1 & 0x10) != 0) {
          *(word *)(param_5 + 0x42) = wVar1 & 0xffee;
          _wakeup(param_5);
        }
        return 2;
      }
      if (sVar2 == 0x7fff) {
        *(word *)(param_5 + 0x42) = wVar1 & 0xfffe;
        if ((wVar1 & 0x10) != 0) {
          *(word *)(param_5 + 0x42) = wVar1 & 0xffee;
          _wakeup(param_5);
        }
        return 0x1f;
      }
      *(sword *)(param_5 + 100) = sVar2 + 1;
      *(word *)(param_5 + 0x42) = *(word *)(param_5 + 0x42) | 0x40;
      _iupdat(param_5,1);
      wVar1 = *(word *)(param_5 + 0x42);
      *(word *)(param_5 + 0x42) = wVar1 & 0xfffe;
      if ((wVar1 & 0x10) != 0) {
        *(word *)(param_5 + 0x42) = wVar1 & 0xffee;
        _wakeup(param_5);
      }
    }
    while ((*(word *)(param_1 + 0x42) & 1) != 0) {
      *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x10;
      _sleep(param_1,10);
    }
    *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 1;
    if ((*(word *)(param_1 + 0x62) & 0xf000) == 0x4000) {
      if (*(sword *)(param_1 + 100) == 0) {
        iVar6 = 2;
      }
      else {
        iVar6 = _iaccess(param_1,0x40);
        if ((iVar6 == 0) &&
           ((((param_3 != 2 || ((*(word *)(param_5 + 0x62) & 0xf000) != 0x4000)) ||
             (param_1 == param_4)) ||
            ((iVar6 = _iaccess(param_5,0x80), iVar6 == 0 &&
             (iVar6 = sub_4036B74(param_5,param_1), iVar6 == 0)))))) {
          piVar4 = aiStack_1c + 1;
          iVar6 = sub_4035BA6(param_1,param_2,iVar7,piVar4,aiStack_1c);
          if (iVar6 == 0) {
            if (aiStack_1c[0] == 0) {
              iVar6 = _iaccess(param_1,0x80);
              if ((iVar6 == 0) &&
                 ((param_3 != 0 || (iVar6 = sub_403643A(param_1,&param_5,param_6), iVar6 == 0)))) {
                iVar6 = _diraddentry(param_1,param_2,iVar7,piVar4,param_5,param_4);
                if (iVar6 == 0) {
                  if (piVar5 == (int *)0x0) {
                    if (param_3 == 0) {
                      _irele(param_5);
                    }
                  }
                  else {
                    while ((*(byte *)(param_5 + 0x43) & 1) != 0) {
                      *(word *)(param_5 + 0x42) = *(word *)(param_5 + 0x42) | 0x10;
                      _sleep(param_5,10);
                    }
                    *(word *)(param_5 + 0x42) = *(word *)(param_5 + 0x42) | 1;
                    *piVar5 = param_5;
                  }
                }
                else if (param_3 == 0) {
                  if ((*(word *)(param_5 + 0x62) & 0xf000) == 0x4000) {
                    *(sword *)(param_1 + 100) = *(sword *)(param_1 + 100) + -1;
                  }
                  *(undefined2 *)(param_5 + 100) = 0;
                  *(word *)(param_5 + 0x42) = *(word *)(param_5 + 0x42) | 0x40;
                  _irele(param_5);
                  param_5 = 0;
                }
              }
            }
            else if (param_3 == 1) {
              _iput(aiStack_1c[0]);
              iVar6 = 0x11;
            }
            else if (param_3 == 0) {
              if (piVar5 == (int *)0x0) {
                _iput(aiStack_1c[0]);
              }
              else {
                *piVar5 = aiStack_1c[0];
                iVar6 = 0x11;
              }
            }
            else if (param_3 == 2) {
              iVar6 = sub_4035DAE(param_4,param_5,param_1,param_2,iVar7,aiStack_1c[0],piVar4);
              _iput(aiStack_1c[0]);
              if (*(sword *)(aiStack_1c[0] + 100) == 0) {
                _vnode_uncache(aiStack_1c[0] + 0xc);
              }
            }
          }
        }
      }
    }
    else {
      iVar6 = 0x14;
    }
    if (iStack_c != 0) {
      _brelse(iStack_c);
    }
    if ((iVar6 != 0) && (param_3 != 0)) {
      *(sword *)(param_5 + 100) = *(sword *)(param_5 + 100) + -1;
      *(word *)(param_5 + 0x42) = *(word *)(param_5 + 0x42) | 0x40;
    }
    wVar1 = *(word *)(param_1 + 0x42);
    *(word *)(param_1 + 0x42) = wVar1 & 0xfffe;
    if ((wVar1 & 0x10) != 0) {
      *(word *)(param_1 + 0x42) = wVar1 & 0xffee;
      _wakeup(param_1);
    }
    return iVar6;
  }
  if (param_3 == 2) {
    return 0x42;
  }
  if ((param_7 != (int *)0x0) && (iVar7 = _dirlook(param_1,param_2,param_7), iVar7 != 0)) {
    return iVar7;
  }
  return 0x11;
}
/* GHIDRADEC_FUNCTION index=992 start=0x40361ac */

int _diraddentry(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,
                undefined4 param_6)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x30) == *(int *)(param_5 + 0x30)) {
    if (((*(word *)(param_5 + 0x62) & 0xf000) == 0x4000) &&
       (iVar1 = sub_4035F40(param_5,param_6,param_1), iVar1 != 0)) {
      return iVar1;
    }
    iVar1 = sub_403627C(param_1,param_4);
    if (iVar1 == 0) {
      *(sword *)(*(int *)(param_4 + 0x10) + 6) = (sword)param_3;
      _strncpy(*(int *)(param_4 + 0x10) + 8,param_2,param_3 + 4U & 0xfffffffc);
      **(undefined4 **)(param_4 + 0x10) = *(undefined4 *)(param_5 + 0x46);
      _dnlc_enter(param_1 + 0xc,param_2,param_5 + 0xc,0);
      _bwrite(*(undefined4 *)(param_4 + 0xc));
      *(undefined4 *)(param_4 + 0xc) = 0;
      if (*(char *)(dword_40B57D4 + 100) == '\0') {
        *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x42;
        *(undefined4 *)(param_1 + 0x4a) = 0;
        iVar1 = 0;
      }
      else {
        iVar1 = (int)*(char *)(dword_40B57D4 + 100);
      }
    }
  }
  else {
    iVar1 = 0x12;
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=993 start=0x40366c4 */

/* WARNING: Type propagation algorithm not settling */

int _dirremove(int param_1,char *param_2,int param_3,int param_4)

{
  sword *psVar1;
  sword sVar2;
  word wVar3;
  int iVar4;
  int iVar5;
  int aiStack_1c [2];
  undefined2 uStack_12;
  undefined2 uStack_10;
  undefined2 uStack_e;
  int iStack_c;
  undefined4 *puStack_8;
  
  iVar4 = _strlen(param_2);
  if (iVar4 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aDirremove);
  }
  if (*param_2 == '.') {
    if (iVar4 == 1) {
      return 0x16;
    }
    if ((iVar4 == 2) && (param_2[1] == '.')) {
      return 0x42;
    }
  }
  aiStack_1c[0] = 0;
  iStack_c = 0;
  while ((*(word *)(param_1 + 0x42) & 1) != 0) {
    *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x10;
    _sleep(param_1,10);
  }
  *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 1;
  if ((*(word *)(param_1 + 0x62) & 0xf000) == 0x4000) {
    iVar5 = _iaccess(param_1,0xc0);
    if (iVar5 == 0) {
      aiStack_1c[1] = 2;
      iVar5 = sub_4035BA6(param_1,param_2,iVar4,aiStack_1c + 1,aiStack_1c);
      if (iVar5 == 0) {
        if ((aiStack_1c[0] == 0) || ((param_3 != 0 && (aiStack_1c[0] != param_3)))) {
          iVar5 = 2;
        }
        else if (((((*(byte *)(param_1 + 0x62) & 2) == 0) ||
                  (sVar2 = *(sword *)(*(int *)(_active_u + 0x1a) + 2), sVar2 == 0)) ||
                 (sVar2 == *(sword *)(param_1 + 0x66))) ||
                (sVar2 == *(sword *)(aiStack_1c[0] + 0x66))) {
          if (*(int *)(aiStack_1c[0] + 0x18) == 0) {
            if (((param_4 == 0) || ((*(word *)(aiStack_1c[0] + 0x62) & 0xf000) != 0x4000)) ||
               ((*(sword *)(aiStack_1c[0] + 100) == 2 &&
                (iVar4 = sub_4036AE4(aiStack_1c[0],*(undefined4 *)(param_1 + 0x46)), iVar4 != 0))))
            {
              _dnlc_remove(param_1 + 0xc,param_2);
              if ((CONCAT22(uStack_12,uStack_10) & 0x3ffffff) >> 0x10 == 0) {
                *puStack_8 = 0;
              }
              else {
                psVar1 = (sword *)((int)puStack_8 + (4 - CONCAT22(uStack_10,uStack_e)));
                *psVar1 = *(sword *)(puStack_8 + 1) + *psVar1;
              }
              _bwrite(iStack_c);
              iStack_c = 0;
              *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x42;
              *(word *)(aiStack_1c[0] + 0x42) = *(word *)(aiStack_1c[0] + 0x42) | 0x40;
              if (*(char *)(dword_40B57D4 + 100) == '\0') {
                if (0 < *(sword *)(aiStack_1c[0] + 100)) {
                  if ((param_4 == 0) || ((*(word *)(aiStack_1c[0] + 0x62) & 0xf000) != 0x4000)) {
                    *(sword *)(aiStack_1c[0] + 100) = *(sword *)(aiStack_1c[0] + 100) + -1;
                  }
                  else {
                    *(sword *)(aiStack_1c[0] + 100) = *(sword *)(aiStack_1c[0] + 100) + -2;
                    *(sword *)(param_1 + 100) = *(sword *)(param_1 + 100) + -1;
                    _dnlc_remove(aiStack_1c[0] + 0xc,&asc_40A6047);
                    _dnlc_remove(aiStack_1c[0] + 0xc,&asc_40A6712);
                    _itrunc(aiStack_1c[0],0);
                  }
                }
              }
              else {
                iVar5 = (int)*(char *)(dword_40B57D4 + 100);
              }
            }
            else {
              iVar5 = 0x42;
            }
          }
          else {
            iVar5 = 0x10;
          }
        }
        else {
          iVar5 = 1;
        }
      }
    }
  }
  else {
    iVar5 = 0x14;
  }
  if ((aiStack_1c[0] != 0) && (_iput(aiStack_1c[0]), *(sword *)(aiStack_1c[0] + 100) == 0)) {
    _vnode_uncache(aiStack_1c[0] + 0xc);
  }
  if (iStack_c != 0) {
    _brelse(iStack_c);
  }
  wVar3 = *(word *)(param_1 + 0x42);
  *(word *)(param_1 + 0x42) = wVar3 & 0xfffe;
  if ((wVar3 & 0x10) != 0) {
    *(word *)(param_1 + 0x42) = wVar3 & 0xffee;
    _wakeup(param_1);
  }
  return iVar5;
}
/* GHIDRADEC_FUNCTION index=994 start=0x4036942 */

int _blkatoff(int param_1,uint param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = *(int *)(param_1 + 0x4e);
  uVar3 = param_2 >> (*(uint *)(iVar1 + 0x50) & 0x3f);
  if (((int)uVar3 < 0xc) &&
     (*(uint *)(param_1 + 0x6e) < uVar3 + 1 << (*(uint *)(iVar1 + 0x50) & 0x3f))) {
    uVar4 = *(uint *)(iVar1 + 0x4c) &
            (*(int *)(iVar1 + 0x34) + (*(uint *)(param_1 + 0x6e) & ~*(uint *)(iVar1 + 0x48))) - 1;
  }
  else {
    uVar4 = *(uint *)(iVar1 + 0x30);
  }
  iVar2 = _bmap(param_1,uVar3,1);
  iVar2 = iVar2 << (*(uint *)(iVar1 + 100) & 0x3f);
  if (iVar2 < 0) {
    sub_4036AAC(param_1,aNonexixtentDir,param_2);
    *(undefined *)(dword_40B57D4 + 100) = 2;
  }
  if (*(char *)(dword_40B57D4 + 100) == '\0') {
    iVar2 = _bread(*(undefined4 *)(param_1 + 0x3e),iVar2,uVar4);
    if ((*(byte *)(iVar2 + 3) & 4) == 0) {
      if (param_3 != (int *)0x0) {
        *param_3 = *(int *)(iVar2 + 0x20) + (param_2 & ~*(uint *)(iVar1 + 0x48));
      }
    }
    else {
      _brelse(iVar2);
      iVar2 = 0;
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=995 start=0x4037142 */

void _disksort_enter(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = _active_threads;
  sub_4036D3E(param_1);
  if (*(char *)(param_1 + 0xc) < '\0') {
    (*_ds_call)(param_1,param_2);
  }
  else {
    if (iVar1 != 0) {
      *(undefined4 *)(param_2 + 0x3c) = *(undefined4 *)(iVar1 + 0x4c);
    }
    sub_4036F96(param_1,param_2);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=996 start=0x4037194 */

void _disksort_enter_head(int param_1,int param_2)

{
  sub_4036D3E(param_1);
  if (*(char *)(param_1 + 0xc) < '\0') {
    (*dword_40C1088)(param_1,param_2);
  }
  else {
    *(undefined4 *)(param_2 + 0x3c) = 0x1f;
    sub_4036F96(param_1,param_2);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=997 start=0x40371de */

void _disksort_enter_tail(int param_1,int param_2)

{
  sub_4036D3E(param_1);
  if (*(char *)(param_1 + 0xc) < '\0') {
    (*_ds_call)(param_1,param_2);
  }
  else {
    *(undefined4 *)(param_2 + 0x3c) = 0;
    sub_4036F96(param_1,param_2);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=998 start=0x4037226 */

undefined4 _disksort_first(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  sub_4036D3E(param_1);
  if (*(char *)(param_1 + 0xc) < '\0') {
    uVar2 = (*dword_40C1090)(param_1);
  }
  else {
    piVar1 = *(int **)(param_1 + 0xe);
    if (piVar1 == (int *)(param_1 + 0xe)) {
      uVar2 = 0;
    }
    else {
      uVar2 = *piVar1;
    }
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=999 start=0x403727c */

int _disksort_remove(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  
  sub_4036D3E(param_1);
  if (*(char *)(param_1 + 0xc) < '\0') {
    iVar5 = (*dword_40C1094)(param_1,param_2);
  }
  else {
    piVar4 = (int *)(param_1 + 0xe);
    piVar6 = (int *)*piVar4;
    if (piVar6 == piVar4) {
      iVar5 = 0;
    }
    else {
      do {
        iVar5 = *piVar6;
        if (param_2 == iVar5) {
          *piVar6 = *(int *)(iVar5 + 0xc);
          if (piVar6 == *(int **)(param_1 + 0xe)) {
            *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) & 0xef;
            *(undefined4 *)(param_1 + 0x1a) = *(undefined4 *)(iVar5 + 0x38);
          }
          break;
        }
        if (*(int *)(iVar5 + 0xc) != 0) {
          do {
            iVar1 = *(int *)(iVar5 + 0xc);
            iVar7 = iVar5;
            if (param_2 == iVar1) break;
            iVar5 = iVar1;
            iVar7 = iVar1;
          } while (*(int *)(iVar1 + 0xc) != 0);
          iVar5 = iVar7;
          if (*(int *)(iVar7 + 0xc) != 0) {
            iVar1 = *(int *)(param_2 + 0xc);
            *(int *)(iVar7 + 0xc) = iVar1;
            iVar5 = param_2;
            if (iVar1 == 0) {
              piVar6[1] = iVar7;
            }
            break;
          }
        }
        piVar6 = (int *)piVar6[4];
      } while (piVar6 != piVar4);
      while (((piVar6 = *(int **)(param_1 + 0xe), (*(byte *)(param_1 + 0xc) & 0x10) == 0 &&
              (piVar4 = (int *)(param_1 + 0xe), piVar4 != (int *)*piVar4)) && (*piVar6 == 0))) {
        piVar2 = (int *)piVar6[4];
        puVar3 = (undefined4 *)piVar6[5];
        if (piVar2 == piVar4) {
          *(undefined4 **)(param_1 + 0x12) = puVar3;
        }
        else {
          piVar2[5] = (int)puVar3;
        }
        if (puVar3 == (undefined4 *)(param_1 + 0xe)) {
          *puVar3 = piVar2;
        }
        else {
          puVar3[4] = piVar2;
        }
        _kfree(piVar6,0x18);
        *(int *)(param_1 + 0x16) = *(int *)(param_1 + 0x16) + 1;
      }
    }
  }
  return iVar5;
}

