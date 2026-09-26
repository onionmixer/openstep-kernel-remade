
undefined4 _thread_wakeup_prim(uint param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined2 uVar6;
  uint uVar7;
  bool bVar8;
  bool bVar9;
  char cVar10;
  bool bVar11;
  
  uVar7 = param_1;
  if ((int)param_1 < 0) {
    uVar7 = ~param_1;
  }
  uVar3 = ((int)uVar7 / 0x3b) * 0x3b;
  puVar1 = &_wait_queue + ((int)uVar7 % 0x3b) * 2;
  uVar7 = uVar3 & 0xffff0000;
  uVar6 = (undefined2)(uVar3 >> 0x10);
  iVar4 = (int)*puVar1 - (int)puVar1;
  puVar5 = (undefined4 *)*puVar1;
  while( true ) {
    bVar9 = SBORROW4((int)puVar5,(int)puVar1);
    cVar10 = puVar5 < puVar1;
    bVar8 = true;
    bVar11 = (bool)cVar10;
    if (puVar5 == puVar1) break;
    puVar2 = (undefined4 *)*puVar5;
    if (param_1 == puVar5[0xe]) {
      puVar2[1] = puVar5[1];
      *(undefined4 *)puVar5[1] = *puVar5;
      puVar5[0xe] = 0;
      if (puVar5[0x4f] != 0) {
        _reset_timeout(puVar5 + 0x44);
      }
      uVar3 = puVar5[0x12];
      uVar7 = (uVar3 & 0xf) - 1;
      cVar10 = 0xe < uVar7;
      switch(uVar7) {
      case :
      case :
      case :
        puVar5[0x12] = uVar3 & 0xfffffffe | 4;
        puVar5[0x10] = param_3;
        uVar7 = _thread_setrun(puVar5,1);
        break;
      :
                    /* WARNING: Subroutine does not return */
        _panic(aThreadWakeup);
      case :
      case :
      case :
      case :
      case :
        puVar5[0x12] = uVar3 & 0xfffffffe;
        puVar5[0x10] = param_3;
      }
      uVar6 = (undefined2)(uVar7 >> 0x10);
      bVar9 = false;
      bVar11 = false;
      bVar8 = param_2 == 0;
      iVar4 = param_2;
      if (!bVar8) break;
    }
    uVar6 = (undefined2)(uVar7 >> 0x10);
    iVar4 = (int)puVar2 - (int)puVar1;
    puVar5 = puVar2;
  }
  return CONCAT22(uVar6,(word)(byte)(cVar10 << 4 | (iVar4 < 0) << 3 | bVar8 << 2 | bVar9 << 1 |
                                    bVar11));
}

