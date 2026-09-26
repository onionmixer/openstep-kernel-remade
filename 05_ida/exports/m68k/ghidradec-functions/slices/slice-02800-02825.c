/* GHIDRADEC_FUNCTION index=2800 start=0x40070ae */

void sub_40070AE(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  while( true ) {
    if (iVar1 == 0) {
      return;
    }
    if (*(char *)(iVar1 + 0x13) == '\x06') break;
    iVar1 = _get_posix_proc((int)*(sword *)(iVar1 + 0x30));
    iVar1 = *(int *)(iVar1 + 10);
  }
  for (iVar1 = *(int *)(param_1 + 4); iVar1 != 0; iVar1 = *(int *)(iVar1 + 10)) {
    _psignal(iVar1,1);
    _psignal(iVar1,0x13);
    iVar1 = _get_posix_proc((int)*(sword *)(iVar1 + 0x30));
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2801 start=0x400b228 */

void sub_400B228(void)

{
  int iVar1;
  
  iVar1 = dword_40B67E8;
  if (_log_open != 0) {
    dword_40B67E8 = 0;
    if (iVar1 != 0) {
      _selwakeup(iVar1,0);
      _thread_deallocate_interrupt(iVar1);
    }
    if ((_logsoftc & 4) != 0) {
      _gsignal(dword_40B67EC,0x17);
    }
    if ((_logsoftc & 8) != 0) {
      _wakeup(_pmsgbuf);
      _logsoftc = _logsoftc & 0xfffffff7;
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2802 start=0x400b4f2 */

void sub_400B4F2(undefined4 param_1)

{
  _logchar(0x3c);
  sub_400BBAA(param_1,10,4,0,0,0);
  _logchar(0x3e);
  return;
}
/* GHIDRADEC_FUNCTION index=2803 start=0x400bb74 */

void sub_400BB74(char *param_1,undefined4 param_2,undefined4 param_3)

{
  while( true ) {
    if (*param_1 == '\0') break;
    sub_400BDAC((int)*param_1,param_2,param_3);
    param_1 = param_1 + 1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2804 start=0x400bbaa */

void sub_400BBAA(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4,int param_5,
                int param_6)

{
  uint uVar1;
  char *pcVar2;
  char *pcVar3;
  undefined4 uVar4;
  char acStack_10 [12];
  
  if ((param_2 == 10) && ((int)param_1 < 0)) {
    sub_400BDAC(0x2d,param_3,param_4);
    param_1 = -param_1;
  }
  pcVar2 = acStack_10;
  do {
    uVar1 = param_1 % param_2;
    param_1 = param_1 / param_2;
    pcVar3 = pcVar2 + 1;
    *pcVar2 = a0123456789abcd[uVar1];
    pcVar2 = pcVar3;
  } while (param_1 != 0);
  if (param_6 != 0) {
    for (param_6 = param_6 - ((int)pcVar3 - (int)acStack_10); 0 < param_6; param_6 = param_6 + -1) {
      if (param_5 == 0) {
        uVar4 = 0x20;
      }
      else {
        uVar4 = 0x30;
      }
      sub_400BDAC(uVar4,param_3,param_4);
    }
  }
  do {
    pcVar3 = pcVar3 + -1;
    sub_400BDAC((int)*pcVar3,param_3,param_4);
  } while (acStack_10 < pcVar3);
  return;
}
/* GHIDRADEC_FUNCTION index=2805 start=0x400bdac */

void sub_400BDAC(int param_1,uint param_2,int *param_3)

{
  int *piVar1;
  uint uVar2;
  
  if ((((param_2 & 2) != 0) && (param_3 != (int *)0x0)) &&
     ((*(uint *)((int)param_3 + 0x3e) & 0x14) == 0x14)) {
    if (param_1 == 10) {
      _ttyoutput(0xd,param_3);
    }
    _ttyoutput(param_1,param_3);
    _ttstart(param_3);
  }
  piVar1 = _pmsgbuf;
  if ((((param_2 & 4) != 0) && (param_1 != 0)) && ((param_1 != 0xd && (param_1 != 0x7f)))) {
    if (*_pmsgbuf != 0x63061) {
      *_pmsgbuf = 0x63061;
      piVar1[2] = 0;
      piVar1[1] = 0;
      uVar2 = 0;
      do {
        *(undefined *)((int)_pmsgbuf + uVar2 + 0xc) = 0;
        uVar2 = uVar2 + 1;
      } while (uVar2 < 0xff4);
    }
    piVar1 = _pmsgbuf;
    *(char *)((int)_pmsgbuf + _pmsgbuf[1] + 0xc) = (char)param_1;
    piVar1[1] = piVar1[1] + 1;
    if ((_pmsgbuf[1] < 0) || (0xff3 < (uint)_pmsgbuf[1])) {
      _pmsgbuf[1] = 0;
    }
  }
  if (((param_2 & 1) != 0) && (param_1 != 0)) {
    _cnputc(param_1);
  }
  if ((param_2 & 8) != 0) {
    *(char *)*param_3 = (char)param_1;
    *param_3 = *param_3 + 1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2806 start=0x40110a0 */

char sub_40110A0(int param_1)

{
  undefined (*pauVar1) [256];
  int iVar2;
  bool bVar3;
  
  while( true ) {
    pauVar1 = off_40AE690;
    iVar2 = _b_to_q(unk_40B3344,off_40AE690[-0x40b34] + 0xbc,param_1 + 0x18);
    if (iVar2 == 0) {
      _ptsstart(param_1);
    }
    bVar3 = off_40AE690 < pauVar1;
    iVar2 = (int)off_40AE690 - (int)pauVar1;
    if (iVar2 == 0) break;
    _bcopy(pauVar1,unk_40B3344,iVar2);
    off_40AE690 = (undefined (*) [256])(unk_40B3344 + iVar2);
  }
  off_40AE690 = &unk_40B3344;
  return bVar3 << 4;
}
/* GHIDRADEC_FUNCTION index=2807 start=0x40177c6 */

void sub_40177C6(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 *param_5)

{
  int iVar1;
  
  param_5[0x10] = 0;
  sub_4018552(param_5,param_1);
  *(undefined2 *)((int)param_5 + 0x1e) = *(undefined2 *)(param_1 + 0x2c);
  *param_5 = 0x2000001;
  param_5[9] = param_3;
  param_5[6] = _page_size;
  param_5[5] = _page_size;
  *(undefined2 *)(param_5 + 7) = 0;
  param_5[10] = 0;
  param_5[8] = *(undefined4 *)(param_2 + 0x22);
  param_5[0xf] = 0;
  *(int *)(_active_u + 0x192) = *(int *)(_active_u + 0x192) + 1;
  if (param_3 < 0) {
    param_3 = param_3 + 7;
  }
  iVar1 = (param_1 + (param_3 >> 3) & 0xfU) * 0xc;
  param_5[1] = *(undefined4 *)(_bufhash + iVar1 + 4);
  param_5[2] = _bufhash + iVar1;
  *(undefined4 **)(*(int *)(_bufhash + iVar1 + 4) + 8) = param_5;
  *(undefined4 **)(_bufhash + iVar1 + 4) = param_5;
  (**(code **)(*(int *)(param_5[0x10] + 0x1c) + 0x54))(param_5);
  return;
}
/* GHIDRADEC_FUNCTION index=2808 start=0x401787a */

void sub_401787A(int param_1)

{
  *(undefined4 *)(*(int *)(param_1 + 8) + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(*(int *)(param_1 + 4) + 8) = *(undefined4 *)(param_1 + 8);
  sub_4018584(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=2809 start=0x4018552 */

void sub_4018552(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x40) != 0) {
    sub_4018584(param_1);
  }
  *(sword *)(param_2 + 6) = *(sword *)(param_2 + 6) + 1;
  *(int *)(param_1 + 0x40) = param_2;
  return;
}
/* GHIDRADEC_FUNCTION index=2810 start=0x4018584 */

void sub_4018584(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x40);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0x40) = 0;
    _vn_rele(iVar1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2811 start=0x4018afe */

void sub_4018AFE(int *param_1)

{
  int iVar1;
  
  *(int *)(param_1[3] + 8) = param_1[2];
  *(int *)(param_1[2] + 0xc) = param_1[3];
  *(int *)(*param_1 + 4) = param_1[1];
  *(int *)param_1[1] = *param_1;
  _vn_rele(param_1[5]);
  param_1[5] = 0;
  _vn_rele(param_1[4]);
  param_1[4] = 0;
  if (*(int *)((int)param_1 + 0x3a) != 0) {
    _crfree(*(int *)((int)param_1 + 0x3a));
    *(undefined4 *)((int)param_1 + 0x3a) = 0;
  }
  if (*(char *)((int)param_1 + 0x42) != '\0') {
    _kfree(*(undefined4 *)((int)param_1 + 0x3e),(int)*(sword *)(param_1 + 0x11));
    *(undefined *)((int)param_1 + 0x42) = 0;
    *(undefined2 *)(param_1 + 0x11) = 0;
  }
  iVar1 = (int)dword_40B6D68;
  dword_40B6D68 = param_1;
  param_1[2] = iVar1;
  *(int **)(iVar1 + 0xc) = param_1;
  param_1[3] = (int)&_nc_lru;
  param_1[1] = (int)param_1;
  *param_1 = (int)param_1;
  dword_40B6D94 = dword_40B6D94 + -1;
  return;
}
/* GHIDRADEC_FUNCTION index=2812 start=0x4018bae */

undefined4 * sub_4018BAE(int param_1,char *param_2,int param_3,int param_4,int param_5)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(&_nc_hash)[param_4 * 2];
  do {
    if (&_nc_hash + param_4 * 2 == puVar1) {
      return (undefined4 *)0x0;
    }
    if ((((param_1 == puVar1[5]) && (param_3 == *(char *)(puVar1 + 6))) &&
        (*(char *)((int)puVar1 + 0x19) == *param_2)) &&
       (iVar2 = _bcmp((int)puVar1 + 0x19,param_2,param_3), iVar2 == 0)) {
      if (param_5 == -1) {
        return puVar1;
      }
      iVar2 = *(int *)((int)puVar1 + 0x3a);
      if (param_5 == iVar2) {
        return puVar1;
      }
      if (((*(sword *)(iVar2 + 2) == *(sword *)(param_5 + 2)) &&
          (*(sword *)(iVar2 + 4) == *(sword *)(param_5 + 4))) &&
         (iVar2 = _bcmp(param_5 + 10,iVar2 + 10,0x20), iVar2 == 0)) {
        return puVar1;
      }
    }
    puVar1 = (undefined4 *)*puVar1;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2813 start=0x40198bc */

int sub_40198BC(int param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  char *pcVar4;
  char cStack_12e;
  undefined auStack_12d [255];
  undefined4 auStack_2e [3];
  int aiStack_22 [2];
  int *piStack_1a;
  undefined4 uStack_16;
  undefined4 uStack_12;
  undefined4 uStack_e;
  int iStack_8;
  
  iVar2 = 0;
  _pn_alloc(param_4);
  iVar1 = _dnlc_lookupSymLink(param_2,param_3);
  if ((iVar1 == 0) || (*(char *)(iVar1 + 0x42) == '\0')) {
    aiStack_22[0] = *param_4;
    aiStack_22[1] = 0x400;
    piStack_1a = aiStack_22;
    uStack_16 = 1;
    uStack_12 = 0;
    uStack_e = 1;
    iStack_8 = 0x400;
    iVar2 = (**(code **)(*(int *)(param_1 + 0x1c) + 0x44))
                      (param_1,&piStack_1a,*(undefined4 *)(_active_u + 0x1a));
    param_4[2] = 0x400 - iStack_8;
    if (iVar2 != 0) goto loc_4019A9E;
    _dnlc_enterSymLink(param_2,param_3,param_4);
  }
  else {
    _bcopy(*(undefined4 *)(iVar1 + 0x3e),*param_4,(int)*(sword *)(iVar1 + 0x44));
    param_4[2] = (int)*(sword *)(iVar1 + 0x44);
  }
  *(undefined *)(param_4[2] + *param_4) = 0;
  iVar1 = *param_4;
  while (iVar1 = _index(iVar1,0x24), iVar1 != 0) {
    if ((iVar1 == *param_4) || (*(char *)(iVar1 + -1) == '/')) {
      if (iVar1 != 0) {
        _pn_alloc(auStack_2e);
        if (param_4[2] == 0) goto loc_4019A7A;
        goto loc_40199D2;
      }
      break;
    }
    iVar1 = iVar1 + 1;
  }
  goto loc_4019A9A;
loc_40199D2:
  do {
    if (*(char *)param_4[1] == '/') {
      iVar2 = _pn_append(auStack_2e,&asc_40A6715);
      if (iVar2 != 0) goto loc_4019A8E;
      _pn_skipslash(param_4);
    }
    iVar2 = _pn_getcomponent(param_4,&cStack_12e);
    if (iVar2 != 0) goto loc_4019A8E;
    pcVar4 = &cStack_12e;
    if (cStack_12e == '$') {
      puVar3 = _metalinks;
      if (_metalinks._0_4_ != 0) {
        do {
          iVar1 = _strcmp(auStack_12d,*(int *)puVar3);
          if (iVar1 == 0) break;
          puVar3 = (undefined *)((int)puVar3 + 0xc);
        } while (*(int *)puVar3 != 0);
        if ((*(int *)puVar3 != 0) &&
           ((pcVar4 = *(char **)((int)puVar3 + 4), *pcVar4 != '\0' ||
            (pcVar4 = *(char **)((int)puVar3 + 8), pcVar4 != (char *)0x0)))) goto loc_4019A60;
      }
      iVar2 = 2;
      goto loc_4019A8E;
    }
loc_4019A60:
    iVar2 = _pn_append(auStack_2e,pcVar4);
    if (iVar2 != 0) goto loc_4019A8E;
  } while (param_4[2] != 0);
loc_4019A7A:
  if (iVar2 == 0) {
    iVar2 = _pn_set(param_4,auStack_2e[0]);
  }
loc_4019A8E:
  _pn_free(auStack_2e);
loc_4019A9A:
  if (iVar2 == 0) {
    return 0;
  }
loc_4019A9E:
  _pn_free(param_4);
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=2814 start=0x401c310 */

int sub_401C310(undefined4 param_1,undefined4 param_2,sword *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined auStack_1a [4];
  undefined4 uStack_16;
  undefined auStack_12 [12];
  undefined2 uStack_6;
  
  iVar2 = _if_private(param_1);
  uVar1 = *(undefined4 *)(iVar2 + 10);
  if (*param_3 == 0) {
    _bcopy(param_3 + 1,auStack_12,0xe);
  }
  else {
    if (*param_3 != 2) {
      _nb_free(param_2);
      return 0x2f;
    }
    uStack_16 = *(undefined4 *)(param_3 + 2);
    iVar2 = _if_private(param_1,param_2,&uStack_16,auStack_12,auStack_1a);
    uVar3 = _if_private(param_1,*(undefined4 *)(iVar2 + 6));
    iVar2 = _arpresolve(param_1,uVar3);
    if (iVar2 == 0) {
      return 0;
    }
    uStack_6 = 0x800;
  }
  _nb_grow_top(param_2,0xe);
  _nb_write(param_2,0xc,2,&uStack_6);
  iVar2 = _if_output(uVar1,param_2,auStack_12);
  if (iVar2 == 0) {
    iVar4 = _if_opackets(param_1);
    _if_opackets_set(param_1,iVar4 + 1);
  }
  else {
    iVar4 = _if_oerrors(param_1);
    _if_oerrors_set(param_1,iVar4 + 1);
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=2815 start=0x401c41e */

undefined4 sub_401C41E(undefined4 param_1,undefined4 param_2,sword *param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined uStack_a;
  undefined uStack_9;
  undefined uStack_8;
  byte bStack_7;
  undefined uStack_6;
  undefined uStack_5;
  
  iVar1 = _if_private(param_1);
  uVar2 = *(undefined4 *)(iVar1 + 10);
  iVar1 = _strcmp(param_2,_IFCONTROL_AUTOADDR);
  if (iVar1 == 0) {
    if (*param_3 == 2) {
      uVar2 = _if_private(param_1);
      uVar2 = _in_bootp(param_1,param_3,uVar2);
      return uVar2;
    }
  }
  else {
    iVar1 = _strcmp(param_2,&_IFCONTROL_SETADDR);
    if (iVar1 != 0) {
      iVar1 = _strcmp(param_2,_IFCONTROL_ADDMULTICAST);
      if ((iVar1 == 0) || (iVar1 = _strcmp(param_2,_IFCONTROL_RMVMULTICAST), iVar1 == 0)) {
        if (param_3[8] != 2) {
          return 0x2f;
        }
        uStack_a = 1;
        uStack_9 = 0;
        uStack_8 = 0x5e;
        bStack_7 = *(byte *)((int)param_3 + 0x15) & 0x7f;
        uStack_6 = *(undefined *)(param_3 + 0xb);
        uStack_5 = *(undefined *)((int)param_3 + 0x17);
        param_3 = (sword *)&uStack_a;
      }
      uVar2 = _if_control(uVar2,param_2,param_3);
      return uVar2;
    }
    if (*param_3 == 2) {
      uVar3 = _if_flags(param_1);
      _if_flags_set(param_1,uVar3 | 0x41);
      _if_init(uVar2);
      param_3 = param_3 + 2;
      _if_control(uVar2,_IFCONTROL_SETIPADDRESS,param_3);
      iVar1 = _if_private(param_1);
      *(undefined4 *)(iVar1 + 6) = *(undefined4 *)param_3;
      uVar3 = _if_flags(param_1);
      if ((uVar3 & 0x4000) == 0) {
        iVar1 = _if_private(param_1,param_3);
        uVar2 = _if_private(param_1,*(undefined4 *)(iVar1 + 6));
        _arpwhohas(param_1,uVar2);
      }
      return 0;
    }
  }
  return 0x2f;
}
/* GHIDRADEC_FUNCTION index=2816 start=0x401c58a */

void sub_401C58A(undefined4 param_1,sword param_2,sword param_3)

{
  int iVar1;
  int iVar2;
  undefined auStack_204 [512];
  
  iVar1 = _nb_map(param_1);
  if (param_2 < 0x201) {
    iVar2 = (int)param_2;
    _nb_read(param_1,0xe,iVar2,auStack_204);
    _bcopy(iVar1 + 0x12 + iVar2,iVar1 + 0xe,(int)param_3);
    _bcopy(auStack_204,iVar1 + 0xe + (int)param_3,iVar2);
  }
  else {
    iVar2 = (int)param_3;
    _nb_read(param_1,param_2 + 0x12,iVar2,auStack_204);
    _bcopy(iVar1 + 0xe,iVar1 + 0xe + iVar2,(int)param_2);
    _bcopy(auStack_204,iVar1 + 0xe,iVar2);
  }
  _nb_shrink_bot(param_1,4);
  return;
}
/* GHIDRADEC_FUNCTION index=2817 start=0x401c642 */

int sub_401C642(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = _if_private(param_1);
  iVar1 = _if_getbuf(*(undefined4 *)(iVar1 + 10));
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    _nb_shrink_top(iVar1,0xe);
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=2818 start=0x401c67e */

undefined4 sub_401C67E(undefined4 param_1,int param_2,undefined4 param_3)

{
  sword sVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  sword sStack_a;
  sword sStack_8;
  sword sStack_6;
  
  iVar2 = _if_private(param_1);
  if (param_2 != *(int *)(iVar2 + 10)) {
    return 0x2f;
  }
  _nb_read(param_3,0xc,2,&sStack_6);
  if ((word)(sStack_6 - 0x1000U) < 0x10) {
    sVar1 = sStack_6 << 9;
    if (sVar1 == 0) {
      return 0x2f;
    }
    uVar3 = _nb_size(param_3);
    if (uVar3 <= (int)sVar1 + 0x12U) {
      return 0x2f;
    }
    _nb_read(param_3,(int)sVar1 | 0xe,4,&sStack_a);
    sStack_6 = sStack_a;
    if ((sStack_a != 0x800) && (sStack_a != 0x806)) {
      return 0x2f;
    }
    uVar3 = _nb_size(param_3);
    if (uVar3 < (uint)(sVar1 + 0xe + (int)sStack_8)) {
      return 0x2f;
    }
    sub_401C58A(param_3,(int)sVar1,(int)(sword)(sStack_8 + -4));
  }
  if (sStack_6 == 0x800) {
    _nb_shrink_top(param_3,0xe);
    iVar2 = _if_ipackets(param_1);
    _if_ipackets_set(param_1,iVar2 + 1);
    _inet_queue(param_1,param_3);
  }
  else {
    if (sStack_6 != 0x806) {
      return 0x2f;
    }
    iVar2 = _if_ipackets(param_1);
    _if_ipackets_set(param_1,iVar2 + 1);
    uVar3 = _if_flags(param_1);
    if ((uVar3 & 0x4000) == 0) {
      _nb_shrink_top(param_3,0xe);
      iVar2 = _if_private(param_1,param_3);
      uVar4 = _if_private(param_1,*(undefined4 *)(iVar2 + 6));
      _arpinput(param_1,uVar4);
    }
    else {
      _nb_free(param_3);
    }
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=2819 start=0x401c804 */

void sub_401C804(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar1 = _if_type(param_2,a10mbEthernet);
  iVar2 = _strcmp(uVar1);
  if (iVar2 == 0) {
    uVar1 = _kalloc(0xe);
    uVar3 = _if_name(param_2);
    uVar4 = _if_unit(param_2);
    uVar1 = _if_attach(0,sub_401C67E,sub_401C310,sub_401C642,sub_401C41E,uVar3,uVar4,
                       aInternetProtoc_0,0x5dc,2,0x1000,uVar1);
    iVar2 = _if_private(uVar1);
    *(undefined4 *)(iVar2 + 10) = param_2;
    uVar1 = _if_private(uVar1);
    _if_control(param_2,&_IFCONTROL_GETADDR,uVar1);
    _printf(aIpProtocolEnab,uVar3,uVar4,a10mbEthernet);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2820 start=0x401c8ea */

void sub_401C8EA(undefined4 *param_1)

{
  _kfree(param_1,*param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=2821 start=0x401cd2c */

void sub_401CD2C(undefined4 param_1)

{
  undefined4 *puVar1;
  
  for (puVar1 = dword_40B3454; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)puVar1[2]) {
    (*(code *)*puVar1)(puVar1[1],param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2822 start=0x4025f16 */

int sub_4025F16(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[1];
  while( true ) {
    if (iVar1 != 0) {
      param_1[1] = *(int *)(iVar1 + 0x14);
      return iVar1;
    }
    if (*param_1 == 0) break;
    iVar1 = *(int *)(*param_1 + 0x44);
    *param_1 = *(int *)(*param_1 + 0x40);
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=2823 start=0x4025f4c */

void sub_4025F4C(undefined4 *param_1)

{
  *param_1 = _in_ifaddr;
  param_1[1] = 0;
  sub_4025F16(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=2824 start=0x4026304 */

void sub_4026304(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iStack_c;
  undefined4 uStack_8;
  
  iVar1 = *(int *)(param_1 + 0x2e);
  _getthetime(&iStack_c);
  *(int *)(iVar1 + 0xb6) = iStack_c;
  *(undefined4 *)(iVar1 + 0xba) = uStack_8;
  uVar3 = iStack_c - *(int *)(iVar1 + 0xa0) >> 4;
  if (*(int *)(param_1 + 0x28) == 2) {
    iVar2 = *(int *)(*(int *)(param_1 + 0x24) + 0x126);
    uVar4 = *(uint *)(iVar2 + 0x66);
    if (uVar4 <= uVar3) {
      uVar4 = *(uint *)(iVar2 + 0x6a);
loc_402636A:
      if (uVar3 <= uVar4) goto loc_4026370;
    }
  }
  else {
    iVar2 = *(int *)(*(int *)(param_1 + 0x24) + 0x126);
    uVar4 = *(uint *)(iVar2 + 0x5e);
    if (uVar4 <= uVar3) {
      uVar4 = *(uint *)(iVar2 + 0x62);
      goto loc_402636A;
    }
  }
  uVar3 = uVar4;
loc_4026370:
  *(int *)(iVar1 + 0xb6) = uVar3 + *(int *)(iVar1 + 0xb6);
  return;
}

