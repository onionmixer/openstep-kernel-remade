/* GHIDRADEC_FUNCTION index=3175 start=0x408d9aa */

byte sub_408D9AA(undefined4 *param_1)

{
  char in_XF;
  char in_NF;
  char in_ZF;
  char in_VF;
  byte in_CF;
  
  *param_1 = dword_40B244A;
  dword_40B244A = param_1;
  dword_40B2452 = dword_40B2452 + 1;
  return in_XF << 4 | in_NF << 3 | in_ZF << 2 | in_VF << 1 | in_CF;
}
/* GHIDRADEC_FUNCTION index=3176 start=0x408d9d4 */

undefined4 sub_408D9D4(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar2 = _m_clalloc(1,2,0);
  if (iVar2 == 0) {
    uVar3 = 1;
  }
  else {
    uVar1 = _page_size + iVar2;
    uVar4 = iVar2 + 0xf;
    if ((int)uVar4 < 0) {
      uVar4 = iVar2 + 0x1e;
    }
    while (uVar5 = uVar4 & 0xfffffff0, uVar5 + 0x62e <= uVar1) {
      sub_408D9AA(uVar5);
      dword_40B244E = dword_40B244E + 1;
      uVar4 = uVar5 + 0x63d;
      if ((int)uVar4 < 0) {
        uVar4 = uVar5 + 0x64c;
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=3177 start=0x408db8a */

undefined sub_408DB8A(undefined4 param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined uStack_5;
  
  iVar3 = 0;
  do {
    iVar2 = _copywithin(param_1,&uStack_5,1);
    if (iVar2 != 0xe) {
      return uStack_5;
    }
    bVar1 = iVar3 < 0x10;
    iVar3 = iVar3 + 1;
  } while (bVar1);
  return 0;
}
/* GHIDRADEC_FUNCTION index=3178 start=0x408dbd2 */

void sub_408DBD2(undefined4 param_1,undefined param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined uStack_5;
  
  uStack_5 = param_2;
  iVar3 = 0;
  do {
    iVar2 = _copywithin(&uStack_5,param_1,1);
    if (iVar2 != 0xe) {
      return;
    }
    bVar1 = iVar3 < 0x10;
    iVar3 = iVar3 + 1;
  } while (bVar1);
  return;
}
/* GHIDRADEC_FUNCTION index=3179 start=0x408dc16 */

bool sub_408DC16(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined uStack_5;
  
  iVar2 = 0;
  do {
    iVar1 = _copywithin(param_1,&uStack_5,1);
    if (iVar1 != 0xe) break;
    _delay(1000);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 10);
  return iVar2 != 10;
}
/* GHIDRADEC_FUNCTION index=3180 start=0x4090a50 */

void sub_4090A50(undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 *in_A1;
  char *pcVar2;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  pcVar2 = (char *)&uStack_24;
  _strcpy(pcVar2,*param_1);
  cVar1 = uStack_24._0_1_;
  while (cVar1 != '\0') {
    pcVar2 = pcVar2 + 1;
    cVar1 = *pcVar2;
  }
  *pcVar2 = (char)*(undefined2 *)(param_1 + 2) + '0';
  pcVar2[1] = '\0';
  _bcopy(param_2,&uStack_14,0x10);
  *in_A1 = uStack_24;
  in_A1[1] = uStack_20;
  in_A1[2] = uStack_1c;
  in_A1[3] = uStack_18;
  in_A1[4] = uStack_14;
  in_A1[5] = uStack_10;
  in_A1[6] = uStack_c;
  in_A1[7] = uStack_8;
  return;
}
/* GHIDRADEC_FUNCTION index=3181 start=0x409100e */

uint sub_409100E(int param_1,uint param_2,int param_3,word param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  word wVar3;
  sword sVar4;
  word *pwVar5;
  word *pwVar6;
  
  if (param_2 == 0) {
    _bcopy(param_1,param_3,param_5 * 2);
    uVar2 = 0;
  }
  else {
    uVar2 = (uint)param_4;
    param_5 = param_5 + -1;
    if (-1 < param_5) {
      pwVar6 = (word *)(param_3 + param_5 * 2);
      pwVar5 = (word *)(param_1 + param_5 * 2);
      do {
        do {
          uVar1 = (uint)*pwVar5 << (param_2 & 0x3f);
          *pwVar6 = (word)uVar1 | (word)uVar2;
          uVar2 = uVar1 >> 0x10;
          pwVar6 = pwVar6 + -1;
          pwVar5 = pwVar5 + -1;
          wVar3 = (word)((uint)param_5 >> 0x10);
          sVar4 = (sword)param_5 + -1;
          param_5 = CONCAT22(wVar3,sVar4);
        } while (sVar4 != -1);
        param_5 = (uint)wVar3 * 0x10000 + -1;
      } while (wVar3 != 0);
    }
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=3182 start=0x4091e18 */

uint sub_4091E18(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = *_event_middle;
  if (((uVar2 ^ (uint)*_eventc_h << 0x10) & 0x80000) != 0) {
    *_event_middle = *_event_middle + 0x80000;
    puVar1 = _event_high;
    uVar2 = *_event_middle & 0xfff80000;
    if (uVar2 == 0) {
      *_event_high = *_event_high + 1;
      uVar2 = *puVar1;
    }
  }
  if (dword_40B55BC != (code *)0x0) {
    uVar2 = (*dword_40B55BC)(param_1,param_2,param_3);
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=3183 start=0x4093792 */

void sub_4093792(undefined4 param_1)

{
  _kernel_thread(_kernel_task,param_1,0);
  return;
}
/* GHIDRADEC_FUNCTION index=3184 start=0x409630e */

void sub_409630E(void)

{
  int iVar1;
  
  iVar1 = _get_vbr();
  dword_40B5614 = *(undefined4 *)(iVar1 + 8);
  dword_40B5618 = *(undefined4 *)(iVar1 + 0xc);
  *(code **)(iVar1 + 8) = __dbg_trap;
  *(code **)(iVar1 + 0xc) = __dbg_trap;
  return;
}
/* GHIDRADEC_FUNCTION index=3185 start=0x4096358 */

void sub_4096358(void)

{
  int iVar1;
  
  iVar1 = _get_vbr();
  *(undefined4 *)(iVar1 + 8) = dword_40B5614;
  *(undefined4 *)(iVar1 + 0xc) = dword_40B5618;
  return;
}
/* GHIDRADEC_FUNCTION index=3186 start=0x40963bc */

int sub_40963BC(int param_1)

{
  bool bVar1;
  int iVar2;
  int aiStack_1c [2];
  int iStack_14;
  int *piStack_10;
  int iStack_c;
  int *piStack_8;
  
  piStack_8 = (int *)&_kdb_net;
  iStack_14 = 0;
loc_40963D0:
  iStack_c = _en_recv(aiStack_1c,0x242,piStack_8[2],_kdb_ipaddr);
  if (iStack_c == 0) {
    if ((param_1 == 0) ||
       (iVar2 = iStack_14 + 1, bVar1 = iStack_14 < param_1, iStack_14 = iVar2, bVar1))
    goto loc_40963D0;
  }
  if ((param_1 != 0) && (iStack_c == 0)) {
    return 0;
  }
  if (aiStack_1c[0] == 0x473) {
    piStack_10 = (int *)(iStack_c + 0x2a);
    if (*piStack_8 == *piStack_10) {
      return iStack_c;
    }
    if (*piStack_8 + -1 == *piStack_10) {
      _kdebug_send(0x473,*piStack_10);
    }
    else if ((*piStack_10 == 0) && (*(int *)(iStack_c + 0x2e) == 8)) {
      *piStack_8 = 0;
      return iStack_c;
    }
  }
  goto loc_40963D0;
}
/* GHIDRADEC_FUNCTION index=3187 start=0x40964c0 */

void sub_40964C0(void)

{
  _kdebug_send(0x473,_kdb_net._0_4_);
  _kdb_net._0_4_ = _kdb_net._0_4_ + 1;
  return;
}
/* GHIDRADEC_FUNCTION index=3188 start=0x4096f96 */

void sub_4096F96(int param_1,uint param_2)

{
  _bzero(param_1,0x1c);
  *(uint *)(param_1 + 8) = param_2;
  *(uint *)(param_1 + 0x18) = _page_size / param_2;
  return;
}
/* GHIDRADEC_FUNCTION index=3189 start=0x4096fd0 */

int sub_4096FD0(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puStack_8;
  
  while (iVar2 = _page_size, iVar1 = param_1[1], iVar1 == 0) {
    _page_table_alloc_size = _page_size + _page_table_alloc_size;
    param_1[4] = _page_size + param_1[4];
    _kmem_alloc_wired(_kernel_map,&puStack_8,iVar2);
    puStack_8 = (undefined4 *)_pmap_resident_extract(_kernel_pmap,puStack_8);
    for (; iVar2 != 0; iVar2 = iVar2 - param_1[2]) {
      *puStack_8 = 0x2a6a6b73;
      puStack_8[1] = *param_1;
      puStack_8[2] = 0;
      if (*param_1 == 0) {
        param_1[1] = (int)puStack_8;
      }
      else {
        *(undefined4 **)(*param_1 + 8) = puStack_8;
      }
      *param_1 = (int)puStack_8;
      puStack_8 = (undefined4 *)(param_1[2] + *param_1);
      param_1[5] = param_1[5] + 1;
    }
  }
  param_1[1] = *(int *)(iVar1 + 8);
  if (param_1[1] == 0) {
    *param_1 = 0;
  }
  else {
    *(undefined4 *)(param_1[1] + 4) = 0;
  }
  param_1[5] = param_1[5] + -1;
  _page_table_memory_size = param_1[2] + _page_table_memory_size;
  param_1[3] = param_1[2] + param_1[3];
  _bzero(iVar1,param_1[2]);
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=3190 start=0x40970c6 */

uint sub_40970C6(uint *param_1,undefined4 *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *unaff_D3;
  int iVar5;
  int *piVar6;
  
  iVar5 = 0;
  *param_2 = 0x2a6a6b73;
  uVar4 = 0;
  iVar3 = _pmap_phys_to_index(param_2);
  if ((iVar3 != -1) && ((int)param_1[6] < (int)param_1[5])) {
    unaff_D3 = (int *)(~_page_mask & (uint)param_2);
    for (piVar6 = unaff_D3;
        (piVar6 < (int *)(_page_size + (int)unaff_D3) && (*piVar6 == 0x2a6a6b73));
        piVar6 = (int *)(param_1[2] + (int)piVar6)) {
      uVar4 = uVar4 + 1;
    }
  }
  *param_2 = 0;
  if ((_pmap_gc == 0) || (uVar4 != param_1[6])) {
    if (*param_1 != 0) {
      *(undefined4 **)(*param_1 + 8) = param_2;
    }
    *param_2 = 0x2a6a6b73;
    param_2[1] = *param_1;
    param_2[2] = 0;
    if (*param_1 == 0) {
      param_1[1] = (uint)param_2;
    }
    else {
      *(undefined4 **)(*param_1 + 8) = param_2;
    }
    *param_1 = (uint)param_2;
    param_1[5] = param_1[5] + 1;
  }
  else {
    uVar4 = *param_1;
    if (uVar4 != 0) {
      uVar2 = ~_page_mask;
      do {
        if (unaff_D3 == (int *)(uVar2 & uVar4)) {
          if (*(int *)(uVar4 + 8) == 0) {
            *param_1 = *(uint *)(uVar4 + 4);
          }
          else {
            *(undefined4 *)(*(int *)(uVar4 + 8) + 4) = *(undefined4 *)(uVar4 + 4);
          }
          if (*(int *)(uVar4 + 4) == 0) {
            param_1[1] = *(uint *)(uVar4 + 8);
          }
          else {
            *(undefined4 *)(*(int *)(uVar4 + 4) + 8) = *(undefined4 *)(uVar4 + 8);
          }
        }
        uVar4 = *(uint *)(uVar4 + 4);
      } while (uVar4 != 0);
    }
    iVar3 = _pmap_phys_to_index(param_2);
    iVar5 = _pv_head_table;
    _page_table_alloc_size = _page_table_alloc_size - _page_size;
    param_1[4] = param_1[4] - _page_size;
    param_1[5] = param_1[5] - param_1[6];
    iVar5 = *(int *)(iVar5 + 8 + iVar3 * 0xc);
  }
  _page_table_memory_size = _page_table_memory_size - param_1[2];
  uVar4 = param_1[2];
  uVar2 = param_1[3];
  uVar1 = uVar2 - uVar4;
  param_1[3] = uVar1;
  uVar4 = (uint)(byte)((uVar2 < uVar4) << 4 | ((int)uVar1 < 0) << 3 | (uVar1 == 0) << 2 |
                       SBORROW4(uVar2,uVar4) << 1 | uVar2 < uVar4);
  if (iVar5 != 0) {
    uVar4 = _kmem_free(_kernel_map,iVar5,_page_size);
  }
  return uVar4;
}
/* GHIDRADEC_FUNCTION index=3191 start=0x409ba26 */

/* WARNING: Control flow encountered unimplemented instructions */

void sub_409BA26(void)

{
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}
/* GHIDRADEC_FUNCTION index=3192 start=0x409bd76 */

/* WARNING: Control flow encountered unimplemented instructions */

void sub_409BD76(void)

{
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}
/* GHIDRADEC_FUNCTION index=3193 start=0x409c614 */

void sub_409C614(void)

{
  word wVar1;
  int unaff_A6;
  
  wVar1 = *(word *)(unaff_A6 + -0xe4);
  if (((wVar1 & 0x20) != 0) && (((wVar1 & 0x10) == 0 || ((wVar1 & 0x7f) == 0x38)))) {
    *(undefined *)(unaff_A6 + -0x48) = 0xff;
    return;
  }
  *(undefined *)(unaff_A6 + -0x48) = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=3194 start=0x409c646 */

void sub_409C646(void)

{
  byte bVar1;
  uint uVar2;
  byte *in_A0;
  byte *extraout_A0;
  byte *extraout_A0_00;
  byte *extraout_A0_01;
  byte *pbVar3;
  int unaff_A6;
  
  *(undefined4 *)(unaff_A6 + -0x54) = 0;
  bVar1 = *in_A0;
  *in_A0 = bVar1 & 0x7f;
  in_A0[2] = -((bVar1 & 0x80) != 0);
  if (*(char *)(unaff_A6 + 0xb) == ',') {
    sub_409C6F2();
    pbVar3 = extraout_A0;
  }
  else if ((*(byte *)(unaff_A6 + -0xe4) & 0x20) == 0) {
    sub_409C6D0();
    pbVar3 = extraout_A0_00;
  }
  else {
    sub_409C6B0();
    pbVar3 = extraout_A0_01;
  }
  if (*(sword *)pbVar3 < 0x4000) {
    *(byte *)(unaff_A6 + -0x54) = *(byte *)(unaff_A6 + -0x54) | 0x10;
  }
  uVar2 = *(uint *)(pbVar3 + 2) >> 0x18;
  *(uint *)(pbVar3 + 2) = uVar2;
  if (uVar2 != 0) {
    *pbVar3 = *pbVar3 | 0x80;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=3195 start=0x409c6b0 */

void sub_409C6B0(void)

{
  int extraout_A0;
  int unaff_A6;
  
  nrm_zero();
  if ((*(byte *)(extraout_A0 + 4) & 0x80) == 0) {
    *(word *)(unaff_A6 + -0x54) = *(word *)(unaff_A6 + -0x54) | 0x80;
    *(byte *)(unaff_A6 + -0x7a) = *(byte *)(unaff_A6 + -0x7a) | 8;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=3196 start=0x409c6d0 */

void sub_409C6D0(void)

{
  int extraout_A0;
  int unaff_A6;
  
  nrm_zero();
  if ((*(byte *)(extraout_A0 + 4) & 0x80) != 0) {
    *(undefined *)(unaff_A6 + -0x54) = *(undefined *)(unaff_A6 + -0x54);
    return;
  }
  *(byte *)(unaff_A6 + -0x54) = *(byte *)(unaff_A6 + -0x54) | 0x80;
  return;
}
/* GHIDRADEC_FUNCTION index=3197 start=0x409c6f2 */

void sub_409C6F2(void)

{
  int extraout_A0;
  int unaff_A6;
  
  nrm_zero();
  if ((*(byte *)(extraout_A0 + 4) & 0x80) != 0) {
    *(undefined *)(unaff_A6 + -0x54) = *(undefined *)(unaff_A6 + -0x54);
    return;
  }
  *(byte *)(unaff_A6 + -0x54) = *(byte *)(unaff_A6 + -0x54) | 0x80;
  return;
}
/* GHIDRADEC_FUNCTION index=3198 start=0x409c714 */

qword sub_409C714(void)

{
  word wVar1;
  undefined2 uVar2;
  undefined2 extraout_D1u;
  undefined2 extraout_D1u_00;
  uint uVar3;
  int iVar4;
  int unaff_A6;
  float10 fVar5;
  
  if ((*(word *)(unaff_A6 + -0xe4) & 0x3b) == 0) {
    if (((sword)(((uint)*(word *)(unaff_A6 + -0xcc) << 0x14) >> 0x10) == -0x10) &&
       (uVar2 = 0, (word)(((uint)*(word *)(unaff_A6 + -0xcc) << 0x11) >> 0x1d) == 7)) {
      if ((*(int *)(unaff_A6 + -200) == 0) && (*(int *)(unaff_A6 + -0xc4) == 0)) {
        *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x2000000;
        if (*(int *)(unaff_A6 + -0xcc) < 0) {
          *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x8000000;
        }
      }
      else {
        *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x1000000;
        *(undefined *)(unaff_A6 + -0xe8) = 0x60;
        if (((*(byte *)(unaff_A6 + -200) & 0x40) == 0) &&
           (*(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x1004080,
           (*(byte *)(unaff_A6 + -0x7e) & 0x40) == 0)) {
          *(byte *)(unaff_A6 + -200) = *(byte *)(unaff_A6 + -200) | 0x40;
        }
        if (*(int *)(unaff_A6 + -0xcc) < 0) {
          *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x8000000;
        }
      }
    }
    else {
      uVar2 = 0;
      if (((*(word *)(unaff_A6 + -0xca) & 0xf) == 0) &&
         ((*(int *)(unaff_A6 + -200) == 0 && (*(int *)(unaff_A6 + -0xc4) == 0)))) {
        if (*(int *)(unaff_A6 + -0xcc) < 0) {
          *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0xc000000;
          *(undefined4 *)(unaff_A6 + -0xcc) = 0x80000000;
          *(undefined4 *)(unaff_A6 + -200) = 0;
          *(undefined4 *)(unaff_A6 + -0xc4) = 0;
        }
        else {
          *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x4000000;
          *(undefined4 *)(unaff_A6 + -0xcc) = 0;
          *(undefined4 *)(unaff_A6 + -200) = 0;
          *(undefined4 *)(unaff_A6 + -0xc4) = 0;
        }
      }
      else {
        fVar5 = (float10)decbin();
        *(undefined (*) [12])(unaff_A6 + -0xcc) = (undefined  [12])fVar5;
        uVar2 = extraout_D1u_00;
      }
    }
  }
  else if (((sword)(((uint)*(word *)(unaff_A6 + -0xcc) << 0x14) >> 0x10) == -0x10) &&
          (uVar2 = 0, (word)(((uint)*(word *)(unaff_A6 + -0xcc) << 0x11) >> 0x1d) == 7)) {
    if (((*(int *)(unaff_A6 + -200) != 0) || (*(int *)(unaff_A6 + -0xc4) != 0)) &&
       ((*(byte *)(unaff_A6 + -200) & 0x40) == 0)) {
      *(uint *)(unaff_A6 + -0x7c) = *(uint *)(unaff_A6 + -0x7c) | 0x1004080;
    }
  }
  else {
    uVar2 = 0;
    if (((*(word *)(unaff_A6 + -0xca) & 0xf) == 0) &&
       ((*(int *)(unaff_A6 + -200) == 0 && (*(int *)(unaff_A6 + -0xc4) == 0)))) {
      if (*(int *)(unaff_A6 + -0xcc) < 0) {
        *(undefined4 *)(unaff_A6 + -0xcc) = 0x80000000;
        *(undefined4 *)(unaff_A6 + -200) = 0;
        *(undefined4 *)(unaff_A6 + -0xc4) = 0;
      }
      else {
        *(undefined4 *)(unaff_A6 + -0xcc) = 0;
        *(undefined4 *)(unaff_A6 + -200) = 0;
        *(undefined4 *)(unaff_A6 + -0xc4) = 0;
      }
    }
    else {
      fVar5 = (float10)decbin();
      *(undefined (*) [12])(unaff_A6 + -0xcc) = (undefined  [12])fVar5;
      uVar2 = extraout_D1u;
    }
  }
  *(word *)(unaff_A6 + -0xe4) = *(word *)(unaff_A6 + -0xe4) & 0xfbff;
  wVar1 = *(word *)(unaff_A6 + -0xcc) & 0x7fff;
  uVar3 = CONCAT22(uVar2,*(word *)(unaff_A6 + -0xcc)) & 0xffff7fff;
  if (wVar1 != 0x7fff) {
    if (wVar1 != 0) {
      if (wVar1 < 0x4000) {
        *(undefined *)(unaff_A6 + -0xe8) = 0x10;
      }
      else {
        *(undefined *)(unaff_A6 + -0xe8) = 0;
      }
      return (qword)uVar3;
    }
    *(undefined *)(unaff_A6 + -0xe8) = 0x30;
    return CONCAT44(0x20,uVar3);
  }
  iVar4 = *(int *)(unaff_A6 + -200);
  if ((iVar4 == 0) && (iVar4 = *(int *)(unaff_A6 + -0xc4), iVar4 == 0)) {
    *(undefined *)(unaff_A6 + -0xe8) = 0x40;
    return 0x4000000000;
  }
  *(undefined *)(unaff_A6 + -0xe8) = 0x60;
  return CONCAT44(0x60,iVar4);
}
/* GHIDRADEC_FUNCTION index=3199 start=0x409d60e */

void sub_409D60E(void)

{
  func_0x0409d61c();
  return;
}

