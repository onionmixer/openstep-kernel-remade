
/* WARNING: Removing unreachable block (ram,0xf00378f0) */
/* WARNING: Removing unreachable block (ram,0xf0037968) */
/* WARNING: Removing unreachable block (ram,0xf0037858) */

undefined8 _tcp_slowtimo(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  int iVar3;
  int iVar4;
  undefined4 unaff_l3;
  undefined4 *puVar5;
  undefined4 unaff_l4;
  undefined4 *puVar6;
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
  _splnet();
  _tcp_maxidle = _tcp_keepintvl << 3;
  if (_tcb != (undefined4 *)0x0) {
    if ((undefined4 **)_tcb != &_tcb) {
      iVar2 = _tcb[8];
      puVar5 = _tcb;
      do {
        puVar6 = (undefined4 *)*puVar5;
        if (iVar2 != 0) {
          iVar4 = 0;
          iVar3 = iVar2;
          do {
            if (((*(sword *)(iVar3 + 10) != 0) &&
                (uVar1 = (int)*(sword *)(iVar3 + 10) - 1, *(sword *)(iVar3 + 10) = (sword)uVar1,
                (uVar1 & 0xffff) == 0)) &&
               (_tcp_usrreq(*(undefined4 *)(*(int *)(iVar2 + 0x20) + 0x1c),0x13,0,iVar4,0),
               (undefined4 *)puVar6[1] != puVar5)) goto loc_F0037940;
            iVar4 = iVar4 + 1;
            iVar3 = iVar3 + 2;
          } while (iVar4 < 4);
          *(sword *)(iVar2 + 0x58) = *(sword *)(iVar2 + 0x58) + 1;
          if (*(sword *)(iVar2 + 0x5a) != 0) {
            *(sword *)(iVar2 + 0x5a) = *(sword *)(iVar2 + 0x5a) + 1;
          }
        }
loc_F0037940:
        if ((undefined4 **)puVar6 == &_tcb) break;
        iVar2 = puVar6[8];
        puVar5 = puVar6;
      } while( true );
    }
    _tcp_iss = _tcp_iss + 64000;
  }
  _splx();
  return CONCAT44(param_2,param_1);
}
