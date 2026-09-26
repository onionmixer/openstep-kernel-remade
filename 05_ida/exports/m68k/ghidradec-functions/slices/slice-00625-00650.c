/* GHIDRADEC_FUNCTION index=625 start=0x401ca9c */

undefined4 _nb_grow_bot(int param_1,sword param_2)

{
  *(sword *)(param_1 + 8) = param_2 + *(sword *)(param_1 + 8);
  return 0;
}
/* GHIDRADEC_FUNCTION index=626 start=0x401cab2 */

undefined4 _if_output(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (*(code **)(param_1 + 0x32) == (code *)0x0) {
    uVar1 = 6;
  }
  else {
    uVar1 = (**(code **)(param_1 + 0x32))(param_1,param_2,param_3);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=627 start=0x401cad6 */

undefined4 _if_control(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (*(code **)(param_1 + 0x36) == (code *)0x0) {
    uVar1 = 6;
  }
  else {
    uVar1 = (**(code **)(param_1 + 0x36))(param_1,param_2,param_3);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=628 start=0x401cafa */

undefined4 _if_ioctl(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  undefined *puVar2;
  uint uStack_c;
  int iStack_8;
  
  if (*(code **)(param_1 + 0x36) == (code *)0x0) {
    return 6;
  }
  if (param_2 == 0x80206931) {
    uVar1 = _if_control(param_1,_IFCONTROL_ADDMULTICAST,param_3);
    return uVar1;
  }
  if (param_2 < 0x80206932) {
    if (param_2 == 0x8020690c) {
      puVar2 = (undefined *)&_IFCONTROL_SETADDR;
    }
    else {
      if (param_2 != 0x80206910) goto loc_401CBA2;
      param_3 = param_3 + 0x10;
      puVar2 = _IFCONTROL_SETFLAGS;
    }
  }
  else if (param_2 == 0xc020690d) {
    param_3 = param_3 + 0x10;
    puVar2 = (undefined *)&_IFCONTROL_GETADDR;
  }
  else if (param_2 < 0xc020690e) {
    if (param_2 != 0x80206932) {
loc_401CBA2:
      uStack_c = param_2;
      iStack_8 = param_3;
      uVar1 = (**(code **)(param_1 + 0x36))(param_1,_IFCONTROL_UNIXIOCTL,&uStack_c);
      return uVar1;
    }
    puVar2 = _IFCONTROL_RMVMULTICAST;
  }
  else {
    if (param_2 != 0xc0206921) goto loc_401CBA2;
    param_3 = param_3 + 0x10;
    puVar2 = _IFCONTROL_AUTOADDR;
  }
  uVar1 = (**(code **)(param_1 + 0x36))(param_1,puVar2,param_3);
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=629 start=0x401cbc4 */

undefined4 _if_init(int param_1)

{
  undefined4 uVar1;
  
  if (*(code **)(param_1 + 0x2e) == (code *)0x0) {
    uVar1 = 6;
  }
  else {
    uVar1 = (**(code **)(param_1 + 0x2e))(param_1);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=630 start=0x401cbe0 */

undefined4 _if_getbuf(int param_1)

{
  undefined4 uVar1;
  
  if (*(code **)(param_1 + 0x3e) == (code *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(param_1 + 0x3e))(param_1);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=631 start=0x401cbfc */

undefined4 _if_private(int param_1)

{
  return *(undefined4 *)(param_1 + 0x56);
}
/* GHIDRADEC_FUNCTION index=632 start=0x401cc0c */

int _if_unit(int param_1)

{
  return (int)*(sword *)(param_1 + 8);
}
/* GHIDRADEC_FUNCTION index=633 start=0x401cc1e */

undefined4 _if_name(undefined4 *param_1)

{
  return *param_1;
}
/* GHIDRADEC_FUNCTION index=634 start=0x401cc2c */

undefined4 _if_type(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}
/* GHIDRADEC_FUNCTION index=635 start=0x401cc3c */

int _if_mtu(int param_1)

{
  return (int)*(sword *)(param_1 + 10);
}
/* GHIDRADEC_FUNCTION index=636 start=0x401cc4e */

undefined4 _if_class(int param_1)

{
  return *(undefined4 *)(param_1 + 0x12);
}
/* GHIDRADEC_FUNCTION index=637 start=0x401cc5e */

int _if_flags(int param_1)

{
  return (int)*(sword *)(param_1 + 0xc);
}
/* GHIDRADEC_FUNCTION index=638 start=0x401cc70 */

undefined4 _if_opackets(int param_1)

{
  return *(undefined4 *)(param_1 + 0x4a);
}
/* GHIDRADEC_FUNCTION index=639 start=0x401cc80 */

undefined4 _if_ipackets(int param_1)

{
  return *(undefined4 *)(param_1 + 0x42);
}
/* GHIDRADEC_FUNCTION index=640 start=0x401cc90 */

undefined4 _if_oerrors(int param_1)

{
  return *(undefined4 *)(param_1 + 0x4e);
}
/* GHIDRADEC_FUNCTION index=641 start=0x401cca0 */

undefined4 _if_ierrors(int param_1)

{
  return *(undefined4 *)(param_1 + 0x46);
}
/* GHIDRADEC_FUNCTION index=642 start=0x401ccb0 */

undefined4 _if_collisions(int param_1)

{
  return *(undefined4 *)(param_1 + 0x52);
}
/* GHIDRADEC_FUNCTION index=643 start=0x401ccc0 */

void _if_flags_set(int param_1,undefined2 param_2)

{
  *(undefined2 *)(param_1 + 0xc) = param_2;
  return;
}
/* GHIDRADEC_FUNCTION index=644 start=0x401ccd2 */

void _if_opackets_set(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x4a) = param_2;
  return;
}
/* GHIDRADEC_FUNCTION index=645 start=0x401cce4 */

void _if_ipackets_set(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x42) = param_2;
  return;
}
/* GHIDRADEC_FUNCTION index=646 start=0x401ccf6 */

void _if_oerrors_set(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x4e) = param_2;
  return;
}
/* GHIDRADEC_FUNCTION index=647 start=0x401cd08 */

void _if_ierrors_set(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x46) = param_2;
  return;
}
/* GHIDRADEC_FUNCTION index=648 start=0x401cd1a */

void _if_collisions_set(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x52) = param_2;
  return;
}
/* GHIDRADEC_FUNCTION index=649 start=0x401cd62 */

undefined4 _iflist_first(void)

{
  return _ifnet;
}

