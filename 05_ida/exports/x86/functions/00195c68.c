/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x195c68. */
int __cdecl -[kmDevice canBecomeOwner:](kmDevice *self, SEL a2, id a3)
{
  id v3; // eax
  int v4; // ebx
  char *v6; // [esp-4h] [ebp-18h]
  char *__s1; // [esp+Ch] [ebp-8h]
  char *__s1a; // [esp+Ch] [ebp-8h]
  id v9; // [esp+10h] [ebp-4h]

  v3 = objc_msgSend(self->kbId, sel_becomeOwner_, self); /*0x195c83*/
  if ( v3 ) /*0x195c8d*/
  {
    -[IODevice stringFromReturn:](self, sel_stringFromReturn_, v3); /*0x195c9b*/
    IOLog(aKmCanbecomeown); /*0x195ca6*/
  }
  if ( !word_1E3D88 ) /*0x195cb6*/
  {
    word_1E3D88 = 1; /*0x195cbc*/
    v9 = +[IOConfigTable newFromSystemConfig](aIoconfigtable, sel_newFromSystemConfig); /*0x195cd8*/
    __s1 = (char *)objc_msgSend(v9, sel_valueForStringKey_, aShutdownGraphi); /*0x195cf0*/
    if ( __s1 ) /*0x195cf8*/
    {
      if ( !strcmp(__s1, aNo) ) /*0x195d0c*/
        word_1E3D8A = 1; /*0x195d10*/
      +[IOConfigTable freeString:](aIoconfigtable, sel_freeString_, __s1); /*0x195d2b*/
    }
    __s1a = (char *)objc_msgSend(v9, sel_valueForStringKey_, aLanguage); /*0x195d48*/
    if ( __s1a ) /*0x195d50*/
    {
      v4 = 0; /*0x195d52*/
      while ( strcmp(__s1a, (&off_1E3D34)[v4]) ) /*0x195d6a*/
      {
        if ( ++v4 > 6 ) /*0x195d70*/
          goto LABEL_12; /*0x195d70*/
      }
      glLanguage = v4; /*0x195de4*/
LABEL_12:
      +[IOConfigTable freeString:](aIoconfigtable, sel_freeString_, __s1a); /*0x195d72*/
    }
    objc_msgSend(v9, sel_free); /*0x195d97*/
  }
  if ( word_1E3D8A ) /*0x195da7*/
    prettyShutdown = 0; /*0x195da9*/
  if ( dword_1E7768 && !prettyShutdown ) /*0x195dc3*/
  {
    self->fbp[0] = ($8EF4127CF77ECA3DDB612FCF233DC3A8 *)objc_msgSend(dword_1E7768, sel_allocateConsoleInfo); /*0x195dfc*/
  }
  else
  {
    -[kmDevice returnToVGAMode](self, sel_returnToVGAMode); /*0x195dd0*/
    self->fbp[0] = ($8EF4127CF77ECA3DDB612FCF233DC3A8 *)basicConsole; /*0x195ddb*/
  }
  if ( prettyShutdown ) /*0x195e0d*/
    self->fbMode = 2; /*0x195e12*/
  else
    self->fbMode = 1; /*0x195e23*/
  (*((void (__cdecl **)($8EF4127CF77ECA3DDB612FCF233DC3A8 *, int, int, int, char *))self->fbp[0] + 1))( /*0x195e4c*/
    self->fbp[0],
    self->fbMode,
    1,
    1,
    mach_title);
  -[kmDevice drawGraphicPanel:](self, sel_drawGraphicPanel_, 1); /*0x195e5b*/
  if ( prettyShutdown == 1 ) /*0x195e6d*/
  {
    v6 = aRestartingTheC; /*0x195e78*/
  }
  else if ( prettyShutdown == 2 ) /*0x195e73*/
  {
    v6 = aPleaseWaitUnti_0; /*0x195e80*/
  }
  else
  {
    v6 = aPleaseWait; /*0x195e88*/
  }
  -[kmDevice graphicPanelString:](self, sel_graphicPanelString_, v6); /*0x195e98*/
  -[kmDevice animationCtl:](self, sel_animationCtl_, 2); /*0x195ead*/
  return 0; /*0x195eb7*/
}
