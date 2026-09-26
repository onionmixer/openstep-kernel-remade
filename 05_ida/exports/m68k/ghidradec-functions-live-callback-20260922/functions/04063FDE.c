
void sub_4063FDE(void)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  
  iVar1 = _kalloc(0x2000);
loc_4063FF4:
  do {
    while( true ) {
      *(undefined4 *)(iVar1 + 0xc) = dword_40B06F8;
      *(undefined4 *)(iVar1 + 4) = 0x2000;
      iVar2 = _msg_receive(iVar1,0,0);
      if (iVar2 == 0) break;
      puVar3 = aVolThreadMsgRe;
loc_4064084:
      _printf(puVar3,iVar2);
    }
    iVar2 = *(int *)(iVar1 + 0x14);
    if (iVar2 == 0x41) {
      sub_40640EA(iVar1);
      goto loc_4063FF4;
    }
    if (iVar2 != 0x357) {
      puVar3 = aVolThreadBogus;
      goto loc_4064084;
    }
    iVar2 = sub_4064092(*(undefined4 *)(iVar1 + 0x1c));
    if (iVar2 != 0) {
      if (*(code **)(iVar2 + 0xc) != (code *)0x0) {
        (**(code **)(iVar2 + 0xc))
                  (*(undefined4 *)(iVar2 + 0x10),*(undefined4 *)(iVar2 + 8),
                   *(undefined4 *)(iVar1 + 0x20));
      }
      _kfree(iVar2,0x14);
    }
  } while( true );
}

