/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b46a4. */
id __cdecl -[KeyMap doKeyboardEvent:direction:keyBits:](
        KeyMap *self,
        SEL a2,
        unsigned int a3,
        char a4,
        unsigned int *a5)
{
  char v6; // [esp+Ch] [ebp-Ch]

  objc_msgSend(self->keyMappingLock, sel_lock); /*0x1b46c7*/
  if ( self->curMapping.mapping ) /*0x1b46cf*/
  {
    v6 = self->curMapping.keyBits[a3]; /*0x1b46e0*/
    if ( a4 == 1 ) /*0x1b46e7*/
    {
      a5[a3 >> 5] |= 1 << (a3 & 0x1F); /*0x1b4701*/
      if ( (v6 & 0x10) != 0 ) /*0x1b470a*/
        -[KeyMap _doModCalc:keyBits:](self, sel__doModCalc_keyBits_, a3, a5); /*0x1b4716*/
      if ( (v6 & 0x20) != 0 ) /*0x1b4724*/
        -[KeyMap _doCharGen:direction:](self, sel__doCharGen_direction_, a3, 1); /*0x1b472f*/
    }
    else
    {
      a5[a3 >> 5] &= __ROL4__(-2, a3 & 0x1F); /*0x1b474a*/
      if ( (v6 & 0x20) != 0 ) /*0x1b4753*/
        -[KeyMap _doCharGen:direction:](self, sel__doCharGen_direction_, a3, a4); /*0x1b4763*/
      if ( (v6 & 0x10) != 0 ) /*0x1b4771*/
        -[KeyMap _doModCalc:keyBits:](self, sel__doModCalc_keyBits_, a3, a5); /*0x1b4780*/
    }
  }
  objc_msgSend(self->keyMappingLock, sel_unlock); /*0x1b4796*/
  return self; /*0x1b47a0*/
}
