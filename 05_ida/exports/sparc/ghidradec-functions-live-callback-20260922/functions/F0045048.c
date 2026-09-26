
/* WARNING: Removing unreachable block (ram,0xf004514c) */
/* WARNING: Removing unreachable block (ram,0xf00450f4) */
/* WARNING: Removing unreachable block (ram,0xf00450d0) */
/* WARNING: Removing unreachable block (ram,0xf004509c) */
/* WARNING: Removing unreachable block (ram,0xf0045078) */
/* WARNING: Removing unreachable block (ram,0xf00450bc) */
/* WARNING: Removing unreachable block (ram,0xf00450e0) */
/* WARNING: Removing unreachable block (ram,0xf0045130) */
/* WARNING: Removing unreachable block (ram,0xf0045154) */
/* WARNING: Removing unreachable block (ram,0xf004504c) */

undefined8 _svckudp_send(int *param_1,uint *param_2)

{
  int *piVar1;
  code *pcVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 unaff_l0;
  uint *puVar8;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 uVar9;
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
  puVar8 = (uint *)param_1[0xc];
  piVar1 = param_1;
  _spltty();
  uVar9 = 0;
  puVar4 = puVar8 + 9;
  uVar7 = *puVar8;
  if ((uVar7 & 1) != 0) {
    do {
      *puVar8 = uVar7 | 2;
      _sleep(puVar8,0x17);
      uVar7 = *puVar8;
    } while ((uVar7 & 1) != 0);
    uVar7 = *puVar8;
  }
  *puVar8 = uVar7 | 1;
  _splx(piVar1);
  pcVar2 = sub_F0045018;
  _mclgetx(sub_F0045018,puVar8,param_1[0xb],0x2260,1);
  if (pcVar2 == (code *)0x0) {
    sub_F0045018(puVar8);
    goto locret_F0045178;
  }
  _xdrmbuf_init(puVar8 + 9,pcVar2,0);
  *param_2 = puVar8[1];
  puVar3 = puVar4;
  _xdr_replymsg();
  if (puVar3 == (uint *)0x0) {
    _printf(DAT_f010de68);
    _m_freem(pcVar2);
loc_F004515C:
    puVar6 = (undefined4 *)puVar8[0xb];
  }
  else {
    (**(code **)(puVar8[10] + 0x10))();
    if (*(int *)pcVar2 == 0) {
      *(sword *)(pcVar2 + 8) = (sword)puVar4;
    }
    iVar5 = *param_1;
    _ku_sendto_mbuf(iVar5,pcVar2,param_1 + 4);
    if (iVar5 == 0) {
      uVar9 = 1;
      goto loc_F004515C;
    }
    puVar6 = (undefined4 *)puVar8[0xb];
  }
  if (puVar6 != (undefined4 *)0x0) {
    (*(code *)*puVar6)();
  }
locret_F0045178:
  return CONCAT44(param_2,uVar9);
}

