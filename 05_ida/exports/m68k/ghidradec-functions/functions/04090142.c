
void _in_bootp_getpacket(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uStack_22;
  undefined4 uStack_1e;
  undefined4 *puStack_1a;
  undefined4 uStack_16;
  undefined4 uStack_12;
  undefined4 uStack_e;
  undefined4 uStack_8;
  
  uStack_22 = param_2;
  uStack_1e = param_3;
  puStack_1a = &uStack_22;
  uStack_16 = 1;
  uStack_e = 1;
  uStack_12 = 0;
  uStack_8 = param_3;
  _soreceive(param_1,0,&puStack_1a,0,0);
  return;
}
