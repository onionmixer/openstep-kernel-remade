
/* WARNING: Removing unreachable block (ram,0xf0029c10) */

undefined8 _ifunit(char *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 unaff_l0;
  char *pcVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar4;
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
  pcVar3 = param_1;
  if (param_1 < param_1 + 0x10) {
    cVar1 = *param_1;
    while (cVar1 != 0) {
      if (((int)cVar1 - 0x30U & 0xff) < 10) {
        cVar1 = *pcVar3;
        goto loc_F0029BD4;
      }
      pcVar3 = pcVar3 + 1;
      if (param_1 + 0x10 <= pcVar3) break;
      cVar1 = *pcVar3;
    }
  }
  cVar1 = *pcVar3;
loc_F0029BD4:
  if ((cVar1 == 0) || (pcVar3 == param_1 + 0x10)) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = _ifnet;
    if (_ifnet != (int *)0x0) {
      iVar2 = *_ifnet;
      do {
        _bcmp(iVar2,param_1,(int)pcVar3 - (int)param_1);
        if (iVar2 == 0) {
          if (piVar4[5] == 0x1000) {
            if (cVar1 + -0x30 == (int)*(sword *)(piVar4 + 2)) break;
            piVar4 = (int *)piVar4[0x17];
          }
          else {
            piVar4 = (int *)piVar4[0x17];
          }
        }
        else {
          piVar4 = (int *)piVar4[0x17];
        }
        if (piVar4 == (int *)0x0) break;
        iVar2 = *piVar4;
      } while( true );
    }
  }
  return CONCAT44(param_2,piVar4);
}
