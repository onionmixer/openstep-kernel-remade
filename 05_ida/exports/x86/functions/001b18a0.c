/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b18a0. */
id __cdecl -[EventDriver evSpecialKeyMsg:direction:flags:level:](
        EventDriver *self,
        SEL a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6)
{
  id v6; // esi
  _DWORD *v8; // eax
  _DWORD *v9; // ebx

  v6 = -[EventDriver specialKeyPort:](self, sel_specialKeyPort_, a3); /*0x1b18ba*/
  if ( !v6 ) /*0x1b18c1*/
    return self; /*0x1b18c3*/
  v8 = (_DWORD *)IOMalloc(0x38u); /*0x1b18ca*/
  v9 = v8; /*0x1b18cf*/
  if ( v8 ) /*0x1b18d6*/
  {
    bcopy(&unk_1D5D90, v8, 0x38u); /*0x1b18e0*/
    v9[4] = v6; /*0x1b18e5*/
    v9[7] = a3; /*0x1b18eb*/
    v9[9] = a4; /*0x1b18f1*/
    v9[11] = a5; /*0x1b18f7*/
    v9[13] = a6; /*0x1b18fd*/
    -[EventDriver sendIOThreadAsyncMsg:to:with:]( /*0x1b1911*/
      self,
      sel_sendIOThreadAsyncMsg_to_with_,
      sel__performSpecialKeyMsg_,
      self,
      v9);
  }
  return self; /*0x1b191b*/
}
