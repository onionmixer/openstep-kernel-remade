/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x196eb0. */
int __cdecl kmioctl(int a1, int a2, int *a3, int a4)
{
  int result; // eax
  _WORD v5[4]; // [esp+Ch] [ebp-8h] BYREF

  if ( a2 == 536898306 ) /*0x196eca*/
    return (int)objc_msgSend(kmId, sel_restore); /*0x196f46*/
  if ( a2 > 536898306 ) /*0x196ecc*/
  {
    if ( a2 == 536898312 ) /*0x196f0e*/
      return (int)objc_msgSend(kmId, sel_disableCons); /*0x196f7e*/
    if ( a2 > 536898312 ) /*0x196f10*/
    {
      if ( a2 == 1074031370 ) /*0x196f26*/
        return (int)objc_msgSend(kmId, sel_getStatus_, a3); /*0x196f9b*/
      if ( a2 == 1074293515 ) /*0x196f2e*/
      {
        objc_msgSend(kmId, sel_getScreenSize_, v5); /*0x196fb2*/
        *(_WORD *)a3 = v5[0]; /*0x196fbb*/
        *((_WORD *)a3 + 1) = v5[1]; /*0x196fc2*/
        *((_WORD *)a3 + 2) = v5[2]; /*0x196fca*/
        *((_WORD *)a3 + 3) = v5[3]; /*0x196fd2*/
        return 0; /*0x196fd8*/
      }
    }
    else if ( a2 == 536898307 ) /*0x196f18*/
    {
      return (int)objc_msgSend(kmId, sel_dumpMsgBuf); /*0x196f86*/
    }
  }
  else
  {
    if ( a2 == -2146929561 ) /*0x196ed4*/
      return 22; /*0x196fe1*/
    if ( a2 > -2146929561 ) /*0x196eda*/
    {
      if ( a2 == -2146669819 ) /*0x196ef6*/
        return (int)objc_msgSend(kmId, sel_drawRect_, a3); /*0x196f5f*/
      if ( a2 == -2146669818 ) /*0x196efe*/
        return (int)objc_msgSend(kmId, sel_eraseRect_, a3); /*0x196f73*/
    }
    else if ( a2 == -2147194103 ) /*0x196ee2*/
    {
      return (int)objc_msgSend(kmId, sel_animationCtl_, *a3); /*0x196f91*/
    }
  }
  result = ((int (__cdecl *)(FILE *, int, int *, int))*(&off_1DAFF8 + 12 * SHIBYTE(cons._lb._base)))(&cons, a2, a3, a4); /*0x196ffb*/
  if ( result < 0 ) /*0x197002*/
  {
    result = ttioctl(&cons, a2, a3, a4); /*0x19700b*/
    if ( result < 0 ) /*0x197012*/
      return 25; /*0x197014*/
  }
  return result; /*0x19701c*/
}
