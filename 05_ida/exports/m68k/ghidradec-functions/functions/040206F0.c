
int _iptime(void)

{
  int iStack_c;
  int iStack_8;
  
  _microtime(&iStack_c);
  return iStack_8 / 1000 +
         (iStack_c +
         ((int)(sword)((sword)(iStack_c / 0x15180) + (sword)(iStack_c >> 0x1f)) - (iStack_c >> 0x1f)
         ) * -0x15180) * 1000;
}
