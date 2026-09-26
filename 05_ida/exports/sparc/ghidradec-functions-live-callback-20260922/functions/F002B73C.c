
/* WARNING: Removing unreachable block (ram,0xf002b900) */
/* WARNING: Removing unreachable block (ram,0xf002b91c) */
/* WARNING: Removing unreachable block (ram,0xf002b824) */
/* WARNING: Removing unreachable block (ram,0xf002b7c4) */
/* WARNING: Removing unreachable block (ram,0xf002b7a8) */
/* WARNING: Removing unreachable block (ram,0xf002b8dc) */
/* WARNING: Removing unreachable block (ram,0xf002b884) */
/* WARNING: Removing unreachable block (ram,0xf002b74c) */
/* WARNING: Removing unreachable block (ram,0xf002b878) */
/* WARNING: Removing unreachable block (ram,0xf002b894) */
/* WARNING: Removing unreachable block (ram,0xf002b8ec) */
/* WARNING: Removing unreachable block (ram,0xf002b7b4) */
/* WARNING: Removing unreachable block (ram,0xf002b80c) */
/* WARNING: Removing unreachable block (ram,0xf002b848) */
/* WARNING: Removing unreachable block (ram,0xf002b928) */
/* WARNING: Removing unreachable block (ram,0xf002b90c) */
/* WARNING: Removing unreachable block (ram,0xf002b740) */

undefined8 _nullsap_input(int param_1,int param_2,char *param_3,int param_4)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
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
  pcVar1 = param_3;
  _nb_map();
  pcVar2 = param_3;
  _nb_size();
  if (pcVar2 < (char *)0x3) {
    uVar5 = 0x2f;
  }
  else if (*pcVar1 == '\0') {
    if ((*(byte *)(param_4 + 1) & 0xc0) == 0x40) {
      iVar4 = param_2;
      if (((pcVar1[2] & 0xefU) == 0xaf) && ((pcVar1[1] & 1U) == 0)) {
        iVar3 = param_1;
        _if_ipackets(param_1);
        _if_ipackets_set(param_1,iVar3 + 1);
        _bcopy(param_4 + 8,param_4 + 2,6);
        *(byte *)(param_4 + 2) = *(byte *)(param_4 + 2) & 0x7f;
        if ((*(byte *)(param_4 + 8) & 0x80) != 0) {
          *(byte *)(param_4 + 0xf) =
               *(byte *)(param_4 + 0xf) & 0x7f | ~(*(byte *)(param_4 + 0xf) >> 7) << 7;
          *(byte *)(param_4 + 0xe) = *(byte *)(param_4 + 0xe) & 0x1f;
        }
        sub_F002B93C(pcVar1);
        if ((pcVar1[3] == -0x7f) && (pcVar2 = param_3, _nb_size(), (char *)0x5 < pcVar2)) {
          pcVar1[4] = '\x01';
          pcVar1[5] = '\0';
        }
        sub_F002B958(param_2,param_3,param_4);
      }
      else {
        if ((pcVar1[2] & 0xefU) != 0xe3) {
          uVar5 = 0x2f;
          goto locret_F002B934;
        }
        if ((pcVar1[1] & 1U) != 0) {
          uVar5 = 0x2f;
          goto locret_F002B934;
        }
        iVar3 = param_1;
        _if_ipackets(param_1);
        _if_ipackets_set(param_1,iVar3 + 1);
        _bcopy(param_4 + 8,param_4 + 2,6);
        *(byte *)(param_4 + 2) = *(byte *)(param_4 + 2) & 0x7f;
        if ((*(byte *)(param_4 + 8) & 0x80) != 0) {
          *(byte *)(param_4 + 0xf) =
               *(byte *)(param_4 + 0xf) & 0x7f | ~(*(byte *)(param_4 + 0xf) >> 7) << 7;
          *(byte *)(param_4 + 0xe) = *(byte *)(param_4 + 0xe) & 0x1f;
        }
        sub_F002B93C(pcVar1);
        sub_F002B958(param_2,param_3,param_4);
      }
      if (iVar4 == 0) {
        iVar4 = param_1;
        _if_opackets(param_1);
        _if_opackets_set(param_1,iVar4 + 1);
        uVar5 = 0;
      }
      else {
        iVar4 = param_1;
        _if_oerrors(param_1);
        _if_oerrors_set(param_1,iVar4 + 1);
        uVar5 = 0;
      }
    }
    else {
      uVar5 = 0x2f;
    }
  }
  else {
    uVar5 = 0x2f;
  }
locret_F002B934:
  return CONCAT44(param_2,uVar5);
}

