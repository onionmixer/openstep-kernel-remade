/* GHIDRADEC_FUNCTION index=1925 start=0x4065bbc */

void _configure(void)

{
  _nbic_configure();
  _intr_mask = _intr_mask | 0x38003;
  *_intrmask = *_intrmask | 0x18003;
  sub_4065C02(_bus_cinit,_bus_dinit);
  _setconf();
  _swapconf();
  return;
}
/* GHIDRADEC_FUNCTION index=1926 start=0x4065f0a */

undefined4 _intr_spurious(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = dword_40B4F4E + 1;
  iVar2 = dword_40B4F4E % 0x100;
  dword_40B4F4E = iVar1;
  if (iVar2 == 1) {
    _printf(aIplDSpuriousIn,5);
  }
  return 1;
}
/* GHIDRADEC_FUNCTION index=1927 start=0x4065f50 */

undefined4 _install_polled_intr(undefined8 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  
  uVar1 = (param_1._3_4_ & 0x7fffffff) >> 0x1c;
  if (uVar1 == 5) {
    puVar4 = _poll_intr;
    iVar3 = 0;
    do {
      if (*(int *)puVar4 == 0) break;
      puVar4 = (undefined *)((int)puVar4 + 4);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 8);
    if (7 < iVar3) {
                    /* WARNING: Subroutine does not return */
      _panic(aTooManyPolledI);
    }
    *(int *)puVar4 = *(int *)((int)puVar4 + -4);
    *(int *)((int)puVar4 + -4) = (int)param_1;
    uVar2 = 0;
  }
  else {
    _printf(aIllegalPolling,uVar1);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1928 start=0x4065fb0 */

undefined4 _install_scanned_intr(uint param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  uVar1 = (param_1 & 0x7f) >> 4;
  if (uVar1 == 4) {
    puVar3 = (undefined *)&_ipl4_scan;
    puVar2 = (undefined *)&_ipl4_arg;
  }
  else if (uVar1 < 5) {
    if (uVar1 != 3) {
loc_406601A:
      _printf(aIllegalScannin,uVar1);
      return 0xffffffff;
    }
    puVar3 = _ipl3_scan;
    puVar2 = _ipl3_arg;
  }
  else if (uVar1 == 6) {
    puVar3 = _ipl6_scan;
    puVar2 = _ipl6_arg;
  }
  else {
    if (uVar1 != 7) goto loc_406601A;
    puVar3 = (undefined *)&_ipl7_scan;
    puVar2 = (undefined *)&_ipl7_arg;
  }
  *(undefined4 *)((int)puVar3 + (param_1 & 0xf) * 4) = param_2;
  *(undefined4 *)((int)puVar2 + (param_1 & 0xf) * 4) = param_3;
  uVar1 = 1 << ((param_1 & 0x1fff) >> 8);
  _intr_mask = uVar1 | _intr_mask;
  *_intrmask = uVar1 | *_intrmask;
  return 0;
}
/* GHIDRADEC_FUNCTION index=1929 start=0x4066060 */

undefined4 _uninstall_polled_intr(undefined8 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  
  uVar1 = (param_1._3_4_ & 0x7fffffff) >> 0x1c;
  if (uVar1 == 5) {
    puVar4 = _poll_intr;
    iVar3 = 0;
    do {
      if ((int)param_1 == *(int *)puVar4) break;
      puVar4 = (undefined *)((int)puVar4 + 4);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 8);
    if (iVar3 < 8) {
      for (; (iVar3 < 7 && (*(int *)puVar4 != 0)); puVar4 = (undefined *)((int)puVar4 + 4)) {
        *(int *)puVar4 = *(int *)((int)puVar4 + 4);
        iVar3 = iVar3 + 1;
      }
      *(int *)puVar4 = 0;
      uVar2 = 0;
    }
    else {
      uVar2 = 0xffffffff;
    }
  }
  else {
    _printf(aIllegalPolling,uVar1);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1930 start=0x40660d8 */

undefined4 _uninstall_scanned_intr(uint param_1)

{
  uint uVar1;
  undefined *puVar2;
  undefined *puVar3;
  
  uVar1 = (param_1 & 0x7f) >> 4;
  if (uVar1 == 4) {
    puVar3 = (undefined *)&_ipl4_scan;
    puVar2 = (undefined *)&_ipl4_arg;
  }
  else if (uVar1 < 5) {
    if (uVar1 != 3) {
loc_4066142:
      _printf(aIllegalScannin,uVar1);
      return 0xffffffff;
    }
    puVar3 = _ipl3_scan;
    puVar2 = _ipl3_arg;
  }
  else if (uVar1 == 6) {
    puVar3 = _ipl6_scan;
    puVar2 = _ipl6_arg;
  }
  else {
    if (uVar1 != 7) goto loc_4066142;
    puVar3 = (undefined *)&_ipl7_scan;
    puVar2 = (undefined *)&_ipl7_arg;
  }
  *(undefined4 *)((int)puVar3 + (param_1 & 0xf) * 4) = 0;
  *(undefined4 *)((int)puVar2 + (param_1 & 0xf) * 4) = 0;
  uVar1 = (param_1 & 0x1fff) >> 8;
  uVar1 = -2 << uVar1 | 0xfffffffeU >> 0x20 - uVar1;
  _intr_mask = uVar1 & _intr_mask;
  *_intrmask = uVar1 & *_intrmask;
  return 0;
}
/* GHIDRADEC_FUNCTION index=1931 start=0x406618e */

undefined4 _map_addr(uint param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uStack_8;
  
  if (_slot_id <= param_1) {
    if (_dma_chip == 0x139) {
      if (_machine_type == '\x03') {
        uVar1 = _slot_id + 0x6000000;
      }
      else {
        uVar1 = _slot_id + 0x8000000;
      }
    }
    else {
      uVar1 = _slot_id + 0xc000000;
    }
    if (param_1 < uVar1) {
      return 0;
    }
  }
  iVar2 = _kmem_alloc_pageable(_kernel_map,&uStack_8,param_2);
  if (iVar2 == 0) {
    uVar3 = _ioaccess(param_1,uStack_8,param_2);
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  _panic(aMapAddrNoMemor);
}
/* GHIDRADEC_FUNCTION index=1932 start=0x406622e */

int _dev_find(undefined4 param_1,undefined4 param_2,int param_3,undefined4 *param_4,
             undefined4 param_5)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)*param_4)(param_1,param_2);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    _printf(aSDAt0xX,param_5,param_2,iVar1);
    if (param_3 != 0) {
      iVar2 = _install_polled_intr(param_3,param_4[5]);
      if (-1 < iVar2) {
        _printf(&aIplD,param_3);
      }
    }
    _printf(&asc_40A6049);
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1933 start=0x40662aa */

int _ioaccess(uint param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar2 = (~_page_mask & _page_mask + param_3) >> (_page_shift & 0x3f);
  iVar3 = param_2;
  uVar4 = param_1;
  do {
    uVar1 = _pmap_kernel(iVar3,uVar4,3,0,0,1);
    _pmap_enter_mapping(uVar1);
    uVar4 = _page_size + uVar4;
    iVar3 = _page_size + iVar3;
    uVar2 = uVar2 - 1;
  } while (0 < (int)uVar2);
  return param_2 + (_m68k_page_mask & param_1);
}
/* GHIDRADEC_FUNCTION index=1934 start=0x406631e */

void _swapconf(void)

{
  _dumplo = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=1935 start=0x406632c */

undefined4 _busgo(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  
  piVar1 = *(int **)(param_1 + 0x22);
  piVar2 = (int *)piVar1[3];
  if ((((*(byte *)(*piVar1 + 0x31) & 1) == 0) || (*(sword *)(piVar2 + 2) < 1)) &&
     (*(sword *)((int)piVar2 + 10) == 0)) {
    *(sword *)(piVar2 + 2) = *(sword *)(piVar2 + 2) + 1;
    if ((*(byte *)(*piVar1 + 0x31) & 1) != 0) {
      *(undefined2 *)((int)piVar2 + 10) = 1;
    }
    piVar1[4] = param_1;
    (**(code **)(*piVar1 + 0xc))(piVar1);
    uVar3 = 1;
  }
  else {
    if (param_1 != *piVar2) {
      *(undefined4 *)(param_1 + 0x1e) = 0;
      if (*piVar2 == 0) {
        *piVar2 = param_1;
      }
      else {
        *(int *)(piVar2[1] + 0x1e) = param_1;
      }
      piVar2[1] = param_1;
    }
    uVar3 = 0;
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=1936 start=0x40663b8 */

undefined4 _busdone(int *param_1)

{
  int iVar1;
  int *piVar2;
  sword sVar3;
  undefined2 extraout_D0u;
  undefined2 uVar4;
  undefined4 uVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  char cVar9;
  byte bVar10;
  
  piVar2 = (int *)param_1[3];
  if ((*(byte *)(*param_1 + 0x31) & 1) != 0) {
    *(undefined2 *)((int)piVar2 + 10) = 0;
  }
  sVar3 = *(sword *)(piVar2 + 2);
  cVar9 = sVar3 == 0;
  *(sword *)(piVar2 + 2) = sVar3 + -1;
  iVar1 = *piVar2;
  cVar6 = iVar1 < 0;
  cVar7 = iVar1 == 0;
  cVar8 = '\0';
  bVar10 = 0;
  uVar4 = 0;
  if (!(bool)cVar7) {
    cVar6 = iVar1 < 0;
    cVar7 = iVar1 == 0;
    cVar8 = '\0';
    bVar10 = 0;
    _busgo(iVar1);
    uVar4 = extraout_D0u;
  }
  uVar5 = CONCAT22(uVar4,(word)(byte)(cVar9 << 4 | cVar6 << 3 | cVar7 << 2 | cVar8 << 1 | bVar10));
  if (*(code **)(*param_1 + 0x10) != (code *)0x0) {
    uVar5 = (**(code **)(*param_1 + 0x10))(param_1);
  }
  return uVar5;
}
/* GHIDRADEC_FUNCTION index=1937 start=0x4066410 */

void _dma_init(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & 0xffff8fff;
  **(undefined4 **)(param_1 + 0x1c) = 0x100000;
  _install_scanned_intr(param_2,_dma_intr,param_1);
  uVar1 = param_1 + 0x53U & 0xfffffff0;
  *(uint *)(param_1 + 0x3c) = uVar1;
  if (_m68k_page_size - (_m68k_page_size - 1U & uVar1) < 0x80) {
    iVar2 = _kalloc(0x110);
    *(int *)(param_1 + 0x38) = iVar2;
    uVar1 = iVar2 + 0xfU & 0xfffffff0;
    *(uint *)(param_1 + 0x3c) = uVar1;
    if (_m68k_page_size - (uVar1 & _m68k_page_size - 1U) < 0x80) {
      *(uint *)(param_1 + 0x3c) = uVar1 + 0x80;
    }
  }
  uVar3 = _pmap_kernel(*(undefined4 *)(param_1 + 0x3c));
  uVar3 = _pmap_resident_extract(uVar3);
  *(undefined4 *)(param_1 + 0x40) = uVar3;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=1938 start=0x40664c6 */

void _dma_close(int param_1)

{
  if (*(int *)(param_1 + 0x38) != 0) {
    _kfree(*(int *)(param_1 + 0x38),0x110);
    *(undefined4 *)(param_1 + 0x38) = 0;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1939 start=0x406655a */

byte _dma_enqueue(int *param_1,undefined4 *param_2)

{
  uint uVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  
  param_2[4] = 0;
  *param_2 = 0;
  if ((param_1[0xb] & 0x5004U) != 4) {
    sub_40664EE(param_1,param_2);
  }
  if (*param_1 == 0) {
    param_1[1] = (int)param_2;
    *param_1 = param_1[1];
  }
  else {
    *(undefined4 **)param_1[1] = param_2;
    param_1[1] = (int)param_2;
  }
  uVar1 = param_1[0xb] & 0x5004;
  cVar5 = 4 < uVar1;
  cVar4 = SBORROW4(4,uVar1);
  cVar2 = (int)(4 - uVar1) < 0;
  cVar3 = '\0';
  bVar6 = cVar5;
  if (uVar1 == 4) {
    cVar2 = (int)param_1 < 0;
    cVar3 = param_1 == (int *)0x0;
    cVar4 = '\0';
    bVar6 = 0;
    _dma_start(param_1,param_2,param_1[8]);
  }
  return cVar5 << 4 | cVar2 << 3 | cVar3 << 2 | cVar4 << 1 | bVar6;
}
/* GHIDRADEC_FUNCTION index=1940 start=0x40665dc */

undefined8 _dma_dequeue(int *param_1,int param_2)

{
  int *piVar1;
  char in_XF;
  char in_NF;
  char in_ZF;
  char in_VF;
  byte in_CF;
  
  piVar1 = (int *)*param_1;
  if ((piVar1 == (int *)0x0) || ((param_2 == 0 && (piVar1[4] == 0)))) {
    piVar1 = (int *)0x0;
  }
  else {
    *param_1 = *piVar1;
  }
  return CONCAT44(piVar1,(int)(sword)(word)(byte)(in_XF << 4 | in_NF << 3 | in_ZF << 2 | in_VF << 1
                                                 | in_CF));
}
/* GHIDRADEC_FUNCTION index=1941 start=0x4066614 */

void _dma_list(int param_1,undefined4 *param_2,uint param_3,int param_4,undefined4 param_5,
              int param_6,int param_7,uint param_8,uint param_9)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uStack_c;
  uint uStack_8;
  
  bVar1 = false;
  uVar3 = (param_4 - param_8) - param_9;
  puVar8 = param_2;
  uStack_8 = param_3;
  if ((param_3 & 0xf) != 0) {
    bVar1 = true;
    *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x8000;
    *(uint *)(param_1 + 0xe4) = param_3;
    *(undefined4 *)(param_1 + 0xf4) = param_5;
    iVar7 = 0x10 - (param_3 & 0xf);
    *(int *)(param_1 + 0xe8) = iVar7;
    uVar5 = uVar3 - iVar7;
    *(uint *)(param_1 + 0xec) = uVar5;
    if ((int)uVar5 < 0) {
      uVar5 = uVar5 + 0xf;
    }
    *(uint *)(param_1 + 0xec) = uVar5 & 0xfffffff0;
    iVar7 = uVar3 - (uVar5 & 0xfffffff0);
    *(int *)(param_1 + 0xf0) = iVar7;
    if (param_6 == 0) {
      uVar2 = _pmap_kernel(iVar7);
      _vcopy(*(int *)(param_1 + 0xec) + param_3,param_5,*(undefined4 *)(param_1 + 0x3c),uVar2);
      _vcopy(param_3,param_5,*(int *)(param_1 + 0xe8) + param_3,param_5,
             *(undefined4 *)(param_1 + 0xec));
    }
    uStack_8 = param_3 + 0xf & 0xfffffff0;
    uVar3 = *(uint *)(param_1 + 0xec);
    param_3 = uStack_8;
  }
  while ((0 < param_4 || (bVar1))) {
    if ((param_8 == 0) && (uVar3 != 0)) {
      uStack_c = uStack_8;
    }
    else {
      uStack_c = param_3 & ~_m68k_page_mask;
    }
    iVar7 = _pmap_resident_extract(param_5,uStack_c);
    if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(aDmaListZeroPfn);
    }
    uVar5 = _m68k_page_size - (_m68k_page_mask & uStack_c);
    if (param_8 == 0) {
      if (uVar3 == 0) {
        if (bVar1) {
          iVar6 = *(int *)(param_1 + 0xf0);
          iVar7 = *(int *)(param_1 + 0x40);
          if ((*(uint *)(param_1 + 0x2c) & 2) != 0) {
            iVar6 = iVar6 + 0x20;
          }
          uVar5 = iVar6 + 0xfU & 0xfffffff0;
          bVar1 = false;
        }
        else {
          if ((int)param_9 < (int)uVar5) {
            uVar5 = param_9;
          }
          param_9 = param_9 - uVar5;
        }
      }
      else {
        if ((int)uVar3 < (int)uVar5) {
          uVar5 = uVar3;
        }
        uVar3 = uVar3 - uVar5;
        uStack_8 = uVar5 + uStack_8;
      }
    }
    else {
      if ((int)param_8 < (int)uVar5) {
        uVar5 = param_8;
      }
      param_8 = param_8 - uVar5;
    }
    param_4 = param_4 - uVar5;
    puVar8[3] = 0;
    if ((((_dma_chip == 0x139) && (puVar8 != param_2)) && (iVar7 == puVar8[-5])) &&
       ((int)((uVar5 + iVar7) - puVar8[-6]) < 0x2000)) {
      puVar8 = puVar8 + -7;
    }
    else {
      puVar8[1] = iVar7;
    }
    puVar8[2] = uVar5 + iVar7;
    puVar4 = (undefined4 *)0x0;
    if (0 < param_4) {
      puVar4 = puVar8 + 7;
    }
    *puVar8 = puVar4;
    puVar8[4] = 0;
    puVar8 = puVar8 + 7;
  }
  *(undefined4 *)(param_1 + 0x34) = 0;
  puVar4 = puVar8 + -7;
  uVar3 = puVar8[-5];
  if ((((uVar3 & 0xf) != 0) || ((*(uint *)(param_1 + 0x2c) & 2) != 0)) &&
     (-1 < (sword)*(undefined4 *)(param_1 + 0x2c))) {
    if (param_6 == 0x40000) {
      iVar7 = (uVar3 - puVar8[-6] & 0xfffffff0) + 0x20;
      if (iVar7 < 0x81) {
        *(undefined4 *)(param_1 + 0x30) = puVar8[-6];
        *(undefined4 *)(param_1 + 0x34) = puVar8[-5] - puVar8[-6];
        puVar8 = puVar4;
      }
      else {
        *(uint *)(param_1 + 0x30) = uVar3 & 0xfffffff0;
        *(uint *)(param_1 + 0x34) = puVar8[-5] - (uVar3 & 0xfffffff0);
        iVar7 = 0x20;
        puVar8[-5] = *(undefined4 *)(param_1 + 0x30);
        *puVar4 = puVar8;
      }
      puVar8[1] = *(undefined4 *)(param_1 + 0x40);
      puVar8[2] = puVar8[1] + iVar7;
    }
    else {
      puVar8[-5] = uVar3 + 0xf & 0xfffffff0;
      *puVar4 = puVar8;
      puVar8[1] = *(undefined4 *)(param_1 + 0x40);
      puVar8[2] = puVar8[1] + 0x30;
    }
    *puVar8 = 0;
    puVar8[4] = 0;
    puVar8[3] = 0;
    puVar4 = puVar8;
  }
  if (((int)puVar4 - (int)param_2) * -0x49249249 >> 2 < param_7) {
    param_2[3] = 4;
    if ((_dma_chip == 0x139) && (_slot_id + 0x2000090 == *(int *)(param_1 + 0x1c))) {
      param_2[3] = param_2[3] | 1;
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  _panic(aDmaListDmaList);
}
/* GHIDRADEC_FUNCTION index=1942 start=0x406690a */

undefined4 _dma_start(int param_1,int *param_2,uint param_3)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  word wVar5;
  word wVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  
  *(uint *)(param_1 + 0x20) = param_3;
  puVar2 = *(uint **)(param_1 + 0x1c);
  for (piVar1 = param_2; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
    sub_40664EE(param_1,piVar1);
  }
  if (_dma_chip == 0x139) {
    *puVar2 = param_3 | 0x100000;
    wVar5 = _dma_chip;
    if ((param_2[3] & 4U) == 0) {
      if ((int)(param_2[1] & 0xfffffffU) < _slot_id + 0x4000000) {
loc_4066A18:
                    /* WARNING: Subroutine does not return */
        _panic(aAttemptedDmaOu);
      }
      if (_machine_type == '\x03') {
        iVar3 = _slot_id + 0x6000000;
      }
      else {
        iVar3 = _slot_id + 0x8000000;
      }
      if (iVar3 <= (int)(param_2[1] & 0xfffffffU)) goto loc_4066A18;
      do {
        puVar2[0x1000] = param_2[1];
        if (wVar5 != 0x139) break;
      } while (puVar2[0x1000] != param_2[1]);
    }
    else {
      if ((int)(param_2[1] & 0xfffffffU) < _slot_id + 0x4000000) {
loc_40669A6:
                    /* WARNING: Subroutine does not return */
        _panic(aAttemptedDmaOu);
      }
      if (_machine_type == '\x03') {
        iVar3 = _slot_id + 0x6000000;
      }
      else {
        iVar3 = _slot_id + 0x8000000;
      }
      if (iVar3 <= (int)(param_2[1] & 0xfffffffU)) goto loc_40669A6;
      do {
        puVar2[0x1080] = param_2[1];
        if (wVar5 != 0x139) break;
      } while (puVar2[0x1080] != param_2[1]);
    }
  }
  else {
    if ((param_2[3] & 4U) == 0) {
      uVar7 = param_3 | 0x100000;
    }
    else {
      uVar7 = param_3 | 0x900000;
    }
    *puVar2 = uVar7;
    wVar5 = _dma_chip;
    if ((int)(param_2[1] & 0xfffffffU) < _slot_id + 0x4000000) {
loc_4066AB8:
                    /* WARNING: Subroutine does not return */
      _panic(aAttemptedDmaOu);
    }
    if (_dma_chip == 0x139) {
      if (_machine_type == '\x03') {
        iVar3 = _slot_id + 0x6000000;
      }
      else {
        iVar3 = _slot_id + 0x8000000;
      }
    }
    else {
      iVar3 = _slot_id + 0xc000000;
    }
    if (iVar3 <= (int)(param_2[1] & 0xfffffffU)) goto loc_4066AB8;
    do {
      puVar2[0x1000] = param_2[1];
      if (wVar5 != 0x139) break;
    } while (puVar2[0x1000] != param_2[1]);
  }
  wVar5 = _dma_chip;
  if (_slot_id + 0x4000000 <= (int)(param_2[2] & 0xfffffffU)) {
    if (_dma_chip == 0x139) {
      if (_machine_type == '\x03') {
        iVar3 = _slot_id + 0x6000000;
      }
      else {
        iVar3 = _slot_id + 0x8000000;
      }
    }
    else {
      iVar3 = _slot_id + 0xc000000;
    }
    if ((int)(param_2[2] & 0xfffffffU) < iVar3) {
      do {
        puVar2[0x1001] = param_2[2];
        wVar6 = _dma_chip;
        if (wVar5 != 0x139) break;
      } while (puVar2[0x1001] != param_2[2]);
      if ((*(uint *)(param_1 + 0x2c) & 0x10) != 0) {
        if (wVar5 == 0x139) {
          if ((int)(param_2[1] & 0xfffffffU) < _slot_id + 0x4000000) {
loc_4066BB6:
                    /* WARNING: Subroutine does not return */
            _panic(aAttemptedDmaOu);
          }
          if (_machine_type == '\x03') {
            iVar3 = _slot_id + 0x6000000;
          }
          else {
            iVar3 = _slot_id + 0x8000000;
          }
          if (iVar3 <= (int)(param_2[1] & 0xfffffffU)) goto loc_4066BB6;
          do {
            puVar2[0xffc] = param_2[1];
            wVar5 = _dma_chip;
            if (wVar6 != 0x139) break;
          } while (puVar2[0xffc] != param_2[1]);
          if ((int)(param_2[2] & 0xfffffffU) < _slot_id + 0x4000000) {
loc_4066C30:
                    /* WARNING: Subroutine does not return */
            _panic(aAttemptedDmaOu);
          }
          if (wVar6 == 0x139) {
            if (_machine_type == '\x03') {
              iVar3 = _slot_id + 0x6000000;
            }
            else {
              iVar3 = _slot_id + 0x8000000;
            }
          }
          else {
            iVar3 = _slot_id + 0xc000000;
          }
          if (iVar3 <= (int)(param_2[2] & 0xfffffffU)) goto loc_4066C30;
          do {
            puVar2[0xffd] = param_2[2];
            bVar9 = wVar5 < 0x139;
            if (wVar5 != 0x139) goto loc_4066CBA;
          } while (puVar2[0xffd] != param_2[2]);
        }
        else {
          if (((int)(param_2[1] & 0xfffffffU) < _slot_id + 0x4000000) ||
             (_slot_id + 0xc000000 <= (int)(param_2[1] & 0xfffffffU))) {
                    /* WARNING: Subroutine does not return */
            _panic(aAttemptedDmaOu);
          }
          do {
            puVar2[0x1002] = param_2[1];
            bVar9 = wVar6 < 0x139;
            if (wVar6 != 0x139) goto loc_4066CBA;
          } while (puVar2[0x1002] != param_2[1]);
        }
      }
      bVar9 = _dma_chip < 0x139;
      if (_dma_chip != 0x139) {
loc_4066CBA:
        iVar3 = _slot_id;
        wVar5 = _dma_chip;
        if ((*(uint *)(param_1 + 0x2c) & 8) != 0) {
          if ((int)(param_2[1] & 0xfffffffU) < _slot_id + 0x4000000) {
loc_4066D1A:
                    /* WARNING: Subroutine does not return */
            _panic(aAttemptedDmaOu);
          }
          if (_dma_chip == 0x139) {
            if (_machine_type == '\x03') {
              iVar4 = _slot_id + 0x6000000;
            }
            else {
              iVar4 = _slot_id + 0x8000000;
            }
          }
          else {
            iVar4 = _slot_id + 0xc000000;
          }
          if (iVar4 <= (int)(param_2[1] & 0xfffffffU)) goto loc_4066D1A;
          do {
            *(int *)(iVar3 + 0x200411c) = param_2[1];
            bVar9 = wVar5 < 0x139;
            if (wVar5 != 0x139) break;
            uVar7 = *(uint *)(iVar3 + 0x200411c);
            bVar9 = uVar7 < (uint)param_2[1];
          } while (uVar7 != param_2[1]);
        }
      }
      *(int **)(param_1 + 8) = param_2;
      wVar5 = _dma_chip;
      iVar3 = *param_2;
      if (iVar3 == 0) {
        *puVar2 = param_3 | 0x10000;
loc_4066F72:
        uVar7 = *(uint *)(param_1 + 0x2c);
        uVar8 = uVar7 | 0x1000;
        *(uint *)(param_1 + 0x2c) = uVar8;
        return CONCAT22((sword)(uVar7 >> 0x10),
                        (word)(byte)(bVar9 << 4 | ((int)uVar8 < 0) << 3 | (uVar8 == 0) << 2));
      }
      uVar7 = *(uint *)(iVar3 + 4) & 0xfffffff;
      if (_slot_id + 0x4000000 <= (int)uVar7) {
        if (_dma_chip == 0x139) {
          if (_machine_type == '\x03') {
            iVar4 = _slot_id + 0x6000000;
          }
          else {
            iVar4 = _slot_id + 0x8000000;
          }
        }
        else {
          iVar4 = _slot_id + 0xc000000;
        }
        if ((int)uVar7 < iVar4) {
          do {
            puVar2[0x1002] = *(uint *)(iVar3 + 4);
            wVar6 = _dma_chip;
            if (wVar5 != 0x139) break;
          } while (puVar2[0x1002] != *(uint *)(iVar3 + 4));
          uVar7 = *(uint *)(iVar3 + 8) & 0xfffffff;
          if (_slot_id + 0x4000000 <= (int)uVar7) {
            if (wVar5 == 0x139) {
              if (_machine_type == '\x03') {
                iVar4 = _slot_id + 0x6000000;
              }
              else {
                iVar4 = _slot_id + 0x8000000;
              }
            }
            else {
              iVar4 = _slot_id + 0xc000000;
            }
            if ((int)uVar7 < iVar4) {
              do {
                puVar2[0x1003] = *(uint *)(iVar3 + 8);
                wVar5 = _dma_chip;
                bVar9 = wVar6 < 0x139;
                if (wVar6 != 0x139) break;
                bVar9 = puVar2[0x1003] < *(uint *)(iVar3 + 8);
              } while (puVar2[0x1003] != *(uint *)(iVar3 + 8));
              if ((*(uint *)(param_1 + 0x2c) & 0x10) != 0) {
                uVar7 = *(uint *)(iVar3 + 4) & 0xfffffff;
                if ((int)uVar7 < _slot_id + 0x4000000) {
loc_4066EB0:
                    /* WARNING: Subroutine does not return */
                  _panic(aAttemptedDmaOu);
                }
                if (wVar6 == 0x139) {
                  if (_machine_type == '\x03') {
                    iVar4 = _slot_id + 0x6000000;
                  }
                  else {
                    iVar4 = _slot_id + 0x8000000;
                  }
                }
                else {
                  iVar4 = _slot_id + 0xc000000;
                }
                if (iVar4 <= (int)uVar7) goto loc_4066EB0;
                do {
                  puVar2[0xffe] = *(uint *)(iVar3 + 4);
                  wVar6 = _dma_chip;
                  if (wVar5 != 0x139) break;
                } while (puVar2[0xffe] != *(uint *)(iVar3 + 4));
                uVar7 = *(uint *)(iVar3 + 8) & 0xfffffff;
                if ((int)uVar7 < _slot_id + 0x4000000) {
loc_4066F2A:
                    /* WARNING: Subroutine does not return */
                  _panic(aAttemptedDmaOu);
                }
                if (wVar5 == 0x139) {
                  if (_machine_type == '\x03') {
                    iVar4 = _slot_id + 0x6000000;
                  }
                  else {
                    iVar4 = _slot_id + 0x8000000;
                  }
                }
                else {
                  iVar4 = _slot_id + 0xc000000;
                }
                if (iVar4 <= (int)uVar7) goto loc_4066F2A;
                do {
                  puVar2[0xfff] = *(uint *)(iVar3 + 8);
                  bVar9 = wVar6 < 0x139;
                  if (wVar6 != 0x139) break;
                  bVar9 = puVar2[0xfff] < *(uint *)(iVar3 + 8);
                } while (puVar2[0xfff] != *(uint *)(iVar3 + 8));
              }
              *puVar2 = param_3 | 0x30000;
              *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x2000;
              goto loc_4066F72;
            }
          }
                    /* WARNING: Subroutine does not return */
          _panic(aAttemptedDmaOu);
        }
      }
                    /* WARNING: Subroutine does not return */
      _panic(aAttemptedDmaOu);
    }
  }
                    /* WARNING: Subroutine does not return */
  _panic(aAttemptedDmaOu);
}
/* GHIDRADEC_FUNCTION index=1943 start=0x4066f8e */

void _dma_cleanup(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  _dma_abort(param_1);
  if (param_2 < 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aDmaCleanupNega);
  }
  if ((sword)*(undefined4 *)(param_1 + 0x2c) < 0) {
    iVar2 = *(int *)(param_1 + 0xf0) + *(int *)(param_1 + 0xec);
    if (*(int *)(param_1 + 0x20) != 0) {
      iVar2 = iVar2 - param_2;
    }
    uVar1 = _min(*(int *)(param_1 + 0xec),iVar2);
    _vcopy(*(int *)(param_1 + 0xe8) + *(int *)(param_1 + 0xe4),*(undefined4 *)(param_1 + 0xf4),
           *(undefined4 *)(param_1 + 0xe4),*(undefined4 *)(param_1 + 0xf4),uVar1);
    iVar2 = iVar2 - *(int *)(param_1 + 0xec);
    if (0 < iVar2) {
      uVar1 = _pmap_kernel(*(int *)(param_1 + 0xe4) + *(int *)(param_1 + 0xec),
                           *(undefined4 *)(param_1 + 0xf4),iVar2);
      _vcopy(*(undefined4 *)(param_1 + 0x3c),uVar1);
    }
    *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & 0xffff7fff;
  }
  else if (param_2 < *(int *)(param_1 + 0x34)) {
    _bcopy(*(undefined4 *)(param_1 + 0x3c),*(undefined4 *)(param_1 + 0x30),
           *(int *)(param_1 + 0x34) - param_2);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1944 start=0x4067058 */

undefined8 _dma_abort(int param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int unaff_A2;
  char in_XF;
  bool bVar4;
  
  puVar1 = *(uint **)(param_1 + 0x1c);
  bVar4 = false;
  if ((*(uint *)(param_1 + 0x2c) & 0x1000) != 0) {
    bVar4 = _dma_chip < 0x139;
    if (_dma_chip == 0x139) {
      do {
      } while (*puVar1 == 0);
      uVar2 = *puVar1 & 0xb000000;
    }
    else {
      uVar2 = *puVar1 & 0x1b000000;
    }
    *(uint *)(param_1 + 0x24) = uVar2;
    *(uint *)(param_1 + 0x28) = puVar1[0x1000];
    if (*(int *)(param_1 + 8) != 0) {
      bVar4 = _dma_chip < 0x139;
      if (_dma_chip == 0x139) {
        do {
        } while (*puVar1 == 0);
        uVar2 = *puVar1 & 0xb000000;
      }
      else {
        uVar2 = *puVar1 & 0x1b000000;
      }
      *(uint *)(*(int *)(param_1 + 8) + 0x10) = uVar2;
      *(uint *)(*(int *)(param_1 + 8) + 0x14) = puVar1[0x1000];
    }
  }
  *puVar1 = 0x100000;
  uVar2 = *(uint *)(param_1 + 0x2c);
  uVar3 = uVar2 & 0xffffcfff;
  *(uint *)(param_1 + 0x2c) = uVar3;
  return CONCAT44(CONCAT22((sword)(uVar2 >> 0x10),
                           (word)(byte)(bVar4 << 4 | ((int)uVar3 < 0) << 3 | (uVar3 == 0) << 2)),
                  (int)(sword)(word)(byte)(in_XF << 4 | (unaff_A2 < 0) << 3 | (unaff_A2 == 0) << 2))
  ;
}
/* GHIDRADEC_FUNCTION index=1945 start=0x40670f6 */

uint _dma_intr(int param_1,undefined4 param_2,undefined8 param_3)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  sword sVar4;
  sword sVar5;
  uint uVar6;
  uint in_D1;
  uint extraout_D1;
  uint extraout_D1_00;
  int *piVar7;
  char cVar8;
  char cVar9;
  char cVar10;
  char cVar11;
  byte bVar12;
  
  puVar2 = *(uint **)(param_1 + 0x1c);
  piVar7 = *(int **)(param_1 + 8);
  if (((*(uint *)(param_1 + 0x2c) & 0x1000) == 0) || (piVar7 == (int *)0x0)) {
    uVar6 = _printf(aSpuriousDmaInt,puVar2);
    *puVar2 = 0x100000;
  }
  else {
    if (_dma_chip == 0x139) {
      do {
      } while (*puVar2 == 0);
      uVar6 = *puVar2 & 0xb000000;
    }
    else {
      uVar6 = *puVar2 & 0x1b000000;
    }
    if ((uVar6 == 0x1000000) || (uVar6 == 0x3000000)) {
      if (_dma_chip == 0x139) {
        do {
        } while (*puVar2 == 0);
        uVar6 = *puVar2 & 0xb000000;
      }
      else {
        uVar6 = *puVar2 & 0x1b000000;
      }
      if ((uVar6 == 0x1000000) || (uVar6 == 0x3000000)) {
        uVar6 = _printf(aSpuriousDmaInt_0,uVar6,puVar2);
        return uVar6;
      }
      _printf(aBadDmaCsrReadD,puVar2);
      in_D1 = extraout_D1;
    }
    piVar7[4] = uVar6;
    if (uVar6 == 0x9000000) {
      if ((*(uint *)(param_1 + 0x2c) & 8) != 0) {
        if (_dma_chip == 0x139) {
          piVar7[5] = puVar2[0xffd];
        }
        else {
          piVar7[5] = *(int *)(_slot_id + 0x2004050);
        }
      }
      piVar7 = (int *)*piVar7;
      *(int **)(param_1 + 8) = piVar7;
      sVar4 = _dma_chip;
      iVar1 = *piVar7;
      if (iVar1 == 0) {
        *puVar2 = *(uint *)(param_1 + 0x20) | 0x80000;
        *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & 0xffffdfff;
      }
      else {
        uVar6 = *(uint *)(iVar1 + 4) & 0xfffffff;
        if ((int)uVar6 < _slot_id + 0x4000000) {
loc_4067256:
                    /* WARNING: Subroutine does not return */
          _panic(aAttemptedDmaOu);
        }
        if (_dma_chip == 0x139) {
          if (_machine_type == '\x03') {
            iVar3 = _slot_id + 0x6000000;
          }
          else {
            iVar3 = _slot_id + 0x8000000;
          }
        }
        else {
          iVar3 = _slot_id + 0xc000000;
        }
        if (iVar3 <= (int)uVar6) goto loc_4067256;
        do {
          puVar2[0x1002] = *(uint *)(iVar1 + 4);
          sVar5 = _dma_chip;
          if (sVar4 != 0x139) break;
        } while (puVar2[0x1002] != *(uint *)(iVar1 + 4));
        in_D1 = *(uint *)(iVar1 + 8) & 0xfffffff;
        if ((int)in_D1 < _slot_id + 0x4000000) {
loc_40672D0:
                    /* WARNING: Subroutine does not return */
          _panic(aAttemptedDmaOu);
        }
        if (sVar4 == 0x139) {
          if (_machine_type == '\x03') {
            iVar3 = _slot_id + 0x6000000;
          }
          else {
            iVar3 = _slot_id + 0x8000000;
          }
        }
        else {
          iVar3 = _slot_id + 0xc000000;
        }
        if (iVar3 <= (int)in_D1) goto loc_40672D0;
        do {
          puVar2[0x1003] = *(uint *)(iVar1 + 8);
          sVar4 = _dma_chip;
          if (sVar5 != 0x139) break;
        } while (puVar2[0x1003] != *(uint *)(iVar1 + 8));
        if ((*(uint *)(param_1 + 0x2c) & 0x10) != 0) {
          uVar6 = *(uint *)(iVar1 + 4) & 0xfffffff;
          if ((int)uVar6 < _slot_id + 0x4000000) {
loc_4067356:
                    /* WARNING: Subroutine does not return */
            _panic(aAttemptedDmaOu);
          }
          if (sVar5 == 0x139) {
            if (_machine_type == '\x03') {
              iVar3 = _slot_id + 0x6000000;
            }
            else {
              iVar3 = _slot_id + 0x8000000;
            }
          }
          else {
            iVar3 = _slot_id + 0xc000000;
          }
          if (iVar3 <= (int)uVar6) goto loc_4067356;
          do {
            puVar2[0xffe] = *(uint *)(iVar1 + 4);
            sVar5 = _dma_chip;
            if (sVar4 != 0x139) break;
          } while (puVar2[0xffe] != *(uint *)(iVar1 + 4));
          uVar6 = *(uint *)(iVar1 + 8) & 0xfffffff;
          if ((int)uVar6 < _slot_id + 0x4000000) {
loc_40673D0:
                    /* WARNING: Subroutine does not return */
            _panic(aAttemptedDmaOu);
          }
          if (sVar4 == 0x139) {
            if (_machine_type == '\x03') {
              iVar3 = _slot_id + 0x6000000;
            }
            else {
              iVar3 = _slot_id + 0x8000000;
            }
          }
          else {
            iVar3 = _slot_id + 0xc000000;
          }
          if (iVar3 <= (int)uVar6) goto loc_40673D0;
          in_D1 = CONCAT22((sword)(uVar6 >> 0x10),_dma_chip);
          do {
            puVar2[0xfff] = *(uint *)(iVar1 + 8);
            if (sVar5 != 0x139) break;
          } while (puVar2[0xfff] != *(uint *)(iVar1 + 8));
        }
        *puVar2 = *(uint *)(param_1 + 0x20) | 0xa0000;
      }
      if ((char)*(undefined4 *)(param_1 + 0x2c) < '\0') {
        _callout_dispatch(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x10),
                          *(undefined4 *)(param_1 + 0x14));
        in_D1 = extraout_D1_00;
      }
      if (_dma_chip == 0x139) {
        do {
        } while (*puVar2 == 0);
        uVar6 = *puVar2 & 0xb000000;
      }
      else {
        uVar6 = *puVar2 & 0x1b000000;
      }
      if ((uVar6 != 0xa000000) && (uVar6 != 0x1a000000)) {
        return 0;
      }
      uVar6 = uVar6 & 0xfdffffff;
      *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & 0xffffdfff;
      piVar7[4] = uVar6;
    }
    if ((*(uint *)(param_1 + 0x2c) & 0x2000) != 0) {
      if ((*(uint *)(param_1 + 0x2c) & 8) != 0) {
        if (_dma_chip == 0x139) {
          piVar7[5] = puVar2[0xffd];
        }
        else {
          piVar7[5] = *(int *)(_slot_id + 0x2004050);
        }
      }
      piVar7[4] = 0x9000000;
      *(int *)(param_1 + 8) = *piVar7;
      piVar7 = *(int **)(param_1 + 8);
      piVar7[4] = uVar6;
    }
    if ((_dma_chip == 0x139) || ((*(uint *)(param_1 + 0x2c) & 8) == 0)) {
      piVar7[5] = puVar2[0x1000];
    }
    else {
      piVar7[5] = (CONCAT31((int3)(in_D1 >> 8),*(undefined *)(_slot_id_bmap + 0x2006007)) |
                  0xfffffff0) + puVar2[0x1000];
    }
    *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) & 0xffffcfff;
    if ((((_dma_chip == 0x139) || ((uVar6 & 0x10000000) == 0)) &&
        ((*(uint *)(param_1 + 0x2c) & 4) != 0)) && (*piVar7 != 0)) {
      _dma_start(param_1,*piVar7,*(undefined4 *)(param_1 + 0x20));
      uVar6 = *(uint *)(param_1 + 0x2c);
      if ((char)uVar6 < '\0') {
        uVar6 = _callout_dispatch(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x10),
                                  *(undefined4 *)(param_1 + 0x14));
      }
    }
    else {
      *(undefined4 *)(param_1 + 8) = 0;
      *puVar2 = 0x100000;
      *(uint *)(param_1 + 0x24) = uVar6;
      *(uint *)(param_1 + 0x28) = puVar2[0x1000];
      if (uVar6 == 0xa000000) {
        *(uint *)(param_1 + 0x2c) = *(uint *)(param_1 + 0x2c) | 0x4000;
      }
      if ((*(uint *)(param_1 + 0x2c) & 0x20) != 0) {
        (**(code **)(param_1 + 0xc))(*(undefined4 *)(param_1 + 0x14));
      }
      uVar6 = 0;
      if ((*(uint *)(param_1 + 0x2c) & 0x4001) != 0) {
        _callout_dispatch(*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x10),
                          *(undefined4 *)(param_1 + 0x14));
        uVar6 = (param_3._2_4_ & 0x7ffffff) >> 0x18;
        if (((int)uVar6 < *(int *)(param_1 + 0x18) + 1) && (*(int *)(param_1 + 0x18) != 4)) {
          cVar8 = '\0';
          iVar1 = *(int *)(param_1 + 0x18);
          cVar9 = iVar1 < 0;
          cVar10 = iVar1 == 0;
          cVar11 = '\0';
          bVar12 = 0;
          _softint_run(iVar1);
          uVar6 = (uint)(byte)(cVar8 << 4 | cVar9 << 3 | cVar10 << 2 | cVar11 << 1 | bVar12);
        }
      }
    }
  }
  return uVar6;
}
/* GHIDRADEC_FUNCTION index=1946 start=0x406760a */

void _cache_flush(uint param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (_dma_chip == 0x139) {
    param_1 = param_1 & 0x3fffffff;
    param_2 = param_2 & 0x3fffffff;
  }
  while( true ) {
    if (param_2 <= param_1) {
      return;
    }
    iVar3 = _m68k_page_size - (_m68k_page_mask & param_1);
    if (param_2 < iVar3 + param_1) {
      iVar3 = param_2 - param_1;
    }
    uVar1 = _pmap_kernel(param_1);
    iVar2 = _pmap_resident_extract(uVar1);
    if (iVar2 == 0) break;
    if (param_3 == 0) {
      _cache_push_page(iVar2);
    }
    else {
      _cache_inval_page(iVar2);
      if (_ncc_chip != 0) {
        _nitro_cache_flush(iVar2,iVar3);
      }
    }
    param_1 = iVar3 + param_1;
  }
                    /* WARNING: Subroutine does not return */
  _panic(aCacheFlushPage);
}
/* GHIDRADEC_FUNCTION index=1947 start=0x40676b8 */

void _nitro_cache_flush(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  if (_cache != 0) {
    if (dword_40B4F52 == 0) {
      dword_40B4F52 = 1;
      if ((*(uint *)(_slot_id + 0x2210000) & 0x11e) == 0) {
        dword_40B4F56 = 0x20000;
        *(undefined4 *)(_slot_id + 0x2210000) = 0x10c;
      }
      else {
        uVar1 = *(uint *)(_slot_id + 0x2210000) & 0x18;
        if (uVar1 == 8) {
          dword_40B4F56 = 0x20000;
        }
        else if (uVar1 < 9) {
          if (uVar1 == 0) {
            dword_40B4F56 = 0x10000;
          }
        }
        else if (uVar1 == 0x10) {
          dword_40B4F56 = 0x40000;
        }
        else if (uVar1 == 0x18) {
          dword_40B4F56 = 0x80000;
        }
      }
      iVar3 = 0;
      if (0 < dword_40B4F56) {
        do {
          *(undefined4 *)(_slot_id + iVar3 + 0x3e00000) = 0;
          iVar3 = iVar3 + 0x20;
        } while (iVar3 < dword_40B4F56);
      }
      *(uint *)(_slot_id + 0x2210000) = *(uint *)(_slot_id + 0x2210000) | 1;
    }
    uVar1 = dword_40B4F56 - 1;
    uVar4 = 0;
    uVar2 = param_2 + 0x1fU >> 5;
    if (uVar2 != 0) {
      do {
        *(undefined4 *)(_slot_id + (uVar1 & param_1) + uVar4 * 0x20 + 0x3e00000) = 0;
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar2);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1948 start=0x40677de */

void _vcopy(uint param_1,undefined4 param_2,uint param_3,undefined4 param_4,uint param_5)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_3 < param_1) {
    for (; param_5 != 0; param_5 = param_5 - uVar2) {
      uVar3 = _m68k_page_size - (_m68k_page_mask & param_1);
      uVar2 = param_5;
      if (uVar3 <= param_5) {
        uVar2 = uVar3;
      }
      uVar3 = _m68k_page_size - (_m68k_page_mask & param_3);
      if (uVar3 <= uVar2) {
        uVar2 = uVar3;
      }
      uVar1 = _pmap_resident_extract(param_4,param_3,uVar2);
      uVar1 = _pmap_resident_extract(param_2,param_1,uVar1);
      _bcopy(uVar1);
      param_1 = uVar2 + param_1;
      param_3 = uVar2 + param_3;
    }
  }
  else {
    param_1 = param_5 + param_1;
    param_3 = param_5 + param_3;
    for (; param_5 != 0; param_5 = param_5 - uVar3) {
      uVar2 = _m68k_page_mask & param_1;
      if ((_m68k_page_mask & param_1) == 0) {
        uVar2 = _m68k_page_size;
      }
      uVar3 = param_5;
      if ((int)uVar2 < (int)param_5) {
        uVar3 = uVar2;
      }
      uVar2 = _m68k_page_mask & param_3;
      if ((_m68k_page_mask & param_3) == 0) {
        uVar2 = _m68k_page_size;
      }
      if ((int)uVar2 < (int)uVar3) {
        uVar3 = uVar2;
      }
      param_1 = param_1 - uVar3;
      param_3 = param_3 - uVar3;
      uVar1 = _pmap_resident_extract(param_4,param_3,uVar3);
      uVar1 = _pmap_resident_extract(param_2,param_1,uVar1);
      _bcopy(uVar1);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1949 start=0x40678ce */

void _evinit(void)

{
  _nbic_bus_enable();
  _km_send(0xc5,0xef000000);
  _km_send(0xc5,0);
  _mon_send(0xc6,0x1fffff1);
  _install_scanned_intr(0x23b,sub_40682E2,0);
  _install_scanned_intr(0x1f70,_call_nmi,0);
  if (_dma_chip != 0x139) {
    _install_scanned_intr(0x1e71,_call_nmi,0);
  }
  _install_scanned_intr(0x33a,_evintr,0);
  return;
}

