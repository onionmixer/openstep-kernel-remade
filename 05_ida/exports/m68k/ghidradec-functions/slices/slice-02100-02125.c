/* GHIDRADEC_FUNCTION index=2100 start=0x4071da0 */

void _km_begin_access(void)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = dword_40B1BBE + 1;
  bVar2 = dword_40B1BBE == 0;
  dword_40B1BBE = iVar1;
  if ((bVar2) && (dword_40B6968 != 0)) {
    _km_run_pcode(dword_40B6968);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2101 start=0x4071dcc */

int _km_end_access(void)

{
  int iVar1;
  int iVar2;
  
  if (dword_40B1BBE != 0) {
    iVar1 = dword_40B1BBE + -1;
    iVar2 = dword_40B1BBE + -1;
    dword_40B1BBE = iVar1;
    if (0 < iVar2) {
      return iVar2;
    }
  }
  if (dword_40B696C != 0) {
    _km_run_pcode(dword_40B696C);
  }
  if ((byte_40B6953 & 2) != 0) {
    pushInvalidateCaches(1);
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=2102 start=0x4071e0e */

int _km_convert_addr(uint param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 0;
  while (((*(int *)((int)&unk_40B6978 + iVar2) == 0 ||
          (uVar1 = *(uint *)((int)&unk_40B6970 + iVar2), param_1 < uVar1)) ||
         (uVar1 + *(int *)((int)&unk_40B6978 + iVar2) <= param_1))) {
    iVar2 = iVar2 + 0xc;
    iVar3 = iVar3 + 1;
    if (5 < iVar3) {
      _log(3,aKmConvertAddr0,param_1,(int)byte_40B6964);
                    /* WARNING: Subroutine does not return */
      _panic(aKmConvertAddrH);
    }
  }
  return *(int *)((int)&dword_40B6974 + iVar2) + (param_1 - uVar1);
}
/* GHIDRADEC_FUNCTION index=2103 start=0x4071e80 */

undefined4 _km_run_pcode(uint param_1)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint unaff_D5;
  int iVar4;
  int iVar5;
  int unaff_A3;
  int unaff_A4;
  int unaff_A5;
  uint auStack_24 [8];
  
  if (param_1 == 0) {
    return 0;
  }
  iVar4 = (int)byte_40B6964;
loc_4071E9C:
  uVar1 = sub_4071A12(param_1);
  uVar3 = param_1 + 1;
  if ((int)uVar1 < 0) {
    unaff_D5 = sub_4071A12(param_1 + 1);
    uVar3 = param_1 + 2;
  }
  param_1 = uVar3;
  switch(uVar1 >> 0x1a) {
  case :
    goto loc_407225A;
  case :
    uVar3 = auStack_24[(uVar1 & 0xffffff) >> 0x15];
    if ((uVar3 & 0xff000000) == 0xf0000000) {
      iVar5 = 0x18;
    }
    else {
      iVar5 = 0x1c;
    }
    goto loc_4071FC8;
  case :
    uVar3 = auStack_24[(uVar1 & 0x7ffff) >> 0x10];
    if ((uVar3 & 0xff000000) == 0xf0000000) {
      iVar5 = 0x18;
    }
    else {
      iVar5 = 0x1c;
    }
    goto loc_4072028;
  case :
    uVar1 = uVar1 & 0x3ffffff;
    do {
      iVar5 = param_1 + 1;
      unaff_D5 = sub_4071A12(param_1);
      param_1 = param_1 + 2;
      uVar3 = sub_4071A12(iVar5);
      if ((uVar3 & 0xff000000) == 0xf0000000) {
        iVar5 = 0x18;
      }
      else {
        iVar5 = 0x1c;
      }
      puVar2 = (uint *)_km_convert_addr(uVar3 | iVar4 << iVar5);
      *puVar2 = unaff_D5;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
    goto loc_4071E9C;
  case :
    auStack_24[(uVar1 & 0x3fff) >> 0xb] =
         auStack_24[(uVar1 & 0x7ffff) >> 0x10] + auStack_24[(uVar1 & 0xffffff) >> 0x15];
    goto loc_4071E9C;
  case :
    auStack_24[(uVar1 & 0x3fff) >> 0xb] =
         auStack_24[(uVar1 & 0xffffff) >> 0x15] - auStack_24[(uVar1 & 0x7ffff) >> 0x10];
    goto loc_4071E9C;
  case :
    unaff_A4 = 0;
    unaff_A3 = 0;
    unaff_A5 = 0;
    unaff_D5 = auStack_24[(uVar1 & 0xffffff) >> 0x15];
    if (unaff_D5 == 0) {
      unaff_A4 = 1;
    }
    else if ((int)unaff_D5 < 1) {
      unaff_A5 = 1;
    }
    else {
      unaff_A3 = 1;
    }
    goto loc_4071E9C;
  case :
    auStack_24[(uVar1 & 0x3fff) >> 0xb] =
         auStack_24[(uVar1 & 0x7ffff) >> 0x10] & auStack_24[(uVar1 & 0xffffff) >> 0x15];
    goto loc_4071E9C;
  case :
    auStack_24[(uVar1 & 0x3fff) >> 0xb] =
         auStack_24[(uVar1 & 0x7ffff) >> 0x10] | auStack_24[(uVar1 & 0xffffff) >> 0x15];
    goto loc_4071E9C;
  case :
    auStack_24[(uVar1 & 0x3fff) >> 0xb] =
         auStack_24[(uVar1 & 0x7ffff) >> 0x10] ^ auStack_24[(uVar1 & 0xffffff) >> 0x15];
    goto loc_4071E9C;
  case :
    auStack_24[(uVar1 & 0x3fff) >> 0xb] =
         auStack_24[(uVar1 & 0xffffff) >> 0x15] << ((uVar1 & 0x1fffff) >> 0x10);
    goto loc_4071E9C;
  case :
    auStack_24[(uVar1 & 0x3fff) >> 0xb] =
         (int)auStack_24[(uVar1 & 0xffffff) >> 0x15] >> ((uVar1 & 0x1fffff) >> 0x10);
    goto loc_4071E9C;
  case :
    auStack_24[(uVar1 & 0x7ffff) >> 0x10] = auStack_24[(uVar1 & 0xffffff) >> 0x15];
    goto loc_4071E9C;
  case :
    goto loc_407224A;
  case :
    iVar5 = unaff_A3;
    break;
  case :
    iVar5 = unaff_A5;
    break;
  case :
    iVar5 = unaff_A4;
    break;
  case :
    iVar5 = unaff_A3;
    goto joined_r0x04072246;
  case :
    iVar5 = unaff_A5;
    goto joined_r0x04072246;
  case :
    iVar5 = unaff_A4;
joined_r0x04072246:
    if (iVar5 == 0) goto loc_407224A;
  :
    goto loc_4071E9C;
  case :
    auStack_24[(uVar1 & 0x7ffff) >> 0x10] = unaff_D5;
    goto loc_4071E9C;
  case :
    uVar3 = unaff_D5;
    if ((unaff_D5 & 0xff000000) == 0xf0000000) {
      iVar5 = 0x18;
    }
    else {
      iVar5 = 0x1c;
    }
loc_4071FC8:
    puVar2 = (uint *)_km_convert_addr(iVar4 << iVar5 | uVar3);
    auStack_24[(uVar1 & 0x7ffff) >> 0x10] = *puVar2;
    goto loc_4071E9C;
  case :
    uVar3 = unaff_D5;
    if ((unaff_D5 & 0xff000000) == 0xf0000000) {
      iVar5 = 0x18;
    }
    else {
      iVar5 = 0x1c;
    }
loc_4072028:
    puVar2 = (uint *)_km_convert_addr(iVar4 << iVar5 | uVar3);
    *puVar2 = auStack_24[(uVar1 & 0xffffff) >> 0x15];
    goto loc_4071E9C;
  case :
    auStack_24[(uVar1 & 0x7ffff) >> 0x10] = auStack_24[(uVar1 & 0xffffff) >> 0x15] + unaff_D5;
    goto loc_4071E9C;
  case :
    auStack_24[(uVar1 & 0x7ffff) >> 0x10] = auStack_24[(uVar1 & 0xffffff) >> 0x15] - unaff_D5;
    goto loc_4071E9C;
  case :
    auStack_24[(uVar1 & 0x7ffff) >> 0x10] = unaff_D5 - auStack_24[(uVar1 & 0xffffff) >> 0x15];
    goto loc_4071E9C;
  case :
    auStack_24[(uVar1 & 0x7ffff) >> 0x10] = auStack_24[(uVar1 & 0xffffff) >> 0x15] & unaff_D5;
    goto loc_4071E9C;
  case :
    auStack_24[(uVar1 & 0x7ffff) >> 0x10] = auStack_24[(uVar1 & 0xffffff) >> 0x15] | unaff_D5;
    goto loc_4071E9C;
  case :
    auStack_24[(uVar1 & 0x7ffff) >> 0x10] = unaff_D5 ^ auStack_24[(uVar1 & 0xffffff) >> 0x15];
    goto loc_4071E9C;
  }
  if (iVar5 != 0) {
loc_407224A:
    param_1 = uVar1 & 0x3ffffff;
  }
  goto loc_4071E9C;
loc_407225A:
  return auStack_24[0];
}
/* GHIDRADEC_FUNCTION index=2104 start=0x4072264 */

undefined4 _mmopen(byte param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 4) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x16;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2105 start=0x4072282 */

void _mmread(sword param_1,undefined4 param_2)

{
  _mmrw((int)param_1,param_2,0);
  return;
}
/* GHIDRADEC_FUNCTION index=2106 start=0x407229c */

void _mmwrite(sword param_1,undefined4 param_2)

{
  _mmrw((int)param_1,param_2,1);
  return;
}
/* GHIDRADEC_FUNCTION index=2107 start=0x40722b8 */

int _mmrw(byte param_1,int *param_2,int param_3)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint unaff_D2;
  int iVar5;
  
  iVar5 = 0;
  if (*(int *)((int)param_2 + 0x12) < 1) {
    return 0;
  }
  do {
    piVar1 = (int *)*param_2;
    uVar3 = piVar1[1];
    if (uVar3 == 0) {
      *param_2 = (int)(piVar1 + 2);
      iVar4 = param_2[1];
      param_2[1] = iVar4 + -1;
      uVar3 = unaff_D2;
      if (iVar4 + -1 < 0) {
                    /* WARNING: Subroutine does not return */
        _panic(&aMmrw);
      }
    }
    else if (param_1 == 1) {
      iVar5 = param_2[2];
loc_40723C2:
      iVar5 = _uiomove(iVar5,uVar3,param_3,param_2);
    }
    else {
      if (param_1 < 2) {
        if (param_1 == 0) {
          uVar2 = ~_page_mask & param_2[2];
          iVar5 = param_2[2] - uVar2;
          uVar3 = _min(_page_size - iVar5,uVar3);
          if (iVar5 < 0) {
            return 0xe;
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
          if (iVar4 < iVar5) {
            return 0xe;
          }
          iVar5 = iVar5 + uVar2;
          goto loc_40723C2;
        }
      }
      else if (param_1 == 2) {
        unaff_D2 = uVar3;
        if (param_3 == 0) {
          return 0;
        }
      }
      else if (param_1 == 3) {
        unaff_D2 = 8;
        if (8 < uVar3) {
          unaff_D2 = uVar3;
        }
        uVar3 = param_2[2];
        param_2[2] = uVar3 & 7;
        iVar5 = _slot_id_bmap + (uVar3 & 7) + 0x2008000;
        param_2[2] = iVar5;
        iVar5 = _uiomove(iVar5,unaff_D2,param_3,param_2);
      }
      if (iVar5 != 0) {
        return iVar5;
      }
      *piVar1 = unaff_D2 + *piVar1;
      piVar1[1] = piVar1[1] - unaff_D2;
      param_2[2] = unaff_D2 + param_2[2];
      *(int *)((int)param_2 + 0x12) = *(int *)((int)param_2 + 0x12) - unaff_D2;
      uVar3 = unaff_D2;
    }
    if (*(int *)((int)param_2 + 0x12) < 1) {
      return iVar5;
    }
    unaff_D2 = uVar3;
    if (iVar5 != 0) {
      return iVar5;
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2108 start=0x4072440 */

uint _mmmmap(char param_1,uint param_2)

{
  if (param_1 == '\x03') {
    if (param_2 != 0) {
      return 0xffffffff;
    }
    param_2 = _slot_id_bmap + 0x2008000;
  }
  else if (param_1 != '\0') {
    return 0xffffffff;
  }
  return param_2 >> (_page_shift & 0x3f);
}
/* GHIDRADEC_FUNCTION index=2109 start=0x407247e */

void _mon_reset(void)

{
  if (dword_40B1BCA == 0) {
    uRam0200e000 = 0x200;
    dword_40B1BCA = 1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2110 start=0x40724a4 */

void _mon_send(void)

{
  func_0x040724b6();
  return;
}
/* GHIDRADEC_FUNCTION index=2111 start=0x40724ac */

/* WARNING: Switch with 1 destination removed at 0x04072532 */

void _lpr_send(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_D0;
  sword sVar1;
  sword sVar2;
  undefined4 uVar3;
  undefined *puVar4;
  int unaff_A2;
  char in_XF;
  undefined auStack_14 [8];
  
  puVar4 = auStack_14;
  uVar3 = CONCAT22((sword)((uint)in_D0 >> 0x10),
                   (word)(byte)(in_XF << 4 | (unaff_A2 < 0) << 3 | (unaff_A2 == 0) << 2));
  do {
    *(undefined4 *)(puVar4 + 4) = uVar3;
    puVar4 = (undefined *)0x200f000;
    sVar1 = 100;
    do {
      if (((bRam0200f002 & 0x20) == 0) || ((bRam0200f002 & 0x10) == 0)) break;
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
    uVar3 = param_2;
    if ((_dma_chip == 0x139) && ((bRam0200f000 & 0x80) != 0)) {
      sVar1 = 1;
      do {
        sVar2 = 100;
        do {
          if ((bRam0200f002 & 0x40) != 0) break;
          sVar2 = sVar2 + -1;
        } while (sVar2 != -1);
        do {
        } while ((bRam0200f002 & 0x40) != 0);
        sVar1 = sVar1 + -1;
      } while (sVar1 != -1);
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2112 start=0x407254a */

void _mon_csr_and(void)

{
  func_0x0407255c();
  return;
}
/* GHIDRADEC_FUNCTION index=2113 start=0x4072552 */

void _lpr_csr_and(byte param_1)

{
  sword sVar1;
  
  if ((_dma_chip == 0x139) && ((bRam0200f000 & 0x80) != 0)) {
    sVar1 = 100;
    do {
      if ((bRam0200f002 & 0x40) != 0) break;
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
    do {
    } while ((bRam0200f002 & 0x40) != 0);
  }
  bRam0200f000 = param_1 & bRam0200f000;
  return;
}
/* GHIDRADEC_FUNCTION index=2114 start=0x4072596 */

void _mon_csr_or(void)

{
  func_0x040725a8();
  return;
}
/* GHIDRADEC_FUNCTION index=2115 start=0x407259e */

void _lpr_csr_or(byte param_1)

{
  sword sVar1;
  
  if ((_dma_chip == 0x139) && ((bRam0200f000 & 0x80) != 0)) {
    sVar1 = 100;
    do {
      if ((bRam0200f002 & 0x40) != 0) break;
      sVar1 = sVar1 + -1;
    } while (sVar1 != -1);
    do {
    } while ((bRam0200f002 & 0x40) != 0);
  }
  bRam0200f000 = param_1 | bRam0200f000;
  return;
}
/* GHIDRADEC_FUNCTION index=2116 start=0x40725e2 */

undefined4 _nbic_bus_enable(void)

{
  undefined4 uVar1;
  uint *puVar2;
  uint *puVar3;
  
  puVar3 = (uint *)(_slot_id + 0x200d000);
  puVar2 = (uint *)(_slot_id + 0x2200010);
  if (_machine_type == 2) {
loc_407261C:
    if (_dma_chip == 0x139) {
      *puVar3 = *puVar3 | 0x80;
    }
    else {
      *puVar3 = *puVar3 & 0xffffff7f;
      *puVar2 = *puVar2 & 0xfffffcff;
      *(undefined *)(_slot_id + 0x2012000) = 0x88;
    }
    if (_bmap_chip != 0) {
      *(byte *)(_bmap_chip + 4) = *(byte *)(_bmap_chip + 4) & 0xbf;
    }
    uVar1 = 1;
  }
  else {
    if (_machine_type < 3) {
      if (_machine_type == 0) goto loc_407261C;
    }
    else if ((_machine_type < 10) && (7 < _machine_type)) goto loc_407261C;
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=2117 start=0x4072672 */

void _nbic_configure(void)

{
  int iVar1;
  
  iVar1 = _nbic_bus_enable();
  if (iVar1 != 0) {
    iVar1 = _probe_rl(0xf0fffff0);
    if (iVar1 != 0) {
      _nbic_present = 1;
      _printf(aNbicPresent);
      if ((_machine_type == '\0') || (_machine_type == '\x02')) {
        uRam02020004 = 0x80000000;
        uRam02020000 = 0x8000000;
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2118 start=0x40726d0 */

void _np_send(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  _lpr_send(param_2,param_3);
  return;
}
/* GHIDRADEC_FUNCTION index=2119 start=0x40726e6 */

undefined8 _np_recv(uint *param_1,undefined4 *param_2,uint *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int unaff_A2;
  char in_XF;
  
  do {
  } while ((*param_1 & 0x800) != 0);
  if (((*param_1 & 0x40000) == 0) && ((*param_1 & 0x20000) == 0)) {
    uVar2 = 0;
  }
  else {
    if ((*param_1 & 0x20000) != 0) {
      *(byte *)((int)param_1 + 1) = *(byte *)((int)param_1 + 1) | 2;
    }
    uVar1 = *param_1;
    *param_2 = 0;
    *(char *)((int)param_2 + 3) = (char)uVar1;
    *param_3 = param_1[1];
    uVar2 = 1;
  }
  return CONCAT44(uVar2,(int)(sword)(word)(byte)(in_XF << 4 | (unaff_A2 < 0) << 3 |
                                                (unaff_A2 == 0) << 2));
}
/* GHIDRADEC_FUNCTION index=2120 start=0x4072752 */

void _np_nap(undefined4 param_1)

{
  undefined4 uStack_8;
  
  uStack_8 = 0;
  _timeout(_thread_wakeup,&uStack_8,param_1);
  _assert_wait(&uStack_8,0);
  _thread_block();
  return;
}
/* GHIDRADEC_FUNCTION index=2121 start=0x407278a */

void _np_gpiwait_timeout(undefined4 *param_1)

{
  _np_send(*param_1,4,0);
  return;
}
/* GHIDRADEC_FUNCTION index=2122 start=0x40727a4 */

void _np_gpinwait(int param_1,int param_2)

{
  if (param_2 != 0) {
    _timeout(_np_gpiwait_timeout,param_1,param_2);
  }
  _assert_wait(param_1 + 0x11b,0);
  _thread_block();
  _untimeout(_np_gpiwait_timeout,param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=2123 start=0x40727f0 */

byte _np_setmask(int *param_1,byte param_2)

{
  int iVar1;
  uint in_D0;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  
  *(byte *)(param_1 + 0x47) = param_2 | *(byte *)(param_1 + 0x47);
  cVar2 = (in_D0 >> 8 & 1) != 0;
  iVar1 = *param_1;
  cVar3 = iVar1 < 0;
  cVar4 = iVar1 == 0;
  cVar5 = '\0';
  bVar6 = 0;
  _np_send(iVar1,0xc5,(*(byte *)(param_1 + 0x47) & 0x3f) << 0x18);
  return cVar2 << 4 | cVar3 << 3 | cVar4 << 2 | cVar5 << 1 | bVar6;
}
/* GHIDRADEC_FUNCTION index=2124 start=0x407283e */

byte _np_clearmask(int *param_1,byte param_2)

{
  int iVar1;
  uint in_D0;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  
  *(byte *)(param_1 + 0x47) = ~param_2 & *(byte *)(param_1 + 0x47);
  cVar2 = (in_D0 >> 8 & 1) != 0;
  iVar1 = *param_1;
  cVar3 = iVar1 < 0;
  cVar4 = iVar1 == 0;
  cVar5 = '\0';
  bVar6 = 0;
  _np_send(iVar1,0xc5,(*(byte *)(param_1 + 0x47) & 0x3f) << 0x18);
  return cVar2 << 4 | cVar3 << 3 | cVar4 << 2 | cVar5 << 1 | bVar6;
}

