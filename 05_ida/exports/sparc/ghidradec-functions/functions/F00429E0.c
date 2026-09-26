
/* WARNING: Removing unreachable block (ram,0xf0042b78) */
/* WARNING: Removing unreachable block (ram,0xf0042adc) */
/* WARNING: Removing unreachable block (ram,0xf0042b54) */
/* WARNING: Removing unreachable block (ram,0xf0042b10) */
/* WARNING: Removing unreachable block (ram,0xf0042abc) */
/* WARNING: Removing unreachable block (ram,0xf0042a94) */
/* WARNING: Removing unreachable block (ram,0xf0042a68) */
/* WARNING: Removing unreachable block (ram,0xf0042a1c) */
/* WARNING: Removing unreachable block (ram,0xf0042a00) */
/* WARNING: Removing unreachable block (ram,0xf0042a38) */
/* WARNING: Removing unreachable block (ram,0xf0042a74) */
/* WARNING: Removing unreachable block (ram,0xf0042ab0) */
/* WARNING: Removing unreachable block (ram,0xf0042afc) */
/* WARNING: Removing unreachable block (ram,0xf0042b2c) */
/* WARNING: Removing unreachable block (ram,0xf0042ad4) */
/* WARNING: Removing unreachable block (ram,0xf0042b70) */
/* WARNING: Removing unreachable block (ram,0xf0042b84) */
/* WARNING: Removing unreachable block (ram,0xf00429f4) */

undefined8
_clntkudp_create(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  int iVar1;
  undefined *puVar2;
  undefined4 uVar3;
  code *pcVar4;
  int iVar5;
  undefined4 unaff_l0;
  int iVar6;
  undefined4 unaff_l1;
  int iVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar1 = 0x78;
  *(undefined4 *)(_active_threads + 0x198) = 1;
  _kalloc();
  _bzero();
  iVar7 = iVar1 + 4;
  if (_clntkudpxid == 0) {
    _getthetime((undefined *)((int)register0x00000038 + -0x40));
    _clntkudpxid = *(int *)((int)register0x00000038 + -0x3c);
  }
  puVar2 = _udp_ops;
  *(undefined **)(iVar1 + 8) = _udp_ops;
  *(int *)(iVar1 + 0xc) = iVar1;
  _authkern_create();
  *(undefined **)(iVar1 + 4) = puVar2;
  *(undefined4 *)((int)register0x00000038 + -0x38) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x34) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x30) = 2;
  *(undefined4 *)((int)register0x00000038 + -0x2c) = param_2;
  *(undefined4 *)((int)register0x00000038 + -0x28) = param_3;
  _clntkudp_init(iVar7,param_1,param_4,param_5);
  uVar3 = 0x2260;
  _kalloc();
  *(undefined4 *)(iVar1 + 0x68) = uVar3;
  pcVar4 = sub_F00429A4;
  _mclgetx(sub_F00429A4,0,uVar3,0x2260,1);
  iVar6 = iVar1 + 0x34;
  if (pcVar4 != (code *)0x0) {
    _xdrmbuf_init(iVar6,pcVar4,0);
    iVar5 = iVar6;
    _xdr_callhdr(iVar6,(undefined *)((int)register0x00000038 + -0x38));
    if (iVar5 == 0) {
      _printf(aClntkudpCreate);
      _m_freem(pcVar4);
    }
    else {
      (**(code **)(*(int *)(iVar1 + 0x38) + 0x10))();
      *(int *)(iVar1 + 100) = iVar6;
      _m_free(pcVar4);
      iVar6 = 2;
      _socreate(2,iVar1 + 0x14,2,0x11);
      if (iVar6 == 0) {
        iVar6 = *(int *)(iVar1 + 0x14);
        sub_F00434D4(iVar6,0);
        if (iVar6 == 0) {
          *(undefined4 *)(_active_threads + 0x198) = 0;
          goto locret_F0042B90;
        }
        puVar2 = aClntkudpCreate_1;
      }
      else {
        puVar2 = aClntkudpCreate_0;
      }
      _printf(puVar2,iVar6);
    }
  }
  *(undefined4 *)(_active_threads + 0x198) = 0;
  _kfree(*(undefined4 *)(iVar1 + 0x68),0x2260);
  _crfree(*(undefined4 *)(iVar1 + 0x74));
  _kfree(iVar1,0x78);
  iVar7 = 0;
locret_F0042B90:
  return CONCAT44(pcVar4,iVar7);
}
