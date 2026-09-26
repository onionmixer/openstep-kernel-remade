/* GHIDRADEC_FUNCTION index=2350 start=0x408d79c */

undefined4 _zsint(void)

{
  byte bVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  while( true ) {
    _delay(1);
    *(undefined *)(_slot_id_bmap + 0x2018001) = 3;
    _delay(1);
    bVar1 = *(byte *)(_slot_id_bmap + 0x2018001);
    if (bVar1 == 0) break;
    if ((bVar1 & 8) != 0) {
      (**(code **)(*off_40B243E + 8))(0);
      uVar2 = 1;
    }
    if ((bVar1 & 1) != 0) {
      (*(code *)off_40B2446[2])(1);
      uVar2 = 1;
    }
    if ((bVar1 & 0x20) != 0) {
      (**(code **)(*off_40B243E + 4))(0);
      uVar2 = 1;
    }
    if ((bVar1 & 4) != 0) {
      (*(code *)off_40B2446[1])(1);
      uVar2 = 1;
    }
    if ((bVar1 & 0x10) != 0) {
      (**(code **)*off_40B243E)(0);
      uVar2 = 1;
    }
    if ((bVar1 & 2) != 0) {
      (*(code *)*off_40B2446)(1);
      uVar2 = 1;
    }
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=2351 start=0x408d884 */

void _zsnullintr(int param_1)

{
  undefined *puVar1;
  
  if (param_1 == 0) {
    puVar1 = (undefined *)(_slot_id_bmap + 0x2018001);
  }
  else {
    puVar1 = (undefined *)(_slot_id_bmap + 0x2018000);
  }
  _delay(1);
  *puVar1 = 1;
  _delay(1);
  *puVar1 = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=2352 start=0x408d8d0 */

void _zsintsetup(void)

{
  undefined uVar1;
  
  uVar1 = 0x30;
  if (_dma_chip == 0x139) {
    uVar1 = 10;
  }
  *(undefined *)(_slot_id_bmap + 0x2018004) = uVar1;
  _install_polled_intr(0x1150,_zsint);
  if ((1 < _console_i - 1U) && (1 < _console_o - 1U)) {
    if (_machine_type == '\0') {
      uVar1 = 0;
      if (_board_rev < 3) {
        uVar1 = 2;
      }
    }
    else {
      uVar1 = 0;
    }
    _delay(1);
    *(undefined *)(_slot_id_bmap + 0x2018001) = 5;
    _delay(1);
    *(undefined *)(_slot_id_bmap + 0x2018001) = uVar1;
    _delay(1);
    *(undefined *)(_slot_id_bmap + 0x2018000) = 5;
    _delay(1);
    *(undefined *)(_slot_id_bmap + 0x2018000) = uVar1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2353 start=0x408da60 */

undefined4 * _enbuf_get(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  if ((dword_40B244A == (undefined4 *)0x0) && (iVar2 = sub_408D9D4(), iVar2 != 0)) {
    return (undefined4 *)0x0;
  }
  puVar1 = dword_40B244A;
  dword_40B2452 = dword_40B2452 + -1;
  dword_40B244A = (undefined4 *)*dword_40B244A;
  return puVar1;
}
/* GHIDRADEC_FUNCTION index=2354 start=0x408daaa */

int _engetbuf(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _enbuf_get();
  if (iVar1 != 0) {
    iVar2 = _nb_alloc_wrapper(iVar1,0x5ea,sub_408D9AA,iVar1);
    if (iVar2 != 0) {
      return iVar2;
    }
    sub_408D9AA(iVar1);
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=2355 start=0x408dae8 */

undefined4 _if_busalloc(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    iVar1 = _enbuf_get();
    *(int *)(param_1 + 0x1c) = iVar1;
    if (iVar1 == 0) {
      return 0;
    }
  }
  else {
    uVar2 = _nb_map(param_2);
    *(undefined4 *)(param_1 + 0x1c) = uVar2;
    _nb_free_wrapper(param_2);
  }
  uVar2 = _pmap_resident_extract(*(undefined4 *)(_mb_map + 0x20),*(undefined4 *)(param_1 + 0x1c));
  *(undefined4 *)(param_1 + 4) = uVar2;
  return 1;
}
/* GHIDRADEC_FUNCTION index=2356 start=0x408db46 */

void _if_busfree(int param_1)

{
  sub_408D9AA(*(undefined4 *)(param_1 + 0x1c));
  *(undefined4 *)(param_1 + 4) = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=2357 start=0x408db66 */

void _if_rbusget(int param_1,undefined4 param_2,undefined4 param_3)

{
  _nb_alloc_wrapper(param_2,param_3,sub_408D9AA,*(undefined4 *)(param_1 + 0x1c));
  return;
}
/* GHIDRADEC_FUNCTION index=2358 start=0x408dc68 */

int _enprobe(int param_1)

{
  return _slot_id_bmap + param_1;
}
/* GHIDRADEC_FUNCTION index=2359 start=0x408dc7a */

void _enattach(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  sword sVar3;
  int iVar4;
  undefined4 uVar5;
  code *pcVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  
  iVar4 = *(sword *)(param_1 + 4) * 0x52c;
  puVar10 = &_en_softc + *(sword *)(param_1 + 4) * 0x14b;
  iVar2 = iVar4 + 0x40c903a;
  iVar8 = *(int *)(param_1 + 0x12);
  *(int *)(DAT_40c8f42 + iVar4 + 0x1f0) = iVar8;
  _bcopy(&_etheraddr,(int)&unk_40C8F38 + iVar4,6);
  _bytecopy(&_etheraddr,iVar8 + 8,6);
  uVar5 = _ether_sprintf((int)&unk_40C8F38 + iVar4);
  _printf(aEnDEthernetAdd,(int)*(sword *)(param_1 + 4),uVar5);
  *(undefined *)(iVar8 + 6) = 0x80;
  if (_dma_chip != 0x139) {
    *(undefined *)(iVar8 + 6) = 0;
  }
  _bzero(DAT_40c8f42 + iVar4,0xf8);
  sVar3 = _dma_chip;
  pcVar6 = (code *)0x0;
  if (_dma_chip == 0x139) {
    pcVar6 = _en_tx_dmaintr;
  }
  *(code **)(DAT_40c8f42 + iVar4 + 0x10) = pcVar6;
  *(int *)(DAT_40c8f42 + iVar4 + 0x14) = (int)*(sword *)(param_1 + 4);
  *(undefined4 *)(DAT_40c8f42 + iVar4 + 0x18) = 1;
  *(int *)(DAT_40c8f42 + iVar4 + 0x1c) = _slot_id + 0x2000110;
  uVar5 = 0x14;
  if (sVar3 == 0x139) {
    uVar5 = 0x15;
  }
  *(undefined4 *)(DAT_40c8f42 + iVar4 + 0x2c) = uVar5;
  *(undefined4 *)(DAT_40c8f42 + iVar4 + 0x20) = 0;
  _dma_init(DAT_40c8f42 + iVar4,0x1c61);
  _install_scanned_intr(0xa33,_en_tx_devintr,(int)*(sword *)(param_1 + 4));
  *(undefined4 *)(DAT_40c944e + iVar4) = 0;
  *(undefined4 *)(DAT_40c944e + iVar4 + 4) = 0;
  iVar8 = 0;
  iVar9 = 0x41a;
  do {
    *(undefined4 *)((int)puVar10 + iVar9) = *(undefined4 *)(DAT_40c944e + iVar4);
    *(undefined4 **)(DAT_40c944e + iVar4) = (undefined4 *)((int)puVar10 + iVar9);
    iVar9 = iVar9 + 0x20;
    iVar8 = iVar8 + 1;
  } while (iVar8 < 8);
  _bzero(iVar2,0xf8);
  *(code **)(DAT_40c8f42 + iVar4 + 0x108) = _en_rx_dmaintr;
  *(int *)(DAT_40c8f42 + iVar4 + 0x10c) = (int)*(sword *)(param_1 + 4);
  *(undefined4 *)(DAT_40c8f42 + iVar4 + 0x110) = 1;
  *(int *)(DAT_40c8f42 + iVar4 + 0x114) = _slot_id + 0x2000150;
  *(undefined4 *)(DAT_40c8f42 + iVar4 + 0x124) = 0x8d;
  *(undefined4 *)(DAT_40c8f42 + iVar4 + 0x118) = 0x40000;
  _dma_init(iVar2,0x1b62);
  if (_dma_chip != 0x139) {
    _install_scanned_intr(0x934,_en_rx_devintr,(int)*(sword *)(param_1 + 4));
  }
  iVar8 = 0;
  iVar9 = 0x21a;
  do {
    puVar1 = (undefined4 *)((int)puVar10 + iVar9);
    iVar7 = _if_busalloc(puVar1,0);
    if (iVar7 == 0) {
      *puVar1 = *(undefined4 *)(DAT_40c944e + iVar4 + 4);
      *(undefined4 **)(DAT_40c944e + iVar4 + 4) = puVar1;
    }
    else {
      puVar1[2] = puVar1[1] + 0x63d & 0xfffffff0;
      puVar1[3] = 4;
      _dma_enqueue(iVar2,puVar1);
    }
    iVar9 = iVar9 + 0x20;
    iVar8 = iVar8 + 1;
  } while (iVar8 < 0x10);
  *(undefined4 *)(DAT_40c944e + iVar4 + 0xc) = 0;
  uVar5 = _if_attach(_eninit,0,_enoutput,_engetbuf,_encontrol,&aEn,(int)*(sword *)(param_1 + 4),
                     a10mbEthernet,0x5dc,0,0,0);
  *puVar10 = uVar5;
  return;
}
/* GHIDRADEC_FUNCTION index=2360 start=0x408deca */

void _eninit(int param_1)

{
  undefined *puVar1;
  int iVar2;
  undefined uVar4;
  undefined4 uVar3;
  
  iVar2 = _if_unit(param_1);
  puVar1 = *(undefined **)((&_eninfo)[iVar2] + 0x12);
  if ((*(uint *)(&DAT_40c9136 + iVar2 * 0x14b) & 1) == 0) {
    *(uint *)(&DAT_40c9136 + iVar2 * 0x14b) = *(uint *)(&DAT_40c9136 + iVar2 * 0x14b) | 1;
    *(word *)(param_1 + 0xc) = *(word *)(param_1 + 0xc) | 0x41;
    puVar1[6] = 0x80;
    if (_dma_chip != 0x139) {
      puVar1[6] = 0;
    }
    if (((&byte_40C9139)[iVar2 * 0x52c] & 4) != 0) {
      _bytecopy((int)&unk_40C8F38 + iVar2 * 0x52c,puVar1 + 8,6);
      *(uint *)(&DAT_40c9136 + iVar2 * 0x14b) = *(uint *)(&DAT_40c9136 + iVar2 * 0x14b) & 0xfffffffb
      ;
    }
    if (_dma_chip == 0x139) {
      puVar1[4] = 0;
    }
    else {
      puVar1[4] = 4;
      _delay(500000);
    }
    *puVar1 = 0xff;
    uVar4 = 4;
    if (_dma_chip != 0x139) {
      uVar4 = 0x8e;
    }
    puVar1[1] = uVar4;
    sub_408DBD2(puVar1 + 2,0xff);
    uVar3 = 0;
    if (_dma_chip != 0x139) {
      uVar3 = 0x41;
    }
    sub_408DBD2(puVar1 + 3,uVar3);
    uVar3 = 0;
    if (_dma_chip != 0x139) {
      uVar3 = 0x80;
    }
    sub_408DBD2(puVar1 + 5,uVar3);
    if (_dma_chip == 0x139) {
      puVar1[6] = 0;
    }
    if ((_dma_chip == 0x139) && (puVar1[4] = 2, _dma_chip == 0x139)) {
      puVar1[5] = 1;
    }
    else {
      sub_408DBD2(puVar1 + 5,0xa2);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2361 start=0x408e01a */

undefined4 _en_rx_grabbufs(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  word extraout_D0u;
  uint in_D0;
  int iVar3;
  undefined4 uVar4;
  
  uVar2 = in_D0 >> 0x10;
  while( true ) {
    puVar1 = *(undefined4 **)(param_1 + 0x51e);
    if (puVar1 == (undefined4 *)0x0) {
      return CONCAT22((sword)uVar2,4);
    }
    *(undefined4 *)(param_1 + 0x51e) = *puVar1;
    iVar3 = _if_busalloc(puVar1,0);
    if (iVar3 == 0) break;
    puVar1[2] = puVar1[1] + 0x63d & 0xfffffff0;
    puVar1[3] = 4;
    _dma_enqueue(param_1 + 0x106,puVar1);
    uVar2 = (uint)extraout_D0u;
  }
  *puVar1 = *(undefined4 *)(param_1 + 0x51e);
  *(undefined4 **)(param_1 + 0x51e) = puVar1;
  uVar4 = _timeout(_en_rx_grabbufs,param_1,_hz);
  return uVar4;
}
/* GHIDRADEC_FUNCTION index=2362 start=0x408e0b6 */

undefined4 _en_accept_multicast(int *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
  if (((*(byte *)(*param_1 + 0xc) & 1) == 0) &&
     ((*param_2 != -1 || (*(sword *)(param_2 + 1) != -1)))) {
    iVar2 = 0;
    uVar1 = 0;
    if (0 < *(int *)((int)param_1 + 0x526)) {
      piVar3 = *(int **)((int)param_1 + 0x522);
      do {
        if ((*param_2 == *piVar3) && (*(sword *)(piVar3 + 1) == *(sword *)(param_2 + 1))) {
          return 1;
        }
        piVar3 = (int *)((int)piVar3 + 6);
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)((int)param_1 + 0x526));
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2363 start=0x408e11a */

void _en_rx_devintr(int param_1)

{
  int iVar1;
  byte bVar3;
  int iVar2;
  
  iVar1 = *(int *)((int)&DAT_40c9132 + param_1 * 0x52c);
  iVar2 = iVar1 + 2;
  bVar3 = sub_408DB8A(iVar2);
  sub_408DBD2(iVar2,0xff);
  if ((bVar3 & 0x40) != 0) {
    iVar2 = _if_collisions((&_en_softc)[param_1 * 0x14b]);
    _if_collisions_set((&_en_softc)[param_1 * 0x14b],iVar2 + 1);
  }
  if ((bVar3 & 1) != 0) {
    iVar1 = iVar1 + 5;
    bVar3 = sub_408DB8A(iVar1);
    sub_408DBD2(iVar1,bVar3 | 0x80);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2364 start=0x408e1a0 */
//Error decompiling function: _en_rx_dmaintr @ 0x408e1a0
//Unable to parse XML: 


<doc><function/><function><comment color="comment">
//Decompiler native message:  Low-level Error: <returnsym> tag must include a valid storage address
</comment></function></doc>
/* GHIDRADEC_FUNCTION index=2365 start=0x408e524 */

undefined4 _enoutput(int param_1,int param_2,byte *param_3)

{
  uint uVar1;
  sword sVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  sVar2 = *(sword *)(param_1 + 8);
  iVar3 = sVar2 * 0x52c;
  iVar4 = *(int *)((int)&DAT_40c9132 + iVar3);
  uVar1 = *(uint *)((int)&DAT_40c9132 + iVar3 + 4);
  if (((uVar1 & 1) == 0) || ((uVar1 & 8) != 0)) {
    _nb_free(param_2);
    uVar5 = 0x32;
  }
  else {
    iVar6 = *(int *)(param_2 + 4) + param_2;
    _bcopy(param_3,iVar6,6);
    _bcopy((int)&unk_40C8F38 + iVar3,iVar6 + 6,6);
    if (((*param_3 & 1) != 0) &&
       (((_bmap_chip != 0 && (*(int *)(_bmap_chip + 0x34) < 0)) ||
        ((_dma_chip != 0x139 && ((*(byte *)(iVar4 + 4) & 4) != 0)))))) {
      iVar4 = _en_accept_multicast(&_en_softc + sVar2 * 0x14b,param_3);
      if (iVar4 == 1) {
        iVar4 = _m_copy(param_2,0,1000000000);
        if (iVar4 != 0) {
          _if_handle_input((&_en_softc)[sVar2 * 0x14b],iVar4,0);
        }
      }
    }
    if (*(int *)(param_1 + 0x22) < *(int *)(param_1 + 0x26)) {
      *(undefined4 *)(param_2 + 0x7c) = 0;
      if (*(int *)(param_1 + 0x1e) == 0) {
        *(int *)(param_1 + 0x1a) = param_2;
      }
      else {
        *(int *)(*(int *)(param_1 + 0x1e) + 0x7c) = param_2;
      }
      *(int *)(param_1 + 0x1e) = param_2;
      *(int *)(param_1 + 0x22) = *(int *)(param_1 + 0x22) + 1;
      if (((&byte_40C9139)[iVar3] & 2) == 0) {
        _enstart((int)*(sword *)(param_1 + 8));
      }
      uVar5 = 0;
    }
    else {
      *(int *)(param_1 + 0x2a) = *(int *)(param_1 + 0x2a) + 1;
      _m_freem(param_2);
      uVar5 = 0x37;
    }
  }
  return uVar5;
}
/* GHIDRADEC_FUNCTION index=2366 start=0x408e668 */

undefined4 _enstart(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  byte bVar5;
  undefined2 extraout_D0u;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  
  uVar6 = param_1 * 0x52c;
  iVar1 = *(int *)(DAT_40c8f42 + uVar6 + 0x1f0);
  iVar9 = (&_en_softc)[param_1 * 0x14b];
  uVar7 = uVar6 & 0xffff0000;
  iVar2 = *(int *)(iVar9 + 0x1a);
  bVar11 = false;
  bVar13 = false;
  bVar10 = iVar2 == 0;
  iVar3 = 0;
  if (!bVar10) {
    uVar7 = *(uint *)(iVar2 + 0x7c);
    *(uint *)(iVar9 + 0x1a) = uVar7;
    if (uVar7 == 0) {
      *(undefined4 *)(iVar9 + 0x1e) = 0;
    }
    *(undefined4 *)(iVar2 + 0x7c) = 0;
    iVar3 = *(int *)(iVar9 + 0x22);
    bVar13 = iVar3 == 0;
    bVar11 = SBORROW4(iVar3,1);
    iVar3 = iVar3 + -1;
    *(int *)(iVar9 + 0x22) = iVar3;
    bVar10 = iVar3 == 0;
  }
  uVar8 = CONCAT22((sword)(uVar7 >> 0x10),
                   (word)(byte)(bVar13 << 4 | (iVar3 < 0) << 3 | bVar10 << 2 | bVar11 << 1 | bVar13)
                  );
  if (iVar2 != 0) {
    puVar4 = *(undefined4 **)(DAT_40c944e + uVar6);
    if (puVar4 == (undefined4 *)0x0) {
      _printf(aEntxNoDmaHeade);
      uVar8 = _nb_free(iVar2);
    }
    else {
      *(undefined4 *)(DAT_40c944e + uVar6) = *puVar4;
      iVar9 = _nb_size(iVar2);
      _if_busalloc(puVar4,iVar2);
      if (iVar9 - 0xeU < 0x2e) {
        iVar9 = 0x3c;
      }
      puVar4[2] = iVar9 + puVar4[1];
      if (_dma_chip == 0x139) {
        puVar4[2] = (iVar9 + puVar4[1] | 0x80000000U) + 0xf;
      }
      puVar4[3] = 5;
      _timeout(_en_tx_guard,&_en_softc + param_1 * 0x14b,_hz);
      *(uint *)(DAT_40c8f42 + uVar6 + 500) = *(uint *)(DAT_40c8f42 + uVar6 + 500) | 2;
      _dma_enqueue(DAT_40c8f42 + uVar6,puVar4);
      bVar14 = _dma_chip < 0x139;
      bVar12 = SBORROW2(_dma_chip,0x139);
      bVar11 = (sword)(_dma_chip - 0x139) < 0;
      bVar13 = _dma_chip == 0x139;
      bVar10 = bVar13;
      if (!bVar13) {
        bVar5 = *(byte *)(iVar1 + 4) | 0x80;
        *(byte *)(iVar1 + 4) = bVar5;
        bVar11 = (char)bVar5 < '\0';
        bVar10 = bVar5 == 0;
      }
      uVar8 = CONCAT22(extraout_D0u,
                       (word)(byte)(bVar14 << 4 | bVar11 << 3 | bVar10 << 2 |
                                   (bVar13 && bVar12) << 1));
    }
  }
  return uVar8;
}
/* GHIDRADEC_FUNCTION index=2367 start=0x408e796 */

byte _en_down(int param_1)

{
  int iVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  
  cVar2 = '\0';
  iVar1 = (&_en_softc)[param_1 * 0x14b];
  cVar3 = iVar1 < 0;
  cVar4 = iVar1 == 0;
  cVar5 = '\0';
  bVar6 = 0;
  _if_down(iVar1);
  return cVar2 << 4 | cVar3 << 3 | cVar4 << 2 | cVar5 << 1 | bVar6;
}
/* GHIDRADEC_FUNCTION index=2368 start=0x408e7cc */

byte _en_antijam(int param_1)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  char cVar4;
  bool bVar5;
  char cVar6;
  char cVar7;
  byte bVar8;
  
  cVar3 = '\0';
  uVar2 = *(uint *)(param_1 + 0x202);
  bVar5 = (uVar2 & 8) == 0;
  if (bVar5) {
    bVar8 = ((int)uVar2 < 0) << 3 | bVar5 << 2;
  }
  else {
    *(uint *)(param_1 + 0x202) = uVar2 & 0xfffffff7;
    cVar4 = (int)(uVar2 & 0xfffffff7) < 0;
    cVar7 = '\0';
    bVar8 = 0;
    cVar6 = '\0';
    if ((uVar2 & 2) == 0) {
      uVar2 = (param_1 + -0x40c8f34) * -0x40317f9d;
      cVar3 = (uVar2 >> 1 & 1) != 0;
      iVar1 = (int)uVar2 >> 2;
      cVar4 = iVar1 < 0;
      cVar6 = iVar1 == 0;
      cVar7 = '\0';
      bVar8 = 0;
      _enstart(iVar1);
    }
    bVar8 = cVar3 << 4 | cVar4 << 3 | cVar6 << 2 | cVar7 << 1 | bVar8;
  }
  return bVar8;
}
/* GHIDRADEC_FUNCTION index=2369 start=0x408e824 */

undefined4 _en_jam(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  
  iVar1 = *(int *)(param_1 + 0x1fe);
  *(undefined4 *)(param_1 + 0x206) = 0;
  if (_bmap_chip == 0) {
loc_408EAE2:
    if (_dma_chip != 0x139) {
      *(byte *)(iVar1 + 4) = *(byte *)(iVar1 + 4) | 4;
      _delay(500000);
      if ((*(byte *)(iVar1 + 6) & 0x40) != 0) {
        *(byte *)(iVar1 + 4) = *(byte *)(iVar1 + 4) & 0xfb;
        _delay(500000);
        iVar5 = sub_408DC16(iVar1 + 2);
        if (iVar5 != 0) {
          iVar1 = *(int *)(param_1 + 0x20a);
          *(int *)(param_1 + 0x20a) = iVar1 + 1;
          if (iVar1 + 1 < 4) {
            return 1;
          }
          goto loc_408EBB4;
        }
        *(byte *)(iVar1 + 4) = *(byte *)(iVar1 + 4) | 4;
        _delay(500000);
      }
      iVar1 = *(int *)(param_1 + 0x20a);
      *(int *)(param_1 + 0x20a) = iVar1 + 1;
      if (iVar1 + 1 < 6) goto loc_408E99C;
    }
loc_408EBB4:
    if ((*(byte *)(param_1 + 0x205) & 0x10) == 0) {
      _printf(aTheNetworkIsDi);
      *(uint *)(param_1 + 0x202) = *(uint *)(param_1 + 0x202) | 0x10;
    }
    *(uint *)(param_1 + 0x202) = *(uint *)(param_1 + 0x202) | 8;
    _en_down((param_1 + -0x40c8f34) * -0x40317f9d >> 2);
    _timeout(_en_antijam,param_1,_hz * 10);
    uVar4 = 2;
  }
  else {
    if (*(int *)(_bmap_chip + 0x34) < 0) {
      uVar6 = *_event_middle;
      uVar2 = CONCAT31((uint3)*_eventc_m | (uint3)(((uint)*_eventc_h << 0x10) >> 8),*_eventc_l) &
              0xfffff;
      if (((uVar2 ^ uVar6) & 0x80000) != 0) {
        uVar6 = uVar6 + 0x80000;
      }
      uVar2 = uVar2 | uVar6;
      do {
        uVar6 = *_event_middle;
        uVar3 = CONCAT31((uint3)*_eventc_m | (uint3)(((uint)*_eventc_h << 0x10) >> 8),*_eventc_l) &
                0xfffff;
        if (((uVar3 ^ uVar6) & 0x80000) != 0) {
          uVar6 = uVar6 + 0x80000;
        }
      } while (((uVar3 | uVar6) - uVar2 < 150000) &&
              ((*(uint *)(_bmap_chip + 0x34) & 0x20000000) != 0));
      uVar6 = *_event_middle;
      uVar3 = CONCAT31((uint3)*_eventc_m | (uint3)(((uint)*_eventc_h << 0x10) >> 8),*_eventc_l) &
              0xfffff;
      if (((uVar3 ^ uVar6) & 0x80000) != 0) {
        uVar6 = uVar6 + 0x80000;
      }
      if (149999 < (uVar3 | uVar6) - uVar2) {
        *(uint *)(_bmap_chip + 0x34) = *(uint *)(_bmap_chip + 0x34) & 0x6fffffff;
        *(byte *)(iVar1 + 4) = *(byte *)(iVar1 + 4) | 2;
        return 1;
      }
    }
    else {
      uVar6 = *_event_middle;
      uVar2 = CONCAT31((uint3)*_eventc_m | (uint3)(((uint)*_eventc_h << 0x10) >> 8),*_eventc_l) &
              0xfffff;
      if (((uVar2 ^ uVar6) & 0x80000) != 0) {
        uVar6 = uVar6 + 0x80000;
      }
      uVar2 = uVar2 | uVar6;
      do {
        uVar6 = *_event_middle;
        uVar3 = CONCAT31((uint3)*_eventc_m | (uint3)(((uint)*_eventc_h << 0x10) >> 8),*_eventc_l) &
                0xfffff;
        if (((uVar3 ^ uVar6) & 0x80000) != 0) {
          uVar6 = uVar6 + 0x80000;
        }
      } while (((uVar3 | uVar6) - uVar2 < 150000) &&
              ((*(uint *)(_bmap_chip + 0x34) & 0x20000000) != 0));
      uVar6 = *_event_middle;
      uVar3 = CONCAT31((uint3)*_eventc_m | (uint3)(((uint)*_eventc_h << 0x10) >> 8),*_eventc_l) &
              0xfffff;
      if (((uVar3 ^ uVar6) & 0x80000) != 0) {
        uVar6 = uVar6 + 0x80000;
      }
      if (149999 < (uVar3 | uVar6) - uVar2) goto loc_408EAE2;
      *(uint *)(_bmap_chip + 0x34) = *(uint *)(_bmap_chip + 0x34) | 0x90000000;
      *(byte *)(iVar1 + 4) = *(byte *)(iVar1 + 4) & 0xfd;
    }
loc_408E99C:
    uVar4 = 0;
  }
  return uVar4;
}
/* GHIDRADEC_FUNCTION index=2370 start=0x408ec2e */

void _en_tx_guard(int param_1)

{
  *(uint *)(param_1 + 0x202) = *(uint *)(param_1 + 0x202) | 0x40;
  _callout_dispatch(1,_en_tx_dmaintr,(param_1 + -0x40c8f34) * -0x40317f9d >> 2);
  return;
}
/* GHIDRADEC_FUNCTION index=2371 start=0x408ec90 */

void _en_tx_devintr(int param_1)

{
  byte *pbVar1;
  int iVar2;
  
  pbVar1 = *(byte **)((int)&DAT_40c9132 + param_1 * 0x52c);
  if ((*pbVar1 & 4) != 0) {
    iVar2 = _if_collisions((&_en_softc)[param_1 * 0x14b]);
    _if_collisions_set((&_en_softc)[param_1 * 0x14b],iVar2 + 1);
  }
  if (_dma_chip == 0x139) {
    *pbVar1 = *pbVar1 | 4;
  }
  else {
    *(byte *)(&DAT_40c945e + param_1 * 0x296) = *pbVar1;
    *pbVar1 = 0xff;
    _callout_dispatch(1,_en_tx_dmaintr,param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2372 start=0x408ed0a */

uint _en_tx_dmaintr(int param_1)

{
  byte *pbVar1;
  int iVar2;
  undefined *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int *piVar11;
  char cVar12;
  char cVar13;
  bool bVar14;
  char cVar15;
  bool bVar16;
  bool bVar17;
  char cVar18;
  bool bVar19;
  byte bVar20;
  bool bVar21;
  
  iVar5 = param_1 * 0x52c;
  piVar11 = &_en_softc + param_1 * 0x14b;
  puVar3 = DAT_40c8f42 + iVar5;
  pbVar1 = *(byte **)(DAT_40c8f42 + iVar5 + 0x1f0);
  iVar8 = *piVar11;
  _untimeout(_en_jam,piVar11);
  _untimeout(_en_tx_guard,piVar11);
  if (((&byte_40C9139)[iVar5] & 2) == 0) {
    if (_dma_chip == 0x139) {
      uVar6 = (uint)(char)*pbVar1;
    }
    else {
      uVar6 = (uint)(byte)DAT_40c913a[iVar5 + 0x324];
    }
    uVar6 = _printf(aEnDSpuriousXmi,param_1,uVar6);
    return uVar6;
  }
  if (_dma_chip != 0x139) {
    pbVar1[4] = pbVar1[4] & 0x7f;
  }
  if (((&byte_40C9139)[iVar5] & 0x40) == 0) {
    if (_dma_chip == 0x139) {
      iVar9 = 0;
      if ((char)(*pbVar1 ^ 0x80) < '\0') {
        do {
          iVar9 = iVar9 + 1;
        } while ((word)((sword)-(iVar9 < 100000) & (word)(*pbVar1 ^ 0x80) >> 7) != 0);
      }
      if (iVar9 == 100000) {
        _printf(aEnDTransmitter,param_1);
      }
      bVar20 = *pbVar1;
      *pbVar1 = 0xff;
    }
    else {
      bVar20 = DAT_40c913a[iVar5 + 0x324];
      _dma_abort(puVar3);
    }
    bVar17 = false;
  }
  else {
    *(uint *)(DAT_40c8f42 + iVar5 + 500) = *(uint *)(DAT_40c8f42 + iVar5 + 500) & 0xffffffbf;
    bVar20 = 0;
    _dma_abort(puVar3);
    bVar17 = true;
  }
  puVar7 = (undefined4 *)_dma_dequeue(puVar3,0);
  uVar10 = dword_40AF7F0;
  if (puVar7 == (undefined4 *)0x0) {
loc_408F0CC:
    do {
      iVar8 = _dma_dequeue(puVar3,0);
    } while (iVar8 != 0);
    cVar12 = '\0';
    uVar6 = *(uint *)(DAT_40c8f42 + iVar5 + 500);
    uVar4 = uVar6 & 0xfffffffd;
    *(uint *)(DAT_40c8f42 + iVar5 + 500) = uVar4;
    cVar13 = (int)uVar4 < 0;
    cVar18 = '\0';
    bVar20 = 0;
    cVar15 = '\0';
    if ((uVar6 & 8) == 0) {
      cVar13 = param_1 < 0;
      cVar15 = param_1 == 0;
      cVar18 = '\0';
      bVar20 = 0;
      _enstart(param_1);
    }
    bVar20 = cVar12 << 4 | cVar13 << 3 | cVar15 << 2 | cVar18 << 1 | bVar20;
  }
  else {
    if (bVar17) {
      if ((_dma_chip == 0x139) || (iVar8 = sub_408DC16(pbVar1 + 2), iVar8 != 0)) {
        iVar8 = *(int *)(DAT_40c913a + iVar5);
        *(int *)(DAT_40c913a + iVar5) = *(int *)(DAT_40c913a + iVar5) + 1;
        if (3 < iVar8) goto loc_408F03C;
      }
      else {
        pbVar1[4] = pbVar1[4] | 4;
        _delay(500000);
      }
    }
    else {
      iVar9 = -(int)-(2 < (int)_time - *(int *)(DAT_40c913a + iVar5 + 8));
      if (iVar9 != 0) {
        *(code *)(DAT_40c913a + iVar5 + 8) = _time;
        *(undefined4 *)(DAT_40c913a + iVar5 + 0xc) = uVar10;
        iVar2 = *(int *)(DAT_40c913a + iVar5 + 0x10);
        if (iVar2 == 1) {
          if (_dma_chip == 0x139) {
            pbVar1[5] = 3;
          }
          else {
            sub_408DBD2(pbVar1 + 5,0xa1);
          }
          *(uint *)(DAT_40c8f42 + iVar5 + 500) = *(uint *)(DAT_40c8f42 + iVar5 + 500) | 0x20;
          uVar10 = 2;
        }
        else {
          if (iVar2 != 0) {
            if (iVar2 == 2) {
              if (((&byte_40C9139)[iVar5] & 0x20) != 0) {
                if ((*(word *)(iVar8 + 0xc) & 0x100) == 0) {
                  if (_dma_chip == 0x139) {
                    if ((*(word *)(iVar8 + 0xc) & 0x200) == 0) {
                      pbVar1[5] = 1;
                    }
                    else {
                      pbVar1[5] = 2;
                    }
                  }
                  else {
                    sub_408DBD2(pbVar1 + 5,0xa2);
                  }
                }
                *(uint *)(DAT_40c8f42 + iVar5 + 500) =
                     *(uint *)(DAT_40c8f42 + iVar5 + 500) & 0xffffffdf;
              }
              *(undefined4 *)(DAT_40c913a + iVar5 + 0x10) = 0;
            }
            goto loc_408EF80;
          }
          uVar10 = 1;
        }
        *(undefined4 *)(DAT_40c913a + iVar5 + 0x10) = uVar10;
        iVar9 = 0;
      }
loc_408EF80:
      bVar17 = false;
      if (((_bmap_chip != 0) && (*(int *)(_bmap_chip + 0x34) < 0)) ||
         ((_dma_chip != 0x139 && ((pbVar1[4] & 4) != 0)))) {
        bVar17 = true;
      }
      if ((bVar17) || (((bVar20 & 2) == 0 && (iVar9 == 0)))) {
        if ((_bmap_chip != 0) && ((*(int *)(_bmap_chip + 0x34) < 0 && (iVar9 != 0)))) {
loc_408F03C:
          iVar8 = _en_jam(piVar11);
          goto joined_r0x0408f002;
        }
        if (_dma_chip != 0x139) {
          if (((pbVar1[4] & 4) != 0) && ((pbVar1[6] & 0x40) != 0)) goto loc_408F03C;
          if ((_dma_chip != 0x139) && ((bVar20 & 0xc) != 0)) goto loc_408F106;
        }
        if ((*(uint *)(DAT_40c8f42 + iVar5 + 0x2c) & 0x4000) != 0) {
          _printf(aEnDDmaErrorOnT,param_1);
          *(uint *)(DAT_40c8f42 + iVar5 + 0x2c) = *(uint *)(DAT_40c8f42 + iVar5 + 0x2c) & 0xffffbfff
          ;
          goto loc_408F106;
        }
        iVar8 = _if_opackets(*piVar11);
        _if_opackets_set(*piVar11,iVar8 + 1);
loc_408F0A2:
        *(undefined4 *)(DAT_40c913a + iVar5) = 0;
        *(undefined4 *)(DAT_40c913a + iVar5 + 4) = 0;
        _if_busfree(puVar7);
        *puVar7 = *(undefined4 *)(DAT_40c913a + iVar5 + 0x314);
        *(undefined4 **)(DAT_40c913a + iVar5 + 0x314) = puVar7;
        goto loc_408F0CC;
      }
      iVar8 = _if_oerrors(*piVar11);
      _if_oerrors_set(*piVar11,iVar8 + 1);
      iVar8 = *(int *)(DAT_40c913a + iVar5);
      *(int *)(DAT_40c913a + iVar5) = *(int *)(DAT_40c913a + iVar5) + 1;
      if (((10 < iVar8) && (((&byte_40C9139)[iVar5] & 8) == 0)) || (iVar9 != 0)) {
        if (iVar9 != 0) {
          *(undefined4 *)(DAT_40c913a + iVar5 + 4) = 4;
        }
        iVar8 = _en_jam(piVar11);
joined_r0x0408f002:
        if (iVar8 == 2) goto loc_408F0A2;
      }
    }
loc_408F106:
    _timeout(_en_tx_guard,piVar11,_hz);
    puVar7[3] = 5;
    _dma_enqueue(puVar3,puVar7);
    bVar21 = _dma_chip < 0x139;
    bVar19 = SBORROW2(_dma_chip,0x139);
    bVar14 = (sword)(_dma_chip - 0x139) < 0;
    bVar16 = _dma_chip == 0x139;
    bVar17 = bVar16;
    if (!bVar16) {
      bVar20 = pbVar1[4] | 0x80;
      pbVar1[4] = bVar20;
      bVar14 = (char)bVar20 < '\0';
      bVar17 = bVar20 == 0;
    }
    bVar20 = bVar21 << 4 | bVar14 << 3 | bVar17 << 2 | (bVar16 && bVar19) << 1;
  }
  return (uint)bVar20;
}
/* GHIDRADEC_FUNCTION index=2373 start=0x408f15a */

undefined4 _encontrol(int param_1,undefined4 param_2,int *param_3)

{
  sword sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  
  sVar1 = *(sword *)(param_1 + 8);
  iVar2 = sVar1 * 0x52c;
  iVar3 = _if_unit(param_1);
  iVar3 = *(int *)((&_eninfo)[iVar3] + 0x12);
  uVar6 = 0;
  iVar4 = _strcmp(param_2,_IFCONTROL_SETFLAGS);
  if (iVar4 == 0) {
    if (((*param_3 & 0x10000) != 0) && (((&byte_40C9139)[iVar2] & 1) == 0)) {
      _eninit(param_1);
    }
  }
  else {
    iVar4 = _strcmp(param_2,&_IFCONTROL_GETADDR);
    if (iVar4 == 0) {
      _bcopy((int)&unk_40C8F38 + iVar2,param_3,6);
    }
    else {
      iVar4 = _strcmp(param_2,_IFCONTROL_SETIPADDRESS);
      if (iVar4 == 0) {
        _bcopy(param_3,&dword_40C8F3E + sVar1 * 0x14b,4);
      }
      else {
        iVar4 = _strcmp(param_2,_IFCONTROL_ADDMULTICAST);
        if (iVar4 == 0) {
          iVar4 = *(int *)(DAT_40c9456 + iVar2 + 4);
          if ((iVar4 / 5) * 5 == iVar4) {
            uVar5 = _kalloc((iVar4 * 3 + 0xf) * 2);
            if (*(int *)(DAT_40c9456 + iVar2) == 0) {
              *(undefined4 *)(DAT_40c9456 + iVar2) = uVar5;
              if (((*(byte *)(param_1 + 0xc) & 1) == 0) && (_dma_chip == 0x139)) {
                *(undefined *)(iVar3 + 5) = 2;
              }
              *(word *)(param_1 + 0xc) = *(word *)(param_1 + 0xc) | 0x200;
            }
            else {
              iVar3 = *(int *)(DAT_40c9456 + iVar2 + 4);
              _bytecopy(*(int *)(DAT_40c9456 + iVar2),uVar5,iVar3 * 6);
              _kfree(*(undefined4 *)(DAT_40c9456 + iVar2),iVar3 * 6);
              *(undefined4 *)(DAT_40c9456 + iVar2) = uVar5;
            }
          }
          iVar3 = 0;
          if (0 < *(int *)(DAT_40c9456 + iVar2 + 4)) {
            piVar7 = *(int **)(DAT_40c9456 + iVar2);
            do {
              if ((*param_3 == *piVar7) && (*(sword *)(piVar7 + 1) == *(sword *)(param_3 + 1))) {
                return 0;
              }
              piVar7 = (int *)((int)piVar7 + 6);
              iVar3 = iVar3 + 1;
            } while (iVar3 < *(int *)(DAT_40c9456 + iVar2 + 4));
          }
          _bytecopy(param_3,*(int *)(DAT_40c9456 + iVar2) + iVar3 * 6,6);
          *(int *)(DAT_40c9456 + iVar2 + 4) = *(int *)(DAT_40c9456 + iVar2 + 4) + 1;
        }
        else {
          iVar4 = _strcmp(param_2,_IFCONTROL_RCVPROMISCUOUS);
          if (iVar4 == 0) {
            if (_dma_chip == 0x139) {
              *(undefined *)(iVar3 + 5) = 3;
            }
            else {
              sub_408DBD2(iVar3 + 5,0xa1);
            }
            *(word *)(param_1 + 0xc) = *(word *)(param_1 + 0xc) | 0x100;
          }
          else {
            iVar4 = _strcmp(param_2,_IFCONTROL_RMVMULTICAST);
            if ((iVar4 == 0) && (*(int *)(DAT_40c9456 + iVar2) != 0)) {
              iVar4 = 0;
              if (param_3 == (int *)0x0) {
                _kfree(*(int *)(DAT_40c9456 + iVar2),
                       ((*(int *)(DAT_40c9456 + iVar2 + 4) + 4) / 5) * 0x1e);
                *(undefined4 *)(DAT_40c9456 + iVar2) = 0;
                *(undefined4 *)(DAT_40c9456 + iVar2 + 4) = 0;
              }
              else {
                if (0 < *(int *)(DAT_40c9456 + iVar2 + 4)) {
                  iVar8 = 0;
loc_408F3BA:
                  if ((*param_3 != *(int *)(*(int *)(DAT_40c9456 + iVar2) + iVar8)) ||
                     (*(sword *)(*(int *)(DAT_40c9456 + iVar2) + 4 + iVar8) !=
                      *(sword *)(param_3 + 1))) goto loc_408F40E;
                  iVar9 = iVar4 * 6;
                  iVar8 = iVar9;
                  do {
                    iVar8 = iVar8 + 6;
                    _bytecopy(iVar8 + *(int *)(DAT_40c9456 + iVar2),
                              iVar9 + *(int *)(DAT_40c9456 + iVar2),6);
                    iVar9 = iVar9 + 6;
                    iVar4 = iVar4 + 1;
                  } while (iVar4 < *(int *)(DAT_40c9456 + iVar2 + 4));
                  *(int *)(DAT_40c9456 + iVar2 + 4) = *(int *)(DAT_40c9456 + iVar2 + 4) + -1;
                }
loc_408F418:
                iVar4 = *(int *)(DAT_40c9456 + iVar2 + 4);
                if (iVar4 == 0) {
                  _kfree(*(undefined4 *)(DAT_40c9456 + iVar2),0x1e);
                  *(undefined4 *)(DAT_40c9456 + iVar2) = 0;
                  if (((*(byte *)(param_1 + 0xc) & 1) == 0) && (_dma_chip == 0x139)) {
                    *(undefined *)(iVar3 + 5) = 1;
                  }
                  *(word *)(param_1 + 0xc) = *(word *)(param_1 + 0xc) & 0xfdff;
                }
                else if ((iVar4 / 5) * 5 == iVar4) {
                  iVar4 = iVar4 * 6;
                  uVar5 = _kalloc(iVar4);
                  _bytecopy(*(undefined4 *)(DAT_40c9456 + iVar2),uVar5,iVar4);
                  _kfree(*(undefined4 *)(DAT_40c9456 + iVar2),iVar4 + 0x1e);
                  *(undefined4 *)(DAT_40c9456 + iVar2) = uVar5;
                }
              }
            }
            else {
              iVar2 = _strcmp(param_2,_IFCONTROL_RCVPROMISCOFF);
              if (iVar2 == 0) {
                if (_dma_chip == 0x139) {
                  if ((*(byte *)(param_1 + 0xc) & 2) == 0) {
                    *(undefined *)(iVar3 + 5) = 1;
                  }
                  else {
                    *(undefined *)(iVar3 + 5) = 2;
                  }
                }
                else {
                  sub_408DBD2(iVar3 + 5,0xa2);
                }
                *(word *)(param_1 + 0xc) = *(word *)(param_1 + 0xc) & 0xfeff;
              }
              else {
                uVar6 = 0x16;
              }
            }
          }
        }
      }
    }
  }
  return uVar6;
loc_408F40E:
  iVar8 = iVar8 + 6;
  iVar4 = iVar4 + 1;
  if (*(int *)(DAT_40c9456 + iVar2 + 4) <= iVar4) goto loc_408F418;
  goto loc_408F3BA;
}
/* GHIDRADEC_FUNCTION index=2374 start=0x408f512 */

byte _en_setaddr(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  word *pwVar3;
  bool bVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  byte bVar9;
  
  iVar1 = (&_en_softc)[param_2 * 0x14b];
  cVar5 = '\0';
  _bcopy(param_1,(int)&unk_40C8F38 + param_2 * 0x52c,6);
  uVar2 = *(uint *)(&DAT_40c9136 + param_2 * 0x14b);
  *(uint *)(&DAT_40c9136 + param_2 * 0x14b) = uVar2 | 4;
  bVar4 = (uVar2 & 1) == 0;
  if (bVar4) {
    bVar9 = cVar5 << 4 | ((int)(uVar2 | 4) < 0) << 3 | bVar4 << 2;
  }
  else {
    *(uint *)(&DAT_40c9136 + param_2 * 0x14b) = uVar2 & 0xfffffffe | 4;
    pwVar3 = (word *)(iVar1 + 0xc);
    *pwVar3 = *pwVar3 & 0xffbe;
    iVar1 = (&_en_softc)[param_2 * 0x14b];
    cVar6 = iVar1 < 0;
    cVar7 = iVar1 == 0;
    cVar8 = '\0';
    bVar9 = 0;
    _eninit(iVar1);
    bVar9 = cVar5 << 4 | cVar6 << 3 | cVar7 << 2 | cVar8 << 1 | bVar9;
  }
  return bVar9;
}
/* GHIDRADEC_FUNCTION index=2375 start=0x408f58c */

void _enintsetup(void)

{
  int iVar1;
  
  iVar1 = _slot_id_bmap;
  if (_dma_chip != 0x139) {
    *(undefined *)(_slot_id_bmap + 0x2006004) = 4;
    _delay(500000);
    *(undefined *)(iVar1 + 0x2006001) = 0;
    sub_408DBD2(iVar1 + 0x2006003,0);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2376 start=0x408f5d2 */

void _en_bufalloc(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  uint *puVar6;
  uint *puVar7;
  
  if (dword_40B5598 == 0) {
    if (param_1 == 1) {
      _dbgstack = _enbuf_get();
      piVar4 = &_en_pkt;
      do {
        iVar1 = _enbuf_get();
        *piVar4 = iVar1;
        if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
          _panic(aNoGdbEnetBuffe);
        }
        uVar2 = _pmap_kernel(*piVar4);
        iVar1 = _pmap_resident_extract(uVar2);
        piVar5 = piVar4 + 1;
        *piVar4 = iVar1;
        piVar4 = piVar5;
      } while ((int)piVar5 < 0x40c8f05);
    }
    else {
      _dbgstack = dword_40C2C40;
      dword_40C2C40 =
           _m68k_page_size * ((_m68k_page_size + dword_40C2C40 + 0x3ff) / _m68k_page_size);
      puVar6 = &_en_pkt;
      do {
        uVar3 = dword_40C2C40 + 0xf;
        if ((int)uVar3 < 0) {
          uVar3 = dword_40C2C40 + 0x1e;
        }
        puVar7 = puVar6 + 1;
        *puVar6 = uVar3 & 0xfffffff0;
        dword_40C2C40 = (uVar3 & 0xfffffff0) + 0x62e;
        puVar6 = puVar7;
      } while ((int)puVar7 < 0x40c8f05);
    }
    if (_dbgstack == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(aNoGdbStackBuff);
    }
    __m68k_dbginit();
    dword_40B5598 = 1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2377 start=0x408f6ba */

int _en_recv(uint *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined *puVar2;
  sword sVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  byte bVar9;
  int iVar8;
  undefined2 extraout_D1u;
  undefined2 extraout_D1u_00;
  undefined2 extraout_D1u_01;
  undefined2 extraout_D1u_02;
  undefined2 extraout_D1u_03;
  undefined2 extraout_D1u_04;
  undefined2 uVar10;
  undefined4 in_D1;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint *puVar14;
  
  iVar1 = _slot_id_bmap;
  iVar4 = _slot_id;
  uVar10 = (undefined2)((uint)in_D1 >> 0x10);
  puVar14 = (uint *)(_slot_id + 0x2000150);
  iVar12 = 0;
  if (param_4 != 0) {
    dword_40C8F3E = param_4;
  }
  if (((byte_40C9139 & 1) == 0) && (dword_40B55A4 == 0)) {
    _bcopy(&_etheraddr,&unk_40C8F38,6);
    _bytecopy(&_etheraddr,iVar1 + 0x2006008,6);
    *(undefined *)(iVar1 + 0x2006006) = 0x80;
    if (_dma_chip != 0x139) {
      *(undefined *)(iVar1 + 0x2006006) = 0;
    }
    *(undefined *)(iVar1 + 0x2006001) = 0;
    sub_408DBD2(iVar1 + 0x2006002,0xff);
    sub_408DBD2(iVar1 + 0x2006003,0);
    uVar5 = 0;
    if (_dma_chip != 0x139) {
      uVar5 = 0x80;
    }
    puVar2 = (undefined *)(iVar1 + 0x2006005);
    sub_408DBD2(puVar2,uVar5);
    if (_dma_chip == 0x139) {
      *(undefined *)(iVar1 + 0x2006006) = 0;
    }
    if (_dma_chip == 0x139) {
      *(byte *)(iVar1 + 0x2006004) = *(byte *)(iVar1 + 0x2006004) | 2;
      *puVar2 = 1;
      uVar10 = extraout_D1u;
    }
    else {
      sub_408DBD2(puVar2,0xa2);
      uVar10 = extraout_D1u_00;
    }
    dword_40B55A4 = 1;
  }
  if (dword_40B55A0 == 0) {
    _cache_flush(dword_40C8EFC,dword_40C8EFC + 0x242,0x40000);
    dword_40B55A8 = 0;
    dword_40B55A0 = 1;
    uVar10 = extraout_D1u_01;
  }
  if (_dma_chip != 0x139) {
    iVar13 = iVar1 + 0x2006002;
    iVar6 = sub_408DC16(iVar13);
    uVar10 = extraout_D1u_02;
    if ((iVar6 != 0) && (uVar7 = sub_408DB8A(iVar13), uVar10 = extraout_D1u_03, (uVar7 & 1) != 0)) {
      sub_408DBD2(iVar13,0xff);
      bVar9 = sub_408DB8A(iVar1 + 0x2006005);
      sub_408DBD2(iVar1 + 0x2006005,bVar9 | 0x80);
      uVar10 = extraout_D1u_04;
    }
  }
  if (dword_40B559C != 0) {
    uVar5 = CONCAT22(uVar10,_dma_chip);
    do {
      if (_dma_chip != 0x139) break;
    } while (*puVar14 == 0);
    if ((*puVar14 & 0x1000000) != 0) {
      return 0;
    }
    iVar1 = (&_en_pkt)[dword_40B55A8];
    if (*(sword *)(iVar1 + 0xc) == 0x800) {
      if (*(char *)(iVar1 + 0x17) == '\x11') {
        *param_1 = (uint)*(word *)(iVar1 + 0x22);
        if (_dma_chip == 0x139) {
          uVar7 = *(uint *)(iVar4 + 0x2004150) & 0x3fffffff;
        }
        else {
          uVar7 = (CONCAT31((int3)((uint)uVar5 >> 8),*(undefined *)(_slot_id_bmap + 0x2006007)) |
                  0xfffffff0) + *(int *)(iVar4 + 0x2004150);
        }
        iVar1 = (&_en_pkt)[dword_40B55A8];
        uVar11 = (uVar7 - iVar1) - 4;
        iVar13 = (&_en_pkt)[dword_40B55A8];
        if (_dma_chip == 0) {
          iVar6 = iVar13 + 1;
          iVar8 = _bcmp(iVar6,&unk_40C8F38,6);
          if ((iVar8 == 0) || (iVar8 = _bcmp(iVar6,&_etherbcastaddr,6), iVar8 == 0)) {
            uVar11 = (uVar7 - iVar1) - 5;
            iVar13 = iVar6;
          }
        }
        if ((((uVar11 < 0x5dd) && (param_2 <= (int)uVar11)) && (iVar12 = iVar13, uVar11 != 0)) &&
           (param_3 == 0)) {
          _bcopy(iVar13,&_en_pkt_hdr,0x2a);
        }
      }
    }
    else if (*(sword *)(iVar1 + 0xc) == 0x806) {
      _en_arp_input(iVar1);
    }
  }
  sVar3 = _dma_chip;
  uVar11 = dword_40B55A8 ^ 1;
  uVar7 = 0x940000;
  if (_dma_chip == 0x139) {
    uVar7 = 0x340000;
  }
  dword_40B55A8 = uVar11;
  *puVar14 = uVar7;
  *(undefined4 *)(iVar4 + 0x2004150) = (&_en_pkt)[uVar11];
  *(int *)(iVar4 + 0x2004154) = (&_en_pkt)[uVar11] + 0x5e0;
  if (sVar3 != 0x139) {
    *(undefined4 *)(iVar4 + 0x200411c) = (&_en_pkt)[uVar11];
  }
  *puVar14 = 0x50000;
  _cache_flush((&_en_pkt)[dword_40B55A8 ^ 1],(&_en_pkt)[dword_40B55A8 ^ 1] + 0x242,0x40000);
  dword_40B559C = 1;
  return iVar12;
}
/* GHIDRADEC_FUNCTION index=2378 start=0x408fa10 */

void _en_arp_input(int param_1)

{
  if (((*(sword *)(param_1 + 0x14) == 1) && (*(int *)(param_1 + 0xe) == 0x10800)) &&
     (*(int *)(param_1 + 0x26) == dword_40C8F3E)) {
    _bcopy(param_1 + 0x16,param_1 + 0x20,6);
    _bcopy((int *)(param_1 + 0x1c),param_1 + 0x26,4);
    _bcopy(&unk_40C8F38,param_1 + 0x16,6);
    *(int *)(param_1 + 0x1c) = dword_40C8F3E;
    *(undefined2 *)(param_1 + 0x14) = 2;
    _bcopy(param_1 + 0x20,param_1,6);
    _bcopy(&unk_40C8F38,param_1 + 6,6);
    _en_xmit(param_1,0x2a);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2379 start=0x408faba */

void _en_send(undefined2 param_1,undefined4 *param_2,int param_3)

{
  word wVar1;
  
  *param_2 = _en_pkt_hdr;
  param_2[1] = dword_40C8F0C;
  param_2[2] = dword_40C8F10;
  *(undefined2 *)(param_2 + 3) = word_40C8F14;
  _bcopy(0x40c8f0e,param_2,6);
  _bcopy(&_en_pkt_hdr,(int)param_2 + 6,6);
  *(undefined4 *)((int)param_2 + 0xe) = dword_40C8F16;
  *(undefined4 *)((int)param_2 + 0x12) = dword_40C8F1A;
  *(undefined4 *)((int)param_2 + 0x16) = dword_40C8F1E;
  *(undefined4 *)((int)param_2 + 0x1a) = dword_40C8F22;
  *(undefined4 *)((int)param_2 + 0x1e) = dword_40C8F26;
  *(undefined4 *)((int)param_2 + 0x1a) = dword_40C8F26;
  *(undefined4 *)((int)param_2 + 0x1e) = dword_40C8F22;
  *(sword *)(param_2 + 4) = (sword)param_3 + -0xe;
  *(undefined2 *)(param_2 + 6) = 0;
  wVar1 = _checksum_16((int)param_2 + 0xe,10);
  *(word *)(param_2 + 6) = ~wVar1;
  *(undefined2 *)(param_2 + 9) = param_1;
  *(undefined2 *)((int)param_2 + 0x22) = word_40C8F2C;
  *(sword *)((int)param_2 + 0x26) = (sword)param_3 + -0x22;
  *(undefined2 *)(param_2 + 10) = 0;
  _en_xmit(param_2,param_3 + 0xe);
  return;
}
/* GHIDRADEC_FUNCTION index=2380 start=0x408fb9a */

undefined4 _en_xmit(int param_1,uint param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  sword sVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint *puVar13;
  char *pcVar14;
  
  iVar7 = _slot_id_bmap;
  iVar6 = _slot_id;
  pcVar14 = (char *)(_slot_id_bmap + 0x2006000);
  puVar13 = (uint *)(_slot_id + 0x2000110);
  uVar11 = 0;
  if (param_2 < 0x3c) {
    param_2 = 0x3c;
  }
  do {
    if (_dma_chip == 0x139) {
      cVar1 = *pcVar14;
      while (-1 < cVar1) {
        cVar1 = *pcVar14;
      }
    }
    else {
      *pcVar14 = -1;
    }
    _cache_flush(param_1,param_1 + 0x242,0);
    sVar5 = _dma_chip;
    uVar8 = 0x900000;
    if (_dma_chip == 0x139) {
      uVar8 = 0x300000;
    }
    *puVar13 = uVar8;
    *(int *)(iVar6 + 0x2004110) = param_1;
    if (sVar5 == 0x139) {
      *(int *)(iVar6 + 0x2004100) = param_1;
    }
    else {
      *(int *)(iVar6 + 0x2004118) = param_1;
    }
    sVar5 = _dma_chip;
    iVar12 = param_1 + param_2;
    if (_dma_chip == 0x139) {
      iVar12 = iVar12 + -0x7ffffff1;
    }
    *(int *)(iVar6 + 0x2004114) = iVar12;
    if (sVar5 == 0x139) {
      *(int *)(iVar6 + 0x2004104) = iVar12;
    }
    *puVar13 = 0x10000;
    if (_dma_chip != 0x139) {
      *(byte *)(iVar7 + 0x2006004) = *(byte *)(iVar7 + 0x2006004) | 0x80;
    }
    uVar8 = *_event_middle;
    uVar2 = CONCAT31((uint3)*_eventc_m | (uint3)(((uint)*_eventc_h << 0x10) >> 8),*_eventc_l) &
            0xfffff;
    if (((uVar2 ^ uVar8) & 0x80000) != 0) {
      uVar8 = uVar8 + 0x80000;
    }
    bVar4 = false;
    do {
      if (_dma_chip == 0x139) {
        if ((*puVar13 & 0x8000000) != 0) goto loc_408FD62;
      }
      else if (*pcVar14 < '\0') goto loc_408FD62;
      _delay(1);
      uVar10 = *_event_middle;
      uVar3 = CONCAT31((uint3)*_eventc_m | (uint3)(((uint)*_eventc_h << 0x10) >> 8),*_eventc_l) &
              0xfffff;
      if (((uVar3 ^ uVar10) & 0x80000) != 0) {
        uVar10 = uVar10 + 0x80000;
      }
    } while ((uVar3 | uVar10) - (uVar2 | uVar8) < 0x2711);
    uVar11 = uVar11 + 1;
    _printf(aEnXmitTimeout);
    bVar4 = true;
loc_408FD62:
    if ((!bVar4) || (3 < uVar11)) {
      *puVar13 = 0x100000;
      if (_dma_chip != 0x139) {
        *(byte *)(iVar7 + 0x2006004) = *(byte *)(iVar7 + 0x2006004) & 0x7f;
      }
      uVar9 = 1;
      if (3 < uVar11) {
        uVar9 = 0xffffffff;
      }
      return uVar9;
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2381 start=0x408fd9e */

int _in_bootp_initnet(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iVar1 = _socreate(2,param_3,2,0);
  if (iVar1 == 0) {
    if ((*(word *)(param_1 + 0xc) & 1) == 0) {
      *(word *)(param_2 + 0x10) = *(word *)(param_1 + 0xc) | 1;
      iVar1 = _ifioctl(*param_3,0x80206910,param_2);
      if (iVar1 != 0) {
        return iVar1;
      }
    }
    else if (*(sword *)(param_1 + 0xc) < 0) {
      iVar1 = _ifioctl(*param_3,0xc020690d,param_2);
      if (iVar1 != 0) {
        return iVar1;
      }
      *(word *)(param_1 + 0xc) = *(word *)(param_1 + 0xc) & 0xbfff;
      return -1;
    }
    *(word *)(param_1 + 0xc) = *(word *)(param_1 + 0xc) | 0x4000;
    _bzero(&uStack_14,0x10);
    uStack_14 = CONCAT22(2,uStack_14._2_2_);
    *(undefined4 *)(param_2 + 0x10) = uStack_14;
    *(undefined4 *)(param_2 + 0x14) = uStack_10;
    *(undefined4 *)(param_2 + 0x18) = uStack_c;
    *(undefined4 *)(param_2 + 0x1c) = uStack_8;
    iVar1 = _ifioctl(*param_3,0x8020690c,param_2);
    if (iVar1 == 0) {
      iVar2 = _m_get(1,8);
      if (iVar2 == 0) {
        iVar1 = 0x37;
      }
      else {
        *(undefined2 *)(iVar2 + 8) = 0x10;
        puVar3 = (undefined2 *)(*(int *)(iVar2 + 4) + iVar2);
        *puVar3 = 2;
        puVar3[1] = 0x44;
        *(undefined4 *)(puVar3 + 2) = 0;
        iVar1 = _sobind(*param_3,iVar2);
        _m_freem(iVar2);
        if (iVar1 == 0) {
          *(word *)(*param_3 + 6) = *(word *)(*param_3 + 6) | 0x100;
          iVar1 = 0;
        }
      }
    }
  }
  else {
    *param_3 = 0;
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=2382 start=0x408feee */

undefined * _in_bootp_buildpacket(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)_kalloc(0x148);
  _bzero(puVar1,0x148);
  *puVar1 = 0x45;
  *(sword *)(puVar1 + 4) = _ip_id;
  _ip_id = _ip_id + 1;
  puVar1[8] = 0xff;
  puVar1[9] = 0x11;
  *(undefined4 *)(puVar1 + 0xc) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(puVar1 + 0x10) = 0xffffffff;
  *(undefined2 *)(puVar1 + 0x14) = 0x44;
  *(undefined2 *)(puVar1 + 0x16) = 0x43;
  *(undefined2 *)(puVar1 + 0x1a) = 0;
  puVar1[0x1c] = 1;
  puVar1[0x1d] = 1;
  puVar1[0x1e] = 6;
  *(undefined4 *)(puVar1 + 0x28) = 0;
  _bcopy(param_3,puVar1 + 0x38,6);
  _bcopy(&aNext,puVar1 + 0x108,4);
  puVar1[0x10c] = 1;
  puVar1[0x10e] = 0;
  *(undefined2 *)(puVar1 + 0x18) = 0x134;
  *(undefined2 *)(puVar1 + 2) = 0x148;
  *(undefined2 *)(puVar1 + 10) = 0;
  return puVar1;
}
/* GHIDRADEC_FUNCTION index=2383 start=0x408ffb0 */

int _in_bootp_bptombuf(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iStack_8;
  
  iVar4 = 0x148;
  piVar6 = &iStack_8;
  do {
    piVar2 = _mfree;
    if (_mfree == (int *)0x0) {
      piVar2 = (int *)_m_more(1,1);
    }
    else {
      if (*(sword *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
        _panic(&aMget);
      }
      *(undefined2 *)((int)_mfree + 10) = 1;
      word_40B61CC = word_40B61CC + -1;
      word_40B61CE = word_40B61CE + 1;
      piVar1 = (int *)*_mfree;
      *_mfree = 0;
      _mfree = piVar1;
      piVar2[1] = 0xc;
    }
    if (iVar4 < 0x200) {
loc_40900BA:
      iVar5 = 0x70;
      if (iVar4 < 0x71) {
loc_40900C4:
        iVar5 = iVar4;
      }
    }
    else {
      if (_mclfree == (undefined4 *)0x0) {
        _m_clalloc(1,1,0);
      }
      if (_mclfree == (undefined4 *)0x0) {
        *(undefined2 *)(piVar2 + 2) = 0x70;
      }
      else {
        _mclrefcnt[(int)_mclfree - _mbutl >> 10] = _mclrefcnt[(int)_mclfree - _mbutl >> 10] + '\x01'
        ;
        dword_40B61BC = dword_40B61BC + -1;
        iVar5 = (int)_mclfree - (int)piVar2;
        _mclfree = (undefined4 *)*_mclfree;
        piVar2[1] = iVar5;
        *(undefined2 *)(piVar2 + 2) = 0x400;
        *(undefined2 *)(piVar2 + 3) = 1;
      }
      if (*(sword *)(piVar2 + 2) != 0x400) goto loc_40900BA;
      iVar5 = 0x400;
      if (iVar4 < 0x401) goto loc_40900C4;
    }
    _bcopy(param_1,piVar2[1] + (int)piVar2,iVar5);
    iVar4 = iVar4 - iVar5;
    param_1 = iVar5 + param_1;
    *(sword *)(piVar2 + 2) = (sword)iVar5;
    *piVar6 = (int)piVar2;
    piVar6 = piVar2;
    if (iVar4 < 1) {
      iVar4 = *(int *)(iStack_8 + 4) + iStack_8;
      *(undefined2 *)(iVar4 + 10) = 0;
      uVar3 = _in_cksum(iStack_8,0x14);
      *(undefined2 *)(iVar4 + 10) = uVar3;
      return iStack_8;
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2384 start=0x409011a */

void _in_bootp_timeout(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = 0;
  _sbwakeup(iVar1 + 0x22);
  return;
}
/* GHIDRADEC_FUNCTION index=2385 start=0x4090134 */

void _in_bootp_promisctimeout(undefined4 *param_1)

{
  *param_1 = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=2386 start=0x4090142 */

void _in_bootp_getpacket(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uStack_22;
  undefined4 uStack_1e;
  undefined4 *puStack_1a;
  undefined4 uStack_16;
  undefined4 uStack_12;
  undefined4 uStack_e;
  undefined4 uStack_8;
  
  uStack_22 = param_2;
  uStack_1e = param_3;
  puStack_1a = &uStack_22;
  uStack_16 = 1;
  uStack_e = 1;
  uStack_12 = 0;
  uStack_8 = param_3;
  _soreceive(param_1,0,&puStack_1a,0,0);
  return;
}
/* GHIDRADEC_FUNCTION index=2387 start=0x4090186 */

int _in_bootp_sendrequest
              (undefined4 param_1,int param_2,int param_3,char *param_4,int param_5,int *param_6)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  code *pcVar7;
  int *piVar8;
  int iStack_6c;
  int iStack_68;
  int iStack_64;
  int iStack_58;
  int iStack_54;
  uint auStack_50 [2];
  undefined2 uStack_48;
  undefined2 uStack_46;
  undefined4 uStack_44;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  bVar3 = false;
  bVar2 = false;
  _microtime(auStack_50);
  uVar1 = auStack_50[0] ^ *(byte *)(param_5 + 5);
  *(uint *)(param_3 + 0x20) = uVar1;
  uStack_48 = 2;
  uStack_46 = 0x43;
  uStack_44 = 0xffffffff;
  iStack_64 = 1;
  iStack_68 = 0;
  iStack_6c = 0;
loc_40901F8:
  if (iStack_68 == 0) {
    uVar4 = _in_bootp_bptombuf(param_3);
    iVar5 = _if_output_mbuf(param_1,uVar4,&uStack_48);
    if (iVar5 != 0) {
loc_409057A:
      _untimeout(_in_bootp_promisctimeout,&iStack_58);
      return iVar5;
    }
  }
  uStack_38 = *(undefined4 *)(dword_40B57D4 + 0x28);
  uStack_34 = *(undefined4 *)(dword_40B57D4 + 0x2c);
  uStack_30 = *(undefined4 *)(dword_40B57D4 + 0x30);
  uStack_2c = *(undefined4 *)(dword_40B57D4 + 0x34);
  uStack_28 = *(undefined4 *)(dword_40B57D4 + 0x38);
  uStack_24 = *(undefined4 *)(dword_40B57D4 + 0x3c);
  uStack_20 = *(undefined4 *)(dword_40B57D4 + 0x40);
  uStack_1c = *(undefined4 *)(dword_40B57D4 + 0x44);
  uStack_18 = *(undefined4 *)(dword_40B57D4 + 0x48);
  uStack_14 = *(undefined4 *)(dword_40B57D4 + 0x4c);
  uStack_10 = *(undefined4 *)(dword_40B57D4 + 0x50);
  uStack_c = *(undefined4 *)(dword_40B57D4 + 0x54);
  uStack_8 = *(undefined4 *)(dword_40B57D4 + 0x58);
  iVar6 = _setjmp(dword_40B57D4 + 0x28);
  iVar5 = dword_40B57D4;
  if (iVar6 == 0) {
    iStack_54 = param_2;
    piVar8 = &iStack_54;
    pcVar7 = _in_bootp_timeout;
    iVar5 = _hz;
loc_4090312:
    _timeout(pcVar7,piVar8,iVar5);
loc_409031C:
    do {
      while ((iVar5 = _in_bootp_getpacket(param_2,param_4,300), iVar6 = dword_40B57D4, iVar5 == 0x23
             && (iStack_54 == param_2))) {
        _sbwait(iStack_54 + 0x22);
      }
      if ((iVar5 != 0) && (iVar5 != 0x23)) {
        *(undefined4 *)(dword_40B57D4 + 0x28) = uStack_38;
        *(undefined4 *)(iVar6 + 0x2c) = uStack_34;
        *(undefined4 *)(iVar6 + 0x30) = uStack_30;
        *(undefined4 *)(iVar6 + 0x34) = uStack_2c;
        *(undefined4 *)(iVar6 + 0x38) = uStack_28;
        *(undefined4 *)(iVar6 + 0x3c) = uStack_24;
        *(undefined4 *)(iVar6 + 0x40) = uStack_20;
        *(undefined4 *)(iVar6 + 0x44) = uStack_1c;
        *(undefined4 *)(iVar6 + 0x48) = uStack_18;
        *(undefined4 *)(iVar6 + 0x4c) = uStack_14;
        *(undefined4 *)(iVar6 + 0x50) = uStack_10;
        *(undefined4 *)(iVar6 + 0x54) = uStack_c;
        *(undefined4 *)(iVar6 + 0x58) = uStack_8;
        _untimeout(_in_bootp_timeout,&iStack_54);
        goto loc_409057A;
      }
      if (iStack_54 == 0) {
        *(undefined4 *)(dword_40B57D4 + 0x28) = uStack_38;
        *(undefined4 *)(iVar6 + 0x2c) = uStack_34;
        *(undefined4 *)(iVar6 + 0x30) = uStack_30;
        *(undefined4 *)(iVar6 + 0x34) = uStack_2c;
        *(undefined4 *)(iVar6 + 0x38) = uStack_28;
        *(undefined4 *)(iVar6 + 0x3c) = uStack_24;
        *(undefined4 *)(iVar6 + 0x40) = uStack_20;
        *(undefined4 *)(iVar6 + 0x44) = uStack_1c;
        *(undefined4 *)(iVar6 + 0x48) = uStack_18;
        *(undefined4 *)(iVar6 + 0x4c) = uStack_14;
        *(undefined4 *)(iVar6 + 0x50) = uStack_10;
        *(undefined4 *)(iVar6 + 0x54) = uStack_c;
        *(undefined4 *)(iVar6 + 0x58) = uStack_8;
        iStack_68 = iStack_68 + 1;
        iStack_6c = iStack_6c + 1;
        if (iStack_68 == iStack_64) {
          if (iStack_68 < 0x40) {
            iStack_64 = iStack_68 * 2;
          }
          iStack_68 = 0;
        }
        if (iStack_6c != 0x14) goto loc_40901F8;
        if ((*param_6 == 0) && (iVar5 = _in_bootp_openconsole(param_6), iVar5 != 0))
        goto loc_409057A;
        _printf(aNoResponseFrom);
        bVar3 = true;
        goto loc_40901F8;
      }
    } while (((*(uint *)(param_4 + 4) != uVar1) || (*param_4 != '\x02')) ||
            (iVar6 = _bcmp(param_4 + 0x1c,param_5,6), iVar5 = dword_40B57D4, iVar6 != 0));
    if ((*(char *)(param_3 + 0x10e) == '\0') && (param_4[0xf2] != '\0')) {
      if (!bVar2) goto loc_40904cc;
      if (iStack_58 == 1) goto loc_409031C;
    }
    *(undefined4 *)(dword_40B57D4 + 0x28) = uStack_38;
    *(undefined4 *)(iVar5 + 0x2c) = uStack_34;
    *(undefined4 *)(iVar5 + 0x30) = uStack_30;
    *(undefined4 *)(iVar5 + 0x34) = uStack_2c;
    *(undefined4 *)(iVar5 + 0x38) = uStack_28;
    *(undefined4 *)(iVar5 + 0x3c) = uStack_24;
    *(undefined4 *)(iVar5 + 0x40) = uStack_20;
    *(undefined4 *)(iVar5 + 0x44) = uStack_1c;
    *(undefined4 *)(iVar5 + 0x48) = uStack_18;
    *(undefined4 *)(iVar5 + 0x4c) = uStack_14;
    *(undefined4 *)(iVar5 + 0x50) = uStack_10;
    *(undefined4 *)(iVar5 + 0x54) = uStack_c;
    *(undefined4 *)(iVar5 + 0x58) = uStack_8;
    _untimeout(_in_bootp_timeout,&iStack_54);
    if (bVar3) {
      _printf(aNetworkRespond);
    }
    iVar5 = 0;
    goto loc_409057A;
  }
  *(undefined4 *)(dword_40B57D4 + 0x28) = uStack_38;
  *(undefined4 *)(iVar5 + 0x2c) = uStack_34;
  *(undefined4 *)(iVar5 + 0x30) = uStack_30;
  *(undefined4 *)(iVar5 + 0x34) = uStack_2c;
  *(undefined4 *)(iVar5 + 0x38) = uStack_28;
  *(undefined4 *)(iVar5 + 0x3c) = uStack_24;
  *(undefined4 *)(iVar5 + 0x40) = uStack_20;
  *(undefined4 *)(iVar5 + 0x44) = uStack_1c;
  *(undefined4 *)(iVar5 + 0x48) = uStack_18;
  *(undefined4 *)(iVar5 + 0x4c) = uStack_14;
  *(undefined4 *)(iVar5 + 0x50) = uStack_10;
  *(undefined4 *)(iVar5 + 0x54) = uStack_c;
  *(undefined4 *)(iVar5 + 0x58) = uStack_8;
  _untimeout(_in_bootp_timeout,&iStack_54);
  iVar5 = 4;
  goto loc_409057A;
loc_40904cc:
  bVar2 = true;
  iStack_58 = 1;
  iVar5 = _hz * 10;
  piVar8 = &iStack_58;
  pcVar7 = _in_bootp_promisctimeout;
  goto loc_4090312;
}
/* GHIDRADEC_FUNCTION index=2388 start=0x4090594 */

void _in_bootp_openconsole(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  int iVar14;
  
  uVar1 = *(undefined4 *)(dword_40B57D4 + 0x28);
  uVar2 = *(undefined4 *)(dword_40B57D4 + 0x2c);
  uVar3 = *(undefined4 *)(dword_40B57D4 + 0x30);
  uVar4 = *(undefined4 *)(dword_40B57D4 + 0x34);
  uVar5 = *(undefined4 *)(dword_40B57D4 + 0x38);
  uVar6 = *(undefined4 *)(dword_40B57D4 + 0x3c);
  uVar7 = *(undefined4 *)(dword_40B57D4 + 0x40);
  uVar8 = *(undefined4 *)(dword_40B57D4 + 0x44);
  uVar9 = *(undefined4 *)(dword_40B57D4 + 0x48);
  uVar10 = *(undefined4 *)(dword_40B57D4 + 0x4c);
  uVar11 = *(undefined4 *)(dword_40B57D4 + 0x50);
  uVar12 = *(undefined4 *)(dword_40B57D4 + 0x54);
  uVar13 = *(undefined4 *)(dword_40B57D4 + 0x58);
  _vn_open(aDevConsole,1,0x20000002,0,param_1);
  iVar14 = dword_40B57D4;
  *(undefined4 *)(dword_40B57D4 + 0x28) = uVar1;
  *(undefined4 *)(iVar14 + 0x2c) = uVar2;
  *(undefined4 *)(iVar14 + 0x30) = uVar3;
  *(undefined4 *)(iVar14 + 0x34) = uVar4;
  *(undefined4 *)(iVar14 + 0x38) = uVar5;
  *(undefined4 *)(iVar14 + 0x3c) = uVar6;
  *(undefined4 *)(iVar14 + 0x40) = uVar7;
  *(undefined4 *)(iVar14 + 0x44) = uVar8;
  *(undefined4 *)(iVar14 + 0x48) = uVar9;
  *(undefined4 *)(iVar14 + 0x4c) = uVar10;
  *(undefined4 *)(iVar14 + 0x50) = uVar11;
  *(undefined4 *)(iVar14 + 0x54) = uVar12;
  *(undefined4 *)(iVar14 + 0x58) = uVar13;
  return;
}
/* GHIDRADEC_FUNCTION index=2389 start=0x4090660 */

undefined4 _in_bootp_closeconsole(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  
  (**(code **)(*(int *)(param_1 + 0x1c) + 0xc))(param_1,0x20006b02,0,0x20000000,0);
  puVar1 = _file_list;
  while( true ) {
    if ((undefined4 **)puVar1 == &_file_list) {
      uVar3 = *(undefined4 *)(dword_40B57D4 + 0x28);
      uVar4 = *(undefined4 *)(dword_40B57D4 + 0x2c);
      uVar5 = *(undefined4 *)(dword_40B57D4 + 0x30);
      uVar6 = *(undefined4 *)(dword_40B57D4 + 0x34);
      uVar7 = *(undefined4 *)(dword_40B57D4 + 0x38);
      uVar8 = *(undefined4 *)(dword_40B57D4 + 0x3c);
      uVar9 = *(undefined4 *)(dword_40B57D4 + 0x40);
      uVar10 = *(undefined4 *)(dword_40B57D4 + 0x44);
      uVar11 = *(undefined4 *)(dword_40B57D4 + 0x48);
      uVar12 = *(undefined4 *)(dword_40B57D4 + 0x4c);
      uVar13 = *(undefined4 *)(dword_40B57D4 + 0x50);
      uVar14 = *(undefined4 *)(dword_40B57D4 + 0x54);
      uVar15 = *(undefined4 *)(dword_40B57D4 + 0x58);
      uVar16 = _vn_close(param_1,0);
      iVar2 = dword_40B57D4;
      *(undefined4 *)(dword_40B57D4 + 0x28) = uVar3;
      *(undefined4 *)(iVar2 + 0x2c) = uVar4;
      *(undefined4 *)(iVar2 + 0x30) = uVar5;
      *(undefined4 *)(iVar2 + 0x34) = uVar6;
      *(undefined4 *)(iVar2 + 0x38) = uVar7;
      *(undefined4 *)(iVar2 + 0x3c) = uVar8;
      *(undefined4 *)(iVar2 + 0x40) = uVar9;
      *(undefined4 *)(iVar2 + 0x44) = uVar10;
      *(undefined4 *)(iVar2 + 0x48) = uVar11;
      *(undefined4 *)(iVar2 + 0x4c) = uVar12;
      *(undefined4 *)(iVar2 + 0x50) = uVar13;
      *(undefined4 *)(iVar2 + 0x54) = uVar14;
      *(undefined4 *)(iVar2 + 0x58) = uVar15;
      _vn_rele(param_1);
      return uVar16;
    }
    if ((((*(sword *)(puVar1 + 3) == 1) && (*(sword *)((int)puVar1 + 0xe) != 0)) &&
        (iVar2 = *(int *)((int)puVar1 + 0x16), iVar2 != 0)) &&
       ((*(sword *)(param_1 + 0x2c) == *(sword *)(iVar2 + 0x2c) &&
        (*(int *)(param_1 + 0x28) == *(int *)(iVar2 + 0x28))))) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  _vn_rele(param_1);
  return 0;
}
/* GHIDRADEC_FUNCTION index=2390 start=0x40907a6 */

int _in_bootp_noecho(int param_1)

{
  int iVar1;
  undefined auStack_a [4];
  word wStack_6;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 0x1c) + 0xc))(param_1,0x40067408,auStack_a,0,0);
  if (iVar1 == 0) {
    wStack_6 = wStack_6 & 0xfff7;
    iVar1 = (**(code **)(*(int *)(param_1 + 0x1c) + 0xc))(param_1,0x80067409,auStack_a,0,0);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=2391 start=0x4090806 */

int _in_bootp_echo(int param_1)

{
  int iVar1;
  undefined auStack_a [4];
  word wStack_6;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 0x1c) + 0xc))(param_1,0x40067408,auStack_a,0,0);
  if (iVar1 == 0) {
    wStack_6 = wStack_6 | 8;
    iVar1 = (**(code **)(*(int *)(param_1 + 0x1c) + 0xc))(param_1,0x80067409,auStack_a,0,0);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=2392 start=0x4090866 */

int _in_bootp_processreply(int param_1,int param_2,int param_3)

{
  char cVar1;
  byte bVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  undefined auStack_c [4];
  undefined4 uStack_8;
  
  uStack_8 = 1;
  bVar3 = false;
  uVar4 = _strlen(param_3 + 0xf4);
  if (0x37 < uVar4) {
    *(undefined *)(param_3 + 299) = 0;
  }
  _printf(&aS_3,param_3 + 0xf4);
  iVar5 = (**(code **)(*(int *)(param_1 + 0x1c) + 0xc))(param_1,0x80047410,&uStack_8,0,0);
  if (iVar5 != 0) goto loc_409099A;
  bVar2 = *(byte *)(param_3 + 0xf2);
  if (bVar2 == 2) {
    iVar5 = _in_bootp_noecho(param_1);
    if (iVar5 != 0) goto loc_409099A;
    bVar3 = true;
  }
  else {
    if (2 < bVar2) {
      if (bVar2 == 3) {
        *(undefined4 *)(param_2 + 0x10) = 0xffffffff;
        *(undefined *)(param_2 + 0x10e) = 0;
        *(undefined *)(param_2 + 0x10f) = 0;
      }
      goto loc_409099A;
    }
    if (bVar2 != 1) goto loc_409099A;
  }
  pcVar6 = (char *)(param_2 + 0x110);
  iVar5 = _vn_rdwr(0,param_1,pcVar6,0x37,0,1,0,auStack_c);
  if (iVar5 == 0) {
    if (bVar3) {
      _printf(&asc_40A6049);
    }
    cVar1 = *pcVar6;
    while (cVar1 != '\0') {
      if ((*pcVar6 == '\n') || (*pcVar6 == '\r')) {
        *pcVar6 = '\0';
        break;
      }
      pcVar6 = pcVar6 + 1;
      cVar1 = *pcVar6;
    }
    *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_3 + 0x14);
    *(undefined *)(param_2 + 0x10e) = *(undefined *)(param_3 + 0xf2);
    *(undefined *)(param_2 + 0x10f) = *(undefined *)(param_3 + 0xf3);
  }
loc_409099A:
  if (bVar3) {
    _in_bootp_echo(param_1);
  }
  return iVar5;
}
/* GHIDRADEC_FUNCTION index=2393 start=0x40909b2 */

int _in_bootp_setaddress(int param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  
  *(word *)(param_2 + 0x10) = *(word *)(param_1 + 0xc) & 0xfffe;
  iVar1 = _ifioctl(param_3,0x80206910,param_2);
  if (iVar1 == 0) {
    *(word *)(param_1 + 0xc) = *(word *)(param_1 + 0xc) & 0xbfff;
    _bzero((undefined2 *)(param_2 + 0x10),0x10);
    *(undefined2 *)(param_2 + 0x10) = 2;
    iVar1 = _ifioctl(param_3,0x80206916,param_2);
    if (iVar1 == 0) {
      *(undefined4 *)(param_2 + 0x14) = *param_4;
      iVar1 = _ifioctl(param_3,0x8020690c,param_2);
      if (iVar1 == 0) {
        *(word *)(param_1 + 0xc) = *(word *)(param_1 + 0xc) | 0x8000;
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=2394 start=0x4090ac6 */

int _in_bootp(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iStack_2c;
  int iStack_28;
  undefined auStack_24 [16];
  word awStack_14 [8];
  
  iVar2 = 0;
  iVar3 = 0;
  iStack_2c = 0;
  sub_4090A50(param_1,param_2);
  iVar1 = _in_bootp_initnet(param_1,auStack_24,&iStack_28);
  if (iVar1 == 0) {
    iVar2 = _in_bootp_buildpacket(param_1,param_2,param_3);
    iVar3 = _kalloc(300);
    while (iVar1 = _in_bootp_sendrequest(param_1,iStack_28,iVar2,iVar3,param_3,&iStack_2c),
          iVar1 == 0) {
      if (*(char *)(iVar3 + 0xf2) == '\0') {
        if (iStack_2c != 0) {
          _in_bootp_closeconsole(iStack_2c);
          iStack_2c = 0;
        }
        iVar1 = _in_bootp_setaddress(param_1,auStack_24,iStack_28,iVar3 + 0x10);
        if (iVar1 == 0) {
          _bcopy(awStack_14,param_2,0x10);
          goto loc_4090C04;
        }
        break;
      }
      if (((iStack_2c == 0) && (iVar1 = _in_bootp_openconsole(&iStack_2c), iVar1 != 0)) ||
         (iVar1 = _in_bootp_processreply(iStack_2c,iVar2,iVar3), iVar1 != 0)) break;
    }
  }
  else {
    if (iVar1 == -1) {
      iVar2 = _ifioctl(iStack_28,0x8020690c,auStack_24);
      if (iVar2 == 0) {
        _bcopy(awStack_14,param_2,0x10);
      }
      _soclose(iStack_28);
      return iVar2;
    }
loc_4090C04:
    if (iVar1 == 0) goto loc_4090C30;
  }
  if (iStack_28 != 0) {
    awStack_14[0] = *(word *)(param_1 + 0xc) & 0xfffe;
    _ifioctl(iStack_28,0x80206910,auStack_24);
  }
loc_4090C30:
  *(word *)(param_1 + 0xc) = *(word *)(param_1 + 0xc) & 0xbfff;
  if (iStack_28 != 0) {
    _soclose(iStack_28);
  }
  if (iVar2 != 0) {
    _kfree(iVar2,0x148);
  }
  if (iVar3 != 0) {
    _kfree(iVar3,300);
  }
  if (iStack_2c != 0) {
    _in_bootp_closeconsole(iStack_2c);
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=2395 start=0x4090c8a */

undefined4 _PMConnect(void)

{
  return 0;
}
/* GHIDRADEC_FUNCTION index=2396 start=0x4090c94 */

undefined4 _PMDisconnect(void)

{
  return 0;
}
/* GHIDRADEC_FUNCTION index=2397 start=0x4090c9e */

undefined4 _PMSetCpuState(void)

{
  return 0;
}
/* GHIDRADEC_FUNCTION index=2398 start=0x4090ca8 */

undefined4 _PMSetPowerState(void)

{
  return 0x3e80060;
}
/* GHIDRADEC_FUNCTION index=2399 start=0x4090cb6 */

undefined4 _PMGetPowerEvent(void)

{
  return 0x3e80080;
}

