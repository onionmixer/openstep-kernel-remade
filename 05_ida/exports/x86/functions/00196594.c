/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x196594. */
int __cdecl -[kmDevice kmOpen:](kmDevice *self, SEL a2, int a3)
{
  int v3; // edi
  int fbMode; // eax
  $8EF4127CF77ECA3DDB612FCF233DC3A8 *Console; // eax

  v3 = 0; /*0x1965a0*/
  objc_msgSend(self->kmOpenLock, sel_lock); /*0x1965b0*/
  if ( (a3 & 0xA0000000) != 0 ) /*0x1965be*/
  {
    fbMode = self->fbMode; /*0x1965c4*/
    if ( fbMode != 1 && fbMode != 3 ) /*0x1965d6*/
    {
      if ( suser() ) /*0x1965dc*/
      {
        if ( self->fbMode == 4 ) /*0x1965f3*/
        {
          v3 = 16; /*0x1965f5*/
        }
        else
        {
          if ( dword_1E7768 ) /*0x196603*/
            Console = ($8EF4127CF77ECA3DDB612FCF233DC3A8 *)objc_msgSend(dword_1E7768, sel_allocateConsoleInfo); /*0x196614*/
          else
            Console = ($8EF4127CF77ECA3DDB612FCF233DC3A8 *)BasicAllocateConsole(); /*0x196605*/
          self->fbp[1] = Console; /*0x19661c*/
          if ( !Console ) /*0x196624*/
            self->fbp[1] = ($8EF4127CF77ECA3DDB612FCF233DC3A8 *)basicConsole; /*0x19662c*/
          (*((void (__cdecl **)($8EF4127CF77ECA3DDB612FCF233DC3A8 *, int, _DWORD, int, char *))self->fbp[1] + 1))( /*0x196649*/
            self->fbp[1],
            3,
            0,
            1,
            off_1E38B0);
          self->savedFbMode = self->fbMode; /*0x196651*/
          self->fbMode = 3; /*0x196657*/
          ++self->alertRefCount; /*0x196661*/
        }
      }
      else
      {
        v3 = 13; /*0x1965e5*/
      }
    }
  }
  objc_msgSend(self->kmOpenLock, sel_unlock); /*0x196678*/
  return v3; /*0x196682*/
}
