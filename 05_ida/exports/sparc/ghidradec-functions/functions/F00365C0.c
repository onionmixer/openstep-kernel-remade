
/* WARNING: Removing unreachable block (ram,0xf0036640) */
/* WARNING: Removing unreachable block (ram,0xf0036658) */
/* WARNING: Removing unreachable block (ram,0xf0036634) */

undefined8 _tcp_dooptions(undefined4 param_1,int param_2,int param_3)

{
  char cVar1;
  undefined4 unaff_l0;
  uint uVar2;
  undefined4 unaff_l1;
  char *pcVar3;
  int iVar4;
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
  iVar4 = (int)*(sword *)(param_2 + 8);
  pcVar3 = (char *)(param_2 + *(int *)(param_2 + 4));
  while (0 < iVar4) {
    cVar1 = *pcVar3;
    if (cVar1 == '\0') break;
    if (cVar1 == '\x01') {
      uVar2 = 1;
    }
    else {
      uVar2 = (uint)(byte)pcVar3[1];
      if (uVar2 == 0) break;
    }
    if (cVar1 == '\x02') {
      if (uVar2 == 4) {
        if ((*(byte *)(param_3 + 0x21) & 2) == 0) {
          iVar4 = iVar4 + -4;
        }
        else {
          _bcopy(pcVar3 + 2,(undefined *)((int)register0x00000038 + -10),2);
          _tcp_mss(param_1,*(undefined2 *)((int)register0x00000038 + -10));
          iVar4 = iVar4 + -4;
        }
      }
      else {
        iVar4 = iVar4 - uVar2;
      }
    }
    else {
      iVar4 = iVar4 - uVar2;
    }
    pcVar3 = pcVar3 + uVar2;
  }
  _m_free(param_2);
  return CONCAT44(param_2,param_1);
}
