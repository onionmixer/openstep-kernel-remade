
undefined4 _bflush(uint param_1,word param_2,word param_3)

{
  uint *puVar1;
  word wVar2;
  undefined2 uVar3;
  uint in_D0;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  
loc_40182DE:
  uVar4 = in_D0 & 0xffff0000;
  puVar5 = &_bfreelist;
  do {
    for (puVar1 = (uint *)puVar5[3]; uVar3 = (undefined2)(uVar4 >> 0x10), puVar5 != puVar1;
        puVar1 = (uint *)puVar1[3]) {
      if ((((param_2 == 0xffff) ||
           (wVar2 = param_3 & *(word *)((int)puVar1 + 0x1e), uVar4 = CONCAT22(uVar3,wVar2),
           wVar2 == param_2)) && (uVar4 = *puVar1, (uVar4 & 0x200) != 0)) &&
         ((param_1 == puVar1[0x10] || (param_1 == 0)))) {
        *puVar1 = uVar4 | 0x100;
        *(uint *)(puVar1[4] + 0xc) = puVar1[3];
        *(uint *)(puVar1[3] + 0x10) = puVar1[4];
        *puVar1 = *puVar1 | 8;
        in_D0 = _bwrite(puVar1);
        goto loc_40182DE;
      }
    }
    puVar6 = puVar5 + 0x11;
    puVar1 = puVar5 + -0x102d618;
    puVar5 = puVar6;
    if (&DAT_40b58a3 < puVar6) {
      return CONCAT22(uVar3,(word)(byte)(((int)puVar1 < 0) << 3 |
                                         (puVar6 == (uint *)((int)&DAT_40b58a3 + 1)) << 2 |
                                        SBORROW4((int)puVar6,0x40b58a4) << 1));
    }
  } while( true );
}

