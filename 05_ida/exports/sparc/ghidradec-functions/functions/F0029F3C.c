
/* WARNING: Removing unreachable block (ram,0xf0029fcc) */
/* WARNING: Removing unreachable block (ram,0xf002a04c) */
/* WARNING: Removing unreachable block (ram,0xf0029fdc) */
/* WARNING: Removing unreachable block (ram,0xf0029f74) */

undefined8 _ifconf(undefined4 param_1,uint *param_2)

{
  char cVar1;
  char *pcVar2;
  undefined4 unaff_l0;
  undefined2 *puVar3;
  undefined4 unaff_l1;
  uint uVar4;
  uint uVar5;
  undefined4 unaff_l3;
  undefined4 *puVar6;
  undefined4 unaff_l4;
  char *pcVar7;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  char *pcVar8;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar9;
  bool bVar10;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  char acStack_27 [39];
  
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
  pcVar8 = (char *)0x0;
  uVar4 = *param_2;
  uVar5 = param_2[1];
  if (0x20 < uVar4) {
    pcVar7 = (char *)((int)register0x00000038 + -0x28);
    puVar6 = _ifnet;
    do {
      if (puVar6 == (undefined4 *)0x0) break;
      _bcopy(*puVar6,pcVar7,0xe);
      pcVar2 = pcVar7;
      if (pcVar7 < (char *)((int)register0x00000038 + -0x1a)) {
        cVar1 = *pcVar7;
        while (cVar1 != '\0') {
          pcVar2 = pcVar2 + 1;
          if ((char *)((int)register0x00000038 + -0x1a) <= pcVar2) goto loc_F0029FA8;
          cVar1 = *pcVar2;
        }
        cVar1 = *(char *)((int)puVar6 + 9);
      }
      else {
loc_F0029FA8:
        cVar1 = *(char *)((int)puVar6 + 9);
      }
      *pcVar2 = cVar1 + '0';
      pcVar2[1] = '\0';
      puVar3 = (undefined2 *)puVar6[6];
      if (puVar3 == (undefined2 *)0x0) {
        _bzero((undefined *)((int)register0x00000038 + -0x18),0x10);
        pcVar8 = pcVar7;
        _copyout(pcVar7,uVar5,0x20);
        if (pcVar8 != (char *)0x0) {
          uVar5 = *param_2;
          goto loc_F002A088;
        }
        uVar4 = uVar4 - 0x20;
        uVar5 = uVar5 + 0x20;
      }
      else {
        for (; 0x20 < uVar4; uVar4 = uVar4 - 0x20) {
          bVar10 = uVar4 < 0x20;
          bVar9 = uVar4 == 0x20;
          if (puVar3 == (undefined2 *)0x0) goto loc_F002A07C;
          *(undefined2 *)((int)register0x00000038 + -0x18) = *puVar3;
          *(undefined2 *)((int)register0x00000038 + -0x16) = puVar3[1];
          *(undefined2 *)((int)register0x00000038 + -0x14) = puVar3[2];
          *(undefined2 *)((int)register0x00000038 + -0x12) = puVar3[3];
          *(undefined2 *)((int)register0x00000038 + -0x10) = puVar3[4];
          pcVar8 = (char *)((int)register0x00000038 + -0x28);
          *(undefined2 *)((int)register0x00000038 + -0xe) = puVar3[5];
          *(undefined2 *)((int)register0x00000038 + -0xc) = puVar3[6];
          *(undefined2 *)((int)register0x00000038 + -10) = puVar3[7];
          _copyout(pcVar8,uVar5,0x20);
          bVar10 = uVar4 < 0x20;
          bVar9 = uVar4 == 0x20;
          if (pcVar8 != (char *)0x0) goto loc_F002A07C;
          uVar5 = uVar5 + 0x20;
          puVar3 = *(undefined2 **)(puVar3 + 0x12);
        }
      }
      bVar10 = uVar4 < 0x20;
      bVar9 = uVar4 == 0x20;
loc_F002A07C:
      puVar6 = (undefined4 *)puVar6[0x17];
    } while (!bVar10 && !bVar9);
  }
  uVar5 = *param_2;
loc_F002A088:
  *param_2 = uVar5 - uVar4;
  return CONCAT44(param_2,pcVar8);
}
