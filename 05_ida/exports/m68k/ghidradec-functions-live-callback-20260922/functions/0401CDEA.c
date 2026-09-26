
undefined4 *
_if_attach(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined2 param_7,undefined4 param_8,
          undefined2 param_9,undefined2 param_10,uint param_11,undefined4 param_12)

{
  undefined4 *puVar1;
  bool bVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  bVar2 = false;
  puVar3 = _ifnet;
  do {
    if (puVar3 == (undefined4 *)0x0) {
loc_401CE1E:
      if (!bVar2) {
        puVar3 = (undefined4 *)_kalloc(0x5e);
        _bzero(puVar3,0x5e);
      }
      *puVar3 = param_6;
      puVar3[1] = param_8;
      *(undefined2 *)(puVar3 + 2) = param_7;
      *(undefined2 *)((int)puVar3 + 10) = param_9;
      *(undefined2 *)(puVar3 + 3) = param_10;
      *(undefined4 *)((int)puVar3 + 0xe) = 0;
      *(undefined4 *)((int)puVar3 + 0x16) = 0;
      *(undefined4 *)((int)puVar3 + 0x26) = _ifqmaxlen;
      *(undefined4 *)((int)puVar3 + 0x2e) = param_1;
      *(undefined4 *)((int)puVar3 + 0x32) = param_3;
      *(undefined4 *)((int)puVar3 + 0x36) = param_5;
      *(undefined4 *)((int)puVar3 + 0x3a) = param_2;
      *(undefined4 *)((int)puVar3 + 0x3e) = param_4;
      *(undefined4 *)((int)puVar3 + 0x56) = param_12;
      *(uint *)((int)puVar3 + 0x12) = param_11;
      *(undefined4 *)((int)puVar3 + 0x42) = 0;
      *(undefined4 *)((int)puVar3 + 0x46) = 0;
      *(undefined4 *)((int)puVar3 + 0x4a) = 0;
      *(undefined4 *)((int)puVar3 + 0x4e) = 0;
      *(undefined4 *)((int)puVar3 + 0x52) = 0;
      if (!bVar2) {
        piVar4 = (int *)&_ifnet;
        puVar1 = _ifnet;
        while ((puVar1 != (undefined4 *)0x0 && (param_11 <= *(uint *)(*piVar4 + 0x12)))) {
          piVar4 = (int *)(*piVar4 + 0x5a);
          puVar1 = (undefined4 *)*piVar4;
        }
        *(int *)((int)puVar3 + 0x5a) = *piVar4;
        *piVar4 = (int)puVar3;
      }
      if (*(int *)((int)puVar3 + 0x12) == 0) {
        sub_401CD2C(puVar3);
      }
      return puVar3;
    }
    if (((undefined5 *)*puVar3 == &aNull_0) && (param_11 == *(uint *)((int)puVar3 + 0x12))) {
      bVar2 = true;
      goto loc_401CE1E;
    }
    puVar3 = *(undefined4 **)((int)puVar3 + 0x5a);
  } while( true );
}

