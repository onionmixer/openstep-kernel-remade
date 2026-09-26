
undefined * _newname(void)

{
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  undefined5 *puVar4;
  undefined *puVar6;
  undefined auStack_c [2];
  word wStack_a;
  undefined5 *puVar5;
  undefined *puVar7;
  
  puVar3 = (undefined *)_kalloc(0xff);
  puVar5 = &aNfs_0;
  puVar7 = puVar3;
  do {
    puVar4 = (undefined5 *)((int)puVar5 + 1);
    puVar6 = puVar7 + 1;
    *puVar7 = *(undefined *)puVar5;
    puVar5 = puVar4;
    puVar7 = puVar6;
  } while (puVar4 < (undefined5 *)((int)&aNfs_0 + 4));
  if (dword_40B352C == 0) {
    _getthetime(auStack_c);
    dword_40B352C = (uint)wStack_a;
  }
  iVar2 = dword_40B352C + 1;
  for (uVar1 = dword_40B352C; dword_40B352C = iVar2, uVar1 != 0; uVar1 = (int)uVar1 >> 4) {
    *puVar6 = a0123456789abcd_0[uVar1 & 0xf];
    puVar6 = puVar6 + 1;
    iVar2 = dword_40B352C;
  }
  *puVar6 = 0;
  return puVar3;
}

