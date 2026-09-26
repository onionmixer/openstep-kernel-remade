/* GHIDRADEC_FUNCTION index=650 start=0x401cd62 */

undefined4 _iflist_first(void)

{
  return _ifnet;
}
/* GHIDRADEC_FUNCTION index=651 start=0x401cd70 */

undefined4 _iflist_next(int param_1)

{
  return *(undefined4 *)(param_1 + 0x5a);
}
/* GHIDRADEC_FUNCTION index=652 start=0x401cd94 */

void _if_detach(undefined4 *param_1)

{
  *param_1 = &aNull_0;
  param_1[1] = &aNull_0;
  *(undefined2 *)(param_1 + 2) = 0;
  *(undefined2 *)((int)param_1 + 10) = 0;
  *(undefined2 *)(param_1 + 3) = 0;
  *(undefined4 *)((int)param_1 + 0x26) = 0;
  *(undefined4 *)((int)param_1 + 0x2e) = 0x401cd80;
  *(undefined4 *)((int)param_1 + 0x32) = 0x401cd80;
  *(undefined4 *)((int)param_1 + 0x36) = 0x401cd80;
  *(undefined4 *)((int)param_1 + 0x3a) = 0x401cd80;
  *(undefined4 *)((int)param_1 + 0x3e) = 0x401cd8a;
  *(undefined4 *)((int)param_1 + 0x56) = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=653 start=0x401cdea */

undefined4 *
_if_attach(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined2 param_7,undefined4 param_8,
          undefined2 param_9,undefined2 param_10,uint param_11,undefined4 param_12)

{
  undefined4 *puVar1;
  bool bVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  bVar2 = false;
  puVar3 = _ifnet;
  do {
    if (puVar3 == (undefined4 *)0x0) {
loc_401CE1E:
      if (!bVar2) {
        puVar3 = (undefined4 *)_kalloc(0x5e);
        _bzero(puVar3,0x5e);
      }
      *puVar3 = param_6;
      puVar3[1] = param_8;
      *(undefined2 *)(puVar3 + 2) = param_7;
      *(undefined2 *)((int)puVar3 + 10) = param_9;
      *(undefined2 *)(puVar3 + 3) = param_10;
      *(undefined4 *)((int)puVar3 + 0xe) = 0;
      *(undefined4 *)((int)puVar3 + 0x16) = 0;
      *(undefined4 *)((int)puVar3 + 0x26) = _ifqmaxlen;
      *(undefined4 *)((int)puVar3 + 0x2e) = param_1;
      *(undefined4 *)((int)puVar3 + 0x32) = param_3;
      *(undefined4 *)((int)puVar3 + 0x36) = param_5;
      *(undefined4 *)((int)puVar3 + 0x3a) = param_2;
      *(undefined4 *)((int)puVar3 + 0x3e) = param_4;
      *(undefined4 *)((int)puVar3 + 0x56) = param_12;
      *(uint *)((int)puVar3 + 0x12) = param_11;
      *(undefined4 *)((int)puVar3 + 0x42) = 0;
      *(undefined4 *)((int)puVar3 + 0x46) = 0;
      *(undefined4 *)((int)puVar3 + 0x4a) = 0;
      *(undefined4 *)((int)puVar3 + 0x4e) = 0;
      *(undefined4 *)((int)puVar3 + 0x52) = 0;
      if (!bVar2) {
        piVar4 = (int *)&_ifnet;
        puVar1 = _ifnet;
        while ((puVar1 != (undefined4 *)0x0 && (param_11 <= *(uint *)(*piVar4 + 0x12)))) {
          piVar4 = (int *)(*piVar4 + 0x5a);
          puVar1 = (undefined4 *)*piVar4;
        }
        *(int *)((int)puVar3 + 0x5a) = *piVar4;
        *piVar4 = (int)puVar3;
      }
      if (*(int *)((int)puVar3 + 0x12) == 0) {
        sub_401CD2C(puVar3);
      }
      return puVar3;
    }
    if (((undefined5 *)*puVar3 == &aNull_0) && (param_11 == *(uint *)((int)puVar3 + 0x12))) {
      bVar2 = true;
      goto loc_401CE1E;
    }
    puVar3 = *(undefined4 **)((int)puVar3 + 0x5a);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=654 start=0x401cee4 */

void _if_registervirtual(code *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  
  piVar3 = &dword_40B3454;
  puVar2 = (undefined4 *)_kalloc(0xc);
  *puVar2 = param_1;
  puVar2[1] = param_2;
  puVar2[2] = 0;
  iVar1 = dword_40B3454;
  while (iVar1 != 0) {
    piVar3 = (int *)(*piVar3 + 8);
    iVar1 = *piVar3;
  }
  *piVar3 = (int)puVar2;
  for (iVar1 = _ifnet; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x5a)) {
    if (*(int *)(iVar1 + 0x12) == 0) {
      (*param_1)(param_2,iVar1);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=655 start=0x401cf4a */

undefined4 _if_handle_input(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _ifnet;
  while( true ) {
    if (iVar1 == 0) {
      _nb_free(param_2);
      return 0x2f;
    }
    if (((*(code **)(iVar1 + 0x3a) != (code *)0x0) && (*(int *)(iVar1 + 0x12) != 0)) &&
       (iVar2 = (**(code **)(iVar1 + 0x3a))(iVar1,param_1,param_2,param_3), iVar2 == 0)) break;
    iVar1 = *(int *)(iVar1 + 0x5a);
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=656 start=0x401cfa8 */

undefined4 _mbuf_read(undefined4 *param_1,int param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    if (param_1 == (undefined4 *)0x0) {
      return 0xffffffff;
    }
    if ((uVar2 <= param_3) && (param_3 < (int)*(sword *)(param_1 + 2) + uVar2)) {
      uVar1 = (int)*(sword *)(param_1 + 2) - (param_3 - uVar2);
      if (param_4 < uVar1) {
        uVar1 = param_4;
      }
      _bcopy((int)param_1 + (param_3 - uVar2) + param_1[1],param_2,uVar1);
      param_2 = uVar1 + param_2;
      param_3 = uVar1 + param_3;
      param_4 = param_4 - uVar1;
      if (param_4 == 0) {
        return 0;
      }
    }
    uVar2 = (int)*(sword *)(param_1 + 2) + uVar2;
    param_1 = (undefined4 *)*param_1;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=657 start=0x401d020 */

undefined4 _if_output_mbuf(int param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  for (puVar1 = param_2; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
    iVar5 = *(sword *)(puVar1 + 2) + iVar5;
  }
  if (*(sword *)(param_1 + 10) < iVar5) {
    _m_freem(param_2);
    uVar2 = 0x28;
  }
  else {
    iVar3 = (**(code **)(param_1 + 0x3e))(param_1);
    if (iVar3 == 0) {
      _m_freem(param_2);
      uVar2 = 0x37;
    }
    else {
      uVar2 = _nb_map(iVar3);
      _mbuf_read(param_2,uVar2,0,iVar5);
      iVar4 = _nb_size(iVar3);
      _nb_shrink_bot(iVar3,iVar4 - iVar5);
      _m_freem(param_2);
      uVar2 = (**(code **)(param_1 + 0x32))(param_1,iVar3,param_3);
    }
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=658 start=0x401d0c0 */

void _netisr_thread_continue(void)

{
  while (_netisr != 0) {
    if ((_netisr & 4) != 0) {
      _netisr = _netisr & 0xfffffffb;
      _ipintr();
    }
    if ((_netisr & 1) != 0) {
      _netisr = _netisr & 0xfffffffe;
      _rawintr();
    }
  }
  _assert_wait(&_soft_net_wakeup,0);
  _thread_block_with_continuation(_netisr_thread_continue);
  return;
}
/* GHIDRADEC_FUNCTION index=659 start=0x401d12a */

void _netisr_thread(void)

{
  undefined4 uVar1;
  
  uVar1 = _active_threads;
  _stack_privilege(_active_threads);
  _thread_bind(uVar1,_master_processor);
  _thread_block_with_continuation(_netisr_thread_continue);
  return;
}
/* GHIDRADEC_FUNCTION index=660 start=0x401d160 */

undefined4 _raw_attach(int param_1,undefined2 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = _m_getclr(0,4);
  if (iVar1 != 0) {
    iVar2 = _sbreserve(param_1 + 0x38,0x800);
    if (iVar2 != 0) {
      iVar2 = _sbreserve(param_1 + 0x22,0x824);
      if (iVar2 != 0) {
        piVar3 = (int *)(*(int *)(iVar1 + 4) + iVar1);
        piVar3[2] = param_1;
        *(int **)(param_1 + 8) = piVar3;
        piVar3[0xc] = 0;
        *(undefined2 *)(piVar3 + 0xb) = *(undefined2 *)(*(int *)(*(int *)(param_1 + 0xc) + 2) + 2);
        *(undefined2 *)((int)piVar3 + 0x2e) = param_2;
        *piVar3 = (int)_rawcb;
        piVar3[1] = (int)&_rawcb;
        *(int **)((int)_rawcb + 4) = piVar3;
        _rawcb = piVar3;
        return 0;
      }
      _sbrelease(param_1 + 0x38);
    }
    _m_free(iVar1);
  }
  return 0x37;
}
/* GHIDRADEC_FUNCTION index=661 start=0x401d210 */

void _raw_detach(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[2];
  if (param_1[0xe] != 0) {
    _rtfree(param_1[0xe]);
  }
  *(undefined4 *)(iVar1 + 8) = 0;
  _sofree(iVar1);
  *(int *)(*param_1 + 4) = param_1[1];
  *(int *)param_1[1] = *param_1;
  if (param_1[0xd] != 0) {
    _m_freem(param_1[0xd] & 0xffffff80);
  }
  if (iVar1 == _ip_mrouter) {
    _ip_mrouter_done();
  }
  if (*(sword *)(param_1 + 0xb) == 2) {
    _ip_freemoptions(*(undefined4 *)((int)param_1 + 0x4e));
  }
  _m_freem((uint)param_1 & 0xffffff80);
  return;
}
/* GHIDRADEC_FUNCTION index=662 start=0x401d29a */

void _raw_disconnect(int param_1)

{
  *(word *)(param_1 + 0x4c) = *(word *)(param_1 + 0x4c) & 0xfffd;
  if ((*(byte *)(*(int *)(param_1 + 8) + 7) & 1) != 0) {
    _raw_detach(param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=663 start=0x401d2c0 */

undefined4 _raw_bind(int param_1,int param_2)

{
  int iVar1;
  word *pwVar2;
  
  pwVar2 = (word *)(*(int *)(param_2 + 4) + param_2);
  if (_ifnet != 0) {
    if ((3 < *pwVar2) || (*pwVar2 < 2)) {
      return 0x2f;
    }
    if ((*(int *)(pwVar2 + 2) == 0) || (iVar1 = _ifa_ifwithaddr(pwVar2), iVar1 != 0)) {
      iVar1 = *(int *)(param_1 + 8);
      _bcopy(pwVar2,iVar1 + 0x1c,0x10);
      pwVar2 = (word *)(iVar1 + 0x4c);
      *pwVar2 = *pwVar2 | 1;
      return 0;
    }
  }
  return 0x31;
}
/* GHIDRADEC_FUNCTION index=664 start=0x401d332 */

void _raw_connaddr(int param_1,int param_2)

{
  _bcopy(*(int *)(param_2 + 4) + param_2,param_1 + 0xc,0x10);
  *(word *)(param_1 + 0x4c) = *(word *)(param_1 + 0x4c) | 2;
  return;
}
/* GHIDRADEC_FUNCTION index=665 start=0x401d362 */

void _raw_init(void)

{
  dword_40B6DEC = &_rawcb;
  _rawcb = &_rawcb;
  dword_40B5A70 = 0x32;
  return;
}
/* GHIDRADEC_FUNCTION index=666 start=0x401d380 */

void _raw_input(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)_m_get(0,2);
  if (puVar1 == (undefined4 *)0x0) {
    _m_freem(param_1);
  }
  else {
    *puVar1 = param_1;
    *(undefined2 *)(puVar1 + 2) = 0x24;
    puVar2 = (undefined4 *)(puVar1[1] + (int)puVar1);
    puVar2[1] = *param_4;
    puVar2[2] = param_4[1];
    puVar2[3] = param_4[2];
    puVar2[4] = param_4[3];
    puVar2[5] = *param_3;
    puVar2[6] = param_3[1];
    puVar2[7] = param_3[2];
    puVar2[8] = param_3[3];
    *puVar2 = *param_2;
    if (dword_40B5A6C < dword_40B5A70) {
      puVar1[0x1f] = 0;
      puVar2 = puVar1;
      if (dword_40B5A68 != (undefined4 *)0x0) {
        dword_40B5A68[0x1f] = puVar1;
        puVar2 = _rawintrq;
      }
      _rawintrq = puVar2;
      dword_40B5A6C = dword_40B5A6C + 1;
      dword_40B5A68 = puVar1;
    }
    else {
      _m_freem(puVar1);
    }
    _netisr = _netisr | 1;
    _wakeup(&_soft_net_wakeup);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=667 start=0x401d45c */

undefined8 _rawintr(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 in_D0;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  sword *psVar6;
  int iVar7;
  char in_XF;
  char in_NF;
  char in_ZF;
  bool bVar8;
  char in_VF;
  bool bVar9;
  byte in_CF;
  bool bVar10;
  word wVar11;
  
  while( true ) {
    puVar2 = _rawintrq;
    wVar11 = (word)(byte)(in_XF << 4 | in_NF << 3 | in_ZF << 2 | in_VF << 1 | in_CF);
    puVar3 = (undefined4 *)CONCAT22((sword)((uint)in_D0 >> 0x10),wVar11);
    bVar8 = _rawintrq == (undefined4 *)0x0;
    bVar9 = false;
    bVar10 = false;
    iVar7 = 0;
    if (!bVar8) {
      puVar3 = (undefined4 *)_rawintrq[0x1f];
      if (puVar3 == (undefined4 *)0x0) {
        dword_40B5A68 = 0;
      }
      puVar1 = _rawintrq + 0x1f;
      _rawintrq = puVar3;
      *puVar1 = 0;
      bVar10 = dword_40B5A6C == 0;
      bVar9 = SBORROW4(dword_40B5A6C,1);
      iVar7 = dword_40B5A6C + -1;
      bVar8 = iVar7 == 0;
      dword_40B5A6C = iVar7;
    }
    if (puVar2 == (undefined4 *)0x0) break;
    psVar6 = (sword *)(puVar2[1] + (int)puVar2);
    iVar7 = 0;
    for (puVar3 = _rawcb; (undefined4 **)puVar3 != &_rawcb; puVar3 = (undefined4 *)*puVar3) {
      if ((((*psVar6 == *(sword *)(puVar3 + 0xb)) &&
           ((*(sword *)((int)puVar3 + 0x2e) == 0 || (*(sword *)((int)puVar3 + 0x2e) == psVar6[1]))))
          && (((*(byte *)((int)puVar3 + 0x4d) & 1) == 0 ||
              (iVar4 = _bcmp(puVar3 + 7,psVar6 + 2,0x10), iVar4 == 0)))) &&
         (((*(byte *)((int)puVar3 + 0x4d) & 2) == 0 ||
          (iVar4 = _bcmp(puVar3 + 3,psVar6 + 10,0x10), iVar4 == 0)))) {
        if ((iVar7 != 0) && (iVar4 = _m_copy(*puVar2,0,1000000000), iVar4 != 0)) {
          iVar5 = _sbappendaddr(iVar7 + 0x22,psVar6 + 10,iVar4,0);
          if (iVar5 == 0) {
            _m_freem(iVar4);
          }
          else {
            _sowakeup(iVar7,iVar7 + 0x22);
          }
        }
        iVar7 = puVar3[2];
      }
    }
    in_XF = '\0';
    if (iVar7 == 0) {
      in_NF = (int)puVar2 < 0;
      in_ZF = puVar2 == (undefined4 *)0x0;
      in_VF = '\0';
      in_CF = 0;
      in_D0 = _m_freem(puVar2);
    }
    else {
      iVar4 = _sbappendaddr(iVar7 + 0x22,psVar6 + 10,*puVar2,0);
      if (iVar4 == 0) {
        _m_freem(*puVar2);
      }
      else {
        _sowakeup(iVar7,iVar7 + 0x22);
      }
      in_NF = (int)puVar2 < 0;
      in_ZF = puVar2 == (undefined4 *)0x0;
      in_VF = '\0';
      in_CF = 0;
      in_D0 = _m_free(puVar2);
    }
  }
  return CONCAT44(CONCAT22((sword)((uint)puVar3 >> 0x10),
                           (word)(byte)(bVar10 << 4 | (iVar7 < 0) << 3 | bVar8 << 2 | bVar9 << 1 |
                                       bVar10)),(int)(sword)wVar11);
}
/* GHIDRADEC_FUNCTION index=668 start=0x401d5d8 */

void _raw_ctlinput(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=669 start=0x401d5e0 */

undefined4 _raw_usrreq(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 8);
  uVar2 = 0;
  if (param_2 == 0xb) {
loc_401D7DE:
    return 0x2d;
  }
  if ((param_5 != 0) && (*(sword *)(param_5 + 8) != 0)) {
loc_401d618:
    uVar2 = 0x2d;
    goto loc_401D7D0;
  }
  if ((iVar3 == 0) && (param_2 != 0)) goto loc_401D6DC;
  switch(param_2) {
  case :
    if (-1 < *(char *)(param_1 + 7)) {
      uVar2 = 0xd;
      break;
    }
    if (iVar3 == 0) {
      uVar2 = _raw_attach(param_1,param_4);
      break;
    }
    goto loc_401D6DC;
  case :
    if (iVar3 != 0) {
      _raw_detach(iVar3);
      break;
    }
    goto loc_401D746;
  case :
    if ((*(byte *)(iVar3 + 0x4d) & 1) == 0) {
      uVar2 = _raw_bind(param_1,param_4);
      break;
    }
loc_401D6DC:
    uVar2 = 0x16;
    break;
  case :
  case :
  case :
  case :
    goto loc_401d618;
  case :
    if ((*(byte *)(iVar3 + 0x4d) & 2) == 0) {
      _raw_connaddr(iVar3,param_4);
      _soisconnected(param_1);
      break;
    }
loc_401D72A:
    uVar2 = 0x38;
    break;
  case :
    if ((*(byte *)(iVar3 + 0x4d) & 2) != 0) {
      _raw_disconnect(iVar3);
      _soisdisconnected(param_1);
      break;
    }
    goto loc_401D746;
  case :
    _socantsendmore(param_1);
    break;
  case :
  case :
    goto loc_401D7DE;
  case :
    if (param_4 != 0) {
      if ((*(byte *)(iVar3 + 0x4d) & 2) == 0) {
        _raw_connaddr(iVar3,param_4);
loc_401D74C:
        uVar2 = (**(code **)(*(int *)(param_1 + 0xc) + 0xe))(param_3,param_1);
        param_3 = 0;
        if (param_4 != 0) {
          *(word *)(iVar3 + 0x4c) = *(word *)(iVar3 + 0x4c) & 0xfffd;
        }
        break;
      }
      goto loc_401D72A;
    }
    if ((*(byte *)(iVar3 + 0x4d) & 2) != 0) goto loc_401D74C;
loc_401D746:
    uVar2 = 0x39;
    break;
  case :
    _raw_disconnect(iVar3);
    _sofree(param_1);
    _soisdisconnected(param_1);
    break;
  :
                    /* WARNING: Subroutine does not return */
    _panic(aRawUsrreq);
  case :
    return 0;
  case :
    iVar1 = *(int *)(param_4 + 4);
    iVar3 = iVar3 + 0x1c;
    goto loc_401D7B0;
  case :
    iVar1 = *(int *)(param_4 + 4);
    iVar3 = iVar3 + 0xc;
loc_401D7B0:
    _bcopy(iVar3,iVar1 + param_4,0x10);
    *(undefined2 *)(param_4 + 8) = 0x10;
  }
loc_401D7D0:
  if (param_3 != 0) {
    _m_freem(param_3);
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=670 start=0x401d7e8 */

void _rtalloc(int *param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined *puVar7;
  uint *puVar8;
  undefined *puVar9;
  uint uStack_c;
  uint uStack_8;
  
  puVar9 = (undefined *)(param_1 + 1);
  uVar6 = (uint)*(word *)puVar9;
  iVar4 = *param_1;
  if ((((iVar4 == 0) || (*(int *)(iVar4 + 0x2c) == 0)) || ((*(byte *)(iVar4 + 0x25) & 1) == 0)) &&
     (uVar6 < 0x11)) {
    (*(code *)(&_afswitch)[uVar6 * 2])(puVar9,&uStack_c);
    pcVar1 = (&off_40AE86A)[uVar6 * 2];
    puVar7 = _rthost;
    bVar3 = true;
    uVar5 = uStack_c;
loc_401D84C:
    for (puVar2 = *(undefined4 **)(puVar7 + (uVar5 & 7) * 4); puVar2 != (undefined4 *)0x0;
        puVar2 = (undefined4 *)*puVar2) {
      puVar8 = (uint *)(puVar2[1] + (int)puVar2);
      if (((uVar5 == *puVar8) && ((*(byte *)((int)puVar8 + 0x25) & 1) != 0)) &&
         ((*(byte *)(puVar8[0xb] + 0xd) & 1) != 0)) {
        if (bVar3) {
          iVar4 = _bcmp(puVar8 + 1,puVar9,0x10);
          if (iVar4 == 0) goto loc_401D8B0;
        }
        else if ((uVar6 == *(word *)(puVar8 + 1)) &&
                (iVar4 = (*pcVar1)(puVar8 + 1,puVar9), iVar4 != 0)) {
loc_401D8B0:
          *(sword *)((int)puVar8 + 0x26) = *(sword *)((int)puVar8 + 0x26) + 1;
          if (puVar9 == _wildcard) {
            word_40B6A14 = word_40B6A14 + 1;
          }
          *param_1 = (int)puVar8;
          return;
        }
      }
    }
    if (bVar3) {
      bVar3 = false;
      puVar7 = _rtnet;
      uVar5 = uStack_8;
      goto loc_401D84C;
    }
    if (puVar9 != _wildcard) {
      puVar9 = _wildcard;
      uVar5 = 0;
      goto loc_401D84C;
    }
    word_40B6A12 = word_40B6A12 + 1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=671 start=0x401d90a */

void _rtfree(uint param_1)

{
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(&aRtfree);
  }
  *(sword *)(param_1 + 0x26) = *(sword *)(param_1 + 0x26) + -1;
  if ((*(uint *)(param_1 + 0x25) & 0x1ffffff) >> 8 == 0) {
    _rttrash = _rttrash + -1;
    _m_free(param_1 & 0xffffff80);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=672 start=0x401d954 */

void _rtredirect(word *param_1,undefined4 *param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iVar1 = _ifa_ifwithnet(param_2);
  if (iVar1 == 0) {
    _rtstat = _rtstat + 1;
    return;
  }
  uStack_14 = *(undefined4 *)param_1;
  uStack_10 = *(undefined4 *)(param_1 + 2);
  uStack_c = *(undefined4 *)(param_1 + 4);
  uStack_8 = *(undefined4 *)(param_1 + 6);
  iStack_18 = 0;
  _rtalloc(&iStack_18);
  iVar1 = iStack_18;
  if (((iStack_18 == 0) || (iVar2 = _bcmp(param_4,iStack_18 + 0x14,0x10), iVar2 == 0)) &&
     (iVar2 = _ifa_ifwithaddr(param_2), iVar2 == 0)) {
    if (iVar1 != 0) {
      iVar2 = (*(&off_40AE86A)[(uint)*param_1 * 2])(_wildcard,iVar1 + 4);
      if (iVar2 != 0) {
        _rtfree(iVar1);
        iVar1 = 0;
      }
      if (iVar1 != 0) {
        if ((*(word *)(iVar1 + 0x24) & 2) == 0) {
          _rtstat = _rtstat + 1;
        }
        else if (((*(word *)(iVar1 + 0x24) & 4) == 0) && ((param_3 & 4) != 0)) {
          _rtinit(param_1,param_2,0x8030720a,param_3 | 0x10);
          word_40B6A0E = word_40B6A0E + 1;
        }
        else {
          *(undefined4 *)(iVar1 + 0x14) = *param_2;
          *(undefined4 *)(iVar1 + 0x18) = param_2[1];
          *(undefined4 *)(iVar1 + 0x1c) = param_2[2];
          *(undefined4 *)(iVar1 + 0x20) = param_2[3];
          *(word *)(iVar1 + 0x24) = *(word *)(iVar1 + 0x24) | 0x20;
          word_40B6A10 = word_40B6A10 + 1;
        }
        goto loc_401DA96;
      }
    }
    _rtinit(param_1,param_2,0x8030720a,param_3 & 4 | 0x12);
    word_40B6A0E = word_40B6A0E + 1;
  }
  else {
    _rtstat = _rtstat + 1;
    if (iVar1 == 0) {
      return;
    }
loc_401DA96:
    _rtfree(iVar1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=673 start=0x401daa8 */

int _rtioctl(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (param_1 + 0x7fcf8df6U < 2) {
    iVar1 = _suser();
    if (iVar1 == 0) {
      iVar1 = (int)*(char *)(dword_40B57D4 + 100);
    }
    else {
      iVar1 = _rtrequest(param_1,param_2);
    }
  }
  else {
    iVar1 = 0x16;
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=674 start=0x401daf0 */

undefined4 _rtrequest(int param_1,int param_2)

{
  undefined4 *puVar1;
  code *pcVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined *puVar9;
  uint *puVar10;
  uint uStack_c;
  uint uStack_8;
  
  puVar10 = (uint *)0x0;
  uVar8 = 0;
  uVar6 = (uint)*(word *)(param_2 + 4);
  if (0x10 < uVar6) {
    return 0x2f;
  }
  (*(code *)(&_afswitch)[uVar6 * 2])(param_2 + 4,&uStack_c);
  if ((*(byte *)(param_2 + 0x25) & 4) == 0) {
    puVar9 = _rtnet;
    uVar7 = uStack_8;
  }
  else {
    puVar9 = _rthost;
    uVar7 = uStack_c;
  }
  puVar1 = (undefined4 *)(puVar9 + (uVar7 & 7) * 4);
  pcVar2 = (&off_40AE86A)[uVar6 * 2];
  puVar5 = puVar1;
  for (puVar3 = (undefined4 *)*puVar1; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3)
  {
    puVar10 = (uint *)(puVar3[1] + (int)puVar3);
    if (uVar7 == *puVar10) {
      if ((*(byte *)(param_2 + 0x25) & 4) == 0) {
        if ((*(sword *)(param_2 + 4) == *(sword *)(puVar10 + 1)) &&
           (iVar4 = (*pcVar2)(puVar10 + 1,param_2 + 4), iVar4 != 0)) {
loc_401DBBC:
          iVar4 = _bcmp(puVar10 + 5,param_2 + 0x14,0x10);
          if (iVar4 == 0) break;
        }
      }
      else {
        iVar4 = _bcmp(puVar10 + 1,param_2 + 4,0x10);
        if (iVar4 == 0) goto loc_401DBBC;
      }
    }
    puVar5 = puVar3;
  }
  if (param_1 != -0x7fcf8df6) {
    if (param_1 != -0x7fcf8df5) {
      return 0;
    }
    if (puVar3 == (undefined4 *)0x0) {
      return 3;
    }
    *puVar5 = *puVar3;
    if (0 < *(sword *)((int)puVar10 + 0x26)) {
      *(word *)(puVar10 + 9) = *(word *)(puVar10 + 9) & 0xfffe;
      _rttrash = _rttrash + 1;
      *puVar3 = 0;
      return 0;
    }
    _m_free(puVar3);
    return 0;
  }
  if (puVar3 != (undefined4 *)0x0) {
    return 0x11;
  }
  if ((*(word *)(param_2 + 0x24) & 2) == 0) {
    iVar4 = 0;
    if ((*(word *)(param_2 + 0x24) & 4) != 0) {
      iVar4 = _ifa_ifwithdstaddr(param_2 + 4);
    }
    if (iVar4 != 0) goto loc_401DC84;
    iVar4 = _ifa_ifwithaddr(param_2 + 0x14);
  }
  else {
    iVar4 = _ifa_ifwithdstaddr(param_2 + 0x14);
  }
  if ((iVar4 == 0) && (iVar4 = _ifa_ifwithnet(param_2 + 0x14), iVar4 == 0)) {
    return 0x33;
  }
loc_401DC84:
  puVar5 = (undefined4 *)_m_get(0,5);
  if (puVar5 == (undefined4 *)0x0) {
    uVar8 = 0x37;
  }
  else {
    *puVar5 = *puVar1;
    *puVar1 = puVar5;
    puVar5[1] = 0xc;
    *(undefined2 *)(puVar5 + 2) = 0x30;
    puVar10 = (uint *)(puVar5[1] + (int)puVar5);
    *puVar10 = uVar7;
    puVar10[1] = *(uint *)(param_2 + 4);
    puVar10[2] = *(uint *)(param_2 + 8);
    puVar10[3] = *(uint *)(param_2 + 0xc);
    puVar10[4] = *(uint *)(param_2 + 0x10);
    puVar10[5] = *(uint *)(param_2 + 0x14);
    puVar10[6] = *(uint *)(param_2 + 0x18);
    puVar10[7] = *(uint *)(param_2 + 0x1c);
    puVar10[8] = *(uint *)(param_2 + 0x20);
    *(word *)(puVar10 + 9) = *(word *)(param_2 + 0x24) & 0x16 | 1;
    *(undefined2 *)((int)puVar10 + 0x26) = 0;
    puVar10[10] = 0;
    puVar10[0xb] = *(uint *)(iVar4 + 0x20);
  }
  return uVar8;
}
/* GHIDRADEC_FUNCTION index=675 start=0x401dd28 */

void _rtinit(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined2 param_4)

{
  undefined auStack_34 [4];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined2 uStack_10;
  
  _bzero(auStack_34,0x30);
  uStack_30 = *param_1;
  uStack_2c = param_1[1];
  uStack_28 = param_1[2];
  uStack_24 = param_1[3];
  uStack_20 = *param_2;
  uStack_1c = param_2[1];
  uStack_18 = param_2[2];
  uStack_14 = param_2[3];
  uStack_10 = param_4;
  _rtrequest(param_3,auStack_34);
  return;
}
/* GHIDRADEC_FUNCTION index=676 start=0x401dd88 */

void _arptimer(void)

{
  char cVar1;
  int iVar2;
  byte bVar3;
  char *pcVar4;
  undefined *puVar5;
  undefined *puVar6;
  
  _timeout(_arptimer,0,_hz * 0x3c);
  puVar6 = _arptab;
  iVar2 = 0;
  puVar5 = unk_40B6E63;
  pcVar4 = &unk_40B6E62;
  do {
    if ((*puVar5 != 0) && ((*puVar5 & 4) == 0)) {
      cVar1 = *pcVar4;
      *pcVar4 = cVar1 + '\x01';
      bVar3 = 2;
      if ((*puVar5 & 2) != 0) {
        bVar3 = 0x13;
      }
      if (bVar3 < (byte)(cVar1 + 1U)) {
        _arptfree(puVar6);
      }
    }
    iVar2 = iVar2 + 1;
    puVar5 = puVar5 + 0x14;
    pcVar4 = pcVar4 + 0x14;
    puVar6 = puVar6 + 0x14;
  } while (iVar2 < 0xab);
  return;
}
/* GHIDRADEC_FUNCTION index=677 start=0x401de16 */

void _arpwhohas(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined2 uStack_14;
  undefined auStack_12 [14];
  
  iVar1 = _m_get(0,1);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 8) = 0x1c;
    uStack_14 = 0x806;
    *(undefined2 *)(iVar1 + 8) = 0x1c;
    _bcopy(&uStack_14,auStack_12 + (uint)word_40AE906._0_1_ * 2,2);
    _bcopy(DAT_40ae90a + (uint)word_40AE906._0_1_ + (uint)(byte)word_40AE906,auStack_12,
           (uint)word_40AE906._0_1_);
    iVar2 = 0x7c - *(sword *)(iVar1 + 8);
    *(int *)(iVar1 + 4) = iVar2;
    iVar2 = iVar1 + iVar2;
    _bcopy(&_arpethertempl,iVar2,(int)*(sword *)(iVar1 + 8));
    _bcopy(param_2,iVar2 + 8,word_40AE906._0_1_);
    _bcopy(&param_3,iVar2 + 8 + (uint)word_40AE906._0_1_,(byte)word_40AE906);
    _bcopy(param_4,iVar2 + (byte)word_40AE906 + 8 + (uint)word_40AE906._0_1_ * 2,
           (uint)(byte)word_40AE906);
    uStack_14 = 0;
    _if_output_mbuf(param_1,iVar1,&uStack_14);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=678 start=0x401df26 */

undefined4
_arpresolve(uint param_1,undefined *param_2,uint param_3,uint param_4,uint *param_5,
           undefined *param_6,undefined4 *param_7)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  undefined uStack_15;
  undefined2 auStack_14 [2];
  uint uStack_10;
  
  *param_7 = 0;
  if ((*param_5 & 0xf0000000) == 0xe0000000) {
    *param_6 = 1;
    param_6[1] = 0;
    param_6[2] = 0x5e;
    param_6[3] = *(byte *)((int)param_5 + 1) & 0x7f;
    param_6[4] = *(undefined *)((int)param_5 + 2);
    param_6[5] = (char)*param_5;
    return 1;
  }
  iVar1 = _in_broadcast(*param_5);
  if (iVar1 == 0) {
    iVar1 = _in_lnaof(*param_5);
    if (param_3 == *param_5) {
      if (_useloopback == 0) {
        uVar5 = 4;
        goto loc_401DFFE;
      }
      auStack_14[0] = 2;
      uStack_10 = *param_5;
      _looutput(_loifp,param_4,auStack_14);
    }
    else {
      puVar4 = (uint *)(_arptab + (*param_5 % 0x13) * 0xb4);
      iVar3 = 0;
      do {
        if ((*param_5 == *puVar4) && ((param_1 == 0 || (param_1 == puVar4[4])))) break;
        iVar3 = iVar3 + 1;
        puVar4 = puVar4 + 5;
      } while (iVar3 < 9);
      if (8 < iVar3) {
        puVar4 = (uint *)0x0;
      }
      if (puVar4 == (uint *)0x0) {
        if (*(char *)(param_1 + 0xd) < '\0') {
          _bcopy(param_2,param_6,3);
          param_6[3] = (byte)((uint)(iVar1 << 9) >> 0x19);
          param_6[4] = (char)((uint)iVar1 >> 8);
          uStack_15 = (undefined)iVar1;
          param_6[5] = uStack_15;
          return 1;
        }
        iVar1 = _arptnew(param_1,param_5);
        if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
          _panic(aArpresolveNoFr);
        }
        *(uint *)(iVar1 + 0xc) = param_4;
        _arpwhohas(param_1,param_2,param_3,param_5);
      }
      else {
        *(undefined *)((int)puVar4 + 10) = 0;
        if ((*(byte *)((int)puVar4 + 0xb) & 2) != 0) {
          _bcopy(puVar4 + 1,param_6,6);
          if ((*(byte *)((int)puVar4 + 0xb) & 0x10) != 0) {
            *param_7 = 1;
          }
          return 1;
        }
        if (puVar4[3] != 0) {
          _m_freem(puVar4[3]);
        }
        puVar4[3] = param_4;
        _arpwhohas(param_1,param_2,param_3,param_5);
      }
    }
    uVar2 = 0;
  }
  else {
    uVar5 = (uint)word_40AE906._0_1_;
    param_2 = DAT_40ae90a + uVar5 + (byte)word_40AE906;
loc_401DFFE:
    _bcopy(param_2,param_6,uVar5);
    uVar2 = 1;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=679 start=0x401e150 */

void _arpinput(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  sword sStack_c;
  sword sStack_a;
  
  if ((((-1 < *(char *)(param_1 + 0xd)) && (7 < *(word *)(param_4 + 8))) &&
      (_bcopy(*(int *)(param_4 + 4) + param_4,&sStack_c,8), sStack_c == 1)) &&
     ((((uint)(byte)word_40AE906 + (uint)word_40AE906._0_1_) * 2 + 8 <=
       (uint)(int)*(sword *)(param_4 + 8) && ((sStack_a == 0x800 || (sStack_a == 0x1000)))))) {
    _in_arpinput(param_1,param_2,param_3,param_4);
    return;
  }
  _m_freem(param_4);
  return;
}
/* GHIDRADEC_FUNCTION index=680 start=0x401e1e4 */

void _in_arpinput(uint param_1,uint *param_2,uint param_3,int param_4)

{
  sword sVar1;
  sword sVar2;
  int iVar3;
  undefined4 uVar4;
  uint *puVar5;
  int iStack_4c;
  uint uStack_48;
  uint uStack_44;
  undefined2 uStack_40;
  undefined auStack_3e [14];
  undefined2 auStack_30 [2];
  uint uStack_2c;
  undefined auStack_20 [2];
  sword sStack_1e;
  sword sStack_1c;
  sword sStack_1a;
  undefined auStack_18 [20];
  
  iStack_4c = 0;
  _bcopy(*(int *)(param_4 + 4) + param_4,auStack_20,0x1c);
  sVar2 = sStack_1a;
  sVar1 = sStack_1e;
  uStack_40 = 0x806;
  if (word_40AE906 != sStack_1c) goto loc_401E6B6;
  _bcopy(auStack_18 + word_40AE906._0_1_,&uStack_44,4);
  _bcopy(auStack_20 + (byte)word_40AE906 + 8 + (uint)word_40AE906._0_1_ * 2,&uStack_48,4);
  iVar3 = _bcmp(auStack_18,param_2,word_40AE906._0_1_);
  if (iVar3 == 0) goto loc_401E6B6;
  iVar3 = _bcmp(auStack_18,&_etherbroadcastaddr,6);
  if (iVar3 == 0) {
    _log(3,aArpEtherAddres,uStack_44);
    goto loc_401E6B6;
  }
  if (uStack_44 == param_3) {
    uVar4 = _ether_sprintf(auStack_18);
    _log(3,&aSS,aDuplicateIpAdd,uVar4);
    uStack_48 = param_3;
    if (sStack_1a != 1) goto loc_401E6B6;
    puVar5 = (uint *)0x0;
  }
  else {
    puVar5 = (uint *)(_arptab + (uStack_44 % 0x13) * 0xb4);
    iVar3 = 0;
    do {
      if ((uStack_44 == *puVar5) && ((param_1 == 0 || (param_1 == puVar5[4])))) break;
      iVar3 = iVar3 + 1;
      puVar5 = puVar5 + 5;
    } while (iVar3 < 9);
    if (8 < iVar3) {
      puVar5 = (uint *)0x0;
    }
    if (puVar5 == (uint *)0x0) {
      if (param_3 == uStack_48) {
        puVar5 = (uint *)_arptnew(param_1,&uStack_44);
        _bcopy(auStack_18,puVar5 + 1,word_40AE906._0_1_);
        if (word_40AE906._0_1_ < 6) {
          _bzero((int)puVar5 + word_40AE906._0_1_ + 4,6 - (uint)word_40AE906._0_1_);
        }
        *(byte *)((int)puVar5 + 0xb) = *(byte *)((int)puVar5 + 0xb) | 2;
      }
    }
    else {
      _bcopy(auStack_18,puVar5 + 1,word_40AE906._0_1_);
      if (word_40AE906._0_1_ < 6) {
        _bzero((int)puVar5 + word_40AE906._0_1_ + 4,6 - (uint)word_40AE906._0_1_);
      }
      *(byte *)((int)puVar5 + 0xb) = *(byte *)((int)puVar5 + 0xb) | 2;
      if (puVar5[3] != 0) {
        auStack_30[0] = 2;
        uStack_2c = uStack_44;
        _if_output_mbuf(param_1,puVar5[3],auStack_30);
        puVar5[3] = 0;
      }
    }
  }
  if (sVar1 == 0x800) {
    if (sStack_1a != 1) goto loc_401E48C;
  }
  else if (sVar1 == 0x1000) {
    if (puVar5 != (uint *)0x0) {
      *(byte *)((int)puVar5 + 0xb) = *(byte *)((int)puVar5 + 0xb) | 0x10;
    }
    if (sStack_1a != 1) goto loc_401E6B6;
loc_401E48C:
    if ((*(byte *)(param_1 + 0xd) & 0x20) != 0) goto loc_401E6B6;
  }
  if (uStack_48 == param_3) {
    _bcopy(auStack_18,auStack_20 + word_40AE906._0_1_ + 8 + (uint)(byte)word_40AE906,
           (uint)word_40AE906._0_1_);
  }
  else {
    param_2 = (uint *)(_arptab + (uStack_48 % 0x13) * 0xb4);
    iVar3 = 0;
    do {
      if ((uStack_48 == *param_2) && ((param_1 == 0 || (param_1 == param_2[4])))) break;
      iVar3 = iVar3 + 1;
      param_2 = param_2 + 5;
    } while (iVar3 < 9);
    if (8 < iVar3) {
      param_2 = (uint *)0x0;
    }
    if ((param_2 == (uint *)0x0) || ((*(byte *)((int)param_2 + 0xb) & 8) == 0)) {
loc_401E6B6:
      _m_freem(param_4);
      return;
    }
    _bcopy(auStack_18,auStack_20 + word_40AE906._0_1_ + 8 + (uint)(byte)word_40AE906,
           (uint)word_40AE906._0_1_);
    param_2 = param_2 + 1;
  }
  _bcopy(param_2,auStack_18,word_40AE906._0_1_);
  _bcopy(auStack_18 + word_40AE906._0_1_,
         auStack_20 + (byte)word_40AE906 + 8 + (uint)word_40AE906._0_1_ * 2,(uint)(byte)word_40AE906
        );
  _bcopy(&uStack_48,auStack_18 + word_40AE906._0_1_,(byte)word_40AE906);
  sStack_1a = 2;
  _bcopy(auStack_20 + word_40AE906._0_1_ + 8 + (uint)(byte)word_40AE906,auStack_3e,
         (uint)word_40AE906._0_1_);
  _bcopy(&uStack_40,auStack_3e + (uint)word_40AE906._0_1_ * 2,2);
  if (sVar2 == 2) {
    sStack_1e = 0x1000;
  }
  else if ((sVar1 == 0x800) && ((*(byte *)(param_1 + 0xd) & 0x20) == 0)) {
    iStack_4c = _m_copy(param_4,0,1000000000);
  }
  _bcopy(auStack_20,*(int *)(param_4 + 4) + param_4,0x1c);
  uStack_40 = 0;
  _if_output_mbuf(param_1,param_4,&uStack_40);
  if (iStack_4c == 0) {
    return;
  }
  sStack_1e = 0x1000;
  _bcopy(auStack_20,*(int *)(iStack_4c + 4) + iStack_4c,0x1c);
  _if_output_mbuf(param_1,iStack_4c,&uStack_40);
  return;
}
/* GHIDRADEC_FUNCTION index=681 start=0x401e6c8 */

undefined4 _arptfree(undefined4 *param_1)

{
  undefined2 extraout_D0u;
  undefined2 uVar1;
  char cVar2;
  
  cVar2 = '\0';
  uVar1 = 0;
  if (param_1[3] != 0) {
    _m_freem(param_1[3]);
    uVar1 = extraout_D0u;
  }
  param_1[3] = 0;
  *(undefined *)((int)param_1 + 0xb) = 0;
  *(undefined *)((int)param_1 + 10) = 0;
  *param_1 = 0;
  return CONCAT22(uVar1,(word)(byte)(cVar2 << 4 | 4));
}
/* GHIDRADEC_FUNCTION index=682 start=0x401e70a */

uint * _arptnew(uint param_1,uint *param_2)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  byte *pbVar6;
  
  uVar4 = 0xffffffff;
  puVar5 = (uint *)0x0;
  if (dword_40AE934 != 0) {
    dword_40AE934 = 0;
    _timeout(_arptimer,0,_hz);
  }
  iVar1 = (*param_2 % 0x13) * 0xb4;
  puVar2 = (uint *)(_arptab + iVar1);
  iVar3 = 0;
  pbVar6 = &unk_40B6E62 + iVar1;
  do {
    if (*(byte *)((int)puVar2 + 0xb) == 0) goto loc_401E7C2;
    if (((*(byte *)((int)puVar2 + 0xb) & 4) == 0) &&
       ((puVar5 == (uint *)0x0 || ((int)uVar4 < (int)(uint)*pbVar6)))) {
      uVar4 = (uint)*pbVar6;
      puVar5 = puVar2;
    }
    iVar3 = iVar3 + 1;
    pbVar6 = pbVar6 + 0x14;
    puVar2 = puVar2 + 5;
  } while (iVar3 < 9);
  if (puVar5 == (uint *)0x0) {
    puVar2 = (uint *)0x0;
  }
  else {
    _arptfree(puVar5);
    puVar2 = puVar5;
loc_401E7C2:
    *puVar2 = *param_2;
    *(undefined *)((int)puVar2 + 0xb) = 1;
    puVar2[4] = param_1;
  }
  return puVar2;
}
/* GHIDRADEC_FUNCTION index=683 start=0x401e7dc */

undefined4 _arpioctl(int param_1,sword *param_2)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  
  iVar2 = 0;
  if ((*param_2 != 2) || (param_2[8] != 0)) {
    return 0x2f;
  }
  puVar3 = (uint *)(_arptab + (*(uint *)(param_2 + 2) % 0x13) * 0xb4);
  iVar1 = 0;
  do {
    if (*(uint *)(param_2 + 2) == *puVar3) break;
    iVar1 = iVar1 + 1;
    puVar3 = puVar3 + 5;
  } while (iVar1 < 9);
  if (8 < iVar1) {
    puVar3 = (uint *)0x0;
  }
  if (puVar3 == (uint *)0x0) {
    if (param_1 != -0x7fdb96e2) {
      return 6;
    }
    iVar2 = _ifa_ifwithnet(param_2);
    if (iVar2 == 0) {
      return 0x33;
    }
  }
  if (param_1 == -0x7fdb96e0) {
    _arptfree(puVar3);
  }
  else if (param_1 < -0x7fdb96df) {
    if (param_1 == -0x7fdb96e2) {
      if (puVar3 == (uint *)0x0) {
        puVar3 = (uint *)_arptnew(*(undefined4 *)(iVar2 + 0x20),param_2 + 2);
        if (puVar3 == (uint *)0x0) {
          return 0x31;
        }
        if ((*(byte *)((int)param_2 + 0x23) & 4) != 0) {
          iVar2 = _arptnew(puVar3[4],param_2 + 2);
          if (iVar2 == 0) {
            _arptfree(puVar3);
            return 0x31;
          }
          _arptfree(iVar2);
        }
      }
      _bcopy(param_2 + 9,puVar3 + 1,6);
      *(byte *)((int)puVar3 + 0xb) = *(byte *)((int)param_2 + 0x23) & 0x1c | 3;
      *(undefined *)((int)puVar3 + 10) = 0;
    }
  }
  else if (param_1 == -0x3fdb96e1) {
    _bcopy(puVar3 + 1,param_2 + 9,6);
    *(uint *)(param_2 + 0x10) = (uint)*(byte *)((int)puVar3 + 0xb);
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=684 start=0x401e970 */

void _revarpinput(int param_1,undefined4 *param_2)

{
  int iVar1;
  sword sVar2;
  int iVar3;
  undefined *puVar4;
  undefined4 *puVar5;
  undefined2 uStack_1a;
  undefined auStack_18 [6];
  undefined auStack_12 [6];
  undefined2 uStack_c;
  
  param_2[1] = param_2[1] + 4;
  sVar2 = *(sword *)(param_2 + 2);
  *(sword *)(param_2 + 2) = sVar2 + -4;
  puVar5 = param_2;
  if ((sword)(sVar2 + -4) == 0) {
    if (*(sword *)((int)param_2 + 10) == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(&aMfree);
    }
    (&word_40B61CC)[*(sword *)((int)param_2 + 10)] =
         (&word_40B61CC)[*(sword *)((int)param_2 + 10)] + -1;
    word_40B61CC = word_40B61CC + 1;
    *(undefined2 *)((int)param_2 + 10) = 0;
    if (0x7f < (uint)param_2[1]) {
      _mclput(param_2);
    }
    puVar5 = (undefined4 *)*param_2;
    *param_2 = _mfree;
    param_2[1] = 0;
    param_2[0x1f] = 0;
    _mfree = param_2;
    if (_m_want != 0) {
      _m_want = 0;
      _wakeup(&_mfree);
    }
  }
  iVar1 = puVar5[1];
  if ((((0x1b < *(word *)(puVar5 + 2)) && (-1 < *(char *)(param_1 + 0xd))) &&
      (*(sword *)((int)puVar5 + iVar1 + 2) == 0x800)) &&
     ((_revarp != 0 && (*(sword *)((int)puVar5 + iVar1 + 6) == 3)))) {
    puVar4 = _arptab;
    do {
      if (((*(byte *)((int)puVar4 + 0xb) & 4) != 0) &&
         (iVar3 = _bcmp((undefined4 *)((int)puVar4 + 4),(int)puVar5 + iVar1 + 0x12,6), iVar3 == 0))
      break;
      puVar4 = (undefined *)((int)puVar4 + 0x14);
    } while (puVar4 < &_in_ifaddr);
    if (puVar4 < &_in_ifaddr) {
      _bcopy((int)puVar5 + iVar1 + 8,auStack_18,6);
      _bcopy(puVar4,(int)puVar5 + iVar1 + 0x18,4);
      iVar3 = *(int *)(param_1 + 0x16);
      if (iVar3 != 0) {
        do {
          if (param_1 == *(int *)(iVar3 + 0x20)) {
            _bcopy(iVar3 + 4,(int)puVar5 + iVar1 + 0xe,4);
            break;
          }
          iVar3 = *(int *)(iVar3 + 0x24);
        } while (iVar3 != 0);
        if (iVar3 != 0) {
          _bcopy(param_1 + 0x5e,(int)puVar5 + iVar1 + 8,6);
          _bcopy(param_1 + 0x5e,auStack_12,6);
          uStack_c = 0x8035;
          *(undefined2 *)((int)puVar5 + iVar1 + 6) = 4;
          uStack_1a = 0;
          if (_revarpdebug != 0) {
            _printf(aRevarpReplyToX,*(undefined4 *)((int)puVar5 + iVar1 + 0x18),
                    *(undefined4 *)((int)puVar5 + iVar1 + 0xe));
          }
          (**(code **)(param_1 + 0x32))(param_1,puVar5,&uStack_1a);
          return;
        }
      }
      if (_revarpdebug != 0) {
        _printf(aRevarpCanTFind);
      }
    }
  }
  _m_freem(puVar5);
  return;
}
/* GHIDRADEC_FUNCTION index=685 start=0x401eb84 */

undefined4 _localetheraddr(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (dword_40AE940 == 0) {
    dword_40AE940 = 1;
    if (param_1 == (undefined4 *)0x0) {
      dword_40AE940 = 1;
      return 0;
    }
    dword_40B3458 = *param_1;
    word_40B345C = *(undefined2 *)(param_1 + 1);
    uVar1 = _ether_sprintf(&dword_40B3458);
    _printf(aEthernetAddres,uVar1);
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = dword_40B3458;
    *(undefined2 *)(param_2 + 1) = word_40B345C;
  }
  return 1;
}
/* GHIDRADEC_FUNCTION index=686 start=0x401ebec */

undefined * _ether_sprintf(byte *param_1)

{
  undefined *puVar1;
  int iVar2;
  undefined *puVar3;
  
  iVar2 = 0;
  puVar1 = unk_40B345E;
  do {
    puVar3 = puVar1;
    *puVar3 = a0123456789abcd_1[*param_1 >> 4];
    puVar3[1] = a0123456789abcd_1[*param_1 & 0xf];
    puVar3[2] = 0x3a;
    iVar2 = iVar2 + 1;
    puVar1 = puVar3 + 3;
    param_1 = param_1 + 1;
  } while (iVar2 < 6);
  puVar3[2] = 0;
  return unk_40B345E;
}
/* GHIDRADEC_FUNCTION index=687 start=0x401ec40 */

void _inet_hash(int param_1,undefined4 *param_2)

{
  uint uVar1;
  char cVar2;
  
  uVar1 = _in_netof(*(undefined4 *)(param_1 + 4));
  if (uVar1 != 0) {
    cVar2 = (char)uVar1;
    while (cVar2 == '\0') {
      cVar2 = (char)(uVar1 >> 8);
      uVar1 = uVar1 >> 8;
    }
  }
  param_2[1] = uVar1;
  *param_2 = *(undefined4 *)(param_1 + 4);
  return;
}
/* GHIDRADEC_FUNCTION index=688 start=0x401ec7c */

int _inet_netmatch(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _in_netof(*(undefined4 *)(param_1 + 4));
  iVar2 = _in_netof(*(undefined4 *)(param_2 + 4));
  return -(int)-(iVar2 == iVar1);
}
/* GHIDRADEC_FUNCTION index=689 start=0x401ecb2 */

void _in_makeaddr(uint param_1)

{
  int iVar1;
  
  for (iVar1 = _in_ifaddr;
      (iVar1 != 0 && ((param_1 & *(uint *)(iVar1 + 0x2c)) != *(uint *)(iVar1 + 0x28)));
      iVar1 = *(int *)(iVar1 + 0x40)) {
  }
  return;
}
/* GHIDRADEC_FUNCTION index=690 start=0x401ed18 */

uint _in_netof(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = _in_ifaddr;
  if ((int)param_1 < 0) {
    if ((param_1 & 0xc0000000) == 0x80000000) {
      uVar2 = param_1 & 0xffff0000;
    }
    else if ((param_1 & 0xe0000000) == 0xc0000000) {
      uVar2 = param_1 & 0xffffff00;
    }
    else {
      uVar2 = param_1 & 0xf0000000;
      if (uVar2 != 0xe0000000) {
        return 0;
      }
    }
  }
  else {
    uVar2 = param_1 & 0xff000000;
  }
  while( true ) {
    if (iVar1 == 0) {
      return uVar2;
    }
    if (uVar2 == *(uint *)(iVar1 + 0x28)) break;
    iVar1 = *(int *)(iVar1 + 0x40);
  }
  return *(uint *)(iVar1 + 0x34) & param_1;
}
/* GHIDRADEC_FUNCTION index=691 start=0x401ed92 */

uint _in_lnaof(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = _in_ifaddr;
  if ((int)param_1 < 0) {
    if ((param_1 & 0xc0000000) == 0x80000000) {
      uVar2 = param_1 & 0xffff0000;
      param_1 = param_1 & 0xffff;
    }
    else if ((param_1 & 0xe0000000) == 0xc0000000) {
      uVar2 = param_1 & 0xffffff00;
      param_1 = param_1 & 0xff;
    }
    else {
      if ((param_1 & 0xf0000000) != 0xe0000000) {
        return param_1;
      }
      param_1 = param_1 & 0xfffffff;
      uVar2 = 0xe0000000;
    }
  }
  else {
    uVar2 = param_1 & 0xff000000;
    param_1 = param_1 & 0xffffff;
  }
  while( true ) {
    if (iVar1 == 0) {
      return param_1;
    }
    if (uVar2 == *(uint *)(iVar1 + 0x28)) break;
    iVar1 = *(int *)(iVar1 + 0x40);
  }
  return param_1 & ~*(uint *)(iVar1 + 0x34);
}
/* GHIDRADEC_FUNCTION index=692 start=0x401ee30 */

undefined4 _in_localaddr(uint param_1)

{
  int iVar1;
  
  iVar1 = _in_ifaddr;
  if (_subnetsarelocal == 0) {
    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x40)) {
      if ((*(uint *)(iVar1 + 0x34) & param_1) == *(uint *)(iVar1 + 0x30)) {
        return 1;
      }
    }
  }
  else {
    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x40)) {
      if ((*(uint *)(iVar1 + 0x2c) & param_1) == *(uint *)(iVar1 + 0x28)) {
        return 1;
      }
    }
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=693 start=0x401ee88 */

undefined4 _in_canforward(uint param_1)

{
  undefined4 uVar1;
  
  if (((param_1 & 0xe0000000) == 0xe0000000) ||
     ((-1 < (int)param_1 && (((param_1 & 0xff000000) == 0 || ((param_1 & 0xff000000) == 0x7f)))))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=694 start=0x401eec4 */

int _in_control(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  byte bVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  puVar6 = (undefined4 *)0x0;
  puVar3 = _in_ifaddr;
  if (param_4 != 0) {
    while ((puVar6 = puVar3, puVar6 != (undefined4 *)0x0 && (param_4 != puVar6[8]))) {
      puVar3 = (undefined4 *)puVar6[0x10];
    }
  }
  if (param_2 == -0x7fdf96ed) {
    iVar4 = _suser();
    if (iVar4 == 0) goto loc_401EFF8;
loc_401F008:
    if (puVar6 == (undefined4 *)0x0) {
      return 0x31;
    }
  }
  else {
    if (param_2 < -0x7fdf96ec) {
      if ((param_2 != -0x7fdf96f4) && (param_2 != -0x7fdf96f2)) goto loc_401F008;
    }
    else if (param_2 != -0x7fdf96de) {
      if (-0x7fdf96de < param_2) {
        if (param_2 != -0x3fdf96df) goto loc_401F008;
        goto loc_401F012;
      }
      if (param_2 != -0x7fdf96ea) goto loc_401F008;
    }
    iVar4 = _suser();
    if (iVar4 == 0) {
loc_401EFF8:
      return (int)*(char *)(dword_40B57D4 + 100);
    }
    if (param_4 == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(aInControl);
    }
    if (puVar6 == (undefined4 *)0x0) {
      iVar4 = _m_getclr(1,0xd);
      if (iVar4 == 0) {
        return 0x37;
      }
      if (_in_ifaddr == (undefined4 *)0x0) {
        _in_ifaddr = (undefined4 *)(*(int *)(iVar4 + 4) + iVar4);
      }
      else {
        iVar1 = _in_ifaddr[0x10];
        puVar6 = _in_ifaddr;
        while (iVar1 != 0) {
          puVar6 = (undefined4 *)puVar6[0x10];
          iVar1 = puVar6[0x10];
        }
        puVar6[0x10] = *(int *)(iVar4 + 4) + iVar4;
      }
      puVar6 = (undefined4 *)(*(int *)(iVar4 + 4) + iVar4);
      iVar4 = *(int *)(param_4 + 0x16);
      if (iVar4 == 0) {
        *(undefined4 **)(param_4 + 0x16) = puVar6;
      }
      else {
        iVar1 = *(int *)(iVar4 + 0x24);
        while (iVar1 != 0) {
          iVar4 = *(int *)(iVar4 + 0x24);
          iVar1 = *(int *)(iVar4 + 0x24);
        }
        *(undefined4 **)(iVar4 + 0x24) = puVar6;
      }
      puVar6[8] = param_4;
      *(undefined2 *)puVar6 = 2;
      if ((*(byte *)(param_4 + 0xd) & 8) == 0) {
        _in_interfaces = _in_interfaces + 1;
      }
    }
  }
loc_401F012:
  if (param_2 == -0x7fdf96de) {
    uVar5 = puVar6[0xf];
    puVar6[0xf] = uVar5 & 0xfffffffd;
    if ((*(byte *)(param_4 + 0xd) & 1) != 0) {
      puVar6[0xf] = uVar5 & 0xfffffffd | 4;
      uVar5 = 0;
      do {
        if ((int)uVar5 < 6) {
          iVar4 = (1 << (uVar5 & 0x3f)) >> 1;
        }
        else {
          iVar4 = 0x20;
        }
        iVar4 = _icmp_sendMaskPacket(param_4,0x11,iVar4);
        if (iVar4 != 0) {
          return iVar4;
        }
        if ((*(byte *)((int)puVar6 + 0x3f) & 4) == 0) {
          return 0;
        }
        uVar5 = uVar5 + 1;
      } while ((int)uVar5 < 5);
    }
    return 0x32;
  }
  if (param_2 < -0x7fdf96dd) {
    if (param_2 != -0x7fdf96f2) {
      if (param_2 < -0x7fdf96f1) {
        if (param_2 == -0x7fdf96f4) {
          *(word *)(param_4 + 0xc) = *(word *)(param_4 + 0xc) & 0x7fff;
          iVar4 = _in_ifinit(param_4,puVar6,param_3 + 0x10);
          return iVar4;
        }
      }
      else {
        if (param_2 == -0x7fdf96ed) {
          if ((*(byte *)(param_4 + 0xd) & 2) != 0) {
            puVar6[4] = *(undefined4 *)(param_3 + 0x10);
            puVar6[5] = *(undefined4 *)(param_3 + 0x14);
            puVar6[6] = *(undefined4 *)(param_3 + 0x18);
            puVar6[7] = *(undefined4 *)(param_3 + 0x1c);
            return 0;
          }
          return 0x16;
        }
        if (param_2 == -0x7fdf96ea) {
          puVar6[0xf] = puVar6[0xf] & 0xfffffff9;
          iVar4 = *(int *)(param_3 + 0x14);
          puVar6[0xd] = iVar4;
          if (iVar4 == 0) {
            return 0;
          }
          puVar6[0xf] = puVar6[0xf] | 2;
          _icmp_sendMaskPacket(param_4,0x12,0);
          return 0;
        }
      }
      goto loc_401F23A;
    }
    if ((*(byte *)(param_4 + 0xd) & 0x10) != 0) {
      uStack_14 = puVar6[4];
      uStack_10 = puVar6[5];
      uStack_c = puVar6[6];
      uStack_8 = puVar6[7];
      puVar6[4] = *(undefined4 *)(param_3 + 0x10);
      puVar6[5] = *(undefined4 *)(param_3 + 0x14);
      puVar6[6] = *(undefined4 *)(param_3 + 0x18);
      puVar6[7] = *(undefined4 *)(param_3 + 0x1c);
      if ((*(int *)(param_4 + 0x36) != 0) &&
         (iVar4 = _if_ioctl(param_4,0x8020690e,puVar6), iVar4 != 0)) {
        puVar6[4] = uStack_14;
        puVar6[5] = uStack_10;
        puVar6[6] = uStack_c;
        puVar6[7] = uStack_8;
        return iVar4;
      }
      if ((*(byte *)((int)puVar6 + 0x3f) & 1) == 0) {
        return 0;
      }
      _rtinit(&uStack_14,puVar6,0x8030720b,4);
      _rtinit(puVar6 + 4,puVar6,0x8030720a,5);
      return 0;
    }
  }
  else {
    if (param_2 == -0x3fdf96f1) {
      bVar2 = *(byte *)(param_4 + 0xd) & 0x10;
    }
    else {
      if (param_2 < -0x3fdf96f0) {
        if (param_2 == -0x3fdf96f3) {
          *(undefined4 *)(param_3 + 0x10) = *puVar6;
          *(undefined4 *)(param_3 + 0x14) = puVar6[1];
          *(undefined4 *)(param_3 + 0x18) = puVar6[2];
          *(undefined4 *)(param_3 + 0x1c) = puVar6[3];
          return 0;
        }
loc_401F23A:
        if ((param_4 != 0) && (*(int *)(param_4 + 0x36) != 0)) {
          iVar4 = _if_ioctl(param_4,param_2,param_3);
          return iVar4;
        }
        return 0x2d;
      }
      if (param_2 != -0x3fdf96ee) {
        if (param_2 == -0x3fdf96eb) {
          *(undefined2 *)(param_3 + 0x10) = 2;
          *(undefined4 *)(param_3 + 0x14) = puVar6[0xd];
          return 0;
        }
        goto loc_401F23A;
      }
      bVar2 = *(byte *)(param_4 + 0xd) & 2;
    }
    if (bVar2 != 0) {
      *(undefined4 *)(param_3 + 0x10) = puVar6[4];
      *(undefined4 *)(param_3 + 0x14) = puVar6[5];
      *(undefined4 *)(param_3 + 0x18) = puVar6[6];
      *(undefined4 *)(param_3 + 0x1c) = puVar6[7];
      return 0;
    }
  }
  return 0x16;
}
/* GHIDRADEC_FUNCTION index=695 start=0x401f262 */

int _in_ifinit(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined2 auStack_24 [2];
  undefined4 uStack_20;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uVar1 = param_3[1];
  uStack_14 = *param_2;
  uStack_10 = param_2[1];
  uStack_c = param_2[2];
  uStack_8 = param_2[3];
  *param_2 = *param_3;
  param_2[1] = param_3[1];
  param_2[2] = param_3[2];
  param_2[3] = param_3[3];
  if ((*(int *)(param_1 + 0x36) != 0) && (iVar3 = _if_ioctl(param_1,0x8020690c,param_2), iVar3 != 0)
     ) {
    *param_2 = uStack_14;
    param_2[1] = uStack_10;
    param_2[2] = uStack_c;
    param_2[3] = uStack_8;
    return iVar3;
  }
  _bzero(auStack_24,0x10);
  auStack_24[0] = 2;
  if ((*(byte *)((int)param_2 + 0x3f) & 1) != 0) {
    if ((*(word *)(param_1 + 0xc) & 8) == 0) {
      if ((*(word *)(param_1 + 0xc) & 0x10) != 0) {
        puVar5 = param_2 + 4;
        goto loc_401F330;
      }
      uStack_20 = _in_makeaddr(param_2[0xc],0);
      _rtinit(auStack_24,&uStack_14,0x8030720b,0);
    }
    else {
      puVar5 = &uStack_14;
loc_401F330:
      _rtinit(puVar5,&uStack_14,0x8030720b,4);
    }
    param_2[0xf] = param_2[0xf] & 0xfffffffe;
  }
  if ((int)uVar1 < 0) {
    if ((uVar1 & 0xc0000000) == 0x80000000) {
      param_2[0xb] = 0xffff0000;
    }
    else {
      param_2[0xb] = 0xffffff00;
    }
  }
  else {
    param_2[0xb] = 0xff000000;
  }
  param_2[10] = param_2[0xb] & uVar1;
  uVar2 = param_2[0xd];
  param_2[0xd] = param_2[0xb] | uVar2;
  param_2[0xc] = (param_2[0xb] | uVar2) & uVar1;
  if ((*(byte *)(param_1 + 0xd) & 2) != 0) {
    *(undefined2 *)(param_2 + 4) = 2;
    uVar4 = _in_makeaddr(param_2[0xc],0xffffffff);
    param_2[5] = uVar4;
    param_2[0xe] = param_2[10] | ~param_2[0xb];
  }
  puVar5 = param_2;
  if ((*(word *)(param_1 + 0xc) & 8) == 0) {
    if ((*(word *)(param_1 + 0xc) & 0x10) == 0) {
      uStack_20 = _in_makeaddr(param_2[0xc],0);
      _rtinit(auStack_24,param_2,0x8030720a,1);
      goto loc_401F44C;
    }
    puVar5 = param_2 + 4;
  }
  _rtinit(puVar5,param_2,0x8030720a,5);
loc_401F44C:
  param_2[0xf] = param_2[0xf] | 1;
  _in_addmulti(0xe0000001,param_1);
  return 0;
}
/* GHIDRADEC_FUNCTION index=696 start=0x401f470 */

int _in_iaonnetof(int param_1)

{
  int iVar1;
  
  iVar1 = _in_ifaddr;
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    if (param_1 == *(int *)(iVar1 + 0x30)) break;
    iVar1 = *(int *)(iVar1 + 0x40);
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=697 start=0x401f49a */

undefined4 _in_broadcast(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  for (iVar1 = _in_ifaddr; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x40)) {
    if (((*(byte *)(*(int *)(iVar1 + 0x20) + 0xd) & 2) != 0) &&
       (((param_1 == *(int *)(iVar1 + 0x14) || (param_1 == *(int *)(iVar1 + 0x30))) ||
        (param_1 == *(int *)(iVar1 + 0x28))))) goto loc_401F4DC;
  }
  if ((param_1 == -1) || (param_1 == 0)) {
loc_401F4DC:
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=698 start=0x401f4e6 */

undefined * _inet_ntoa(undefined4 *param_1)

{
  int iVar1;
  undefined *puVar2;
  char *pcVar3;
  char *pcVar4;
  byte *pbVar5;
  undefined4 uStack_8;
  
  uStack_8 = *param_1;
  puVar2 = unk_40B3470;
  iVar1 = 0;
  pbVar5 = (byte *)&uStack_8;
  do {
    pcVar3 = puVar2;
    if (iVar1 != 0) {
      pcVar3 = puVar2 + 1;
      *puVar2 = '.';
    }
    pcVar4 = pcVar3;
    if (99 < *pbVar5) {
      *pcVar3 = *pbVar5 / 100 + 0x30;
      pcVar4 = pcVar3 + 1;
      if ((char)(((word)((word)*pbVar5 + ((*pbVar5 >> 2) / 0x19) * -100) & 0xff) / 10) == '\0') {
        pcVar4 = pcVar3 + 2;
        pcVar3[1] = '0';
      }
      *pbVar5 = *pbVar5 % 100;
    }
    pcVar3 = pcVar4;
    if (9 < *pbVar5) {
      pcVar3 = pcVar4 + 1;
      *pcVar4 = *pbVar5 / 10 + 0x30;
      *pbVar5 = *pbVar5 % 10;
    }
    puVar2 = pcVar3 + 1;
    *pcVar3 = *pbVar5 + 0x30;
    iVar1 = iVar1 + 1;
    pbVar5 = pbVar5 + 1;
  } while (iVar1 < 4);
  *puVar2 = '\0';
  return unk_40B3470;
}
/* GHIDRADEC_FUNCTION index=699 start=0x401f5f0 */

byte _inet_queue(undefined4 param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  byte bVar8;
  
  _netisr = _netisr | 4;
  _wakeup(&_soft_net_wakeup);
  puVar3 = _mfree;
  uVar1 = dword_40B7BC8;
  if ((int)dword_40B7BC0 < dword_40B7BC4) {
    if (param_2[1] - 0x10 < 0x6d) {
      param_2[1] = param_2[1] + -4;
      *(sword *)(param_2 + 2) = *(sword *)(param_2 + 2) + 4;
      puVar3 = param_2;
    }
    else {
      if (_mfree == (undefined4 *)0x0) {
        puVar3 = (undefined4 *)_m_more(0,2);
      }
      else {
        if (*(sword *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
          _panic(&aMget);
        }
        *(undefined2 *)((int)_mfree + 10) = 2;
        word_40B61CC = word_40B61CC + -1;
        word_40B61D0 = word_40B61D0 + 1;
        puVar2 = (undefined4 *)*_mfree;
        *_mfree = 0;
        _mfree = puVar2;
        puVar3[1] = 0xc;
      }
      uVar1 = dword_40B7BC8;
      if (puVar3 == (undefined4 *)0x0) goto loc_401F6F6;
      puVar3[1] = 0xc;
      *(undefined2 *)(puVar3 + 2) = 4;
      *puVar3 = param_2;
    }
    uVar1 = dword_40B7BC8;
    if (puVar3 != (undefined4 *)0x0) {
      *(undefined4 *)((int)puVar3 + puVar3[1]) = param_1;
      puVar3[0x1f] = 0;
      puVar2 = puVar3;
      if (dword_40B7BBC != (undefined4 *)0x0) {
        dword_40B7BBC[0x1f] = puVar3;
        puVar2 = _ipintrq;
      }
      _ipintrq = puVar2;
      cVar4 = 0xfffffffe < dword_40B7BC0;
      cVar7 = SCARRY4(dword_40B7BC0,1);
      dword_40B7BC0 = dword_40B7BC0 + 1;
      cVar5 = (int)dword_40B7BC0 < 0;
      cVar6 = dword_40B7BC0 == 0;
      bVar8 = cVar4;
      dword_40B7BBC = puVar3;
      goto loc_401F6FE;
    }
  }
loc_401F6F6:
  dword_40B7BC8 = uVar1 + 1;
  cVar4 = 0xfffffffe < uVar1;
  cVar5 = (int)param_2 < 0;
  cVar6 = param_2 == (undefined4 *)0x0;
  cVar7 = '\0';
  bVar8 = 0;
  _m_freem(param_2);
loc_401F6FE:
  return cVar4 << 4 | cVar5 << 3 | cVar6 << 2 | cVar7 << 1 | bVar8;
}

