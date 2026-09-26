
void _loattach(void)

{
  _loifp = _if_attach(0,0,_looutput,_logetbuf,_locontrol,&aLo,0,aInternetProtoc,0x600,0x808,0x1000,0
                     );
  return;
}
