/* GHIDRADEC_FUNCTION index=250 start=0x400aff6 */

undefined4 _logopen(void)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (_log_open == 0) {
    dword_40B67E8 = 0;
    dword_40B67EC = (int)*(sword *)(*_active_u + 0x2e);
    dword_40B67F0 = _calloutEntryAllocate(sub_400B228,0);
    piVar1 = _pmsgbuf;
    _log_open = 1;
    if (*_pmsgbuf != 0x63061) {
      *_pmsgbuf = 0x63061;
      piVar1[2] = 0;
      piVar1[1] = 0;
      uVar3 = 0;
      do {
        *(undefined *)((int)_pmsgbuf + uVar3 + 0xc) = 0;
        uVar3 = uVar3 + 1;
      } while (uVar3 < 0xff4);
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 0x10;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=251 start=0x400b072 */

int _logclose(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char in_XF;
  
  uVar2 = dword_40B67F0;
  _log_open = 0;
  dword_40B67F0 = 0;
  _calloutEntryRemove(uVar2);
  _calloutEntryFree(uVar2);
  iVar1 = dword_40B67E8;
  _logsoftc = 0;
  iVar3 = (int)(sword)(word)(byte)(in_XF << 4 | 4);
  dword_40B67E8 = 0;
  if (iVar1 != 0) {
    iVar3 = _thread_deallocate(iVar1);
  }
  dword_40B67EC = 0;
  return iVar3;
}
/* GHIDRADEC_FUNCTION index=252 start=0x400b0d4 */

int _logread(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  if (*(int *)(_pmsgbuf + 8) == *(int *)(_pmsgbuf + 4)) {
    do {
      if ((_logsoftc & 2) != 0) {
        return 0x23;
      }
      _logsoftc = _logsoftc | 8;
      _sleep(_pmsgbuf,0x1a);
    } while (*(int *)(_pmsgbuf + 8) == *(int *)(_pmsgbuf + 4));
  }
  _logsoftc = _logsoftc & 0xfffffff7;
  while( true ) {
    if (*(int *)(param_2 + 0x12) < 1) {
      return 0;
    }
    iVar1 = *(int *)(_pmsgbuf + 8);
    iVar4 = *(int *)(_pmsgbuf + 4) - iVar1;
    if (iVar4 < 0) {
      iVar4 = 0xff4 - iVar1;
    }
    if (*(int *)(param_2 + 0x12) < iVar4) {
      iVar4 = *(int *)(param_2 + 0x12);
    }
    if (iVar4 == 0) break;
    iVar3 = _uiomove(_pmsgbuf + 0xc + iVar1,iVar4,0,param_2);
    iVar1 = _pmsgbuf;
    if (iVar3 != 0) {
      return iVar3;
    }
    uVar2 = iVar4 + *(int *)(_pmsgbuf + 8);
    *(uint *)(_pmsgbuf + 8) = uVar2;
    if (((int)uVar2 < 0) || (0xff3 < uVar2)) {
      *(undefined4 *)(iVar1 + 8) = 0;
    }
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=253 start=0x400b1ba */

undefined4 _logselect(undefined4 param_1,int param_2)

{
  if (param_2 == 1) {
    if (*(int *)(_pmsgbuf + 8) != *(int *)(_pmsgbuf + 4)) {
      return 1;
    }
    _selthreadcache(&dword_40B67E8);
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=254 start=0x400b20c */

void _logwakeup(void)

{
  if (_log_open != 0) {
    _calloutEntryDispatch(dword_40B67F0);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=255 start=0x400b2a6 */

undefined4 _logioctl(int param_1,int *param_2)

{
  int iVar1;
  
  if (param_1 == -0x7ffb8b8a) {
    dword_40B67EC = *param_2;
  }
  else if (param_1 < -0x7ffb8b89) {
    if (param_1 == -0x7ffb9983) {
      if (*param_2 == 0) {
        _logsoftc = _logsoftc & 0xfffffffb;
      }
      else {
        _logsoftc = _logsoftc | 4;
      }
    }
    else {
      if (param_1 != -0x7ffb9982) {
        return 0xffffffff;
      }
      if (*param_2 == 0) {
        _logsoftc = _logsoftc & 0xfffffffd;
      }
      else {
        _logsoftc = _logsoftc | 2;
      }
    }
  }
  else if (param_1 == 0x4004667f) {
    iVar1 = *(int *)(_pmsgbuf + 4) - *(int *)(_pmsgbuf + 8);
    if (iVar1 < 0) {
      iVar1 = iVar1 + 0xff4;
    }
    *param_2 = iVar1;
  }
  else {
    if (param_1 != 0x40047477) {
      return 0xffffffff;
    }
    *param_2 = dword_40B67EC;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=256 start=0x400b358 */

undefined4 _printf(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = _prf(param_1,&stack0x00000008,5,0);
  if (iVar1 != 0) {
    _logwakeup();
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=257 start=0x400b384 */

void _uprintf(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(_active_u + 0x15e);
  if (iVar1 != 0) {
    _ttycheckoutq(iVar1,1);
    _prf(param_1,&stack0x00000008,2,iVar1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=258 start=0x400b3c0 */

undefined4 _tprintf(undefined *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 6;
  sub_400B4F2(6);
  if (param_1 == (undefined *)0x0) {
    param_1 = _cons;
  }
  iVar1 = _ttycheckoutq(param_1,0);
  if (iVar1 == 0) {
    uVar2 = 4;
  }
  _prf(param_2,&stack0x0000000c,uVar2,param_1);
  _logwakeup();
  return 0;
}
/* GHIDRADEC_FUNCTION index=259 start=0x400b41c */

undefined * _sprintf(undefined *param_1,undefined4 param_2)

{
  undefined *puStack_8;
  
  puStack_8 = param_1;
  _prf(param_2,&stack0x0000000c,8,&puStack_8);
  *puStack_8 = 0;
  return puStack_8 + (1 - (int)param_1);
}
/* GHIDRADEC_FUNCTION index=260 start=0x400b458 */

undefined4 _log(undefined4 param_1,undefined4 param_2)

{
  sub_400B4F2(param_1);
  _prf(param_2,&stack0x0000000c,4,0);
  if (_log_open == 0) {
    _prf(param_2,&stack0x0000000c,1,0);
  }
  _logwakeup();
  return 0;
}
/* GHIDRADEC_FUNCTION index=261 start=0x400b4c6 */

undefined4 _vlog(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = _prf(param_2,param_3,5,0);
  if (iVar1 != 0) {
    _logwakeup();
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=262 start=0x400b532 */

void __printf(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  _prf(param_3,&stack0x00000010,param_1,param_2);
  return;
}
/* GHIDRADEC_FUNCTION index=263 start=0x400b550 */

undefined4 _prf(char *param_1,uint *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint *puVar2;
  char cVar3;
  uint uVar4;
  bool bVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  undefined4 uVar9;
  int iVar10;
  char *pcVar11;
  char *pcVar12;
  uint *puVar13;
  uint *puVar14;
  uint *puVar15;
  uint *puVar16;
  uint *puVar17;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0;
  uStack_c = 1;
loc_400B580:
  pcVar12 = param_1 + 1;
  iVar6 = (int)*param_1;
  param_1 = pcVar12;
  if (iVar6 == 0x25) {
loc_400b592:
    iVar6 = (int)*param_1;
    if (iVar6 == 0x30) {
      uStack_8 = 0x30;
    }
    iVar10 = 0;
    while (param_1 = param_1 + 1, iVar6 - 0x30U < 10) {
      iVar10 = iVar6 + -0x30 + iVar10 * 10;
      iVar6 = (int)*param_1;
    }
    goto loc_400b5dc;
  }
  if (iVar6 == 0) {
    return uStack_c;
  }
  goto loc_400B576;
loc_400b5dc:
  switch(iVar6) {
  case :
    goto loc_400b8e6;
  :
    goto loc_400B580;
  case :
    puVar8 = param_2 + 1;
    uVar1 = *param_2;
    uVar7 = 0x18;
    do {
      uVar4 = (int)uVar1 >> (uVar7 & 0x3f) & 0xff;
      if (uVar4 != 0) {
        sub_400BDAC(uVar4,param_3,param_4);
      }
      uVar7 = uVar7 - 8;
      param_2 = puVar8;
    } while (-1 < (int)uVar7);
    goto loc_400B580;
  case :
  case :
  case :
    uVar9 = 10;
    break;
  case :
    uStack_c = 0;
    goto loc_400B580;
  case :
  case :
    uVar1 = *param_2;
    puVar15 = param_2 + 2;
    puVar8 = (uint *)param_2[1];
    if (puVar8[1] != 0) goto loc_400BAFA;
    goto loc_400BB0C;
  case :
  case :
    uVar9 = 8;
    break;
  case :
  case :
    puVar8 = param_2 + 1;
    uVar1 = *param_2;
    param_2 = param_2 + 2;
    puVar8 = (uint *)*puVar8;
    if (iVar6 == 0x52) {
      sub_400BB74(&a0x,param_3,param_4);
      sub_400BBAA(uVar1,0x10,param_3,param_4,0,0);
    }
    bVar5 = false;
    if ((iVar6 != 0x72) && (uVar1 == 0)) goto loc_400B580;
    sub_400BDAC(0x3c,param_3,param_4);
    if (*puVar8 == 0) goto loc_400BABC;
    puVar15 = puVar8 + 4;
    puVar16 = puVar8 + 3;
    puVar17 = puVar8 + 2;
    goto loc_400B9A4;
  case :
  case :
    uVar9 = 0x10;
    break;
  case :
    puVar8 = param_2 + 1;
    uVar1 = *param_2;
    param_2 = param_2 + 2;
    pcVar12 = (char *)*puVar8 + 1;
    sub_400BBAA(uVar1,(int)*(char *)*puVar8,param_3,param_4,0,0);
    iVar6 = 0;
    if (uVar1 != 0) goto loc_400B8A2;
    goto loc_400B580;
  case :
    puVar8 = param_2 + 1;
    uVar1 = *param_2;
    uVar7 = 0x18;
    do {
      uVar4 = (int)uVar1 >> (uVar7 & 0x3f) & 0x7f;
      if (uVar4 != 0) {
        sub_400BDAC(uVar4,param_3,param_4);
      }
      uVar7 = uVar7 - 8;
      param_2 = puVar8;
    } while (-1 < (int)uVar7);
    goto loc_400B580;
  case :
    goto loc_400b592;
  case :
    puVar8 = param_2 + 1;
    pcVar12 = (char *)*param_2;
    cVar3 = *pcVar12;
    while (param_2 = puVar8, cVar3 != 0) {
      pcVar12 = pcVar12 + 1;
      sub_400BDAC((int)cVar3,param_3,param_4);
      cVar3 = *pcVar12;
    }
    goto loc_400B580;
  }
  sub_400BBAA(*param_2,uVar9,param_3,param_4,uStack_8,iVar10);
  param_2 = param_2 + 1;
  goto loc_400B580;
loc_400B8A2:
  while( true ) {
    pcVar11 = pcVar12 + 1;
    iVar10 = (int)*pcVar12;
    if (iVar10 == 0) break;
    if (*pcVar11 < '!') {
      iVar6 = iVar6 + 1;
      if (iVar6 != 1) {
        sub_400BDAC(0x2c,param_3,param_4);
      }
      cVar3 = *pcVar11;
      for (pcVar12 = pcVar12 + 2; 0x20 < *pcVar12; pcVar12 = pcVar12 + 1) {
        sub_400BDAC((int)*pcVar12,param_3,param_4);
      }
      sub_400BBAA((2 << (iVar10 - cVar3 & 0x3fU)) - 1U & (int)uVar1 >> ((int)cVar3 - 1U & 0x3f),8,
                  param_3,param_4,0,0);
    }
    else {
      pcVar12 = pcVar11;
      if ((int)(uVar1 << 0x20 - iVar10) < 0) {
        uVar9 = 0x3c;
        if (iVar6 != 0) {
          uVar9 = 0x2c;
        }
        sub_400BDAC(uVar9,param_3,param_4);
        iVar6 = 1;
        cVar3 = *pcVar11;
        while (0x20 < cVar3) {
          sub_400BDAC((int)cVar3,param_3,param_4);
          pcVar12 = pcVar12 + 1;
          cVar3 = *pcVar12;
        }
      }
      else {
        do {
          pcVar12 = pcVar12 + 1;
        } while (' ' < *pcVar12);
      }
    }
  }
  iVar6 = 0x3e;
  goto loc_400B576;
loc_400B9A4:
  do {
    uVar7 = puVar8[1];
    if ((int)uVar7 < 1) {
      uVar7 = (*puVar8 & uVar1) >> (-uVar7 & 0x3f);
    }
    else {
      uVar7 = (*puVar8 & uVar1) << (uVar7 & 0x3f);
    }
    if (bVar5) {
      if ((*puVar16 != 0) || (*puVar15 != 0)) {
loc_400B9E4:
        sub_400BDAC(0x2c,param_3,param_4);
        goto loc_400B9F8;
      }
      if (*puVar17 != 0) {
        if (uVar7 == 0) goto loc_400B9F8;
        goto loc_400B9E4;
      }
    }
    else {
loc_400B9F8:
      if (*puVar17 != 0) {
        if (((*puVar16 != 0) || (*puVar15 != 0)) || (uVar7 != 0)) {
          sub_400BB74(*puVar17,param_3,param_4);
          bVar5 = true;
        }
        if ((*puVar16 != 0) || (*puVar15 != 0)) {
          sub_400BDAC(0x3d,param_3,param_4);
          bVar5 = true;
        }
      }
    }
    if (*puVar16 == 0) {
loc_400BA6C:
      puVar13 = (uint *)*puVar15;
      if (puVar13 != (uint *)0x0) {
        bVar5 = true;
        if (puVar13[1] != 0) {
          do {
            if (uVar7 == *puVar13) {
              sub_400BB74(puVar13[1],param_3,param_4);
              break;
            }
            puVar14 = puVar13 + 2;
            puVar2 = puVar13 + 3;
            puVar13 = puVar14;
          } while (*puVar2 != 0);
          if (puVar13[1] != 0) goto loc_400BAA4;
        }
        sub_400BB74(&asc_40A6284,param_3,param_4);
      }
    }
    else {
      __printf(param_3,param_4,*puVar16,uVar7);
      bVar5 = true;
      if (*puVar15 != 0) {
        sub_400BDAC(0x3a,param_3,param_4);
        goto loc_400BA6C;
      }
    }
loc_400BAA4:
    puVar15 = puVar15 + 5;
    puVar16 = puVar16 + 5;
    puVar17 = puVar17 + 5;
    puVar8 = puVar8 + 5;
  } while (*puVar8 != 0);
loc_400BABC:
  iVar6 = 0x3e;
loc_400B576:
  sub_400BDAC(iVar6,param_3,param_4);
  goto loc_400B580;
  while (puVar17 = puVar8 + 2, puVar16 = puVar8 + 3, puVar8 = puVar17, *puVar16 != 0) {
loc_400BAFA:
    if (uVar1 == *puVar8) {
      sub_400BB74(puVar8[1],param_3,param_4);
      break;
    }
  }
  if (puVar8[1] == 0) {
loc_400BB0C:
    sub_400BB74(&asc_40A6284,param_3,param_4);
  }
  param_2 = puVar15;
  if ((iVar6 == 0x4e) || (puVar8[1] == 0)) {
    sub_400BDAC(0x3a,param_3,param_4);
    sub_400BBAA(uVar1,10,param_3,param_4,0,0);
  }
  goto loc_400B580;
loc_400b8e6:
  iVar6 = 0x25;
  goto loc_400B576;
}
/* GHIDRADEC_FUNCTION index=264 start=0x400bc5e */

void _panic_init(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=265 start=0x400bc66 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _panic(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _mon_global;
  uVar2 = 0;
  if (_panicstr == 0) {
    _panicstr = param_1;
    _paniccpu = 0;
  }
  else {
    if (_paniccpu != 0) {
                    /* WARNING: Subroutine does not return */
      _halt_cpu();
    }
    uVar2 = 4;
  }
  _printf(aPanicCpuDS,_paniccpu,param_1);
  _printf(aNextRomMonitor,(int)*(sword *)(iVar1 + 0x312),(int)*(sword *)(iVar1 + 0x30a),
          (int)*(sword *)(iVar1 + 0x30c));
  _printf(aPanicS,_version);
  _mini_mon(&aPanic,aSystemPanic,__boothowto);
  _boot(0,uVar2,&unk_40A62E7);
  return;
}
/* GHIDRADEC_FUNCTION index=266 start=0x400bd16 */

void _tablefull(undefined4 param_1)

{
  _printf(aSTableIsFull,param_1);
  _log(3,aSTableIsFull,param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=267 start=0x400bd48 */

void _harderr(int param_1,undefined4 param_2)

{
  _printf(aSDCHardErrorSn,param_2,(*(word *)(param_1 + 0x1e) & 0xff) >> 3,
          (*(word *)(param_1 + 0x1e) & 7) + 0x61,*(undefined4 *)(param_1 + 0x24));
  return;
}
/* GHIDRADEC_FUNCTION index=268 start=0x400bd7c */

undefined4 _putchar(undefined4 param_1)

{
  sub_400BDAC(param_1,0,0);
  return 0;
}
/* GHIDRADEC_FUNCTION index=269 start=0x400bd94 */

void _logchar(undefined4 param_1)

{
  sub_400BDAC(param_1,4,0);
  return;
}
/* GHIDRADEC_FUNCTION index=270 start=0x400beaa */

undefined4 _nodev(void)

{
  return 0x13;
}
/* GHIDRADEC_FUNCTION index=271 start=0x400beb4 */

undefined4 _nulldev(void)

{
  return 0;
}
/* GHIDRADEC_FUNCTION index=272 start=0x400bebe */

void _errsys(void)

{
  *(undefined *)(dword_40B57D4 + 100) = 0x16;
  return;
}
/* GHIDRADEC_FUNCTION index=273 start=0x400bed2 */

void _nullsys(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=274 start=0x400beda */

void _nosys(void)

{
  if ((*(int *)(_active_u + 0x5a) == 1) || (*(int *)(_active_u + 0x5a) == 3)) {
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
  }
  _exception_from_kernel(5,0x10000,0);
  return;
}
/* GHIDRADEC_FUNCTION index=275 start=0x400bf16 */

int _imin(int param_1,int param_2)

{
  if (param_2 < param_1) {
    param_1 = param_2;
  }
  return param_1;
}
/* GHIDRADEC_FUNCTION index=276 start=0x400bf2c */

int _imax(int param_1,int param_2)

{
  if (param_1 < param_2) {
    param_1 = param_2;
  }
  return param_1;
}
/* GHIDRADEC_FUNCTION index=277 start=0x400bf42 */

uint _min(uint param_1,uint param_2)

{
  if (param_2 < param_1) {
    param_1 = param_2;
  }
  return param_1;
}
/* GHIDRADEC_FUNCTION index=278 start=0x400bf58 */

uint _max(uint param_1,uint param_2)

{
  if (param_1 < param_2) {
    param_1 = param_2;
  }
  return param_1;
}
/* GHIDRADEC_FUNCTION index=279 start=0x400bf6e */

void _read(void)

{
  undefined4 uStack_22;
  undefined4 uStack_1e;
  undefined4 *puStack_1a;
  undefined4 uStack_16;
  
  uStack_22 = *(undefined4 *)(*(int *)(dword_40B57D4 + 0x24) + 4);
  uStack_1e = *(undefined4 *)(*(int *)(dword_40B57D4 + 0x24) + 8);
  puStack_1a = &uStack_22;
  uStack_16 = 1;
  _rwuio(&puStack_1a,0);
  return;
}
/* GHIDRADEC_FUNCTION index=280 start=0x400bfa6 */

void _readv(void)

{
  int iVar1;
  undefined uVar2;
  undefined auStack_9a [128];
  undefined *puStack_1a;
  undefined4 uStack_16;
  
  iVar1 = *(int *)(dword_40B57D4 + 0x24);
  if (*(uint *)(iVar1 + 8) < 0x11) {
    puStack_1a = auStack_9a;
    uStack_16 = *(undefined4 *)(iVar1 + 8);
    uVar2 = _copyinmsg(*(undefined4 *)(iVar1 + 4),puStack_1a,*(int *)(iVar1 + 8) << 3);
    *(undefined *)(dword_40B57D4 + 100) = uVar2;
    if (*(char *)(dword_40B57D4 + 100) == '\0') {
      _rwuio(&puStack_1a,0);
    }
  }
  else {
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=281 start=0x400c010 */

void _write(void)

{
  undefined4 uStack_22;
  undefined4 uStack_1e;
  undefined4 *puStack_1a;
  undefined4 uStack_16;
  
  puStack_1a = &uStack_22;
  uStack_16 = 1;
  uStack_22 = *(undefined4 *)(*(int *)(dword_40B57D4 + 0x24) + 4);
  uStack_1e = *(undefined4 *)(*(int *)(dword_40B57D4 + 0x24) + 8);
  _rwuio(&puStack_1a,1);
  return;
}
/* GHIDRADEC_FUNCTION index=282 start=0x400c04a */

void _writev(void)

{
  int iVar1;
  undefined uVar2;
  undefined auStack_9a [128];
  undefined *puStack_1a;
  undefined4 uStack_16;
  
  iVar1 = *(int *)(dword_40B57D4 + 0x24);
  if (*(uint *)(iVar1 + 8) < 0x11) {
    puStack_1a = auStack_9a;
    uStack_16 = *(undefined4 *)(iVar1 + 8);
    uVar2 = _copyinmsg(*(undefined4 *)(iVar1 + 4),puStack_1a,*(int *)(iVar1 + 8) << 3);
    *(undefined *)(dword_40B57D4 + 100) = uVar2;
    if (*(char *)(dword_40B57D4 + 100) == '\0') {
      _rwuio(&puStack_1a,1);
    }
  }
  else {
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=283 start=0x400c0b6 */

void _rwuio(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined uVar5;
  int iVar4;
  int iVar6;
  int iStack_c;
  
  if (((**(uint **)(dword_40B57D4 + 0x24) < *(uint *)((int)_active_u + 0x152)) &&
      (iVar1 = *(int *)(*(int *)((int)_active_u + 0x146) + **(uint **)(dword_40B57D4 + 0x24) * 4),
      iVar1 != 0)) && (iVar1 != -0x10000)) {
    if (param_2 == 0) {
      uVar2 = *(uint *)(iVar1 + 8) & 1;
    }
    else {
      uVar2 = *(uint *)(iVar1 + 8) & 2;
    }
    if (uVar2 != 0) {
      *(undefined4 *)((int)param_1 + 0x12) = 0;
      param_1[3] = 0;
      iVar6 = *param_1;
      iStack_c = 0;
      if (0 < param_1[1]) {
        do {
          if ((*(int *)(iVar6 + 4) < 0) ||
             (iVar4 = *(int *)((int)param_1 + 0x12) + *(int *)(iVar6 + 4),
             *(int *)((int)param_1 + 0x12) = iVar4, iVar4 < 0)) {
            *(undefined *)(dword_40B57D4 + 100) = 0x16;
            return;
          }
          iVar6 = iVar6 + 8;
          iStack_c = iStack_c + 1;
        } while (iStack_c < param_1[1]);
      }
      iVar6 = *(int *)((int)param_1 + 0x12);
      while( true ) {
        iVar4 = *(int *)((int)param_1 + 0x12);
        param_1[2] = *(int *)(iVar1 + 0x1a);
        iVar3 = _setjmp(dword_40B57D4 + 0x28);
        if (iVar3 == 0) {
          uVar5 = (*(code *)**(undefined4 **)(iVar1 + 0x12))(iVar1,param_2,param_1);
          *(undefined *)(dword_40B57D4 + 100) = uVar5;
        }
        else if (*(int *)((int)param_1 + 0x12) == iVar6) {
          if (*(int *)((int)_active_u + 0x136) << 0x20 - *(char *)(*_active_u + 0x17) < 0) {
            *(undefined *)(dword_40B57D4 + 100) = 4;
          }
          else {
            *(undefined *)(dword_40B57D4 + 0x65) = 2;
          }
        }
        *(int *)(dword_40B57D4 + 0x5c) = iVar6 - *(int *)((int)param_1 + 0x12);
        *(int *)(iVar1 + 0x1a) = (iVar4 - *(int *)((int)param_1 + 0x12)) + *(int *)(iVar1 + 0x1a);
        if (*(char *)(dword_40B57D4 + 100) == '\0') break;
        iVar4 = _fspause(*(uint *)(iVar1 + 8) & 0x1000);
        if (iVar4 == 0) {
          return;
        }
      }
      return;
    }
  }
  *(undefined *)(dword_40B57D4 + 100) = 9;
  return;
}
/* GHIDRADEC_FUNCTION index=284 start=0x400c26c */

void _ioctl(void)

{
  byte *pbVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  undefined uVar6;
  uint auStack_84 [32];
  
  puVar3 = *(uint **)(dword_40B57D4 + 0x24);
  uVar2 = *puVar3;
  if (((*(uint *)(_active_u + 0x152) <= uVar2) ||
      (iVar5 = *(int *)(*(int *)(_active_u + 0x146) + uVar2 * 4), iVar5 == 0)) ||
     (iVar5 == -0x10000)) {
    *(undefined *)(dword_40B57D4 + 100) = 9;
    return;
  }
  if ((*(uint *)(iVar5 + 0xb) & 0x3ffffff) >> 0x18 == 0) {
    *(undefined *)(dword_40B57D4 + 100) = 9;
    return;
  }
  uVar4 = puVar3[1];
  if (uVar4 == 0x20006601) {
    pbVar1 = (byte *)(uVar2 + *(int *)(_active_u + 0x14a));
    *pbVar1 = *pbVar1 | 1;
    return;
  }
  if (uVar4 == 0x20006602) {
    pbVar1 = (byte *)(uVar2 + *(int *)(_active_u + 0x14a));
    *pbVar1 = *pbVar1 & 0xfe;
    return;
  }
  uVar2 = (uVar4 & 0x1fffffff) >> 0x10;
  if (0x80 < uVar2) {
    *(undefined *)(dword_40B57D4 + 100) = 0xe;
    return;
  }
  if ((int)uVar4 < 0) {
    if (uVar2 == 0) {
loc_400C35E:
      auStack_84[0] = puVar3[2];
    }
    else {
      uVar6 = _copyinmsg(puVar3[2],auStack_84,uVar2);
      *(undefined *)(dword_40B57D4 + 100) = uVar6;
      if (*(char *)(dword_40B57D4 + 100) != '\0') {
        return;
      }
    }
  }
  else if (((uVar4 & 0x40000000) == 0) || (uVar2 == 0)) {
    if ((uVar4 & 0x20000000) != 0) goto loc_400C35E;
  }
  else {
    _bzero(auStack_84,uVar2);
  }
  if (uVar4 == 0x8004667d) {
    uVar6 = _fset(iVar5,0x40,auStack_84[0]);
    goto loc_400C410;
  }
  if ((int)uVar4 < -0x7ffb9982) {
    if (uVar4 == 0x8004667c) {
      uVar6 = _fsetown(iVar5,auStack_84[0]);
      goto loc_400C410;
    }
  }
  else {
    if (uVar4 == 0x8004667e) {
      uVar6 = _fset(iVar5,4,auStack_84[0]);
      goto loc_400C410;
    }
    if (uVar4 == 0x4004667b) {
      uVar6 = _fgetown(iVar5,auStack_84);
      goto loc_400C410;
    }
  }
  uVar6 = (**(code **)(*(int *)(iVar5 + 0x12) + 4))(iVar5,uVar4,auStack_84);
  *(undefined *)(dword_40B57D4 + 100) = uVar6;
  if (*(char *)(dword_40B57D4 + 100) != '\0') {
    return;
  }
  if ((uVar4 & 0x40000000) == 0) {
    return;
  }
  if (uVar2 == 0) {
    return;
  }
  uVar6 = _copyoutmsg(auStack_84,puVar3[2],uVar2);
loc_400C410:
  *(undefined *)(dword_40B57D4 + 100) = uVar6;
  return;
}
/* GHIDRADEC_FUNCTION index=285 start=0x400c424 */

void _select(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined auStack_c [8];
  
  iVar2 = dword_40B57D4;
  piVar1 = *(int **)(dword_40B57D4 + 0x24);
  iVar3 = dword_40B57D4 + 0x7e;
  _bcopy(unk_40ACE76,iVar3,0xd0);
  if (0x100 < *piVar1) {
    *piVar1 = 0x100;
  }
  uVar4 = *piVar1 + 0x1fU >> 5;
  if (piVar1[1] != 0) {
    iVar3 = _copyinmsg(piVar1[1],iVar3,uVar4 << 2);
    *(int *)(iVar2 + 0x14a) = iVar3;
    if (iVar3 != 0) goto loc_400C538;
  }
  if (piVar1[2] != 0) {
    iVar3 = _copyinmsg(piVar1[2],iVar2 + 0x9e,uVar4 << 2);
    *(int *)(iVar2 + 0x14a) = iVar3;
    if (iVar3 != 0) goto loc_400C538;
  }
  if (piVar1[3] != 0) {
    iVar3 = _copyinmsg(piVar1[3],iVar2 + 0xbe,uVar4 << 2);
    *(int *)(iVar2 + 0x14a) = iVar3;
    if (iVar3 != 0) goto loc_400C538;
  }
  if (piVar1[4] != 0) {
    iVar3 = _copyinmsg(piVar1[4],iVar2 + 0x13e,8);
    *(int *)(iVar2 + 0x14a) = iVar3;
    if (iVar3 == 0) {
      iVar3 = _itimerfix(iVar2 + 0x13e);
      if (iVar3 == 0) {
        if ((*(int *)(iVar2 + 0x13e) == 0) && (*(int *)(iVar2 + 0x142) == 0)) {
          *(undefined4 *)(iVar2 + 0x146) = 1;
        }
        else {
          _getthetime(auStack_c);
          _timevaladd(iVar2 + 0x13e,auStack_c);
        }
      }
      else {
        *(undefined4 *)(iVar2 + 0x14a) = 0x16;
      }
    }
  }
loc_400C538:
  _selcont();
  return;
}
/* GHIDRADEC_FUNCTION index=286 start=0x400c548 */

void _selcont(void)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  int iStack_c;
  int iStack_8;
  
  iVar4 = dword_40B57D4;
  piVar1 = *(int **)(dword_40B57D4 + 0x24);
  iVar3 = dword_40B57D4 + 0x7e;
  if (*(int *)(dword_40B57D4 + 0x14a) < 0) {
    iVar6 = _thread_wait_result();
    if (iVar6 - 2U < 2) {
      *(undefined4 *)(iVar4 + 0x14a) = 4;
    }
    else {
      *(undefined4 *)(iVar4 + 0x14a) = 0;
    }
  }
  if (*(int *)(iVar4 + 0x14a) < 1) {
    while( true ) {
      iVar5 = _nselcoll;
      iVar6 = *_active_u;
      *(byte *)(iVar6 + 0x29) = *(byte *)(iVar6 + 0x29) | 0x40;
      uVar7 = _selscan(iVar3,iVar4 + 0xde,*piVar1);
      *(undefined4 *)(dword_40B57D4 + 0x5c) = uVar7;
      cVar2 = *(char *)(dword_40B57D4 + 100);
      *(int *)(iVar4 + 0x14a) = (int)cVar2;
      if (((cVar2 != 0) || (*(int *)(dword_40B57D4 + 0x5c) != 0)) || (*(int *)(iVar4 + 0x146) != 0))
      goto loc_400C68C;
      if (piVar1[4] != 0) {
        _getthetime(&iStack_c);
        if ((*(int *)(iVar4 + 0x13e) < iStack_c) ||
           ((*(int *)(iVar4 + 0x13e) == iStack_c && (*(int *)(iVar4 + 0x142) <= iStack_8))))
        goto loc_400C68C;
      }
      uVar8 = *(uint *)(iVar6 + 0x28);
      if (((uVar8 & 0x400000) != 0) && (iVar5 == _nselcoll)) break;
      *(uint *)(iVar6 + 0x28) = uVar8 & 0xffbfffff;
    }
    *(uint *)(iVar6 + 0x28) = uVar8 & 0xffbfffff;
    *(undefined4 *)(iVar4 + 0x14a) = 0xffffffff;
    if (piVar1[4] == 0) {
      _sleep_with_continuation(&_selwait,0x1a,_selcont);
    }
    else {
      _sleep_with_continuation_and_deadline(&_selwait,0x1a,_selcont,iVar4 + 0x13e);
    }
  }
loc_400C68C:
  uVar8 = *piVar1 + 0x1fU >> 5;
  if (*(int *)(iVar4 + 0x14a) == 0) {
    if (piVar1[1] != 0) {
      uVar7 = _copyoutmsg(iVar4 + 0xde,piVar1[1],uVar8 << 2);
      *(undefined4 *)(iVar4 + 0x14a) = uVar7;
    }
    if (piVar1[2] != 0) {
      uVar7 = _copyoutmsg(iVar4 + 0xfe,piVar1[2],uVar8 << 2);
      *(undefined4 *)(iVar4 + 0x14a) = uVar7;
    }
    if (piVar1[3] != 0) {
      uVar7 = _copyoutmsg(iVar4 + 0x11e,piVar1[3],uVar8 << 2);
      *(undefined4 *)(iVar4 + 0x14a) = uVar7;
    }
    if (*(int *)(iVar4 + 0x14a) == 0) goto loc_400C70C;
  }
  *(undefined *)(dword_40B57D4 + 100) = *(undefined *)(iVar4 + 0x14d);
loc_400C70C:
  _unix_syscall_return(*(undefined4 *)(iVar4 + 0x14a));
  return;
}
/* GHIDRADEC_FUNCTION index=287 start=0x400c720 */

int _selscan(int param_1,int param_2,int param_3)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iStack_14;
  int iStack_10;
  
  iVar7 = 0;
  iVar8 = 0;
  iStack_10 = param_2;
  iStack_14 = param_1;
  do {
    uVar2 = *(undefined4 *)(unk_40AE242 + iVar8 * 4);
    uVar9 = 0;
    if (0 < param_3) {
      do {
        uVar5 = *(uint *)(iStack_14 + (uVar9 >> 5) * 4);
        if (uVar5 != 0) {
          uVar6 = 0;
          do {
            uVar3 = uVar5 & 1;
            uVar5 = (int)uVar5 >> 1;
            if (uVar3 != 0) {
              uVar3 = uVar6 + uVar9;
              if ((param_3 <= (int)uVar3) || (*(int *)(_active_u + 0x152) <= (int)uVar3)) break;
              iVar4 = *(int *)(*(int *)(_active_u + 0x146) + uVar3 * 4);
              if (iVar4 == 0) {
                *(undefined *)(dword_40B57D4 + 100) = 9;
                break;
              }
              iVar4 = (**(code **)(*(int *)(iVar4 + 0x12) + 8))(iVar4,uVar2);
              if (iVar4 != 0) {
                puVar1 = (uint *)(iStack_10 + (uVar3 >> 5) * 4);
                *puVar1 = 1 << (uVar3 & 0x1f) | *puVar1;
                iVar7 = iVar7 + 1;
              }
              if (uVar5 == 0) break;
            }
            uVar6 = uVar6 + 1;
          } while (uVar6 < 0x20);
        }
        uVar9 = uVar9 + 0x20;
      } while ((int)uVar9 < param_3);
    }
    iStack_10 = iStack_10 + 0x20;
    iStack_14 = iStack_14 + 0x20;
    iVar8 = iVar8 + 1;
    if (2 < iVar8) {
      return iVar7;
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=288 start=0x400c800 */

undefined4 _seltrue(void)

{
  return 1;
}
/* GHIDRADEC_FUNCTION index=289 start=0x400c80a */

undefined4 _selthreadcache(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    if ((*(int *)(iVar1 + 0x170) != 0) && (*(undefined4 **)(iVar1 + 0x38) == &_selwait)) {
      return 1;
    }
    *param_1 = 0;
    _thread_deallocate(iVar1);
  }
  iVar1 = _active_threads;
  _thread_reference(_active_threads);
  *param_1 = iVar1;
  return 0;
}
/* GHIDRADEC_FUNCTION index=290 start=0x400c872 */

void _selthreadclear(int *param_1)

{
  if (param_1 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    _panic(aSelthreadclear);
  }
  if (*param_1 != 0) {
    _thread_deallocate_interrupt(*param_1);
  }
  *param_1 = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=291 start=0x400c8a4 */

void _selwakeup(int param_1,int param_2)

{
  int iVar1;
  byte *pbVar2;
  
  if (param_2 != 0) {
    _nselcoll = _nselcoll + 1;
    _wakeup(&_selwait);
  }
  if ((param_1 != 0) && (*(int *)(param_1 + 0x170) != 0)) {
    if (*(undefined4 **)(param_1 + 0x38) == &_selwait) {
      _clear_wait(param_1,0,1);
    }
    iVar1 = *(int *)(*(int *)(param_1 + 0xc) + 0x34);
    if (iVar1 != 0) {
      pbVar2 = (byte *)(iVar1 + 0x29);
      *pbVar2 = *pbVar2 & 0xbf;
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=292 start=0x400c918 */

void _soo_rw(int param_1,int param_2,int param_3)

{
  code *pcVar1;
  
  if (((*(byte *)(*_active_u + 0x16) & 0x40) != 0) && ((*(uint *)(param_1 + 8) & 0x2000) != 0)) {
    *(sword *)(param_3 + 0x10) = (sword)*(uint *)(param_1 + 8);
  }
  pcVar1 = _sosend;
  if (param_2 == 0) {
    pcVar1 = _soreceive;
  }
  (*pcVar1)(*(undefined4 *)(param_1 + 0x16),0,param_3,0,0);
  return;
}
/* GHIDRADEC_FUNCTION index=293 start=0x400c96c */

undefined4 _soo_ioctl(int param_1,uint param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 0x16);
  if (param_2 == 0x200073ff) {
    *(word *)(iVar1 + 6) = *(word *)(iVar1 + 6) | 0x80;
  }
  else if ((int)param_2 < 0x20007400) {
    if (param_2 == 0x8004667e) {
      if (*param_3 == 0) {
        *(word *)(iVar1 + 6) = *(word *)(iVar1 + 6) & 0xfeff;
      }
      else {
        *(word *)(iVar1 + 6) = *(word *)(iVar1 + 6) | 0x100;
      }
    }
    else if ((int)param_2 < -0x7ffb9981) {
      if (param_2 != 0x8004667d) {
loc_400CA24:
        uVar2 = (param_2 & 0xffff) >> 8;
        if (uVar2 == 0x69) {
          uVar3 = _ifioctl(iVar1,param_2,param_3);
          return uVar3;
        }
        if (uVar2 != 0x72) {
          uVar3 = (**(code **)(*(int *)(iVar1 + 0xc) + 0x1a))(iVar1,0xb,param_2,param_3,0);
          return uVar3;
        }
        uVar3 = _rtioctl(param_2,param_3);
        return uVar3;
      }
      if (*param_3 == 0) {
        *(word *)(iVar1 + 6) = *(word *)(iVar1 + 6) & 0xfdff;
      }
      else {
        *(word *)(iVar1 + 6) = *(word *)(iVar1 + 6) | 0x200;
      }
    }
    else {
      if (param_2 != 0x80047308) goto loc_400CA24;
      *(sword *)(iVar1 + 0x54) = (sword)*param_3;
    }
  }
  else if (param_2 == 0x40047307) {
    *param_3 = (*(uint *)(iVar1 + 7) & 0x7fffffff) >> 0x1e;
  }
  else if ((int)param_2 < 0x40047308) {
    if (param_2 != 0x4004667f) goto loc_400CA24;
    *param_3 = (uint)*(word *)(iVar1 + 0x22);
  }
  else {
    if (param_2 != 0x40047309) goto loc_400CA24;
    *param_3 = (int)*(sword *)(iVar1 + 0x54);
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=294 start=0x400ca70 */

undefined4 _soo_select(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x16);
  if (param_2 == 1) {
    if ((((*(sword *)(iVar3 + 0x22) != 0) || ((*(byte *)(iVar3 + 7) & 0x20) != 0)) ||
        (*(sword *)(iVar3 + 0x1e) != 0)) || (*(sword *)(iVar3 + 0x50) != 0)) {
      return 1;
    }
  }
  else {
    if (1 < param_2) {
      if (param_2 != 2) {
        return 0;
      }
      iVar2 = (uint)*(word *)(iVar3 + 0x3e) - (uint)*(word *)(iVar3 + 0x3c);
      iVar1 = (uint)*(word *)(iVar3 + 0x3a) - (uint)*(word *)(iVar3 + 0x38);
      if (iVar2 < iVar1) {
        iVar1 = iVar2;
      }
      if ((((0 < iVar1) &&
           (((*(byte *)(iVar3 + 7) & 2) != 0 || ((*(byte *)(*(int *)(iVar3 + 0xc) + 9) & 4) == 0))))
          || ((*(byte *)(iVar3 + 7) & 0x10) != 0)) || (*(sword *)(iVar3 + 0x50) != 0)) {
        return 1;
      }
      iVar3 = iVar3 + 0x38;
      goto loc_400CB42;
    }
    if (param_2 != 0) {
      return 0;
    }
    if ((*(sword *)(iVar3 + 0x52) != 0) || ((*(byte *)(iVar3 + 7) & 0x40) != 0)) {
      return 1;
    }
  }
  iVar3 = iVar3 + 0x22;
loc_400CB42:
  _sbselqueue(iVar3);
  return 0;
}
/* GHIDRADEC_FUNCTION index=295 start=0x400cb5a */

void _soo_stat(int param_1,undefined4 param_2)

{
  _bzero(param_2,0x3c);
  (**(code **)(*(int *)(param_1 + 0xc) + 0x1a))(param_1,0xc,param_2,0,0);
  return;
}
/* GHIDRADEC_FUNCTION index=296 start=0x400cb98 */

undefined4 _soo_close(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(int *)(param_1 + 0x16) != 0) {
    uVar1 = _soclose(*(int *)(param_1 + 0x16));
  }
  *(undefined4 *)(param_1 + 0x16) = 0;
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=297 start=0x400cbbe */

void _ttysetspec(int *param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  
  iVar2 = *param_1;
  uVar6 = *(uint *)(iVar2 + 0x3a);
  uVar3 = param_1[4];
  uVar5 = 0;
  do {
    *(undefined4 *)(iVar2 + 0x62 + uVar5 * 4) = 0;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 8);
  if ((uVar6 & 0x20) == 0) {
    if ((uVar3 & 0x10) != 0) {
      bVar4 = *(byte *)(iVar2 + 0x59);
      if (bVar4 != 0xff) {
        puVar1 = (uint *)(iVar2 + 0x62 + (uint)(bVar4 >> 5) * 4);
        *puVar1 = 1 << (bVar4 & 0x1f) | *puVar1;
      }
      bVar4 = *(byte *)(iVar2 + 0x57);
      if (bVar4 != 0xff) {
        puVar1 = (uint *)(iVar2 + 0x62 + (uint)(bVar4 >> 5) * 4);
        *puVar1 = 1 << (bVar4 & 0x1f) | *puVar1;
      }
    }
    if ((uVar3 & 8) != 0) {
      bVar4 = *(byte *)(iVar2 + 0x4e);
      if (bVar4 != 0xff) {
        puVar1 = (uint *)(iVar2 + 0x62 + (uint)(bVar4 >> 5) * 4);
        *puVar1 = 1 << (bVar4 & 0x1f) | *puVar1;
      }
      bVar4 = *(byte *)(iVar2 + 0x4f);
      if (bVar4 != 0xff) {
        puVar1 = (uint *)(iVar2 + 0x62 + (uint)(bVar4 >> 5) * 4);
        *puVar1 = 1 << (bVar4 & 0x1f) | *puVar1;
      }
      bVar4 = *(byte *)(iVar2 + 0x54);
      if (bVar4 != 0xff) {
        puVar1 = (uint *)(iVar2 + 0x62 + (uint)(bVar4 >> 5) * 4);
        *puVar1 = 1 << (bVar4 & 0x1f) | *puVar1;
      }
    }
    if ((uVar3 & 0x4000000) != 0) {
      bVar4 = *(byte *)(iVar2 + 0x51);
      if (bVar4 != 0xff) {
        puVar1 = (uint *)(iVar2 + 0x62 + (uint)(bVar4 >> 5) * 4);
        *puVar1 = 1 << (bVar4 & 0x1f) | *puVar1;
      }
      bVar4 = *(byte *)(iVar2 + 0x50);
      if (bVar4 != 0xff) {
        puVar1 = (uint *)(iVar2 + 0x62 + (uint)(bVar4 >> 5) * 4);
        *puVar1 = 1 << (bVar4 & 0x1f) | *puVar1;
      }
    }
    if (((uVar6 & 0x10) != 0) || ((uVar3 & 0x3000000) != 0)) {
      *(word *)(iVar2 + 100) = *(word *)(iVar2 + 100) | 0x2000;
    }
    if ((uVar3 & 0x800000) != 0) {
      *(word *)(iVar2 + 100) = *(word *)(iVar2 + 100) | 0x400;
    }
    if ((uVar6 & 2) == 0) {
      bVar4 = *(byte *)(iVar2 + 0x4c);
      if (bVar4 != 0xff) {
        puVar1 = (uint *)(iVar2 + 0x62 + (uint)(bVar4 >> 5) * 4);
        *puVar1 = 1 << (bVar4 & 0x1f) | *puVar1;
      }
      bVar4 = *(byte *)(iVar2 + 0x4d);
      if (bVar4 != 0xff) {
        puVar1 = (uint *)(iVar2 + 0x62 + (uint)(bVar4 >> 5) * 4);
        *puVar1 = 1 << (bVar4 & 0x1f) | *puVar1;
      }
      bVar4 = *(byte *)(iVar2 + 0x58);
      if (bVar4 != 0xff) {
        puVar1 = (uint *)(iVar2 + 0x62 + (uint)(bVar4 >> 5) * 4);
        *puVar1 = 1 << (bVar4 & 0x1f) | *puVar1;
      }
      bVar4 = *(byte *)(iVar2 + 0x56);
      if (bVar4 != 0xff) {
        puVar1 = (uint *)(iVar2 + 0x62 + (uint)(bVar4 >> 5) * 4);
        *puVar1 = 1 << (bVar4 & 0x1f) | *puVar1;
      }
    }
    if ((uVar6 & 4) != 0) {
      uVar6 = 0;
      do {
        puVar1 = (uint *)(iVar2 + 0x62 + (uVar6 >> 5 & 7) * 4);
        *puVar1 = 1 << (uVar6 & 0x1f) | *puVar1;
        uVar6 = uVar6 + 1;
      } while ((int)uVar6 < 0x80);
    }
    if ((uVar3 & 0x181000) == 0x101000) {
      *(byte *)(iVar2 + 0x7e) = *(byte *)(iVar2 + 0x7e) | 0x80;
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=298 start=0x400cd8a */

void _ttychars(int param_1)

{
  int iVar1;
  
  iVar1 = _ttynty(param_1);
  *(undefined4 *)(param_1 + 0x4c) = _ttydefaults;
  *(undefined4 *)(param_1 + 0x50) = dword_40AE4A2;
  *(undefined4 *)(param_1 + 0x54) = dword_40AE4A6;
  *(undefined2 *)(param_1 + 0x58) = word_40AE4AA;
  *(undefined *)(iVar1 + 0x14) = 0x5c;
  *(undefined *)(iVar1 + 0x15) = 1;
  *(undefined *)(iVar1 + 0x16) = 0;
  _ttysetspec(iVar1);
  return;
}
/* GHIDRADEC_FUNCTION index=299 start=0x400cdde */

void _ttywflush(undefined4 param_1)

{
  _ttywait(param_1);
  _ttyflush(param_1,1);
  return;
}

