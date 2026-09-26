/* GHIDRADEC_FUNCTION index=3075 start=0x407f1ee */

void sub_407F1EE(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_kalloc(0x14);
  puVar1[2] = param_1;
  puVar1[3] = param_2;
  puVar1[4] = param_3;
  *dword_40B5032 = puVar1;
  puVar1[1] = dword_40B5032;
  *puVar1 = &unk_40B502E;
  dword_40B5032 = puVar1;
  _thread_wakeup_prim(&dword_40B5046,0,0);
  return;
}
/* GHIDRADEC_FUNCTION index=3076 start=0x407f250 */

void sub_407F250(int *param_1)

{
  word wVar1;
  uint uVar2;
  uint uVar3;
  undefined auStack_a [6];
  
  if ((param_1[2] & 0x400U) == 0) {
    uVar3 = 2;
  }
  else {
    uVar3 = ((word)((word)param_1[2] ^ 4) & 7) >> 2;
  }
  _sprintf(auStack_a,&aSdD,param_1[1]);
  uVar2 = *(uint *)(*(int *)(*param_1 + 0xb2) + 1) >> 0x1f;
  if ((*(byte *)((int)param_1 + 10) & 8) != 0) {
    uVar2 = uVar2 | 2;
  }
  wVar1 = (sword)param_1[1] << 3;
  _vol_notify_dev((int)(sword)(wVar1 | (sword)dword_40B5026 << 8),
                  (int)(sword)(wVar1 | (sword)dword_40B502A << 8),&unk_40A62E7,uVar3,auStack_a,uVar2
                 );
  return;
}
/* GHIDRADEC_FUNCTION index=3077 start=0x407f2e4 */

void sub_407F2E4(void)

{
  if ((_kernel_task == 0) || (dword_40B2080 != 0)) {
    _timeout(sub_407F2E4,0,_hz);
  }
  else {
    if (dword_40B2088 != 0) {
      _kernel_thread_noblock(_kernel_task,sub_407E934);
    }
    dword_40B2080 = 1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=3078 start=0x407f330 */

void sub_407F330(int param_1)

{
  if (*(uint *)(param_1 + 4) < dword_40B2084) {
    *(word *)(param_1 + 10) = *(word *)(param_1 + 10) & 0xff7f;
  }
  else {
    sub_407E8B8(param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=3079 start=0x407f358 */

void sub_407F358(int param_1)

{
  int iVar1;
  
  iVar1 = param_1 * 0xc2;
  _bzero(_sd_sdd + iVar1,0xc2);
  *(undefined **)(_sd_sdd + iVar1 + 8) = _sd_sd + param_1 * 0x50;
  *(uint *)(_sd_sdd + iVar1 + 0xb2) = iVar1 + 0x40c5ee7U & 0xfffffff0;
  *(undefined4 *)(_sd_sdd + iVar1 + 0xc) = 0;
  *(undefined4 *)(_sd_sdd + iVar1 + 0x1c) = 0;
  _sd_sdd[iVar1 + 0x10] = 0;
  _sd_sdd[iVar1 + 0x15] = 10;
  *(undefined4 *)(_sd_sdd + iVar1 + 0xbe) = 0xffffffff;
  return;
}
/* GHIDRADEC_FUNCTION index=3080 start=0x407f682 */

void sub_407F682(undefined4 param_1)

{
  sub_407F6A6(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=3081 start=0x407f6a6 */

void sub_407F6A6(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = *(sword *)(*(int *)(param_1 + 0x10) + 4) * 0x42;
  piVar3 = (int *)(_sg_sgd + iVar2);
  _bzero(piVar3,0x42);
  *piVar3 = param_1;
  *(uint *)(_sg_sgd + iVar2 + 4) = iVar2 + 0x40c65efU & 0xfffffff0;
  iVar1 = iVar2 + 0x40c65d0;
  *(int *)(_sg_sgd + iVar2 + 0xc) = iVar1;
  *(int *)iVar1 = iVar1;
  _sg_sgd[iVar2 + 0x15] = 0;
  _sg_sgd[iVar2 + 0x17] = 0;
  *(undefined *)(*piVar3 + 0x1c) = 0xff;
  *(undefined *)(*piVar3 + 0x1d) = 0xff;
  return;
}
/* GHIDRADEC_FUNCTION index=3082 start=0x407fae2 */

void sub_407FAE2(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  piVar4 = param_1 + 2;
  if (piVar4 == (int *)*piVar4) {
                    /* WARNING: Subroutine does not return */
    _panic(aSgdoneNoBufOnS);
  }
  *(undefined *)((int)param_1 + 0x15) = 0;
  iVar1 = *piVar4;
  piVar2 = *(int **)(iVar1 + 0x4a);
  piVar3 = *(int **)(iVar1 + 0x4e);
  if (piVar2 == piVar4) {
    param_1[3] = (int)piVar3;
  }
  else {
    *(int **)((int)piVar2 + 0x4e) = piVar3;
  }
  if (piVar3 == param_1 + 2) {
    *piVar3 = (int)piVar2;
  }
  else {
    *(int **)((int)piVar3 + 0x4a) = piVar2;
  }
  *(int *)(iVar1 + 0x3c) = *(int *)(iVar1 + 0x14) - param_2;
  *(int *)(iVar1 + 0x1c) = param_3;
  if (param_3 == 2) {
    *(undefined *)(iVar1 + 0x20) = 2;
  }
  else {
    *(undefined *)(iVar1 + 0x20) = *(undefined *)(*param_1 + 0x4e);
  }
  if (param_1 + 2 == (int *)param_1[2]) {
    *(byte *)(iVar1 + 0x48) = *(byte *)(iVar1 + 0x48) | 1;
    _wakeup(iVar1);
  }
  else {
    _scsi_dstart(*param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=3083 start=0x407fc78 */

undefined4 sub_407FC78(int *param_1,byte *param_2)

{
  char *pcVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((*param_2 < 8) && (param_2[1] < 8)) {
    iVar3 = *param_1;
    if (*(byte *)(iVar3 + 0x1c) != 0xff) {
      pcVar1 = (char *)(*(int *)(iVar3 + 0x18) + (uint)*(byte *)(iVar3 + 0x1c) * 8 + 0x18 +
                       (uint)*(byte *)(iVar3 + 0x1d));
      *pcVar1 = *pcVar1 + -1;
      *(undefined *)(*param_1 + 0x1c) = 0xff;
      *(undefined *)(*param_1 + 0x1d) = 0xff;
    }
    if ((*(char *)(*(int *)(*param_1 + 0x18) + (uint)*param_2 * 8 + 0x18 + (uint)param_2[1]) != '\0'
        ) && (iVar3 = _suser(), iVar3 == 0)) {
      return 0xd;
    }
    pcVar1 = (char *)(*(int *)(*param_1 + 0x18) + (uint)*param_2 * 8 + 0x18 + (uint)param_2[1]);
    *pcVar1 = *pcVar1 + '\x01';
    *(byte *)(*param_1 + 0x1c) = *param_2;
    *(byte *)(*param_1 + 0x1d) = param_2[1];
    uVar2 = 0;
  }
  else {
    uVar2 = 0x16;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=3084 start=0x407fd2c */

int sub_407FD2C(int *param_1,int param_2)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 *puVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined auStack_c [8];
  
  iVar6 = *param_1;
  if (*(char *)(iVar6 + 0x1c) == -1) {
    *(undefined4 *)(param_2 + 0x1c) = 0xb;
    return 0xd;
  }
  _microtime(auStack_c);
  if (*(int *)(param_2 + 0x14) == 0) {
    uStack_10 = 0;
  }
  else {
    iVar5 = _kmem_alloc_wired(_kernel_map,&uStack_10,*(int *)(param_2 + 0x14));
    if (iVar5 != 0) {
      *(undefined4 *)(param_2 + 0x1c) = 8;
      return 0xc;
    }
    if ((*(int *)(param_2 + 0xc) == 1) &&
       (iVar5 = _copyinmsg(*(undefined4 *)(param_2 + 0x10),uStack_10,*(undefined4 *)(param_2 + 0x14)
                          ), iVar5 != 0)) {
      _kmem_free(_kernel_map,uStack_10,*(undefined4 *)(param_2 + 0x14));
      *(undefined4 *)(param_2 + 0x1c) = 9;
      return iVar5;
    }
  }
  uVar1 = *(undefined4 *)(param_2 + 0x10);
  *(undefined4 *)(param_2 + 0x10) = uStack_10;
  piVar2 = (int *)param_1[3];
  if (piVar2 == param_1 + 2) {
    *piVar2 = param_2;
  }
  else {
    *(int *)((int)piVar2 + 0x4a) = param_2;
  }
  *(int **)(param_2 + 0x4e) = piVar2;
  *(int **)(param_2 + 0x4a) = param_1 + 2;
  param_1[3] = param_2;
  iVar5 = 0;
  *(byte *)(param_2 + 0x48) = *(byte *)(param_2 + 0x48) & 0xfe;
  if ((*(byte *)(iVar6 + 0x24) & 0x20) == 0) {
    iVar5 = _scsi_dstart(iVar6);
  }
  if (iVar5 == 0) {
    bVar4 = *(byte *)(param_2 + 0x48);
    while ((bVar4 & 1) == 0) {
      _sleep(param_2,0x14);
      bVar4 = *(byte *)(param_2 + 0x48);
    }
  }
  *(undefined4 *)(param_2 + 0x10) = uVar1;
  if (((*(int *)(param_2 + 0x3c) == 0) || (*(int *)(param_2 + 0xc) != 0)) ||
     (iVar6 = _copyoutmsg(uStack_10,uVar1,*(int *)(param_2 + 0x3c)), iVar6 == 0)) {
    if (*(int *)(param_2 + 0x14) != 0) {
      _kmem_free(_kernel_map,uStack_10,*(int *)(param_2 + 0x14));
    }
    puVar3 = (undefined4 *)param_1[1];
    *(undefined4 *)(param_2 + 0x22) = *puVar3;
    *(undefined4 *)(param_2 + 0x26) = puVar3[1];
    *(undefined4 *)(param_2 + 0x2a) = puVar3[2];
    *(undefined4 *)(param_2 + 0x2e) = puVar3[3];
    *(undefined4 *)(param_2 + 0x32) = puVar3[4];
    *(undefined4 *)(param_2 + 0x36) = puVar3[5];
    *(undefined2 *)(param_2 + 0x3a) = *(undefined2 *)(puVar3 + 6);
    _microtime(&uStack_18);
    _timevalsub(&uStack_18,auStack_c);
    *(undefined4 *)(param_2 + 0x40) = uStack_18;
    *(undefined4 *)(param_2 + 0x44) = uStack_14;
    iVar6 = 0;
  }
  else {
    _kmem_free(_kernel_map,uStack_10,*(undefined4 *)(param_2 + 0x14));
    *(undefined4 *)(param_2 + 0x1c) = 9;
  }
  return iVar6;
}
/* GHIDRADEC_FUNCTION index=3085 start=0x40800cc */

void sub_40800CC(void)

{
  uint uVar1;
  uint uVar2;
  word wVar3;
  uint uVar4;
  sword sVar5;
  uint uVar6;
  uint unaff_D5;
  undefined *puVar7;
  uint uStack_24;
  uint *puVar8;
  
  puVar7 = &stack0xffffffe0;
  dword_40B5080 = (_gpflags & 0x1f) >> 4;
  dword_40B5084 = (_gpflags & 0xf) >> 3;
  byte_40C6CED = (undefined)_gpflags;
  if ((_vol_r == dword_40B5088) && (_vol_l == dword_40B508C)) {
    uStack_24 = _gpflags << 0x18;
    _mon_send(0xc4);
    puVar7 = &stack0xffffffe0;
  }
  else {
    _vol_r = _vol_r & 0x3f;
    _vol_l = _vol_l & 0x3f;
    if (_mon_rev != '\0') {
      uStack_24 = _gpflags << 0x18;
      _mon_send(0xc4);
      _delay(200);
      if (_vol_l == _vol_r) {
        uStack_24 = _vol_r << 0x18 | 0xc0000000;
        _mon_send(0xc2);
      }
      else {
        uStack_24 = _vol_r << 0x18 | 0x80000000;
        _mon_send(0xc2);
        _delay(200);
        _mon_send(0xc2,_vol_l << 0x18 | 0x40000000);
      }
      puVar8 = &uStack_24;
      uStack_24 = 200;
      _delay();
      dword_40B5088 = _vol_r;
      dword_40B508C = _vol_l;
      goto loc_4080342;
    }
    unaff_D5 = _gpflags << 0x18;
  }
  do {
    if ((_vol_r == dword_40B5088) && (_vol_l == dword_40B508C)) {
      return;
    }
    if (_vol_l == _vol_r) {
      uVar6 = _vol_r | 0x7c0;
      dword_40B5088 = _vol_r;
loc_4080278:
      dword_40B508C = _vol_l;
    }
    else {
      if (_vol_r == dword_40B5088) {
        uVar6 = _vol_l | 0x740;
        goto loc_4080278;
      }
      uVar6 = _vol_r | 0x780;
      dword_40B5088 = _vol_r;
    }
    *(uint *)(puVar7 + -4) = unaff_D5;
    *(undefined4 *)(puVar7 + -8) = 0xc4;
    *(undefined4 *)(puVar7 + -0xc) = 0x408028e;
    _mon_send();
    *(undefined4 *)(puVar7 + -0xc) = 200;
    *(undefined4 *)(puVar7 + -0x10) = 0x4080298;
    _delay();
    uVar4 = 10;
    do {
      uVar1 = (int)uVar6 >> (uVar4 & 0x3f) & 1;
      uVar2 = unaff_D5;
      if (uVar1 != 0) {
        uVar2 = unaff_D5 | 0x2000000;
      }
      *(uint *)(puVar7 + -4) = uVar2;
      *(undefined4 *)(puVar7 + -8) = 0xc4;
      *(undefined4 *)(puVar7 + -0xc) = 0x40802ba;
      _mon_send();
      *(undefined4 *)(puVar7 + -0xc) = 200;
      *(undefined4 *)(puVar7 + -0x10) = 0x40802c4;
      _delay();
      if (uVar1 == 0) {
        uVar1 = unaff_D5 | 0x4000000;
      }
      else {
        uVar1 = unaff_D5 | 0x6000000;
      }
      *(uint *)(puVar7 + -4) = uVar1;
      *(undefined4 *)(puVar7 + -8) = 0xc4;
      *(undefined4 *)(puVar7 + -0xc) = 0x40802e8;
      _mon_send();
      *(undefined4 *)(puVar7 + -0xc) = 200;
      *(undefined4 *)(puVar7 + -0x10) = 0x40802f2;
      _delay();
      wVar3 = (word)(uVar4 >> 0x10);
      sVar5 = (sword)uVar4 + -1;
      uVar4 = CONCAT22(wVar3,sVar5);
    } while ((sVar5 != -1) || (uVar4 = (uint)wVar3 * 0x10000 - 1, wVar3 != 0));
    *(uint *)(puVar7 + -4) = unaff_D5;
    *(undefined4 *)(puVar7 + -8) = 0xc4;
    *(undefined4 *)(puVar7 + -0xc) = 0x408030e;
    _mon_send();
    *(undefined4 *)(puVar7 + -0xc) = 200;
    *(undefined4 *)(puVar7 + -0x10) = 0x408031a;
    _delay();
    *(uint *)(puVar7 + -0x10) = unaff_D5 | 0x1000000;
    *(undefined4 *)(puVar7 + -0x14) = 0xc4;
    *(undefined4 *)(puVar7 + -0x18) = 0x4080328;
    _mon_send();
    *(undefined4 *)(puVar7 + -0x18) = 200;
    *(undefined4 *)(puVar7 + -0x1c) = 0x408032e;
    _delay();
    *(uint *)(puVar7 + -0x1c) = unaff_D5;
    *(undefined4 *)(puVar7 + -0x20) = 0xc4;
    *(undefined4 *)(puVar7 + -0x24) = 0x4080336;
    _mon_send();
    puVar8 = (uint *)(puVar7 + -4);
    *(undefined4 *)(puVar7 + -4) = 200;
    *(undefined4 *)(puVar7 + -8) = 0x4080342;
    _delay();
loc_4080342:
    puVar7 = (undefined *)((int)puVar8 + 4);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=3086 start=0x4080388 */

void sub_4080388(void)

{
  uint uVar1;
  uint uVar2;
  word wStack_24;
  undefined uStack_22;
  byte bStack_21;
  undefined2 uStack_20;
  
  _nvram_check(&wStack_24);
  uVar1 = CONCAT31(CONCAT21(wStack_24,uStack_22),bStack_21) & 0xfc0fffff;
  wStack_24 = (word)(uVar1 >> 0x10) | (word)(((wRam040b508a & 0x3f) << 0x14) >> 0x10);
  uVar2 = CONCAT22((sword)uVar1,uStack_20) & 0xfc0fffff;
  uVar1 = uVar2 | (wRam040b508e & 0x3f) << 0x14;
  uStack_22 = (undefined)(uVar1 >> 0x18);
  bStack_21 = (byte)(uVar1 >> 0x10);
  uStack_20 = (undefined2)uVar2;
  bStack_21 = bStack_21 & 0xf3 | (byte)((dword_40B5084 & 1) << 2) | (byte)((dword_40B5080 & 1) << 3)
  ;
  _nvram_set(&wStack_24);
  return;
}
/* GHIDRADEC_FUNCTION index=3087 start=0x408061a */

void sub_408061A(int param_1)

{
  int iVar1;
  int iVar2;
  
  if ((&unk_40C6DF4)[param_1] == 0) {
    iVar2 = _kalloc(0x54);
    _snd_stream_queue_init(iVar2,iVar2,_dspq_start_complex);
    iVar1 = iVar2 + 0x3e;
    *(int *)(iVar2 + 0x42) = iVar1;
    *(int *)iVar1 = iVar1;
    (&unk_40C6DF4)[param_1] = iVar2;
    *(undefined4 *)(iVar2 + 0x32) = 0x10000;
    *(undefined4 *)(iVar2 + 0x36) = 0xc000;
    *(undefined4 *)(iVar2 + 0x46) = 0;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=3088 start=0x408067a */

/* WARNING: Type propagation algorithm not settling */

undefined4 sub_408067A(int param_1)

{
  undefined4 uVar1;
  undefined4 ******ppppppuVar2;
  uint uVar3;
  int iVar4;
  word wVar5;
  undefined4 *******pppppppuVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 ******ppppppuVar11;
  undefined4 ******ppppppuVar12;
  int iVar13;
  uint uVar14;
  undefined uVar15;
  undefined4 *******unaff_A3;
  int iVar16;
  uint uStack_1c;
  undefined uStack_d;
  undefined4 *******pppppppuStack_c;
  undefined4 *******pppppppuStack_8;
  
  iVar13 = *(int *)(param_1 + 4) + -0x24;
  uVar10 = *(undefined4 *)(param_1 + 0x1c);
  uVar1 = *(undefined4 *)(param_1 + 0x20);
  ppppppuVar2 = *(undefined4 *******)(param_1 + 0x10);
  if (*(int *)(param_1 + 0x14) == 200) {
    if ((dword_40C6E84 & 0x20000) == 0) {
      iVar9 = param_1 + 0x24;
      pppppppuStack_c = &pppppppuStack_c;
      pppppppuStack_8 = &pppppppuStack_c;
      while (0 < iVar13) {
        uVar15 = (undefined)uVar1;
        uStack_d = (undefined)uVar10;
        switch(*(undefined4 *)(iVar9 + 4)) {
        case :
          uStack_1c = (uint)*(word *)(iVar9 + 0xe);
          ppppppuVar11 = (undefined4 ******)(*(int *)(iVar9 + 0x10) * uStack_1c >> 3);
          if ((*(byte *)(iVar9 + 0xb) & 8) == 0) {
            uVar8 = ~_page_mask;
            uVar3 = *(uint *)(iVar9 + 0x14);
            uVar14 = uVar3 % _page_size;
            uVar7 = (int)ppppppuVar11 + _page_mask + uVar14 & uVar8;
            unaff_A3 = (undefined4 *******)_kalloc(0x26);
            *(undefined *)((int)unaff_A3 + 0x23) = 0;
            pppppppuVar6 = unaff_A3 + 1;
            iVar16 = _vm_allocate(_kernel_map,pppppppuVar6,uVar7,1);
            if (iVar16 != 0) {
              return 0x68;
            }
            iVar16 = _vm_map_copy(_kernel_map,dword_40C6EBC,*pppppppuVar6,uVar7,uVar8 & uVar3,0,1);
            if (iVar16 != 0) {
              _vm_deallocate(_kernel_map,*pppppppuVar6,uVar7);
              return 0x68;
            }
            _vm_map_pageable(_kernel_map,*pppppppuVar6,(int)*pppppppuVar6 + uVar7,0);
            *pppppppuVar6 = (undefined4 ******)(uVar14 + (int)*pppppppuVar6);
            iVar13 = iVar13 + -0x18;
            iVar16 = iVar9 + 0x18;
          }
          else {
            unaff_A3 = (undefined4 *******)_kalloc((int)ppppppuVar11 + 0x26);
            *(undefined *)((int)unaff_A3 + 0x23) = 1;
            _bcopy(iVar9 + 0x14,(undefined4 ******)((int)unaff_A3 + 0x26),ppppppuVar11);
            unaff_A3[1] = (undefined4 ******)((int)unaff_A3 + 0x26);
            iVar13 = (iVar13 + -0x14) - (int)ppppppuVar11;
            iVar16 = iVar9 + 0x14 + (int)ppppppuVar11;
          }
          wVar5 = *(word *)(iVar9 + 0xe);
          if (wVar5 == 0x10) {
            ppppppuVar12 = (undefined4 ******)0x2;
loc_408089C:
            *unaff_A3 = ppppppuVar12;
          }
          else {
            if (0x10 < wVar5) {
              if (wVar5 == 0x18) {
                ppppppuVar12 = (undefined4 ******)0x3;
              }
              else {
                if (wVar5 != 0x20) goto loc_408089E;
                ppppppuVar12 = (undefined4 ******)0x4;
              }
              goto loc_408089C;
            }
            if (wVar5 == 8) {
              ppppppuVar12 = (undefined4 ******)0x1;
              goto loc_408089C;
            }
          }
loc_408089E:
          unaff_A3[2] = ppppppuVar11;
          unaff_A3[3] = unaff_A3[1];
          *(undefined *)(unaff_A3 + 8) = uStack_d;
          *(undefined *)((int)unaff_A3 + 0x21) = 3;
          *(undefined *)((int)unaff_A3 + 0x22) = uVar15;
          *(undefined *)(unaff_A3 + 9) = 0;
          pppppppuVar6 = pppppppuStack_c;
          goto joined_r0x04080ab2;
        case :
          iVar16 = iVar9 + 0x10;
          iVar13 = iVar13 + -0x10;
          unaff_A3 = (undefined4 *******)_kalloc(0x26);
          *unaff_A3 = (undefined4 ******)0x7;
          unaff_A3[1] = *(undefined4 *******)(iVar9 + 0xc);
          break;
        case :
          iVar16 = iVar9 + 0x14;
          iVar13 = iVar13 + -0x14;
          unaff_A3 = (undefined4 *******)_kalloc(0x26);
          *unaff_A3 = (undefined4 ******)0x8;
          unaff_A3[1] = (undefined4 ******)(*(uint *)(iVar9 + 0xc) & 0xf89f0000);
          unaff_A3[2] = (undefined4 ******)(*(uint *)(iVar9 + 0x10) & 0xf89f0000);
          break;
        case :
          iVar4 = *(int *)(iVar9 + 0x20);
          if ((*(byte *)(iVar9 + 0x13) & 8) == 0) {
            unaff_A3 = (undefined4 *******)_kalloc(0x26);
            *(undefined *)((int)unaff_A3 + 0x23) = 0;
          }
          else {
            unaff_A3 = (undefined4 *******)_kalloc(iVar4 + 0x26);
            *(undefined *)((int)unaff_A3 + 0x23) = 1;
            _bcopy(iVar9 + 0x1c,(undefined4 ******)((int)unaff_A3 + 0x26),iVar4);
            unaff_A3[1] = (undefined4 ******)((int)unaff_A3 + 0x26);
          }
          *unaff_A3 = (undefined4 ******)0x9;
          if (*(undefined4 ******)(iVar9 + 0xc) == (undefined4 *****)0x0) {
            unaff_A3[1][4] = _snd_var;
          }
          else {
            unaff_A3[1][4] = *(undefined4 ******)(iVar9 + 0xc);
          }
          iVar16 = iVar4 + 0x1c + iVar9;
          iVar13 = (iVar13 + -0x1c) - iVar4;
          *(undefined *)(unaff_A3 + 8) = uStack_d;
          *(undefined *)((int)unaff_A3 + 0x21) = 3;
          *(undefined *)((int)unaff_A3 + 0x22) = uVar15;
          *(undefined *)(unaff_A3 + 9) = 0;
          pppppppuVar6 = pppppppuStack_c;
          goto joined_r0x04080ab2;
        case :
          iVar16 = iVar9 + 8;
          iVar13 = iVar13 + -8;
          unaff_A3 = (undefined4 *******)_kalloc(0x26);
          *unaff_A3 = (undefined4 ******)0xa;
          break;
        case :
          iVar16 = iVar9 + 8;
          iVar13 = iVar13 + -8;
          unaff_A3 = (undefined4 *******)_kalloc(0x26);
          *unaff_A3 = (undefined4 ******)0xb;
          break;
        case :
          iVar16 = iVar9 + 0x1c;
          iVar13 = iVar13 + -0x1c;
          unaff_A3 = (undefined4 *******)_kalloc(0x26);
          *unaff_A3 = (undefined4 ******)0x0;
          unaff_A3[1] = *(undefined4 *******)(iVar9 + 0xc);
          unaff_A3[2] = *(undefined4 *******)(iVar9 + 0x10);
          unaff_A3[3] = *(undefined4 *******)(iVar9 + 0x18);
          break;
        case :
          ppppppuVar11 = *(undefined4 *******)(iVar9 + 0x14);
          if ((undefined4 ******)0x1fd0 < ppppppuVar11) {
            return 0x68;
          }
          unaff_A3 = (undefined4 *******)_kalloc(0x26);
          ppppppuVar12 = (undefined4 ******)_kalloc(ppppppuVar11);
          unaff_A3[1] = ppppppuVar12;
          *(undefined *)((int)unaff_A3 + 0x23) = 0;
          unaff_A3[4] = ppppppuVar2;
          wVar5 = *(word *)(iVar9 + 0xe);
          if (wVar5 == 0x10) {
            ppppppuVar12 = (undefined4 ******)0xe;
loc_4080922:
            *unaff_A3 = ppppppuVar12;
          }
          else {
            if (0x10 < wVar5) {
              if (wVar5 == 0x18) {
                ppppppuVar12 = (undefined4 ******)0xf;
              }
              else {
                if (wVar5 != 0x20) goto loc_4080924;
                ppppppuVar12 = (undefined4 ******)0x10;
              }
              goto loc_4080922;
            }
            if (wVar5 == 8) {
              ppppppuVar12 = (undefined4 ******)0xd;
              goto loc_4080922;
            }
          }
loc_4080924:
          unaff_A3[2] = ppppppuVar11;
          unaff_A3[3] = unaff_A3[1];
          iVar16 = iVar9 + 0x18;
          iVar13 = iVar13 + -0x18;
          *(undefined *)(unaff_A3 + 8) = uStack_d;
          *(undefined *)((int)unaff_A3 + 0x21) = 3;
          *(undefined *)((int)unaff_A3 + 0x22) = uVar15;
          *(undefined *)(unaff_A3 + 9) = 0;
          pppppppuVar6 = pppppppuStack_c;
          goto joined_r0x04080ab2;
        case :
          iVar16 = iVar9 + 0x10;
          iVar13 = iVar13 + -0x10;
          unaff_A3 = (undefined4 *******)_kalloc(0x26);
          *unaff_A3 = (undefined4 ******)0x11;
          unaff_A3[1] = *(undefined4 *******)(iVar9 + 0xc);
          *(undefined *)((int)unaff_A3 + 0x23) = 0;
          *(undefined *)(unaff_A3 + 8) = uStack_d;
          *(undefined *)((int)unaff_A3 + 0x21) = 3;
          *(undefined *)((int)unaff_A3 + 0x22) = uVar15;
          *(undefined *)(unaff_A3 + 9) = 0;
          pppppppuVar6 = pppppppuStack_c;
          goto joined_r0x04080ab2;
        :
          goto loc_40806AA;
        }
        *(undefined *)((int)unaff_A3 + 0x23) = 0;
        *(undefined *)(unaff_A3 + 8) = uStack_d;
        *(undefined *)((int)unaff_A3 + 0x21) = 3;
        *(undefined *)((int)unaff_A3 + 0x22) = uVar15;
        *(undefined *)(unaff_A3 + 9) = 0;
        pppppppuVar6 = pppppppuStack_c;
joined_r0x04080ab2:
        pppppppuStack_c = unaff_A3;
        if ((undefined4 ********)pppppppuStack_8 != &pppppppuStack_c) {
          pppppppuStack_8[6] = unaff_A3;
          pppppppuStack_c = pppppppuVar6;
        }
        unaff_A3[7] = pppppppuStack_8;
        unaff_A3[6] = &pppppppuStack_c;
        iVar9 = iVar16;
        pppppppuStack_8 = unaff_A3;
      }
      if ((undefined4 ********)pppppppuStack_c == &pppppppuStack_c) {
        _dspq_execute();
      }
      else {
        if (pppppppuStack_8 == pppppppuStack_c) {
          *(undefined *)((int)unaff_A3 + 0x21) = 0;
        }
        else {
          *(undefined *)((int)pppppppuStack_8 + 0x21) = 2;
          *(undefined *)((int)pppppppuStack_c + 0x21) = 1;
        }
        _dspq_enqueue(&pppppppuStack_c);
      }
      uVar10 = 100;
    }
    else {
      uVar10 = 0x6d;
    }
  }
  else {
loc_40806AA:
    uVar10 = 0x66;
  }
  return uVar10;
}
/* GHIDRADEC_FUNCTION index=3089 start=0x4080b2e */

undefined4 sub_4080B2E(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_kalloc(*(int *)(param_1 + 0x3c) + 0x26);
  *puVar1 = 9;
  *(undefined *)((int)puVar1 + 0x23) = 1;
  *(undefined *)(puVar1 + 9) = 0;
  _bcopy(*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x3c),
         *(undefined4 *)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x44),
         *(undefined4 *)(param_1 + 0x48),*(undefined4 *)(param_1 + 0x4c),(int)puVar1 + 0x26,
         *(undefined4 *)(param_1 + 0x3c));
  if (dword_40C6E72 != (undefined4 *)0x0) {
    _dspq_free_msg(dword_40C6E72);
  }
  if (*(int *)(param_1 + 0x28) == 0) {
    *(undefined4 *)(puVar1[1] + 0x10) = _snd_var;
  }
  else {
    *(int *)(puVar1[1] + 0x10) = *(int *)(param_1 + 0x28);
  }
  dword_40C6E6A = *(undefined4 *)(param_1 + 0x1c);
  dword_40C6E6E = *(undefined4 *)(param_1 + 0x20);
  dword_40C6E72 = puVar1;
  _dspq_execute();
  return 100;
}
/* GHIDRADEC_FUNCTION index=3090 start=0x4080be6 */

undefined4 sub_4080BE6(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  code *pcVar6;
  
  if ((*(int *)(param_1 + 4) == 0x34) && (iVar1 = *(int *)(param_1 + 0x30), iVar1 - 1U < 0x13)) {
    if (*(int *)(param_1 + 0x2c) == 5) {
      uVar3 = *(int *)(param_1 + 0x20) * 2;
    }
    else {
      uVar3 = *(int *)(param_1 + 0x2c) * *(int *)(param_1 + 0x20);
    }
    if (uVar3 <= _page_size) {
      if (*(int *)(param_1 + 0x2c) == 5) {
        uVar3 = *(int *)(param_1 + 0x20) * 2;
      }
      else {
        uVar3 = *(int *)(param_1 + 0x2c) * *(int *)(param_1 + 0x20);
      }
      if (_page_size % uVar3 == 0) {
        iVar4 = (&unk_40C6DF4)[iVar1];
        if (iVar4 == 0) {
          iVar4 = _kalloc(0x54);
          pcVar6 = _dspq_start_simple;
          if ((dword_40C6E84 & 0x2000) != 0) {
            pcVar6 = _dspq_start_complex;
          }
          _snd_stream_queue_init(iVar4,iVar4,pcVar6);
          iVar2 = iVar4 + 0x3e;
          *(int *)(iVar4 + 0x42) = iVar2;
          *(int *)iVar2 = iVar2;
          (&unk_40C6DF4)[iVar1] = iVar4;
        }
        *(undefined4 *)(iVar4 + 0x46) = 0;
        *(undefined4 *)(iVar4 + 0x4a) = *(undefined4 *)(param_1 + 0x1c);
        *(undefined2 *)(iVar4 + 0x4e) = *(undefined2 *)(param_1 + 0x22);
        *(undefined2 *)(iVar4 + 0x50) = *(undefined2 *)(param_1 + 0x26);
        *(undefined *)(iVar4 + 0x52) = *(undefined *)(param_1 + 0x2b);
        *(undefined *)(iVar4 + 0x53) = *(undefined *)(param_1 + 0x2f);
        uVar5 = _snd_dspcmd_def_dmasize(iVar1);
        *(undefined4 *)(iVar4 + 0x2a) = uVar5;
        uVar5 = _snd_dspcmd_def_high_water(iVar1);
        *(undefined4 *)(iVar4 + 0x32) = uVar5;
        uVar5 = _snd_dspcmd_def_low_water(iVar1);
        *(undefined4 *)(iVar4 + 0x36) = uVar5;
        return 100;
      }
    }
  }
  return 0x67;
}
/* GHIDRADEC_FUNCTION index=3091 start=0x4080d78 */

int sub_4080D78(int param_1)

{
  undefined4 ***pppuVar1;
  int iVar2;
  undefined4 ***pppuVar3;
  undefined4 **ppuStack_5c;
  undefined4 **ppuStack_58;
  undefined auStack_54 [12];
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_18;
  undefined2 uStack_10;
  undefined2 uStack_e;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  sub_408061A(0);
  _bcopy(unk_40B20FA,auStack_54,0x50);
  uStack_44 = 0x10000;
  uStack_48 = *(undefined4 *)(param_1 + 0x10);
  uStack_18 = *(undefined4 *)(param_1 + 0x10);
  uStack_8 = *(undefined4 *)(param_1 + 0x3c);
  uStack_10 = *(undefined2 *)(param_1 + 0x34);
  uStack_e = *(undefined2 *)(param_1 + 0x36);
  uStack_c = *(undefined4 *)(param_1 + 0x38);
  iVar2 = _msg_send(auStack_54,0,0);
  if (iVar2 == 0) {
    ppuStack_5c = &ppuStack_5c;
    ppuStack_58 = &ppuStack_5c;
    pppuVar3 = (undefined4 ***)_kalloc(0x26);
    *pppuVar3 = (undefined4 **)0x5;
    pppuVar3[1] = *(undefined4 ***)(param_1 + 0x1c);
    *(undefined2 *)(pppuVar3 + 2) = *(undefined2 *)(param_1 + 0x22);
    *(undefined2 *)((int)pppuVar3 + 10) = *(undefined2 *)(param_1 + 0x26);
    *(undefined *)(pppuVar3 + 3) = *(undefined *)(param_1 + 0x2b);
    *(undefined *)((int)pppuVar3 + 0xd) = *(undefined *)(param_1 + 0x2f);
    *(undefined *)((int)pppuVar3 + 0xe) = 0;
    *(undefined *)((int)pppuVar3 + 0x23) = 0;
    *(undefined *)(pppuVar3 + 9) = 0;
    pppuVar1 = pppuVar3;
    if ((undefined4 ***)ppuStack_58 != &ppuStack_5c) {
      ppuStack_58[6] = pppuVar3;
      pppuVar1 = (undefined4 ***)ppuStack_5c;
    }
    ppuStack_5c = pppuVar1;
    pppuVar3[7] = ppuStack_58;
    pppuVar3[6] = &ppuStack_5c;
    ppuStack_58 = pppuVar3;
    _dspq_enqueue(&ppuStack_5c);
    iVar2 = 0;
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=3092 start=0x4080e6e */

int sub_4080E6E(int param_1)

{
  undefined4 ***pppuVar1;
  int iVar2;
  undefined4 ***pppuVar3;
  undefined4 **ppuStack_54;
  undefined4 **ppuStack_50;
  undefined auStack_4c [12];
  undefined4 uStack_40;
  undefined4 uStack_3c;
  int iStack_14;
  undefined4 uStack_c;
  
  sub_408061A(0);
  _bcopy(unk_40B214A,auStack_4c,0x48);
  uStack_3c = 0x10000;
  uStack_40 = *(undefined4 *)(param_1 + 0x10);
  uStack_c = *(undefined4 *)(param_1 + 0x10);
  if (*(int *)(param_1 + 0x2c) == 5) {
    iStack_14 = *(int *)(param_1 + 0x20) * 2;
  }
  else {
    iStack_14 = *(int *)(param_1 + 0x20) * *(int *)(param_1 + 0x2c);
  }
  iVar2 = _msg_send(auStack_4c,0,0);
  if (iVar2 == 0) {
    ppuStack_54 = &ppuStack_54;
    ppuStack_50 = &ppuStack_54;
    pppuVar3 = (undefined4 ***)_kalloc(0x26);
    *pppuVar3 = (undefined4 **)0x6;
    pppuVar3[1] = *(undefined4 ***)(param_1 + 0x1c);
    *(undefined2 *)(pppuVar3 + 2) = *(undefined2 *)(param_1 + 0x22);
    *(undefined2 *)((int)pppuVar3 + 10) = *(undefined2 *)(param_1 + 0x26);
    *(undefined *)(pppuVar3 + 3) = *(undefined *)(param_1 + 0x2b);
    *(undefined *)((int)pppuVar3 + 0xd) = *(undefined *)(param_1 + 0x2f);
    *(undefined *)((int)pppuVar3 + 0xe) = 0;
    *(undefined *)(pppuVar3 + 8) = 2;
    *(undefined *)((int)pppuVar3 + 0x22) = 0;
    *(undefined *)((int)pppuVar3 + 0x21) = 0;
    *(undefined *)((int)pppuVar3 + 0x23) = 0;
    *(undefined *)(pppuVar3 + 9) = 0;
    pppuVar1 = pppuVar3;
    if ((undefined4 ***)ppuStack_50 != &ppuStack_54) {
      ppuStack_50[6] = pppuVar3;
      pppuVar1 = (undefined4 ***)ppuStack_54;
    }
    ppuStack_54 = pppuVar1;
    pppuVar3[7] = ppuStack_50;
    pppuVar3[6] = &ppuStack_54;
    ppuStack_50 = pppuVar3;
    _dspq_enqueue(&ppuStack_54);
    iVar2 = 0;
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=3093 start=0x4080f78 */

undefined4 sub_4080F78(void)

{
  return 0x67;
}
/* GHIDRADEC_FUNCTION index=3094 start=0x4080f82 */

undefined4 sub_4080F82(int param_1)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = dword_40C6E5A == dword_40C6E56;
  iVar1 = *(int *)(param_1 + 0x10);
  if (*(int *)(param_1 + 0x10) == 0) {
    iVar1 = _snd_var;
  }
  if (dword_40C6E5A != dword_40C6E52) {
    _snd_reply_dsp_msg(iVar1);
    iVar1 = dword_40C6E7C;
  }
  dword_40C6E7C = iVar1;
  if (bVar2) {
    _dsp_dev_loop();
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=3095 start=0x4080fe0 */

undefined4 sub_4080FE0(int param_1)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = dword_40C6E66 == dword_40C6E62;
  iVar1 = *(int *)(param_1 + 0x10);
  if (*(int *)(param_1 + 0x10) == 0) {
    iVar1 = _snd_var;
  }
  if (dword_40C6E66 != dword_40C6E5E) {
    _snd_reply_dsp_err(iVar1);
    iVar1 = dword_40C6E80;
  }
  dword_40C6E80 = iVar1;
  if (bVar2) {
    _dsp_dev_loop();
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=3096 start=0x40818b4 */

byte sub_40818B4(void)

{
  int iVar1;
  byte bVar2;
  
  bVar2 = *(byte *)(_slot_id_bmap + 0x2008002);
  if ((char)bVar2 < '\0') {
    if (((_snd_var == 0) && (dword_40C6E76 == 0)) || (dword_40C6E76 == 7)) {
      bVar2 = *(byte *)(_slot_id_bmap + 0x2008000) & 0xfc;
      *(byte *)(_slot_id_bmap + 0x2008000) = *(byte *)(_slot_id_bmap + 0x2008000) & 0xfc;
    }
    else {
      if (((*(byte *)(_slot_id_bmap + 0x2008000) & 2) != 0) &&
         (*(byte *)(_slot_id_bmap + 0x2008000) = *(byte *)(_slot_id_bmap + 0x2008000) & 0xfd,
         (dword_40C6E84 & 0x2000) != 0)) {
        _softint_run(3);
      }
      if ((*(byte *)(_slot_id_bmap + 0x2008000) & 1) != 0) {
        if (((dword_40C6E84 & 0x2c00) == 0) && ((dword_40C6E84 & 0x100) != 0)) {
          bVar2 = *(byte *)(_slot_id_bmap + 0x2008000) & 0xfe;
        }
        else {
          bVar2 = *(byte *)(_slot_id_bmap + 0x2008000) | 1;
        }
        *(byte *)(_slot_id_bmap + 0x2008000) = bVar2;
      }
      if (dword_40C6E76 == 3) {
        _dsp_dev_reset_chip();
      }
      if (((*(byte *)(_slot_id_bmap + 0x2008002) & 0x18) == 0x18) && ((dword_40C6E84 & 0x200) != 0))
      {
        dword_40C6E76 = 7;
        _printf(aDspAborted);
      }
      if ((*(byte *)(_slot_id_bmap + 0x2008002) & 0x40) != 0) {
        sub_40826E6(1);
      }
      if (((*(byte *)(_slot_id_bmap + 0x2008002) & 3) == 0) && (iVar1 = _dspq_check(), iVar1 == 0))
      {
        return 0;
      }
      bVar2 = _dsp_dev_loop();
    }
  }
  return bVar2;
}
/* GHIDRADEC_FUNCTION index=3097 start=0x40821fa */

void sub_40821FA(int param_1,uint param_2,int param_3,int param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  
  if ((param_5 != 0x40000) || (param_2 == 0)) {
    uVar1 = 0;
    if ((param_1 == 0) && (param_3 == 4)) {
      uVar1 = param_2;
    }
    uVar1 = uVar1 & 0x1f;
    if (param_5 == 0x40000) {
      uVar2 = uVar1 | 0x10000;
    }
    else {
      uVar2 = uVar1 | 0x20000;
      if ((param_4 == 4) && (_dma_chip == 0x139)) {
        uVar2 = CONCAT22(2,(sword)uVar1) | 0x8000;
      }
    }
    dword_40C6E84 = dword_40C6E84 | 0x40;
    _dspq_enqueue_syscall(uVar2);
    _dspq_enqueue_cond(0x800000,0);
    dword_40C6E84 = dword_40C6E84 & 0xffffffbf;
    _dspq_execute();
  }
  return;
}
/* GHIDRADEC_FUNCTION index=3098 start=0x408229e */

undefined4 sub_408229E(undefined4 param_1,int param_2,uint param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  word extraout_D0u;
  word wVar5;
  word extraout_D0u_00;
  byte bVar6;
  int iVar7;
  char cVar8;
  
  bVar6 = 1;
  if (param_4 == 0) {
    bVar6 = 2;
  }
  bVar6 = *(byte *)(_slot_id_bmap + 0x2008000) & 0x18 | bVar6;
  iVar3 = (&unk_40C6DF4)[param_2];
  iVar2 = *(int *)(iVar3 + 0x3e);
  iVar7 = *(int *)(iVar2 + 0x2c);
  if (iVar7 == iVar3 + 0x3e) {
    *(int *)(iVar3 + 0x42) = iVar7;
  }
  else {
    *(int *)(iVar7 + 0x30) = iVar3 + 0x3e;
  }
  *(int *)(iVar3 + 0x3e) = iVar7;
  dword_40C6D1C = param_4;
  *(undefined4 *)(iVar2 + 0x18) = 4;
  if ((param_3 - 1 < 2) && (param_4 == 0)) {
    iVar7 = 10;
    bVar4 = *(byte *)(_slot_id_bmap + 0x2008002);
    while ((bVar4 & 4) == 0) {
      _delay(1);
      iVar7 = iVar7 + -1;
      if (iVar7 == 0) goto loc_4082358;
      bVar4 = *(byte *)(_slot_id_bmap + 0x2008002);
    }
    if (iVar7 == 0) {
loc_4082358:
      _printf(aDspDmaTimedOut);
    }
    if (param_3 == 1) {
      *(undefined *)(_slot_id_bmap + 0x2008005) = 0;
      *(undefined *)(_slot_id_bmap + 0x2008006) = 0;
    }
    else if (param_3 == 2) {
      *(undefined *)(_slot_id_bmap + 0x2008005) = 0;
    }
  }
  sub_40826E6(1);
  _dma_enqueue(&_dsp_var,iVar2 + 0xc);
  wVar5 = extraout_D0u;
  if (param_3 == 2) {
    *(byte *)(_slot_id_bmap + 0x2008000) = bVar6 | 0x40;
    cVar8 = '\0';
  }
  else if ((int)param_3 < 3) {
    cVar8 = 1 < param_3;
    if (param_3 == 1) {
      *(byte *)(_slot_id_bmap + 0x2008000) = bVar6 | 0x60;
    }
  }
  else if (param_3 == 3) {
    uVar1 = *_scr2;
    *_scr2 = uVar1 & 0xdfffffff;
    wVar5 = (word)(uVar1 >> 0x10) & 0xdfff;
    *(byte *)(_slot_id_bmap + 0x2008000) = bVar6 | 0x20;
    cVar8 = '\0';
  }
  else {
    cVar8 = 4 < param_3;
    if (param_3 == 4) {
      uVar1 = *_scr2;
      *_scr2 = uVar1 | 0x20000000;
      wVar5 = (word)(uVar1 >> 0x10) | 0x2000;
      *(byte *)(_slot_id_bmap + 0x2008000) = bVar6 | 0x20;
      cVar8 = _dma_chip < 0x139;
      if (_dma_chip == 0x139) {
        _printf(aAttemptToUseBr);
        wVar5 = extraout_D0u_00;
      }
    }
  }
  bVar6 = *(byte *)(_slot_id_bmap + 0x2008000) | 0x10;
  *(byte *)(_slot_id_bmap + 0x2008000) = bVar6;
  return CONCAT22(wVar5,(word)(byte)(cVar8 << 4 | ((char)bVar6 < '\0') << 3 | (bVar6 == 0) << 2));
}
/* GHIDRADEC_FUNCTION index=3099 start=0x40824bc */

void sub_40824BC(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _dma_dequeue(&_dsp_var,0);
  iVar1 = *(int *)(iVar1 + 0x18);
  *(int *)((&unk_40C6DF4)[param_2] + 0x26) =
       *(int *)(iVar1 + 4) + *(int *)((&unk_40C6DF4)[param_2] + 0x26);
  if (param_4 == 0) {
    *(byte *)(_slot_id_bmap + 0x2008000) = *(byte *)(_slot_id_bmap + 0x2008000) & 0x8d;
    *(undefined *)(_slot_id_bmap + 0x2008001) = 0x94;
    iVar2 = 100;
    do {
      if (-1 < *(char *)(_slot_id_bmap + 0x2008001)) break;
      _delay(1);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    if (iVar2 == 0) {
      _printf(aDspDmaCleanupD);
    }
    dword_40C6E76 = 0;
    *(byte *)(_slot_id_bmap + 0x2008000) = *(byte *)(_slot_id_bmap + 0x2008000) | 1;
  }
  else {
    dword_40C6E84 = dword_40C6E84 | 0x40;
    dword_40C6E76 = 3;
    _dspq_enqueue_cond(0x800000,0);
    _dspq_enqueue_hc(0x12);
    _dspq_enqueue_cond(0x800000,0);
    _dspq_enqueue_hf(0x73000000,0x81000000);
    _dspq_enqueue_state(0);
    dword_40C6E84 = dword_40C6E84 & 0xffffffbf;
    _dspq_execute();
  }
  if ((int *)((&unk_40C6DF4)[param_2] + 0x3e) == *(int **)((&unk_40C6DF4)[param_2] + 0x3e)) {
    *(uint *)(iVar1 + 0x34) = *(uint *)(iVar1 + 0x34) | 1;
  }
  (**(code **)(iVar1 + 0x28))(iVar1);
  return;
}

