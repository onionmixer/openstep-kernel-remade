/* GHIDRADEC_FUNCTION index=600 start=0x401bdbc */

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
/* GHIDRADEC_FUNCTION index=601 start=0x401bdf6 */

byte _if_down_all(void)

{
  int iVar1;
  char cVar2;
  
  cVar2 = '\0';
  for (iVar1 = _ifnet; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x5a)) {
    _if_down(iVar1);
  }
  return cVar2 << 4 | 4;
}
/* GHIDRADEC_FUNCTION index=602 start=0x401be34 */

undefined4 * _ifunit(char *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  char *pcVar4;
  
  for (pcVar4 = param_1; pcVar4 < param_1 + 0x10; pcVar4 = pcVar4 + 1) {
    if (*pcVar4 == '\0') goto loc_401BE6A;
    if ((byte)(*pcVar4 - 0x30U) < 10) break;
  }
  cVar1 = *pcVar4;
  if ((cVar1 == '\0') || (param_1 + 0x10 == pcVar4)) {
loc_401BE6A:
    puVar2 = (undefined4 *)0x0;
  }
  else {
    for (puVar2 = _ifnet;
        (puVar2 != (undefined4 *)0x0 &&
        (((iVar3 = _bcmp(*puVar2,param_1,(int)pcVar4 - (int)param_1), iVar3 != 0 ||
          (*(int *)((int)puVar2 + 0x12) != 0x1000)) ||
         ((int)*(sword *)(puVar2 + 2) != cVar1 + -0x30))));
        puVar2 = *(undefined4 **)((int)puVar2 + 0x5a)) {
    }
  }
  return puVar2;
}
/* GHIDRADEC_FUNCTION index=603 start=0x401bebc */

int _ifioctl(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_2 == -0x7fdb96e0) {
loc_401BF04:
    iVar1 = _suser();
    if (iVar1 != 0) {
loc_401BF10:
      iVar1 = _arpioctl(param_2,param_3);
      return iVar1;
    }
    goto loc_401C02E;
  }
  if (param_2 < -0x7fdb96df) {
    if (param_2 == -0x7fdb96e2) goto loc_401BF04;
  }
  else {
    if (param_2 == -0x3ff796ec) {
      iVar1 = _ifconf(0xc0086914,param_3);
      return iVar1;
    }
    if (param_2 == -0x3fdb96e1) goto loc_401BF10;
  }
  iVar1 = _ifunit(param_3);
  if (iVar1 == 0) {
    return 6;
  }
  if (param_2 == -0x7fdf9683) goto loc_401C03C;
  if (-0x7fdf9683 < param_2) {
    if (param_2 == -0x3fdf96e9) {
      *(undefined4 *)(param_3 + 0x10) = *(undefined4 *)(iVar1 + 0xe);
      return 0;
    }
    if (param_2 < -0x3fdf96e8) {
      if (param_2 != -0x7fdf9681) {
        if (param_2 == -0x3fdf96ef) {
          *(undefined2 *)(param_3 + 0x10) = *(undefined2 *)(iVar1 + 0xc);
          return 0;
        }
        goto loc_401C050;
      }
    }
    else if ((param_2 != -0x3fdf9684) && (param_2 != -0x3fdf9682)) goto loc_401C050;
loc_401C03C:
    if (*(int *)(iVar1 + 0x36) == 0) {
      return 0x2d;
    }
    iVar1 = _if_ioctl(iVar1,param_2,param_3);
    return iVar1;
  }
  if (param_2 == -0x7fdf96e8) {
    iVar2 = _suser();
    if (iVar2 != 0) {
      *(undefined4 *)(iVar1 + 0xe) = *(undefined4 *)(param_3 + 0x10);
      return 0;
    }
loc_401C02E:
    return (int)*(char *)(dword_40B57D4 + 100);
  }
  if (param_2 < -0x7fdf96e7) {
    if (param_2 == -0x7fdf96f0) {
      iVar2 = _suser();
      if (iVar2 != 0) {
        if (((*(byte *)(iVar1 + 0xd) & 1) != 0) && ((*(byte *)(param_3 + 0x11) & 1) == 0)) {
          _if_down(iVar1);
        }
        *(word *)(iVar1 + 0xc) =
             *(word *)(param_3 + 0x10) & 0x37ad | *(word *)(iVar1 + 0xc) & 0xc852;
        _if_ioctl(iVar1,0x80206910,param_3);
        return 0;
      }
      goto loc_401C02E;
    }
  }
  else if ((param_2 < -0x7fdf96cd) && (-0x7fdf96d0 < param_2)) {
    iVar2 = _suser();
    if (iVar2 != 0) goto loc_401C03C;
    goto loc_401C02E;
  }
loc_401C050:
  if (*(int *)(param_1 + 0xc) == 0) {
    return 0x2d;
  }
  iVar1 = (**(code **)(*(int *)(param_1 + 0xc) + 0x1a))(param_1,0xb,param_2,param_3,iVar1);
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=604 start=0x401c07c */

int _ifconf(undefined4 param_1,uint *param_2)

{
  int iVar1;
  char *pcVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  char acStack_24 [16];
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uVar4 = *param_2;
  iVar1 = 0;
  uVar5 = param_2[1];
  if (0x20 < uVar4) {
    puVar6 = _ifnet;
    do {
      if (puVar6 == (undefined4 *)0x0) break;
      _bcopy(*puVar6,acStack_24,0xe);
      for (pcVar2 = acStack_24; (pcVar2 < acStack_24 + 0xe && (*pcVar2 != '\0'));
          pcVar2 = pcVar2 + 1) {
      }
      *pcVar2 = *(char *)((int)puVar6 + 9) + '0';
      pcVar2[1] = '\0';
      puVar3 = *(undefined4 **)((int)puVar6 + 0x16);
      if (puVar3 == (undefined4 *)0x0) {
        _bzero(&uStack_14,0x10);
        iVar1 = _copyoutmsg(acStack_24,uVar5,0x20);
        if (iVar1 != 0) break;
        uVar4 = uVar4 - 0x20;
        uVar5 = uVar5 + 0x20;
      }
      else {
        for (; (0x20 < uVar4 && (puVar3 != (undefined4 *)0x0)); puVar3 = (undefined4 *)puVar3[9]) {
          uStack_14 = *puVar3;
          uStack_10 = puVar3[1];
          uStack_c = puVar3[2];
          uStack_8 = puVar3[3];
          iVar1 = _copyoutmsg(acStack_24,uVar5,0x20);
          if (iVar1 != 0) break;
          uVar4 = uVar4 - 0x20;
          uVar5 = uVar5 + 0x20;
        }
      }
      puVar6 = *(undefined4 **)((int)puVar6 + 0x5a);
    } while (0x20 < uVar4);
  }
  *param_2 = *param_2 - uVar4;
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=605 start=0x401c170 */

int _address_known(int param_1)

{
  return -(int)-(*(int *)(param_1 + 0x16) != 0);
}
/* GHIDRADEC_FUNCTION index=606 start=0x401c186 */

void _logetbuf(void)

{
  _nb_alloc(0x600);
  return;
}
/* GHIDRADEC_FUNCTION index=607 start=0x401c198 */

undefined4 _looutput(undefined4 param_1,undefined4 param_2,sword *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*param_3 == 2) {
    _inet_queue(param_1,param_2);
    iVar2 = _if_opackets(param_1);
    _if_opackets_set(param_1,iVar2 + 1);
    iVar2 = _if_ipackets(param_1);
    _if_ipackets_set(param_1,iVar2 + 1);
    uVar1 = 0;
  }
  else {
    _nb_free(param_2);
    uVar1 = 0x2f;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=608 start=0x401c1fa */

undefined4 _locontrol(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  iVar1 = _strcmp(param_2,&_IFCONTROL_SETADDR);
  if (iVar1 == 0) {
    uVar2 = _if_flags(param_1);
    _if_flags_set(param_1,uVar2 | 0x41);
  }
  else {
    iVar1 = _strcmp(param_2,_IFCONTROL_ADDMULTICAST);
    if ((iVar1 != 0) && (iVar1 = _strcmp(param_2,_IFCONTROL_ADDMULTICAST), iVar1 != 0)) {
      return 0x16;
    }
    if (*(sword *)(param_3 + 0x10) != 2) {
      uVar3 = 0x2f;
    }
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=609 start=0x401c276 */

void _loattach(void)

{
  _loifp = _if_attach(0,0,_looutput,_logetbuf,_locontrol,&aLo,0,aInternetProtoc,0x600,0x808,0x1000,0
                     );
  return;
}
/* GHIDRADEC_FUNCTION index=610 start=0x401c2bc */

void _VENIP_PRIVATE(undefined4 param_1)

{
  _if_private(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=611 start=0x401c2ce */

void _VENIP_ENADDRP(undefined4 param_1)

{
  _if_private(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=612 start=0x401c2e0 */

undefined4 _VENIP_IPADDR(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = _if_private(param_1);
  return *(undefined4 *)(iVar1 + 6);
}
/* GHIDRADEC_FUNCTION index=613 start=0x401c2f8 */

undefined4 _VENIP_RIF(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = _if_private(param_1);
  return *(undefined4 *)(iVar1 + 10);
}
/* GHIDRADEC_FUNCTION index=614 start=0x401c8d4 */

void _venip_config(void)

{
  _if_registervirtual(sub_401C804,0);
  return;
}
/* GHIDRADEC_FUNCTION index=615 start=0x401c900 */

int _nb_alloc(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)_kalloc(param_1 + 4);
  if (piVar1 != (int *)0x0) {
    *piVar1 = param_1 + 4;
    iVar2 = _nb_alloc_wrapper(piVar1 + 1,param_1,sub_401C8EA,piVar1);
    if (iVar2 != 0) {
      return iVar2;
    }
    sub_401C8EA(piVar1);
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=616 start=0x401c950 */

int _nb_alloc_wrapper(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _mclgetx(param_3,param_4,param_1,param_2,0);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = iVar1;
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=617 start=0x401c97a */

int _nb_map(int param_1)

{
  return *(int *)(param_1 + 4) + param_1;
}
/* GHIDRADEC_FUNCTION index=618 start=0x401c98c */

void _nb_free(undefined4 param_1)

{
  _m_freem(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=619 start=0x401c99e */

void _nb_free_wrapper(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 0xc;
  *(undefined2 *)(param_1 + 8) = 0;
  _m_free(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=620 start=0x401c9bc */

int _nb_size(int param_1)

{
  return (int)*(sword *)(param_1 + 8);
}
/* GHIDRADEC_FUNCTION index=621 start=0x401c9ce */

undefined4 _nb_read(int param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if ((uint)(int)*(sword *)(param_1 + 8) < (uint)(param_3 + param_2)) {
    uVar1 = 0xffffffff;
  }
  else {
    _bcopy(*(int *)(param_1 + 4) + param_1 + param_2,param_4,param_3);
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=622 start=0x401ca10 */

undefined4 _nb_write(int param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if ((uint)(int)*(sword *)(param_1 + 8) < (uint)(param_3 + param_2)) {
    uVar1 = 0xffffffff;
  }
  else {
    _bcopy(param_4,*(int *)(param_1 + 4) + param_1 + param_2,param_3);
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=623 start=0x401ca52 */

undefined4 _nb_shrink_top(int param_1,int param_2)

{
  *(sword *)(param_1 + 8) = *(sword *)(param_1 + 8) - (sword)param_2;
  *(int *)(param_1 + 4) = param_2 + *(int *)(param_1 + 4);
  return 0;
}
/* GHIDRADEC_FUNCTION index=624 start=0x401ca6c */

undefined4 _nb_grow_top(int param_1,int param_2)

{
  *(sword *)(param_1 + 8) = (sword)param_2 + *(sword *)(param_1 + 8);
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
  return 0;
}
/* GHIDRADEC_FUNCTION index=625 start=0x401ca86 */

undefined4 _nb_shrink_bot(int param_1,sword param_2)

{
  *(sword *)(param_1 + 8) = *(sword *)(param_1 + 8) - param_2;
  return 0;
}
/* GHIDRADEC_FUNCTION index=626 start=0x401ca9c */

undefined4 _nb_grow_bot(int param_1,sword param_2)

{
  *(sword *)(param_1 + 8) = param_2 + *(sword *)(param_1 + 8);
  return 0;
}
/* GHIDRADEC_FUNCTION index=627 start=0x401cab2 */

undefined4 _if_output(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (*(code **)(param_1 + 0x32) == (code *)0x0) {
    uVar1 = 6;
  }
  else {
    uVar1 = (**(code **)(param_1 + 0x32))(param_1,param_2,param_3);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=628 start=0x401cad6 */

undefined4 _if_control(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (*(code **)(param_1 + 0x36) == (code *)0x0) {
    uVar1 = 6;
  }
  else {
    uVar1 = (**(code **)(param_1 + 0x36))(param_1,param_2,param_3);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=629 start=0x401cafa */

undefined4 _if_ioctl(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  undefined *puVar2;
  uint uStack_c;
  int iStack_8;
  
  if (*(code **)(param_1 + 0x36) == (code *)0x0) {
    return 6;
  }
  if (param_2 == 0x80206931) {
    uVar1 = _if_control(param_1,_IFCONTROL_ADDMULTICAST,param_3);
    return uVar1;
  }
  if (param_2 < 0x80206932) {
    if (param_2 == 0x8020690c) {
      puVar2 = (undefined *)&_IFCONTROL_SETADDR;
    }
    else {
      if (param_2 != 0x80206910) goto loc_401CBA2;
      param_3 = param_3 + 0x10;
      puVar2 = _IFCONTROL_SETFLAGS;
    }
  }
  else if (param_2 == 0xc020690d) {
    param_3 = param_3 + 0x10;
    puVar2 = (undefined *)&_IFCONTROL_GETADDR;
  }
  else if (param_2 < 0xc020690e) {
    if (param_2 != 0x80206932) {
loc_401CBA2:
      uStack_c = param_2;
      iStack_8 = param_3;
      uVar1 = (**(code **)(param_1 + 0x36))(param_1,_IFCONTROL_UNIXIOCTL,&uStack_c);
      return uVar1;
    }
    puVar2 = _IFCONTROL_RMVMULTICAST;
  }
  else {
    if (param_2 != 0xc0206921) goto loc_401CBA2;
    param_3 = param_3 + 0x10;
    puVar2 = _IFCONTROL_AUTOADDR;
  }
  uVar1 = (**(code **)(param_1 + 0x36))(param_1,puVar2,param_3);
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=630 start=0x401cbc4 */

undefined4 _if_init(int param_1)

{
  undefined4 uVar1;
  
  if (*(code **)(param_1 + 0x2e) == (code *)0x0) {
    uVar1 = 6;
  }
  else {
    uVar1 = (**(code **)(param_1 + 0x2e))(param_1);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=631 start=0x401cbe0 */

undefined4 _if_getbuf(int param_1)

{
  undefined4 uVar1;
  
  if (*(code **)(param_1 + 0x3e) == (code *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(param_1 + 0x3e))(param_1);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=632 start=0x401cbfc */

undefined4 _if_private(int param_1)

{
  return *(undefined4 *)(param_1 + 0x56);
}
/* GHIDRADEC_FUNCTION index=633 start=0x401cc0c */

int _if_unit(int param_1)

{
  return (int)*(sword *)(param_1 + 8);
}
/* GHIDRADEC_FUNCTION index=634 start=0x401cc1e */

undefined4 _if_name(undefined4 *param_1)

{
  return *param_1;
}
/* GHIDRADEC_FUNCTION index=635 start=0x401cc2c */

undefined4 _if_type(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}
/* GHIDRADEC_FUNCTION index=636 start=0x401cc3c */

int _if_mtu(int param_1)

{
  return (int)*(sword *)(param_1 + 10);
}
/* GHIDRADEC_FUNCTION index=637 start=0x401cc4e */

undefined4 _if_class(int param_1)

{
  return *(undefined4 *)(param_1 + 0x12);
}
/* GHIDRADEC_FUNCTION index=638 start=0x401cc5e */

int _if_flags(int param_1)

{
  return (int)*(sword *)(param_1 + 0xc);
}
/* GHIDRADEC_FUNCTION index=639 start=0x401cc70 */

undefined4 _if_opackets(int param_1)

{
  return *(undefined4 *)(param_1 + 0x4a);
}
/* GHIDRADEC_FUNCTION index=640 start=0x401cc80 */

undefined4 _if_ipackets(int param_1)

{
  return *(undefined4 *)(param_1 + 0x42);
}
/* GHIDRADEC_FUNCTION index=641 start=0x401cc90 */

undefined4 _if_oerrors(int param_1)

{
  return *(undefined4 *)(param_1 + 0x4e);
}
/* GHIDRADEC_FUNCTION index=642 start=0x401cca0 */

undefined4 _if_ierrors(int param_1)

{
  return *(undefined4 *)(param_1 + 0x46);
}
/* GHIDRADEC_FUNCTION index=643 start=0x401ccb0 */

undefined4 _if_collisions(int param_1)

{
  return *(undefined4 *)(param_1 + 0x52);
}
/* GHIDRADEC_FUNCTION index=644 start=0x401ccc0 */

void _if_flags_set(int param_1,undefined2 param_2)

{
  *(undefined2 *)(param_1 + 0xc) = param_2;
  return;
}
/* GHIDRADEC_FUNCTION index=645 start=0x401ccd2 */

void _if_opackets_set(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x4a) = param_2;
  return;
}
/* GHIDRADEC_FUNCTION index=646 start=0x401cce4 */

void _if_ipackets_set(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x42) = param_2;
  return;
}
/* GHIDRADEC_FUNCTION index=647 start=0x401ccf6 */

void _if_oerrors_set(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x4e) = param_2;
  return;
}
/* GHIDRADEC_FUNCTION index=648 start=0x401cd08 */

void _if_ierrors_set(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x46) = param_2;
  return;
}
/* GHIDRADEC_FUNCTION index=649 start=0x401cd1a */

void _if_collisions_set(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x52) = param_2;
  return;
}

